/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2005
  * All rights reserved.
  * ============================================ */

#ifndef _VBI_H_
#define _VBI_H_
#if (_VBI_ENABLE)

/*======================== CONSTANTS =========================================*/
#define CCBuffer_Size 2//10//80

#ifdef _VBI_C
    #define EXTERN
#else
    #define EXTERN   extern
#endif

#if(_VBI_INTERRUPT)
EXTERN unsigned char xdata  CCBuffer[2/*10*//*80*/][2];	//VBI_INTERRUPT
EXTERN unsigned char xdata	ucCCWriteCnt;		//VBI_INTERRUPT
EXTERN unsigned char xdata 	ucCCReadCnt;		//VBI_INTERRUPT
EXTERN bit bCCReceiveOK;						//VBI_INTERRUPT
#endif


EXTERN unsigned char xdata 	ucCC_VSyncCnt;	
EXTERN BIT bVBI_INT_Enable;
EXTERN BIT bVideoStable;
EXTERN BIT bYPbPrStable;
EXTERN BIT bVCRStalbe;
EXTERN BIT bCCDecodeStalbe;
EXTERN BIT bNotify_Timer1_VBI_Int;

#undef EXTERN

#if (_VBI_INTERRUPT)
void ClearVerLineCompSts(void);
#endif
void CVbiInitial(void);
#endif

#endif 

