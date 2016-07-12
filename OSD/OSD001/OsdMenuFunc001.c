

#define __OSDDRAW001__


#include "Core\Header\Include.h"

#if(_OSD_TYPE == _OSD001)
//-------------------------------------------------------------------

void CDrawNull(BYTE ucDrawID)
{
     ucDrawID = ucDrawID;
}

//-------------------------------------------------------------------
bit CMIVedio8Enable(void)
{
	if(bSourceVideo())
    	return 1;
    else return 0;
}

//----------------------------------------------------------------------------------------------------
bit CMIVGAEnable(void)
{
	if(_GET_INPUT_SOURCE() == _SOURCE_VGA)
    	return 1;
    else return 0;
}

//----------------------------------------------------------------------------------------------------
bit CMITVEnable(void)
{
	if(_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV)
    	return 1;
    else return 0;
}

//========================================= MenuNone =================================================
/*
void CMenuNoneLRKey(bit bKey)
{
    switch(_GET_INPUT_SOURCE())
    {
    case _SOURCE_VGA:
    case _SOURCE_DVI:
    case _SOURCE_HDMI:
    case _SOURCE_YPBPR:
    case _SOURCE_VIDEO_AV:
    case _SOURCE_VIDEO_SV:       break;
#if(_VIDEO_TV_SUPPORT)
    case _SOURCE_VIDEO_TV:       CChangeChannel(bKey);     break;
#endif
    } 
}
 */
//----------------------------------------------------------------------------------------------------
void CMIMenuNoneRun(BYTE ucMode)
{
    switch(ucMode)
    {      /*
    case _MENU_ADJ_DEC:
        CMenuNoneLRKey(0);
        break;

    case _MENU_ADJ_INC:
        CMenuNoneLRKey(1);
        break; */
    }
}

//----------------------------------------------------------------------------------------------------
void CPDrawMainMenu(BYTE ucDrawID)
{
    switch(ucDrawID)
    {
        // Menu Draw ID
        case _DRAW_ENTER_MENU:              //进入当前的菜单时调用
#if(_UART_SND_EN == _ON)
        	 CUartSendString("Init Osd.\n");
#endif        	 
             InitOsdFrame();
			 OSDPosition(_MAINMENU_WIDTH * 12,_MAINMENU_HEIGHT * 18,50,85,0x03);
             
             CURRENT_MENU_ITEM.Draw(_DRAW_MENU_ITEM);
             COsdFxEnableOsd();
             break;
             
        case _DRAW_BEFORE_RETURN_PARENTMENU://返回到上一级菜单之前...
             COsdFxDisableOsd();
        	 break;
        case _DRAW_BEFORE_ENTER_SUBMENU:    //进入子菜单之前...
        case _DRAW_FROM_SUBMENU_RETURN:     //从子菜单返回
             break;
    }
}

//----------------------------------------------------------------------------------------------------
void CClearMsg(void)
{
    OSDClear(1, 1, 0, _MAINMENU_WIDTH + 3, 0x00, BYTE_DISPLAY);
    OSDClear(1, 1, 0, _MAINMENU_WIDTH + 3, 0x8c, BYTE_ATTRIB);
}

//========================== Brightness =================================
#define DRAW_SLIDER(x)		OSDSlider(1, 2, 10, x, 100,0x60)

void CMIDrawBrightness(BYTE ucDrawID)
{
     switch(ucDrawID)
     {
         case _DRAW_SELECT:           //选中状态
         case _DRAW_MENU_ITEM:        //画菜单项
              CCenterTextout(sBrightness[GET_LANGUAGE()],ROW(0),COL(0),_MAINMENU_WIDTH);
              DRAW_SLIDER(stConBriData.Brightness);
              break;
              
         case _DRAW_NORMARL:          //标准状态
             CClearClientOSD();
             break;

         case _DRAW_DISABLE:          //禁用状态
             break;
     }
}

//----------------------------------------------------------------------
void CMIBrightnessRun(BYTE ucMode)
{
     switch(ucMode)
     {
		case _MENU_ADJ_DEC:
		case _MENU_ADJ_INC:
             SET_KEYREPEATENABLE();
		     stConBriData.Brightness = ValueInRangeChange(0, 100, stConBriData.Brightness, _NON_LOOP | ucMode);
			 DRAW_SLIDER(stConBriData.Brightness);
             CAdjustBrightness();
             ucOsdEventMsg = _SAVE_EE_COLORPROC0_MSG;
		     break;
		     
		case _MENU_RUN:
		     break;
     }
}

//========================== Contrast =================================
void CMIDrawContrast(BYTE ucDrawID)
{
     switch(ucDrawID)
     {
         case _DRAW_SELECT:           //选中状态
         case _DRAW_MENU_ITEM:        //画菜单项
             CCenterTextout(sContrast[GET_LANGUAGE()],ROW(0),COL(0),_MAINMENU_WIDTH);
             DRAW_SLIDER(stConBriData.Contrast);
             break;
             
         case _DRAW_NORMARL:          //标准状态
             CClearClientOSD();
             break;
             
         case _DRAW_DISABLE:          //禁用状态
             break;
     }
}   

//-----------------------------------------------------------------------
void CMIContrastRun(BYTE ucMode)
{
     switch(ucMode)
     {
		case _MENU_ADJ_DEC:
		case _MENU_ADJ_INC:
             SET_KEYREPEATENABLE();
            stConBriData.Contrast = ValueInRangeChange(0, 100, stConBriData.Contrast, _NON_LOOP | ucMode);
            DRAW_SLIDER(stConBriData.Contrast);
            CAdjustBrightness();
            ucOsdEventMsg = _SAVE_EE_COLORPROC0_MSG;
		    break;
		case _MENU_RUN:
		    break;
     }
}

//========================== Hue =================================
void CMIDrawHue(BYTE ucDrawID)
{
     switch(ucDrawID)
     {
         case _DRAW_SELECT:           //选中状态
         case _DRAW_MENU_ITEM:        //画菜单项
             CCenterTextout(sHue[GET_LANGUAGE()],ROW(0),COL(0),_MAINMENU_WIDTH);
             DRAW_SLIDER(GET_HUE());
             break;
             
         case _DRAW_NORMARL:          //标准状态
             CClearClientOSD();
             break;
             
         case _DRAW_DISABLE:          //禁用状态
             break;
     }
}

//-----------------------------------------------------------------------
void CMIHueRun(BYTE ucMode)
{
     switch(ucMode)
     {
		case _MENU_ADJ_DEC:
		case _MENU_ADJ_INC:
            SET_KEYREPEATENABLE();
            stHueSatData.Hue = ValueInRangeChange(0, 100, stHueSatData.Hue, _NON_LOOP | ucMode);
            DRAW_SLIDER(GET_HUE());
	        if(bSourceVideo())
                gmi_CAdjustVDCHue(stHueSatData.Hue);
            else
                CAdjustYpbprhue(stHueSatData.Hue);
            ucOsdEventMsg = _SAVE_EE_HUE_SAT_DATA_MSG;
		    break;
		case _MENU_RUN:
		    break;
     }
}

//========================== Saturation =================================
void CMIDrawSaturation(BYTE ucDrawID)
{
     switch(ucDrawID)
     {
         case _DRAW_SELECT:           //选中状态
         case _DRAW_MENU_ITEM:        //画菜单项
             CCenterTextout(sSaturation[GET_LANGUAGE()],ROW(0),COL(0),_MAINMENU_WIDTH);
             DRAW_SLIDER(GET_SATURATION());
             break;
             
         case _DRAW_NORMARL:          //标准状态
             CClearClientOSD();
             break;
             
         case _DRAW_DISABLE:          //禁用状态
             break;
     }
}

//-----------------------------------------------------------------------
void CMISaturationRun(BYTE ucMode)
{
     switch(ucMode)
     {
		case _MENU_ADJ_DEC:
		case _MENU_ADJ_INC:
            SET_KEYREPEATENABLE();
            stHueSatData.Saturation = ValueInRangeChange(0, 100, stHueSatData.Saturation, _NON_LOOP | ucMode);
            DRAW_SLIDER(GET_SATURATION());
            if (bSourceVideo())
               CVideoSetSaturation(GET_SATURATION());
            else
               CAdjustYpbprSaturation(GET_SATURATION());
            ucOsdEventMsg = _SAVE_EE_HUE_SAT_DATA_MSG;
		    break;
		case _MENU_RUN:
		    break;
     }
}

//========================== Phase =================================
void CMIDrawPhase(BYTE ucDrawID)
{
     switch(ucDrawID)
     {
         case _DRAW_SELECT:           //选中状态
         case _DRAW_MENU_ITEM:        //画菜单项
             CCenterTextout(sPhase[GET_LANGUAGE()],ROW(0),COL(0),_MAINMENU_WIDTH);
             DRAW_SLIDER(50);
             break;
             
         case _DRAW_NORMARL:          //标准状态
             CClearClientOSD();
             break;
             
         case _DRAW_DISABLE:          //禁用状态
             break;
     }
}

//-----------------------------------------------------------------------
void CMIPhaseRun(BYTE ucMode)
{
     switch(ucMode)
     {
		case _MENU_ADJ_DEC:
		case _MENU_ADJ_INC:
             SET_KEYREPEATENABLE();
            //stConBriData.Contrast = ValueInRangeChange(0, 100, stConBriData.Contrast, _NON_LOOP | ucMode);
            DRAW_SLIDER(50);
		    break;
		case _MENU_RUN:
		    break;
     }
}

//========================== Clock =================================
void CMIDrawClock(BYTE ucDrawID)
{
     switch(ucDrawID)
     {
         case _DRAW_SELECT:           //选中状态
         case _DRAW_MENU_ITEM:        //画菜单项
             CCenterTextout(sClock[GET_LANGUAGE()],ROW(0),COL(0),_MAINMENU_WIDTH);
             DRAW_SLIDER(50);
             break;
             
         case _DRAW_NORMARL:          //标准状态
             CClearClientOSD();
             break;
             
         case _DRAW_DISABLE:          //禁用状态
             break;
     }
}

//-----------------------------------------------------------------------
void CMIClockRun(BYTE ucMode)
{
     switch(ucMode)
     {
		case _MENU_ADJ_DEC:
		case _MENU_ADJ_INC:
             SET_KEYREPEATENABLE();
            //stConBriData.Contrast = ValueInRangeChange(0, 100, stConBriData.Contrast, _NON_LOOP | ucMode);
            DRAW_SLIDER(50);
		    break;
		case _MENU_RUN:
		    break;
     }
}     

//========================== DisplayMode =================================
void CDrawDisplayModeState(void)
{
    BYTE ucColor1,ucColor2;

    if(GET_DISPLAYMODE() == _DISPMODE_FULL)
    {
        ucColor1 = 0x60;
        ucColor2 = 0x80;
    }
    else		// 4:3
    {
        ucColor1 = 0x80;
        ucColor2 = 0x60;
    }

    OSDLine(1, 0,  10, ucColor1, BYTE_COLOR);
    OSDLine(1, 10, 10, ucColor2, BYTE_COLOR);
} 

//-----------------------------------------------------------------------
void CMIDrawDisplayMode(BYTE ucDrawID)
{
     switch(ucDrawID)
     {
         case _DRAW_SELECT:           //选中状态
         case _DRAW_MENU_ITEM:        //画菜单项
             
             CCenterTextout(sDisplayMode[GET_LANGUAGE()],ROW(0),COL(0),_MAINMENU_WIDTH);
			 CCenterTextout(sFull[GET_LANGUAGE()],ROW(1),COL(0),10);
			 CCenterTextout(sDM4_3[GET_LANGUAGE()],ROW(1),COL(10),10);
			 CDrawDisplayModeState();
             break;
             
         case _DRAW_NORMARL:          //标准状态
             CClearClientOSD();
             break;
             
         case _DRAW_DISABLE:          //禁用状态
             break;
     }
}

//-----------------------------------------------------------------------
void CMIDisplayModeRun(BYTE ucMode)
{
     switch(ucMode)
     {
		case _MENU_ADJ_DEC:
		case _MENU_ADJ_INC:
		    break;
		case _MENU_RUN:
			if(GET_DISPLAYMODE() == _DISPMODE_FULL)
			    SET_DISPLAYMODE(_DISPMODE_43);
			else SET_DISPLAYMODE(_DISPMODE_FULL);

            ucTVSyncFailCount = 250;
			CModeResetMode();
			
		    break;
     }
}

//========================== AutoAdjust =================================
void CMIDrawAutoAdjust(BYTE ucDrawID)
{
     switch(ucDrawID)
     {
         case _DRAW_SELECT:           //选中状态
         case _DRAW_MENU_ITEM:        //画菜单项
             
             CCenterTextout(sAutoAdjust[GET_LANGUAGE()],ROW(1),COL(0),_MAINMENU_WIDTH);
             break;
             
         case _DRAW_NORMARL:          //标准状态
             CClearClientOSD();
             break;
             
         case _DRAW_DISABLE:          //禁用状态
             break;
     }
}

//-----------------------------------------------------------------------
void CMIAutoAdjustRun(BYTE ucMode)
{
     switch(ucMode)
     {
		case _MENU_ADJ_DEC:
		case _MENU_ADJ_INC:
		    break;
		case _MENU_RUN:
			
			CCenterTextout(sAutoAdjusting[GET_LANGUAGE()],ROW(1),COL(0),_MAINMENU_WIDTH);
			// Add auto adjust code to here...

			CClearClientOSD();
			CCenterTextout(sAutoAdjust[GET_LANGUAGE()],ROW(1),COL(0),_MAINMENU_WIDTH);
		    break;
     }
}

#if(_VIDEO_TV_SUPPORT)
//========================== TV System =================================
void CMIDrawTVSystem(BYTE ucDrawID)
{
     switch(ucDrawID)
     {
         case _DRAW_SELECT:           //选中状态
         case _DRAW_MENU_ITEM:        //画菜单项            
             CCenterTextout(sTVSystem[GET_LANGUAGE()],ROW(0),COL(0),_MAINMENU_WIDTH);
             CCenterTextout(sTVType[ucTVType],ROW(1),COL(0),_MAINMENU_WIDTH);
             break;
             
         case _DRAW_NORMARL:          //标准状态
             CClearClientOSD();
             break;
             
         case _DRAW_DISABLE:          //禁用状态
             ucOSDAdjTemp = 0;
             break;
     }
}

//-----------------------------------------------------------------------
bit bSearchedTVType(BYTE ucTvType)
{
    switch(ucTvType) 
    {
        case _TV_NTSC_M    :    // 60Hz Sound 4.5M  NTSC M
#if(_TV_NTSC_M_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_NTSC_4_BG :    // 60Hz Sound 5.5M  NTSC 4/BG 
#if(_TV_NTSC_4_BG_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_NTSC_4_DK :    // 60Hz Sound 6.5M  NTSC 4/DK 
#if(_TV_NTSC_4_DK_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_NTSC_4_I  :    // 60Hz Sound 6.0M  NTSC 4/I
#if(_TV_NTSC_4_I_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_PAL_M     :    // 60Hz Sound 4.5M  PAL M  
#if(_TV_PAL_M_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_PAL_BG    :    // 50Hz Sound 5.5M  PAL B/G
#if(_TV_PAL_BG_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_PAL_I     :    // 50Hz Sound 6.0M  PAL I
#if(_TV_PAL_I_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_PAL_DK    :    // 50Hz Sound 6.5M  PAL D/K
#if(_TV_PAL_DK_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_PAL_N     :    // 50Hz Sound 4.5M  PAL N 
#if(_TV_PAL_N_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_SECAM_BG  :    // 50Hz Sound 5.5M  SECAM B/G
#if(_TV_SECAM_BG_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_SECAM_DK  :    // 50Hz Sound 6.5M  SECAM D/K
#if(_TV_SECAM_DK_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_SECAM_L   :    // 50Hz Sound 6.5M  SECAM L  
#if(_TV_SECAM_L_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_SECAM_LL  :    // 50Hz Sound 6.5M  Secam L' 
#if(_TV_SECAM_LL_SUPPORT)
            return 1;
#endif
            break;
    } // end switch 
    
    return 0;
}

//-----------------------------------------------------------------------
void CMITVSystemRun(BYTE ucMode)
{
     switch(ucMode)
     {
		case _MENU_ADJ_DEC:
		case _MENU_ADJ_INC:
            for(pData[15] = 0; pData[15] < (_MAX_TV_TYPE + 1); pData[15]++)
            {
                ucTVType = ValueInRangeChange(0, _MAX_TV_TYPE, ucTVType, _LOOP | ucMode);
                
                if (bSearchedTVType(ucTVType))
                    break;
            }
            
            CClearMsg();           
            CCenterTextout(sTVType[ucTVType], ROW(1),COL(0),_MAINMENU_WIDTH);
            CSaveChannelColorType(stTvInfo.CurChn, ucTVType);
            gmi_CI2CWriteIfPllDM(ucTVType, _TUNER_MUTE_OFF, _NORMAL_MODE);
            break;
		case _MENU_RUN: 
            CClearClientOSD();
		    break;
     }
}

//========================== AutoSearch =================================
void CShowFreq(WORD iFreqN)
{
    BYTE x = 6;
    DWORD lFreqTemp = 0;

    // Get PIF freq
    lFreqTemp = (((float)iFreqN/_TUNER_BP) - ((float)_PIF_FREQ/1000))*100;

    iFreqN = lFreqTemp/100;  // MHz  
    CShowNumber(x, 1, iFreqN);
   // OutputChar(0x2E); // "."
    if (iFreqN > 99)
        x += 4;
    else if(iFreqN > 9)
        x += 3;
    else
        x += 2;
    CTextOutEx(sPixel, x-1, 1); // "."

    iFreqN = lFreqTemp%100;  // KHz
    CShowNumber(x, 1, iFreqN);
    if (iFreqN > 99)
        x += 3;
    else if(iFreqN > 9)
        x += 2;
    else
        x += 1;
    CTextOutEx(sMhz, x, 1); // "MHz"
}

//-----------------------------------------------------------------------
void CShowCurrentChannelFreq(void)
{
    WORD iFreq = 0;

    iFreq = CLoadChannelFreq(stTvInfo.CurChn);
    CShowFreq(iFreq);
}

//-----------------------------------------------------------------------
void CShowAutoSearchSliderInOSD(WORD ucCurrentValue)
{
    OSDClear(1, 1, 4, _MAINMENU_WIDTH-4, 0x00, BYTE_DISPLAY);
    OSDClear(1, 1, 4, _MAINMENU_WIDTH-4, 0x8c, BYTE_ATTRIB);
    CShowFreq(ucCurrentValue);
}   
                        
//-----------------------------------------------------------------------
void CMIDrawAutoSearch(BYTE ucDrawID)
{
     switch(ucDrawID)
     {
         case _DRAW_SELECT:           //选中状态
         case _DRAW_MENU_ITEM:        //画菜单项            
             CCenterTextout(sAutoSearch[GET_LANGUAGE()],ROW(0),COL(0),_MAINMENU_WIDTH);
             CShowCurrentChannelFreq();
             break;
             
         case _DRAW_NORMARL:          //标准状态
             CClearClientOSD();
             break;
             
         case _DRAW_DISABLE:          //禁用状态
             break;
     }
}

//-----------------------------------------------------------------------
void CMIAutoSearchRun(BYTE ucMode)
{
     switch(ucMode)
     {
		case _MENU_ADJ_DEC:
		case _MENU_ADJ_INC:
		case _MENU_RUN:
			CTvAutoSearch();
            CClearClientOSD();
		    break;
     }
}

//-----------------------------------------------------------------------
void CShowAutoSerachTotal(BYTE ucSearchTotal)
{
    CShowNumber(0, 1, ucSearchTotal);
}

//========================== ManualSearch =================================
void CMIDrawManualSearch(BYTE ucDrawID)
{
     switch(ucDrawID)
     {
         case _DRAW_SELECT:           //选中状态
         case _DRAW_MENU_ITEM:        //画菜单项            
             CCenterTextout(sManualSearch[GET_LANGUAGE()],ROW(0),COL(0),_MAINMENU_WIDTH);
             CShowCurrentChannelFreq();
             break;
             
         case _DRAW_NORMARL:          //标准状态
             CClearClientOSD();
             break;
             
         case _DRAW_DISABLE:          //禁用状态
             break;
     }
}

//-----------------------------------------------------------------------
void CMIManualSearchRun(BYTE ucMode)
{
     switch(ucMode)
     {
		case _MENU_ADJ_DEC:
		case _MENU_ADJ_INC:
            CManualSearch((ucMode == _MENU_ADJ_DEC) ? 0 : 1, stTvInfo.CurChn);
            break;

		case _MENU_RUN:
          //  CClearClientOSD();
		    break;
     }
}

//========================== Tunning =================================
void CMIDrawTunning(BYTE ucDrawID)
{
     switch(ucDrawID)
     {
         case _DRAW_SELECT:           //选中状态
         case _DRAW_MENU_ITEM:        //画菜单项            
             CCenterTextout(sTunning[GET_LANGUAGE()],ROW(0),COL(0),_MAINMENU_WIDTH);
             CShowCurrentChannelFreq();
             break;
             
         case _DRAW_NORMARL:          //标准状态
             CClearClientOSD();
             break;
             
         case _DRAW_DISABLE:          //禁用状态
             break;
     }
}

//-----------------------------------------------------------------------
void CMITunningRun(BYTE ucMode)
{
     switch(ucMode)
     {
		case _MENU_ADJ_DEC:
		case _MENU_ADJ_INC:
            SET_KEYREPEATENABLE();
            CTuningCurrentChannel(ucMode, stTvInfo.CurChn);
            CShowCurrentChannelFreq();
            break;

		case _MENU_RUN:
        //    CClearClientOSD();
		    break;
     }
}

//========================== Swap =================================
void CSaveSwap(void)
{
    WORD ucSwapFreq        = CLoadChannelFreq(stTvInfo.CurChn);
    BYTE ucSwapColorSystem = CLoadChannelColorType(stTvInfo.CurChn);
    BYTE ucSwapSoundSystem = CLoadChannelSoundType(stTvInfo.CurChn);
    
    if (stTvInfo.CurChn == ucPrevChannel)
        return;
  //  CAdjustBackgroundColor(0x00, 0x00, 0x00);     
//    CScalerSetBit(_VDISP_CTRL_28, ~_BIT5, _BIT5);
//    bChangeChannel = 1;
    
    CSaveChannelFreq(CLoadChannelFreq(ucPrevChannel), stTvInfo.CurChn);
    CSaveChannelColorType(CLoadChannelColorType(ucPrevChannel), stTvInfo.CurChn);
    CSaveChannelSoundType(CLoadChannelSoundType(ucPrevChannel), stTvInfo.CurChn);
    
    CSaveChannelFreq(ucSwapFreq, ucPrevChannel);
    CSaveChannelColorType(ucSwapColorSystem, ucPrevChannel);
    CSaveChannelSoundType(ucSwapSoundSystem, ucPrevChannel);  
    
    CSetTVChannel(stTvInfo.CurChn); 
    ucOsdEventMsg = _SAVE_EE_TV_DATA_MSG;
}

//-----------------------------------------------------------------------
void CMIDrawSwap(BYTE ucDrawID)
{
     switch(ucDrawID)
     {
         case _DRAW_SELECT:           //选中状态
         case _DRAW_MENU_ITEM:        //画菜单项            
             CCenterTextout(sSwap[GET_LANGUAGE()],ROW(0),COL(0),_MAINMENU_WIDTH);
             CShowNumber(9, 1, stTvInfo.CurChn);
             ucPrevChannel = stTvInfo.CurChn;
             break;
             
         case _DRAW_NORMARL:          //标准状态
             if (ucOSDAdjTemp && ucPrevChannel != stTvInfo.CurChn)
                 CSaveSwap();
             CClearClientOSD();
             ucOSDAdjTemp = 0;
             break;
             
         case _DRAW_DISABLE:          //禁用状态
             break;
     }
}


//-----------------------------------------------------------------------
void CMISwapRun(BYTE ucMode)
{
     switch(ucMode)
     {
		case _MENU_ADJ_DEC:
		case _MENU_ADJ_INC:
            stTvInfo.CurChn = ValueInRangeChange(0, CloadMaxChannelNumber(), stTvInfo.CurChn, _LOOP | ucMode);
            CModeResetTVMode(); //bChangeChannel = 1;
            CSetTVChannel(stTvInfo.CurChn);
            CClearMsg();           
            CShowNumber(9, 1, stTvInfo.CurChn);
            ucOSDAdjTemp = 1;
            break;

     }
}

//========================== Channel =================================
void CMIDrawChannel(BYTE ucDrawID)
{
     switch(ucDrawID)
     {
         case _DRAW_SELECT:           //选中状态
         case _DRAW_MENU_ITEM:        //画菜单项            
             CCenterTextout(sChannel[GET_LANGUAGE()],ROW(0),COL(0),_MAINMENU_WIDTH);
             CShowNumber(9, 1, stTvInfo.CurChn);
             break;
             
         case _DRAW_NORMARL:          //标准状态
             CClearClientOSD();
             break;
             
         case _DRAW_DISABLE:          //禁用状态
             break;
     }
}

//-----------------------------------------------------------------------
void CMIChannelRun(BYTE ucMode)
{
     switch(ucMode)
     {
		case _MENU_ADJ_DEC:
		case _MENU_ADJ_INC:
            stTvInfo.CurChn = ValueInRangeChange(0, CloadMaxChannelNumber(), stTvInfo.CurChn, _LOOP | ucMode);
            CModeResetTVMode(); //bChangeChannel = 1;
            CSetTVChannel(stTvInfo.CurChn);
            CClearMsg();           
            CShowNumber(9, 1, stTvInfo.CurChn);
            ucPrevChannel =  stTvInfo.CurChn;
            //MUTE_ON();
            ucOsdEventMsg = _SAVE_EE_TV_DATA_MSG;
            break;

		case _MENU_RUN:
        //    CClearClientOSD();
		    break;
     }
}

//========================== Skip =================================
void CMIDrawSkip(BYTE ucDrawID)
{
     switch(ucDrawID)
     {
         case _DRAW_SELECT:           //选中状态
         case _DRAW_MENU_ITEM:        //画菜单项            
             CCenterTextout(sSkip[GET_LANGUAGE()],ROW(0),COL(0),_MAINMENU_WIDTH);
             CCenterTextout(sOnOff[CLoadChannelSkip(stTvInfo.CurChn)][GET_LANGUAGE()],ROW(1),COL(0),_MAINMENU_WIDTH);
             break;
             
         case _DRAW_NORMARL:          //标准状态
             CClearClientOSD();
             break;
             
         case _DRAW_DISABLE:          //禁用状态
             break;
     }
}

//-----------------------------------------------------------------------
void CSkipAdj(void)
{
    BYTE ucTemp = CLoadChannelSkip(stTvInfo.CurChn);
    
    ucTemp = 1 - ucTemp;
    
    // Save current channel skip state
    CSaveChannelSkip((bit)ucTemp, stTvInfo.CurChn);
    
    CCenterTextout(sOnOff[ucTemp][GET_LANGUAGE()],ROW(1),COL(0),_MAINMENU_WIDTH);
}

//-----------------------------------------------------------------------
void CMISkipRun(BYTE ucMode)
{
     switch(ucMode)
     {
		case _MENU_ADJ_DEC:
		case _MENU_ADJ_INC:
            CClearMsg();           
            CSkipAdj();
            break;

		case _MENU_RUN:
            CClearClientOSD();
		    break;
     }
}

#endif // #if(_VIDEO_TV_SUPPORT)

//========================== Language =================================
void CMIDrawLanguage(BYTE ucDrawID)
{
     switch(ucDrawID)
     {
         case _DRAW_SELECT:           //选中状态
         case _DRAW_MENU_ITEM:        //画菜单项            
             CCenterTextout(sLanguage[GET_LANGUAGE()],ROW(0),COL(0),_MAINMENU_WIDTH);
             CCenterTextout(sLanguageName[GET_LANGUAGE()],ROW(1),COL(0),_MAINMENU_WIDTH);
             break;
             
         case _DRAW_NORMARL:          //标准状态
             CClearClientOSD();
             break;
             
         case _DRAW_DISABLE:          //禁用状态
             break;
     }
}

//-----------------------------------------------------------------------
void CAdjLanguage(BYTE ucAdj)
{
    BYTE ucLng = GET_LANGUAGE();
    
    if (ucAdj) 
        ucLng = GetNextLanguage(ucLng);
    else   
        ucLng = GetPrevLanguage(ucLng);
    
    SET_LANGUAGE(ucLng);
    
    // Load Font
  //  LoadLanguageFont();
}

//-----------------------------------------------------------------------
void CMILanguageRun(BYTE ucMode)
{
     switch(ucMode)
     {
		case _MENU_ADJ_DEC:
		case _MENU_ADJ_INC:
            CClearClientOSD();
            CAdjLanguage(ucMode);
            CCenterTextout(sLanguage[GET_LANGUAGE()],ROW(0),COL(0),_MAINMENU_WIDTH);
            CCenterTextout(sLanguageName[GET_LANGUAGE()],ROW(1),COL(0),_MAINMENU_WIDTH);
            break;

		case _MENU_RUN:
         //   CClearClientOSD();
		    break;
     }
}

//========================== Blue =================================
void CMIDrawBlue(BYTE ucDrawID)
{
     switch(ucDrawID)
     {
         case _DRAW_SELECT:           //选中状态
         case _DRAW_MENU_ITEM:        //画菜单项
             CCenterTextout(sBlue[GET_LANGUAGE()],ROW(0),COL(0),_MAINMENU_WIDTH);
             CCenterTextout(sOnOff[_GET_BLUE_BACKGROUND()][GET_LANGUAGE()],ROW(1),COL(0),_MAINMENU_WIDTH);
             break;
             
         case _DRAW_NORMARL:          //标准状态
             CClearClientOSD();
             break;
             
         case _DRAW_DISABLE:          //禁用状态
             break;
     }
}

//-----------------------------------------------------------------------
void CMIBlueRun(BYTE ucMode)
{
     switch(ucMode)
     {
		case _MENU_ADJ_DEC:
		case _MENU_ADJ_INC:
            ucMode = _GET_BLUE_BACKGROUND();
            ucMode = 1 - ucMode;
            CClearMsg();           
            CCenterTextout(sOnOff[ucMode][GET_LANGUAGE()],ROW(1),COL(0),_MAINMENU_WIDTH);
            _SET_BLUE_BACKGROUND(ucMode);
            ucOsdEventMsg = _SAVE_EE_SYSTEMDATA_MSG;
		    break;
		case _MENU_RUN:
		    break;
     }
}

//========================== Volume =================================
void CMIDrawVolume(BYTE ucDrawID)
{
     switch(ucDrawID)
     {
         case _DRAW_SELECT:           //选中状态
         case _DRAW_MENU_ITEM:        //画菜单项
             CCenterTextout(sVolume[GET_LANGUAGE()],ROW(0),COL(0),_MAINMENU_WIDTH);
             DRAW_SLIDER(GET_VOLUME());
             break;
             
         case _DRAW_NORMARL:          //标准状态
             CClearClientOSD();
             break;
             
         case _DRAW_DISABLE:          //禁用状态
             break;
     }
}

//-----------------------------------------------------------------------
void CMIVolumeRun(BYTE ucMode)
{
     switch(ucMode)
     {
		case _MENU_ADJ_DEC:
		case _MENU_ADJ_INC:
            SET_KEYREPEATENABLE();
            stAudioData.Volume = ValueInRangeChange(0, 100, stAudioData.Volume, _NON_LOOP | ucMode);
            DRAW_SLIDER(GET_VOLUME());
            CSetVolume();
            ucOsdEventMsg = _SAVE_EE_AUDIO_DATA_MSG;
		    break;

		case _MENU_RUN:
		    break;
     }
}

//========================== Exit =================================
void CMIDrawExit(BYTE ucDrawID)
{
     switch(ucDrawID)
     {
         case _DRAW_SELECT:           //选中状态
         case _DRAW_MENU_ITEM:        //画菜单项
             CCenterTextout(sExit[GET_LANGUAGE()],ROW(1),COL(0),_MAINMENU_WIDTH);
             break;
             
         case _DRAW_NORMARL:          //标准状态
             CClearClientOSD();
             break;
             
         case _DRAW_DISABLE:          //禁用状态
             break;
     }
}
//-----------------------------------------------------------------------
void CMIExitRun(BYTE ucMode)
{
     switch(ucMode)
     {
		case _MENU_ADJ_DEC:
		case _MENU_ADJ_INC:
		case _MENU_RUN:
			COsdDispOsdTimerEvent();			
		    break;
     }
}

//-----------------------------------------------------------------------
void CPDrawSCMenu(BYTE ucDrawID)
{
    ucDrawID = ucDrawID;
    switch(g_ucMenuItemIndex)
    {
    case _SC_MUTE:
       // CSetMuteState();
        break;

    case _SC_VOLUME:
        break;

    }
}

//-----------------------------------------------------------------------
void CDrawSCMute(BYTE ucDrawID)
{
     switch(ucDrawID)
     {
         case _DRAW_BEFORE_ENTER_SUBMENU:
             g_ucPageIndex     = _P_MENU_NONE;
             g_ucMenuItemIndex = _MENU_NONE;
             COsdFxDisableOsd();
             break;
     }
}

//-----------------------------------------------------------------------
void CSCMuteRun(BYTE ucMode)
{
    ucMode = ucMode;
    CSetMuteState();
}

//-----------------------------------------------------------------------
void CDrawMuteState(void)
{
    COsdFxDisableOsd();
  //  g_ucPageIndex     = _P_MENU_NONE;
  //  g_ucMenuItemIndex = _MENU_NONE;
    SetOSDDouble(0x03);
    SetOsdMap(tUserMenuOsdMap);
                
    // Init OSD Ram
    OSDClear(0, 2, 0, 30, 0x8C, BYTE_ATTRIB);
    OSDClear(0, 2, 0, 30, 0x00, BYTE_DISPLAY);
    OSDClear(0, 2, 0, 6, 0x40, BYTE_COLOR);
    
    COsdFxCodeWrite(ucCloseAllWindow);
    OSDPosition(_MAINMENU_WIDTH * 12,_MAINMENU_HEIGHT * 18,50,1,0x03);
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
    if (GET_AUDIO_MUTE()) // Mute on  
    {
       	CTimerCancelTimerEvent(COsdDispOsdTimerEvent);
     //   g_ucPageIndex = _P_SHOW_MUTE;
    }
    else
       CTimerReactiveTimerEvent(SEC(5), COsdDispOsdTimerEvent);
}

//-----------------------------------------------------------------------
void CSetMuteState(void)
{
    if (GET_AUDIO_MUTE()) // Mute on 
        CLR_AUDIO_MUTE();
    else
       SET_AUDIO_MUTE();

    CDrawMuteState();

    CSetVolume();
    ucOsdEventMsg = _SAVE_EE_AUDIO_DATA_MSG;
}

#if(_VIDEO_TV_SUPPORT)
//-----------------------------------------------------------------------
void CShowTVNumber(BYTE ucNumber, BYTE ucOption)
{              
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
}
#endif // #if(_VIDEO_TV_SUPPORT)

#endif		//#if(_OSD_TYPE == _OSD001)