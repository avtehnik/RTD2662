
#if(_TV_CHIP == _TNF_8337)

#define _TV_NTSC_M_SUPPORT       _TV_TYPE_SUPPORT        // 60Hz Sound 4.5M  NTSC M
#define _TV_NTSC_4_BG_SUPPORT    _TV_TYPE_NOT_SUPPORT    // 60Hz Sound 5.5M  NTSC 4/BG
#define _TV_NTSC_4_DK_SUPPORT    _TV_TYPE_NOT_SUPPORT    // 60Hz Sound 6.5M  NTSC 4/DK
#define _TV_NTSC_4_I_SUPPORT     _TV_TYPE_NOT_SUPPORT    // 60Hz Sound 6.0M  NTSC 4/I
#define _TV_PAL_M_SUPPORT        _TV_TYPE_NOT_SUPPORT    // 60Hz Sound 4.5M  PAL M

#define _TV_PAL_BG_SUPPORT       _TV_TYPE_SUPPORT        // 50Hz Sound 5.5M  PAL B/G
#define _TV_PAL_I_SUPPORT        _TV_TYPE_SUPPORT        // 50Hz Sound 6.0M  PAL I
#define _TV_PAL_DK_SUPPORT       _TV_TYPE_SUPPORT        // 50Hz Sound 6.5M  PAL D/K
#define _TV_PAL_N_SUPPORT        _TV_TYPE_NOT_SUPPORT    // 50Hz Sound 4.5M  PAL N

#define _TV_SECAM_BG_SUPPORT     _TV_TYPE_NOT_SUPPORT    // 50Hz Sound 5.5M  SECAM B/G
#define _TV_SECAM_DK_SUPPORT     _TV_TYPE_NOT_SUPPORT    // 50Hz Sound 6.5M  SECAM D/K
#define _TV_SECAM_L_SUPPORT      _TV_TYPE_SUPPORT        // 50Hz Sound 6.5M  SECAM L
#define _TV_SECAM_LL_SUPPORT     _TV_TYPE_NOT_SUPPORT    // 50Hz Sound 6.5M  Secam L'

#define _TUNER_BP                20
#define _FM_TUNER_BP             32

//33400,33900,34200,38000,38900,457500 KHz
#define _PIF_FREQ                38900  // KHz

//_SPLIT_CARRIER,_INTER_CARRIER 
#define _CARRIER_SELECT          _SPLIT_CARRIER


#define _ADDR_TUNER              0xC0    // address select    
#define _VHF_LOW_BAND            ((165.25 + (WORD)(_PIF_FREQ/1000)) * _TUNER_BP)
#define _VHF_HIGH_BAND           ((467.25 + (WORD)(_PIF_FREQ/1000)) * _TUNER_BP)

#define _MAX_TV_TYPE             _TV_SECAM_L//_TV_PAL_DK

#define _MAX_FREQ                ((864.25 + (WORD)(_PIF_FREQ/1000)) * _TUNER_BP)
#define _MIN_FREQ                ((48.25 + (WORD)(_PIF_FREQ/1000)) * _TUNER_BP)

#define _NORMAL_TV_TYPE          _TV_PAL_I


#define _ADDR_IfPllDM            _TB1338_ADDR

#define _FM_DEVICE               _ON

//--------------------------------------------------
//  TV IF PLL Demodulator select
#define _IF_PLL_DE_CHIP          _IF_PLL_DE_1338


#endif // #if(_TV_CHIP == _TNF_8337)
