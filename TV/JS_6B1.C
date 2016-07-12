#include "Core\Header\Include.h"

#if(_TV_CHIP == _TV_JS_6B1)





 
//==========================================================================
//                            gmi_CI2CWriteIfPllDM
//==========================================================================
void gmi_CI2CWriteIfPllDM(BYTE ucTvType, const bit bTunerMute, const BYTE ucAFTMode)
{
    if (ucAFTMode);

    // Set TDA9886 B,C data
    switch(ucTvType)
    {
    case _TV_PAL_M     :    // 60Hz PAL M
    case _TV_NTSC_M    :    // 60Hz NTSC M
    case _TV_NTSC_4_BG :    // 60Hz NTSC 4/BG
    case _TV_NTSC_4_I  :    // 60Hz NTSC 4/I
    case _TV_NTSC_4_DK :    // 60Hz NTSC 4/DK
        pData[0] = _TDA9886_B_DATA_NTSC;
        pData[1] = _TDA9886_C_DATA_NTSC;
        break;

    default:                // Normal sound
    case _TV_SECAM_BG  :    // 50Hz SECAM B/G
    case _TV_SECAM_DK  :    // 50Hz SECAM D/K
    case _TV_PAL_N     :    // 50Hz PAL N
    case _TV_PAL_BG    :    // 50Hz PAL B/G
    case _TV_PAL_I     :    // 50Hz PAL I
    case _TV_PAL_DK    :    // 50Hz PAL D/K
        pData[0] = _TDA9886_B_DATA_PAL;
        pData[1] = _TDA9886_C_DATA_PAL;
        break;

    } // end switch

    if (bTunerMute)
        CMuteOn();
    
    // Set TDA9886 E data
    switch(ucTvType)
    {
    case _TV_PAL_M     :    // Sound 4.5M  PAL M
    case _TV_NTSC_M    :    // Sound 4.5M  NTSC M
    case _TV_PAL_N     :    // Sound 4.5M  PAL N 
        pData[2] = _TDA9886_E_DATA_NTSC;
        break;

    case _TV_NTSC_4_BG :    // Sound 5.5M  NTSC 4/BG
    case _TV_PAL_BG    :    // Sound 5.5M  PAL B/G
    case _TV_SECAM_BG  :    // Sound 5.5M  SECAM B/G
        pData[2] = _TDA9886_E_DATA_PAL_BG;
        break;

    default:                // Normal sound
    case _TV_NTSC_4_I  :    // Sound 6.0M  NTSC 4/I
    case _TV_PAL_I     :    // Sound 6.0M  PAL I
        pData[2] = _TDA9886_E_DATA_PAL_I;
        break;

    case _TV_NTSC_4_DK :    // Sound 6.5M  NTSC 4/DK
    case _TV_PAL_DK    :    // Sound 6.5M  PAL D/K
    case _TV_SECAM_DK  :    // Sound 6.5M  SECAM D/K
        pData[2] = _TDA9886_E_DATA_PAL_DK;
        break;

    } // end switch
      
    CI2cWrite(_ADDR_IfPllDM,0x00,3, pData);  // Set TDA9886
}

//==========================================================================
//                         gmi_CSetTuner
//==========================================================================
void gmi_CSetTuner(BYTE ucTunerAddress, WORD Freq)
{	   
   pData[0] = 8;
   pData[1] = ucTunerAddress;
   ((WORD *)pData)[1] = Freq;

   pData[4] = 0x88;//0xc8; 
  
   if(Freq < _VHF_LOW_BAND)  
      pData[5]=0x01;   // VHFLOW   
   else if(Freq < _VHF_HIGH_BAND)
      pData[5]=0x02;  // VHFHIGH 
   else 
      pData[5]=0x04;  //Band select//UHF 
   pData[6]=0xd8;//0x98;
   pData[7]=0x60;

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

    gmi_CI2CWriteIfPllDM(ucTVType, _TUNER_MUTE_ON, _NORMAL_MODE);
    CTimerDelayXms(8);
    CShowAutoSerachTotal(ucPRG);   // Show search tv channel number
                    
    CScalerSetBit(_VDISP_CTRL_28, ~_BIT5, 0x00); 

	CScalerPageSelect(_PAGE9);		
    CScalerSetByte(_P9_C_LOCK_CONF_B6, 0x6B);

    while(1)
    {
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
    CSetTVChannel(0);

//    bChangeChannel = 1;

//	CTimerReactiveTimerEvent(SEC(GET_OSDTIMEOUT()), COsdFxExitEvent);

    gmi_CI2CWriteIfPllDM(ucTVType, _TUNER_MUTE_OFF, _NORMAL_MODE); // set tv system
   // CModeResetTVMode();
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

    gmi_CI2CWriteIfPllDM(ucTVType, _TUNER_MUTE_ON, _NORMAL_MODE);
    CTimerDelayXms(100);

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

    gmi_CI2CWriteIfPllDM(ucTVType, _TUNER_MUTE_OFF, _NORMAL_MODE);
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

        rData = gmi_CReadIfPllDM();

        switch((rData >> 1) & 0x0f)
        {
        case 7:
            if (bCLockMode) // Search up
            {
                f = 1;
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

		if (0x1b==f || 0x1a==f) 
		{
			LowLevel_CH++;
            if (0 == freq)
        		freq = iStartFreq;
		}
		else
            LowLevel_CH = 0;

        if((rData & 0xc0) != 0xc0)
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

        if (bCLockMode) // Search up
        {
            iStartFreq++;
            if (iStartFreq > _MAX_FREQ)
                return 1;
        }
        else            // Search down
        {
            iStartFreq--;
            if (iStartFreq < _MIN_FREQ)
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
        
    gmi_CSetTuner(_ADDR_TUNER, CLoadChannelFreq(ucCurrentChannel));
    gmi_CI2CWriteIfPllDM(ucTVType, _TUNER_MUTE_ON, _NORMAL_MODE); // set tv system
    CTimerDelayXms(20);
}


#endif // #if(_TV_CHIP == _TV_JS_6B1)

