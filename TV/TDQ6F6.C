#include "Core\Header\Include.h"

#if (_TV_CHIP == _TV_TDQ_6F6)


 
//==========================================================================
//                            gmi_CI2CWriteIfPllDM
//==========================================================================
void gmi_CI2CWriteIfPllDM(BYTE ucTvType, const bit bTunerMute, const BYTE ucAFTMode)
{
 //   CSetTVSystem(ucTvType);
    
    if (bTunerMute)
        CMuteOn();
    
    switch(ucTvType)
    {
    case _TV_PAL_M     :    // Sound 4.5M  PAL M
    case _TV_NTSC_M    :    // Sound 4.5M  NTSC M
    case _TV_PAL_N     :    // Sound 4.5M  PAL N 
#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
        CSetPifFreq(ucAFTMode, _OTHER_MODE, _PIF_FREQ, _CARRIER_SELECT);
        CSetSoundFreq(_SIF_4_5_MHZ);
#endif
        break;

    case _TV_NTSC_4_BG :    // Sound 5.5M  NTSC 4/BG
    case _TV_PAL_BG    :    // Sound 5.5M  PAL B/G
    case _TV_SECAM_BG  :    // Sound 5.5M  SECAM B/G
#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
        CSetPifFreq(ucAFTMode, _OTHER_MODE, _PIF_FREQ, _CARRIER_SELECT);
        CSetSoundFreq(_SIF_5_5_MHZ);
#endif
        break;

    default:                // Normal sound
    case _TV_NTSC_4_I  :    // Sound 6.0M  NTSC 4/I
    case _TV_PAL_I     :    // Sound 6.0M  PAL I
#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
        CSetPifFreq(ucAFTMode, _OTHER_MODE, _PIF_FREQ, _CARRIER_SELECT);
        CSetSoundFreq(_SIF_6_0_MHZ);
#endif
        break;

    case _TV_NTSC_4_DK :    // Sound 6.5M  NTSC 4/DK
    case _TV_PAL_DK    :    // Sound 6.5M  PAL D/K
    case _TV_SECAM_DK  :    // Sound 6.5M  SECAM D/K
#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
        CSetPifFreq(ucAFTMode, _OTHER_MODE, _PIF_FREQ, _CARRIER_SELECT);
        CSetSoundFreq(_SIF_6_5_MHZ);
#endif
        break;

    case _TV_SECAM_L   :    // Sound 6.5M  SECAM L
    case _TV_SECAM_LL  :    // Sound 6.5M  Secam L'
#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
        CSetPifFreq(ucAFTMode, _SECAML_MODE, _PIF_FREQ, _CARRIER_SELECT);
        CSetSoundFreq(_SIF_6_5_MHZ);
#endif
        break;

    } // end switch
}

//==========================================================================
//                         gmi_CSetTuner
//==========================================================================
void gmi_CSetTuner(BYTE ucTunerAddress, WORD Freq)
{	
   pData[0] = 6;
   pData[1] = ucTunerAddress;
   ((WORD *)pData)[1] = Freq;
   pData[4] = (bFM) ? 0xCA : 0xC8; // 0xCE 
   
   if((Freq < _VHF_LOW_BAND) || (bFM == 1))  
      pData[5]=0x01;   // VHFLOW   
   else if(Freq < _VHF_HIGH_BAND)   
      pData[5]=0x02;  // VHFHIGH 
   else 
      pData[5]=0x04;  //Band select//UHF 
   
   gmi_CI2CWriteTuner(pData);
}

//==========================================================================
//                         CTvAutoSearch
//==========================================================================
void CTvAutoSearch(void) small
{
    BYTE ucSound = 0;
    BYTE ucPRG        = 0;
    BYTE ucmaxchannel = CloadMaxChannelNumber();
    WORD iFreq        = _MIN_FREQ;
         
    if (bFM) 
    {
       stTvInfo.ucFMCurrCh = 0;
       CFMInit();
       iFreq = _FM_MIN_FREQ;
    }

    // Read color and sound type
    if (0 == ucmaxchannel)
    {
        ucSound  = 0;
        ucTVType = CLoadChannelColorType(0); 
    }
    else
    {
        ucSound  = 0;
        ucTVType = CLoadChannelColorType(stTvInfo.CurChn); 
    }

    // Reset search max tv channel number
    pData[0] = 0; 
    CI2cWrite(_TV_MAX_CHANNEL_EEPROM_ADDR, _MAX_CHANNEL_ADDR, 1, pData);

    stTvInfo.CurChn = 0;
	ucPrevChannel = 0;
    // Save current channel
    CEepromSaveTvData();
//    CEepromSaveVedioColor();    

    gmi_CI2CWriteIfPllDM(ucTVType, _TUNER_MUTE_ON, _TUNNING_MODE);
    CTimerDelayXms(8);
    CShowAutoSerachTotal(ucPRG);   // Show search tv channel number
                    
    CScalerSetBit(_VDISP_CTRL_28, ~_BIT5, 0x00); 

	CScalerPageSelect(_PAGE9);		
    CScalerSetByte(_P9_C_LOCK_CONF_B6, 0x6B);

    while(1)
    {
        if (bFM)
           iFreq = CLockChannel(iFreq, 1);
        else
           iFreq = CLockChannel(iFreq+40, 1);

        if(iFreq < 2)
        {
            ucPRG = (ucPRG == 0) ? 0 : (ucPRG - 1);
            break;
        }
        
        CSaveChannelData(iFreq,ucSound,ucPRG);
        
        ucPRG++;
        if(ucPRG > _MAX_CHANNEL_COUNT)
        {
           ucPRG -= 1;
           break;
        }

        CShowAutoSerachTotal(ucPRG);  // Show search tv channel number

    }  // End while

#if(_FM_DEVICE)
    if (1 == bFM)
    {
        BYTE ucChannelCount = 0;

        ucPRG++;

        for(ucChannelCount = ucPRG; ucChannelCount < _FM_MAX_CHANNEL; ucChannelCount++)
        {
            CSaveChannelFreq((WORD)_FM_MIN_FREQ | 0x8000, ucChannelCount);
        }
    }
    else
#endif
    {
    #if(_CHANGE_CHANNEL_MTD == _CHANGE_CHANNEL_M2)
        {
            BYTE ucChannelCount = 0;
    
            ucPRG++;
    
            for(ucChannelCount = ucPRG; ucChannelCount < _MAX_CHANNEL_COUNT; ucChannelCount++)
            {
                CSaveChannelData((WORD)_MIN_FREQ | 0x8000, ucSound, ucChannelCount);
            }
    
        }
    #endif
    
        // Save search channel number
        pData[0] = ucPRG;
        CI2cWrite(_TV_MAX_CHANNEL_EEPROM_ADDR, _MAX_CHANNEL_ADDR, 1, pData);
    }
    CSetTVChannel(0);


#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
    gmi_CI2CWriteIfPllDM(ucTVType, _TUNER_MUTE_OFF, _NORMAL_MODE); // set tv system
#endif
   // CModeResetTVMode();
#if(_FM_DEVICE)
    if (1 == bFM)
        CSetVolume();
    else
#endif
    ucCurrState = _SEARCH_STATE;
}

//==========================================================================
//bSearchAction:   0 --> Search down
//                 1 --> Search up
//==========================================================================
void CManualSearch(const bit bSearchAction, const BYTE ucCurrentChannel) small
{
    BYTE ucSound           = 0;
    WORD iFreq             = 0;
    WORD ucSatrtSearchFreq = 0;  
   
	CScalerPageSelect(_PAGE9);		
    CScalerSetByte(_P9_C_LOCK_CONF_B6, 0x6B);
    ucSatrtSearchFreq = CLoadChannelFreq(ucCurrentChannel);

#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
    gmi_CI2CWriteIfPllDM(ucTVType, _TUNER_MUTE_ON, _TUNNING_MODE);
    CTimerDelayXms(100);
#endif

    if (ucSatrtSearchFreq > _MAX_FREQ)
        ucSatrtSearchFreq = _MAX_FREQ;
    else if(ucSatrtSearchFreq < _MIN_FREQ)
        ucSatrtSearchFreq = _MIN_FREQ;


    if (bSearchAction)
        iFreq = CLockChannel(ucSatrtSearchFreq + 40, 1);
    else
        iFreq = CLockChannel(ucSatrtSearchFreq - 40, 0);

    if (iFreq > 100)
        CSaveChannelData(iFreq,CLoadChannelSoundType(ucCurrentChannel),ucCurrentChannel);
    CSetTVChannel(ucCurrentChannel);

    CShowAutoSearchSliderInOSD(CLoadChannelFreq(stTvInfo.CurChn));                         

    CTimerDelayXms(50);
    if (gmi_CModeLocked())
        CScalerSetBit(_VDISP_CTRL_28, ~_BIT5, 0x00); 

//	CTimerReactiveTimerEvent(SEC(GET_OSDTIMEOUT()), COsdFxExitEvent);

#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
    gmi_CI2CWriteIfPllDM(ucTVType, _TUNER_MUTE_OFF, _NORMAL_MODE);
#endif
   // CModeResetTVMode();
    ucCurrState = _SEARCH_STATE;
}

//==========================================================================
//  bCLockMode --> 1: lock up         0 : lock down
//==========================================================================
WORD CLockChannel(WORD iStartFreq, const bit bCLockMode) small
{
    BYTE f            = 0;
    BYTE rData        = 0;
    BYTE LowLevel_CH  = 0;
    BYTE count        = 0;
    WORD freq         = 0;
    WORD iStartFreqBase = iStartFreq;
    BYTE ucPattCount  = 0;

    while(1)
    {
        gmi_CSetTuner(_ADDR_TUNER, iStartFreq);

#if(_OSD_TYPE == _OSD002)
        ucPattCount++;
        if (ucPattCount > 50)
        {
            ucPattCount = 0;
            CChangePalette();
        } 
#endif

        if (bCLockMode) // Search up
        {
            if (iStartFreq > (iStartFreqBase + 300))
            {
                if(CKeyStopAutoSearch())
                   return 0;
            }
        }
        else
        {
            if (iStartFreq < (iStartFreqBase - 300))
            {
                if(CKeyStopAutoSearch())
                   return 0;
            }
        } 
                          
        // Show search channel state 
        CShowAutoSearchSliderInOSD((iStartFreq)); 
        if (1 == bFM)
           CTimerDelayXms(50);
        rData = gmi_CReadIfPllDM();

            
        switch(rData & 0x0f)
        {
        case 7:
            if (bCLockMode) // Search up
            {
                f = 1;
                if (!bFM)
                   iStartFreq++;
            }
            else            // Search down
            {
                count++;
                f |= 0x02;
            }
            break;

        case 8:
            if (bCLockMode) // Search up
            {
                count++;
                f |= 0x02;
            }
            else            // Search down
            {
                f = 1;
                if (!bFM)
                    iStartFreq--;
            }
            break; 

        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            f |= 0x0a;
            break; 
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
            f |= 0x10;
            break; 
        case 0:
        case 15:
            f |= 0x04;
            freq = iStartFreq;
            break;
        } 
            
        if (1 == bFM)
        {  
            if(f == 0x0f)  // FM locked
               return freq;
        }
        else
        {
    		if (0x1b==f || 0x1a==f) 
    		{
    			LowLevel_CH++;
                if (0 == freq)
        			freq = iStartFreq;
    		}
    		else
                LowLevel_CH = 0;
    
            if((rData & 0x50) != 0x50)
            {
                f     = 0;
       	        count = 0;
          	  //  i    += 4;    
            }
            else if((f==0x1f || LowLevel_CH>4) && ((count > 3 && bCLockMode) || (count > 0 && !bCLockMode)) )
            {
                gmi_CSetTuner(_ADDR_TUNER, freq);
    			CTimerDelayXms(200);
                CVideoSoftReset();
                CTimerDelayXms(10);
    
                switch(CDetectTVSignalType())
                {
                case 0:  // MODE_NOSIGNAL
                    LowLevel_CH = 0;  // eric add
                    f = 0;
                    count = 0;
                    break;
    
                case 1:  // 
                    return freq;
                }

                freq = 0;
            }      
        }   

        if (bCLockMode) // Search up
        {
            iStartFreq++;
            if (((iStartFreq > _MAX_FREQ) && (0 == bFM)) ||
                ((iStartFreq > _FM_MAX_FREQ) && (1 == bFM)))
                return 1;
        }
        else            // Search down
        {
            iStartFreq--;
            if (((iStartFreq < _MIN_FREQ) && (0 == bFM)) ||
                ((iStartFreq < _FM_MIN_FREQ) && (1 == bFM)))
                return 1;
        }
    }
    return 1;  //Not Find Channel
}

//==========================================================================
//                        CSetTVChannel
//==========================================================================
void CSetTVChannel(const BYTE ucCurrentChannel)
{  
    ucTVType = CLoadChannelColorType(ucCurrentChannel); // set tv system
        
#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
    gmi_CI2CWriteIfPllDM(ucTVType, _TUNER_MUTE_ON, _TUNNING_MODE); // set tv system
#endif
    gmi_CSetTuner(_ADDR_TUNER, CLoadChannelFreq(ucCurrentChannel));
#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
    gmi_CI2CWriteIfPllDM(ucTVType, _TUNER_MUTE_OFF, _NORMAL_MODE); // set tv system
#endif
    CTimerDelayXms(20);
    ucAudioState = 1;
}

#endif  // #if (_TV_CHIP == _TV_TDQ_6F6)
