#define __OSD002FUNC__

#include "Core\Header\Include.h"

#if(_OSD_TYPE == _OSD002)

//-----------------------------------------------------------------------
void CDrawMuteState(void)
{           
    COsdFxDisableOsd();
    SetOSDDouble(0x03);
    SetOsdMap(tUserMenuOsdMap);
                
    // Init OSD Ram
    OSDClear(0,_MAINMENU_HEIGHT, 0, 31, 0x8C, BYTE_ATTRIB);
    OSDClear(0,_MAINMENU_HEIGHT, 0, 31, 0x00, BYTE_DISPLAY);
    OSDClear(0,_MAINMENU_HEIGHT, 0, 31, 0x40, BYTE_COLOR);
                
    COsdFxCodeWrite(ucCloseAllWindow);  
    OSDPosition(4 * 12, 2 * 18, 40, 1, 0x03);
    if (GET_AUDIO_MUTE()) // Mute on 
       COsdLoad1BitFont(FntMute, 0x10, 6, tFntVolumeCharWidth);
    else
       COsdLoad1BitFont(FntVolume, 0x10, 6, tFntVolumeCharWidth);  
                               
    // Display Volume/Mute icon
    Gotoxy(0, 0, BYTE_DISPLAY);
    OutputChar(0x10);
    OutputChar(0x11);
    OutputChar(0x12);
    Gotoxy(0, 1, BYTE_DISPLAY);
    OutputChar(0x13);
    OutputChar(0x14);
    OutputChar(0x15);

    COsdFxEnableOsd();
    bOSDTimeOut  = 0;
 //   ucAudioState = 1;
    if (GET_AUDIO_MUTE()) // Mute on  
    {
       	CTimerCancelTimerEvent(COsdDispOsdTimerEvent);
    }
    else
    {
       CTimerReactiveTimerEvent(SEC(5), COsdDispOsdTimerEvent);
    } 
}

//----------------------------------------------------------------------------------------------------
void InitMainMenu(void)
{
    InitOsdFrame();

	// Set 2bit sub menu select flag,color & Attrib
    OSDClear(5, 12, 2, 2, 0xFA, BYTE_ATTRIB);
    OSDClear(5, 12, 2, 2, 0x37, BYTE_COLOR);

	// Draw ----------- ·Ö¸ô --------------
    OSDLine(ROW(3), COL(1), LENGTH(23), 0x5c, BYTE_DISPLAY);
    
    // Set Menu Title color
	OSDLine(ROW(4), COL(0), LENGTH(31), 0x40, BYTE_COLOR);

    // Draw Main Window
    COsdFxDrawWindow(8,0,												//WORD usXStart,WORD usYStart,  
    				 _MAINMENU_WIDTH * 12 + 8,_MAINMENU_HEIGHT * 18,	//WORD usXEnd,WORD usYEnd,  
    				 tMainWindowStyle);									//BYTE *pStyle)

    // Draw Adjust Window
    COsdFxDrawWindow(28,		306,									//WORD usXStart,WORD usYStart,  
    				 288,		372,									//WORD usXEnd,WORD usYEnd,  
    				 tAdjustWindowStyle);								//BYTE *pStyle)
    				 
    ShowMode();
}

//---------------------------------------------------------------------------
void CChangePalette(void)
{
	static BYTE ucState = 0;
	char *p = tColorPalettes[ucState];
	
    //CTimerWaitForEvent(_EVENT_DEN_STOP);
	CScalerSetByte(_OVERLAY_LUT_ADDR_6E, 0x80 | 0x27);
	CScalerWrite(_COLOR_LUT_PORT_6F, 9, p, _NON_AUTOINC);
	CScalerSetByte(_OVERLAY_LUT_ADDR_6E, 0x00);

    ucState++;
    
    if(ucState > 2)
       ucState = 0;
}

//----------------------------------------------------------------------------------------------------
void COsdDispFirstTimeLoadFont(void)
{       
    COsdFxDisableOsd();
    COsdColorPalette(tPALETTE_0);
    
    SetOsdMap(tUserMenuOsdMap);
    
    COsdLoad1BitFont(FntGlobal, 0x00, 123, tFntGlobalCharWidth);
    CScalerLoadHardwareVLCFont(FntMainIcon, 0x80 * 2);		// 2bit Icon

	//Load Languege Font
	LoadLanguageFont();

}
//----------------------------------------------------------
void LoadLanguageFont()
{
	switch(GET_LANGUAGE())
	{
		case LNG_CHI_S:
#if(LNG_CHI_S_EN == 1)
		{
			COsdLoad1BitFont(FntGlobal,0x00,123,tFntGlobalCharWidth);
			COsdLoad1BitFont(FntChi_S,0x7b,80,tFntChi_SCharWidth);
		}
#endif	//#if(LNG_CHI_S == 1)
		break;

		case LNG_CHI_T:
#if(LNG_CHI_T_EN ==1)
		{
			COsdLoad1BitFont(FntGlobal,0x00,123,tFntGlobalCharWidth);
			COsdLoad1BitFont(FntChi_T,0x7b,80,tFntChi_TCharWidth);
		}
#endif	//#if(LNG_CHI_T == 1)
		break;

        case LNG_RUS: 
#if(LNG_RUS_EN == 1)
        {
            COsdLoad1BitFont(FntGlobal,0x00,123,tFntGlobalCharWidth);
            COsdLoad1BitFont(FntRus,0x7b,67,tFntRusCharWidth);
        }
#endif	//#if(LNG_RUS == 1)
        break;

        case LNG_JAP:
#if(LNG_JAP_EN == 1)
{
			COsdLoad1BitFont(FntGlobal,0x00,123,tFntGlobalCharWidth);
			COsdLoad1BitFont(FntJap,0x7b,92,tFntJapCharWidth);
}
#endif	//#if(LNG_JAP_EN == 1)
		break;

		case LNG_KOR:
#if(LNG_KOR_EN == 1)
{
    		COsdLoad1BitFont(FntGlobal,0x00,123,tFntGlobalCharWidth);
    		COsdLoad1BitFont(FntKor,0x7b,75,tFntKorCharWidth);
}
#endif	//#if(LNG_KOR_EN == 1)
		break;

	}
}  

#if(_VIDEO_TV_SUPPORT) 
//---------------------------------------------------------------------------
void CShowTVNumber(BYTE ucNumber, BYTE ucOption)
{              
    BYTE PosX = 0;

    bChangeChannel = 0;
    COsdFxDisableOsd();
    g_ucPageIndex     = _P_MENU_NONE;
    g_ucMenuItemIndex = _MENU_NONE;
    SetOSDDouble(0x03);
    SetOsdMap(tUserMenuOsdMap);
                         
    // Init OSD Ram
    OSDClear(0, GET_OSD_MAP_ROWCOUNT(), 0, 30, 0x8C, BYTE_ATTRIB);
    OSDClear(0, GET_OSD_MAP_ROWCOUNT(), 0, 30, 0x00, BYTE_DISPLAY);
    OSDLine(0, 0, 30, 0x40, BYTE_COLOR);
    OSDClear(1, GET_OSD_MAP_ROWCOUNT() - 1, 0, 30, 0x60, BYTE_COLOR);
    
    COsdFxCodeWrite(ucCloseAllWindow);
    OSDPosition(_MAINMENU_WIDTH * 12,_MAINMENU_HEIGHT * 18,50,1,0x03);
//    OSDPosition(10 * 12, 3 * 18, 90, 4, 0x03);
                        
    if (ucOption & _SHOW_CH_TV_NUMBER) 
        CShowNumber(0, 0, ucNumber);

    if (_SHOW_CH_TV_TYPE & ucOption)       
        CTextOutEx(sTVType[ucTVType], 0, 1);
    
    COsdFxEnableOsd();
    CTimerReactiveTimerEvent(SEC(5), COsdDispOsdTimerEvent);
    bOSDTimeOut  = 0;
#if(_SLEEP_FUNC)
    bOSDOnScreen = 1;
#endif
}
#endif // #if(_VIDEO_TV_SUPPORT)


//---------------------------------------------------------------------------
void CShowVGAMode(void)
{
    Gotoxy(6, _SHOW_NUM_POS_Y, BYTE_DISPLAY);
    CShowNumber1(stModeInfo.IHWidth, 0);
    OutputChar('X');
    CShowNumber1(stModeInfo.IVHeight, 0);
    OutputChar('X');
    CShowNumber1((stModeInfo.IVFreq/10), 0);
    OutputChar('H');
    OutputChar('Z');
    OutputChar(' ');
}

//---------------------------------------------------------------------------
void CShowHDMIMode(void)
{
	WORD ucLen;
	WORD IHWidth_Tmp,IVHeight_Tmp;

	IHWidth_Tmp  = stModeInfo.IHWidth;
	IVHeight_Tmp = stModeInfo.IVHeight;

	CScalerPageSelect(_PAGE2);
	CScalerGetDataPortByte(_P2_HDMI_ADDR_PORT_C9, _P2_HDMI_VCR_50, 1, pData, _NON_AUTOINC);
	stModeInfo.IVHeight = HDMI_V_Height;

	if((pData[0]&0x0F) == 0x01)			// 2 times
		stModeInfo.IHWidth = HDMI_H_Width*2;
	else if((pData[0]&0x0F) == 0x03)	// 4 times
		stModeInfo.IHWidth = HDMI_H_Width*4;
	else
        stModeInfo.IHWidth = HDMI_H_Width;

	ucLen = stModeInfo.IVHeight;
	CScalerRead(_IPV_ACT_LEN_H_1A, 1, pData, _AUTOINC);

	if (pData[0] & _BIT5)
		ucLen = stModeInfo.IVHeight*2;

	if (GET_INTERLACE_MODE())
    {
		if(stModeInfo.IVFreq>=598 && stModeInfo.IVFreq<=599)			//60Hz
			stModeInfo.IVFreq += 2;
		else if(stModeInfo.IVFreq>=498 && stModeInfo.IVFreq<=499)	//50Hz
			stModeInfo.IVFreq += 2;
	}

    Gotoxy(6, _SHOW_NUM_POS_Y, BYTE_DISPLAY);
    CShowNumber1(stModeInfo.IHWidth, 0);
    OutputChar('X');
    CShowNumber1(ucLen, 0);
    OutputChar('X');
    CShowNumber1(stModeInfo.IVFreq/10, 0);
    OutputChar('H');
    OutputChar('Z');
    OutputChar(' ');

	stModeInfo.IHWidth  = IHWidth_Tmp;
	stModeInfo.IVHeight = IVHeight_Tmp;
}

//---------------------------------------------------------------------------
void ShowMode(void)
{
    if (ucCurrState == _NOSIGNAL_STATE) 
        return;
    
    switch(_GET_INPUT_SOURCE())
    {  
    case _SOURCE_HDMI:
        CShowHDMIMode();
        break;

    case _SOURCE_VGA:
    case _SOURCE_DVI:
        CShowVGAMode();
        break; 
           
	#if(_YPBPR_SUPPORT == _ON)
    case _SOURCE_YPBPR:
        if (stModeInfo.ModeCurr < _MAX_YPBPR_MODE)
           CCenterTextout(sYPbPrMode[stModeInfo.ModeCurr], ROW(_SHOW_NUM_POS_Y), COL(0), _DIALOG_WIDTH);
        break;
	#endif  

	#if(_VIDEO_SUPPORT == _ON)
    case _SOURCE_VIDEO_AV:
    case _SOURCE_VIDEO_SV:
    case _SOURCE_VIDEO_YUV:
    case _SOURCE_VIDEO_SCART:
        if(ucVideoType > ZPAL_60)
            CCenterTextout(sPAL,ROW(_SHOW_NUM_POS_Y), COL(0), _DIALOG_WIDTH);
        else
            CCenterTextout(sNTSC,ROW(_SHOW_NUM_POS_Y), COL(0), _DIALOG_WIDTH);
        break; 

  	#if(_VIDEO_TV_SUPPORT == _ON) 
    case _SOURCE_VIDEO_TV:
		CCenterTextout(sTVType[ucTVType],ROW(_SHOW_NUM_POS_Y), COL(0), _DIALOG_WIDTH);
        break;
  	#endif
	#endif
    }
	#if(_SLEEP_FUNC)
	//bOSDOnScreen = 1;
	#endif
}


#endif
