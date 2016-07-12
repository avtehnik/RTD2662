//----------------------------------------------------------------------------------------------------
// ID Code      : Struct.h No.0000
// Update Note  :
//
//----------------------------------------------------------------------------------------------------
#include "Core\Header\Maindef.h"

#define _SET_INPUT_SOURCE(value)        (stSystemData.InputSource = value)
#define _GET_INPUT_SOURCE()             stSystemData.InputSource

#define _GET_BLUE_BACKGROUND()          ((stSystemData.MonitorFlag & _BIT5) >> 5)
#define _SET_BLUE_BACKGROUND(x)         stSystemData.MonitorFlag = (stSystemData.MonitorFlag & (~_BIT5)) | (x << 5)

#define _BURNIN_ON						_BIT2
#define _BURNIN_OFF						0x00	

#define GET_BURNIN_STATE()          	(stSystemData.MonitorFlag & _BIT2)
#define SET_BURNIN_STATE(x)             stSystemData.MonitorFlag = (stSystemData.MonitorFlag & (~_BIT2)) | (x << 2)

#define _DISPMODE_FULL					0
#define _DISPMODE_43					1
#define _DISPMODE_AUTO					2

#define GET_DISPLAYMODE()				(stSystemData.MonitorFlag & 0x03)
#define SET_DISPLAYMODE(x)				stSystemData.MonitorFlag = ((stSystemData.MonitorFlag & 0xFC) | x) 

//------------------------------------------------------------------------------
// Reset
//------------------------------------------------------------------------------
#define _RESET_SELECT_STATE                0x40  
#define _RESET_NO_STATE                    0x00 
#define _GET_RESET_SELECT_STATE()         (stOsdUserData.OsdSettingFlag & _BIT6)  
#define _SET_RESET_SELECT_STATE(x)     stOsdUserData.OsdSettingFlag = (stOsdUserData.OsdSettingFlag & (~_BIT6)) | x
//------------------------------------------------------------------------------

#define GET_OSD_SIZE()   				(stSystemData.MonitorFlag & _BIT3)
#define SET_OSD_SIZE(x)  				stSystemData.MonitorFlag = ((stSystemData.MonitorFlag & (~_BIT3)) | (x << 3)) 

#define _GET_POWER_DOWN_TIME()          ((stTvInfo.TvSettingFlag >> 2) & 0x0F)
#define _SET_POWER_DOWN_TIME(x)         stTvInfo.TvSettingFlag = (stTvInfo.TvSettingFlag & 0xC3) | (x << 2)

//--------------------------------------------------
// Macro of Color Temperature
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE()           (stSystemData.ColorTemp & (_BIT3 | _BIT2 | _BIT1 | _BIT0))
#define SET_COLOR_TEMP_TYPE(x)          (stSystemData.ColorTemp = ((stSystemData.ColorTemp & ~(_BIT3 | _BIT2 | _BIT1 | _BIT0)) | x))

//------------------------------------------------------------------------------
//FM
//------------------------------------------------------------------------------
#define GET_FM_TYPE()           		(stSystemData.ColorTemp & (_BIT7 | _BIT6 | _BIT5 | _BIT4)) >> 4//(stAudioData.Mode & (_BIT7 | _BIT6 | _BIT5 | _BIT4)) >> 4//(stSystemData.ColorTemp & (_BIT7 | _BIT6 | _BIT5 | _BIT4)) >> 4
#define SET_FM_TYPE(x)          		(stSystemData.ColorTemp = ((stSystemData.ColorTemp & ~(_BIT7 | _BIT6 | _BIT5 | _BIT4)) | x<<4))//(stAudioData.Mode = ((stAudioData.Mode & ~(_BIT7 | _BIT6 | _BIT5 | _BIT4)) | x<<4))

#define GET_FM_STATE()          	(stSystemData.MonitorFlag & _BIT4)
#define SET_FM_STATE(x)             stSystemData.MonitorFlag = (stSystemData.MonitorFlag & (~_BIT4)) | (x << 4)
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//Screnn 0,90,180,270,
//------------------------------------------------------------------------------
#define GET_SCREEN_UD()					((stSystemData.ClientDef & _BIT7) >> 7)
#define SET_SCREEN_UD(x)				stSystemData.ClientDef= (stSystemData.ClientDef & (~_BIT7)) | (x << 7)

#define GET_SCREEN_LR()					((stSystemData.ClientDef & _BIT6) >> 6)
#define SET_SCREEN_LR(x)				stSystemData.ClientDef= (stSystemData.ClientDef & (~_BIT6)) | (x << 6)
//------------------------------------------------------------------------------
//IR
//------------------------------------------------------------------------------
#define _GET_IR_MODE()				    ((bit)(stSystemData.IRStatus & _BIT1))
#define _SET_IR_MODE()					(stSystemData.IRStatus |= _BIT1) 
#define _CLR_IR_MODE()					(stSystemData.IRStatus &= ~_BIT1) 
//------------------------------------------------------------------------------

#define _CT_9300						0
#define _CT_6500						1
#define _CT_5800						2
#define _CT_SRGB						3
#define _CT_USER						4

//--------------------------------------------------
// Struct Type
//--------------------------------------------------
typedef struct
{
    UINT8 PolarityFlag;              
    UINT16 IHWidth;                   // Input Horizontal Width
    UINT16 IVHeight;                  // Input Vertical Height
    UINT16 IHFreq;                    // Input Horizontal Frequency
    UINT16 IVFreq;                    // Input Vertical Frequency
    UINT8 IHFreqTolerance;            // Input Horizontal Frequency Tolerance
    UINT8 IVFreqTolerance;            // Input Vertical Frequency Tolerance
    UINT16 IHTotal;                   // Input Horizontal Total Length
    UINT16 IVTotal;                   // Input Vertical Total Length
    UINT16 IHStartPos;                // Input Horizontal Start Position
    UINT16 IVStartPos;                // Input Vertical Start Position

} ModeTableType;
//------------------------------------------------------
typedef struct
{
    UINT16 DHTotal;                   // Display Horizontal Total Length
    UINT16 DHWidth;                   // Display Horizontal Width
    UINT16 DVHeight;                  // Display Vertical Height
    UINT16 DVStartPos;                // Display Vertical Start Position

} DisplayTableType;
//------------------------------------------------------
typedef struct
{
    UINT8 ModeCurr;                   // Input Mode
    UINT8 Polarity;                   // BIT0: H Polarity, Bit1: V Polarity
    UINT16 IHFreq;                    // Input Horizontal Frequency
    UINT16 IVFreq;                    // Input Vertical Frequency
    UINT16 IHTotal;                   // Input Horizontal Total Length
    UINT16 IVTotal;                   // Input Vertical Total Length
    UINT16 IHWidth;                   // Input Horizontal Width
    UINT16 IVHeight;                  // Input Vertical Height
    UINT16 IHStartPos;                // Input Horizontal Start Position
    UINT16 IVStartPos;                // Input Vertical Start Position
    UINT16 IHCount;                   // Input Horizontal Count Numbers
    UINT16 IHSyncPulseCount;          // Input Horizontal Sync Pulse Count Numbers

} ModeInformationType;
//------------------------------------------------------
typedef struct
{
    UINT8 PanelStyle;                 // Panel Style
    UINT8 PanelConfig;                // Panel Configuration

    UINT16 DHStartPos;                // Display Horizontal Start Position
    UINT16 DHWidth;                   // Display Horizontal Width

    UINT16 DHTotal;                   // Display Horizontal Total Clock Number in One Display Line
    UINT16 PalDHTotal;                // Display Horizontal Total Clock Number in One Display Line for CVBS PAL
    UINT16 NtscDHTotal;               // Display Horizontal Total Clock Number in One Display Line for CVBS NTSC

    UINT16 DVStartPos;                // Display Vertical Start Position
    UINT16 DVHeight;                  // Display Vertical Height

    UINT16 DVTotal;                   // Display Vertical Total Line Number in One Frame

    UINT8 DHSyncWidth;                // Display H Sync Width
    UINT8 DVSyncHeight;               // Display V Sync Height

    UINT16 PixelClock;                // Typical Pixel Clock in MHz

    UINT16 HSyncMaxFreq;              // H Sync Max Freq Unit in 0.1 kHZ
    UINT16 HSyncMinFreq;              // H Sync Min Freq Unit in 0.1 kHZ
    UINT16 VSyncMaxFreq;              // V Sync Max Freq Unit in 0.1 HZ
    UINT16 VSyncMinFreq;              // V Sync Min Freq Unit in 0.1 HZ

    UINT8 TTL20;

} PanelType;
//------------------------------------------------------

typedef struct
{
    UINT8 FirstAuto;                  // First Auto
    UINT16 HPosition;                 // Horizontal Position
    UINT16 VPosition;                 // Vertical Position
    UINT16 Clock;                     // Clock Adjust
    UINT8 Phase;                      // Phase Adjust

} StructModeUserDataType;
//------------------------------------------------------
typedef struct
{
    UINT8 ModeNum;                    // Mode Number
    UINT16 IHFreq;                    // Input Horizontal Frequency
    UINT16 IVFreq;                    // Input Vertical Frequency

} StructModeUserFIFODataType;
//------------------------------------------------------
typedef struct
{
    UINT16 CenterHPos;                // Horizontal Position
    UINT16 CenterVPos;                // Vertical Position
    UINT16 CenterClock;               // Clock Adjust

} StructModeUserCenterDataType;
//------------------------------------------------------
typedef struct
{
	UINT8 MonitorFlag;	   			// Bit 7: Monitor Power Status
      	                            // Bit 6: DVI-I/VGA switch flag
      	                            // Bit 5: Blue background 0-> Disable  1->Enable
      	                            // Bit 4: Reserved
      	                            // Bit 3: OSD Size        0-> Normal   1-> Double
                                    // Bit 2: Burnin          0-> Off      1-> On
                                    // Bit 1~0: Display mode  0-> full     1-> 4:3     2-> auto

	UINT8 InputSource;
	UINT8 BackLight;
	UINT8 ColorTemp;
	UINT8 Sharpness;
		//bit 7~4  Peaking-Coring
		//  		[ 000b: Disable]
		//  		[ 001b: Mode 1	]
		//  		[ 010b: Mode 2	]
		//  		[ 011b: Mode 3	]
		//  		[ 100b: Mode 4	]
		//bit 3~0	[ Sharpness		]
		//  		[ 000b: Disable]
		//  		[ 001b: Mode 1	]
		//  		[ 010b: Mode 2	]
		//  		[ 011b: Mode 3	]
		//  		[ 100b: Mode 4	]
    UINT8 PeakingCoring;

	UINT8 UserFIFOMode;
	UINT8 Hue;
	UINT8 Saturation;
	UINT8 YPbPrHue;  // Ken
	UINT8 YPbPrSaturation;//Ken

	UINT8 Contrast;	// for VDC 2612
	UINT8 Brightness;	// for VDC 2612
	UINT8 Gamma;
		// Bit 0: NR[1: On / 0:Off]
		// Bit 1: Reserved
        //bit 3~2   [ Display Ratio ]
        //          [ 01b :   4:3       ]
        //          [ 10b :  16:9       ]
        //          [ 11b :  Letter Box ]
		//bit 4~6	[ Gamma			]
		//  		[ 000b: Disable	]
		//  		[ 001b: Gamma 1	]
		//  		[ 010b: Gamma 2	]
		//  		[ 011b: Gamma 3	]
		//  		[ 100b: Gamma 4	]
      	// Bit 7: DOS mode select

	UINT8 ucColorSetting;
		// bit 7 [Black Level Expansion	]
		// bit 6 [Auto Image			]
		// bit 5 [Flesh Tone			]
		// bit 4 [Reserved              ][NonLinear Enable		]
		// bit 3~1[DCC Mode			]
		// 		[ 000b: Disable		]
		//  	[ 001b: Mode 1		]
		//  	[ 010b: Mode 2		]
		//  	[ 011b: Mode 3		]
		//  	[ 100b: Mode 4		]
		//      [101b~111b: Reserved  ]
		// bit 0 [ICM  0: Disable 1: Enable  ]

	UINT8 CcSystem;
		//bit 7~4 	[ Nonlinear Scaling]
        //         	[ 00b : Off        ]
        //         	[ 01 ~ 10 On       ]
		// bit 3~0
		//		0: ccmute
		// 		1: CC1, 2:CC2, 3:CC3, 4:CC4,
		//		5: TT1, 6:TT2, 7:TT3, 8:TT4
	UINT8 Mode;//use for picture mode and audio mode  
               //-------picture mode--------
		//bit 7~4	[0: standard			标准]
		//			[1: bright				亮丽]
		//			[2: MILD				柔和]
		//			[3: movie			    电影]
		//			[4: user				用户]  
		//--------audio mode---------
		//bit 0~3		[0: standard		标准]
		//			[1: THEATER			    影院]
		//			[2: music				音乐]
		//			[3: news				新闻]
		//			[3: user				用户]
		//---------------------------------------

} StructSystemDataType;
//------------------------------------------------------
typedef struct
{
	UINT8 ICM_COLOR[10];	  //0~9 use for RGBYC
	//leo 20060613 add black level
	#if(_BLACK_LEVEL ==  _ENABLE)
	UINT8 BlackLevel;
	UINT8 WhiteLevel;
	#endif
}StructICMColor;
//------------------------------------------------------

typedef struct 
{
    BYTE KeyMessage;
    BYTE OsdEvent;
}SKeyToOsdEvent;
//------------------------------------------------------


#define GET_DCC_MODE()					    ((stSystemData.ucColorSetting & (_BIT3 | _BIT2 | _BIT1)) >> 1)
#define SET_DCC_MODE(x) 				    (stSystemData.ucColorSetting = (stSystemData.ucColorSetting & ~(_BIT3 | _BIT2 | _BIT1)) | (x<<1))

//leo 20060613 add black level
#if(_BLACK_LEVEL ==  _ENABLE)
#define GET_BLACKLEVEL()			        (stICMColor.BlackLevel)
#define SET_BLACKLEVEL(x)			        (stICMColor.BlackLevel = x)
#define GET_WHITELEVEL()			        (stICMColor.WhiteLevel)
#define SET_WHITELEVEL(x)			        (stICMColor.WhiteLevel = x)
#endif

#define GET_ICM_on_off()				    ((stSystemData.ucColorSetting & _BIT0))
#define SET_ICM_on_off() 				    (stSystemData.ucColorSetting |=( _BIT0))
#define CLR_ICM_on_off() 				    (stSystemData.ucColorSetting &= (~_BIT0))
//Video / TV
#define GET_ICM_HUE_R()				        (stICMColor.ICM_COLOR[0])
#define GET_ICM_HUE_G()				        (stICMColor.ICM_COLOR[1])
#define GET_ICM_HUE_B()				        (stICMColor.ICM_COLOR[2])
#define GET_ICM_HUE_Y()				        (stICMColor.ICM_COLOR[3])
#define GET_ICM_HUE_C()				        (stICMColor.ICM_COLOR[4])
#define GET_ICM_SAT_R()                     (stICMColor.ICM_COLOR[5])
#define GET_ICM_SAT_G()                     (stICMColor.ICM_COLOR[6])
#define GET_ICM_SAT_B()                     (stICMColor.ICM_COLOR[7])
#define GET_ICM_SAT_Y()                     (stICMColor.ICM_COLOR[8])
#define GET_ICM_SAT_C()                     (stICMColor.ICM_COLOR[9])

#define SET_ICM_HUE_R(x)                    (stICMColor.ICM_COLOR[0] = (stICMColor.ICM_COLOR[0] & 0x00)|(x))
#define SET_ICM_HUE_G(x)			        (stICMColor.ICM_COLOR[1] = (stICMColor.ICM_COLOR[1] & 0x00)|(x))
#define SET_ICM_HUE_B(x)			        (stICMColor.ICM_COLOR[2] = (stICMColor.ICM_COLOR[2] & 0x00)|(x))
#define SET_ICM_HUE_Y(x)			        (stICMColor.ICM_COLOR[3] = (stICMColor.ICM_COLOR[3] & 0x00)|(x))
#define SET_ICM_HUE_C(x)			        (stICMColor.ICM_COLOR[4] = (stICMColor.ICM_COLOR[4] & 0x00)|(x))
#define SET_ICM_SAT_R(x)			        (stICMColor.ICM_COLOR[5] = (stICMColor.ICM_COLOR[5] & 0x00)|(x))
#define SET_ICM_SAT_G(x)			        (stICMColor.ICM_COLOR[6] = (stICMColor.ICM_COLOR[6] & 0x00)|(x))
#define SET_ICM_SAT_B(x)			        (stICMColor.ICM_COLOR[7] = (stICMColor.ICM_COLOR[7] & 0x00)|(x))
#define SET_ICM_SAT_Y(x)			        (stICMColor.ICM_COLOR[8] = (stICMColor.ICM_COLOR[8] & 0x00)|(x))
#define SET_ICM_SAT_C(x)			        (stICMColor.ICM_COLOR[9] = (stICMColor.ICM_COLOR[9] & 0x00)|(x))

#define GET_CLOSEDCAPTION()				    (stSystemData.CcSystem & (_BIT0 | _BIT1 | _BIT2 | _BIT3 ))
#define SET_CLOSEDCAPTION(x)			    (stSystemData.CcSystem = (stSystemData.CcSystem & ~(_BIT0 | _BIT1 | _BIT2 | _BIT3)) | x)

#define SET_NONLINEAR_VALUE(x)              (stSystemData.CcSystem = stSystemData.CcSystem & 0x0f | ((x & 0x0f) << 4))
#define GET_NONLINEAR_VALUE()               ((stSystemData.CcSystem & 0xf0) >> 4)
#define CLR_NONLINEAR_VALUE()               (stSystemData.CcSystem & 0x0f)

#define GET_GAMMA()                         ((stSystemData.Gamma & (_BIT4 | _BIT5 | _BIT6)) >> 4)
#define SET_GAMMA(x)                        (stSystemData.Gamma = (stSystemData.Gamma & ~(_BIT4 | _BIT5 | _BIT6)) | ((x & (_BIT0 | _BIT1 | _BIT2)) << 4))

#define GET_DISPLAYRATIO()                  ((stSystemData.Gamma & (_BIT2 | _BIT3)) >> 2)
#define SET_DISPLAYRATIO(x)                 (stSystemData.Gamma = (stSystemData.Gamma & ~(_BIT2 | _BIT3)) | ((x & (_BIT0 | _BIT1)) << 2))

#define GET_NOISEREDUTION()                 (stSystemData.Gamma & (_BIT0))
#define SET_NOISEREDUTION(x)                (stSystemData.Gamma = (stSystemData.Gamma & ~(_BIT0)) | x)

#define GET_PEAKING_CORING()                (stSystemData.PeakingCoring)
#define SET_PEAKING_CORING(x)               (stSystemData.PeakingCoring = x)

#define GET_SHARPNESS()                     (stSystemData.Sharpness & (_BIT0 | _BIT1 | _BIT2 | _BIT3))
#define SET_SHARPNESS(x)                    (stSystemData.Sharpness = (stSystemData.Sharpness & ~(_BIT0 | _BIT1 | _BIT2 | _BIT3)) | x)

#define GET_HUE()                           (stHueSatData.Hue)
#define SET_HUE(x)                          (stHueSatData.Hue = x);
#define GET_SATURATION()                    (stHueSatData.Saturation)
#define SET_SATURATION(x)                   (stHueSatData.Saturation = x)
#define GET_CONTRAST()                      (stConBriData.Contrast)
#define SET_CONTRAST(x)                     (stConBriData.Contrast = x)

#define GET_BRIGHTNESS()                    (stSystemData.Brightness)
#define SET_BRIGHTNESS(x)                   (stSystemData.Brightness = x)
#define GET_MODESELECT_TYPE()	            (BIT)(stSystemData.Gamma & _BIT7)
#define SET_MODESELECT_TYPE(x) 	            (stSystemData.Gamma =  (stSystemData.Gamma & ~_BIT7) | (x<<7))

//brighty for skyworth
#define GET_Picture_Mode()			        ((stSystemData.Mode & (_BIT7|_BIT6|_BIT5|_BIT4)) >> 4)							
#define SET_Picture_Mode(x)			        (stSystemData.Mode = (stSystemData.Mode & ~(_BIT7|_BIT6|_BIT5|_BIT4) | (x<<4)))	
#define GET_Sound_Mode() 			        (stSystemData.Mode & (_BIT0 | _BIT1|_BIT2|_BIT3))
#define SET_Sound_Mode(x) 			        (stSystemData.Mode = (stSystemData.Mode & ~(_BIT0 | _BIT1|_BIT2|_BIT3)) | x)

typedef struct
{

    UINT8 OsdHPos;
    UINT8 OsdVPos;
    UINT8 Language;
    UINT8 OsdTimeout;
    UINT8 OsdBlending;
    UINT8 Volumn;
    UINT8 Filter_type;
} StructOsdUserDataType;

#define NoSignalAutoOff_Enable	1
#define NoSignalAutoOff_Disable	0

#define GET_OSDTIMEOUT() 							(stOsdUserData.OsdTimeout)
#define SET_OSDTIMEOUT(x) 							(stOsdUserData.OsdTimeout = x)
#define SET_OSDUSERHPOS(x) 							(stOsdUserData.OsdHPos= x)
#define SET_OSDUSERVPOS(x) 							(stOsdUserData.OsdVPos= x)
#define GET_OSDBLENDING() 							(stOsdUserData.OsdBlending)
#define SET_OSDBLENDING(x) 							(stOsdUserData.OsdBlending = x)
#define GET_FILTER_TYPE() 							(stOsdUserData.Filter_type)
#define SET_FILTER_TYPE(x) 							(stOsdUserData.Filter_type = x)

typedef struct
{
    UINT8 AdcGain[3];
    UINT8 AdcOffset[3];
} StructAdcDataType;

typedef struct
{
    UINT8 YPbPrGain[3];
    UINT8 YPbPrOffset[3];
#if(_VIDEO_AUTO_WHITE_BLANCE == _ENABLE)
    UINT8 VDCGain;
    UINT8 VDCOffset;
    UINT8 VDCChroma;
#endif
}StructYPbPrDataType;

#if(_VIDEO_AUTO_WHITE_BLANCE == _ENABLE)
#define GET_VDC_GAIN() 		                (stYPbPrData.VDCGain)
#define SET_VDC_GAIN(x) 	                (stYPbPrData.VDCGain= x)
#define GET_VDC_OFFSET() 	                (stYPbPrData.VDCOffset)
#define SET_VDC_OFFSET(x) 	                (stYPbPrData.VDCOffset= x)
#define GET_VDC_CHROMA() 	                (stYPbPrData.VDCChroma)
#define SET_VDC_CHROMA(x) 	                (stYPbPrData.VDCChroma= x)
#endif

typedef struct			// for D-sub and DVI
{
    UINT8 Brightness;
    UINT8 Contrast;

} StructColorProc0DataType;

typedef struct
{
    UINT8 ColorTemp[3];
} StructColorProc1DataType;

typedef struct
{
    UINT8 ColorTemp9300Red;
    UINT8 ColorTemp9300Green;
    UINT8 ColorTemp9300Blue;

    UINT8 ColorTemp6500Red;
    UINT8 ColorTemp6500Green;
    UINT8 ColorTemp6500Blue;

    UINT8 ColorTemp5800Red;
    UINT8 ColorTemp5800Green;
    UINT8 ColorTemp5800Blue;

    UINT8 ColorTempsRGBRed;
    UINT8 ColorTempsRGBGreen;
    UINT8 ColorTempsRGBBlue;

    UINT8 ColorTempUserRed;
    UINT8 ColorTempUserGreen;
    UINT8 ColorTempUserBlue;
} StructColorTempDataType;

//--------------------------------------------------
// TV information Struct
//--------------------------------------------------
typedef struct
{
	UINT8 CurChn;
    UINT8 ucFMCurrCh;
	UINT8 TvSettingFlag;
		// Bit 7:  AFC  0: OFF
        //              1: ON
		// Bit 6:  0: CATV
        //         1: AIR
		// Bit 5~2 Auto power down
        //        0: Auto power down off
        //        1: 15 Minute
        //        2: 30 Minute
        //        3: 45 Minute
        //        4: 60 Minute
        //        5: 75 Minute
        //        6: 90 Minute
        //        7: 105 Minute
        //        8: 120 Minute

		// Bit 1~0: Input channel state
        //        00: Input one channel   -
        //        01: Input two channel   --
        //        02: Input three channel ---  
	UINT16 TvRating;
		// D11 : TV-MA-V
		// D10 : TV-MA-S
		// D9 : TV-MA-L
		// D8 : TV-14-V
		// D7 : TV-14-S
              // D6 : TV-14-L
		// D5 : TV-14-D
		// D4 : TV-PG-V
		// D3 : TV-PG-S
		// D2 : TV-PG-L
		// D1 : TV-PG-D
		// D0 : TV-Y7-FV
	UINT8 usaRating;
		//D7-4: MOVING_RATING
		//D3-0: TV_RATING
	UINT8 canadaRating;
		//D7-4: FRENCH_RATING
		//D3-0: ENGLISH_RATING
	UINT8 scartStatus;
		//bit 7~3 	 Reserved
		//bit 2 	[ WSS  Scaling	]
		//  		[ 0 : Disable	]
		//			[ 1 : Enable	]
		//bit 1		[ AUTO SCART Scaling]
		//  		[ 0 : Disable		]
		//			[ 1:  Enable		]
		//bit 0		[AUTO SCART Source	]
		//  		[ 0 : Disable		]
		//			[ 1:  Enable		]
  	UINT8 TvRatingLock;
		//b6~b7 : Resvered
		//b5: TV-MA-LOCK
		//b4: TV-14-LOCK
		//b3: TV-PG-LOCK
		//b2: TV-G-LOCK
		//b1: TV-Y7-LOCK
		//b0: TV-Y-LOCK
} StructTvDataType;

#define GET_INPUTCH_STATE()         (stTvInfo.TvSettingFlag & 0x03)
#define SET_INPUTCH_STATE(x)        stTvInfo.TvSettingFlag = (stTvInfo.TvSettingFlag & 0xFC) | x


typedef struct {
	UINT8 Mode;	// General Audio Mode
		//bit 7~4 	 Reserved
		//bit 3~2	[ MTS				]
		//  		[ 00b: Mono		    ]
		//  		[ 01b: Stereo		]
		//  		[ 10b: SAP			]
		//  		[ 11b: Dual		    ]
		//bit 1	    [ Mute on/off ctrl	]
		//		    [ 0: Mute off		]
		//		    [ 1: Mute On		]
		//bit 0	    [ Audio Destination	]
		//  		[ 0: Loudspeaker	]
		//  		[ 1: Earphone		]
	UINT8 Volume;	// based on Audio Dst (bit 0 of Mode)
	UINT8 Balance;		// Balance value of each output channel
	UINT8 Bass;			// Bass value of each output channel
	UINT8 Treble;		// Treble value of each output channel
	UINT8 Woofer;		// Woofer value for loudspeaker
} StructAudioDataType;


#define GET_AUDIO_MUTE()            ((stAudioData.Mode & _BIT1) >> 1)
#define SET_AUDIO_MUTE()            (stAudioData.Mode |= (_BIT1))
#define CLR_AUDIO_MUTE()            (stAudioData.Mode &= ~(_BIT1))
#define GET_VOLUME()                (stAudioData.Volume)
#define SET_VOLUME(x)               (stAudioData.Volume = x)


#define _TV_NOSIGNAL_OFF			0x00
#define _TV_NOSIGNAL_ON				0x01
#define GET_TV_NOSIGNAL()			(stAudioData.Mode&_BIT4)
#define SET_TV_NOSIGNAL(x)			stAudioData.Mode = (stAudioData.Mode&(~_BIT4))|(x<<4)


#define _SYS_OSD_ON					0x01
#define _SYS_OSD_OFF				0x00
#define GET_SYS_OSD()				(stAudioData.Mode&_BIT5)
#define SET_SYS_OSD(x)				stAudioData.Mode = (stAudioData.Mode&(~_BIT5))|(x<<5)

//--------------------------------------------------
// Timer Struct
//--------------------------------------------------
struct CTimerEventTable
{
    UINT16 Time;
    void (*Event)(void);
};

typedef struct		
{
    UINT8 Hue;
    UINT8 Saturation;
} StructHueSaturationDataType;


//--------------------------------------------------
// Extern Global Struct Variables
//--------------------------------------------------
extern StructModeUserDataType       xdata   stModeUserData;
extern StructModeUserCenterDataType xdata   stModeUserCenterData;
extern StructSystemDataType         xdata   stSystemData;
extern StructICMColor               xdata   stICMColor;
extern StructOsdUserDataType        xdata   stOsdUserData;
extern StructAdcDataType            xdata   stAdcData;
extern StructYPbPrDataType          xdata   stYPbPrData;
extern StructColorProc0DataType     xdata   stConBriData;
extern StructColorProc1DataType     xdata   stColorTempData;
extern ModeInformationType          idata   stModeInfo;
extern DisplayTableType             idata   stDisplayInfo;
extern StructTvDataType		    	xdata   stTvInfo;
extern StructAudioDataType 	    	xdata   stAudioData;
extern StructHueSaturationDataType  xdata   stHueSatData;
