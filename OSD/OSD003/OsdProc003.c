

#define __OSDPROC003__

#include "Core\Header\Include.h"

#if(_OSD_TYPE == _OSD003)

//--------------------------------------------------
void COsdHandler(void)
{
    bit fTest = 0;

    bOSDTimeOut = 1;

    COsdSystemFlowProc();
    
    COsdEventMsgProc();

    if (_PWOFF_STATE == ucCurrState)
        return;

    CKeyOSDMsgCover();

    // 执行当前菜单的私有处理函数
    if(CURRENT_MENU_ITEM.Proc != NULL)
    {
        CURRENT_MENU_ITEM.Proc();
    }

    if ((ucKeyMessage != _NONE_KEY_MESSAGE) && bOSDTimeOut && ucOsdState != _MI_SC_INPUT_CH_NUM)
    {            
        if (GET_OSDTIMEOUT() < 5)
        	CTimerCancelTimerEvent(COsdDispOsdTimerEvent);
        else
            CTimerReactiveTimerEvent(SEC(GET_OSDTIMEOUT()), COsdDispOsdTimerEvent);
    }

	DbgShowOSDState();

	#if(_VIDEO_TV_SUPPORT)
	#if(_SLEEP_FUNC)
  	#if(_SHOW_TV_NO_SIGNAL)
    if (!ucOsdState && !bOSDOnScreen && !bTVNoSignal)
  	#else
    if (!ucOsdState && !bOSDOnScreen)
  	#endif
    {
        if((0xff != ucAutoPowerDownTime) && (0 != _GET_POWER_DOWN_TIME()))
           CShowTimer();
    }
	#endif
	#endif

    if(_NOSIGNAL_STATE == ucCurrState && GET_BURNIN_STATE()==_BURNIN_ON)
    {
		BurnInRun();		
    }

	if(fTest)
	{
 		CNotUse();
	}

    if (bDrawMute)
    {
        bDrawMute = 0;
        if (GET_AUDIO_MUTE()) // Mute on 
           CDrawMuteState();
    }

    COsdEventMsgProc();
}

//--------------------------------------------------
void CKeyOSDMsgCover(void)
{
    // Key Message -> Osd Message
    if(ucCurrState == _ACTIVE_STATE)
    {
        CCoverKeyMsgToOsdEvent(CURRENT_MENU_ITEM.KeyMsgToOsdEvnet,CURRENT_MENU_ITEM.Option & _EN_PUB_KEYEVENT);
    }
    else
    {	
    	if(CURRENT_MENU_ITEM.Option & _KEYMAP_EN_IN_NOSIGNAL)
		{
        	CCoverKeyMsgToOsdEvent(CURRENT_MENU_ITEM.KeyMsgToOsdEvnet,CURRENT_MENU_ITEM.Option & _EN_PUB_KEYEVENT);
		}
		else
		{
    	    CCoverKeyMsgToOsdEvent(tKONoSignal, 0x00);
    	}
	}
}
//--------------------------------------------------

void DbgShowOSDState(void)
{
/*
    static BYTE ucMenuItemIndexBak = 0;

	if(ucMenuItemIndexBak != ucOsdState)
	{
		ucMenuItemIndexBak = ucOsdState;
		CUartPrintf("Osd State:",ucOsdState);
	}

    // debug info
    if(ucKeyMessage != _NONE_KEY_MESSAGE)
		CUartPrintf("Osd Event:",ucOsdEventMsg);
*/
}
//--------------------------------------------------
void COsdSystemFlowProc(void)
{
    switch(ucCurrState)
    {         
        case _PWOFF_STATE:
            break;
            
        case _INITIAL_STATE:
            break;
            
        case _SEARCH_STATE:
            break;
            
        case _ACTIVE_STATE:
            if(GET_OSD_READYFORDISPLAY() == _TRUE)
            {
            	CPowerLedOn();

                if (!bSourceVideo())
				#if(_CHANGE_SOURCE_METHOD == _CHANGE_SOURCE_METHOD_0)
                if (ucOsdState < _MI_SOURCE_VGA || ucOsdState > _MI_SOURCE_TV)
				#endif
                    COsdDispOsdTimerEvent();

                CLR_OSD_READYFORDISPLAY();
                CAdjustBackgroundColor(0x00, 0x00, 0x00);
                
				#if(_VIDEO_TV_SUPPORT)
            	ucNoSigCount = 0;
 				#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
                if (_GET_INPUT_SOURCE() != _SOURCE_VIDEO_TV)
 				#endif
				#endif
                CSetVolume();
            }
                            
			#if(_VIDEO_TV_SUPPORT)
 			#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
            CAudioCtrl(); 
 			#endif
                
 			#if(_SHOW_TV_NO_SIGNAL)
            CCheckTVSignal();
 			#endif
			#endif	// #if(_VIDEO_TV_SUPPORT)
            break;
            
        case _NOSUPPORT_STATE:
        	CMuteOn();
            if(GET_OSD_READYFORDISPLAY() == _TRUE)
            {
                CLR_OSD_READYFORDISPLAY();
                CAdjustBackgroundColor(0xFF, 0x00, 0x00);
                if (GET_FIRST_SHOW_NOTE())
                   ucOsdEventMsg = _DO_SHOW_NOTE;
                
                CTimerReactiveTimerEvent(SEC(1), CModeNoSupportEvent);
            }
            
            break;
            
        case _NOSIGNAL_STATE:
        	CMuteOn();
			#if(_CHANGE_SOURCE_METHOD == _CHANGE_SOURCE_METHOD_0)
            if (ucOsdState >= _MI_SOURCE_VGA && ucOsdState <= _MI_SOURCE_TV)
            {
            	CTimerCancelTimerEvent(CModeNoSignalEvent);
            	CTimerCancelTimerEvent(CModePowerSavingEvent);
                SET_OSD_READYFORDISPLAY();
                return;
            }
			#endif

            if(GET_OSD_READYFORDISPLAY() == _TRUE)
            {    
                CLR_OSD_READYFORDISPLAY(); 
    
                if (bSourceVideo())
                   CAdjustBackgroundColor(0x00, 0x00, (_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV) ? ((_GET_BLUE_BACKGROUND()) ? 0xFF : 0x00) : 0x00);

                if (GET_FIRST_SHOW_NOTE())
                {
                    ucOsdEventMsg = _DO_SHOW_NOTE;
                    CPowerPanelOn();
                    CPowerLightPowerOn();
                }

    			if (_GET_INPUT_SOURCE() == _SOURCE_YPBPR) 
    			{
    				CTimerReactiveTimerEvent(SEC(1), CModeNoSignalEvent);
    				break;
    			}
    
			    #if (_HDMI_SUPPORT == _ON)
    			if (_GET_INPUT_SOURCE() == _SOURCE_HDMI) 
    			{
    				CTimerReactiveTimerEvent(SEC(5), CModeNoSignalEvent);
    				CTimerReactiveTimerEvent(SEC(20), CModePowerSavingEvent);
    				break;
    			}		
			    #endif	// #if (_HDMI_SUPPORT == _ON)

    			// here comes for VGA, DVI input only
    			#if(_TMDS_SUPPORT == _ON)
    			if (_GET_INPUT_SOURCE() == _SOURCE_DVI) 
    			{
                    if (bDVICONNECT)
        				CTimerReactiveTimerEvent(SEC(1), CModeNoCableEvent);
                    else
    			    	CTimerReactiveTimerEvent(SEC(1), CModeNoSignalEvent);
    			}		
    			#endif	// #if(_TMDS_SUPPORT == _ON)

    			if (_GET_INPUT_SOURCE() == _SOURCE_VGA) 
    			{
        			if (bVGACONNECT)
        				CTimerReactiveTimerEvent(SEC(1), CModeNoCableEvent);
        			else       
        				CTimerReactiveTimerEvent(SEC(1), CModeNoSignalEvent);
    	        }

                if (bSourceVideo())
        			CTimerReactiveTimerEvent(SEC(1), CModeNoSignalEvent);

    			CTimerReactiveTimerEvent(SEC(20), CModePowerSavingEvent);   
            }
            
            break;
            
        case _SLEEP_STATE:
            break;
            
        default:
            break;
    }
}

//==========================================================================
//                          ChangeSourceState
//==========================================================================
void ChangeSourceState(void)
{
    TUNER_PWR_OFF();
    CMuteOn();

	#if(_VIDEO_TV_SUPPORT)
    if (_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV)
    	CAdjustBackgroundColor(0x00, 0x00, (_GET_BLUE_BACKGROUND()) ? 0xFF : 0x00);
    else
	#endif
		CAdjustBackgroundColor(0x00, 0x00, 0x00);

	CScalerSetBit(_VDISP_CTRL_28, 0xff, 0x20);
    CScalerSetBit(_VDISP_CTRL_28, ~(_BIT3), _BIT5);
    CInitInputSource();
    
	#if(_VIDEO_TV_SUPPORT)
	#if(_FM_DEVICE)  
    bFM = 0; // Close FM
	#endif
	#endif

	// close OSD first to avoid dirty screen.
	COsdFxDisableOsd();

	switch(_GET_INPUT_SOURCE())
	{
		case _SOURCE_VGA:
		case _SOURCE_YPBPR:
			CScalerSetBit(_IPH_ACT_WID_H_16, ~_BIT5, 0x00);
			CVideoOutputDisable();
			break;

		#if( (_TMDS_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON) )			
		case _SOURCE_DVI:
        case _SOURCE_HDMI:
			CVideoOutputDisable();
			break;
		#endif
		    
		#if(_VIDEO_TV_SUPPORT)
		case _SOURCE_VIDEO_TV:
            CInitTV();
		#endif

		case _SOURCE_VIDEO_AV:
		case _SOURCE_VIDEO_SV:
			CVideoOutputEnable();
			break;
	}
}

//-----------------------------------------------------------
void COsdEventMsgProc(void)
{                  
    if(ucOsdEventMsg > _OE_USER_CMD)
    {    
         ucOsdEventMsg = _NONE_MSG;
         return;
    }

    switch(ucOsdEventMsg)
    {
        case _SHOW_NOSIGNAL_MSG:
        case _SHOW_NOCABLE_MSG:
        case _SHOW_NOSUPPORT_MSG:
            ucOsdState = 0;

            if(GET_BURNIN_STATE() == _BURNIN_ON)
            {				
				CTimerCancelTimerEvent(CModePowerSavingEvent);				
				InitBurnIn();
            }
            else
            {            
				#if(_CHINESE_FONT_TYPE == _CHINESE_2_FONT)
            	LoadCHIFont(_LF_OTHER);
				#endif
    			CShowNoSignal();
                CTimerReactiveTimerEvent(SEC(20), COsdDispOsdTimerEvent);
    		}    		
            break;
            
        case _SAVE_EE_MODEUSERDATA_MSG:
            CEepromSaveModeData(stModeInfo.ModeCurr);
            break;
            
        case _SAVE_EE_SYSTEMDATA_MSG:
            CEepromSaveSystemData();
            break;
            
        case _SAVE_EE_OSDUSERDATA_MSG:
            CEepromSaveOsdUserData();
            break;
            
        case _SAVE_EE_ADCDATA_MSG:
            CEepromSaveAdcData();
            break;
            
        case _SAVE_EE_COLORPROC0_MSG:
            CEepromSaveBriConData();
            break;
            
        case _SAVE_EE_COLORPROC1_MSG:
            CEepromSaveColorTempData();
            break;

        case _SAVE_EE_AUDIO_DATA_MSG:
            CEepromSaveAudioData();
            break;

        case _SAVE_EE_HUE_SAT_DATA_MSG:
            CEepromSaveHueSatData();
            break;

        case _SAVE_EE_TV_DATA_MSG:
            CEepromSaveTvData();
            break;
           
        case _CHANGE_SOURCE_MSG:
            ChangeSourceState();
        	CEepromSaveSystemData();
            ucTVSyncFailCount = 250;
            CLR_CLEAR_OSD_EN();
            CModeResetMode();
        	CLR_SOURCE_AUTOCHANGE();
            CShowNote();
            SET_FIRST_SHOW_NOTE();
            break;
            
        case _DO_AUTO_CONFIG:
        	if(_GET_INPUT_SOURCE() == _SOURCE_VGA)
        	{
				CShowAutoAdjust();
        	}
        	break;
        	
        case _DO_SHOW_NOTE:
            CLR_FIRST_SHOW_NOTE();
            CShowNote();
            break;


        default:
            break;
    }
    
    ucOsdEventMsg = _NONE_MSG;
}

//----------------------------------------------------------------------------------------------------
void COsdDispFirstTimeLoadFont(void)
{       
    COsdFxDisableOsd();
    COsdColorPalette(tPALETTE_0);
    
    SetOsdMap(tUserMenuOsdMap);
    
    // Load global font 
    // insert code to here 
#if(_CHINESE_FONT_TYPE == _CHINESE_1_FONT)
    COsdLoad1BitFont(FntGlobal,0x00,0x6E,tGlobalCharWidth);
#else
    COsdLoad1BitFont(FntGlobal,0x00,0x5F,tGlobalCharWidth);
#endif
    CScalerLoadHardwareVLCFont(FntMainIcon,0x80 * 2);
    
	//Load Languege Font
	LoadLanguageFont();

}

//-----------------------------------------------------------
void COsdLoad1BitFontWidth12(BYTE *pFont,WORD usOffset,BYTE ucFntCount)
{
     BYTE i;

     CScalerLoadHardwareVLCFont(pFont, usOffset);

     if(usOffset > 0x100)		return;

     if(usOffset + ucFntCount > 0x100)
        ucFntCount = 0x100 - usOffset; 


     for(i=0;i<ucFntCount;i++)
     {
         SetCharWdith(usOffset,12);
         usOffset ++;
     }
}

#if(_CHINESE_FONT_TYPE == _CHINESE_2_FONT)
//---------------------------------------------------------------------------
void LoadCHI_S_Font(BYTE ucPage)
{
	BYTE *pFont;
	COsdLoad1BitFontWidth12(FntPublic_CHI_S,0x80,0x20);	
	switch(ucPage)
	{

		case _LF_COLOR_PAGE:		pFont = FntColorPage_S;		break;
		case _LF_ADJUST_PAGE:		pFont = FntAdjustPage_S;	break;
		case _LF_TV_PAGE:			pFont = FntTVPage_S;		break;
		case _LF_OSD_PAGE:			pFont = FntOSDPage_S;		break;
		case _LF_FUNC_PAGE:			pFont = FntFuncPage_S;		break;
		case _LF_SOUND_PAGE:		pFont = FntSoundPage_S;		break;
		case _LF_OTHER:				pFont = FntOther_CHI_S;		break;
	}

	COsdLoad1BitFontWidth12(pFont,0xA0,0x2F);	
}

//-----------------------------------------------------------
void LoadCHI_T_Font(BYTE ucPage)
{
	BYTE *pFont;
	COsdLoad1BitFontWidth12(FntPublic_CHI_T,0x80,0x20);	
	
	switch(ucPage)
	{

		case _LF_COLOR_PAGE:		pFont = FntColorPage_T;		break;
		case _LF_ADJUST_PAGE:		pFont = FntAdjustPage_T;	break;
		case _LF_TV_PAGE:			pFont = FntTVPage_T;		break;
		case _LF_OSD_PAGE:			pFont = FntOSDPage_T;		break;
		case _LF_FUNC_PAGE:			pFont = FntFuncPage_T;		break;
		case _LF_SOUND_PAGE:		pFont = FntSoundPage_T;		break;
		case _LF_OTHER:				pFont = FntOther_CHI_T;		break;
	}

	COsdLoad1BitFontWidth12(pFont,0xA0,0x22);
}

//-----------------------------------------------------------
void LoadCHIFont(BYTE ucPage)
{
	if(GET_LANGUAGE() == LNG_CHI_S)
	{
		LoadCHI_S_Font(ucPage);
	}
	else if(GET_LANGUAGE() == LNG_CHI_T)
	{
		LoadCHI_T_Font(ucPage);
	}
}
#endif

#if((_CHINESE_FONT_TYPE == _CHINESE_1_FONT && !_LOGO_ENABLE) || _CHINESE_FONT_TYPE != _CHINESE_1_FONT)
//----------------------------------------------------------
void LoadLanguageFont(void)
{
    // load language font

	switch(GET_LANGUAGE())
	{
	#if(LNG_JAP_EN)
		case LNG_JAP:
            COsdLoad1BitFont(FntJap,0x80,0x57,tFntJapCharWidth);
            break;
    #endif
    #if(LNG_KOR_EN)
        case LNG_KOR:
            COsdLoad1BitFont(FntKor,0x80,0x68,tFntKorCharWidth);
            break;
    #endif
    #if(LNG_RUS_EN)
		case LNG_RUS:
			COsdLoad1BitFont(FntRus,0x80,0x21,tFntRusCharWidth);
            break;
    #endif
#if(_CHINESE_FONT_TYPE == _CHINESE_1_FONT)
    #if(LNG_CHI_S_EN)
		case LNG_CHI_S:
			COsdLoad1BitFontWidth12(tFntChiGlobal,0x80,0x34);
			COsdLoad1BitFontWidth12(tFntChiS,0xC0,0x1D);
            break;
    #endif
    #if(LNG_CHI_T_EN)
		case LNG_CHI_T:
			COsdLoad1BitFontWidth12(tFntChiGlobal,0x80,0x34);
			COsdLoad1BitFontWidth12(tFntChiT,0xC0,0x1D);
            break;
    #endif
#endif
	}
}  
#endif

//-----------------------------------------------------------
void COsdDispOsdTimerEvent(void)
{
    COsdFxDisableOsd();
    ucOsdState = _MI_MENU_NONE;
        
	#if(_VIDEO_TV_SUPPORT)
	#if(_SLEEP_FUNC)
    bOSDOnScreen = 0;
	#endif
         
	#if(_SLEEP_FUNC)
    if(_ACTIVE_STATE == ucCurrState && (0xff == ucAutoPowerDownTime) || (0 == _GET_POWER_DOWN_TIME()))
	#endif 
	#else
    if(_ACTIVE_STATE == ucCurrState)
	#endif 
    {
         bDrawMute = 1;
    }
}

//-----------------------------------------------------------
BYTE CFoundKeyMsgToOsdEvent(SKeyToOsdEvent *tMsgTable)
{
     BYTE i;

     if(ucKeyMessage == _NONE_KEY_MESSAGE)
     {
          //ucOsdEventMsg = _NONE_MSG;
          return 0;
     }
                        
     i = 0;
     while(1)
     {
         if(tMsgTable[i].KeyMessage == _NONE_KEY_MESSAGE)
         {
              //ucOsdEventMsg = _NONE_MSG;
              // End flag
              return 1;
         }
         if(ucKeyMessage == tMsgTable[i].KeyMessage)
         {
              ucOsdEventMsg = tMsgTable[i].OsdEvent;
              return 0;
         }

         i++;
     }
     return 1;
}                                        
//---------------------------------------------------------------------------

void CShortCutKeyMsg(void)
{
    if (ucOsdEventMsg >= _OE_CHANGE_SOURCE)
    {
        if (!CTVEnable() && ucOsdEventMsg >= _OE_SC_CH_DEC) // Only for TV
            ucOsdEventMsg = _NONE_MSG;
        else
            COsdDispOsdTimerEvent();
    }
}

//---------------------------------------------------------------------------
void CCoverKeyMsgToOsdEvent(SKeyToOsdEvent *tMsgTable,BYTE bUserPublicKeyEvnet)
{
     bit bFoundPublic = 1;

     if(tMsgTable != NULL)
         bFoundPublic = CFoundKeyMsgToOsdEvent(tMsgTable);

     if(bFoundPublic && bUserPublicKeyEvnet)
     {
         CFoundKeyMsgToOsdEvent(tKOPublic);
         CShortCutKeyMsg();
     }
}
//---------------------------------------------------------------------------
void InitOsdFrame(void)
{
    COsdFxDisableOsd();

#if(_LOGO_ENABLE)
    if (bLoadLogoFont)
    {       
        SetOsdMap(tUserMenuOsdMap);
        
        // Load global font 
        // insert code to here 
        COsdLoad1BitFont(FntGlobal,0x00,0x5F,tGlobalCharWidth);
        CScalerLoadHardwareVLCFont(FntMainIcon,0x80 * 2);
        
    	//Load Languege Font
    	LoadLanguageFont();
        bLoadLogoFont = 0;
    }
#endif

    SetOsdMap(tUserMenuOsdMap);
    COsdFxCodeWrite(ucCloseAllWindow);

	CScalerSetBit(_OVERLAY_CTRL_6C, 0x23, ((stOsdUserData.OsdBlending & 0x07) << 2));
    
    // Init osd
    // insert code to here
    OSDClear(ROW(0), HEIGHT(18), COL(0), WIDTH(46), 0x8C, BYTE_ATTRIB);
    OSDClear(ROW(0), HEIGHT(18), COL(0), WIDTH(46), 0x00, BYTE_DISPLAY);
	OSDClear(ROW(0), HEIGHT(18), COL(0), WIDTH(46), 0x40, BYTE_COLOR);
}     



//---------------------------------------------------------------------------
void CShowNoSignal(void)
{
	BYTE *pStr;
	
	InitOsdFrame();
    SetOSDDouble((GET_OSD_SIZE() ? 0x03 : 0x00)  | OSD_WINDOWCHAR_BLENDING);   
	
	// Draw Top Line
	OSDLine(ROW(1), COL(1), LENGTH(25), 0xA6, THE_BYTE0);
	OSDLine(ROW(1), COL(1), LENGTH(25), 0xA4, THE_BYTE1);
	OSDLine(ROW(1), COL(1), LENGTH(25), 0x11, THE_BYTE2);

	// Draw Bottom Line
	OSDLine(ROW(5), COL(1), LENGTH(25), 0xA6, THE_BYTE0);
	OSDLine(ROW(5), COL(1), LENGTH(25), 0xA4, THE_BYTE1);
	OSDLine(ROW(5), COL(1), LENGTH(25), 0x11, THE_BYTE2);

	OSDLine(ROW(3), COL(1), LENGTH(45), 0x10, BYTE_COLOR);

	// Draw Window
	COsdFxDrawWindow(0,0,								//WORD usXStart,WORD usYStart,  
					_DIALOG_WIDTH,_DIALOG_HEIGHT,		//WORD usXEnd,WORD usYEnd,  
					tMainWindowStyle);					//BYTE *pStyle)
	 
    CSetOSDPosition(_DIALOG_WIDTH, _DIALOG_HEIGHT, 50, 50);

	// Text out
	if(ucCurrState == _NOSIGNAL_STATE || _GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV)
		pStr = sNoSignal[GET_LANGUAGE()];
		
	else if(ucCurrState == _NOSUPPORT_STATE)
		pStr = sNotSupport[GET_LANGUAGE()];

	CCenterTextout(pStr,ROW(3),1,25);
	
	COsdFxEnableOsd();

}
//---------------------------------------------------------------------------
void CShowAutoAdjust(void)
{
	InitOsdFrame();
    SetOSDDouble((GET_OSD_SIZE() ? 0x03 : 0x00)  | OSD_WINDOWCHAR_BLENDING);   
	
	// Draw nosignal & set osd position

	// Draw Top Line
	OSDLine(ROW(1), COL(1), LENGTH(25), 0xA6, THE_BYTE0);
	OSDLine(ROW(1), COL(1), LENGTH(25), 0xA4, THE_BYTE1);
	OSDLine(ROW(1), COL(1), LENGTH(25), 0x11, THE_BYTE2);

	// Draw Bottom Line
	OSDLine(ROW(5), COL(1), LENGTH(25), 0xA6, THE_BYTE0);
	OSDLine(ROW(5), COL(1), LENGTH(25), 0xA4, THE_BYTE1);
	OSDLine(ROW(5), COL(1), LENGTH(25), 0x11, THE_BYTE2);

	OSDLine(ROW(3), COL(1), LENGTH(45), 0x10, BYTE_COLOR);

	// Draw Window
	COsdFxDrawWindow(0,0,								//WORD usXStart,WORD usYStart,  
					_DIALOG_WIDTH,_DIALOG_HEIGHT,		//WORD usXEnd,WORD usYEnd,  
					tMainWindowStyle);					//BYTE *pStyle)

    CSetOSDPosition(_DIALOG_WIDTH, _DIALOG_HEIGHT, 50, 50);
#if(_CHINESE_FONT_TYPE == _CHINESE_2_FONT)	
	LoadCHIFont(_LF_ADJUST_PAGE);
#endif
	CCenterTextout(sAutoConfig[GET_LANGUAGE()],ROW(3),1,25);
	
	COsdFxEnableOsd();

	CAutoDoAutoConfig();

	COsdFxDisableOsd();	
}
//---------------------------------------------------------------------------
#define _NOTE_WIDTH						(11 * 12 + 4)	
#define _NOTE_HEIGHT					(4 * 18)

void CShowNote(void)
{
	BYTE code *pStr; 
    
    ucOsdState = _MI_MENU_NONE;
    InitOsdFrame();
    SetOSDDouble(GET_OSD_SIZE() ? 0x03 : 0x00);   
    
	// Draw Top Line
	OSDLine(ROW(1), COL(1), LENGTH(8), 0xA6, THE_BYTE0);
	OSDLine(ROW(1), COL(1), LENGTH(8), 0xA4, THE_BYTE1);
	OSDLine(ROW(1), COL(1), LENGTH(8), 0x11, THE_BYTE2);

	// Draw Bottom Line
	OSDLine(ROW(3), COL(1), LENGTH(8), 0xA6, THE_BYTE0);
	OSDLine(ROW(3), COL(1), LENGTH(8), 0xA4, THE_BYTE1);
	OSDLine(ROW(3), COL(1), LENGTH(8), 0x11, THE_BYTE2);

	OSDLine(ROW(2), COL(1), LENGTH(45), 0x10, BYTE_COLOR);

	// TextOut
	switch(_GET_INPUT_SOURCE())
	{
		case _SOURCE_VGA:			pStr = sVGA;		break;
		case _SOURCE_DVI:			pStr = sDVI;		break;
		case _SOURCE_HDMI:			pStr = sHDMI;		break;
        case _SOURCE_YPBPR:         pStr = sYPBPR;      break;
		case _SOURCE_VIDEO_SV:		pStr = sSVideo;		break;
		case _SOURCE_VIDEO_AV:		pStr = sAV;			break;
		case _SOURCE_VIDEO_TV:		pStr = sTV;			break;
	}
	
	CCenterTextout(pStr,ROW(2),1,8);

	// Draw Window
	COsdFxDrawWindow(0,8,								//WORD usXStart,WORD usYStart,  
					_NOTE_WIDTH,_NOTE_HEIGHT,		    //WORD usXEnd,WORD usYEnd,  
					tMainWindowStyle);					//BYTE *pStyle)
	 
    if (GET_OSD_SIZE())
        OSDPosition(_OSD_DOUBLE_WIDTH(_NOTE_WIDTH), _OSD_DOUBLE_HEIGHT(_NOTE_HEIGHT), 0, 0, 0x03);
    else
        OSDPosition(_NOTE_WIDTH, _NOTE_HEIGHT, 5, 5, 0x03);
	
    COsdFxEnableOsd();
    CPowerPanelOn();  

    CTimerReactiveTimerEvent(SEC(5), COsdDispOsdTimerEvent);
    bOSDTimeOut = 0;
#if(_SLEEP_FUNC)
    bOSDOnScreen = 1;
#endif
}
//---------------------------------------------------------------------------



#if(_VIDEO_TV_SUPPORT)
//---------------------------------------------------------------------------
void CShowTVNumber(BYTE ucNumber, BYTE ucOption)
{ 
    BYTE PosX = 0;

    ucOsdState     = _MI_MENU_NONE;
    bChangeChannel = 0;
    COsdFxDisableOsd();

#if(_LOGO_ENABLE)
    if (bLoadLogoFont)
    {       
        SetOsdMap(tUserMenuOsdMap);
        
        // Load global font 
        // insert code to here 
        COsdLoad1BitFont(FntGlobal,0x00,0x5F,tGlobalCharWidth);
        CScalerLoadHardwareVLCFont(FntMainIcon,0x80 * 2);
        
    	//Load Languege Font
    	LoadLanguageFont();
        bLoadLogoFont = 0;
    }
#endif

    SetOSDDouble(0x03);
    SetOsdMap(tMsgOsdMap);
                         
    // Init OSD Ram
    OSDClear(0, 8, 0, 20, 0x8C, BYTE_ATTRIB);
    OSDClear(0, 8, 0, 20, 0x00, BYTE_DISPLAY);
    OSDClear(0, 8, 0, 20, 0xF0, BYTE_COLOR);
    
    COsdFxCodeWrite(ucCloseAllWindow);

    OSDPosition(_MAINMENU_WIDTH,_MAINMENU_HEIGHT,64,1,0x03);
                        
    if (ucOption & _SHOW_CH_TV_NUMBER) 
        CShowNumber(0, 0, ucNumber);

    if (_SHOW_CH_TV_TYPE & ucOption)
    {
    	BYTE *pStr;

    	switch(ucTVType)
    	{
    		case _TV_NTSC_M:		pStr = sNTSC_M;			break;
    		case _TV_NTSC_4_BG:		pStr = sNTSC_4_BG;		break;
    		case _TV_NTSC_4_DK:		pStr = sNTSC_4_DK;		break;
    		case _TV_NTSC_4_I:		pStr = sNTSC_4_I;		break;
    		case _TV_PAL_M:		    pStr = sPAL_M;			break;
    		case _TV_PAL_BG:		pStr = sPAL_BG;			break;
    		case _TV_PAL_I:			pStr = sPAL_I;			break;
    		case _TV_PAL_DK:		pStr = sPAL_DK;			break;
    		case _TV_PAL_N:			pStr = sPAL_N;			break;
    		case _TV_SECAM_BG:		pStr = sSECAM_BG;		break;
    		case _TV_SECAM_DK:		pStr = sSECAM_DK;		break;
    		case _TV_SECAM_L:		pStr = sSECAM_L;		break;
    		case _TV_SECAM_LL:		pStr = sSECAM_L;		break;
        }

        CTextOutEx(pStr, 0, 1);  
    }

    COsdFxEnableOsd();
    CTimerReactiveTimerEvent(SEC(5), COsdDispOsdTimerEvent);
    bOSDTimeOut  = 0;

	#if(_SLEEP_FUNC)
    bOSDOnScreen = 1;
	#endif
}
#endif // #if(_VIDEO_TV_SUPPORT)



//---------------------------------------------------------------------------
void Draw2bit3x2Icon(BYTE *tIcon,BYTE x,BYTE y)
{
     Gotoxy(x,y,ALL_BYTE);

     pData[0] = tIcon[0]; 
     pData[1] = tIcon[1];
     pData[2] = tIcon[2];
     
     pData[3] = tIcon[0];
     pData[4] = tIcon[1] + 1;
     pData[5] = tIcon[2];

     pData[6] = tIcon[0];
     pData[7] = tIcon[1] + 2;
     pData[8] = tIcon[2];     
     
     CScalerWrite(_OSD_DATA_PORT_92, 9, pData, _NON_AUTOINC);

     Gotoxy(x,y + 1,ALL_BYTE);

     pData[0] = tIcon[0]; 
     pData[1] = tIcon[1] + 3;
     pData[2] = tIcon[2];
     
     pData[3] = tIcon[0];
     pData[4] = tIcon[1] + 4;
     pData[5] = tIcon[2];

     pData[6] = tIcon[0];
     pData[7] = tIcon[1] + 5;
     pData[8] = tIcon[2];
     
     CScalerWrite(_OSD_DATA_PORT_92, 9, pData, _NON_AUTOINC);
}

//---------------------------------------------------------------------------
BYTE AdjustMenuItem(BYTE ucBeginItem,BYTE ucEndItem,BYTE ucMode)
{
     BYTE i;
     BYTE ucCount;
     BYTE ucNewItem;

     CLR_KEYREPEATENABLE();

     //如果菜单只有一项,直接返回
     ucCount = ucEndItem - ucBeginItem;
     if(ucCount < 1)
     {
          return ucOsdState;
     }

     // 计算下一项菜单，或是上一菜单
     i = 0;

     ucNewItem = ucOsdState;

     while(i < ucCount)
     {

         ucNewItem = ValueInRangeChange(ucBeginItem, ucEndItem, ucNewItem, ucMode | _LOOP);

         if(g_tMenuItem[ucNewItem].Enable())
         {
             break;
         }

         i++;
     }

     return ucNewItem;
}
//----------------------------------------------------------------------------------------------------
BYTE GetShowIndex(BYTE ucMenuItem,BYTE ucBeginItem,BYTE ucEndItem)
{
     BYTE Index;

     bit fEnable;
     bit fDisableNoShow;

     Index = 0;

     while(ucBeginItem <= ucEndItem)
     {
     	fEnable = g_tMenuItem[ucBeginItem].Enable();
		if((g_tMenuItem[ucBeginItem].Option & _DISABLE_NOT_SHOW) != _DISABLE_NOT_SHOW)
			fDisableNoShow = 0;
		else
			fDisableNoShow = 1;

			
     	if(ucBeginItem == ucMenuItem)
     	{
     		if(fEnable)		
     		{
     			return Index;
     		}
     		else
     		{
				if(fDisableNoShow)
					return _NOT_SHOW;
				else
					return Index;
     		}
     	}

     	if(ucBeginItem > ucMenuItem)
     		return _NOT_SHOW;
     		
       	if(!fDisableNoShow)
       	{	
        	Index++;
        }
        else
        {
        	if(fEnable)
        	{
            	Index++;
            }
		}
        ucBeginItem++;
     }

     return _NOT_SHOW;     
}
//----------------------------------------------------------------------------------------------------
BYTE GetShowCount(BYTE ucBeginItem,BYTE ucEndItem)
{
     BYTE ucCount;

     bit fEnable;
     bit fDisableNoShow;


     ucCount = 0;

     while(ucBeginItem <= ucEndItem)
     {
     	fEnable = g_tMenuItem[ucBeginItem].Enable();
     	
		if((g_tMenuItem[ucBeginItem].Option & _DISABLE_NOT_SHOW) != _DISABLE_NOT_SHOW)
			fDisableNoShow = 0;
		else
			fDisableNoShow = 1;
     		
       	if(!fDisableNoShow)
       	{	
        	ucCount++;
        }
        else
        {
        	if(fEnable)
        	{
            	ucCount++;
            }
		}
        ucBeginItem++;
     }

     return ucCount;     
}
//----------------------------------------------------------------------------------------------------
void TextOutCalcWidth(BYTE *pStr,BYTE row,BYTE col,BYTE ucMaxLength,BYTE ucDisplayPixcel)
{
     BYTE ucPixLen = CTextOutBase(pStr, col, row);
     BYTE i = StrLen(pStr);

     ucMaxLength -= 1;

     CScalerSendAddr(_OSD_DATA_PORT_92, _NON_AUTOINC);

     for(;i<ucMaxLength;i++)
     {
         *(&MCU_SCA_INF_DATA_FFF5) = (0x80 | 4);
         ucPixLen += 4;
     }
     
     // 计算 Blank 宽度
     ucPixLen = ucDisplayPixcel - ucPixLen;

     //设置 Blank                                                       
     Gotoxy(col + ucMaxLength,row,ALL_BYTE);

     pData[0] = 0x00;
     pData[1] = ucPixLen;
     CScalerWrite(_OSD_DATA_PORT_92, 2, pData, _NON_AUTOINC);
}
//---------------------------------------------------------------------------


void CSetMuteState(void)
{
    if (GET_AUDIO_MUTE()) // Mute on 
        CLR_AUDIO_MUTE();
    else
        SET_AUDIO_MUTE();

    CDrawMuteState();

#if(_VIDEO_TV_SUPPORT)
 #if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
    if ((_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV && gmi_CModeLocked()) || _GET_INPUT_SOURCE() != _SOURCE_VIDEO_TV)
 #endif
#endif
       CSetVolume();
    ucOsdEventMsg = _SAVE_EE_AUDIO_DATA_MSG;
}

//-----------------------------------------------------------------------
void CDrawMuteState(void)
{           
    ucOsdState     = _MI_MENU_NONE;
#if(_VIDEO_TV_SUPPORT)
    bChangeChannel = 0;
#endif
    COsdFxDisableOsd();
#if(_LOGO_ENABLE)
    if (bLoadLogoFont)
    {       
        SetOsdMap(tUserMenuOsdMap);
        
        // Load global font 
        // insert code to here 
        COsdLoad1BitFont(FntGlobal,0x00,0x5F,tGlobalCharWidth);
        CScalerLoadHardwareVLCFont(FntMainIcon,0x80 * 2);
        
    	//Load Languege Font
    	LoadLanguageFont();
        bLoadLogoFont = 0;
    }
#endif

    SetOSDDouble(0x03);
    SetOsdMap(tMsgOsdMap);
                         
    // Init OSD Ram
    OSDClear(0, 8, 0, 10, 0x8C, BYTE_ATTRIB);
    OSDClear(0, 8, 0, 10, 0x00, BYTE_DISPLAY);
    OSDClear(0, 8, 0, 10, 0xF0, BYTE_COLOR);
    
    COsdFxCodeWrite(ucCloseAllWindow); 
 
    OSDPosition(6 * 12, 4 * 18, 44, 0, 0x03);
    if (GET_AUDIO_MUTE()) // Mute on 
       COsdLoad1BitFont(FntMute, 0x7A, 6, tFntVolumeCharWidth);
    else
       COsdLoad1BitFont(FntVolume, 0x7A, 6, tFntVolumeCharWidth);  
                                              
    // Display Volume/Mute icon
    Gotoxy(0, 1, BYTE_DISPLAY);
    OutputChar(0x7A);
    OutputChar(0x7B);
    OutputChar(0x7C);
    Gotoxy(0, 2, BYTE_DISPLAY);
    OutputChar(0x7D);
    OutputChar(0x7E);
    OutputChar(0x7F);
    COsdFxDrawWindow(0,16,                               //WORD usXStart,WORD usYStart,  
                        54,52,       //WORD usXEnd,WORD usYEnd,  
                        tMainWindowStyle);                  //BYTE *pStyle)

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

    bOSDTimeOut  = 0;
    bOSDOnScreen = 1;
}

//-----------------------------------------------------------------------
#if(_VIDEO_TV_SUPPORT)
#if(_SHOW_TV_NO_SIGNAL)
   
#if(_LOGO_ENABLE)
#define _H_POS_MAX         ((DWORD)((Panel[ucPanelSelect]->DHWidth - _LOGO_WIDTH)/4 - 12))
#define _V_POS_MAX         ((DWORD)((Panel[ucPanelSelect]->DVHeight - _LOGO_HEIGHT)/4 - 6))
#define _H_DOUBLE_POS_MAX  ((DWORD)((Panel[ucPanelSelect]->DHWidth - _OSD_DOUBLE_WIDTH(_LOGO_WIDTH))/4 - 12))
#define _V_DOUBLE_POS_MAX  ((DWORD)((Panel[ucPanelSelect]->DVHeight - _OSD_DOUBLE_HEIGHT(_LOGO_HEIGHT))/4 - 6))
#else
#define _H_POS_MAX         ((DWORD)((Panel[ucPanelSelect]->DHWidth - _DIALOG_WIDTH)/4 - 12))
#define _V_POS_MAX         ((DWORD)((Panel[ucPanelSelect]->DVHeight - _DIALOG_HEIGHT)/4 - 6))
#define _H_DOUBLE_POS_MAX  ((DWORD)((Panel[ucPanelSelect]->DHWidth - _OSD_DOUBLE_WIDTH(_DIALOG_WIDTH))/4 - 12))
#define _V_DOUBLE_POS_MAX  ((DWORD)((Panel[ucPanelSelect]->DVHeight - _OSD_DOUBLE_HEIGHT(_DIALOG_HEIGHT))/4 - 6))
#endif

void OSDMove(WORD usOsdActWidth, WORD usOsdActHeight, WORD ucHPos, WORD ucVPos, BYTE ucPar)
{              
    usOsdActWidth  = _OSD_HPOSITION_OFFSET + 
                    (DWORD)(Panel[ucPanelSelect]->DHStartPos / 4) + ucHPos;

    usOsdActHeight = _OSD_VPOSITION_OFFSET + 
                    (DWORD)(Panel[ucPanelSelect]->DVStartPos / 4) + ucVPos;


    CScalerSetBit(_OSD_SCRAMBLE_93, 0xf8, 0x02);

    pData[0] = CScalerGetBit(_OVERLAY_CTRL_6C, _BIT0);

    pData[0] = (pData[0] == 0x00) ? 0xc0 : 0xe0;
    pData[1] = 0x00;
    CScalerWrite(_OSD_ADDR_MSB_90, 2, pData, _AUTOINC);

	pData[0] = usOsdActHeight >> 1;
	pData[1] = (UINT8) (usOsdActWidth >> 2);
	pData[2] = ((UINT8) (usOsdActWidth & 0x0003) << 6) |	((usOsdActHeight & 0x01) << 5) | ucPar;
	CScalerWrite(_OSD_DATA_PORT_92, 3, pData, _NON_AUTOINC);
 
    CTimerWaitForEvent(_EVENT_DEN_STOP);
    CTimerWaitForEvent(_EVENT_DEN_STOP);
    CScalerSetBit(_OSD_SCRAMBLE_93, 0xf8, 0x05);
}

//-----------------------------------------------------------------------
#define _ON_SCREEN_STATE    1
#define _MOVE_STATE         2
void CCheckTVSignal(void)
{
    static WORD ucPosX  = 0;
    static WORD ucPosY  = 0;
    static BYTE ucDir   = 0;

    if (_GET_INPUT_SOURCE() != _SOURCE_VIDEO_TV || bOSDOnScreen == 1 || ucOsdState != _MI_MENU_NONE)
        return;

    if (ucLogoMoveCount > 250)
        ucLogoMoveCount = 0;
    else
        return; 

    if (bTVNoSignal)
    {         
        switch(ucSignalOSDState)
        {
        case 0:
            ucNoSigCount++;
            if (ucNoSigCount > 15)
            {
#if(_CHINESE_FONT_TYPE == _CHINESE_2_FONT)
                LoadCHIFont(_LF_OTHER);
#endif
#if(_LOGO_ENABLE)
                CDrawLogo((GET_OSD_SIZE()) ? 0x03 : 0x00);
#else
                CShowNoSignal();
#endif
                CTimerCancelTimerEvent(COsdDispOsdTimerEvent);
                ucSignalOSDState = _ON_SCREEN_STATE;
            }
            break;

        case _ON_SCREEN_STATE:
            if (GET_OSD_SIZE())
            {
                ucPosX = _H_DOUBLE_POS_MAX/2;
                ucPosY = _V_DOUBLE_POS_MAX/2;
            }
            else
            {
                ucPosX = _H_POS_MAX/2;
                ucPosY = _V_POS_MAX/2;
            }
            ucDir  = _BIT1;
            ucDir  |= _BIT5;
            ucSignalOSDState = _MOVE_STATE;
            break;

        case _MOVE_STATE:
            if (GET_OSD_SIZE())
            {
                if (ucPosX >= _H_DOUBLE_POS_MAX)   ucDir = (ucDir & 0xf0) | _BIT0; // --
                if (ucPosY >= _V_DOUBLE_POS_MAX)   ucDir = (ucDir & 0x0f) | _BIT4; // --
            }
            else
            {
                if (ucPosX >= _H_POS_MAX)   ucDir = (ucDir & 0xf0) | _BIT0; // --
                if (ucPosY >= _V_POS_MAX)   ucDir = (ucDir & 0x0f) | _BIT4; // --
            }
            if (ucPosX == 0)            ucDir = (ucDir & 0xf0) | _BIT1; // ++           
            if (ucPosY == 0)            ucDir = (ucDir & 0x0f) | _BIT5; // ++
            
            if (ucDir & _BIT0)          ucPosX--;
            if (ucDir & _BIT1)          ucPosX++;
            if (ucPosY < 2)             ucPosY = 2;
            if (ucDir & _BIT4)          ucPosY-=2;
            if (ucDir & _BIT5)          ucPosY+=2;

#if(_LOGO_ENABLE)               
            if (GET_OSD_SIZE())
                OSDMove(_OSD_DOUBLE_WIDTH(_LOGO_WIDTH), _OSD_DOUBLE_HEIGHT(_LOGO_HEIGHT), ucPosX, ucPosY, 0x03);
            else
                OSDMove(_LOGO_WIDTH, _LOGO_HEIGHT, ucPosX, ucPosY, 0x03);
#else
            if (GET_OSD_SIZE())
                OSDMove(_OSD_DOUBLE_WIDTH(_DIALOG_WIDTH), _OSD_DOUBLE_HEIGHT(_DIALOG_HEIGHT), ucPosX, ucPosY, 0x03);
            else
                OSDMove(_DIALOG_WIDTH, _DIALOG_HEIGHT, ucPosX, ucPosY, 0x03);
#endif            
	        break;
        }
    }
    else
    {
        if (ucSignalOSDState)
        {
            ucNoSigCount = 0;
            COsdFxDisableOsd();
        }
    }
}
#endif // #if(_SHOW_TV_NO_SIGNAL)
#endif // #if(_VIDEO_TV_SUPPORT)

//----------------------------------------------------------------------------------------------------
#if(_LOGO_ENABLE)
BYTE code tLogoOsdMap[] =
{ 
    6,         // Row Count
    LOBYTE(0x300),HIBYTE(0x300),
    21,   // Row 0 char count
    21,   // Row 1 char count
    21,   // Row 2 char count
    21,   // Row 3 char count
    21,   // Row 4 char count
    21,   // Row 5 char count
};

void CDrawLogo(BYTE ucDouble)
{
    BYTE x;
    BYTE y;
    BYTE ucFont = 0x00;
	
    COsdFxDisableOsd();

    SetOsdMap(tLogoOsdMap);
    COsdColorPalette(tPALETTE_0);
    COsdFxCodeWrite(ucCloseAllWindow);
    COsdLoad1BitFontWidth12(FntLogo, 0x00, 0x72);
    // Dot 0
    COsdLoad1BitFontWidth12(FntLogoDotUpSide0, 0x72, 0x03);
    CScalerLoadHardwareVLCFont(FntLogoDotDownSide0_2Bit,0x80 * 2);
    // Dot 1
    CScalerLoadHardwareVLCFont(FntLogoDot1_2Bit,0x83 * 2);
    // Dot 2
    CScalerLoadHardwareVLCFont(FntLogoDot2_2Bit,0x89 * 2);
    // Dot 3
    COsdLoad1BitFontWidth12(FntLogoDot3, 0x75, 0x04);

	CScalerSetBit(_OVERLAY_CTRL_6C, 0x23, ((0x00) << 2));
    
    bLoadLogoFont = 1;

    // Init osd
    // insert code to here
    OSDClear(ROW(0), HEIGHT(6), COL(0), WIDTH(21), 0x8C, BYTE_ATTRIB);
    OSDClear(ROW(0), HEIGHT(6), COL(0), WIDTH(21), 0x00, BYTE_DISPLAY);
	OSDClear(ROW(0), HEIGHT(6), COL(0), WIDTH(21), 0xA0, BYTE_COLOR);
    SetOSDDouble(ucDouble);   
	
    if (ucDouble)
        OSDPosition(_OSD_DOUBLE_WIDTH(_LOGO_WIDTH), _OSD_DOUBLE_HEIGHT(_LOGO_HEIGHT), 50, 50, 0x03);
    else
        OSDPosition(_LOGO_WIDTH, _LOGO_HEIGHT, 50, 50, 0x03);

    // 1BIT font
    for(y = 0; y < 6; y++)
    {
        for(x = 0; x < 19; x++)
        {  
            Gotoxy(x, y, BYTE_DISPLAY);
            OutputChar(ucFont);
            ucFont++;
        }
    }
	OSDClear(ROW(0), HEIGHT(1), COL(16), WIDTH(3), 0xC0, BYTE_COLOR);
    Gotoxy(16, 0, BYTE_DISPLAY);
    OutputChar(0x72);
    OutputChar(0x73);
    OutputChar(0x74);

    // 2bit font 0
	OSDLine(ROW(1), COL(16), LENGTH(3), 0xF8, THE_BYTE0);
	OSDLine(ROW(1), COL(16), LENGTH(3), 0x02, BYTE_COLOR);
    Gotoxy(16, 1, BYTE_DISPLAY);
    OutputChar(0x80);
    OutputChar(0x81);
    OutputChar(0x82);

    // 2bit font 1
	OSDClear(ROW(4), HEIGHT(2), COL(6), WIDTH(3), 0xB0, THE_BYTE0);
	OSDClear(ROW(4), HEIGHT(2), COL(6), WIDTH(3), 0x1A, BYTE_COLOR);
    Gotoxy(6, 4, BYTE_DISPLAY);
    OutputChar(0x83);
    OutputChar(0x84);
    OutputChar(0x85);
    Gotoxy(6, 5, BYTE_DISPLAY);
    OutputChar(0x86);
    OutputChar(0x87);
    OutputChar(0x88);
              
    // 2bit font 2
	OSDClear(ROW(4), HEIGHT(2), COL(15), WIDTH(4), 0xB0, THE_BYTE0);
	OSDClear(ROW(4), HEIGHT(2), COL(15), WIDTH(4), 0x1A, BYTE_COLOR);
    Gotoxy(15, 4, BYTE_DISPLAY);
    OutputChar(0x89);
    OutputChar(0x8A);
    OutputChar(0x8B);
    OutputChar(0x8C);
    Gotoxy(15, 5, BYTE_DISPLAY);
    OutputChar(0x8D);
    OutputChar(0x8E);
    OutputChar(0x8F);
    OutputChar(0x90);
                

    // 1bit font 3
	OSDClear(ROW(4), HEIGHT(2), COL(19), WIDTH(2), 0xB0, BYTE_COLOR); 
    Gotoxy(19, 4, BYTE_DISPLAY);
    OutputChar(0x75);
    OutputChar(0x76);
    Gotoxy(19, 5, BYTE_DISPLAY);
    OutputChar(0x77);
    OutputChar(0x78);
	
	COsdFxEnableOsd();
}

//----------------------------------------------------------------------------------------------------
void CPattenChange(void)
{
	BYTE ucPatten[9];
    BYTE ucTemp;

    // 0x0A
    ucPatten[0] = tPALETTE_0[30];//0x33;
    ucPatten[1] = tPALETTE_0[31];//0x6A;
    ucPatten[2] = tPALETTE_0[32];//0xA5;
    // 0x0B
    ucPatten[3] = tPALETTE_0[33];//0x94;
    ucPatten[4] = tPALETTE_0[34];//0xBD;
    ucPatten[5] = tPALETTE_0[35];//0x35;
    // 0x0C
    ucPatten[6] = tPALETTE_0[36];//0xF3;
    ucPatten[7] = tPALETTE_0[37];//0x94;
    ucPatten[8] = tPALETTE_0[38];//0x28;

    for(ucTemp = 0; ucTemp < 9; ucTemp++)
    {
        ucPatten[ucTemp] -= 0x28;
    }

    while(ucPatten[6] != 0xFF)
    {
    	CScalerSetByte(_OVERLAY_LUT_ADDR_6E, 0x80 | 0x1E);
    	CScalerWrite(_COLOR_LUT_PORT_6F, 3, &ucPatten, _NON_AUTOINC);
    	CScalerSetByte(_OVERLAY_LUT_ADDR_6E, 0x00);
        CTimerDelayXms(30);

        for(ucTemp = 0; ucTemp < 9; ucTemp++)
        {
            ucPatten[ucTemp]++;
        }
    }

    while(ucPatten[8])
    {
    	CScalerSetByte(_OVERLAY_LUT_ADDR_6E, 0x80 | 0x1E);
    	CScalerWrite(_COLOR_LUT_PORT_6F, 3, &ucPatten, _NON_AUTOINC);
    	CScalerSetByte(_OVERLAY_LUT_ADDR_6E, 0x00);
        CTimerDelayXms(30);

        for(ucTemp = 0; ucTemp < 9; ucTemp++)
        {
            ucPatten[ucTemp]--;
        }
    }
}
   
#endif



//----------------------------------------------------------------------------------------------------
void CNotUse(void)
{
/*
	CAdjustMZHueSat(0);
	CEepromSaveHueSatData();
	CKeyScanReadyTimerEvent();
	CKeyRepeatEnableTimerEvent();
	CAutoDoAutoConfig();

	CAutoDoWhiteBalance();
	CEepromSaveOsdUserData();
	CEepromSaveBriConData();
	CEepromSaveColorTempData();
	CEepromSaveTvData();
	CScalerWriteAmount(0,0,0,0);

	SetOsdMap(0);
	SetOSDRamAddress();
	DirectWOSDRam(0, 0, 0, 0);
	SetRowCmds();
	Gotoxy(0, 0, 0);
	OutputChar(0);

	COsdFxCloseWindow(0);
	ValueInRangeChange(0, 0, 0, 0);
	Textout(0);
	StrLen(0);
	OSDPosition(0, 0, 0, 0, 0);
	OSDClear(0, 0, 0, 0, 0,0);
	COsdFxCodeWrite(0);
	COsdFxGetAdcClockRange(0);
	InitBurnIn();
	BurnInRun();
    CKeyScanReady();

    CSetPWM(0, 0);
    OSDSlider(0, 0, 0, 0, 0,0);

	COsdCtrlGetHPosition();
	COsdCtrlGetVPosition();
	COsdCtrlGetClock();
    CDoReset();

    AdjustMenuItem(0,0,0);

	CEnable();
	CVideoEnable();
	CVgaEnable();
	CDviEnable();
	CTVEnable();
   
	CHDMIEnable();
    Draw2bit3x2Icon(0,0,0);
              */
    EnterSystemMenu(); 
    //CSetTVSignalWidth();
    bChangeSource();
    CAdjustMZHueSat(0);
//    ChangeSourceHandler();
    CTextOutRightAlign(0,0,0);
	COsdCtrlGetPhase();
    GetNextLanguage(0);
	GetPrevLanguage(0);
#if(_VIDEO_TV_SUPPORT)
    #if(_FM_DEVICE)
    CChangeFM();
    #else
//    CFMInit();
    #endif
    CShowTimer();
    CSaveChannelSoundType(stTvInfo.CurChn, 0);
    gmi_CReadIfPllDM();
#endif
    CCenterTextout(" ",ROW(1),COL(0),0);
    COsdLoad1BitFont(0, 0x00, 123, 0);
}
//--------------------------------------------------

#endif			//#if(_OSD_TYPE == _OSD003)
