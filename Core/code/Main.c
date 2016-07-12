//----------------------------------------------------------------------------------------------------
// Copyright of Realtek SemiConductor Corp.
// Model   : RTD2553V
// Version : V0.00c (08.31.2005)
//
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
// ID Code      : Main.c No.0002
// Update Note  :
//
//----------------------------------------------------------------------------------------------------

#define __MAIN__

#include "Core\Header\Include.h"


/**
 * CMainUserInitial
 * Setting some flags for user when initial
 * @param <none>
 * @return {none}
 *
 */
void CMainUserInitial(void)
{
	// User can make some initial settings at firmware startup
	CLR_PANELPOWERSTATUS();
	CLR_LIGHTPOWERSTATUS();
	CLR_FRAMESYNCSTATUS();
	CLR_POWERSWITCH();
	CLR_FIRST_ADCCLOCK();
    CLR_OSD_READYFORDISPLAY();
	#if(_HDMI_SUPPORT == _ON)
    CLR_HDMIINPUT();
	#endif
	SET_FIRST_LOADFONT();
	#if defined(CONFIG_VBI_ENABLE)
	CLR_OSDVBI_INITIAL();
	#endif
	//SET_SOURCE_AUTOCHANGE();
	CLR_SOURCE_AUTOCHANGE();
	SET_PRE_VGA_CONNECT(bVGACONNECT);
	#if(_TMDS_SUPPORT == _ON)
	#if (_HDMI_SUPPORT == _ON)
	SET_PRE_HDMI_CONNECT(bHDMICONNECT);
	#else
	SET_PRE_DVI_CONNECT(bDVICONNECT);
	#endif
	#endif
	CLR_USE_TRANSITION_RESULT();
    CheckLanguage();
}

/**
 * CMainSystemInitial
 * Initial the system for once when power up
 * @param <none>
 * @return {none}
 *
 */
void CMainSystemInitial(void)
{
	#if(_VIDEO_TV_SUPPORT)
    ucAddrIfPllDM = _ADDR_IfPllDM;
	#endif

    // Initial MCU
	CMcuInitial();
    CMuteOn();

	#if( (_HDCP_SUPPORT == _ON) && _HDMI_HOT_PLUG_OPTION)
   	bHot_Plug = _HOT_PLUG_LOW;
	#endif

    // Initial timer events
	CTimerInitialTimerEvent();

    CPowerLightPowerOff();
    CPowerPanelPowerOff();
 	//CScalerPageSelect(_PAGE0);//eric 20070529
	//CScalerSetByte(_P0_POWER_ON_RESET_F3,_BIT7|_BIT6);		

    // Check eeprom and load eeprom settings
	CEepromStartupCheck();

    _SET_INPUT_SOURCE(_SOURCE_HDMI);
    //SET_POWERSTATUS();

    // Initial scaler settings
	CScalerInitial();

    // Initial key scan status
	CKeyInitial();

    // Initial user settings
	CMainUserInitial();

	#if(_VIDEO_SUPPORT == _ON)
    // Initial video settings
   	CVideoInitial();
	CVideoOutputDisable();
	#else
    CInitInputSource();
	#endif  // End of #if(_VIDEO_SUPPORT == _ON)

	CDdcciInitial();

	#if(_FAST_READ == _ON)
	CMCUSetFlashClk();
	#endif
	 
    CIrdaInitial();
}

/**
 * main
 * main process
 * first system initial, then main loop
 * @param <none>
 * @return {none}
 *
*/
void main(void)
{          
	//bit fTest = 1;
    
	CMainSystemInitial();
    
	bLED1 = _LED_OFF;
	bLED2 = _LED_OFF;

	bHot_Plug = _HOT_PLUG_HI;
	
	//CTimerDelayXms(4000);

	/*while(fTest)
    {
        //bPANELPOWER ^= 1;
        //bLIGHTPOWER ^= 1;

        bLED1 ^= 1;
		bLED2 ^= bLED1;

		CTimerDelayXms(250);
    }*/

    do
	{
		#if(_DEBUG_EN)
		CMiscIspDebugProc();
        #endif

		CTimerHandler();
        CKeyHandler();
		CModeHandler();
		COsdHandler();
	}	

    while(_TRUE);
}

