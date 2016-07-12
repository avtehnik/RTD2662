#include "Core\Header\Include.h"

//__________________________________________________________________________
//
//                         Audio func
//__________________________________________________________________________

#if(AUDIO_TYPE == _AUDIO_PWM)
//==========================================================================
//                          CMuteOn
//==========================================================================
void CMuteOn(void)
{                                    
    // Set Mute
    if(_VOLUME_INV)         CSetPWM(bVOLUME_PWM,0xff);
    else                    CSetPWM(bVOLUME_PWM,0x00);

    bMUTE = _MUTE_ON;
}

//==========================================================================
//                          CMuteOff
//==========================================================================
void CMuteOff(void)
{
    bMUTE = _MUTE_OFF;
}

//==========================================================================
//                               CSetVolume
//==========================================================================
void CSetVolume(void)
{
    WORD iVolume;
                   
    if((GET_VOLUME() == 0) || (GET_AUDIO_MUTE()))
    {
       //  if(_VOLUME_INV)         CSetPWM(bVOLUME_PWM,0xff);
         //else                    CSetPWM(bVOLUME_PWM,0x00);

         CMuteOn();
         return;
    }
                   
    CMuteOff();
                                                            
    iVolume = (WORD)(_MAX_VOLUME - _MIN_VOLUME) * GET_VOLUME() / 100;

    if(_VOLUME_INV)
        iVolume = _MAX_VOLUME - iVolume;
    else
        iVolume = _MIN_VOLUME + iVolume;
      
    CSetPWM(bVOLUME_PWM,iVolume);
}
#endif    // #if(AUDIO_TYPE == _AUDIO_PWM)

#if(AUDIO_TYPE == _AUDIO_SC7313)
//==========================================================================
//                           MUTE_ON
//==========================================================================
void CMuteOn(void)
{
    CSetSc7313Volume(0);
    CSc7313MuteOn();
}

//==========================================================================
//                           CMuteOff
//==========================================================================
void CMuteOff(void)
{
    bMUTE = _MUTE_OFF;
}

//==========================================================================
//                             CSetVolume
//==========================================================================
void CSetVolume(void)
{      
	#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
     if (_SOURCE_VIDEO_TV == _GET_INPUT_SOURCE() && !gmi_CModeLocked() && bFM == 0)
        return;
	#endif

     if((GET_AUDIO_MUTE()) || (GET_VOLUME() == 0))
     {
         CMuteOn();
         return;
     }   
    
     CSetSc7313Volume(GET_VOLUME());
	#if (_SOUND_PROCESSOR)
     CSetAudioProcessor(stAudioData.Balance, stAudioData.Bass, stAudioData.Treble);
	#else
     CSetAudioProcessor(50, 50, 50);
	#endif      
     if (bMUTE)
         CMuteOff();
}

#endif          //#if(AUDIO_TYPE == _AUDIO_SC7313)

//==========================================================================
//                         CInitSoundChannel 
//==========================================================================
void CInitSoundChannel(BYTE ucChannel)
{
	CMuteOn();
	
	switch(ucChannel)
	{
	#if(_VGA_SUPPORT)
		case _SOURCE_VGA:
		#if(AUDIO_TYPE == _AUDIO_SC7313)
		CSelect7313SoundChannel(0x01);
		#elif(AUDIO_TYPE == _AUDIO_PWM)  
		_AUDIO_A = 1;
		_AUDIO_B = 1;
		#endif
		break;
	
		case _SOURCE_YPBPR:
		case _SOURCE_HDMI:
		case _SOURCE_DVI:              
		#if(AUDIO_TYPE == _AUDIO_SC7313)
		CSelect7313SoundChannel(0x01);
		#elif(AUDIO_TYPE == _AUDIO_PWM) 
		_AUDIO_A = 0;
		_AUDIO_B = 1; 
		#endif
		break;
	#endif
	
	#if(_VIDEO_SUPPORT)
		case _SOURCE_VIDEO_AV:       
		#if(AUDIO_TYPE == _AUDIO_SC7313)
		CSelect7313SoundChannel(0x02);
		#elif(AUDIO_TYPE == _AUDIO_PWM) 
		_AUDIO_A = 0;//1;
		_AUDIO_B = 0;
		#endif
		break;
	
		case _SOURCE_VIDEO_SV:        
		#if(AUDIO_TYPE == _AUDIO_SC7313)
		CSelect7313SoundChannel(0x02);
		#elif(AUDIO_TYPE == _AUDIO_PWM) 
		_AUDIO_A = 0;//1;
		_AUDIO_B = 1;
		#endif
		break;
	
	#endif //#if(_VIDEO_SUPPORT)
	
		case _SOURCE_VIDEO_YUV:
		#if(AUDIO_TYPE == _AUDIO_SC7313)
		CSelect7313SoundChannel(0x03);  // Only for PT2314
		#elif(AUDIO_TYPE == _AUDIO_PWM)  
		_AUDIO_A = 0;
		_AUDIO_B = 0;
		#endif
		break;
	
		#if(_VIDEO_TV_SUPPORT)
		case _SOURCE_VIDEO_TV:        
		#if(AUDIO_TYPE == _AUDIO_SC7313)
		CSelect7313SoundChannel(0x00);
		#elif(AUDIO_TYPE == _AUDIO_PWM)  
		_AUDIO_A = 0;
		_AUDIO_B = 0;
		#endif
		break;
		#endif

	}
}


//==========================================================================
//                          CGetCurrSourcePos
//==========================================================================
BYTE CGetCurrSourcePos(void)
{
    if     (_GET_INPUT_SOURCE() == _SOURCE_0_TYPE)   return 0;
    else if(_GET_INPUT_SOURCE() == _SOURCE_1_TYPE)   return 1;
    else if(_GET_INPUT_SOURCE() == _SOURCE_2_TYPE)   return 2;
    else if(_GET_INPUT_SOURCE() == _SOURCE_3_TYPE)   return 3;
    else if(_GET_INPUT_SOURCE() == _SOURCE_4_TYPE)   return 4;
    else if(_GET_INPUT_SOURCE() == _SOURCE_5_TYPE)   return 5;
    else if(_GET_INPUT_SOURCE() == _SOURCE_6_TYPE)   return 6;
    else if(_GET_INPUT_SOURCE() == _SOURCE_7_TYPE)   return 7;
    else if(_GET_INPUT_SOURCE() == _SOURCE_8_TYPE)   return 8;
    else if(_GET_INPUT_SOURCE() == _SOURCE_9_TYPE)   return 9;
    else if(_GET_INPUT_SOURCE() == _SOURCE_10_TYPE)  return 10;

    return _NORMAL_SOURCE;
}

//==========================================================================
//                          CSetCurrSource   
//==========================================================================
void CSetCurrSource(const BYTE ucCurrSource)
{
    switch(ucCurrSource)
    {
    case 0:    _SET_INPUT_SOURCE(_SOURCE_0_TYPE);    break;
    case 1:    _SET_INPUT_SOURCE(_SOURCE_1_TYPE);    break;
    case 2:    _SET_INPUT_SOURCE(_SOURCE_2_TYPE);    break;
    case 3:    _SET_INPUT_SOURCE(_SOURCE_3_TYPE);    break;
    case 4:    _SET_INPUT_SOURCE(_SOURCE_4_TYPE);    break;
    case 5:    _SET_INPUT_SOURCE(_SOURCE_5_TYPE);    break;
    case 6:    _SET_INPUT_SOURCE(_SOURCE_6_TYPE);    break;
    case 7:    _SET_INPUT_SOURCE(_SOURCE_7_TYPE);    break;
    case 8:    _SET_INPUT_SOURCE(_SOURCE_8_TYPE);    break;
    case 9:    _SET_INPUT_SOURCE(_SOURCE_9_TYPE);    break;
    case 10:   _SET_INPUT_SOURCE(_SOURCE_10_TYPE);   break;
    }
}

//==========================================================================
//                           bCurrSourceSupport
//==========================================================================
bit bCurrSourceSupport(const BYTE ucSource)
{
    BYTE ucSourceTemp;

    switch(ucSource)
    {
    case 0:   ucSourceTemp = _SOURCE_0_TYPE;     break;
    case 1:   ucSourceTemp = _SOURCE_1_TYPE;     break;
    case 2:   ucSourceTemp = _SOURCE_2_TYPE;     break;
    case 3:   ucSourceTemp = _SOURCE_3_TYPE;     break;
    case 4:   ucSourceTemp = _SOURCE_4_TYPE;     break;
    case 5:   ucSourceTemp = _SOURCE_5_TYPE;     break;
    case 6:   ucSourceTemp = _SOURCE_6_TYPE;     break;
    case 7:   ucSourceTemp = _SOURCE_7_TYPE;     break;
    case 8:   ucSourceTemp = _SOURCE_8_TYPE;     break;
    case 9:   ucSourceTemp = _SOURCE_9_TYPE;     break;
    case 10:  ucSourceTemp = _SOURCE_10_TYPE;     break;
    }

    switch(ucSourceTemp)
    {
	#if (_VGA_SUPPORT)
    case _SOURCE_VGA:          return 1;
	#endif

	#if (_TMDS_SUPPORT)
    case _SOURCE_DVI:          return 1;
	#endif

	#if (_VIDEO_AV_SUPPORT)
    case _SOURCE_VIDEO_AV:     return 1;
	#endif

	#if (_VIDEO_SV_SUPPORT)
    case _SOURCE_VIDEO_SV:     return 1;
	#endif

	#if (_VIDEO_YUV_SUPPORT)
    case _SOURCE_VIDEO_YUV:    return 1;
	#endif

	#if (_VIDEO_TV_SUPPORT)
    case _SOURCE_VIDEO_TV:     return 0;
	#endif

	#if (_VIDEO_SCART_SUPPORT)
    case _SOURCE_VIDEO_SCART:  return 1;
	#endif

	#if (_HDMI_SUPPORT)
    case _SOURCE_HDMI:         return 1;
	#endif

	#if (_YPBPR_SUPPORT)
    case _SOURCE_YPBPR:        return 1;
	#endif
    }

    return 0;
}

//==========================================================================
//                          bChangeSource
//==========================================================================
bit bChangeSource(void)
{
    bit bSourceSelect = 0;
    BYTE i;

    for (i = (CGetCurrSourcePos() + 1); i < _INPUT_PORT_NUM; i++)
    {
         if (bCurrSourceSupport(i))
         {
             bSourceSelect = 1;
             break;
         }
    }

    if (0 == bSourceSelect)  // Source not change
    {
        for (i = 0; i < CGetCurrSourcePos(); i++)
        {
            if (bCurrSourceSupport(i))
            {
                bSourceSelect = 1;
                break;
            }
         }
    }

    if (bSourceSelect && i != CGetCurrSourcePos())
    {
        CSetCurrSource(i);
        CInitInputSource();
        return 1;
    }

    return 0;
}

//==========================================================================
//                          ChangeSourceHandler
//==========================================================================
void ChangeSourceHandler(void)
{
	#if(_VIDEO_TV_SUPPORT)
	#if(_FM_DEVICE)  
    bFM = 0; // Close FM
	#endif

    if (_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV)
       CAdjustBackgroundColor(0x00, 0x00, (_GET_BLUE_BACKGROUND()) ? 0xFF : 0x00);
    else
	#endif
       CAdjustBackgroundColor(0x00, 0x00, 0x00);

	CScalerSetBit(_VDISP_CTRL_28, 0xff, 0x20);
	CScalerSetBit(_VDISP_CTRL_28, ~(_BIT3), _BIT5);

    if (bChangeSource()) // Change source OK
    {
        if (_SLEEP_STATE == ucCurrState)
            CPowerLVDSOn();
                      
    	// close OSD first to avoid dirty screen.
    	COsdFxDisableOsd();
    	switch(_GET_INPUT_SOURCE())
    	{
    		#if(_VGA_SUPPORT || _YPBPR_SUPPORT)
    		case _SOURCE_VGA:
			case _SOURCE_YPBPR:
    			CScalerSetBit(_IPH_ACT_WID_H_16, ~_BIT5, 0x00);
    			CVideoOutputDisable();
    			break;
			#endif

    		#if((_TMDS_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))			
    		case _SOURCE_DVI:
            case _SOURCE_HDMI:
    			CVideoOutputDisable();
    			break;
    		#endif

			#if(_VIDEO_TV_SUPPORT)
    		case _SOURCE_VIDEO_TV:
                CInitTV();
			#endif

    		#if(_VIDEO_TV_SUPPORT ||_VIDEO_AV_SUPPORT || _VIDEO_SV_SUPPORT)
    		case _SOURCE_VIDEO_AV:
    		case _SOURCE_VIDEO_SV:
    			CVideoOutputEnable();
    			break;
			#endif
    	}
       
    	COsdFxDisableOsd();
        ucOsdEventMsg = _CHANGE_SOURCE_MSG;
/*    
        CModeResetMode();
    	CLR_SOURCE_AUTOCHANGE();
    	CEepromLoadBriConData();
    	CEepromLoadHueSatData();
    	CEepromSaveSystemData();
    	CEepromSaveTvData();*/         
    }
}

//==========================================================================
//                          CInitInputSource
//==========================================================================
void CInitInputSource(void)
{
    switch(_GET_INPUT_SOURCE()) 
    {
	#if(_VGA_SUPPORT)
    case _SOURCE_VGA:
        break;
	#endif

	#if(_VIDEO_AV_SUPPORT)
    case _SOURCE_VIDEO_AV:
        gmi_CSelectInputChannel(_AV_CHANNEL, 0);
        break;
	#endif

	#if(_VIDEO_SV_SUPPORT)
    case _SOURCE_VIDEO_SV:
        gmi_CSelectInputChannel(_SV_CHANNEL, 0);
        break;
	#endif

	#if(_VIDEO_TV_SUPPORT)
    case _SOURCE_VIDEO_TV:
        gmi_CSelectInputChannel(_TV_CHANNEL, 0);
        CInitTV();
        break;
	#endif

	#if(_VIDEO_YUV_SUPPORT)
    case _SOURCE_VIDEO_YUV:
        break;
	#endif

	#if(_VIDEO_SCART_SUPPORT)
    case _SOURCE_VIDEO_SCART:
        break;                  
	#endif 

	#if(_HDMI_SUPPORT == _ON)
    case _SOURCE_HDMI:
        break;
	#endif

	#if(_YPBPR_SUPPORT)
    case _SOURCE_YPBPR:
        break;
	#endif
    }  
    
    CInitSoundChannel(_GET_INPUT_SOURCE());

	#if(_VIDEO_TV_SUPPORT)
	#if(_SLEEP_FUNC)
    _SET_POWER_DOWN_TIME(0);
    ucAutoPowerDownTime = 0xff;
    CEepromSaveTvData();
	#endif
	#endif

	#if( (_DE_INTERLACE_SUPPORT == _ON) && (_DE_INTERLACE_TEST_OPTION==_ENABLE) )
    if (bSourceVideo())
        bDIstatus = 1;
    else
        bDIstatus = 0; 
	#endif
}
