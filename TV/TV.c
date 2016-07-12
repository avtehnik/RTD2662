#include "Core\Header\Include.h"

BYTE idata ucTVType             = 0;//_NORMAL_TV_TYPE;

#if(_VIDEO_TV_SUPPORT)

bit bChangeChannel              = 0;
BYTE xdata ucPrevChannel        = 0;
WORD xdata ucCurrentInputNumber = 0;
BYTE xdata ucCurrentInputState  = 0;
BYTE xdata ucAudioState         = 1;
BYTE xdata ucAddrIfPllDM        = _ADDR_IfPllDM;

#if(_SLEEP_FUNC)
bit bTimerOnScreen            = 0;
WORD data ucMinuteCount       = 0;
BYTE data ucAutoPowerDownTime = 0xFF;
bit bTimerFirstShow			  = 0;
#endif

#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
bit bFM = 0;
#endif

WORD CLoadChannelFreq(const BYTE ucCurrentChannel);
void CSaveChannelFreq(const WORD iFreq, const BYTE ucCurrentChannel);



//==========================================================================
//                       CGetTVEepromAddr
//==========================================================================
BYTE CGetTVEepromAddr(const BYTE ucCurrentChannel)
{
    BYTE ucEeprom_Addr;

	#if(_FM_DEVICE)
    if (bFM)
       ucEeprom_Addr = _TV_FREQ_EEPROM_ADDR0;
    else
	#endif
    ucEeprom_Addr = (_TV_FREQ_EP0_TV_NUMBER < ucCurrentChannel) ? _TV_FREQ_EEPROM_ADDR1 : _TV_FREQ_EEPROM_ADDR0;

    return ucEeprom_Addr;
}

//==========================================================================
//                      CGetTVStartAddr
//==========================================================================
BYTE CGetTVStartAddr(const BYTE ucCurrentChannel)
{
    BYTE ucStart_Addr;

	#if(_FM_DEVICE)
    if (bFM)
        ucStart_Addr = _FM_START_ADDR + (ucCurrentChannel * 2);
    else
	#endif
    ucStart_Addr = (_TV_FREQ_EP0_TV_NUMBER < ucCurrentChannel) ? ((ucCurrentChannel - (_TV_FREQ_EP0_TV_NUMBER+1)) * 2)
                                                : (_TV_FREQ_EP_START_ADDR0 + (ucCurrentChannel * 2));

    return ucStart_Addr;
}

//==========================================================================
//                      CDetectTVSignalType
//==========================================================================
BYTE CDetectTVSignalType(void)
{
    BYTE ucTemp;

    for(ucTemp = 0; ucTemp < 4; ucTemp++)
    {
        if (gmi_CModeLocked())  // Horizontal Lock
             return 1;

        CTimerDelayXms(50);
    }

    // No video detected or h/v sync not locked
    return 0;  
}

//============================================================
//                    CLoadChannelSkip
//Output: Channel skip     0 --> no skip     1 --> skip
//============================================================
bit CLoadChannelSkip(const BYTE ucCurrentChannel)
{
    CI2cRead(CGetTVEepromAddr(ucCurrentChannel), CGetTVStartAddr(ucCurrentChannel)+1, LENGTH(1), pData);  // eric 0223

    if (pData[0] & 0x80)  // Channel skip
        return 1;
    else         // No skip
        return 0;
}

//============================================================
//                    CSaveChannelSkip
//============================================================
void CSaveChannelSkip(const bit bSkip, const BYTE ucCurrentChannel)
{
    WORD iFreq = CLoadChannelFreq(ucCurrentChannel);

    if (bSkip)
       CSaveChannelFreq((iFreq & 0x7fff) | 0x8000, ucCurrentChannel);
    else
       CSaveChannelFreq(iFreq & 0x7fff, ucCurrentChannel);
}

//============================================================
//Output: Channel freq
//============================================================
WORD CLoadChannelFreq(const BYTE ucCurrentChannel)
{
    WORD freq = 0;

    CI2cRead(CGetTVEepromAddr(ucCurrentChannel), CGetTVStartAddr(ucCurrentChannel), LENGTH(2), pData);  // eric 0223
    pData[1] &= 0x7f;

    freq = (256*pData[1]) + pData[0];

    if (_MAX_FREQ < freq)
        freq = _MAX_FREQ;
    else if(_MIN_FREQ > freq)
        freq = _MIN_FREQ;

    return freq;
}

//==========================================================================
//                         CSaveChannelFreq
//==========================================================================
void CSaveChannelFreq(const WORD iFreq, const BYTE ucCurrentChannel)
{
    pData[0] = iFreq & 0xff;
    pData[1] = (iFreq >> 8) & 0xff;
    CI2cWrite(CGetTVEepromAddr(ucCurrentChannel), CGetTVStartAddr(ucCurrentChannel), LENGTH(2), pData);  // eric 0223
}

//============================================================
//Output: Channel color type
//============================================================
BYTE CLoadChannelColorType(const BYTE ucCurrentChannel)
{ 
#if(_VIDEO_TV_SUPPORT)          
#if(_FM_DEVICE)
    if (bFM)
       return ucTVType;
#endif
#endif

    CI2cRead(_TV_SYSTEM_EEPROM_ADDR, _TV_SYSTEM_START_ADDR+ucCurrentChannel, LENGTH(1), pData);    // Read current channel sound and tv system
    pData[0] = pData[0] >> 4; // tv type

    if (_MAX_TV_TYPE < pData[0] || 0 == pData[0])
        pData[0] = _NORMAL_TV_TYPE; // Set to normal PAL I 
    
    return pData[0];
}

//==========================================================================
//                           CSaveChannelColorType
//==========================================================================
void CSaveChannelColorType(const BYTE ucCurrentChannel, const BYTE TVType)
{
#if(_FM_DEVICE)
    if (bFM)
       return;
#endif

    pData[0] = (TVType << 4) | (CLoadChannelSoundType(ucCurrentChannel));
    CI2cWrite(_TV_SYSTEM_EEPROM_ADDR, _TV_SYSTEM_START_ADDR+ucCurrentChannel, LENGTH(1), pData);
}

//============================================================
//Output: Channel sound type
//============================================================
BYTE CLoadChannelSoundType(const BYTE ucCurrentChannel)
{
    CI2cRead(_TV_SYSTEM_EEPROM_ADDR, _TV_SYSTEM_START_ADDR+ucCurrentChannel, LENGTH(1), pData);    // Read current channel sound and tv system
    pData[0] = pData[0] & 0x03; // sound type

  //  if (_MAX_TV_SOUND_TYPE_NUM < pData[0])
    //    pData[0] = 1;  // Set to normal: 6.0M

    return pData[0];
}
  
//==========================================================================
//                          CSaveChannelSoundType
//==========================================================================
void CSaveChannelSoundType(const BYTE ucCurrentChannel, const BYTE ucSoundType)
{
    pData[0] = (CLoadChannelColorType(ucCurrentChannel) << 4) | ucSoundType;
    CI2cWrite(_TV_SYSTEM_EEPROM_ADDR, _TV_SYSTEM_START_ADDR+ucCurrentChannel, LENGTH(1), pData);
}  

//==========================================================================
//                          CSaveChannelData
//==========================================================================
void CSaveChannelData(const WORD iFreq, const BYTE ucSound, const BYTE ucChannelNumber)
{
    CSaveChannelFreq(iFreq, ucChannelNumber);
    CTimerDelayXms(4);

#if(_FM_DEVICE)
    if (bFM)
       return;
#endif

    // Save sound and tv system
    pData[0] = (ucTVType<<4) | (ucSound & 0x03);
    CI2cWrite(_TV_SYSTEM_EEPROM_ADDR, _TV_SYSTEM_START_ADDR+ucChannelNumber, LENGTH(1), pData);
    CTimerDelayXms(4);
}

//==========================================================================
//                           CloadMaxChannelNumber
//==========================================================================
BYTE CloadMaxChannelNumber(void)
{
#if(_FM_DEVICE)
    if (bFM)
        return _FM_MAX_CHANNEL;
#endif

#if(_CHANGE_CHANNEL_MTD == _CHANGE_CHANNEL_M2)
    return _MAX_CHANNEL_COUNT;
#else

    CI2cRead(_TV_MAX_CHANNEL_EEPROM_ADDR, _MAX_CHANNEL_ADDR, LENGTH(1), pData);    // Read search max channel
    if (_MAX_CHANNEL_COUNT < pData[0])
    {
        // Save search channel number
        pData[0] = 0;
        CI2cWrite(_TV_MAX_CHANNEL_EEPROM_ADDR, _MAX_CHANNEL_ADDR, 1, pData);

        pData[0] = 0;//_MAX_CHANNEL_COUNT;
    }

    return pData[0];
#endif
}
      

//==========================================================================
//                        CModeResetTVMode
//==========================================================================
void CModeResetTVMode(void)  // eric 1130 add for change tv channel bug
{ 
 //   CPowerLightPowerOff();
	// force to background
    CAdjustBackgroundColor(0x00, 0x00, 0x00);     
	CScalerSetBit(_VDISP_CTRL_28, 0xf7, _BIT5);	// Display output is forced to the background color,and free run
	CTimerWaitForEvent(_EVENT_DEN_STOP);	          
	CAdjustDisableWatchDog(_WD_ALL);			// Disable watch dog
	CScalerSetByte(_HOST_CTRL_01, 0x40);
	CScalerSetBit(_VGIP_CTRL_10, ~(_BIT1 | _BIT0), 0x00);
	CScalerSetByte(_VGIP_SIGINV_11, 0x00);
    CScalerSetByte(_VGIP_DELAY_CTRL_12, 0x00); //731301	
    CScalerPageSelect(_PAGE2);
	CScalerSetBit(_P2_Z0_CALIBRATION_CTRL_AC, ~_BIT6, _BIT6); //V305 modify    
    CScalerPageSelect(_PAGE2);
	CScalerSetByte(_P2_TMDS_OUTPUT_CTRL_A6, 0x78);		//Auto Output Disable
	CScalerSetByte(_P2_POWER_ON_OFF_CTRL_A7, 0x0F);	//Input Channel ctrl by auto func(Manual)                
	CModeAutoMeasureOff();						// Disable auto measure
	CMiscClearStatusRegister();
    ucSearchCount  = 1;
    bChangeChannel = 1;
	
    ucCurrState  = _SEARCH_STATE;                  
}                                                        

//==========================================================================
//                            CChangeChannel
//==========================================================================
void CChangeChannel(bit bNext)
{
    BYTE ucmaxchannel = CloadMaxChannelNumber();

    COsdDispOsdTimerEvent();
	#if (_OSD_TYPE == _OSD003)
    bDrawMute = 0;
	#endif

    if (stTvInfo.CurChn > ucmaxchannel)
    {
        ucPrevChannel   = 0;
        stTvInfo.CurChn = 0;
        return;
    }
              
    CMuteOn();
	#if(_FM_DEVICE)
    if (1 == bFM)
    {
        ucPrevChannel =  stTvInfo.ucFMCurrCh;
    }
    else
	#endif
    {
        ucPrevChannel =  stTvInfo.CurChn;
        CModeResetTVMode();
    }

	do
	{
       if (bNext)  // Change next channel
           stTvInfo.CurChn = (stTvInfo.CurChn == ucmaxchannel) ? 0 : (stTvInfo.CurChn+1);
       else        // Change prev channel
           stTvInfo.CurChn = (stTvInfo.CurChn == 0) ? ucmaxchannel : (stTvInfo.CurChn-1);
    
	   if (!CLoadChannelSkip(stTvInfo.CurChn) || stTvInfo.CurChn == ucPrevChannel)
	        break;
	}
	while(1);

    CSetTVChannel(stTvInfo.CurChn); 
    CEepromSaveTvData();
   // CShowTVNumber(stTvInfo.CurChn, _SHOW_CH_TV_NUMBER | _SHOW_CH_TV_TYPE);
}

//==========================================================================
//bSearchAction:   0 --> Tuning down
//                 1 --> Tuning up
//==========================================================================
void CTuningCurrentChannel(const bit bSearchAction, const BYTE ucCurrentChannel) small
{
    bit bSkip  = CLoadChannelSkip(ucCurrentChannel);
    WORD iFreq = CLoadChannelFreq(ucCurrentChannel);

    if ((iFreq < _MIN_FREQ || iFreq > _MAX_FREQ) && 0 == CloadMaxChannelNumber())
        iFreq = _MIN_FREQ;

    if (bSearchAction) // Tuning up
    {
		#if (_FM_DEVICE)
        if (((iFreq < _MAX_FREQ) && 0 == bFM) || ((iFreq < _FM_MAX_FREQ) && 1 == bFM))
		#else
        if (iFreq < _MAX_FREQ)
		#endif
            iFreq++;
    }
    else  // Tuning down
    {
		#if (_FM_DEVICE)
        if (((iFreq > _MIN_FREQ) && 0 == bFM) || ((iFreq > _FM_MIN_FREQ) && 1 == bFM))
		#else
        if (iFreq > _MIN_FREQ)
		#endif
            iFreq--;
    }

    gmi_CSetTuner(_ADDR_TUNER, iFreq);
    CSaveChannelFreq((iFreq | ((bSkip) ? 0x8000 : 0x0000)), ucCurrentChannel);
}

//==========================================================================
//                          CInitTV
//==========================================================================
void CInitTV(void)
{
	#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
    CInitialTB1338();
	#endif

//     TUNER_PWR_ON();
    CSetTVChannel(stTvInfo.CurChn);
    ucPrevChannel = stTvInfo.CurChn;
    CSetTvColor(ucTVType);
    CTimerDelayXms(100); 
}
   
#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)  
//---------------------------------------------------------------------------
void CAudioCtrl(void)
{
    if (_GET_INPUT_SOURCE() != _SOURCE_VIDEO_TV)
        return;
 
    if (!gmi_CModeLocked() && ucAudioState == 0)
       ucAudioState = 1;

    if (ucAudioState != 0)
        ucAudioState++;

    if (ucAudioState < 50)
        return;

    if (!gmi_CModeLocked() && bFM == 0)  // TV no signal
        CMuteOn();
    else      
        CSetVolume();

    ucAudioState = 0;
}

//---------------------------------------------------------------------------
#if(_FM_DEVICE)
void CChangeFM(void)
{
    CMuteOn();
    if (bFM)
    {                
        CInitialTB1338();
        CTimerDelayXms(10);
        CFMInit();
        CSetTVChannel(stTvInfo.ucFMCurrCh);
        CInitSoundChannel(_SOURCE_VIDEO_TV);
    }
    else
    {
        if (_SOURCE_VIDEO_TV == _GET_INPUT_SOURCE())
           CInitTV();

        CInitSoundChannel(_GET_INPUT_SOURCE());
    }

    CTimerDelayXms(100);
    CSetVolume();
}
#endif
#endif
    
//---------------------------------------------------------------------------
#if(_SLEEP_FUNC)
#if(_OSD_TYPE == _OSD002)
void CShowTimer(void) small
{
    BYTE ucCurrentMin = ucAutoPowerDownTime - 1;
    BYTE ucCurrentSec = 59 - (BYTE)(ucMinuteCount/1000);
    
    if (!bTimerOnScreen)
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
    
        COsdFxEnableOsd();
        bTimerOnScreen = 1;
    }
    
    Gotoxy(0, 0, BYTE_DISPLAY);
    CShowNumber1(ucAutoPowerDownTime - 1, 0);
    OutputChar(0x3a);  // Show ":"
    CShowNumber1(59 - (BYTE)(ucMinuteCount/1000), 2);
    OutputChar(0x00);   

    CTimerReactiveTimerEvent(SEC(GET_OSDTIMEOUT()), COsdDispOsdTimerEvent);
}
#endif // OSD002

#if(_OSD_TYPE == _OSD003)
void CShowTimer(void) small
{
    BYTE ucCurrentMin = ucAutoPowerDownTime;
    BYTE ucCurrentSec = 60-(BYTE)(ucMinuteCount/1000);
    
    if (!bTimerOnScreen)
    {              
        COsdFxDisableOsd();
        ucOsdState = _MI_MENU_NONE;
        SetOSDDouble(0x03);
        SetOsdMap(tMsgOsdMap);
                             
        // Init OSD Ram
        OSDClear(0, 8, 0, 46, 0x8C, BYTE_ATTRIB);
        OSDClear(0, 8, 0, 46, 0x00, BYTE_DISPLAY);
        OSDClear(0, 8, 0, 46, 0xc0, BYTE_COLOR);
        
        COsdFxCodeWrite(ucCloseAllWindow);
    
        OSDPosition(_MAINMENU_WIDTH,_MAINMENU_HEIGHT,80,1,0x03);
    
        COsdFxEnableOsd();
        bTimerOnScreen = 1;
    }
    
    Gotoxy(3, 0, BYTE_DISPLAY);	
    CShowNumber1(ucAutoPowerDownTime , 0);
    OutputChar(0x5E);  // Show ":"
    if(ucCurrentSec == 60)
    	CShowNumber1(0, 2);
    else
    	CShowNumber1(60-(BYTE)(ucMinuteCount/1000), 2);
    OutputChar(0x01);   
   	CTimerCancelTimerEvent(COsdDispOsdTimerEvent);
}

#elif(_OSD_TYPE == _OSD007)

void CShowTimer(void) small
{
    BYTE ucCurrentMin = ucAutoPowerDownTime - 1;
    BYTE ucCurrentSec = 59 - (BYTE)(ucMinuteCount/1000);
    
    if (!bTimerOnScreen)
    {
        COsdFxDisableOsd();
        SetOsdMap(tUserMenuOsdMap);
        SetOSDDouble(OSD_DOUBLE_HEIGHT_ENABLE | OSD_DOUBLE_WIDTH_ENABLE);
        COsdFxCodeWrite(ucCloseAllWindow);
        CClearWindow(0x20);

		#if(_OSD_DISPLAY_SIZE_ADJ)
        if (GET_OSD_SIZE())
        {
            OSDPosition(12*10, 18*3, 80, 1, 0x03);
            DirectWOSDRam(0x00, 0x01, THE_BYTE0, 0x80|0x03);  // Row 0 character double height and width
        }
        else
		#endif
            OSDPosition(30,30,38,1,0x01);

        COsdFxEnableOsd();
        bTimerOnScreen = 1;
    }
    
    Gotoxy(3,0,BYTE_DISPLAY);         
    CShowNumber1(ucAutoPowerDownTime - 1, 2);
    OutputChar(0x3a);  // Show ":"
    CShowNumber1(59 - (BYTE)(ucMinuteCount/1000), 2);
    
    
    CTimerReactiveTimerEvent(SEC(stOsdUserData.OsdTimeout),COsdDispOsdTimerEvent);
}

#endif  // OSD003

#endif  // #if(_SLEEP_FUNC)

  
#endif


