#define __OSD007_LCD_OSD__

#include "Core\Header\include.h"

#if(_OSD_TYPE == _OSD007)
          
//-----------------------------------------------------------
void COsdHandler(void)
{    
    COsdEventMsgProc();

    COsdSystemFlowProc();

    if (_PWOFF_STATE == ucCurrState)
        return;
    
    if(ucKeyMessage == VK_SOURCE && ucCurrState != _SEARCH_STATE)
    {
        CSourceChange(); 
        return;
    }

#if(_CHANGE_SOURCE_METHOD == _CHANGE_SOURCE_METHOD_0)
    if (ucChangeSourceCount)
        CChangeSourceHandler();
#endif
    
#if(_VIDEO_TV_SUPPORT)
    if (_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV || ucCurrState == _ACTIVE_STATE)
#else
    if (ucCurrState == _ACTIVE_STATE)
#endif
    {           
        COsdProc();

        if (bRCallOSD)
        {
            bRCallOSD = 0;
            COsdProc();
        }

    }  

#if(_VIDEO_TV_SUPPORT)
    if (ucKeyMessage != _NONE_KEY_MESSAGE)// && ucOsdState != MENU_SHOW_MUTE_STATE && !bChangeChannel)
#else
    if (ucKeyMessage != _NONE_KEY_MESSAGE && ucOsdState != MENU_SHOW_MUTE_STATE)
#endif
    {
        switch(ucKeyMessage)
        {
            case VK_IR_DISPLAY:
            case VK_IR_MUTE:
                return;
        }

        if (GET_OSDTIMEOUT() < 5)
        	CTimerCancelTimerEvent(COsdDispOsdTimerEvent);
        else
            CTimerReactiveTimerEvent(SEC(GET_OSDTIMEOUT()), COsdDispOsdTimerEvent);
    } 
    
    if (ucOsdState == 245)
       NotUseFunc();
}
//-----------------------------------------------------------

void CSourceChange(void)
{
    TUNER_PWR_OFF();
    CMuteOn();

#if(_CHANGE_SOURCE_METHOD == _CHANGE_SOURCE_METHOD_0)

    if (!ucChangeSourceCount)
    {
        if(_SLEEP_STATE == ucCurrState)
        {
        	CModeSetFreeRun();
            CPowerLVDSOn();
        }

        
        ucTVSyncFailCount = 250;
        CModeResetMode();
    }
    
    ucCurrState = _SOURCE_CHANGE_STATE;
    bChangeSource();
    
    ShowNote();
    ucChangeSourceCount = 1;
    
#elif(_CHANGE_SOURCE_METHOD == _CHANGE_SOURCE_METHOD_1)

    if(_SLEEP_STATE == ucCurrState)
    {
    	CModeSetFreeRun();
        CPowerLVDSOn();
    }
        
    ucOsdEventMsg = _CHANGE_SOURCE_MSG;
    bChangeSource();

    ucTVSyncFailCount = 250;
    CModeResetMode();

	switch(_GET_INPUT_SOURCE())
	{
		case _SOURCE_VGA:
		case _SOURCE_YPBPR:
			CScalerSetBit(_IPH_ACT_WID_H_16, ~_BIT5, 0x00);
			CVideoOutputDisable();
            CScalerLoadHardwareVLCFont(tFntIcon4Bit, (_4BIT_ICON_COLOR_ADDR*4));  // icon
			break;
	#if((_TMDS_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))			
		case _SOURCE_DVI:
        case _SOURCE_HDMI:
			CVideoOutputDisable();
			break;
	#endif
		    break;
#if(_VIDEO_TV_SUPPORT)
		case _SOURCE_VIDEO_TV:
            CInitTV();
            CScalerLoadHardwareVLCFont(tFntIcon4BitTvFunc, (_4BIT_ICON_TV_FUNC_ADDR*4));  // TV function icon
            CScalerLoadHardwareVLCFont(tFntIcon4BitOSD, ((_4BIT_ICON_TV_FUNC_ADDR+6)*4));  // OSD function icon
#endif
		case _SOURCE_VIDEO_AV:
		case _SOURCE_VIDEO_SV:
			CVideoOutputEnable();
			break;
	}

    ucOsdEventMsg = _CHANGE_SOURCE_MSG;

#endif  // #if(_CHANGE_SOURCE_METHOD == _CHANGE_SOURCE_METHOD_0)

    CPowerLightPowerOn();
}
//-----------------------------------------------------------

#if(_CHANGE_SOURCE_METHOD == _CHANGE_SOURCE_METHOD_0)

void CChangeSourceHandler(void)
{
    ucChangeSourceCount++;
                          
    if (_CHANGE_SOURCE_TIME < ucChangeSourceCount)
    {          
    	switch(_GET_INPUT_SOURCE())
    	{
    		case _SOURCE_VGA:
    		case _SOURCE_YPBPR:
    			CScalerSetBit(_IPH_ACT_WID_H_16, ~_BIT5, 0x00);
    			CVideoOutputDisable();
                CScalerLoadHardwareVLCFont(tFntIcon4Bit, (_4BIT_ICON_COLOR_ADDR*4));  // icon
    			break;
    	#if((_TMDS_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))			
    		case _SOURCE_DVI:
            case _SOURCE_HDMI:
    			CVideoOutputDisable();
    			break;
    	#endif
    		    break;
#if(_VIDEO_TV_SUPPORT)
    		case _SOURCE_VIDEO_TV:
                CInitTV();
                CScalerLoadHardwareVLCFont(tFntIcon4BitTvFunc, (_4BIT_ICON_TV_FUNC_ADDR*4));  // TV function icon
                CScalerLoadHardwareVLCFont(tFntIcon4BitOSD, ((_4BIT_ICON_TV_FUNC_ADDR+6)*4));  // OSD function icon
#endif
    		case _SOURCE_VIDEO_AV:
    		case _SOURCE_VIDEO_SV:
    			CVideoOutputEnable();
    			break;
    	}
 
        ucOsdEventMsg       = _CHANGE_SOURCE_MSG;
        ucChangeSourceCount = 0;
    }
}      
#endif
//-----------------------------------------------------------

void COsdSystemFlowProc(void)
{
    switch(ucCurrState)
    {
    case _PWOFF_STATE:
        break;
        
    case _INITIAL_STATE:
       // COsdDispFirstTimeLoadFont();
        break;
        
    case _SEARCH_STATE:
        GREENLED_ON();
        REDLED_ON();
        break;
        
    case _ACTIVE_STATE:
        if(GET_OSD_READYFORDISPLAY() == _TRUE)
        {         
            COsdDispOsdTimerEvent();
            CLR_OSD_READYFORDISPLAY();
            GREENLED_ON();
            REDLED_OFF();
            CAdjustBackgroundColor(0x00, 0x00, 0x00);
#if(_VIDEO_TV_SUPPORT)
 #if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
            if (_GET_INPUT_SOURCE() != _SOURCE_VIDEO_TV)
 #endif
#endif
                CSetVolume();

            if (GET_FIRST_SHOW_NOTE())
               ucOsdEventMsg = _DO_SHOW_NOTE;
#if(_VIDEO_TV_SUPPORT)
            else if(_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV && bChangeChannel)
               CShowTVNumber(stTvInfo.CurChn, _SHOW_CH_TV_NUMBER | _SHOW_CH_TV_TYPE); 
#endif
        }

#if(_VIDEO_TV_SUPPORT)
 #if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
        CAudioCtrl(); 
 #endif
#endif
        break;
        
    case _NOSUPPORT_STATE:
        if(GET_OSD_READYFORDISPLAY() == _TRUE)
        {
            GREENLED_ON();
            REDLED_ON();
            CLR_OSD_READYFORDISPLAY();
            CAdjustBackgroundColor(0x00, 0x00, (_GET_BLUE_BACKGROUND()) ? 0xFF : 0x00);
            if (GET_FIRST_SHOW_NOTE())
               ucOsdEventMsg = _DO_SHOW_NOTE;
            
            CTimerReactiveTimerEvent(SEC(3), CModeNoSupportEvent);
        }
        
        break;
        
    case _NOSIGNAL_STATE:
        if(GET_OSD_READYFORDISPLAY() == _TRUE)
        {    
            CLR_OSD_READYFORDISPLAY(); 
            GREENLED_ON();
            REDLED_ON();

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
				break;
			}		
	        
#endif
			// here comes for VGA, DVI input only
#if(_TMDS_SUPPORT == _ON)
			if (_GET_INPUT_SOURCE() == _SOURCE_DVI) 
			{
                if (bDVICONNECT)
    				CTimerReactiveTimerEvent(SEC(1), CModeNoCableEvent);
                else
			    	CTimerReactiveTimerEvent(SEC(1), CModeNoSignalEvent);
			}		
#endif


			if (_GET_INPUT_SOURCE() == _SOURCE_VGA) 
			{
    			if (bVGACONNECT)
    				CTimerReactiveTimerEvent(SEC(1), CModeNoCableEvent);
    			else       
    				CTimerReactiveTimerEvent(SEC(1), CModeNoSignalEvent);
	        }

            if (bSourceVideo())
    			CTimerReactiveTimerEvent(SEC(1), CModeNoSignalEvent);

			CTimerReactiveTimerEvent(SEC(6), CModePowerSavingEvent);

        }
        
        break;
        
    case _SLEEP_STATE:
        break;
        
    default:
        break;
    }
}

//-----------------------------------------------------------

void COsdProc(void)
{               
#if(_VIDEO_TV_SUPPORT)           
    if (MENU_SHOW_MESSAGE_SATAE == ucOsdState)
    {
        if (_NONE_KEY_MESSAGE != ucKeyMessage)
            ucOsdState = _MENU_NONE;
        else
            return;
    }
#endif

    switch(ucOsdState)
    {
        case MENU_SHOW_MUTE_STATE:
        case MENU_SHOW_MSG_STATE:
        case _MENU_NONE:                    MPubNoneProc();           break;

        //==================== Main item ===========================
        case MENU_MAIN_COLOR:        // Public color item
#if(_VGA_SUPPORT || _YPBPR_SUPPORT)                   
        case MENU_MAIN_PICTURE:      // VGA picture item
#endif
#if(_VIDEO_TV_SUPPORT)           
        case MENU_MAIN_TV_FUNC:      // TV function item
#endif
        case MENU_MAIN_OSD_FUNC:     // Public OSD function item
        case MENU_MAIN_SOUND:        // Public Sound item
        case MENU_MAIN_OTHER:        // Public other item
        case MENU_MAIN_EXIT:         // Public exit item
            MMainItemProc();       
            break;
    


        //======================= Sub item =========================

        //---------------- Public Color Sub item -------------------
        case MENU_ITEM_BRIGHT:       // Public <Brightness>
        case MENU_ITEM_CONTRAST:     // Public <Contrast>
#if(_TMDS_SUPPORT || _VGA_SUPPORT || _HDMI_SUPPORT)
        case MENU_ITEM_COLOR_TEMP:   // VGA/DVI/HDMI <Color temp>
#endif

#if(_VIDEO_SUPPORT)
        case MENU_AV_SATURATION:     // Video <Saturation>
        case MENU_AV_HUE:            // Video <Hue>
#endif
        case MENU_SUB_COLOR_CLOSE:   // Public <Close> 
            MColorSubItemProc();
            break;

        //------------------ TV function sub item -------------------
#if(_VIDEO_TV_SUPPORT)
        case MENU_AUTO_SEARCH:       // TV <Auto search>
        case MENU_MANUAL_SEARCH:     // TV <Manual search> 
        case MENU_TUNING:            // TV <Tunning>
        case MENU_CHANNEL:           // TV <Channel>
        case MENU_TV_SYSTEM:         // TV <TV system>
        case MENU_SWAP:              // TV <Swap>
        case MENU_SKIP:              // TV <Skip>
        case MENU_SUB_TV_FUNC_CLOSE: // TV <Close>
            MTVFuncSubItemProc();
            break;
#endif
    
        //------------- VGA/DVI/HDMI Color sub temp sub item -------------
#if(_TMDS_SUPPORT || _VGA_SUPPORT || _HDMI_SUPPORT)           
#if(_COLOR_TEMP)
        case MENU_SUB_CT_9300:       // VGA/DVI/HDMI <9300>
        case MENU_SUB_CT_6500:       // VGA/DVI/HDMI <6500>
        case MENU_SUB_CT_5800:       // VGA/DVI/HDMI <5800>
        case MENU_SUB_CT_SRGB:       // VGA/DVI/HDMI <SRGB>
        case MENU_SUB_CT_USER:       // VGA/DVI/HDMI <User>
        case MENU_SUB_CT_CLOSE:      // VGA/DVI/HDMI <close>
            MColorTempSubItemProc();
            break;

        case MENU_SUB_CT_R:          // VGA/DVI/HDMI <R>
        case MENU_SUB_CT_G:          // VGA/DVI/HDMI <G>
        case MENU_SUB_CT_B:          // VGA/DVI/HDMI <B>
            MColorTempUserItemProc();
            break;
#endif
#endif
    
       //------------------- VGA pciture sub item -------------------
#if(_VGA_SUPPORT  || _YPBPR_SUPPORT)
        case MENU_ITEM_AUTO:         // VGA <Auto>
#if(_VGA_SUPPORT)
        case MENU_ITEM_AUTO_COLOR:
        case MENU_ITEM_HPOS:         // VGA <H position>
        case MENU_ITEM_VPOS:         // VGA <V position>
        case MENU_ITEM_PHASE:        // VGA <Phase>
        case MENU_ITEM_CLOCK:        // VGA <Clock>
#endif
        case MENU_SUB_PICTURE_CLOSE: // VGA <Close>
            MPictureSubItemProc();
            break;
#endif
    
        //------------- Public OSD function sub item ----------------
        case MENU_SUB_LANGUAGE:        // Public <Language>
        case MENU_SUB_H_POSITION:      // Public <OSD H position>
        case MENU_SUB_V_POSITION:      // Public <OSD V position>
        case MENU_SUB_OSD_TIMEOUT:     // Public <OSD timeout>
        case MENU_SUB_OSD_TRANSLUCENT: // Public <OSD Translucent>
        case MENU_SUB_OSD_SIZE:        // public <OSD Size>
        case MENU_SUB_OSD_CLOSE:       // Public <Close>
            MOSDSubItemProc();
            break;

        //---------------- Public Sound sub item ---------------------
        case MENU_SUB_VOLUME:        // Public <Volume>
        case MENU_SUB_MUTE:          // Public <Mute>
#if(_SOUND_PROCESSOR == _ENABLE)
        case MENU_SUB_BALANCE:       // Public <Balance>
        case MENU_SUB_BASS:          // Public <Bass>
        case MENU_SUB_TREBLE:        // Public <Treble>
//        case MENU_SUB_SRS:           // Public <SRS>
  //      case MENU_SUB_BBE:           // Public <BBE>
#endif  
        case MENU_SUB_SOUND_CLOSE:   // Public <Close>
            MSoundSubItemProc();
            break;

        //------------------ Public Other sub item --------------------
        case MENU_SUB_RESET:         // Public <Reset>
        case MENU_SUB_BLUE:          // Public <Blue>
#if(_SLEEP_FUNC)
        case MENU_SUB_AUTO_POWER:    // Public <Auto power down>
#endif
        case MENU_SUB_COLOR_MODE:    // Public <Color Mode>
        case MENU_SUB_SHARP:         // Public <Sharp>
        case MENU_SUB_OTHER_CLOSE:   // Public <Close>
            MOtherSubItemProc();
            break;
    

        //======================= Sub item adjust proc =====================

        //------------------- Public Color adj proc ----------------------
        case MENU_SUB_BRIGH_ADJ:     // Public <Brightness> adj     
            MBrightAdjProc();            
            break;
        case MENU_SUB_CONTRAST_ADJ:  // Public <Contrast> adj     
            MContrastAdjProc();          
            break;
#if(_VIDEO_SUPPORT)
        case MENU_AV_SATURATION_ADJ: // Video <Saturation> adj   
            MAVSaturationAdjProc();      
            break;
        case MENU_AV_HUE_ADJ:        // Video <Hue> adj      
            MAVHueAdjProc();             
            break;
#endif


        //----------------------- VGA Picture adj proc -------------------
#if(_VGA_SUPPORT)
        case MENU_SUB_PHASE_ADJ:     // VGA <Phase> adj     
            MPhaseAdjProc();        
            break;
        case MENU_SUB_CLOCK_ADJ:     // VGA <Clock> adj    
            MClockAdjProc();        
            break;
        case MENU_SUB_HPOS_ADJ:      // VGA <H position> adj    
            MHPosAdjProc();         
            break;
        case MENU_SUB_VPOS_ADJ:      // VGA <V position> adj    
            MVPosAdjProc();         
            break;
#endif

        //---------------------- TV function adj proc --------------------
#if(_VIDEO_TV_SUPPORT)
        case MENU_AUTO_SEARCH_ADJ:   // TV <Auto search> adj     
            MAutoSearchAdjProc();        
            break;
        case MENU_MANUAL_SEARCH_ADJ: // TV <Manual search> adj    
            MManualSearchAdjProc();      
            break;
        case MENU_TUNING_ADJ:        // TV <Tunning> adj    
            MTuningAdjProc();            
            break;
        case MENU_TV_SYSTEM_ADJ:     // TV <TV system> adj    
            MTVSystemAdjProc();          
            break;
 //       case MENU_SOUND_SYSTEM_ADJ:  // TV <Sound system> adj <Not use>     
   //         MSoundSystemAdjProc();       
     //       break;
        case MENU_CHANNEL_ADJ:       // TV <Channel> adj    
            MChannelAdjProc();           
            break;
        case MENU_SWAP_ADJ:          // TV <Swap> adj      
            MSwapAdjProc();               
            break;
        case MENU_SKIP_ADJ:          // TV <Skip> adj    
            MSkipAdjProc();              
            break;
#endif

        //----------------------- Public OSD adj proc ---------------------
        case MENU_SUB_OSDLANGUAGE_ADJ:   // Public <Language> adj 
            MLanguageAdjProc();     
            break;
#if(_OSD_POSITION_ADJ_CTRL)
        case MENU_SUB_OSDH_POSITION_ADJ: // Public <OSD H position> adj
            MOSDHPositionAdjProc(); 
            break;
        case MENU_SUB_OSDV_POSITION_ADJ: // Public <OSD V position> adj
            MOSDVPositionAdjProc(); 
            break;
#endif
#if(_OSD_TIMEOUT_ADJ_CTRL)
        case MENU_SUB_OSD_TIMEOUT_ADJ:   // Public <OSD timeout> adj
            MOSDTimeoutAdjProc();   
            break;
#endif
#if(_ALPHA_BLENDING_ADJ)
        case MENU_SUB_OSD_TRANS_ADJ:    // Public <OSD Translucent> adj
            MOSDTranslucentAdjProc();   
            break;
#endif
#if(_OSD_DISPLAY_SIZE_ADJ)
        case MENU_SUB_OSD_SIZE_ADJ:    // Public <OSD Size> adj
            MOSDSizeAdjProc();   
            break;
#endif


        //---------------------- Public Ohter adj proc --------------------
#if(_BLUE_BACKGROUND_FUNC == _ENABLE)
        case MENU_BLUE_ADJ:              // Public <Blue> adj 
            MBlueAdjProc();              
            break;
#endif

#if(_VIDEO_TV_SUPPORT) 
 #if(_SLEEP_FUNC)
        case MENU_AUTO_POWER_DOWN_ADJ:   // Public <Auto power down> adj
            MAutoPowerDownAdjProc();     
            break;
 #endif
#endif

#if(_IMAGE_COLOR_MODE)
        case MENU_COLOR_MODE_ADJ:        // Public <Color mode> adj
            MColorModeAdjProc();
            break;
#endif

#if(_SHARPNESS_ADJ)
        case MENU_SHARP_ADJ:             // Public <Sharp> adj
            MSharpAdjProc();
            break;
#endif

        //--------------------- Public Sound adj porc ---------------------
        case MENU_SUB_VOL_ADJ:           // Public <Volume> adj
        case MENU_VOLUME_SP:
            MVolumeAdjProc();            
            break;
        case MENU_SUB_MUTE_ADJ:          // Public <Mute> adj
            MMuteAdjProc();              
            break;
#if(_SOUND_PROCESSOR == _ENABLE)
        case MENU_SUB_BALANCE_ADJ:       // Public <Balance> adj
            MBalanceAdjProc();           
            break;
        case MENU_SUB_BASS_ADJ:          // Public <Bass> adj
            MBassAdjProc();              
            break;
        case MENU_SUB_TREBLE_ADJ:        // Public <Treble> adj
            MTrebleAdjProc();            
            break;
        case MENU_SUB_SRS_ADJ:           // Public <SRS> adj
            MSRSAdjProc();               
            break;
        case MENU_SUB_BBE_ADJ:           // Public <BBE> adj
            MBBEAdjProc();               
            break;
#endif

        //------------------ TV Input ch number adj proc -----------------
#if(_VIDEO_TV_SUPPORT)
        case ITEM_SHORTCUT_INPUTCH_NUM:  SInputCHNumber();            break;
#endif


        //======================== Peaking coring function =====================
#if(_VGA_COLOR_SUPPORT)
        //---------------------- Vivid color item ------------------------
        case MENU_SAC_DCC_TEXT:               // DCC <Text>
        case MENU_SAC_DCC_MOVIE:              // DCC <Movie>
        case MENU_SAC_DCC_GRAPHIC:            // DCC <Graphic>
        case MENU_SAC_DCC_GAME:               // DCC <Game>
        case MENU_SAC_DCC_NORMAL:             // DCC <Normal>
        case MENU_SAC_DCC_USER:               // DCC <User>
        case MENU_SAC_DCC_CLOSE:              // DCC <Exit>
            MVividColorItemProc();
            break;
    
        //---------------------- Vivid color sub item --------------------
        case MENU_USER_ITEM_DCC:              // Vivid Color <DCC>
        case MENU_USER_ITEM_ICM:              // Vivid Color <ICM>
        case MENU_USER_ITEM_COLOR:            // Vivid Color <Color>
        case MENU_USER_ITEM_CLOSE:            // Vivid Color <Exit>
            MVividColorSubProc();
            break;
       
        //--------------------- Vivid color DCC adj ---------------------
        case MENU_DCC_ITEM_TEXT:              // DCC <Text>
        case MENU_DCC_ITEM_MOVIE:             // DCC <Movie>
        case MENU_DCC_ITEM_GRAPHIC:           // DCC <Graphic>
        case MENU_DCC_ITEM_GAME:              // DCC <Game>
        case MENU_DCC_ITEM_NORMAL:            // DCC <Normal>
            MDCCAdjProc();
            break;
    
        //--------------------------- ICM item ---------------------------
        case MENU_ICM_ITEM_RED:               // ICM <Red>
        case MENU_ICM_ITEM_GREEN:             // ICM <Green>
        case MENU_ICM_ITEM_BLUE:              // ICM <Blue>
        case MENU_ICM_ITEM_YELLOW:            // ICM <Yellow>
        case MENU_ICM_ITEM_CYAN:              // ICM <Cyan>
        case MENU_ICM_ITEM_MAGENTA:           // ICM <Magenta>
        case MENU_ICM_ITEM_ON_OFF:            // ICM <ICM>
        case MENU_ICM_ITEM_CLOSE:             // ICM <Exit>
            MICMItemProc();
            break;
    
        //------------------------ ICM R/G/B item ------------------------
        case MENU_ICM_SUB_R_HUE:              // ICM R <Hue>
        case MENU_ICM_SUB_R_SAT:              // ICM R <Saturation>
        case MENU_ICM_SUB_R_CLOSE:            // ICM R <Close>
        case MENU_ICM_SUB_G_HUE:              // ICM G <Hue>
        case MENU_ICM_SUB_G_SAT:              // ICM G <Saturation>
        case MENU_ICM_SUB_G_CLOSE:            // ICM G <Close>
        case MENU_ICM_SUB_B_HUE:              // ICM B <Hue>
        case MENU_ICM_SUB_B_SAT:              // ICM B <Saturation>
        case MENU_ICM_SUB_B_CLOSE:            // ICM B <Close>
        case MENU_ICM_SUB_Y_HUE:              // ICM Y <Hue>
        case MENU_ICM_SUB_Y_SAT:              // ICM Y <Saturation>
        case MENU_ICM_SUB_Y_CLOSE:            // ICM Y <Close>
        case MENU_ICM_SUB_C_HUE:              // ICM C <Hue>
        case MENU_ICM_SUB_C_SAT:              // ICM C <Saturation>
        case MENU_ICM_SUB_C_CLOSE:            // ICM C <Close>
        case MENU_ICM_SUB_M_HUE:              // ICM M <Hue>
        case MENU_ICM_SUB_M_SAT:              // ICM M <Saturation>
        case MENU_ICM_SUB_M_CLOSE:            // ICM M <Close>
            MICMSubRGBItemAdjProc();
            break;
    
        //-------------------- ICM R/G/B color adj page --------------------
        case MENU_ICM_R_HUE_ADJ:              // ICM R adj <Hue>
        case MENU_ICM_R_SAT_ADJ:              // ICM R adj <Saturation>
        case MENU_ICM_G_HUE_ADJ:              // ICM G adj <Hue>
        case MENU_ICM_G_SAT_ADJ:              // ICM G adj <Saturation>
        case MENU_ICM_B_HUE_ADJ:              // ICM B adj <Hue>
        case MENU_ICM_B_SAT_ADJ:              // ICM B adj <Saturation>
        case MENU_ICM_Y_HUE_ADJ:              // ICM Y adj <Hue>
        case MENU_ICM_Y_SAT_ADJ:              // ICM Y adj <Saturation>
        case MENU_ICM_C_HUE_ADJ:              // ICM C adj <Hue>
        case MENU_ICM_C_SAT_ADJ:              // ICM C adj <Saturation>
        case MENU_ICM_M_HUE_ADJ:              // ICM M adj <Hue>
        case MENU_ICM_M_SAT_ADJ:              // ICM M adj <Saturation>
            MICMSubRGBColorAdjProc();
            break;
       
        //-------------------------- Vivid color ---------------------------
        case MENU_COLOR_ITEM_BRIGHTNESS:      // Color <Brightness>
        case MENU_COLOR_ITEM_CONTRAST:        // Color <Contrast>
        case MENU_COLOR_ITEM_PEAKING:         // Color <Peaking>
        case MENU_COLOR_ITEM_CLOSE:           // Color <Exit>
            MDCCColorAdjProc();
            break;
    
        //------------------ Vivid bright/Contrast adj proc ----------------
        case MENU_COLOR_ITEM_BRIGHT_ADJ:      // Color adj <Brightness>
        case MENU_COLOR_ITEM_CON_ADJ:         // Color adj <Contrast>
        case MENU_COLOR_ITEM_PEAK_ADJ:        // Color adj <Peaking>
            MDCCColorBCAdjProc();
            break;
#endif
    
        default:                              break;
            
    }    
}

//-----------------------------------------------------------
void MPubNoneProc(void)
{
    switch(_GET_INPUT_SOURCE())
    {
#if(_TMDS_SUPPORT || _VGA_SUPPORT || _YPBPR_SUPPORT || _HDMI_SUPPORT)
    case _SOURCE_YPBPR:
    case _SOURCE_VGA:
    case _SOURCE_DVI:
    case _SOURCE_HDMI:
        MNoneProc();
        break;
#endif    
        
#if(_VIDEO_SUPPORT)
#if(_VIDEO_YUV_SUPPORT)
    case _SOURCE_VIDEO_YUV:
#endif
    case _SOURCE_VIDEO_AV:
    case _SOURCE_VIDEO_SV:
    case _SOURCE_VIDEO_SCART:
        MAVNoneProc();
        break;
#endif    
       
#if(_VIDEO_TV_SUPPORT)
    case _SOURCE_VIDEO_TV:
        MTVNoneProc();
        break;
#endif
    }
         
    if (_MENU_NONE == ucOsdState && _NONE_MSG == ucOsdEventMsg)// && GET_AUDIO_MUTE() == STATE_MUTEON && ucOsdState != MENU_SHOW_MUTE_STATE)
    {
  #if(_VIDEO_TV_SUPPORT)
        if (GET_AUDIO_MUTE() && ucOsdState != MENU_SHOW_MUTE_STATE && !bChangeChannel)
  #else
        if (GET_AUDIO_MUTE() && ucOsdState != MENU_SHOW_MUTE_STATE)
  #endif
           DrawMuteState();
#if(_VIDEO_TV_SUPPORT)
 #if(_SLEEP_FUNC)
        else if(0xff != ucAutoPowerDownTime && 0 != _GET_POWER_DOWN_TIME())
           CShowTimer(); // Show auto power down timer
 #endif
#endif

    } 
}


//-----------------------------------------------------------
void COthterKeyAction(void)
{
    if (_NONE_KEY_MESSAGE != ucKeyMessage)
    {
        switch(ucKeyMessage)
        {
  #if(_USE_UD_LR_KEY_MSG)
            case VK_F_LEFT:
            case VK_F_RIGHT:
            case VK_F_UP:
            case VK_F_DOWN:
  #endif

            case VK_IR_DISPLAY:
            case VK_IR_MUTE:
            case VK_IR_VOLDEC:
            case VK_IR_VOLINC:
                break;
    
            case VK_IR_CHINC:
            case VK_IR_CHDEC:
            case VK_IR_NUM0:
            case VK_IR_NUM1:
            case VK_IR_NUM2:
            case VK_IR_NUM3:
            case VK_IR_NUM4:
            case VK_IR_NUM5:
            case VK_IR_NUM6:
            case VK_IR_NUM7:
            case VK_IR_NUM8:
            case VK_IR_NUM9:
            case VK_IR_INPUTCH:
            case VK_IR_RETURN:
                if (_SOURCE_VIDEO_TV != _GET_INPUT_SOURCE())  // TV key
                    return;
    
                break;
            default:
                return;
        }

        CLR_KEYREPEATENABLE();
        ucOsdState = _MENU_NONE;
        bRCallOSD  = 1;
       // COsdProc();
    }
}

//------------------------------------------------------------
void MPublicNoneMenu(void)
{           
    InitOSDFrame();
    CDrawColorPage();
    ucOsdState = MENU_MAIN_COLOR;
    CShowSelectMainItemWindow(_FIRST_ITEM);

    COsdFxEnableOsd();
}

//------------------------------------------------------------
void MMainItemProc(void)
{
    switch(ucKeyMessage)
    {
        //  Select item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
#endif
        case VK_MENU:        MMainItemMenu();       break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MMainItemLR(1);        break;
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MMainItemLR(0);        break;

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER:       COsdDispOsdTimerEvent();    break;
#endif

        // Default
        default:             COthterKeyAction();    break;
    }
}

//------------------------------------------------------------
void MMainItemMenu(void)
{       
    // Enter Sub Item
    switch(ucOsdState)
    {
        case MENU_MAIN_COLOR: 
            ucOsdState = MENU_ITEM_BRIGHT;      
            break;

#if(_VGA_SUPPORT || _YPBPR_SUPPORT)
        case MENU_MAIN_PICTURE:
            ucOsdState= MENU_ITEM_AUTO;      
            break;
#endif
            
#if(_VIDEO_TV_SUPPORT)
        case MENU_MAIN_TV_FUNC:
            ucOsdState= MENU_AUTO_SEARCH;      
            break;
#endif
            
        case MENU_MAIN_OSD_FUNC:
            ucOsdState= MENU_SUB_LANGUAGE;      
            break;

        case MENU_MAIN_SOUND:
            ucOsdState= MENU_SUB_VOLUME;      
            break;

        case MENU_MAIN_OTHER:
            ucOsdState= MENU_SUB_RESET;      
            break;

        case MENU_MAIN_EXIT:
            COsdDispOsdTimerEvent();
            break;

    }

    CSetItemWindowState(_SELECT_MAIN_WINDOW, _SELECT_STATE);
    CShowSubItemWindow(_FIRST_ITEM);
}

//------------------------------------------------------------
void MMainItemLR(BYTE  LR)
{  
    BYTE ucTemp = 0;

    CClearSubItem();

    if(LR)
    {     
        switch(ucOsdState)
        {
            case MENU_MAIN_COLOR:
                switch(_GET_INPUT_SOURCE())
                {
#if(_VGA_SUPPORT || _YPBPR_SUPPORT)
                    case _SOURCE_VGA:
                    case _SOURCE_YPBPR:
                        ucOsdState = MENU_MAIN_PICTURE;      
                        break;
#endif

                    case _SOURCE_DVI:
                    case _SOURCE_HDMI:
                    case _SOURCE_VIDEO_AV:
                    case _SOURCE_VIDEO_SV:
                    case _SOURCE_VIDEO_YUV:
                    case _SOURCE_VIDEO_SCART:
                        ucOsdState = MENU_MAIN_OSD_FUNC;      
                        break;

#if(_VIDEO_TV_SUPPORT)
                    case _SOURCE_VIDEO_TV:
                        ucOsdState = MENU_MAIN_TV_FUNC;      
                        break;
#endif
                }
                break;

            case MENU_MAIN_PICTURE:        
            case MENU_MAIN_TV_FUNC:        ucOsdState = MENU_MAIN_OSD_FUNC;     break;
            case MENU_MAIN_OSD_FUNC:       ucOsdState = MENU_MAIN_SOUND;        break;
            case MENU_MAIN_SOUND:          ucOsdState = MENU_MAIN_OTHER;        break;
            case MENU_MAIN_OTHER:          ucOsdState = MENU_MAIN_EXIT;         break;
            case MENU_MAIN_EXIT:           ucOsdState = MENU_MAIN_COLOR;        break;
        }  
    }
    else
    {
        switch(ucOsdState)
        {
            case MENU_MAIN_COLOR:          ucOsdState = MENU_MAIN_EXIT;         break;
            case MENU_MAIN_PICTURE:
            case MENU_MAIN_TV_FUNC:        ucOsdState = MENU_MAIN_COLOR;        break;
            case MENU_MAIN_OSD_FUNC:       
                switch(_GET_INPUT_SOURCE())
                {
#if(_VGA_SUPPORT || _YPBPR_SUPPORT || _HDMI_SUPPORT)
                    case _SOURCE_VGA:
                    case _SOURCE_YPBPR:
                        ucOsdState = MENU_MAIN_PICTURE;      
                        break;
#endif

                    case _SOURCE_DVI:
                    case _SOURCE_HDMI:
                    case _SOURCE_VIDEO_AV:
                    case _SOURCE_VIDEO_SV:
                    case _SOURCE_VIDEO_YUV:
                    case _SOURCE_VIDEO_SCART:
                        ucOsdState = MENU_MAIN_COLOR;      
                        break;

#if(_VIDEO_TV_SUPPORT)
                    case _SOURCE_VIDEO_TV:
                        ucOsdState = MENU_MAIN_TV_FUNC;      
                        break;
#endif
                }
                break;            

            case MENU_MAIN_SOUND:          ucOsdState = MENU_MAIN_OSD_FUNC;     break;
            case MENU_MAIN_OTHER:          ucOsdState = MENU_MAIN_SOUND;        break;
            case MENU_MAIN_EXIT:           ucOsdState = MENU_MAIN_OTHER;        break;
        }
    }
    
    if (_GET_INPUT_SOURCE() == _SOURCE_VIDEO_AV       || _GET_INPUT_SOURCE() == _SOURCE_VIDEO_SV
          || _GET_INPUT_SOURCE() == _SOURCE_VIDEO_YUV || _GET_INPUT_SOURCE() == _SOURCE_DVI
          || _GET_INPUT_SOURCE() == _SOURCE_HDMI      || _GET_INPUT_SOURCE() == _SOURCE_VIDEO_SCART)  // eric 0718
        ucTemp = 1; 
    else
        ucTemp = 0;

    switch(ucOsdState)
    {
        case MENU_MAIN_COLOR:
            CDrawColorPage();
            ucTemp = 0;
            break;

#if(_VGA_SUPPORT || _YPBPR_SUPPORT)
        case MENU_MAIN_PICTURE:
            CDrawPicturePage();
            ucTemp = 1;
            break;
#endif

#if(_VIDEO_TV_SUPPORT)
        case MENU_MAIN_TV_FUNC:
            CDrawTVFunction();
            ucTemp = 1;
            break;
#endif

        case MENU_MAIN_OSD_FUNC:
            CDrawOSDFuncPage();

            if (ucTemp)
               ucTemp = 1;
            else
               ucTemp = 2;
            break;

        case MENU_MAIN_SOUND:
            CDrawSoundPage();
            if (ucTemp)
               ucTemp = 2;
            else
               ucTemp = 3;
            break;

        case MENU_MAIN_OTHER:
            CDrawOtherFuncPage();
            if (ucTemp)
               ucTemp = 3;
            else
               ucTemp = 4;
            break;

        case MENU_MAIN_EXIT:
            CDrawExitPage();
            if (ucTemp)
               ucTemp = 4;
            else
               ucTemp = 5;
            break;
    }   
    
    CShowSelectMainItemWindow(ucTemp);
}

//-----------------------------------------------------------
void COsdDispFirstTimeLoadFont(void)
{               
    //Before First Time Load Font Disable OSD
    COsdFxDisableOsd();
    COsdColorPalette(tPALETTE_0);
    
    //Load Public Fonts
    SetOsdMap(tUserMenuOsdMap);
    
    COsdLoad1BitFont(tFntGlobal,0x00,123,tFntGlobalPixelWidth);
    //Load Languege Font
    LoadLanguageFont();
    
    // Load 4 bit icon
    CScalerLoadHardwareVLCFont(tFntIcon4Bit, (_4BIT_ICON_COLOR_ADDR*4));  // icon
    if (_SOURCE_VIDEO_TV == _GET_INPUT_SOURCE())
    {
        CScalerLoadHardwareVLCFont(tFntIcon4BitTvFunc, _4BIT_ICON_TV_FUNC_ADDR*4);     // TV function icon
        CScalerLoadHardwareVLCFont(tFntIcon4BitOSD, ((_4BIT_ICON_TV_FUNC_ADDR+6)*4));  // OSD function icon
    }
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

//-----------------------------------------------------------
void LoadLanguageFont()
{   
    switch(GET_LANGUAGE())
    {
    case LNG_CHI_S:
#if(LNG_CHI_S_EN == 1)

        CScalerLoadHardwareVLCFont(tFntIcon4Bit, (_4BIT_ICON_COLOR_ADDR*4));  // icon
    	COsdLoad1BitFontWidth12(tFntChiPublic,0x7B,0x2D);	
    	COsdLoad1BitFontWidth12(tFntChi_S,0xA8,0x22);
	
#endif
        break;
        
    case LNG_CHI_T:
#if(LNG_CHI_T_EN == 1)
    	COsdLoad1BitFontWidth12(tFntChiPublic,0x7B,0x2D);	
    	COsdLoad1BitFontWidth12(tFntChi_T,0xA8,0x22);	
#endif
        break;
    }  
}
//-----------------------------------------------------------
void COsdDispOsdTimerEvent(void)
{
    COsdFxDisableOsd();
    ucOsdState   = _MENU_NONE;       
    ucOSDAdjTemp = 0;
    OSDClear(0, ROW_COUNT, 0 , COL_WIDTH, 0x00, BYTE_DISPLAY);
    //COsdFxCloseAllWindow();
    CLR_KEYREPEATENABLE();
}

//-----------------------------------------------------------
void COsdEventMsgProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _SHOW_NOSIGNAL_MSG:
    case _SHOW_NOCABLE_MSG:
    case _SHOW_NOSUPPORT_MSG:
        CMuteOn();
        HintDialog();
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
        
    case _ENTER_FACTORY_MODE_MSG:
        //stOsdUserData.OsdSettingFlag |= _BIT7;
        break;
        
    case _CHANGE_SOURCE_MSG:
        CLR_SOURCE_AUTOCHANGE();
        CEepromSaveSystemData();
        ucTVSyncFailCount = 250;
        CLR_CLEAR_OSD_EN();
        CModeResetMode();
        ShowNote();
        SET_FIRST_SHOW_NOTE();
        break;
        
    case _DO_AUTO_CONFIG:
#if(_VGA_SUPPORT)
        //       DoAuto();
#endif
        break;   
        
    case _DO_SHOW_NOTE:
        CLR_FIRST_SHOW_NOTE();
        ShowNote();
        break;
        
    default:
        break;
    }
    
    ucOsdEventMsg = _NONE_MSG;
}

//----------------------------------------------------------------------------------------------------
void ShowMode(void)
{
    if (ucCurrState == _NOSIGNAL_STATE) 
        return;
    
    switch(_GET_INPUT_SOURCE())
    {
    case _SOURCE_VGA:
    case _SOURCE_DVI:
    case _SOURCE_HDMI:
        //display display size
        Gotoxy(5,_MESSAGE_V_POSITION,0x50);
        OutputDisplaySize();
        //display refresh
        Gotoxy(17,_MESSAGE_V_POSITION,0x50);
        OutputChar('@');          
        OutputChar(0x00);            
        OutputRefrushRate();  
        break; 

#if(_YPBPR_SUPPORT)
    case _SOURCE_YPBPR:
        if (stModeInfo.ModeCurr < _MAX_YPBPR_MODE)
			CCenterTextout(sYPbPrMode[stModeInfo.ModeCurr],ROW(_MESSAGE_V_POSITION),COL(0),29);
        break;
#endif

#if(_VIDEO_SUPPORT)
    case _SOURCE_VIDEO_AV:
    case _SOURCE_VIDEO_SV:
    case _SOURCE_VIDEO_YUV:
    case _SOURCE_VIDEO_SCART:
        if(ucVideoType > ZPAL_60)
			CCenterTextout(sPAL,ROW(_MESSAGE_V_POSITION),COL(0),29);
        else
			CCenterTextout(sNTSC,ROW(_MESSAGE_V_POSITION),COL(0),29);
        break;

  #if(_VIDEO_TV_SUPPORT) 
    case _SOURCE_VIDEO_TV:
        CCenterTextout(sTVType[ucTVType],ROW(_MESSAGE_V_POSITION),COL(0),30);
        break;
  #endif
#endif
    }
}

//---------------------------------------------------------------------------------------------------------------------
void OSDSlider(BYTE row, BYTE col, BYTE length, BYTE value, BYTE range,
               BYTE color, bit bMode)
{
    WORD bound;
    BYTE i,c;
    
    OSDLine(row, col, length + 6, color, THE_BYTE2);   // Set Slider Attribute. 4 extra columns for space/numbers/space
    bound   = length * value;
    Gotoxy(col,row,THE_BYTE1);
    OutputChar(0x21);          // Left Border
    
    for (i = 1; i <= length; i++)
    {
        if (bound)
        {
            if(bound >= range)
            {
                c       = 0x28;
                bound   = bound - range;
            }
            else
            {
                color   = (bound << 4) / range;
                bound   = 0;
                if (4 > color)                    c = 0x23;
                else if (7 > color)               c = 0x24;
                else if (10 > color)              c = 0x25;
                else if (13 > color)              c = 0x26;
                else                              c = 0x27;
            }
        }
        else
        {
            c = 0x22;
        }
        OutputChar(c);
    }
    OutputChar(0x29);    // Right Border
    OutputChar(0x00);

    if (_SHOW_PERCENT == bMode)
    {
        CShowNumber1(value, 0);    //百分比显示在右边
        OutputChar(0x2a);
        if (value < 100)
           OutputChar(0x00);
    }
}

//---------------------------------------------------------------------------
void DispIcon(BYTE x, BYTE y, BYTE ucIconBaseAddr)
{
    Gotoxy(x, y, BYTE_DISPLAY);
    
    pData[0] = ucIconBaseAddr;
    pData[1] = ucIconBaseAddr + 1;
    pData[2] = ucIconBaseAddr + 2;
    CScalerWrite(_OSD_DATA_PORT_92, 3, pData, _NON_AUTOINC);
    
    Gotoxy(x, y + 1, BYTE_DISPLAY);
    pData[0] = ucIconBaseAddr + 3;
    pData[1] = ucIconBaseAddr + 4;
    pData[2] = ucIconBaseAddr + 5;
    CScalerWrite(_OSD_DATA_PORT_92, 3, pData, _NON_AUTOINC);
}
//---------------------------------------------------------------------------

void NotUseFunc()
{ 
 //   SetOSDRamAddress(0,0,0);
   // DirectWOSDRam(0,0,0,0);
 //   SetRowCmds(0,0);
    //  Gotoxy(0,0,0);
 //   OutputChar(0);
//    Textout(0);
//    PrintfDec(0);
    //    OSDPosition(0,0,0,0,0);
    //  OSDLine(0,0,0,0,0);
    //    OSDClear(0,0,0, 0,0,0);
  //  OutputDisplaySize();       //在当前的位置输出显示尺寸
 //   OutputRefrushRate();       //在当前的位置输出刷新频率
    //    COsdFxCodeWrite(0);
    //  COsdFxDisableOsd();
    //   COsdFxDrawWindow(0,0,0,0,0);
//    StrLen(0);
    //    ValueInRangeChange(0,0,0,0,0);
  //  CAutoDoAutoConfig();
    CAutoDoWhiteBalance();
#if(_VGA_SUPPORT)
    DoAuto();
#endif
    InitBurnIn();
    BurnInRun();
    COsdLoad1BitFont(0, 0x00, 123, 0);
    CShowNumber(0,0,0);
    CTextOutRightAlign(0,0,0);
//    ChangeSourceHandler();
    CAdjustMZHueSat(0);
    //   CEepromSaveOsdUserData();
    //    CEepromSaveBriConData();
  //  CEepromSaveColorTempData();
 //   CScalerLoadFont(0, 0, 0, 0);
    //  ShowMode();
    //   OSDSlider(0, 0, 0, 0, 0,0);   
   // GetNextLanguage(0);
//    GetPrevLanguage(0);
  //  CheckLanguage();
  //  FirstLanguage();
   //   COsdFxEnableOsd();
  //  DoReset();
 //   VPosGuage();
  //  HPosGuage();
 //   ClockGuage();
  //  COsdFxCloseWindow(0);
//    GotoAdjustBrightness();
 //   gmi_CInitial_IR();
 //   gmi_CStopIR();
//    gmi_CStartIR();
//    gmi_IR_Delay();
//    RightAlignTextOut(0,0,0);
 //   CShowNumber(0,0);
 //   CDrawColorPage();
//    CDrawOSDFuncPage();
  //  CDrawSoundPage();
  //  CDrawOtherFuncPage();
  //  GetVirtualKey();
  //  ShowMode();
#if(_VIDEO_TV_SUPPORT && _FM_DEVICE) 
      CChangeFM();
#endif
}

//----------------------------------------------------------------------------------------------------
void CClearWindow(BYTE ucCharacterColor)
{
    OSDClear(0, ROW_COUNT, 0, COL_WIDTH, 0x8C, THE_BYTE0);
    OSDClear(0, ROW_COUNT, 0, COL_WIDTH, 0x00, THE_BYTE1);
    OSDClear(0, ROW_COUNT, 0, COL_WIDTH, ucCharacterColor, THE_BYTE2);
}

//----------------------------------------------------------------------------------------------------
void CInitOSDMainFrame(void)
{        
    COsdFxDisableOsd();
    SetOsdMap(tUserMenuOsdMap);
    COsdFxCodeWrite(ucCloseAllWindow);
	CScalerSetBit(_OVERLAY_CTRL_6C, 0x23, ((stOsdUserData.OsdBlending & 0x07) << 2));

    CClearWindow(0x40);  // Clear window and set character color to black
}

//----------------------------------------------------------------------------------------------------
void InitOSDFrame(void)
{    
    BYTE ucTemp = 0;
   
    CInitOSDMainFrame();
    SetOSDDouble((GET_OSD_SIZE() ? 0x03 : 0x00)  | OSD_WINDOWCHAR_BLENDING);   

#if(_OSD_DISPLAY_SIZE_ADJ)
    if (GET_OSD_SIZE())
        OSDPosition(_MAIN_OSD_DOUBLE_WIDTH, _MAIN_OSD_DOUBLE_HEIGHT, stOsdUserData.OsdHPos, stOsdUserData.OsdVPos, 0x03);
    else
        OSDPosition(_MAIN_WINDOW_WIDTH,_MAIN_WINDOW_HEIGHT,stOsdUserData.OsdHPos, stOsdUserData.OsdVPos, 0x03);
#else
    OSDPosition(_MAIN_WINDOW_WIDTH,_MAIN_WINDOW_HEIGHT,stOsdUserData.OsdHPos, stOsdUserData.OsdVPos, 0x03);
#endif
    // Set item shadow
#if(_OSD_SHADOW_FUNC == _ENABLE)
    DirectWOSDRam(0x04, ROW_COUNT-0x04, THE_BYTE0, (0x80 | 0x18));
#endif
#if(0)//!_OSD_DISPLAY_SIZE_ADJ && !_ALPHA_BLENDING_ADJ)
    pData[0] = 0x40;
    pData[1] = 0x03;
    pData[2] = 0xa0;
    CScalerWrite(_OSD_ADDR_MSB_90,3,pData,_AUTOINC);
#endif

    // Draw window
    COsdFxDrawWindow(XSTART(_MAIN_WINDOW_H_POS),                  YSTART(_MAIN_WINDOW_V_POS), 
                     XEND(_MAIN_WINDOW_H_POS+_MAIN_WINDOW_WIDTH), YEND(_MAIN_WINDOW_V_POS+_MAIN_WINDOW_HEIGHT), 
                     tOSD_MAIN_WINDOW_STYLE);

    COsdFxDrawWindow(XSTART(_LINE_WINDOW_H_POS),                  YSTART(_LINE_WINDOW_V_POS),
                     XEND(_LINE_WINDOW_H_POS+_LINE_WINDOW_WIDTH), YEND(_LINE_WINDOW_V_POS+_LINE_WINDOW_HEIGHT), 
                     tOSD_LINE_WINDOW_STYLE);

    // Init Char Cmd
    // Set row 1/2 to 4bit
    OSDClear(1, 2, 0, COL_WIDTH-1, 0x90, BYTE_ATTRIB);

    // Set row height to 31, and col space to 0
    DirectWOSDRam(3, 1, THE_BYTE1, 0xf8); // Row 3
    // Set row height to 22, and col space to 0
    DirectWOSDRam(4, 9, THE_BYTE1, 0xb0); // Row 4 ~ (4+9)

    // Show 4bit Icon
    CShow4BitIcon();
    ShowMode();
    CLR_KEYREPEATENABLE();

}

//----------------------------------------------------------------------------------------------------
void CShow4BitIcon(void)
{
    BYTE uctemp;

    switch(_GET_INPUT_SOURCE())
    {
#if(_VGA_SUPPORT || _YPBPR_SUPPORT)
    case _SOURCE_VGA:
    case _SOURCE_YPBPR:
        for(uctemp = 0; uctemp < 6; uctemp++)
        {
            DispIcon(1+(4*uctemp), 1, _4BIT_ICON_COLOR_ADDR+(uctemp*6));
        } 
        break;
#endif

#if(_TMDS_SUPPORT || _VIDEO_AV_SUPPORT || _VIDEO_SV_SUPPORT || _VIDEO_YUV_SUPPORT || _HDMI_SUPPORT || _VIDEO_SCART_SUPPORT)                                    
    case _SOURCE_DVI:
    case _SOURCE_HDMI:
    case _SOURCE_VIDEO_AV:
    case _SOURCE_VIDEO_SV:
    case _SOURCE_VIDEO_YUV:
    case _SOURCE_VIDEO_SCART:
        DispIcon(1+(4*0), 1, _4BIT_ICON_COLOR_ADDR+(0*6));
        DispIcon(1+(4*1), 1, _4BIT_ICON_COLOR_ADDR+(2*6));
        DispIcon(1+(4*2), 1, _4BIT_ICON_COLOR_ADDR+(3*6));
        DispIcon(1+(4*3), 1, _4BIT_ICON_COLOR_ADDR+(4*6));
        DispIcon(1+(4*4), 1, _4BIT_ICON_COLOR_ADDR+(5*6));

        break;
#endif // end #if(_TMDS_SUPPORT || _VIDEO_AV_SUPPORT || _VIDEO_SV_SUPPORT || _VIDEO_YUV_SUPPORT || _HDMI_SUPPORT || _VIDEO_SCART_SUPPORT)                                    

#if(_VIDEO_TV_SUPPORT)
    case _SOURCE_VIDEO_TV:
        for(uctemp = 0; uctemp < 6; uctemp++)
        {                                                            
            DispIcon(1+(4*uctemp), 1, _4BIT_ICON_COLOR_ADDR+(uctemp*6));
        } 
        break;
#endif  // end #if(_VIDEO_TV_SUPPORT)
    }
}     


//----------------------------------------------------------------------------------------------------
void CShowSelectMainItemWindow(BYTE ucItem)
{
    COsdFxDrawWindow(XSTART(16+(ucItem*48)), YSTART(12), XEND(64+(ucItem*48)), YEND(58), tOSD_SELECT_MAIN_WINDOW_STYLE);
}

//----------------------------------------------------------------------------------------------------
void CShowSubItemWindow(BYTE ucItem)
{
    OSDClear(4, 8, 1, 15, 0x40, BYTE_COLOR);            // Clear item color
    OSDClear((4+ucItem), 1, 1, 15, 0x10, BYTE_COLOR);   // Set current sub item character color to white
    COsdFxDrawWindow(XSTART(18), YSTART(81+(ucItem*23)), XEND(206), YEND(81+24+(ucItem*23)), tOSD_SELECT_SUB_WINDOW_STYLE);
}

//----------------------------------------------------------------------------------------------------
// Set window to select or move state
void CSetItemWindowState(BYTE ucWinNumber, BYTE ucItemState)
{
    pData[0]    = 0x81;
    pData[1]    = (BYTE)(ucWinNumber * 4+3);
    pData[2]    = SHADOW_BORDER_EN(1) | WINDOW_TYPE(ucItemState) | WINDOW_ENABLE(1);
    CScalerWrite(_OSD_ADDR_MSB_90, 3, pData, _AUTOINC);
}

//----------------------------------------------------------------------------------------------------
void CExitToMainItem(BYTE ucMainItem)
{
    OSDClear(4, 8, 1, 15, 0x40, BYTE_COLOR);  // Clear item color
    COsdFxCloseWindow(_SELECT_SUB_WINDOW);    // Disable sub item window
    ShowMode();
    ucOsdState = ucMainItem;

    CSetItemWindowState(_SELECT_MAIN_WINDOW, _MOVE_STATE); // Set main item window to move state
}

//----------------------------------------------------------------------------------------------------
void CGotoNextSubItem(BYTE ucItem)
{
    CShowSubItemWindow(ucItem);
    CLR_KEYREPEATENABLE();
}

//----------------------------------------------------------------------------------------------------
void CClearSubItem(void)
{   // Clear item character
    OSDClear(4, 8, 1, COL_WIDTH - 2, 0x00, BYTE_DISPLAY);
    OSDClear(4, 8, 1, COL_WIDTH - 2, 0x8C, BYTE_ATTRIB);
}

//----------------------------------------------------------------------------------------------------
void CClearMsg(BYTE ucMode)
{
    // Set Character width to 12 
    OSDLine(_MESSAGE_V_POSITION, 1, COL_WIDTH - 1, 0x8c, BYTE_ATTRIB);
    OSDClear(_MESSAGE_V_POSITION, 1, 1, COL_WIDTH - 2, 0x00, BYTE_DISPLAY);
    CLR_KEYREPEATENABLE();
    
    switch(ucMode)
    {
        case _CLEAR_AND_SELECT_SUB_ITEM:
            CSetItemWindowState(_SELECT_SUB_WINDOW, _SELECT_STATE);
            break;

        case _CLEAR_AND_EXIT_SUB_ITEM:
            CSetItemWindowState(_SELECT_SUB_WINDOW, _MOVE_STATE);
            ShowMode();
            break;

        case _CLEAR_MSG_ONLY:
            break;
    }
}

//----------------------------------------------------------------------------------------------------
void CDrawColorPage(void)
{                     
    BYTE uctemp = 0;
                                           
    CTextOutEx(sBright[GET_LANGUAGE()], 1, 4);          // "Brightness"
    CTextOutEx(sContrast[GET_LANGUAGE()], 1, 5);        // "Contrast"

    uctemp = 6;

    switch(_GET_INPUT_SOURCE())
    {
#if(_VGA_SUPPORT || _TMDS_SUPPORT || _YPBPR_SUPPORT || _HDMI_SUPPORT)
    case _SOURCE_VGA:
    case _SOURCE_DVI:
    case _SOURCE_HDMI:
    case _SOURCE_YPBPR:
    #if(_COLOR_TEMP)
        if (_SOURCE_YPBPR != _GET_INPUT_SOURCE())
        {
            CTextOutEx(sColorTemp[GET_LANGUAGE()], 1, 6);   // "Color Temp."
            uctemp = 7;
        }
        else
            uctemp = 6;
    #else
        uctemp = 6;
    #endif
        break;
#endif

#if(_VIDEO_SUPPORT)                                    
    case _SOURCE_VIDEO_AV:
    case _SOURCE_VIDEO_SV:
    case _SOURCE_VIDEO_YUV:
    case _SOURCE_VIDEO_TV:
    case _SOURCE_VIDEO_SCART:
        CTextOutEx(sSaturation[GET_LANGUAGE()], 1, 6);  // "Saturation"
        CTextOutEx(sHue[GET_LANGUAGE()], 1, 7);         // "Hue"
        uctemp = 8;
        break;
#endif
    }

    CTextOutEx(sExit[GET_LANGUAGE()], 1, uctemp);    // "Exit"

}

//----------------------------------------------------------------------------------------------------
void CDrawOSDFuncPage(void)
{
    BYTE uctemp = 4;

    CTextOutEx(sLanguage[GET_LANGUAGE()], 1, 4);       // "Language"

#if(_OSD_POSITION_ADJ_CTRL)
    CTextOutEx(sOSDHPosition[GET_LANGUAGE()], 1, 5);       // "OSD H Position"
    CTextOutEx(sOSDVPosition[GET_LANGUAGE()], 1, 6);       // "OSD V Position"
    uctemp = 7;
#else
    uctemp = 5;
#endif
    
#if(_OSD_TIMEOUT_ADJ_CTRL)
    CTextOutEx(sOSDTimeOut[GET_LANGUAGE()], 1, uctemp);     // "OSD Timeout"
    uctemp++;
#endif

#if(_ALPHA_BLENDING_ADJ == _ON)
    CTextOutEx(sOSDTranslucent[GET_LANGUAGE()], 1, uctemp); // "OSD Translucent"
    uctemp++;
#endif

#if(_OSD_DISPLAY_SIZE_ADJ == _ON)
    CTextOutEx(sOSDSize[GET_LANGUAGE()], 1, uctemp);        // "OSD Size"
    uctemp++;
#endif

    CTextOutEx(sExit[GET_LANGUAGE()], 1, uctemp);           // "Exit"
}

//----------------------------------------------------------------------------------------------------
void CDrawSoundPage(void)
{
    CTextOutEx(sVolume[GET_LANGUAGE()], 1, 4);          // "Volume"
    CTextOutEx(sMute[GET_LANGUAGE()], 1, 5);            // "Mute"

#if(_SOUND_PROCESSOR == _ENABLE)
    CTextOutEx(sBalance[GET_LANGUAGE()], 1, 6);         // "Balance"
    CTextOutEx(sBass[GET_LANGUAGE()], 1, 7);            // "Bass"
    CTextOutEx(sTreble[GET_LANGUAGE()], 1, 8);          // "Treble"
  //  CTextOutEx(sSRS[GET_LANGUAGE()], 1, 9);             // "SRS"
  //  CTextOutEx(sBBE[GET_LANGUAGE()], 1, 10);            // "BBE"
    CTextOutEx(sExit[GET_LANGUAGE()], 1, 9);           // "Exit"
#else
    CTextOutEx(sExit[GET_LANGUAGE()], 1, 6);            // "Exit"
#endif
}
//----------------------------------------------------------------------------------------------------

#if(_VGA_COLOR_SUPPORT)
void CDrawVividColorPage(void)
{         
    CClearVColorItem();                                             
    CTextOutEx(sText, 1, 1);                // "Text"
    CTextOutEx(sMovie, 1, 2);               // "Movie"
    CTextOutEx(sGraphic, 1, 3);             // "Graphic"
    CTextOutEx(sGame, 1, 4);                // "Game"
    CTextOutEx(sNormal, 1, 5);              // "Normal"
    CTextOutEx(sUser, 1, 6);                // "User"
    CTextOutEx(sExit[GET_LANGUAGE()], 1, 7);  // "Exit"
    

}
//----------------------------------------------------------------------------------------------------
void CDrawVividColorSubPage(void)
{
    CClearVColorItem();
    CTextOutEx(sVividColor, 3, 1);          // "Vivid Color"
    CTextOutEx(sDCC, 4, 3);                 // "DCC"
    CTextOutEx(sICM, 4, 4);                 // "ICM"
    CTextOutEx(sColor, 4, 5);               // "Color"
    CTextOutEx(sExit[GET_LANGUAGE()], 4, 6);  // "Exit" 
}

//----------------------------------------------------------------------------------------------------
void CDrawDCCPage(void)
{
    CClearVColorItem();
    CTextOutEx(sText, 3, 1);                // "Text"
    CTextOutEx(sMovie, 3, 2);               // "Movie"
    CTextOutEx(sGraphic, 3, 3);             // "Graphic"
    CTextOutEx(sGame, 3, 4);                // "Game"
    CTextOutEx(sDCCNormal, 3, 5);           // "DCC Normal"
}

//----------------------------------------------------------------------------------------------------
void CDrawICMPage(void)
{
    CClearVColorItem(); 
    CTextOutEx(sRed, 1, 1);                  // "Red"
    CTextOutEx(sGreen, 1, 2);                // "Green"
    CTextOutEx(sBlue_ENG, 1, 3);             // "Blue"
    CTextOutEx(sYellow, 1, 4);               // "Yellow"
    CTextOutEx(sCyan, 1, 5);                 // "Cyan"
    CTextOutEx(sMagenta, 1, 6);              // "Magenta"                                
    CTextOutEx(sICM, 1, 7);                  // "ICM"
    CCenterTextout(sOn_Off[GET_MZ_ICM_ON_OFF_TYPE()][GET_LANGUAGE()],ROW(7),COL(0),30);
    CTextOutEx(sExit[GET_LANGUAGE()], 1, 8);   // "Exit"  
}

//----------------------------------------------------------------------------------------------------
void CDrawVividSubColorPage(void)
{
    CClearVColorItem();
    CTextOutEx(sBright[GET_LANGUAGE()], 1, 1);    // "Bright"
    Gotoxy(12, 1, BYTE_DISPLAY);         
    CShowNumber(stOsdUserData.MZBright, 0);

    CTextOutEx(sContrast[GET_LANGUAGE()], 1, 3);  // "Contrast"
    Gotoxy(12, 3, BYTE_DISPLAY);         
    CShowNumber(stOsdUserData.MZContrast, 0);

    CTextOutEx(sPeaking, 1, 5);                 // "Peaking"
    Gotoxy(12, 5, BYTE_DISPLAY);         
    CShowNumber(stOsdUserData.MZPeaking, 0);

    CTextOutEx(sExit[GET_LANGUAGE()], 1, 7);      // "Exit"
}

//----------------------------------------------------------------------------------------------------
void CDrawICMColorAdjPage(void)
{
    CClearVColorItem();
    CTextOutEx(sHue[GET_LANGUAGE()], 1, 2);         // "Hue"
    CTextOutEx(sSaturation[GET_LANGUAGE()], 1, 4);  // "Saturation"
    CTextOutEx(sExit[GET_LANGUAGE()], 1, 6);        // "Exit"

}
#endif

//----------------------------------------------------------------------------------------------------
void CDrawOtherFuncPage(void)
{
    BYTE uctemp = 5;

    CTextOutEx(sReset[GET_LANGUAGE()], 1, 4);           // "Reset"
#if(_BLUE_BACKGROUND_FUNC == _ENABLE)
    CTextOutEx(sBlue[GET_LANGUAGE()], 1, 5);            // "Blue"
    uctemp++;
#endif
#if(_SLEEP_FUNC)
    CTextOutEx(sAutoPowerDown[GET_LANGUAGE()], 1, uctemp);   // "Auto power down"
    uctemp++;
#endif
          
#if(_IMAGE_COLOR_MODE)
    CTextOutEx(sColorMode[GET_LANGUAGE()], 1, uctemp);  // "Color mode"
    uctemp++;
#endif
           
#if(_SHARPNESS_ADJ)
    CTextOutEx(sSharp[GET_LANGUAGE()], 1, uctemp);      // "Sharp"
    uctemp++;
#endif      

    CTextOutEx(sExit[GET_LANGUAGE()], 1, uctemp);       // "Exit"
}   

//----------------------------------------------------------------------------------------------------
void CDrawExitPage(void)
{
    CTextOutEx(sExit[GET_LANGUAGE()], 1, 4);            // "Exit"
}

//----------------------------------------------------------------------------------------------------
//   Color Sub item
void MColorSubItemProc(void)
{
    switch(ucKeyMessage)
    {
        // Select item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
        case VK_F_RIGHT:
#endif
        case VK_MENU:        MColorSubItemMenu();               break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
#endif
        case VK_LEFT:        MColorSubItemLR(1);                break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_DOWN:
#endif
        case VK_RIGHT:       MColorSubItemLR(0);                break;

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER:       CExitToMainItem(MENU_MAIN_COLOR);  break;
#endif
        
        // Other key
        default:             COthterKeyAction();                break;
    }
}

//----------------------------------------------------------------------------------------------------
void MColorSubItemMenu(void)
{      
    CClearMsg(_CLEAR_AND_SELECT_SUB_ITEM);

    switch(ucOsdState)
    {
        case MENU_ITEM_BRIGHT:  
            SLIDER1(BRIGHTNESS_GUAGE);
            ucOsdState = MENU_SUB_BRIGH_ADJ;     
            break;

        case MENU_ITEM_CONTRAST:       
            SLIDER1(CONTRAST_GUAGE);
            ucOsdState = MENU_SUB_CONTRAST_ADJ;   
            break;

#if(_VGA_SUPPORT || _TMDS_SUPPORT || _YPBPR_SUPPORT)
   #if(_COLOR_TEMP)
        case MENU_ITEM_COLOR_TEMP:
            CClearSubItem();
            CDrawColorTempSubItem();
            {
                BYTE ucTemp = GET_COLOR_TEMP_TYPE();

                switch(ucTemp)
                {
                    case 0:
                        ucOsdState = MENU_SUB_CT_9300;        
                        break;

                    case 1:
                        ucOsdState = MENU_SUB_CT_6500;        
                        break;

                    case 2:
                        ucOsdState = MENU_SUB_CT_5800;        
                        break;

                    case 3:
                        ucOsdState = MENU_SUB_CT_SRGB;        
                        break;

                    case 4:
                        ucOsdState = MENU_SUB_CT_USER;        
                        break;

                    default:
                        ucOsdState = MENU_SUB_CT_6500; 
                        SET_COLOR_TEMP_TYPE(_CT_6500);
                        break;
                }

                CShowSubItemWindow(ucTemp);
            }
            break;
   #endif
#endif

#if(_VIDEO_SUPPORT)
        case MENU_AV_SATURATION:
            SLIDER1(GET_SATURATION());
            ucOsdState = MENU_AV_SATURATION_ADJ;
            break;

        case MENU_AV_HUE:
            SLIDER1(GET_HUE());
            ucOsdState = MENU_AV_HUE_ADJ;
            break;
#endif

        case MENU_SUB_COLOR_CLOSE:
            CExitToMainItem(MENU_MAIN_COLOR);
            break;
    }
}

//----------------------------------------------------------------------------------------------------
void MColorSubItemLR(BYTE LR)
{
    BYTE ucTemp = 0;

    if(LR)
    {
        switch(ucOsdState)
        {
            case MENU_ITEM_BRIGHT:         ucOsdState = MENU_ITEM_CONTRAST;     break;
            case MENU_ITEM_CONTRAST:
            
#if(_VIDEO_SUPPORT)
   #if(_COLOR_TEMP)
                if (CGetInputSourceNum(_GET_INPUT_SOURCE()) == 2)  // Source video
                    ucOsdState = MENU_AV_SATURATION;
                else
                    ucOsdState = (_SOURCE_YPBPR == _GET_INPUT_SOURCE()) ? MENU_SUB_COLOR_CLOSE : MENU_ITEM_COLOR_TEMP;
//                ucOsdState = (CGetInputSourceNum(_GET_INPUT_SOURCE()) == 2) ? MENU_AV_SATURATION : MENU_ITEM_COLOR_TEMP;
   #else
                ucOsdState = (CGetInputSourceNum(_GET_INPUT_SOURCE()) == 2) ? MENU_AV_SATURATION : MENU_SUB_COLOR_CLOSE;
   #endif
#else
   #if(_COLOR_TEMP)
                ucOsdState = MENU_ITEM_COLOR_TEMP;
   #else
                ucOsdState = MENU_SUB_COLOR_CLOSE;
   #endif
#endif           
                break;

#if(_VIDEO_SUPPORT)
            case MENU_AV_SATURATION:       ucOsdState = MENU_AV_HUE;            break;
            case MENU_AV_HUE:              ucOsdState = MENU_SUB_COLOR_CLOSE;   break;
#endif

            case MENU_ITEM_COLOR_TEMP:     ucOsdState = MENU_SUB_COLOR_CLOSE;   break;
            case MENU_SUB_COLOR_CLOSE:     ucOsdState = MENU_ITEM_BRIGHT;       break;
        }
    }
    else
    {
        switch(ucOsdState)
        {
            case MENU_ITEM_BRIGHT:         ucOsdState = MENU_SUB_COLOR_CLOSE;   break;
            case MENU_ITEM_CONTRAST:       ucOsdState = MENU_ITEM_BRIGHT;       break;
            case MENU_ITEM_COLOR_TEMP:     ucOsdState = MENU_ITEM_CONTRAST;     break;

#if(_VIDEO_SUPPORT)
            case MENU_AV_SATURATION:       ucOsdState = MENU_ITEM_CONTRAST;     break;
            case MENU_AV_HUE:              ucOsdState = MENU_AV_SATURATION;     break;
            case MENU_SUB_COLOR_CLOSE:
   #if(_COLOR_TEMP)
                if (CGetInputSourceNum(_GET_INPUT_SOURCE()) == 2)  // Source video
                    ucOsdState = MENU_AV_HUE;
                else
                    ucOsdState = (_SOURCE_YPBPR == _GET_INPUT_SOURCE()) ? MENU_ITEM_CONTRAST : MENU_ITEM_COLOR_TEMP;

              //  ucOsdState = (CGetInputSourceNum(_GET_INPUT_SOURCE()) == 2) ? MENU_AV_HUE : MENU_ITEM_COLOR_TEMP;
   #else
                ucOsdState = (CGetInputSourceNum(_GET_INPUT_SOURCE()) == 2) ? MENU_AV_HUE : MENU_ITEM_CONTRAST;
   #endif
                break;
#else
   #if(_COLOR_TEMP)
            case MENU_SUB_COLOR_CLOSE:     ucOsdState = MENU_ITEM_COLOR_TEMP;   break;
   #else
            case MENU_SUB_COLOR_CLOSE:     ucOsdState = MENU_ITEM_CONTRAST;     break;
   #endif
#endif
        }
    }
    
    switch(ucOsdState)
    {      
        case MENU_ITEM_BRIGHT:
            ucTemp = 0;      
            break;

        case MENU_ITEM_CONTRAST:
            ucTemp = 1;      
            break;

#if(_VIDEO_SUPPORT)
        case MENU_AV_SATURATION:
            ucTemp = 2;
            break;

        case MENU_AV_HUE:
            ucTemp = 3;
            break;
#endif

#if(_COLOR_TEMP)
        case MENU_ITEM_COLOR_TEMP:
            ucTemp = 2;      
            break;
#endif

        case MENU_SUB_COLOR_CLOSE:
#if(_VIDEO_SUPPORT)
    #if(_COLOR_TEMP)
            if (CGetInputSourceNum(_GET_INPUT_SOURCE()) == 2)  // Source video
                ucTemp = 4;
            else
                ucTemp = (_SOURCE_YPBPR == _GET_INPUT_SOURCE()) ? 2 : 3;
//            ucTemp = (CGetInputSourceNum(_GET_INPUT_SOURCE()) == 2) ? 4 : 3; 
    #else
            ucTemp = (CGetInputSourceNum(_GET_INPUT_SOURCE()) == 2) ? 4 : 2; 
    #endif
#else
    #if(_COLOR_TEMP)
            ucTemp = 3;      
    #else
            ucTemp = 2;      
    #endif
#endif     
            break;
    }   
    
    CGotoNextSubItem(ucTemp);
}


//----------------------------------------------------------------------------------------------------
//   OSD Sub item
void MOSDSubItemProc(void)
{
    switch(ucKeyMessage)
    {
        // Select item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
        case VK_F_RIGHT:
#endif
        case VK_MENU:        MOSDSubItemMenu();                    break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
#endif
        case VK_LEFT:        MOSDSubItemLR(1);                     break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_DOWN:
#endif
        case VK_RIGHT:       MOSDSubItemLR(0);                     break;

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER:       CExitToMainItem(MENU_MAIN_OSD_FUNC);  break;
#endif
        
        // Other key
        default:             COthterKeyAction();                   break;
    }
}

//----------------------------------------------------------------------------------------------------
void MOSDSubItemMenu(void)
{
    CClearMsg(_CLEAR_AND_SELECT_SUB_ITEM);

    switch(ucOsdState)
    {
        case MENU_SUB_LANGUAGE:
            CCenterTextout(sLangName[GET_LANGUAGE()],ROW(_MESSAGE_V_POSITION),COL(0),30);
            ucOsdState = MENU_SUB_OSDLANGUAGE_ADJ;     
            break;

#if(_OSD_POSITION_ADJ_CTRL)
        case MENU_SUB_H_POSITION:       
            SLIDER1(stOsdUserData.OsdHPos);
            ucOsdState = MENU_SUB_OSDH_POSITION_ADJ;   
            break;

        case MENU_SUB_V_POSITION:     
            SLIDER1(stOsdUserData.OsdVPos);
            ucOsdState = MENU_SUB_OSDV_POSITION_ADJ;   
            break;
#endif

#if(_OSD_TIMEOUT_ADJ_CTRL)
        case MENU_SUB_OSD_TIMEOUT:  
            if (stOsdUserData.OsdTimeout < 5)
            {
                CCenterTextout(sOn_Off[0][GET_LANGUAGE()],ROW(_MESSAGE_V_POSITION),COL(0),30);
            }
            else
            {
                Gotoxy(14, _MESSAGE_V_POSITION, BYTE_DISPLAY);
                CShowNumber1(stOsdUserData.OsdTimeout, 0);
            }
            ucOsdState = MENU_SUB_OSD_TIMEOUT_ADJ;   
            break;
#endif

#if(_ALPHA_BLENDING_ADJ)
        case MENU_SUB_OSD_TRANSLUCENT:
            if (0 == GET_OSDBLENDING())
            {
                CCenterTextout(sOn_Off[0][GET_LANGUAGE()],ROW(_MESSAGE_V_POSITION),COL(0),30);
            }
            else
            {
                Gotoxy(14, _MESSAGE_V_POSITION, BYTE_DISPLAY);
                CShowNumber1(GET_OSDBLENDING(), 0);
            }
            ucOsdState = MENU_SUB_OSD_TRANS_ADJ;   
            break;
#endif

#if(_OSD_DISPLAY_SIZE_ADJ)
        case MENU_SUB_OSD_SIZE:
            CCenterTextout(sOn_Off[(GET_OSD_SIZE()) ? 1 : 0][GET_LANGUAGE()],ROW(_MESSAGE_V_POSITION),COL(0),30);
            ucOsdState = MENU_SUB_OSD_SIZE_ADJ;   
            break;
#endif

        case MENU_SUB_OSD_CLOSE:
            CExitToMainItem(MENU_MAIN_OSD_FUNC);
            break;
    }
}

//----------------------------------------------------------------------------------------------------
bit bOSDItemSupport(BYTE ucOSDItem)
{
    switch(ucOSDItem)
    {
        case MENU_SUB_LANGUAGE:
        case MENU_SUB_OSD_CLOSE:
            return 1;

#if(_OSD_POSITION_ADJ_CTRL)
        case MENU_SUB_H_POSITION:
        case MENU_SUB_V_POSITION:
            return 1;
#endif

#if(_OSD_TIMEOUT_ADJ_CTRL)
        case MENU_SUB_OSD_TIMEOUT:
            return 1;
#endif

#if(_ALPHA_BLENDING_ADJ)
        case MENU_SUB_OSD_TRANSLUCENT:
            return 1;
#endif

#if(_OSD_DISPLAY_SIZE_ADJ)
        case MENU_SUB_OSD_SIZE:
            return 1;
#endif
    } 
    
    return 0;
}

//----------------------------------------------------------------------------------------------------
void MOSDSubItemLR(BYTE LR)
{
    BYTE ucTemp  = 0;
    BYTE ucItem  = 0;
    
    // Search next item
    while(1)
    {
        ucOsdState = ValueInRangeChange(MENU_SUB_LANGUAGE, MENU_SUB_OSD_CLOSE, ucOsdState, _LOOP | LR);

        if (bOSDItemSupport(ucOsdState))
            break; 
    }

    // Search item position
    ucTemp = MENU_SUB_LANGUAGE;
    while(1)
    {
        if (ucOsdState == ucTemp)
           break;

        ucTemp = ValueInRangeChange(MENU_SUB_LANGUAGE, MENU_SUB_OSD_CLOSE,ucTemp, _LOOP | 0x01);

        if (bOSDItemSupport(ucTemp))
           ucItem++;
    }

    CGotoNextSubItem(ucItem);
}


//----------------------------------------------------------------------------------------------------
#if(_OSD_POSITION_ADJ_CTRL)
// OSD H position
void MOSDHPositionAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MOSDHPositionAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MOSDHPositionAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MOSDHPositionAdjLR(1);        break;
    
        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MOSDHPositionAdjLR(0);        break;
               
        // Other key
        default:             COthterKeyAction();      break;
    }
}

//----------------------------------------------------------------------------------------------------
void MOSDHPositionAdjMenu(void)
{
    ucOsdState = MENU_SUB_H_POSITION;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MOSDHPositionAdjLR(BYTE LR)
{
    SET_KEYREPEATENABLE();
    stOsdUserData.OsdHPos = ValueInRangeChange(0, 100, stOsdUserData.OsdHPos, _NON_LOOP | LR);
    SLIDER1(stOsdUserData.OsdHPos);
#if(_OSD_DISPLAY_SIZE_ADJ)
    if (GET_OSD_SIZE())
        OSDPosition(_MAIN_OSD_DOUBLE_WIDTH, _MAIN_OSD_DOUBLE_HEIGHT, stOsdUserData.OsdHPos, stOsdUserData.OsdVPos, 0x03);
    else
#endif
        OSDPosition(_MAIN_WINDOW_WIDTH,_MAIN_WINDOW_HEIGHT,stOsdUserData.OsdHPos, stOsdUserData.OsdVPos, 0x03);

    ucOsdEventMsg = _SAVE_EE_OSDUSERDATA_MSG;
}

//----------------------------------------------------------------------------------------------------

// OSD V position
void MOSDVPositionAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MOSDVPositionAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MOSDVPositionAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MOSDVPositionAdjLR(1);        break;
    
        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MOSDVPositionAdjLR(0);        break;
                
        // Other key
        default:             COthterKeyAction();           break;
    }
}

//----------------------------------------------------------------------------------------------------
void MOSDVPositionAdjMenu(void)
{
    ucOsdState = MENU_SUB_V_POSITION;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MOSDVPositionAdjLR(BYTE LR)
{
    SET_KEYREPEATENABLE();
    stOsdUserData.OsdVPos = ValueInRangeChange(0, 100, stOsdUserData.OsdVPos, _NON_LOOP | LR);
    SLIDER1(stOsdUserData.OsdVPos);
#if(_OSD_DISPLAY_SIZE_ADJ)
    if (GET_OSD_SIZE())
        OSDPosition(_MAIN_OSD_DOUBLE_WIDTH, _MAIN_OSD_DOUBLE_HEIGHT, stOsdUserData.OsdHPos, stOsdUserData.OsdVPos, 0x03);
    else
#endif
        OSDPosition(_MAIN_WINDOW_WIDTH,_MAIN_WINDOW_HEIGHT,stOsdUserData.OsdHPos, stOsdUserData.OsdVPos, 0x03);

    ucOsdEventMsg = _SAVE_EE_OSDUSERDATA_MSG;
}

#endif
//----------------------------------------------------------------------------------------------------

#if(_OSD_TIMEOUT_ADJ_CTRL)
// OSD timeout
void MOSDTimeoutAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MOSDTimeoutAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MOSDTimeoutAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MOSDTimeoutAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MOSDTimeoutAdjLR(0);        break;
           
        // Other key
        default:             COthterKeyAction();         break;
    }
}

//----------------------------------------------------------------------------------------------------
void MOSDTimeoutAdjMenu(void)
{
    ucOsdState = MENU_SUB_OSD_TIMEOUT;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MOSDTimeoutAdjLR(BYTE LR)
{
    SET_KEYREPEATENABLE();
    CClearMsg(_CLEAR_MSG_ONLY);

    stOsdUserData.OsdTimeout = ValueInRangeChange(4, 30, stOsdUserData.OsdTimeout, _LOOP | LR);

    if (stOsdUserData.OsdTimeout == 4)
    {
        CCenterTextout(sOn_Off[0][GET_LANGUAGE()],ROW(_MESSAGE_V_POSITION),COL(0),30);
    }
    else
    {
        Gotoxy(14, _MESSAGE_V_POSITION, BYTE_DISPLAY);
        CShowNumber1(stOsdUserData.OsdTimeout, 0);
    }

    ucOsdEventMsg = _SAVE_EE_OSDUSERDATA_MSG;
}

#endif
//----------------------------------------------------------------------------------------------------

#if(_ALPHA_BLENDING_ADJ)
// OSD Translucent sub item
void MOSDTranslucentAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MOSDTranslucentAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MOSDTranslucentAdjMenu();       break;


        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MOSDTranslucentAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MOSDTranslucentAdjLR(0);        break;
            
        // Other key
        default:             COthterKeyAction();             break;
    }
}

//----------------------------------------------------------------------------------------------------
void MOSDTranslucentAdjMenu(void)
{
    ucOsdState = MENU_SUB_OSD_TRANSLUCENT;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MOSDTranslucentAdjLR(BYTE LR)
{
    BYTE ucTemp = GET_OSDBLENDING();

    CClearMsg(_CLEAR_MSG_ONLY);

    ucTemp = ValueInRangeChange(0, 7, ucTemp, _LOOP | LR);

    SET_OSDBLENDING(ucTemp);
	CScalerSetBit(_OVERLAY_CTRL_6C, 0x23, ((stOsdUserData.OsdBlending & 0x07) << 2));
    
    if (ucTemp == 0)
    {
        CCenterTextout(sOn_Off[0][GET_LANGUAGE()],ROW(_MESSAGE_V_POSITION),COL(0),30);
    }
    else
    {
        Gotoxy(14, _MESSAGE_V_POSITION, BYTE_DISPLAY);
        CShowNumber1(ucTemp, 0);
    }

    ucOsdEventMsg = _SAVE_EE_OSDUSERDATA_MSG;
}

#endif

#if(_OSD_DISPLAY_SIZE_ADJ)
//--------- OSD Size proc ----------------------------------
void MOSDSizeAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MOSDSizeAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MOSDSizeAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MOSDSizeAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MOSDSizeAdjLR(0);        break;
            
        // Other key
        default:             COthterKeyAction();      break;
    }
}

//----------------------------------------------------------------------------------------------------
void MOSDSizeAdjMenu(void)
{
    ucOsdState = MENU_SUB_OSD_SIZE;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MOSDSizeAdjLR(BYTE LR)
{   
    CClearMsg(_CLEAR_MSG_ONLY);
        
    LR = (GET_OSD_SIZE()) ? 0 : 1;
    SET_OSD_SIZE(LR);

    COsdFxDisableOsd();
    if (GET_OSD_SIZE())
    {
        SetOSDDouble(0x03 | OSD_WINDOWCHAR_BLENDING);
        OSDPosition(_MAIN_OSD_DOUBLE_WIDTH, _MAIN_OSD_DOUBLE_HEIGHT, stOsdUserData.OsdHPos, stOsdUserData.OsdVPos, 0x03);
    }
    else
    {
        SetOSDDouble(OSD_WINDOWCHAR_BLENDING);
        OSDPosition(_MAIN_WINDOW_WIDTH,_MAIN_WINDOW_HEIGHT,stOsdUserData.OsdHPos, stOsdUserData.OsdVPos, 0x03);
    }
    COsdFxEnableOsd();

    CCenterTextout(sOn_Off[LR][GET_LANGUAGE()], _MESSAGE_V_POSITION, 0, 30);

    ucOsdEventMsg = _SAVE_EE_SYSTEMDATA_MSG;
}

#endif

//----------------------------------------------------------------------------------------------------
//   Sound Sub item
void MSoundSubItemProc(void)
{
    switch(ucKeyMessage)
    {
        // Select item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
        case VK_F_RIGHT:
        //    MSoundSubItemMenu();
          //  break;
#endif
        case VK_MENU:        MSoundSubItemMenu();               break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
#endif
        case VK_LEFT:        MSoundSubItemLR(1);                break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_DOWN:
#endif
        case VK_RIGHT:       MSoundSubItemLR(0);                break;

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER:       CExitToMainItem(MENU_MAIN_SOUND);  break;
#endif
            
        // Other key
        default:             COthterKeyAction();                break;
    }
}

//----------------------------------------------------------------------------------------------------
void MSoundSubItemMenu(void)
{
    BYTE ucTemp = 0;

    CClearMsg(_CLEAR_AND_SELECT_SUB_ITEM);

    switch(ucOsdState)
    {
        case MENU_SUB_VOLUME:
            ucTemp = stAudioData.Volume;
            ucOsdState = MENU_SUB_VOL_ADJ;     
            break;

        case MENU_SUB_MUTE: 
            CCenterTextout(sOn_Off[(GET_AUDIO_MUTE()) ? 1 : 0][GET_LANGUAGE()], _MESSAGE_V_POSITION, 0, 30);
            ucOsdState = MENU_SUB_MUTE_ADJ;     
            return;  // Not show slider

#if(_SOUND_PROCESSOR == _ENABLE)
        case MENU_SUB_BALANCE:
            ucTemp = stAudioData.Balance;
            ucOsdState = MENU_SUB_BALANCE_ADJ;     
            break;

        case MENU_SUB_BASS:
            ucTemp = stAudioData.Bass;
            ucOsdState = MENU_SUB_BASS_ADJ;     
            break;

        case MENU_SUB_TREBLE:
            ucTemp = stAudioData.Treble;
            ucOsdState = MENU_SUB_TREBLE_ADJ;     
            break;
                     /*
        case MENU_SUB_SRS:
            ucTemp = stAudioData.SRS;
            ucOsdState = MENU_SUB_SRS_ADJ;     
            break;

        case MENU_SUB_BBE:
            ucTemp = stAudioData.BBE;
            ucOsdState = MENU_SUB_BBE_ADJ;     
            break;  */
#endif

        case MENU_SUB_SOUND_CLOSE: 
            CExitToMainItem(MENU_MAIN_SOUND);
            return;
    }

    SLIDER1(ucTemp);
}

//----------------------------------------------------------------------------------------------------
void MSoundSubItemLR(BYTE LR)
{            
#if(_SOUND_PROCESSOR == _DISABLE)
    BYTE ucTemp = 0;

#else

    ucOsdState = ValueInRangeChange(MENU_SUB_VOLUME, MENU_SUB_SOUND_CLOSE, ucOsdState, _LOOP | LR);

#endif
    
#if(_SOUND_PROCESSOR == _DISABLE)
    if(LR)
    {
        switch(ucOsdState)
        {
            case MENU_SUB_VOLUME:      ucOsdState = MENU_SUB_MUTE;        break;

#if(_SOUND_PROCESSOR == _ENABLE)
            case MENU_SUB_MUTE:        ucOsdState = MENU_SUB_BALANCE;     break;
            case MENU_SUB_BALANCE:     ucOsdState = MENU_SUB_BASS;        break;
            case MENU_SUB_BASS:        ucOsdState = MENU_SUB_TREBLE;      break;
            case MENU_SUB_TREBLE:      ucOsdState = MENU_SUB_SRS;         break;
            case MENU_SUB_SRS:         ucOsdState = MENU_SUB_BBE;         break;
            case MENU_SUB_BBE:         ucOsdState = MENU_SUB_SOUND_CLOSE; break;
#else
            case MENU_SUB_MUTE:        ucOsdState = MENU_SUB_SOUND_CLOSE; break;
#endif

            case MENU_SUB_SOUND_CLOSE: ucOsdState = MENU_SUB_VOLUME;      break;
        }
    }
    else
    {
        switch(ucOsdState)
        {
            case MENU_SUB_VOLUME:      ucOsdState = MENU_SUB_SOUND_CLOSE; break;
            case MENU_SUB_MUTE:        ucOsdState = MENU_SUB_VOLUME;      break;

#if(_SOUND_PROCESSOR == _ENABLE)
            case MENU_SUB_BALANCE:     ucOsdState = MENU_SUB_MUTE;        break;
            case MENU_SUB_BASS:        ucOsdState = MENU_SUB_BALANCE;     break;
            case MENU_SUB_TREBLE:      ucOsdState = MENU_SUB_BASS;        break;
            case MENU_SUB_SRS:         ucOsdState = MENU_SUB_TREBLE;      break;
            case MENU_SUB_BBE:         ucOsdState = MENU_SUB_SRS;         break;
            case MENU_SUB_SOUND_CLOSE: ucOsdState = MENU_SUB_BBE;         break;
#else
            case MENU_SUB_SOUND_CLOSE: ucOsdState = MENU_SUB_MUTE;        break;
#endif
        }
    }   
    
    switch(ucOsdState)
    {      
        case MENU_SUB_VOLUME:  
            ucTemp = 0;      
            break;

        case MENU_SUB_MUTE: 
            ucTemp = 1;      
            break;

#if(_SOUND_PROCESSOR == _ENABLE)
        case MENU_SUB_BALANCE:
            ucTemp = 2;      
            break;

        case MENU_SUB_BASS:
            ucTemp = 3;      
            break;

        case MENU_SUB_TREBLE:
            ucTemp = 4;      
            break;

        case MENU_SUB_SRS:
            ucTemp = 5;      
            break;

        case MENU_SUB_BBE:
            ucTemp = 6;      
            break;
#endif

        case MENU_SUB_SOUND_CLOSE:
#if(_SOUND_PROCESSOR == _ENABLE)
            ucTemp = 5;
#else
            ucTemp = 2;
#endif      
            break;
    }
     
    CGotoNextSubItem(ucTemp);

#else
       
    CGotoNextSubItem(ucOsdState - MENU_SUB_VOLUME);

#endif  // end #if(_SOUND_PROCESSOR == _DISABLE) 
}
//----------------------------------------------------------------------------------------------------

#if(_VGA_COLOR_SUPPORT)
void CClearVColorItem(void)
{
    OSDClear(1, 8, 1, 20, 0x00, BYTE_DISPLAY);
    OSDClear(1, 8, 1, 20, 0x8C, BYTE_ATTRIB);
}
//----------------------------------------------------------------------------------------------------

void CShowVColorSubItemWindow(BYTE ucItem)
{
    OSDClear(1, 8, 1, 20, 0x40, BYTE_COLOR);           // Clear item color
    OSDClear((1+ucItem), 1, 1, 20, 0x10, BYTE_COLOR); // Set current sub item character color to white
}
//----------------------------------------------------------------------------------------------------
      
void CShowVColorSelectSubItemWindow(BYTE ucItem)
{
    OSDClear(1, 8, 1, 20, 0x40, BYTE_COLOR);           // Clear item color
    OSDClear((1+ucItem), 1, 1, 20, 0x20, BYTE_COLOR); // Set current sub item character color to red
}       
//----------------------------------------------------------------------------------------------------

void CGotoAdjustVColor(void)
{
    CInitOSDMainFrame();
    SetOSDDouble(0x00 | OSD_WINDOWCHAR_BLENDING);   

#if(_OSD_DISPLAY_SIZE_ADJ)
    if (GET_OSD_SIZE())
        OSDPosition(_VCOLOR_OSD_DOUBLE_WIDTH, _VCOLOR_OSD_DOUBLE_HEIGHT, 5, 90, 0x03);
    else
#endif
        OSDPosition(_VCOLOR_WINDOW_WIDTH, _VCOLOR_WINDOW_HEIGHT, 5, 90, 0x03);

#if(!_OSD_DISPLAY_SIZE_ADJ && !_ALPHA_BLENDING_ADJ)
    pData[0] = 0x40;
    pData[1] = 0x03;
    pData[2] = 0xa0;
    CScalerWrite(_OSD_ADDR_MSB_90,3,pData,_AUTOINC);
#endif

    // Set row height to 22, and col space to 0
    DirectWOSDRam(1, 7, THE_BYTE1, 0xf0); // Row 1 ~ (1+7)

    // Draw window
    COsdFxDrawWindow(XSTART(_VCOLOR_WINDOW_H_POS), YSTART(_VCOLOR_WINDOW_V_POS), XEND(_VCOLOR_WINDOW_WIDTH), YEND(_VCOLOR_WINDOW_HEIGHT), tOSD_MINI_WINDOW_STYLE);  
    CDrawVividColorPage();
    CShowVColorSubItemWindow(GET_SAC_DCC_TYPE());

    COsdFxEnableOsd();
    ucOsdState = MENU_SAC_DCC_TEXT + GET_SAC_DCC_TYPE();
}

//----------------------------------------------------------------------------------------------------
// Vivid color page
//----------------------------------------------------------------------------------------------------
void MVividColorItemProc(void)
{
    switch(ucKeyMessage)
    {
        // Select item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
        case VK_F_RIGHT:
#endif
        case VK_MENU:        MVividColorItemMenu();                   break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
#endif
        case VK_LEFT:        MVividColorItemLR(1);                    break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_DOWN:
#endif
        case VK_RIGHT:       MVividColorItemLR(0);                    break;

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER:       COsdDispOsdTimerEvent();                 break;
#endif
            
        // Other key
        default:             COthterKeyAction();                      break;
    }
}

//----------------------------------------------------------------------------------------------------
void MVividColorItemMenu(void)
{
    BYTE ucTemp = 0;

    switch(ucOsdState)
    {
        case MENU_SAC_DCC_TEXT:               // DCC <Text>
        case MENU_SAC_DCC_MOVIE:              // DCC <Movie>
        case MENU_SAC_DCC_GRAPHIC:            // DCC <Graphic>
        case MENU_SAC_DCC_GAME:               // DCC <Game>
        case MENU_SAC_DCC_NORMAL:             // DCC <Normal>
        case MENU_SAC_DCC_CLOSE:              // DCC <Exit>
            COsdDispOsdTimerEvent();
            break;

        case MENU_SAC_DCC_USER:               // DCC <User>
            CDrawVividColorSubPage();
            ucOsdState = MENU_USER_ITEM_DCC;  
            CShowVColorSubItemWindow(_FIRST_ITEM+2);
            break;
    }
}

//----------------------------------------------------------------------------------------------------
void MVividColorItemLR(BYTE LR)
{
    ucOsdState = ValueInRangeChange(MENU_SAC_DCC_TEXT, MENU_SAC_DCC_CLOSE, ucOsdState, _LOOP | LR);
    
    CShowVColorSubItemWindow(ucOsdState - MENU_SAC_DCC_TEXT);

    switch(ucOsdState)
    {
        case MENU_SAC_DCC_TEXT:        CSetSACMode(_SAC_DCC_TEXT);    break;
        case MENU_SAC_DCC_MOVIE:       CSetSACMode(_SAC_DCC_MOVIE);   break;
        case MENU_SAC_DCC_GRAPHIC:     CSetSACMode(_SAC_DCC_GRAPHIC); break;
        case MENU_SAC_DCC_GAME:        CSetSACMode(_SAC_DCC_GAME);    break;
        case MENU_SAC_DCC_NORMAL:      CSetSACMode(_SAC_DCC_NORMAL);  break;
        case MENU_SAC_DCC_USER:        CSetSACMode(_SAC_DCC_USER);    break;
        case MENU_SAC_DCC_CLOSE:                                      break; // DCC <Exit>
    }

    ucOsdEventMsg = _SAVE_EE_OSDUSERDATA_MSG;
}

//----------------------------------------------------------------------------------------------------
// Vivid color sub page
//----------------------------------------------------------------------------------------------------
void MVividColorSubProc(void)
{
    switch(ucKeyMessage)
    {
        // Select item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
        case VK_F_RIGHT:
#endif
        case VK_MENU:        MVividColorSubMenu();        break; 

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
#endif
        case VK_LEFT:        MVividColorSubLR(1);         break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_DOWN:
#endif
        case VK_RIGHT:       MVividColorSubLR(0);         break;

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER:      
            CDrawVividColorPage();
            ucOsdState = MENU_SAC_DCC_USER;
            CShowVColorSubItemWindow(ucOsdState - MENU_SAC_DCC_TEXT);
#endif
            
        // Other key
        default:             COthterKeyAction();          break;
    }
}

//----------------------------------------------------------------------------------------------------
void MVividColorSubMenu(void)
{
    switch(ucOsdState)
    {
        case MENU_USER_ITEM_DCC:              // Vivid Color <DCC>
            CDrawDCCPage();
            ucOsdState = MENU_DCC_ITEM_TEXT + GET_MZ_DCC_TYPE();
            CShowVColorSubItemWindow(GET_MZ_DCC_TYPE());
            break;

        case MENU_USER_ITEM_ICM:              // Vivid Color <ICM>
            CDrawICMPage();
            ucOsdState = MENU_ICM_ITEM_ON_OFF;
            CShowVColorSubItemWindow(MENU_ICM_ITEM_ON_OFF - MENU_ICM_ITEM_RED);
            break;

        case MENU_USER_ITEM_COLOR:            // Vivid Color <Color>
            CDrawVividSubColorPage();
            ucOsdState = MENU_COLOR_ITEM_BRIGHTNESS;
            CShowVColorSubItemWindow(_FIRST_ITEM);
            break;

        case MENU_USER_ITEM_CLOSE:            // Vivid Color <Exit>
            CDrawVividColorPage();
            ucOsdState = MENU_SAC_DCC_USER;
            CShowVColorSubItemWindow(MENU_SAC_DCC_USER - MENU_SAC_DCC_TEXT);
            break;
    }
}

//----------------------------------------------------------------------------------------------------
void MVividColorSubLR(BYTE LR)
{
    ucOsdState = ValueInRangeChange(MENU_USER_ITEM_DCC, MENU_USER_ITEM_CLOSE, ucOsdState, _LOOP | LR);
       
    CShowVColorSubItemWindow(ucOsdState - MENU_USER_ITEM_DCC + 2);
}

//----------------------------------------------------------------------------------------------------
// DCC page
//----------------------------------------------------------------------------------------------------
void MDCCAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Select item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
        case VK_F_RIGHT:
#endif
        case VK_MENU:        MDCCAdjMenu();                         break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
#endif
        case VK_LEFT:        MDCCAdjLR(1);           break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_DOWN:
#endif
        case VK_RIGHT:       MDCCAdjLR(0);           break;

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER:       
            CDrawVividColorSubPage();
            ucOsdState = MENU_USER_ITEM_DCC;  
            CShowVColorSubItemWindow(_FIRST_ITEM+2);
#endif
            
        // Other key
        default:             COthterKeyAction();     break;
    }
}

//----------------------------------------------------------------------------------------------------
void MDCCAdjMenu(void)
{
    switch(ucOsdState)
    {
        case MENU_DCC_ITEM_TEXT:
        case MENU_DCC_ITEM_MOVIE:
        case MENU_DCC_ITEM_GRAPHIC:
        case MENU_DCC_ITEM_GAME:
        case MENU_DCC_ITEM_NORMAL:
            CDrawVividColorSubPage();
            ucOsdState = MENU_USER_ITEM_DCC;  
            CShowVColorSubItemWindow(_FIRST_ITEM+2);
            break;
    }
}

//----------------------------------------------------------------------------------------------------
void MDCCAdjLR(BYTE LR)
{
    BYTE uctemp =0;

    ucOsdState = ValueInRangeChange(MENU_DCC_ITEM_TEXT, MENU_DCC_ITEM_NORMAL, ucOsdState, _LOOP | LR);
    
    uctemp = ucOsdState - MENU_DCC_ITEM_TEXT;  // DCC type
    SET_MZ_DCC_TYPE(uctemp);

    if(uctemp < _MZ_DCC_NORMAL)
    {
        CAdjustFillDCCTable(tDCC_CONTROL[GET_MZ_DCC_TYPE()], tDCC_USERCURVE[GET_MZ_DCC_TYPE()]);
        CScalerSetBit(_DCC_CTRL0_E4, ~_BIT7, _BIT7);
    }
    else if(uctemp == _MZ_DCC_NORMAL)
    {
        if (GET_MZ_ICM_ON_OFF_TYPE() == _OFF)
           CAdjustDisableHLWindow(); 

        CScalerSetBit(_DCC_CTRL0_E4, ~_BIT7, 0x00);
    }
   
    CShowVColorSubItemWindow(ucOsdState - MENU_DCC_ITEM_TEXT);

    ucOsdEventMsg = _SAVE_EE_OSDUSERDATA_MSG;
}

//----------------------------------------------------------------------------------------------------
// ICM page
//----------------------------------------------------------------------------------------------------
void MICMItemProc(void)
{
    switch(ucKeyMessage)
    {
        // Select item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
        case VK_F_RIGHT:
#endif
        case VK_MENU:        MICMItemMenu();                          break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
#endif
        case VK_LEFT:        MICMItemLR(1);          break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_DOWN:
#endif
        case VK_RIGHT:       MICMItemLR(0);          break;

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER:       
            CDrawVividColorSubPage();
            ucOsdState = MENU_USER_ITEM_ICM;  
            CShowVColorSubItemWindow(3);
#endif
            
        // Other key
        default:             COthterKeyAction();     break;
    }
}

//----------------------------------------------------------------------------------------------------
void MICMItemMenu(void)
{
    BYTE ucHue = 0;
    BYTE ucSat = 0;

    switch(ucOsdState)
    {
        case MENU_ICM_ITEM_RED: 
            ucHue = stOsdUserData.MZICMRedHue;
            ucSat = stOsdUserData.MZICMRedSat;
            ucOsdState = MENU_ICM_SUB_R_HUE;
            break;

        case MENU_ICM_ITEM_GREEN:      
            ucHue = stOsdUserData.MZICMGreenHue;
            ucSat = stOsdUserData.MZICMGreenSat;
            ucOsdState = MENU_ICM_SUB_G_HUE;     
            break;

        case MENU_ICM_ITEM_BLUE:       
            ucHue = stOsdUserData.MZICMBlueHue;
            ucSat = stOsdUserData.MZICMBlueSat;
            ucOsdState = MENU_ICM_SUB_B_HUE;     
            break;
            
        case MENU_ICM_ITEM_YELLOW: 
            ucHue = stOsdUserData.MZICMYellowHue;
            ucSat = stOsdUserData.MZICMYellowSat;
            ucOsdState = MENU_ICM_SUB_Y_HUE;
            break;

        case MENU_ICM_ITEM_CYAN:      
            ucHue = stOsdUserData.MZICMCyanHue;
            ucSat = stOsdUserData.MZICMCyanSat;
            ucOsdState = MENU_ICM_SUB_C_HUE;     
            break;

        case MENU_ICM_ITEM_MAGENTA:       
            ucHue = stOsdUserData.MZICMMagentaHue;
            ucSat = stOsdUserData.MZICMMagentaSat;
            ucOsdState = MENU_ICM_SUB_M_HUE;     
            break;
            
        case MENU_ICM_ITEM_ON_OFF:
            if (GET_MZ_ICM_ON_OFF_TYPE())  // ICM on
            {
                SET_MZ_ICM_ON_OFF_TYPE(_OFF);
                CScalerSetBit(_ICM_CTRL_E0, ~_BIT7, 0x00);
            }
            else
            {
                SET_MZ_ICM_ON_OFF_TYPE(_ON);
                CScalerSetBit(_ICM_CTRL_E0, ~_BIT7, _BIT7);
            }
			CCenterTextout(sOn_Off[GET_MZ_ICM_ON_OFF_TYPE()][GET_LANGUAGE()],ROW(7),COL(0),30);
            OutputChar(0x00);
            ucOsdEventMsg = _SAVE_EE_OSDUSERDATA_MSG;
            return;

        case MENU_ICM_ITEM_CLOSE:
            CDrawVividColorSubPage();
            ucOsdState = MENU_USER_ITEM_ICM;  
            CShowVColorSubItemWindow(3);
            return;
    }

    CDrawICMColorAdjPage();
    CShowVColorSubItemWindow(_FIRST_ITEM+1);

    Gotoxy(12,2,BYTE_DISPLAY);         
    CShowNumber(ucHue, 0);
    Gotoxy(12,4,BYTE_DISPLAY);         
    CShowNumber(ucSat, 0);
}

//----------------------------------------------------------------------------------------------------
void MICMItemLR(BYTE LR)
{
    if (GET_MZ_ICM_ON_OFF_TYPE() == _OFF && (ucOsdState == MENU_ICM_ITEM_ON_OFF || ucOsdState == MENU_ICM_ITEM_CLOSE))
    {
        ucOsdState = (ucOsdState == MENU_ICM_ITEM_ON_OFF) ? MENU_ICM_ITEM_CLOSE : MENU_ICM_ITEM_ON_OFF;
    }
    else
        ucOsdState = ValueInRangeChange(MENU_ICM_ITEM_RED, MENU_ICM_ITEM_CLOSE, ucOsdState, _LOOP | LR);

      
    CShowVColorSubItemWindow(ucOsdState - MENU_ICM_ITEM_RED);
}

//----------------------------------------------------------------------------------------------------
// ICM R/G/B item page
//----------------------------------------------------------------------------------------------------
void MICMSubRGBItemAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Select item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
        case VK_F_RIGHT:
#endif
        case VK_MENU:        MICMSubRGBItemAdjMenu();     break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
#endif
        case VK_LEFT:        MICMSubRGBItemAdjLR(1);      break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_DOWN:
#endif
        case VK_RIGHT:       MICMSubRGBItemAdjLR(0);      break;

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER:       
            switch(ucOsdState)
            {
                //-------------  Red --------------
                case MENU_ICM_SUB_R_HUE:
                case MENU_ICM_SUB_R_SAT:
                case MENU_ICM_SUB_R_CLOSE:
                    CExitToICMPage(MENU_ICM_ITEM_RED);
                    break;
        
                //------------- Green -------------
                case MENU_ICM_SUB_G_HUE:
                case MENU_ICM_SUB_G_SAT:
                case MENU_ICM_SUB_G_CLOSE:
                    CExitToICMPage(MENU_ICM_ITEM_GREEN);
                    break;
        
                //-------------- Blue -------------
                case MENU_ICM_SUB_B_HUE:
                case MENU_ICM_SUB_B_SAT:
                case MENU_ICM_SUB_B_CLOSE:
                    CExitToICMPage(MENU_ICM_ITEM_BLUE);
                    break;

                //------------ Yellow -------------
                case MENU_ICM_SUB_Y_HUE:
                case MENU_ICM_SUB_Y_SAT:
                case MENU_ICM_SUB_Y_CLOSE:
                    CExitToICMPage(MENU_ICM_ITEM_YELLOW);
                    break;
        
                //-------------_ Cyan -------------
                case MENU_ICM_SUB_C_HUE:
                case MENU_ICM_SUB_C_SAT:
                case MENU_ICM_SUB_C_CLOSE:
                    CExitToICMPage(MENU_ICM_ITEM_CYAN);
                    break;
        
                //------------ Magenta ------------
                case MENU_ICM_SUB_M_HUE:
                case MENU_ICM_SUB_M_SAT:
                case MENU_ICM_SUB_M_CLOSE:
                    CExitToICMPage(MENU_ICM_ITEM_MAGENTA);
                    break;
            }
#endif
            
        // Other key
        default:             COthterKeyAction();          break;
    }
}

//----------------------------------------------------------------------------------------------------
void CExitToICMPage(const BYTE ucExitToItem)
{
    CDrawICMPage();
    ucOsdState = ucExitToItem;
    CShowVColorSubItemWindow(ucOsdState - MENU_ICM_ITEM_RED);
}

void MICMSubRGBItemAdjMenu(void)
{
    BYTE ucTemp       = 0;

    switch(ucOsdState)
    {
        //-------------  Red --------------------
        case MENU_ICM_SUB_R_HUE:
            ucOsdState   = MENU_ICM_R_HUE_ADJ;
            ucTemp       = 1;
            break;

        case MENU_ICM_SUB_R_SAT:
            ucOsdState   = MENU_ICM_R_SAT_ADJ;
            ucTemp       = 3;
            break;

        case MENU_ICM_SUB_R_CLOSE:
            CExitToICMPage(MENU_ICM_ITEM_RED);
            return;

        //------------- Green -------------
        case MENU_ICM_SUB_G_HUE:
            ucOsdState   = MENU_ICM_G_HUE_ADJ;
            ucTemp       = 1;
            break;

        case MENU_ICM_SUB_G_SAT:
            ucOsdState   = MENU_ICM_G_SAT_ADJ;
            ucTemp       = 3;
            break;

        case MENU_ICM_SUB_G_CLOSE:
            CExitToICMPage(MENU_ICM_ITEM_GREEN);
            return;

        //-------------- Blue ---------------
        case MENU_ICM_SUB_B_HUE:
            ucOsdState   = MENU_ICM_B_HUE_ADJ;
            ucTemp       = 1;
            break;

        case MENU_ICM_SUB_B_SAT:
            ucOsdState   = MENU_ICM_B_SAT_ADJ;
            ucTemp       = 3;
            break;

        case MENU_ICM_SUB_B_CLOSE:
            CExitToICMPage(MENU_ICM_ITEM_BLUE);
            return;

        //------------- Yellow ---------------
        case MENU_ICM_SUB_Y_HUE:
            ucOsdState   = MENU_ICM_Y_HUE_ADJ;
            ucTemp       = 1;
            break;

        case MENU_ICM_SUB_Y_SAT:
            ucOsdState   = MENU_ICM_Y_SAT_ADJ;
            ucTemp       = 3;
            break;

        case MENU_ICM_SUB_Y_CLOSE:
            CExitToICMPage(MENU_ICM_ITEM_YELLOW);
            return;

        //-------------- Cyan ---------------
        case MENU_ICM_SUB_C_HUE:
            ucOsdState   = MENU_ICM_C_HUE_ADJ;
            ucTemp       = 1;
            break;

        case MENU_ICM_SUB_C_SAT:
            ucOsdState   = MENU_ICM_C_SAT_ADJ;
            ucTemp       = 3;
            break;

        case MENU_ICM_SUB_C_CLOSE:
            CExitToICMPage(MENU_ICM_ITEM_CYAN);
            return;

        //------------- Magenta --------------
        case MENU_ICM_SUB_M_HUE:
            ucOsdState   = MENU_ICM_M_HUE_ADJ;
            ucTemp       = 1;
            break;

        case MENU_ICM_SUB_M_SAT:
            ucOsdState   = MENU_ICM_M_SAT_ADJ;
            ucTemp       = 3;
            break;

        case MENU_ICM_SUB_M_CLOSE:
            CExitToICMPage(MENU_ICM_ITEM_MAGENTA);
            return;
    }

    CShowVColorSelectSubItemWindow(ucTemp); 
}

//----------------------------------------------------------------------------------------------------
void MICMSubRGBItemAdjLR(BYTE LR)
{
    BYTE ucTemp = 0;

    if(LR)
    {
        switch(ucOsdState)
        {
            case MENU_ICM_SUB_R_HUE:           ucOsdState = MENU_ICM_SUB_R_SAT;     break;
            case MENU_ICM_SUB_R_SAT:           ucOsdState = MENU_ICM_SUB_R_CLOSE;   break;
            case MENU_ICM_SUB_R_CLOSE:         ucOsdState = MENU_ICM_SUB_R_HUE;     break;

            case MENU_ICM_SUB_G_HUE:           ucOsdState = MENU_ICM_SUB_G_SAT;     break;
            case MENU_ICM_SUB_G_SAT:           ucOsdState = MENU_ICM_SUB_G_CLOSE;   break;
            case MENU_ICM_SUB_G_CLOSE:         ucOsdState = MENU_ICM_SUB_G_HUE;     break;

            case MENU_ICM_SUB_B_HUE:           ucOsdState = MENU_ICM_SUB_B_SAT;     break;
            case MENU_ICM_SUB_B_SAT:           ucOsdState = MENU_ICM_SUB_B_CLOSE;   break;
            case MENU_ICM_SUB_B_CLOSE:         ucOsdState = MENU_ICM_SUB_B_HUE;     break;

            case MENU_ICM_SUB_Y_HUE:           ucOsdState = MENU_ICM_SUB_Y_SAT;     break;
            case MENU_ICM_SUB_Y_SAT:           ucOsdState = MENU_ICM_SUB_Y_CLOSE;   break;
            case MENU_ICM_SUB_Y_CLOSE:         ucOsdState = MENU_ICM_SUB_Y_HUE;     break;

            case MENU_ICM_SUB_C_HUE:           ucOsdState = MENU_ICM_SUB_C_SAT;     break;
            case MENU_ICM_SUB_C_SAT:           ucOsdState = MENU_ICM_SUB_C_CLOSE;   break;
            case MENU_ICM_SUB_C_CLOSE:         ucOsdState = MENU_ICM_SUB_C_HUE;     break;

            case MENU_ICM_SUB_M_HUE:           ucOsdState = MENU_ICM_SUB_M_SAT;     break;
            case MENU_ICM_SUB_M_SAT:           ucOsdState = MENU_ICM_SUB_M_CLOSE;   break;
            case MENU_ICM_SUB_M_CLOSE:         ucOsdState = MENU_ICM_SUB_M_HUE;     break;
        }
    }
    else
    {
        switch(ucOsdState)
        {
            case MENU_ICM_SUB_R_HUE:           ucOsdState = MENU_ICM_SUB_R_CLOSE;   break;
            case MENU_ICM_SUB_R_SAT:           ucOsdState = MENU_ICM_SUB_R_HUE;     break;
            case MENU_ICM_SUB_R_CLOSE:         ucOsdState = MENU_ICM_SUB_R_SAT;     break;

            case MENU_ICM_SUB_G_HUE:           ucOsdState = MENU_ICM_SUB_G_CLOSE;   break;
            case MENU_ICM_SUB_G_SAT:           ucOsdState = MENU_ICM_SUB_G_HUE;     break;
            case MENU_ICM_SUB_G_CLOSE:         ucOsdState = MENU_ICM_SUB_G_SAT;     break;

            case MENU_ICM_SUB_B_HUE:           ucOsdState = MENU_ICM_SUB_B_CLOSE;   break;
            case MENU_ICM_SUB_B_SAT:           ucOsdState = MENU_ICM_SUB_B_HUE;     break;
            case MENU_ICM_SUB_B_CLOSE:         ucOsdState = MENU_ICM_SUB_B_SAT;     break;

            case MENU_ICM_SUB_Y_HUE:           ucOsdState = MENU_ICM_SUB_Y_CLOSE;   break;
            case MENU_ICM_SUB_Y_SAT:           ucOsdState = MENU_ICM_SUB_Y_HUE;     break;
            case MENU_ICM_SUB_Y_CLOSE:         ucOsdState = MENU_ICM_SUB_Y_SAT;     break;

            case MENU_ICM_SUB_C_HUE:           ucOsdState = MENU_ICM_SUB_C_CLOSE;   break;
            case MENU_ICM_SUB_C_SAT:           ucOsdState = MENU_ICM_SUB_C_HUE;     break;
            case MENU_ICM_SUB_C_CLOSE:         ucOsdState = MENU_ICM_SUB_C_SAT;     break;

            case MENU_ICM_SUB_M_HUE:           ucOsdState = MENU_ICM_SUB_M_CLOSE;   break;
            case MENU_ICM_SUB_M_SAT:           ucOsdState = MENU_ICM_SUB_M_HUE;     break;
            case MENU_ICM_SUB_M_CLOSE:         ucOsdState = MENU_ICM_SUB_M_SAT;     break;
        }
    }
    
    switch(ucOsdState)
    {      
        case MENU_ICM_SUB_R_HUE:
        case MENU_ICM_SUB_G_HUE:
        case MENU_ICM_SUB_B_HUE:
        case MENU_ICM_SUB_Y_HUE:
        case MENU_ICM_SUB_C_HUE:
        case MENU_ICM_SUB_M_HUE:
            ucTemp = 1;      
            break;

        case MENU_ICM_SUB_R_SAT:
        case MENU_ICM_SUB_G_SAT:
        case MENU_ICM_SUB_B_SAT:
        case MENU_ICM_SUB_Y_SAT:
        case MENU_ICM_SUB_C_SAT:
        case MENU_ICM_SUB_M_SAT:
            ucTemp = 3;      
            break;

        case MENU_ICM_SUB_R_CLOSE:
        case MENU_ICM_SUB_G_CLOSE:
        case MENU_ICM_SUB_B_CLOSE:
        case MENU_ICM_SUB_Y_CLOSE:
        case MENU_ICM_SUB_C_CLOSE:
        case MENU_ICM_SUB_M_CLOSE:
            ucTemp = 5;      
            break;
    }   
    
    CShowVColorSubItemWindow(ucTemp);
}

//----------------------------------------------------------------------------------------------------
// ICM R/G/B color item page
//----------------------------------------------------------------------------------------------------
void MICMSubRGBColorAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MICMSubRGBColorAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MICMSubRGBColorAdjMenu();     break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MICMSubRGBColorAdjLR(1);      break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MICMSubRGBColorAdjLR(0);      break;
            
        // Other key
        default:             COthterKeyAction();           break;
    }
}
//----------------------------------------------------------------------------------------------------

void CExitAdjState(const BYTE ucSubItem, const BYTE ucBarPos)
{
    ucOsdState = ucSubItem;
    CShowVColorSubItemWindow(ucBarPos); 
}
//----------------------------------------------------------------------------------------------------

void MICMSubRGBColorAdjMenu(void)
{
    CLR_KEYREPEATENABLE();

    switch(ucOsdState)
    {
        case MENU_ICM_R_HUE_ADJ:
            CExitAdjState(MENU_ICM_SUB_R_HUE, 1);
            break;

        case MENU_ICM_R_SAT_ADJ:
            CExitAdjState(MENU_ICM_SUB_R_SAT, 3);
            break;

        case MENU_ICM_G_HUE_ADJ:
            CExitAdjState(MENU_ICM_SUB_G_HUE, 1);
            break;

        case MENU_ICM_G_SAT_ADJ:
            CExitAdjState(MENU_ICM_SUB_G_SAT, 3);
            break;

        case MENU_ICM_B_HUE_ADJ:
            CExitAdjState(MENU_ICM_SUB_B_HUE, 1);
            break;

        case MENU_ICM_B_SAT_ADJ:
            CExitAdjState(MENU_ICM_SUB_B_SAT, 3);
            break;

        case MENU_ICM_Y_HUE_ADJ:
            CExitAdjState(MENU_ICM_SUB_Y_HUE, 1);
            break;

        case MENU_ICM_Y_SAT_ADJ:
            CExitAdjState(MENU_ICM_SUB_Y_SAT, 3);
            break;

        case MENU_ICM_C_HUE_ADJ:
            CExitAdjState(MENU_ICM_SUB_C_HUE, 1);
            break;

        case MENU_ICM_C_SAT_ADJ:
            CExitAdjState(MENU_ICM_SUB_C_SAT, 3);
            break;

        case MENU_ICM_M_HUE_ADJ:
            CExitAdjState(MENU_ICM_SUB_M_HUE, 1);
            break;

        case MENU_ICM_M_SAT_ADJ:
            CExitAdjState(MENU_ICM_SUB_M_SAT, 3);
            break;
    }
}
//----------------------------------------------------------------------------------------------------

void MICMSubRGBColorAdjLR(BYTE LR)
{             
    BYTE ucAdjResult = 0;
    BYTE ucAdjMode   = 0;
    BYTE ucShowPos   = 0;

    SET_KEYREPEATENABLE();

    switch(ucOsdState)
    {
    case MENU_ICM_R_HUE_ADJ:
        stOsdUserData.MZICMRedHue = ValueInRangeChange(_MZ_ICM_RED_HUE_MIN, _MZ_ICM_RED_HUE_MAX, stOsdUserData.MZICMRedHue, _NON_LOOP | LR);
        ucAdjMode   = _V_RED;
        ucAdjResult = stOsdUserData.MZICMRedHue;
        break;

    case MENU_ICM_R_SAT_ADJ:
        stOsdUserData.MZICMRedSat = ValueInRangeChange(_MZ_ICM_RED_SAT_MIN, _MZ_ICM_RED_SAT_MAX, stOsdUserData.MZICMRedSat, _NON_LOOP | LR);
        ucAdjMode   = _V_RED;
        ucAdjResult = stOsdUserData.MZICMRedSat;
        ucShowPos   = 1;
        break;

    case MENU_ICM_G_HUE_ADJ:
        stOsdUserData.MZICMGreenHue = ValueInRangeChange(_MZ_ICM_GREEN_HUE_MIN, _MZ_ICM_GREEN_HUE_MAX, stOsdUserData.MZICMGreenHue, _NON_LOOP | LR);
        ucAdjMode   = _V_GREEN;
        ucAdjResult = stOsdUserData.MZICMGreenHue;
        break;

    case MENU_ICM_G_SAT_ADJ:
        stOsdUserData.MZICMGreenSat = ValueInRangeChange(_MZ_ICM_GREEN_SAT_MIN, _MZ_ICM_GREEN_SAT_MAX, stOsdUserData.MZICMGreenSat, _NON_LOOP | LR);
        ucAdjMode   = _V_GREEN;
        ucAdjResult = stOsdUserData.MZICMGreenSat;
        ucShowPos   = 1;
        break;

    case MENU_ICM_B_HUE_ADJ:
        stOsdUserData.MZICMBlueHue = ValueInRangeChange(_MZ_ICM_BLUE_HUE_MIN, _MZ_ICM_BLUE_HUE_MAX, stOsdUserData.MZICMBlueHue, _NON_LOOP | LR);
        ucAdjMode   = _V_BLUE;
        ucAdjResult = stOsdUserData.MZICMBlueHue;
        break;

    case MENU_ICM_B_SAT_ADJ:
        stOsdUserData.MZICMBlueSat = ValueInRangeChange(_MZ_ICM_BLUE_SAT_MIN, _MZ_ICM_BLUE_SAT_MAX, stOsdUserData.MZICMBlueSat, _NON_LOOP | LR);
        ucAdjMode   = _V_BLUE;
        ucAdjResult = stOsdUserData.MZICMBlueSat;
        ucShowPos   = 1;
        break;

    case MENU_ICM_Y_HUE_ADJ:
        stOsdUserData.MZICMYellowHue = ValueInRangeChange(_MZ_ICM_YELLOW_HUE_MIN, _MZ_ICM_YELLOW_HUE_MAX, stOsdUserData.MZICMYellowHue, _NON_LOOP | LR);
        ucAdjMode   = _V_YELLOW;
        ucAdjResult = stOsdUserData.MZICMYellowHue;
        break;

    case MENU_ICM_Y_SAT_ADJ:
        stOsdUserData.MZICMYellowSat = ValueInRangeChange(_MZ_ICM_RED_SAT_MIN, _MZ_ICM_RED_SAT_MAX, stOsdUserData.MZICMYellowSat, _NON_LOOP | LR);
        ucAdjMode   = _V_YELLOW;
        ucAdjResult = stOsdUserData.MZICMYellowSat;
        ucShowPos   = 1;
        break;

    case MENU_ICM_C_HUE_ADJ:
        stOsdUserData.MZICMCyanHue = ValueInRangeChange(_MZ_ICM_CYAN_HUE_MIN, _MZ_ICM_CYAN_HUE_MAX, stOsdUserData.MZICMCyanHue, _NON_LOOP | LR);
        ucAdjMode   = _V_CYAN;
        ucAdjResult = stOsdUserData.MZICMCyanHue;
        break;

    case MENU_ICM_C_SAT_ADJ:
        stOsdUserData.MZICMCyanSat = ValueInRangeChange(_MZ_ICM_CYAN_SAT_MIN, _MZ_ICM_CYAN_SAT_MAX, stOsdUserData.MZICMCyanSat, _NON_LOOP | LR);
        ucAdjMode   = _V_CYAN;
        ucAdjResult = stOsdUserData.MZICMCyanSat;
        ucShowPos   = 1;
        break;

    case MENU_ICM_M_HUE_ADJ:
        stOsdUserData.MZICMMagentaHue = ValueInRangeChange(_MZ_ICM_MAGENTA_HUE_MIN, _MZ_ICM_MAGENTA_HUE_MAX, stOsdUserData.MZICMMagentaHue, _NON_LOOP | LR);
        ucAdjMode   = _V_MAGENTA;
        ucAdjResult = stOsdUserData.MZICMMagentaHue;
        break;

    case MENU_ICM_M_SAT_ADJ:
        stOsdUserData.MZICMMagentaSat = ValueInRangeChange(_MZ_ICM_MAGENTA_SAT_MIN, _MZ_ICM_MAGENTA_SAT_MAX, stOsdUserData.MZICMMagentaSat, _NON_LOOP | LR);
        ucAdjMode   = _V_MAGENTA;
        ucAdjResult = stOsdUserData.MZICMMagentaSat;
        ucShowPos   = 1;
        break;
    } 
 
    CAdjustMZHueSat(ucAdjMode);

    if (0 == ucShowPos)  // Adj HUE
    {
        Gotoxy(12, 2, BYTE_DISPLAY);         
        CShowNumber(ucAdjResult, 0);
        OutputChar(' ');
    }
    else
    {
        Gotoxy(12, 4, BYTE_DISPLAY);         
        CShowNumber(ucAdjResult, 0);
        OutputChar(' ');
    }

    ucOsdEventMsg = _SAVE_EE_OSDUSERDATA_MSG;
}

//----------------------------------------------------------------------------------------------------
// DCC Color adj proc
//----------------------------------------------------------------------------------------------------
void MDCCColorAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Select item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
        case VK_F_RIGHT:
#endif
        case VK_MENU:        MDCCColorAdjMenu();       break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
#endif
        case VK_LEFT:        MDCCColorAdjLR(1);        break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_DOWN:
#endif
        case VK_RIGHT:       MDCCColorAdjLR(0);        break;

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER:
            CDrawVividColorSubPage();
            ucOsdState = MENU_USER_ITEM_COLOR;  
            CShowVColorSubItemWindow(_FIRST_ITEM+4);
            break;
#endif
            
        // Other key
        default:             COthterKeyAction();         break;
    }
}

//----------------------------------------------------------------------------------------------------
void MDCCColorAdjMenu(void)
{
    switch(ucOsdState)
    {      
        case MENU_COLOR_ITEM_BRIGHTNESS:
            ucOsdState = MENU_COLOR_ITEM_BRIGHT_ADJ;
            break;

        case MENU_COLOR_ITEM_CONTRAST:
            ucOsdState = MENU_COLOR_ITEM_CON_ADJ;
            break;

        case MENU_COLOR_ITEM_PEAKING:
            ucOsdState = MENU_COLOR_ITEM_PEAK_ADJ;
            break;

        case MENU_COLOR_ITEM_CLOSE:
            CDrawVividColorSubPage();
            ucOsdState = MENU_USER_ITEM_COLOR;  
            CShowVColorSubItemWindow(_FIRST_ITEM+4);
            return;
    }  

    CShowVColorSelectSubItemWindow((ucOsdState - MENU_COLOR_ITEM_BRIGHT_ADJ)*2);
}

//----------------------------------------------------------------------------------------------------
void MDCCColorAdjLR(BYTE  LR)
{   
    ucOsdState = ValueInRangeChange(MENU_COLOR_ITEM_BRIGHTNESS, MENU_COLOR_ITEM_CLOSE, ucOsdState, LR, 1);

    CShowVColorSubItemWindow((ucOsdState - MENU_COLOR_ITEM_BRIGHTNESS)*2);
}

//----------------------------------------------------------------------------------------------------
// Vivid color bright/contrast adj proc
//----------------------------------------------------------------------------------------------------
void MDCCColorBCAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MDCCColorBCAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MDCCColorBCAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MDCCColorBCAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MDCCColorBCAdjLR(0);        break;
           
        // Other key
        default:             COthterKeyAction();         break;
    }
}

//----------------------------------------------------------------------------------------------------
void MDCCColorBCAdjMenu(void)
{
    CLR_KEYREPEATENABLE();

    switch(ucOsdState)
    {
        case MENU_COLOR_ITEM_BRIGHT_ADJ:   CExitAdjState(MENU_COLOR_ITEM_BRIGHTNESS, 0);  break;
        case MENU_COLOR_ITEM_CON_ADJ:      CExitAdjState(MENU_COLOR_ITEM_CONTRAST, 2);    break;
        case MENU_COLOR_ITEM_PEAK_ADJ:     CExitAdjState(MENU_COLOR_ITEM_PEAKING, 4);     break;
    }
}

//----------------------------------------------------------------------------------------------------
void MDCCColorBCAdjLR(BYTE  LR)
{    
    SET_KEYREPEATENABLE();

    switch(ucOsdState)
    {
        case MENU_COLOR_ITEM_BRIGHT_ADJ:
            stOsdUserData.MZBright = ValueInRangeChange(0, 255, stOsdUserData.MZBright, LR, 0);
            CAdjustHLWindowBrightness(stOsdUserData.MZBright);

            Gotoxy(12, 1, BYTE_DISPLAY);         
            CShowNumber(stOsdUserData.MZBright, 0);
            OutputChar(' ');
            break;

        case MENU_COLOR_ITEM_CON_ADJ:
            stOsdUserData.MZContrast = ValueInRangeChange(0, 255, stOsdUserData.MZContrast, LR, 0);
            CAdjustHLWindowContrast(stOsdUserData.MZContrast);

            Gotoxy(12, 3, BYTE_DISPLAY);         
            CShowNumber(stOsdUserData.MZContrast, 0);
            OutputChar(' ');
            break;

        case MENU_COLOR_ITEM_PEAK_ADJ:
            stOsdUserData.MZPeaking = ValueInRangeChange(_MZ_COLOR_PEAKING_MIN, _MZ_COLOR_PEAKING_MAX, stOsdUserData.MZPeaking, LR, 0);
            CAdjustHLWindowPeaking(stOsdUserData.MZPeaking);

            Gotoxy(12, 5, BYTE_DISPLAY);         
            CShowNumber(stOsdUserData.MZPeaking, 0);
            OutputChar(' ');
            break;
    }      

    ucOsdEventMsg = _SAVE_EE_OSDUSERDATA_MSG;
}

#endif

//----------------------------------------------------------------------------------------------------
//   Other Sub item
void MOtherSubItemProc(void)
{
    switch(ucKeyMessage)
    {
        // Select item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
        case VK_F_RIGHT:
#endif
        case VK_MENU:        MOtherSubItemMenu();               break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
#endif
        case VK_LEFT:        MOtherSubItemLR(1);                break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_DOWN:
#endif
        case VK_RIGHT:       MOtherSubItemLR(0);                break;

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER:       CExitToMainItem(MENU_MAIN_OTHER);  break;
#endif
            
        // Other key
        default:             COthterKeyAction();                break;
    }
}

//----------------------------------------------------------------------------------------------------
void MOtherSubItemMenu(void)
{
    CClearMsg(_CLEAR_MSG_ONLY);
    CSetItemWindowState(_SELECT_SUB_WINDOW, _SELECT_STATE);

    switch(ucOsdState)
    {
        case MENU_SUB_RESET:
            CDoReset();
            if (_SOURCE_VGA == _GET_INPUT_SOURCE())
            {
               // CAutoDoWhiteBalance();
                CAutoDoAutoConfig();
            }

            CSetItemWindowState(_SELECT_SUB_WINDOW, _MOVE_STATE);
            ShowMode();
            break;

#if(_BLUE_BACKGROUND_FUNC == _ENABLE)
        case MENU_SUB_BLUE: 
			CCenterTextout(sOn_Off[_GET_BLUE_BACKGROUND()][GET_LANGUAGE()],ROW(_MESSAGE_V_POSITION),COL(0),30);
            ucOsdState = MENU_BLUE_ADJ;     
            break;
#endif

#if(_SLEEP_FUNC)
        case MENU_SUB_AUTO_POWER:
            {
                BYTE ucTemp = _GET_POWER_DOWN_TIME();
    
                if (0 == ucTemp) // Auto power down time off
        			CCenterTextout(sOn_Off[0][GET_LANGUAGE()],ROW(_MESSAGE_V_POSITION),COL(0),30);
                else
                {
                   Gotoxy(13, _MESSAGE_V_POSITION, BYTE_DISPLAY);
                   CShowNumber1((ucTemp * 15), 0);    
                }
            }
            ucOsdState = MENU_AUTO_POWER_DOWN_ADJ;     
            break;
#endif

#if(_IMAGE_COLOR_MODE)
        case MENU_SUB_COLOR_MODE: 
            CDrawColorModeState(_GET_IMAGE_COLOR_MODE());
            ucOsdState = MENU_COLOR_MODE_ADJ;     
            break;
#endif

#if(_SHARPNESS_ADJ)
        case MENU_SUB_SHARP:
            Gotoxy(13, _MESSAGE_V_POSITION, BYTE_DISPLAY);
#if(_VIDEO_SUPPORT)  // Source video
            if (_GET_INPUT_SOURCE() != _SOURCE_VGA   && 
                _GET_INPUT_SOURCE() != _SOURCE_DVI   && 
                _GET_INPUT_SOURCE() != _SOURCE_YPBPR &&
                _GET_INPUT_SOURCE() != _SOURCE_HDMI)
                CShowNumber1(GET_PEAKING_CORING(), 0);    
            else
#endif   
            CShowNumber1(GET_PEAKING_CORING(), 0);    
            ucOsdState = MENU_SHARP_ADJ;
            break;
#endif

        case MENU_SUB_OTHER_CLOSE:
            CExitToMainItem(MENU_MAIN_OTHER);
            break;
    }
}

//----------------------------------------------------------------------------------------------------
bit bOtherItemSupport(BYTE ucOSDItem)
{
    switch(ucOSDItem)
    {
        case MENU_SUB_RESET:  
        case MENU_SUB_OTHER_CLOSE:
            return 1;

#if(_BLUE_BACKGROUND_FUNC == _ENABLE)
        case MENU_SUB_BLUE: 
            return 1;
#endif

#if(_SLEEP_FUNC)
        case MENU_SUB_AUTO_POWER:
            return 1;
#endif

#if(_IMAGE_COLOR_MODE)
        case MENU_SUB_COLOR_MODE:
            return 1;
#endif

#if(_SHARPNESS_ADJ)
        case MENU_SUB_SHARP:
            return 1;
#endif
    }

    return 0;
}

//----------------------------------------------------------------------------------------------------
void MOtherSubItemLR(BYTE LR)
{
    BYTE ucTemp  = 0;
    BYTE ucItem  = 0;
    
    // Search next item
    while(1)
    {
        ucOsdState = ValueInRangeChange(MENU_SUB_RESET, MENU_SUB_OTHER_CLOSE, ucOsdState, _LOOP | LR);

        if (bOtherItemSupport(ucOsdState))
            break; 
    }

    // Search item position
    ucTemp = MENU_SUB_RESET;
    while(1)
    {
        if (ucOsdState == ucTemp)
           break;

        ucTemp = ValueInRangeChange(MENU_SUB_RESET, MENU_SUB_OTHER_CLOSE,ucTemp, _LOOP | 0x01);

        if (bOtherItemSupport(ucTemp))
           ucItem++;

    }

    CGotoNextSubItem(ucItem);
}

//--------- Color mode proc ----------------------------------
#if(_IMAGE_COLOR_MODE)
void MColorModeAdjProc(void)
{             
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MColorModeAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MColorModeAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MColorModeAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MColorModeAdjLR(0);        break;
           
        // Other key
        default:             COthterKeyAction();        break;
    }
}
//----------------------------------------------------------------------------------------------------
void MColorModeAdjMenu(void)
{
    ucOsdState = MENU_SUB_COLOR_MODE;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MColorModeAdjLR(BYTE LR)
{
    BYTE ucTemp = _GET_IMAGE_COLOR_MODE();

    ucTemp = ValueInRangeChange(0, 5, ucTemp, LR, 1);
    _SET_IMAGE_COLOR_MODE(ucTemp);
    CSetColorMode(ucTemp);

    CClearMsg(_CLEAR_MSG_ONLY);
    CDrawColorModeState(ucTemp);
   
    ucOsdEventMsg = _SAVE_EE_OSDUSERDATA_MSG;
}

//----------------------------------------------------------------------------------------------------
void CDrawColorModeState(BYTE ucColorModeState)
{
    switch(ucColorModeState)
    {
        case 0:
			CCenterTextout(sColorMode0[GET_LANGUAGE()],ROW(_MESSAGE_V_POSITION),COL(0),30);
            break;

        case 1:
			CCenterTextout(sColorMode1[GET_LANGUAGE()],ROW(_MESSAGE_V_POSITION),COL(0),30);
            break;

        case 2:
			CCenterTextout(sColorMode2[GET_LANGUAGE()],ROW(_MESSAGE_V_POSITION),COL(0),30);
            break;

        case 3:
			CCenterTextout(sColorMode3[GET_LANGUAGE()],ROW(_MESSAGE_V_POSITION),COL(0),30);
            break;

        case 4:
			CCenterTextout(sColorMode4[GET_LANGUAGE()],ROW(_MESSAGE_V_POSITION),COL(0),30);
            break;

        case 5:
			CCenterTextout(sColorMode5[GET_LANGUAGE()],ROW(_MESSAGE_V_POSITION),COL(0),30);
            break;
    }
}

//----------------------------------------------------------------------------------------------------
void CSetColorMode(BYTE ucMode)
{
    switch(ucMode)
    {
        case 0:
            break;

        case 1:
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;
    }
}

//----------------------------------------------------------------------------------------------------

#endif

//--------- Sharp adj proc ----------------------------------
#if(_SHARPNESS_ADJ)
void MSharpAdjProc(void)
{             
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MSharpAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MSharpAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MSharpAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MSharpAdjLR(0);        break;
           
        // Other key
        default:             COthterKeyAction();    break;
    }
}
//----------------------------------------------------------------------------------------------------
void MSharpAdjMenu(void)
{
    ucOsdState = MENU_SUB_SHARP;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MSharpAdjLR(BYTE LR)
{
    BYTE ucTemp = GET_PEAKING_CORING(); // Default to VGA sharpness

    ucTemp = ValueInRangeChange(0, 15, ucTemp, _NON_LOOP | LR);

    CClearMsg(_CLEAR_MSG_ONLY);
    Gotoxy(13, _MESSAGE_V_POSITION, BYTE_DISPLAY);  
    CShowNumber1(GET_PEAKING_CORING(), 0); 
   
    SET_PEAKING_CORING(ucTemp);
    ucOsdEventMsg = _SAVE_EE_SYSTEMDATA_MSG;  
    CAdjustPeakingCoding();
}

#endif

//----------------------------------------------------------------------------------------------------
void DrawMuteState(void)
{
    COsdDispOsdTimerEvent();
    SetOsdMap(tUserMenuOsdMap);
    SetOSDDouble(OSD_DOUBLE_HEIGHT_ENABLE | OSD_DOUBLE_WIDTH_ENABLE);
//    SetRowCmds(ROW_COUNT,COL_WIDTH);
    COsdFxCodeWrite(ucCloseAllWindow);
    CClearWindow(0x20);

#if(_OSD_DISPLAY_SIZE_ADJ)
    if (GET_OSD_SIZE())
    {
        OSDPosition(12*10, 18*3, 32, 1, 0x03);
        DirectWOSDRam(0x00, 0x03, THE_BYTE0, 0x80|0x03);  // Row 0~2 character double height and width
    }
    else
#endif
        OSDPosition(30,30,38,1,0x01);

#if(_VIDEO_TV_SUPPORT) 
 #if(_SLEEP_FUNC)
    bTimerOnScreen = 0;
 #endif
#endif

    if (GET_AUDIO_MUTE())
    {
#if(_HARDWARE_LOAD_FONT == _ON)

        CScalerLoadHardwareVLCFont(tFntIconMute, 0x10);

#else

        CScalerLoadFont(tFntIconMute, 0x10, 6, _COMPRESS_FONT);

#endif
        CTimerCancelTimerEvent(COsdDispOsdTimerEvent);
        ucOsdState = MENU_SHOW_MUTE_STATE;
    }
    else
    {
#if(_HARDWARE_LOAD_FONT == _ON)

        CScalerLoadHardwareVLCFont(tFntIconSpker, 0x10);

#else

        CScalerLoadFont(tFntIconSpker, 0x10, 6, _COMPRESS_FONT);

#endif
        ucOsdState = MENU_SHOW_MSG_STATE;
        CTimerReactiveTimerEvent(SEC(5),COsdDispOsdTimerEvent);
    }

    DispIcon(6,0,0x10);   

    COsdFxEnableOsd();
}


//--------- brightness proc ----------------------------------
void MBrightAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MBrightAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MBrightAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MBrightAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MBrightAdjLR(0);        break;
            
        // Other key
        default:             COthterKeyAction();     break;
    }
}

//----------------------------------------------------------------------------------------------------
void MBrightAdjMenu(void)
{
    ucOsdState = MENU_ITEM_BRIGHT;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MBrightAdjLR(BYTE  LR)
{   
    SET_KEYREPEATENABLE();
    BRIGHTNESS_GUAGE = ValueInRangeChange(0, 100, BRIGHTNESS_GUAGE, _NON_LOOP | LR);
    SLIDER1(BRIGHTNESS_GUAGE);
    CAdjustBrightness();
    
    stSystemData.BackLight = BRIGHTNESS_GUAGE;
    CAdjustBacklight();
    CEepromSaveSystemData();
    ucOsdEventMsg = _SAVE_EE_COLORPROC0_MSG;  
}


//--------- CONTRAST ADJUST PROC ----------------------------------
void MContrastAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MContrastAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MContrastAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MContrastAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MContrastAdjLR(0);        break;

        // Other key
        default:             COthterKeyAction();       break;
    }
}

//----------------------------------------------------------------------------------------------------
void MContrastAdjMenu(void)
{
    ucOsdState = MENU_ITEM_CONTRAST;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MContrastAdjLR(BYTE  LR)
{   
    SET_KEYREPEATENABLE();
    CONTRAST_GUAGE = ValueInRangeChange(0, 100, CONTRAST_GUAGE, _NON_LOOP | LR);
    SLIDER1(CONTRAST_GUAGE);
    CAdjustContrast();
    ucOsdEventMsg = _SAVE_EE_COLORPROC0_MSG;     
}

//--------- LANGUAGE ADJUST PROC ----------------------------------
void MLanguageAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MLanguageAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MLanguageAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MLanguageAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MLanguageAdjLR(0);        break;
            
        // Other key
        default:             COthterKeyAction();       break;
    }
}

//----------------------------------------------------------------------------------------------------
void MLanguageAdjMenu(void)
{
    ucOsdState = MENU_SUB_LANGUAGE;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);        
}

//----------------------------------------------------------------------------------------------------
void MLanguageAdjLR(BYTE  LR)
{
    BYTE ucLng = GET_LANGUAGE();
    
    if (LR) 
        ucLng = GetNextLanguage(ucLng);
    else   
        ucLng = GetPrevLanguage(ucLng);
    
    SET_LANGUAGE(ucLng);
    
    // Load Font
    LoadLanguageFont();

    // Redraw
    CClearSubItem();
    CClearMsg(_CLEAR_MSG_ONLY);
    CDrawOSDFuncPage();
    CCenterTextout(sLangName[GET_LANGUAGE()],ROW(_MESSAGE_V_POSITION),COL(0),30);
    ucOsdEventMsg = _SAVE_EE_OSDUSERDATA_MSG;
}


//--------- Volume adjust proc ----------------------------------
void MVolumeAdjProc()
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MVolumeAdjMenu();
            if (ucOsdState == MENU_SUB_VOLUME)
               COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MVolumeAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_IR_VOLINC:
        case VK_LEFT:        MVolumeAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_IR_VOLDEC:
        case VK_RIGHT:       MVolumeAdjLR(0);        break;
            
        // Other key
        default:             COthterKeyAction();     break;
    }
}

//----------------------------------------------------------------------------------------------------
void MVolumeAdjMenu(void)
{
    if (MENU_VOLUME_SP == ucOsdState)
    {
        COsdDispOsdTimerEvent();
//        CTimerDelayXms(100);
  //      ucDetectIR_Cmd = 0;
    }
    else
    {
        ucOsdState = MENU_SUB_VOLUME;
        CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);        
    }
}

//----------------------------------------------------------------------------------------------------
void MVolumeAdjLR(BYTE  LR)
{
    CLR_AUDIO_MUTE();
    SET_KEYREPEATENABLE();
    stAudioData.Volume = ValueInRangeChange(0,100,stAudioData.Volume,_NON_LOOP | LR);

    if (MENU_VOLUME_SP == ucOsdState)
       OSDSlider(3, 1, 10, stAudioData.Volume, 100, 0x40, _SHOW_PERCENT);
    else
       SLIDER1(stAudioData.Volume);
    CSetVolume();
    ucOsdEventMsg = _SAVE_EE_AUDIO_DATA_MSG;
}

//--------- Mute PROC ----------------------------------
void MMuteAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MMuteAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MMuteAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MMuteAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MMuteAdjLR(0);        break;

        // Other key
        default:             COthterKeyAction();   break;
    }
}

//----------------------------------------------------------------------------------------------------
void MMuteAdjMenu(void)
{
    ucOsdState = MENU_SUB_MUTE;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MMuteAdjLR(BYTE LR)
{   
    CClearMsg(_CLEAR_MSG_ONLY);

    LR = LR;//(GET_AUDIO_MUTE()) ? 0 : 1;
       
    if (GET_AUDIO_MUTE()) // Mute on 
        CLR_AUDIO_MUTE();
    else
        SET_AUDIO_MUTE();

    CSetVolume();   
    CCenterTextout(sOn_Off[(GET_AUDIO_MUTE()) ? 1 : 0][GET_LANGUAGE()],ROW(_MESSAGE_V_POSITION),COL(0),30);
    ucOsdEventMsg = _SAVE_EE_AUDIO_DATA_MSG;
}

#if(_SOUND_PROCESSOR == _ENABLE)
//--------- Balance adjust proc ----------------------------------
void MBalanceAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MBalanceAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MBalanceAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MBalanceAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MBalanceAdjLR(0);        break;
            
        // Other key
        default:             COthterKeyAction();      break;
    }
}

//----------------------------------------------------------------------------------------------------
void MBalanceAdjMenu(void)
{
    ucOsdState = MENU_SUB_BALANCE;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);        
}

//----------------------------------------------------------------------------------------------------
void MBalanceAdjLR(BYTE  LR)
{
    SET_KEYREPEATENABLE();
    stAudioData.Balance = ValueInRangeChange(0,100,stAudioData.Balance,_NON_LOOP | LR);
    SLIDER1(stAudioData.Balance);
    CSetAudioProcessor(stAudioData.Balance, stAudioData.Bass, stAudioData.Treble);
    ucOsdEventMsg = _SAVE_EE_AUDIO_DATA_MSG;
}

//--------- Bass adjust proc ----------------------------------
void MBassAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MBassAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MBassAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MBassAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MBassAdjLR(0);        break;

        // Other key
        default:             COthterKeyAction();   break;
    }
}

//----------------------------------------------------------------------------------------------------
void MBassAdjMenu(void)
{
    ucOsdState = MENU_SUB_BASS;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);        
}

//----------------------------------------------------------------------------------------------------
void MBassAdjLR(BYTE  LR)
{
    SET_KEYREPEATENABLE();
    stAudioData.Bass = ValueInRangeChange(0,100,stAudioData.Bass,_NON_LOOP | LR);
    SLIDER1(stAudioData.Bass);
    CSetAudioProcessor(stAudioData.Balance, stAudioData.Bass, stAudioData.Treble);
    ucOsdEventMsg = _SAVE_EE_AUDIO_DATA_MSG;
}


//--------- Treble adjust proc ----------------------------------
void MTrebleAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MTrebleAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MTrebleAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MTrebleAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MTrebleAdjLR(0);        break;

        // Other key
        default:             COthterKeyAction();     break;
    }
}

//----------------------------------------------------------------------------------------------------
void MTrebleAdjMenu(void)
{
    ucOsdState = MENU_SUB_TREBLE;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);        
}

//----------------------------------------------------------------------------------------------------
void MTrebleAdjLR(BYTE  LR)
{
    SET_KEYREPEATENABLE();
    stAudioData.Treble = ValueInRangeChange(0,100,stAudioData.Treble,_NON_LOOP | LR);
    SLIDER1(stAudioData.Treble);
    CSetAudioProcessor(stAudioData.Balance, stAudioData.Bass, stAudioData.Treble);
    ucOsdEventMsg = _SAVE_EE_AUDIO_DATA_MSG;
}

//--------- SRS adjust proc ----------------------------------
void MSRSAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MSRSAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MSRSAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MSRSAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MSRSAdjLR(0);        break;

        // Other key
        default:             COthterKeyAction();  break;
    }
}

//----------------------------------------------------------------------------------------------------
void MSRSAdjMenu(void)
{
//    ucOsdState = MENU_SUB_SRS;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);        
}

//----------------------------------------------------------------------------------------------------
void MSRSAdjLR(BYTE  LR)
{                   LR = LR;
    SET_KEYREPEATENABLE();
//    stAudioData.SRS = ValueInRangeChange(0,100,stAudioData.SRS,_NON_LOOP | LR);
//    SLIDER1(stAudioData.SRS);
    CSetVolume();
    ucOsdEventMsg = _SAVE_EE_AUDIO_DATA_MSG;
}

//--------- BBE adjust proc ----------------------------------
void MBBEAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MBBEAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MBBEAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MBBEAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MBBEAdjLR(0);        break;

        // Other key
        default:             COthterKeyAction();  break;
    }
}

//----------------------------------------------------------------------------------------------------
void MBBEAdjMenu(void)
{
//    ucOsdState = MENU_SUB_BBE;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);        
}

//----------------------------------------------------------------------------------------------------
void MBBEAdjLR(BYTE  LR)
{                LR = LR;
    SET_KEYREPEATENABLE();
//    stAudioData.BBE = ValueInRangeChange(0,100,stAudioData.BBE,_NON_LOOP | LR);
//    SLIDER1(stAudioData.BBE);
    CSetVolume();
    ucOsdEventMsg = _SAVE_EE_AUDIO_DATA_MSG;
}

#endif



#if(_VIDEO_TV_SUPPORT) 
#if(_SLEEP_FUNC)
//--------- AutoPowerDown PROC ----------------------------------
void MAutoPowerDownAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MAutoPowerDownAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MAutoPowerDownAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MAutoPowerDownAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MAutoPowerDownAdjLR(0);        break;

        // Other key
        default:             COthterKeyAction();            break;
    }
}

//----------------------------------------------------------------------------------------------------
void MAutoPowerDownAdjMenu(void)
{
    ucOsdState = MENU_SUB_AUTO_POWER;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MAutoPowerDownAdjLR(BYTE LR)
{
    BYTE ucTemp = _GET_POWER_DOWN_TIME();
    
    CClearMsg(_CLEAR_MSG_ONLY);

    ucTemp = ValueInRangeChange(0, 8, ucTemp, _LOOP | LR);
    
    _SET_POWER_DOWN_TIME(ucTemp);
    
    ucAutoPowerDownTime = ucTemp * 15;
    if (0 == ucAutoPowerDownTime) // Auto power down time off
    {
        ucAutoPowerDownTime = 0xff;
    }
    
    ucMinuteCount       = 0;  // Reset count
    

    if (0 == ucTemp) // Auto power down time off
        CCenterTextout(sOn_Off[0][GET_LANGUAGE()],ROW(_MESSAGE_V_POSITION),COL(0),30);
    else
    {
       Gotoxy(13, _MESSAGE_V_POSITION, BYTE_DISPLAY);
       CShowNumber1((ucTemp * 15), 0);    
    }

    LR = 0;
    ucOsdEventMsg = _SAVE_EE_TV_DATA_MSG;
}

#endif
#endif // #if(_VIDEO_TV_SUPPORT) 

#if(_BLUE_BACKGROUND_FUNC == _ENABLE)
//--------- Blue proc ----------------------------------
void MBlueAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MBlueAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MBlueAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MBlueAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MBlueAdjLR(0);        break;

        // Other key
        default:             COthterKeyAction();   break;
    }
}

//----------------------------------------------------------------------------------------------------
void MBlueAdjMenu(void)
{
    ucOsdState = MENU_SUB_BLUE;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MBlueAdjLR(BYTE LR)
{   
    CClearMsg(_CLEAR_MSG_ONLY);

    LR = _GET_BLUE_BACKGROUND();
    
    LR = 1 - LR;
    
    _SET_BLUE_BACKGROUND(LR);
    ucOsdEventMsg = _SAVE_EE_SYSTEMDATA_MSG;
    CCenterTextout(sOn_Off[LR][GET_LANGUAGE()],ROW(_MESSAGE_V_POSITION),COL(0),30);
}

//----------------------------------------------------------------------------------------------------
#endif


//----------------------------------------------------------------------------------------------------
void GotoAdjustVolume(void)
{ 
    CInitOSDMainFrame();
#if(_HARDWARE_LOAD_FONT == _ON)

        CScalerLoadHardwareVLCFont(tFntIconSpker, 0x10);

#else

    CScalerLoadFont(tFntIconSpker, 0x10, 6, _COMPRESS_FONT);

#endif

#if(_OSD_DISPLAY_SIZE_ADJ)
    if (GET_OSD_SIZE())
        OSDPosition(_VOLUME_OSD_DOUBLE_WIDTH, _VOLUME_OSD_DOUBLE_HEIGHT, 50, 100, 0x03);
    else
#endif
        OSDPosition(_VOLUME_WINDOW_WIDTH, _VOLUME_WINDOW_HEIGHT, 50, 100, 0x03);

#if(!_OSD_DISPLAY_SIZE_ADJ && !_ALPHA_BLENDING_ADJ)
    pData[0] = 0x40;
    pData[1] = 0x03;
    pData[2] = 0xa0;
    CScalerWrite(_OSD_ADDR_MSB_90,3,pData,_AUTOINC);
#endif
    SetOSDDouble((GET_OSD_SIZE() ? 0x03 : 0x00)  | OSD_WINDOWCHAR_BLENDING);   

    // Draw window
    COsdFxDrawWindow(XSTART(_VOLUME_WINDOW_H_POS), YSTART(_VOLUME_WINDOW_V_POS), XEND(_VOLUME_WINDOW_WIDTH), YEND(_VOLUME_WINDOW_HEIGHT), tOSD_MINI_WINDOW_STYLE);

    if (GET_AUDIO_MUTE()) // Current mute on,so set mute off
    {
        CLR_AUDIO_MUTE();
        CSetVolume();
    }

    DispIcon(1, 1, 0x10);
    OSDSlider(3, 1, 10, stAudioData.Volume, 100, 0x40, _SHOW_PERCENT);
    
    
    COsdFxEnableOsd();
    ucOsdState = MENU_VOLUME_SP;
}

//----------------------------------------------------------------------------------------------------
void SSetMuteState(void)
{
    BYTE ucMuteCurrent = GET_AUDIO_MUTE();
    
    
    if (1 == ucMuteCurrent) // Current mute on,so set mute off
    {
        CLR_AUDIO_MUTE();
    }
    else
    {
        SET_AUDIO_MUTE();
    }

    DrawMuteState();
    
    CSetVolume();
}

//----------------------------------------------------------------------------------------------------
#if(0)//_SLEEP_FUNC)
void CShowTimer(void)
{
    BYTE ucCurrentMin = ucAutoPowerDownTime - 1;
    BYTE ucCurrentSec = 59 - (BYTE)(ucMinuteCount/1000);
    
    if (!bTimerOnScreen)
    {
        COsdFxDisableOsd();
        SetOSDRamAddress(ROW_COUNT,COL_WIDTH,FONT_BASE_ADDRESS);
        SetOSDDouble(OSD_DOUBLE_HEIGHT_ENABLE | OSD_DOUBLE_WIDTH_ENABLE);
        SetRowCmds(ROW_COUNT,COL_WIDTH);
        COsdFxCodeWrite(ucCloseAllWindow);
        CClearWindow(0x20);

#if(_OSD_DISPLAY_SIZE_ADJ)
        if (GET_OSD_SIZE())
        {
            OSDPosition(12*10, 18*3, 32, 1, 0x03);
            DirectWOSDRam(0x00, 0x01, THE_BYTE0, 0x80|0x03);  // Row 0 character double height and width
        }
        else
#endif
            OSDPosition(30,30,38,1,0x01);

        COsdFxEnableOsd();
        bTimerOnScreen = 1;
    }
    
    Gotoxy(3,0,BYTE_DISPLAY);         
    CShowNumber(ucAutoPowerDownTime - 1, 2);
    OutputChar(0x3a);  // Show ":"
    CShowNumber(59 - (BYTE)(ucMinuteCount/1000), 2);
    
    
    CTimerReactiveTimerEvent(SEC(stOsdUserData.OsdTimeout),COsdDispOsdTimerEvent);
}
#endif


#if(0)//_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
//----------------------------------------------------------------------------------------------------
void CAudioCtrl(void)
{
    if (_GET_INPUT_SOURCE() != _SOURCE_VIDEO_TV)
        return;
 
  #if(_VIDEO_TV_SUPPORT)
    if (bChangeChannel)
        return;
  #endif

    if (ucAudioState != 0)
        ucAudioState++;

    if (ucAudioState < 250)
        return;

    if (!gmi_CModeLocked())  // TV no signal
        MUTE_ON();
    else
        CSetVolume();

    ucAudioState = 1;
}
#endif

//----------------------------------------------------------------------------------------------------

void HintDialog(void)
{
    CInitOSDMainFrame();
    if(GET_OSD_SIZE())
    {
        SetOSDDouble(0x03 | OSD_WINDOWCHAR_BLENDING);   
        OSDPosition(_HINT_WINDOW_H_END+(Panel[ucPanelSelect]->DHWidth/2) + 40, 
                    _HINT_WINDOW_V_END + (Panel[ucPanelSelect]->DVHeight/2) + 8, 50, 50, 0x03);
    }
    else
    {
        SetOSDDouble(0x00 | OSD_WINDOWCHAR_BLENDING);   
        OSDPosition(_HINT_WINDOW_H_END, _HINT_WINDOW_V_END, 50, 50, 0x03);
    }
  //  SetOSDDouble((GET_OSD_SIZE() ? 0x03 : 0x00)  | OSD_WINDOWCHAR_BLENDING);   
   // OSDPosition(_HINT_WINDOW_H_END, _HINT_WINDOW_V_END, 50, 50, 0x03);

    COsdFxDrawWindow(XSTART(_HINT_WINDOW_H_POS), YSTART(_HINT_WINDOW_V_POS), XEND(_HINT_WINDOW_H_END), YEND(_HINT_WINDOW_V_END), tOSD_MINI_WINDOW_STYLE);

    switch(ucOsdEventMsg)
    {
        case _SHOW_NOSIGNAL_MSG:
            CCenterTextout(sNoSignal[GET_LANGUAGE()],ROW(2),COL(0),20);
            break;

        case _SHOW_NOSUPPORT_MSG:
            CCenterTextout(sNotSupport[GET_LANGUAGE()],ROW(2),COL(0),20);
            break;

        case _SHOW_NOCABLE_MSG:
            CCenterTextout(sNoCable[GET_LANGUAGE()],ROW(2),COL(0),20);
            CTimerCancelTimerEvent(COsdDispOsdTimerEvent);
            break;
    }
   
    COsdFxEnableOsd();    
}
//----------------------------------------------------------------------------------------------------
void CShowCurrentSourceTitle(BYTE ucHpos, BYTE ucVpos)
{
    switch(_GET_INPUT_SOURCE())
    {
        case _SOURCE_VGA:             CTextOutEx(sVGA, ucHpos, ucVpos);             break;
        case _SOURCE_DVI:             CTextOutEx(sDVI, ucHpos, ucVpos);             break;
        case _SOURCE_HDMI:            CTextOutEx(sHDMI, ucHpos, ucVpos);            break;
        case _SOURCE_VIDEO_AV:        CTextOutEx(sVIDEO, ucHpos, ucVpos);           break;
        case _SOURCE_VIDEO_SV:        CTextOutEx(sSVIDEO, ucHpos, ucVpos);          break;
        case _SOURCE_VIDEO_YUV:       CTextOutEx(sYUV, ucHpos, ucVpos);             break;    
        case _SOURCE_VIDEO_TV:        CTextOutEx(sTV, ucHpos, ucVpos);              break;
        case _SOURCE_YPBPR:           CTextOutEx(sYPBPR, ucHpos, ucVpos);           break;
        case _SOURCE_VIDEO_SCART:     CTextOutEx(sSCART, ucHpos, ucVpos);           break;
    }
}

//----------------------------------------------------------------------------------------------------
void OutputDisplaySize()
{
    CShowNumber1(stModeInfo.IHWidth, 0);
    OutputChar(0x00);  // " "
    OutputChar(0x5b);  // "X"
    OutputChar(0x00);  // " "
    CShowNumber1(stModeInfo.IVHeight, 0);
}

//----------------------------------------------------------------------------------------------------
void OutputRefrushRate()
{
    CShowNumber1((stModeInfo.IVFreq/10), 0);
    OutputChar('H');  // " "
    OutputChar('Z');  // " "
}

//----------------------------------------------------------------------------------------------------
void CDisplayCurrentSourceMessage(void)
{
    CInitOSDMainFrame();
    SetOSDDouble(0x03);   

#if(_OSD_DISPLAY_SIZE_ADJ)
    if (GET_OSD_SIZE())
    {
        OSDPosition(12*10, 18*3, 1, 2, 0x03);
        DirectWOSDRam(0x00, 0x01, THE_BYTE0, 0x80|0x03);  // Row 0 character double height and width
    }
    else
#endif
        OSDPosition(12*10, 18*3, 1, 2, 0x03);


    OSDClear(0, 4, 0, 25, 0x20, BYTE_COLOR);  // Set message color to red

    CShowCurrentSourceTitle(0, 0);
    switch(_GET_INPUT_SOURCE())
    {
    case _SOURCE_VGA:
    case _SOURCE_DVI:
    case _SOURCE_HDMI:
        //display display size
        Gotoxy(0, 2, 0x50);
        OutputDisplaySize();
        //display refresh
        Gotoxy(12, 2, 0x50);
        OutputChar('@');          
        OutputChar(0x00);            
        OutputRefrushRate();             
        break; 

#if(_YPBPR_SUPPORT)
    case _SOURCE_YPBPR:
        if (stModeInfo.ModeCurr < _MAX_YPBPR_MODE)
            CCenterTextout(sYPbPrMode[stModeInfo.ModeCurr],ROW(2),COL(0),30);
        break;
#endif

#if(_VIDEO_SUPPORT)
    case _SOURCE_VIDEO_AV:
    case _SOURCE_VIDEO_SV:
    case _SOURCE_VIDEO_YUV:
    case _SOURCE_VIDEO_SCART:
        if(ucVideoType > ZPAL_60)
            CCenterTextout(sPAL,ROW(2),COL(0),30);
        else
            CCenterTextout(sNTSC,ROW(2),COL(0),30);
        break;
#endif

#if(_VIDEO_TV_SUPPORT)
    case _SOURCE_VIDEO_TV:
        Gotoxy(0, 2, BYTE_DISPLAY);         
        CShowNumber1(stTvInfo.CurChn, 0);
        OutputChar(0x00);            
        OutputChar(0x00);            
        Textout(sTVType[ucTVType]);
        break;
#endif
    }

    CTimerReactiveTimerEvent(SEC(5),COsdDispOsdTimerEvent);
    COsdFxEnableOsd();         
#if(_VIDEO_TV_SUPPORT) 
 #if(_SLEEP_FUNC)
    bTimerOnScreen = 0;
 #endif
#endif

    ucOsdState     = MENU_SHOW_MESSAGE_SATAE;
}

//----------------------------------------------------------------------------------------------------
void ShowNote(void)
{       
    CInitOSDMainFrame();
    SetOSDDouble(0x03);   

#if(_OSD_DISPLAY_SIZE_ADJ)
    if (GET_OSD_SIZE())
    {
        OSDPosition(12*10, 18*3, 1, 2, 0x03);
        DirectWOSDRam(0x00, 0x01, THE_BYTE0, 0x80|0x03);  // Row 0 character double height and width
    }
    else
#endif
        OSDPosition(12*10, 18*3, 1, 2, 0x03);

    OSDLine(0, 0, 10, 0x20, BYTE_COLOR);
    CShowCurrentSourceTitle(0, 0);
    
    COsdFxEnableOsd();         
    CTimerReactiveTimerEvent(SEC(10),COsdDispOsdTimerEvent);
             
    CPowerPanelOn();  

    ucOsdState = MENU_SHOW_MSG_STATE;
}
//---------------------------------------------------------------------------------------------------------------------
#endif        //#if(OSD_TYPE == OSD03)
