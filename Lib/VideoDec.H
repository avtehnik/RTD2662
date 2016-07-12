////////////////////////////////////////////////////////////////////////////
//         Copyright of Vector Co.,Ltd.                                   //
//                                                                        //
//                                                                        //
//                       Video Decoder function                           //
//   Ver: 6.20                                                            //
//   Create file time: 2006.5.15                                          //
//   End modify time: 2007.2.27                                           //
//   For RTD2523B/RTD2553V/RTD2525L                                       //
////////////////////////////////////////////////////////////////////////////



// Definitions for Vedio Decoder
#define _VDC_NONE          0   // 0:  No vedio decoder available

#define _VDC_RTD2612       1   // 1: Realtek RTD2612 chip
#define _VDC_RTD2613       2   // 2: Realtek RTD2613 chip
#define _VDC_RTD2662       3   // 3: Realtek RTD2662 chip


#define _VIDEO_CHIP        _VDC_RTD2662


// definitions for public
#define _VDC_FREE_RUN_MODE_TO_AUTO     0
#define _VDC_FREE_RUN_MODE_TO_50HZ     1
#define _VDC_FREE_RUN_MODE_TO_60HZ     2


//////////////////////////////////////////////////// RTD2612 //////////////////////////////////////////////////////////
#if(_VIDEO_CHIP == _VDC_RTD2612)
// Definitions for Vedio Decoder input channel
//--------------- ADC 0 ---------------
// ADC 0 only for Y
#define _ADC0_AI00_INPUT           0x00
#define _ADC0_AI01_INPUT           0x01

//--------------- ADC 1 ---------------
#define _ADC1_AI10_INPUT           0x02
#define _ADC1_AI11_INPUT           0x03
#define _ADC1_AI12_INPUT           0x04
#define _ADC1_AI13_INPUT           0x05

//--------------- ADC 2 ---------------
#define _ADC2_AI20_INPUT           0x06
#define _ADC2_AI21_INPUT           0x07
#define _ADC2_AI22_INPUT           0x08
#define _ADC2_AI23_INPUT           0x09

//--------------- ADC 3 ---------------
#define _ADC3_AI30_INPUT           0x0a
#define _ADC3_AI31_INPUT           0x0b
#define _ADC3_AI32_INPUT           0x0c
#define _ADC3_AI33_INPUT           0x0d

#define _NONE_INPUT                0x0f

//                                 |    Y input            |  C input         |
#define _AV_CHANNEL                (_ADC0_AI01_INPUT << 4) |  _NONE_INPUT
#define _SV_CHANNEL                (_ADC2_AI23_INPUT << 4) |  _ADC1_AI13_INPUT
#define _TV_CHANNEL                (_ADC3_AI33_INPUT << 4) |  _NONE_INPUT

//-------------- YCbCr ----------------
//                                 |    Y input            |  Cr input        |
#define _YCBCR_CHANNEL_Y_CR        (_ADC0_AI01_INPUT << 4) |  _ADC2_AI23_INPUT
//                                 |    Cb input
#define _YCBCR_CHANNEL_CB          _ADC1_AI13_INPUT

#define _VIDEODEVICE               0x40

//////////////////////////////////////////////////// RTD2613 //////////////////////////////////////////////////////////
#elif(_VIDEO_CHIP == _VDC_RTD2613)
// Definitions for Vedio Decoder input channel
//--------------- ADC 0 ---------------
// ADC 0 not use in S-VIDEO C
#define _ADC0_AI00_INPUT           0x00
#define _ADC0_AI01_INPUT           0x01

//--------------- ADC 1 ---------------
#define _ADC1_AI10_INPUT           0x02
#define _ADC1_AI11_INPUT           0x03
#define _ADC1_AI12_INPUT           0x04
#define _ADC1_AI13_INPUT           0x05

//--------------- ADC 2 ---------------
#define _ADC2_AI20_INPUT           0x06
#define _ADC2_AI21_INPUT           0x07
#define _ADC2_AI22_INPUT           0x08
#define _ADC2_AI23_INPUT           0x09

//--------------- ADC 3 ---------------
#define _ADC3_AI30_INPUT           0x0a
#define _ADC3_AI31_INPUT           0x0b
#define _ADC3_AI32_INPUT           0x0c
#define _ADC3_AI33_INPUT           0x0d

#define _NONE_INPUT                0x0f

//                                 |    Y input            |  C input         |
#define _AV_CHANNEL                (_ADC0_AI01_INPUT << 4) |  _NONE_INPUT
#define _SV_CHANNEL                (_ADC2_AI23_INPUT << 4) |  _ADC1_AI13_INPUT
#define _TV_CHANNEL                (_ADC3_AI33_INPUT << 4) |  _NONE_INPUT

//                                 |    Y input            |  Cr input        |
#define _YCBCR_CHANNEL_Y_CR        (_ADC0_AI01_INPUT << 4) |  _ADC2_AI23_INPUT
//                                 |    Cb input
#define _YCBCR_CHANNEL_CB          _ADC1_AI13_INPUT

#define _VIDEODEVICE               0x40

//////////////////////////////////////////////////// RTD2662 //////////////////////////////////////////////////////////
#elif(_VIDEO_CHIP == _VDC_RTD2662)
// Definitions for Vedio Decoder input channel
#define _V0_INPUT                  0x01
#define _V1_INPUT                  0x02
#define _V2_INPUT                  0x03
#define _V3_INPUT                  0x04

// If you select SV port, we only support
// V0 with V1 or V1 with V2 or V2 with V3.

//                                 |    Y input     |  C input   |
#define _AV_CHANNEL                (_V1_INPUT << 4)
#define _SV_CHANNEL                (_V0_INPUT << 4) //|  _V0_INPUT
#define _TV_CHANNEL                (_V3_INPUT << 4)


#define _VIDEODEVICE               0x40


////////////////////////////////////////////// VIDEO NONE ////////////////////////////////////////////////
#elif(_VIDEO_CHIP != _VDC_NONE)
    #error  Definitions Code Trapped 

#endif

#if(_VIDEO_CHIP != _VDC_NONE)
#ifndef __VIDEO_CHIP__
#define __VIDEO_CHIP__

/*
 _______________________________________________________________________________________________________________________
|                                                                                                                       |
|                            Function gmi_CVideoCurrentColor() return data explain                                       |
|_______________________________________________________________________________________________________________________|
|\          |             |             |             |          |          |          |          |          |          |
|  \ Return |             |             |             |          |          |          |          |          |          | 
|    \ data |    0x00     |    0x01     |    0x02     |   0x03   |   0x04   |   0x05   |  0x06    |  0x07    |  0x08    |
|VDC   \    |             |             |             |          |          |          |          |          |          |
|  CHIP  \  | (bMode:0/1) | (bMode:0/1) | (bMode:0/1) |(bMode:1) |(bMode:1) |(bMode:1) |(bMode:1) |(bMode:1) |(bMode:1) |
|__________\|_____________|_____________|_____________|__________|__________|__________|__________|__________|__________| 
|           |             |             |             |          |          |          |          |          |          |
| RTD2612/3 | No signal   |    NTSC     |     PAL     | Reserved | Reserved | Reserved | Reserved | Reserved | Reserved |
|___________|_____________|_____________|_____________|__________|__________|__________|__________|__________|__________|
|           |             |             |(bMode:0 PAL)|          |          |          |          |          |          |
| RTD2660   |  Reserved   |    NTSC     |   NTSC4.43  |   PAL-M  |  PAL 60  |  PAL N   |   PAL I  | NTSC 50  |   SECAM  |
|___________|_____________|_____________|_____________|__________|__________|__________|__________|__________|__________|
|           |             |             |             |          |          |          |          |          |          |
|           |             |             |             |          |          |          |          |          |          |
|___________|_____________|_____________|_____________|__________|__________|__________|__________|__________|__________|
*/

extern void gmi_CI2CWriteVDCByte(const unsigned char ucAddress, const unsigned char ucWriteValue);
extern unsigned char gmi_CI2CReadVDCByte(const unsigned char ucAddress);
extern unsigned char gmi_CVideoCurrentColor(bit bMode);
extern void gmi_CInitialVDC(void);
extern void gmi_CVDCOutputDisable(void);
extern bit gmi_CModeLocked(void);
extern void gmi_CSelectInputChannel(unsigned char ucYCrChannel, unsigned char ucAVOut);
extern void gmi_CAdjustVDCBrightness(const unsigned char ucVDCBrightness);
extern void gmi_CAdjustVDCContrast(const unsigned char ucVDCContrast);
extern void gmi_CAdjustVDCSaturation(const unsigned char ucVDCSaturation);
extern void gmi_CAdjustVDCHue(const unsigned char ucVDCHue);
extern void gmi_CSetVDCFreeRunMode(const unsigned char ucMode);

      


#endif
#endif


