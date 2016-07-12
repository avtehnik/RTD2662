
//=======================================================================================
//                                                                                      ]
//EEPROM address: 0xA6  0x50~0xFF    [ Save channel freq or tv sound and tv color type  ]
//EEPROM address: 0xA8  0x00~0xFC    [ Save channel freq or tv sound and tv color type  ]
//                      0xFE         [ Search max channel                               ]
//                      0xFF         [ User select search ch tv and sound type          ]
// Modify TV EEPROM address by EricLee 04-30-2007                                       ]
//=======================================================================================
// Definitions for max channel count

#define _TV_SYSTEM_EEPROM_ADDR       0xA6   // 24C16 Page 3
#define _TV_SYSTEM_START_ADDR        0x20   // Save tv system data start address

#define _MAX_CHANNEL_COUNT           ((WORD)((0xFF-_TV_SYSTEM_START_ADDR+0xFF-2)/3))

#define _TV_FREQ_EEPROM_ADDR0        0xA6   // 24C16 Page 3
#define _TV_FREQ_EP_START_ADDR0      (((_TV_SYSTEM_START_ADDR+_MAX_CHANNEL_COUNT)/2)*2 + 2) // Freq page6 start address
#define _TV_FREQ_EP0_TV_NUMBER       ((0xFF-_TV_FREQ_EP_START_ADDR0)/2)         // Page6 save tv channel total
#define _TV_FREQ_EEPROM_ADDR1        0xA8   // 24C16 Page 4
#define _TV_MAX_CHANNEL_EEPROM_ADDR  0xA8   // 24C16 Page 4
//#define EEPROM_SEARCH_TYPE_ADDR        0xFF
#define _MAX_CHANNEL_ADDR            0xFE

// FM definition
#define _FM_START_ADDR               0x00
#define _FM_MAX_CHANNEL              16

// Definitions for auto power down
#define _ONE_MINUTE_COUNT            60000  // On minute count 1ms*60000 = 1 minute

//----------------------------------------------------------
// For show tv number option
#define _SHOW_CH_TV_NUMBER           0x01
#define _SHOW_CH_TV_TYPE             0x02
#define _SHOW_CH_SOUND_TYPE          0x04

//----------------------------------------------------------
//Definitions for change channel Method
#define _CHANGE_CHANNEL_M1           0   // Normal Method
#define _CHANGE_CHANNEL_M2           1

#define _CHANGE_CHANNEL_MTD          _CHANGE_CHANNEL_M2

//----------------------------------------------------------
//Definitions for change channel
#define _PREV_CHANNEL                0
#define _NEXT_CHANNEL                1


//----------------------------------------------------------
//Definitions for tuner mute on/off
#define _TUNER_MUTE_ON               1
#define _TUNER_MUTE_OFF              0

//----------------------------------------------------------
#define _TV_TYPE_SUPPORT             1       // Support this type
#define _TV_TYPE_NOT_SUPPORT         0       // Not support this type


//----------------------------------------------------------
#define _TV_AFC_START                0
#define _TV_AFC_TIMEOUT              40      // +-2Mhz -->Step size 50Khz
#define _TV_AFC_STOP                 (_TV_AFC_TIMEOUT+5)
#define _TV_AFC                      _DISABLE

// Definitions for TV chip
#define _TV_NONE              0       // 0:No tv chip
#define _TV_JS_6B1            1       // 1:EYTYANT JS_6B1/111 for PAL B/G,PAL I,PAL D/K,NTSC M/N           // Ready
#define _TV_JS6B2             2
#define _TV_TDQ_6F6           3       // 2:XuGuang TDQ-6F6/T126CW
#define _TNF_8337             4       // 3:TNF 8337-BFD
#define _TNJ_8355             5       // 4:TNJ 8366-CF

#if (_VIDEO_TV_SUPPORT)
#define _TV_CHIP              _TNF_8337
#else
#define _TV_CHIP              _TV_NONE
#endif

//--------------------------------------------------
// Definitions for TV color
//--------------------------------------------------
#define _TV_NTSC_M            0x01    // 60Hz Sound 4.5M  NTSC M
#define _TV_NTSC_4_BG         0x02    // 60Hz Sound 5.5M  NTSC 4/BG
#define _TV_NTSC_4_DK         0x03    // 60Hz Sound 6.5M  NTSC 4/DK
#define _TV_NTSC_4_I          0x04    // 60Hz Sound 6.0M  NTSC 4/I
#define _TV_PAL_M             0x05    // 60Hz Sound 4.5M  PAL M

#define _TV_PAL_BG            0x06    // 50Hz Sound 5.5M  PAL B/G
#define _TV_PAL_I             0x07    // 50Hz Sound 6.0M  PAL I
#define _TV_PAL_DK            0x08    // 50Hz Sound 6.5M  PAL D/K
#define _TV_PAL_N             0x09    // 50Hz Sound 4.5M  PAL N

#define _TV_SECAM_BG          0x0a    // 50Hz Sound 5.5M  SECAM B/G
#define _TV_SECAM_DK          0x0b    // 50Hz Sound 6.5M  SECAM D/K
#define _TV_SECAM_L           0x0c    // 50Hz Sound 6.5M  SECAM L
#define _TV_SECAM_LL          0x0d    // 50Hz Sound 6.5M  Secam L'


//--------------------------------------------------
//  TV IF PLL Demodulator definitions
//--------------------------------------------------
#define _IF_PLL_DE_9886       0       // Philips TDA9886
#define _IF_PLL_DE_1338       1       // Toshiba TB1338

//--------------------------------------------------
// Definition for search channel
//--------------------------------------------------
#define _TUNNING_MODE         0x00
#define _NORMAL_MODE          0x80


//--------------------------------------------------
// For FM freq
//--------------------------------------------------
#define _FM_MIN_FREQ          ((87.5 + (WORD)(_PIF_FREQ/1000)) * _FM_TUNER_BP)
#define _FM_MAX_FREQ          ((109 + (WORD)(_PIF_FREQ/1000)) * _FM_TUNER_BP)



#if(_VIDEO_TV_SUPPORT)

#ifndef __TV__
#define __TV__

extern bit bChangeChannel;
extern BYTE idata ucTVType;
extern BYTE xdata ucPrevChannel;
extern WORD xdata ucCurrentInputNumber;
extern BYTE xdata ucCurrentInputState;
extern BYTE xdata ucAudioState;
extern BYTE ucAddrIfPllDM;


#if(_SLEEP_FUNC)
extern bit bTimerOnScreen;
extern bit bTimerFirstShow;
extern WORD data ucMinuteCount;
extern BYTE data ucAutoPowerDownTime;
#endif

void CForceBackGroundToBlack(void);

void gmi_CI2CWriteIfPllDM(BYTE ucTvType, const bit bTunerMute, const BYTE ucAFTMode);
void gmi_CSetTuner(BYTE ucTunerAddress, WORD Freq);
void CTvAutoSearch(void) small;
void CSetTVChannel(const BYTE ucCurrentChannel);
void CChangeChannel(bit bNext);

BYTE CloadMaxChannelNumber(void);
void CManualSearch(const bit bSearchAction, const BYTE ucCurrentChannel) small;
void CTuningCurrentChannel(const bit bSearchAction, const BYTE ucCurrentChannel) small;
BYTE CLoadChannelSoundType(const BYTE ucCurrentChannel);
void CSaveChannelSoundType(const BYTE ucCurrentChannel, const BYTE ucSoundType);
BYTE CLoadChannelColorType(const BYTE ucCurrentChannel);
void CSaveChannelColorType(const BYTE ucCurrentChannel, const BYTE TVType);
WORD CLoadChannelFreq(const BYTE ucCurrentChannel);
void CSaveChannelFreq(const WORD iFreq, const BYTE ucCurrentChannel);
BYTE CLoadChannelSoundType(const BYTE ucCurrentChannel);
bit  CLoadChannelSkip(const BYTE ucCurrentChannel);
void CSaveChannelSkip(const bit bSkip, const BYTE ucCurrentChannel);
void CInitTV(void);
BYTE CDetectTVSignalType(void);
void CSaveChannelData(const WORD iFreq, const BYTE ucSound, const BYTE ucChannelNumber);
WORD CLockChannel(WORD iStartFreq, const bit bCLockMode) small;
void CModeResetTVMode(void);
void CAudioCtrl(void);
void CChangeFM(void);

#if(_SLEEP_FUNC)
void CShowTimer(void) small;
#endif

#endif    //#ifndef __TV__
#endif 
