//----------------------------------------------------------------------------------------------------
// ID Code      : Video.c No.0002
// Update Note  :
//
//----------------------------------------------------------------------------------------------------

#define __VIDEO__

#include "Core\Header\Include.h"

#if(_VIDEO_SUPPORT == _ON)

BYTE ucSearchCount = 0;

/**
 * CVideoInitial
 * initial video source
 * set saturation,hue,backlight,sharpness, only called by CVideoIsExist
 * @param <none>
 * @return {none}
 *
*/
//================================================================================================
/////////////////////////////////////////////////
void CVideoInitial(void)
{       
	CScalerSetBit(_SYNC_CTRL_49, ~(_BIT1 | _BIT0), _BIT0);		// Measure HS/VS source select Video8/Video16
	CScalerCodeW(VideoInit);
	CScalerCodeW(VideoAdcInit);

    gmi_CInitialVDC();
    CScalerPageSelect(_PAGE8); 
    CScalerSetBit(_P8_VIDEO_CTRL1_A1, ~_BIT0, 0x00);  
    CScalerSetBit(_P8_INOUT_CTRL_A4, ~(_BIT1|_BIT4|_BIT5), _BIT4|_BIT5); // Force Only 4:2:2 Format Output for 3580 !!  
	CScalerPageSelect(_PAGE9);		
    CScalerSetBit(_P9_HLOOP_MAXSTATE_C1, ~(_BIT2 | _BIT1 | _BIT0), 0x03);

    CInitInputSource();
    CVideoSoftReset();    
}


//--------------------------------------------------
void CVideoSetVDCConBriCustomer(void)
{
	CVideoSetContrast(GET_CONTRAST());
	#if(_VIDEO_AUTO_WHITE_BLANCE == _ENABLE)
	CVideoSetVDCBrightness(GET_VDC_OFFSET());
	#else
	CVideoSetVDCBrightness(0x88);
	#endif	
}

//--------------------------------------------------
void CSetVideoParameter(void)
{
    CScalerPageSelect(_PAGE6);
    CScalerSetByte(_P6_SPATIAL_CTRL_DB, 0x02);
    //CScalerSetBit(_P6_DCTI_1ST_GAIN_D8, ~(_BIT7), 0);
    
    CScalerPageSelect(_PAGE7);
    CScalerSetBit(_P7_DLTI_DCTI_ENABLE_A1, ~(_BIT6), 0);

    switch (ucVideoType)
	{
		case ZNTSC:
			CScalerCodeW(RTD2610_NTSC_M_ini);
			break;

		case ZPAL_I:
			CScalerCodeW(RTD2610_PAL_I_ini);
			break;

		case ZPAL_M:
			CScalerCodeW(RTD2610_PAL_M_ini);
			break;

		case ZPAL_N:
			CScalerCodeW(RTD2610_PAL_CN_ini);
			break;

		case ZNTSC_443:
			CScalerCodeW(RTD2610_NTSC_443_ini);
			break;

		case ZSECAM:
			CScalerCodeW(RTD2610_SECAM_ini);
			break;

		case ZPAL_60:
			CScalerCodeW(RTD2610_PAL_60_ini);
			break;

		case ZNTSC_50:
			//CScalerCodeW(RTD2610_NTSC_50_ini);
			break;
	}


    CScalerPageSelect(_PAGE8);		
	CScalerRead(_P8_VIDEO_CTRL1_A1, 1, pData, _NON_AUTOINC);
	if(pData[0] & _BIT5)//_GET_INPUT_SOURCE() == _SOURCE_VIDEO_SV)
	{
		CScalerPageSelect(_PAGE8);		
		CScalerSetByte(_P8_YCSEP_CTRL_E0, 0x03); 	// YC Seperate Control:1D			
	}
    CScalerPageSelect(_PAGE8);
    CScalerSetBit(0xA7, ~(_BIT3|_BIT2|_BIT1|_BIT0), _BIT0);
     /*
	if((ucVideoType == ZSECAM )&&(_SOURCE_VIDEO_SV == _GET_INPUT_SOURCE()))
		CScalerSetBit(_P8_OUTPUT_CTRL_A7, 0xf0, 0x08);	//set bit0-3 as 0x8
	else
		CScalerSetBit(_P8_OUTPUT_CTRL_A7, 0xf0, 0x00);	//set bit0-3 as 0x0	
	    */
	if (ucVideoType == ZNTSC_50)
		CScalerSetBit(_P8_YCSEP_CTRL_E0, 0xF8, 0x03);		
    CScalerPageSelect(_PAGE9);
	if (ucVideoType == ZPAL_60)	// willy added for pal 60 only
		CScalerSetBit(_P9_VS_TC_E7, 0xbf, 0x40);	
	else
		CScalerSetBit(_P9_VS_TC_E7, 0xbf, 0x00);	
}

//--------------------------------------------------
// Description  : Disable 2610 output
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CVideoOutputDisable(void)
{
	CScalerPageSelect(_PAGE0);		
	CScalerSetBit(_P0_VADC_SWITCH_AF, ~(_BIT2|_BIT1), 0x00);
}

//--------------------------------------------------
// Description  : Eisable 2610 output
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CVideoOutputEnable(void)
{
}

//--------------------------------------------------
// Description  : Soft Reset 2610
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CVideoSoftReset(void)
{
	CScalerPageSelect(_PAGE8);
	CScalerSetByte(_P8_SOFT_RESET_CF, 0x01); 
	CTimerDelayXms(10);    
	CScalerSetByte(_P8_SOFT_RESET_CF, 0x00);
}

//--------------------------------------------------
// Description  : Set  2610 Saturation
// Input Value  : saturationNone
// Output Value : None
//--------------------------------------------------
void CVideoSetVDCSaturation(BYTE ucValue)
{	
	CScalerPageSelect(_PAGE8);
	#if(1)
	CScalerSetByte(_P8_SATURATION1_AA, ucValue);	  
	#else

	BYTE moderesult;
	WORD temp;
	
	CScalerRead(_P8_MODE_DET_STATUS_D3, 1, &moderesult, _NON_AUTOINC);
    CTimerDelayXms(20);
	moderesult &=0x07;	
	//for PAL sat/1.414
	temp =((WORD)(ucValue*100));	
	if(ucVideoType >= ZPAL_M &&  ucVideoType <= ZPAL_I)
	{		
		ucValue=(temp/141);
	}	
	CScalerSetByte(_P8_SATURATION1_AA,ucValue);	  

#endif
}

//--------------------------------------------------
// Description  : Set  2610 Contrast
// Input Value  : ucValue
// Output Value : None
//--------------------------------------------------
void CVideoSetVDCContrast(BYTE ucValue)
{
	CScalerPageSelect(_PAGE8);
	CScalerSetByte(_P8_CONTRAST1_A8,ucValue);	  
}

//--------------------------------------------------
// Description  : Set  2610 Brightness
// Input Value  : ucValue
// Output Value : None
//--------------------------------------------------
void CVideoSetVDCBrightness(BYTE ucValue)
{
	CScalerPageSelect(_PAGE8);
	CScalerSetByte(_P8_BRIGHTNESS1_A9,ucValue);	  
}

//--------------------------------------------------
#if(_VIDEO_TV_SUPPORT)
void CSetTvColor(BYTE ucColorMode)
{
	if(_GET_INPUT_SOURCE() != _SOURCE_VIDEO_TV)
       return;

    switch(ucColorMode)
    {
    case _TV_NTSC_M:
    case _TV_NTSC_4_BG:
    case _TV_NTSC_4_DK:
    case _TV_NTSC_4_I:
        ucColorMode = 0x00;
        break;

    case _TV_PAL_M:
        ucColorMode = 0x01;
        break;

    case _TV_PAL_BG:
    case _TV_PAL_I:
    case _TV_PAL_DK:
        ucColorMode = 0x06;
        break;

    case _TV_PAL_N:
        ucColorMode = 0x03;
        break;

    case _TV_SECAM_BG:
    case _TV_SECAM_DK:
    case _TV_SECAM_L:
    case _TV_SECAM_LL:
        ucColorMode = 0x07;
        break;
    }

    CScalerPageSelect(_PAGE8);   // TV disable auto mode
    CScalerSetByte(0xD2, ucColorMode); 
}
#endif // #if(_VIDEO_TV_SUPPORT)

//--------------------------------------------------
// Description  : Display video set color process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CSetVideoColor(void)
{
	// Setup color conversion
	CModeSetupColorConversion();
    CEepromLoadColorTempData();
    CEepromLoadBriConData();
    CEepromLoadHueSatData();

    //adjust customer color mode
	#if(_AdjustCustomerColorMode == _ENABLE)
	CAdjustCustomerColorMode();
	#endif
    CAdjustContrast();
    CAdjustBrightness();
    CAdjustBacklight();
	CAdjustPeakingCoding();
	CVideoSetSaturation(GET_SATURATION());
	CVideoSetVDCConBriCustomer();
	stSystemData.Sharpness &= 0xF0;
	CAdjustSharpnessForScaleUp();

    CPowerADCAPLLOff();
    CVideoSetVDCBrightness(0x88);
    CVideoSetVDCContrast(0x90);
	CAccAdjust(GET_DCC_MODE());  // set DCC mode

    if (0)//stDisplayInfo.DHWidth > 700)
    {
    	CTimerWaitForEvent(_EVENT_DEN_STOP);
    	CScalerPageSelect(_PAGE6);
    	if(GET_NOISEREDUTION())
			CScalerSetBit(_P6_SPATIAL_CTRL_DB, ~(_BIT2 |_BIT1), _BIT2 |_BIT1);
    	else
    		CScalerSetBit(_P6_UZD_CTRL1_E4, ~(_BIT3 |_BIT2), 0x00); 	//For 480i/576i SU case,close NR func.
    }
}

#if(_VIDEO_TV_SUPPORT)
//--------------------------------------------------
void CSetTVPanelParameter(void)
{
#if 0//(_PANEL_SELECT == _1280_1024)
	if(ucVideoType > ZPAL_60)
    {   // 50Hz
        CScalerSetBit(_FS_DELAY_FINE_TUNING_43, ~_BIT1, 0x00);
        CScalerSetByte(_IVS2DVS_DELAY_LINES_40, 0x00);
        CScalerSetByte(_IV_DV_DELAY_CLK_ODD_41, 0x3C);
		CScalerSetByte(_IV_DV_DELAY_CLK_EVEN_42, 0x21);

    	CScalerPageSelect(_PAGE1);
    	CScalerSetBit(_P1_EVEN_FIXED_LAST_LINE_CTRL_CA, ~_BIT0, _BIT0);
        CScalerSetBit(_P1_DCLK_FINE_TUNE_OFFSET_MSB_C4, 0xf0, 0x08);
        CScalerSetByte(_P1_DCLK_FINE_TUNE_OFFSET_LSB_C5, 0x17);
        CScalerSetBit(_P1_DCLK_SPREAD_SPECTRUM_C6, ~_BIT2, _BIT2);
    }
	else 
    {   // 60Hz
        CScalerSetBit(_FS_DELAY_FINE_TUNING_43, ~_BIT1, 0x00);
        CScalerSetByte(_IVS2DVS_DELAY_LINES_40, 0x00);
        CScalerSetByte(_IV_DV_DELAY_CLK_ODD_41, 0x27);
		CScalerSetByte(_IV_DV_DELAY_CLK_EVEN_42, 0x0D);

    	CScalerPageSelect(_PAGE1);
    	CScalerSetBit(_P1_EVEN_FIXED_LAST_LINE_CTRL_CA, ~_BIT0, _BIT0);
        CScalerSetBit(_P1_DCLK_FINE_TUNE_OFFSET_MSB_C4, 0xf0, 0x07);
        CScalerSetByte(_P1_DCLK_FINE_TUNE_OFFSET_LSB_C5, 0x2D);
        CScalerSetBit(_P1_DCLK_SPREAD_SPECTRUM_C6, ~_BIT2, _BIT2);
    }
#else

//    #error  Error TV Panel Parameter, add new Parameter in "void CSetTVPanelParameter(void)"

#endif 
}
#endif

/**
 * CVideoDisplaySet
 * Setup VGA display
 * set video display
 * @param <none>
 * @return {none}
 *
*/
//--------------------------------------------------
// Description  : Display video set process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CVideoDisplaySet(void)
{
	BYTE field;                         
    BYTE ucScale = 0;
    WORD iDHTotal;
         
  //  CPowerLightPowerOff();        

    CVideoOutputEnable();
    CScalerCodeW(tVIDEO_TABLE_SET_SCALER);
    //double clk input & Swap V8/V6-C-port MSB to LSB sequence into LSB to MSB
	CScalerSetByte(_IPH_ACT_WID_H_16, 0x8A);
    CSetVideoParameter();
	CVideoSoftReset();
   
	//if(CTimerPollingEventProc(60, CMiscModeMeasurePollingEvent))
	//	CModeMeasureData();

	#if(_VIDEO_TV_SUPPORT)
	if(_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV)
    {

        bTVSignal = _TV_NO_SIGNAL;
        for(field = 0; field < 10; field++)
        {
        	if (gmi_CModeLocked())
            {
                bTVSignal = _TV_IS_SIGNAL;
                break;
            }
            CTimerDelayXms(5);
        }

    	CScalerPageSelect(_PAGE9);		
        CScalerSetByte(_P9_C_LOCK_CONF_B6, (ucVideoType == ZSECAM && bTVSignal == _TV_IS_SIGNAL) ? 0xFB : 0x6B);

        //CSetTvColor(ucTVType);

        // add for tv
        CScalerPageSelect(_PAGE8);  
        CScalerSetByte(0xE1, 0x65); 
        CScalerSetByte(0xE2, 0x00); 
        CScalerSetByte(0xEA, 0x08);	
    }
    else
	#endif
    {
        CScalerPageSelect(_PAGE8);   // Video enable auto mode
        CScalerSetByte(0xD2, 0x80);  
    	//CScalerSetBit(_P8_OUTPUT_CTRL_A7, ~(_BIT0|_BIT1|_BIT2), 0x00);
        CScalerSetByte(0xEA, 0x00);	 //CLOSE the VD C's LOW PASS of FILTER}
    	CScalerPageSelect(_PAGE9);		
        CScalerSetByte(_P9_C_LOCK_CONF_B6, 0x6B);
    }
	
	if(ucVideoType > ZPAL_60)
    {
		field    = _VIDEO_50HZ;
        iDHTotal = Panel[ucPanelSelect]->PalDHTotal;
    }
	else
    {
		field    = _VIDEO_60HZ;
        iDHTotal = Panel[ucPanelSelect]->NtscDHTotal;
    }
          
    stModeInfo.IHTotal      = tVIDEO_TABLE_INPUT_INFO[field][0];
    stModeInfo.IHStartPos   = tVIDEO_TABLE_INPUT_INFO[field][1];
    stModeInfo.IHWidth      = tVIDEO_TABLE_INPUT_INFO[field][2];
    stModeInfo.IVStartPos   = tVIDEO_TABLE_INPUT_INFO[field][3];
    stModeInfo.IVHeight     = tVIDEO_TABLE_INPUT_INFO[field][4];
    stModeInfo.IHFreq       = 157;    // For PAL and NTSC. We can use sync processor to measure the actual value.

    stDisplayInfo.DHWidth   = CCalcPanelWdith();//Panel[ucPanelSelect]->DHWidth;
    stDisplayInfo.DVHeight  = Panel[ucPanelSelect]->DVHeight;
    stDisplayInfo.DVStartPos = Panel[ucPanelSelect]->DVStartPos;
    stDisplayInfo.DHTotal   = iDHTotal;//Panel[ucPanelSelect]->DHTotal;

    // Get scaling information
    ucScale = 0;
    if(stModeInfo.IVHeight < stDisplayInfo.DVHeight)        ucScale |= _BIT0;    // bit 0 : V scale-up
    if(stModeInfo.IVHeight > stDisplayInfo.DVHeight)        ucScale |= _BIT1;    // bit 1 : V scale-down
    if(stModeInfo.IHWidth < stDisplayInfo.DHWidth)          ucScale |= _BIT2;    // bit 2 : H scale-up
    if(stModeInfo.IHWidth > stDisplayInfo.DHWidth)          ucScale |= _BIT3;    // bit 3 : H scale-down
                 
	// Capture window setup
	CModeSetCaptureWindow(ucScale);		//!set capture size
	CModeSetScaling(ucScale);         
	CScalerSetBit(_IPH_ACT_WID_H_16, ~_BIT7, 0x00);//Video8 C-port MSB & LSB Swap(Normal)

	CModeSetDisplay(ucScale);
	// Disable SRGB
	CScalerSetBit(_COLOR_CTRL_62, ~(_BIT2), 0x00);

    CSetVideoColor();

	#if(_DE_INTERLACE_SUPPORT == _ON)
  	#if(_DE_INTERLACE_TEST_OPTION==_ENABLE)	
	if(!bDIstatus)
		CModeDeInterlaceSetting();
	else
    {
		CScalerSetBit(_SCALE_CTRL_32, ~(_BIT7 ), _BIT7);        //video mode compensation enable
		CScalerPageSelect(_PAGE6);
		CScalerSetBit(_P6_ENABLE_BIST_CTRL_A0, ~_BIT3, 0x00);	//Disable De-interlace Mode		
 	}			
  	#else
	CModeDeInterlaceSetting();	
  	#endif		
	#endif

	CAdjustInterlaceIVS2DVSDelay();
	
	pData[0] = CFrameSyncDo();

	if (pData[0] == 2) 
    {
	//	CModeResetMode();
	//	return;
	}

    
	#if(_VIDEO_TV_SUPPORT)
    if(_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV)
    {
        CSetTVPanelParameter();
    }
	#endif

	SET_MODESTABLE();

	CTimerDelayXms(100);
	CModeSetupEtcs(_FUNCTION_DISABLE);
   
    if (ucVideoType == ZNTSC || ucVideoType == ZNTSC_443 || ucVideoType == ZNTSC_50)
    	gmi_CAdjustVDCHue(GET_HUE());
    else
	    gmi_CAdjustVDCHue(50);
                                                          
	if(_GET_INPUT_SOURCE() == _SOURCE_VIDEO_AV && (ucVideoType == ZNTSC_443 || ucVideoType == ZPAL_60))
    {

		CScalerPageSelect(_PAGE9);		
        CScalerSetBit(_P9_HLOOP_MAXSTATE_C1, ~(_BIT2 | _BIT1 | _BIT0), 0x01);
    }
                        /*
    CScalerPageSelect(_PAGE6);
    CScalerSetBit(0xC2, ~(_BIT0), 0);
    CScalerSetByte(0xC3, 0x7F); 
    CScalerSetByte(0xC4, 0x4A);
    CScalerSetByte(0xC5, 0xF6);
    CScalerSetByte(0xC6, 0x00);
    CScalerSetByte(0xC7, 0x80);
    CScalerSetByte(0xC8, 0x80);
    CScalerSetByte(0xC9, 0x00);
    CScalerSetByte(0xCA, 0x0A);
    CScalerSetByte(0xCB, 0x0A);
    CScalerSetByte(0xCC, 0x07);
     
    CScalerPageSelect(_PAGE7);
    CScalerSetBit(0xAA, ~(_BIT0), 0);	 
    CScalerSetByte(0xAB, 0x7E); 		 //PEAKING C0
    CScalerSetByte(0xAC, 0x0B);			 //PEAKING C1
    CScalerSetByte(0xAD, 0x36);			 //PEAKING C2
    CScalerSetByte(0xAE, 0x00);
    CScalerSetByte(0xAF, 0x80);
    CScalerSetByte(0xB0, 0x80);
    CScalerSetByte(0xB1, 0x00);
    CScalerSetByte(0xB2, 0x08);		    //POS RANGE		   //08		   80
    CScalerSetByte(0xB3, 0x80);			//NEG RANGE		   //40
    CScalerSetByte(0xB4, 0x0F);			//CORING		   //0A
     
    CScalerPageSelect(_PAGE8);
    CScalerSetBit(0xA7, ~(_BIT3|_BIT2|_BIT1|_BIT0), _BIT0);
    CScalerSetBit(0xEA, ~(_BIT3|_BIT2|_BIT1|_BIT0), _BIT3|_BIT2|_BIT1|_BIT0);
    CScalerSetByte(0xE2, 0x00);			//70

	CScalerPageSelect(_PAGE6);
    if (ucVideoType == ZNTSC || ucVideoType == ZNTSC_443 || ucVideoType == ZNTSC_50)
    	CScalerSetByte(0xD8, 0x0f);	 //Close  I DOMAIN's DCTI,Open GAIN to 0xOF
    else
    	CScalerSetByte(0xD8, 0x8f);	 //Open  I DOMAIN's DCTI,Open GAIN to 0xOF
	CScalerSetByte(0xC1, 0x00);	 //Close I DOMAIN's PEAKING
	
	CScalerPageSelect(_PAGE7);
	CScalerSetByte(0xA1, 0xC0);	 //Open  D DOMAIN's DCTI, Open GAIN to 0xOF
	CScalerSetByte(0xA3, 0x05);	 //DLTi_Gain
	CScalerSetByte(0xA4, 0x01);	 //DLTi_Gain_Threshold	 0x1e
	CScalerSetByte(0xA5, 0x70);	 //DLTi_Options
	CScalerSetByte(0xA6, 0x0F);	 //Open GAIN to 0xOF

	CScalerPageSelect(_PAGE8);
    if(_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV)
    {	
        CScalerSetByte(0xEA, 0x08);	
        CScalerSetByte(0xA8, 0x85);				//Contrast
        CScalerSetByte(0xA9, 0x76);			   //Brightness
    }
    else
    {
        CScalerSetByte(0xEA, 0x00);	 //CLOSE the VD C's LOW PASS of FILTER}
        CScalerSetByte(0xA8, 0x90);				//Contrast
        CScalerSetByte(0xA9, 0x7b);			   //Brightness	  0x85
    }	
*/   
}

//--------------------------------------------------
//
//      void CSetVideoModeReady(void)
//--------------------------------------------------
void CSetVideoModeReady(void)
{
    gmi_CAdjustVDCHue(50);
	CTimerCancelTimerEvent(CModeNoSignalEvent);
	CTimerCancelTimerEvent(CModeNoCableEvent);
	CTimerCancelTimerEvent(CModeNoSupportEvent);
	CTimerCancelTimerEvent(CModePowerSavingEvent);
	SET_READYFORDISPLAY();
    bShowOSDCurr = (bit)(CScalerGetBit(_OVERLAY_CTRL_6C, _BIT0));
    CScalerSetBit(_OVERLAY_CTRL_6C, ~_BIT0, 0x00);
	CVideoDisplaySet();
#if(_VIDEO_TV_SUPPORT)
    if (_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV)
    {
        TVNoSignalCount = 0;
        TVSignalCount   = 0;
    }
#endif
    CScalerSetBit(_OVERLAY_CTRL_6C, ~_BIT0, bShowOSDCurr);         
    CLR_LIGHTPOWERSTATUS();
    ucSearchCount     = 1;
    ucTVSyncFailCount = 0;
	ucCurrState       = _ACTIVE_STATE;
}
        
/**
 * CVideoProcess
 * The VDC input's state machine.
 * If the input source is throught VDC, it will call this function to
 * process display state. There are 4 states here.
 * @param <none>
 * @return {none}
 *
*/     
//--------------------------------------------------
// Description  : The VDC input's state machine.
// If the input source is throught VDC, it will call this function to
// process display state. There are 4 states here.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CVideoProcess(void)
{
	switch (ucCurrState) 
	{
		case _SEARCH_STATE:	
			if(gmi_CVideoModeChange())
			{
                CSetVideoModeReady();
			} 
			else 
            {
				ucCurrState = _NOSIGNAL_STATE;
                SET_READYFORDISPLAY();
            }
			break;

		case _ACTIVE_STATE:
			if (!gmi_CVideoIsExist())
			{         
			   	CModeResetMode();  
				break;
			}
#if(_VIDEO_TV_SUPPORT)
            bTVSigChange();
#endif

           // CVideoFixedFHFVBug();                       
			if (GET_READYFORDISPLAY() == _TRUE) 
			{
                CPowerPanelOn();
				CLR_READYFORDISPLAY();
                SET_OSD_READYFORDISPLAY();
			}    

            if (ucSearchCount)
                ucSearchCount++;
                                                                                   
#if(_VIDEO_TV_SUPPORT)
  #if (_TV_AFC)
            CTVAFC();
  #endif
#endif               
            if (ucSearchCount < 100)                          
                break;
                  
            ucSearchCount = 0;
			if (GET_LIGHTPOWERSTATUS() == _OFF) 
			{
                CScalerSetBit(_VDISP_CTRL_28, ~(_BIT5), (_BIT3));
				CPowerLightPowerOn();

                if (GET_FIRST_SHOW_NOTE())
                   ucOsdEventMsg = _DO_SHOW_NOTE;
#if(_VIDEO_TV_SUPPORT)
                else if(_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV && bChangeChannel)
                   CShowTVNumber(stTvInfo.CurChn, _SHOW_CH_TV_NUMBER | _SHOW_CH_TV_TYPE); 
#endif
			}
		
			break;

		case _NOSIGNAL_STATE:
			if (GET_READYFORDISPLAY()) 
			{
                CLR_READYFORDISPLAY();
				CModeSetFreeRun();  
                SET_OSD_READYFORDISPLAY();
			}    

            if (gmi_CModeLocked())
			{
                COsdDispOsdTimerEvent();
                ucTVSyncFailCount = 250;
			   	CModeResetMode();
			}
			break;

		case _SLEEP_STATE:
            if (gmi_CModeLocked())
			{      
                ucTVSyncFailCount = 250;
			   	CModeResetMode();
			}
			break;

		default:
			break;
	}
}

//--------------------------------------------------
#if(_VIDEO_TV_SUPPORT)
void bTVSigChange(void)
{
    if(_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV)
    {
        if (gmi_CModeLocked())
        {     
            if (TVNoSignalCount)    TVNoSignalCount--;

            if ((bTVSignal == _TV_NO_SIGNAL) && (TVSignalCount < (_TV_SIGNAL_FAIL+10)))
            {
                TVSignalCount++;
                if (TVSignalCount > _TV_SIGNAL_FAIL)
                {         
                    TVNoSignalCount = 0;
                    TVSignalCount   = 0;
                    bTVSignal       = _TV_IS_SIGNAL;
                	CScalerPageSelect(_PAGE9);		
                    CScalerSetByte(_P9_C_LOCK_CONF_B6, (ucVideoType == ZSECAM && bTVSignal == _TV_IS_SIGNAL) ? 0xFB : 0x6B);
                }
            }
        }
        else
        {
            if (TVSignalCount)    TVSignalCount--;

            if ((bTVSignal == _TV_IS_SIGNAL) && (TVNoSignalCount < (_TV_SIGNAL_FAIL+10)))
            {
                TVNoSignalCount++;
                if (TVNoSignalCount > _TV_SIGNAL_FAIL)
                {
                    TVNoSignalCount = 0;
                    TVSignalCount   = 0;
                    bTVSignal       = _TV_NO_SIGNAL;
                	CScalerPageSelect(_PAGE9);		
                    CScalerSetByte(_P9_C_LOCK_CONF_B6, (ucVideoType == ZSECAM && bTVSignal == _TV_IS_SIGNAL) ? 0xFB : 0x6B);
                }
            } 
        }
    }
}
#endif

#endif  // End of #if(_VIDEO_SUPPORT == _ON)
