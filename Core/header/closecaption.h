/*===========================================================
 * Copyright (c)      Realtek Semiconductor Corporation, 2005
 * All rights reserved.
 * ========================================================== */

/*==================== File Description ===================== */
/**
 * @file
 * 	This file is for mode related functions.
 *
 * @author 	$Author: Dgoetz $
 * @date 	$Date: 1/27/15 8:12p $
 * @version 	$Revision: 1 $
 * @ingroup vbi
 */

/**
 * @addtogroup vbi
 * @{
 */

#ifndef _CLOSECAPTION_H_
#define _CLOSECAPTION_H_

/*===================== Module dependency  ================== */
//#include "main_def.h"

#if defined(CONFIG_VBI_ENABLE)

//#include "vbi.h"

/*======================== CONSTANTS =========================================*/
#define _Cc1Mode _BIT0
#define _Cc2Mode _BIT1
#define _Cc3Mode _BIT4
#define _Cc4Mode _BIT5
#define _T1Mode _BIT2
#define _T2Mode _BIT3
#define _T3Mode _BIT6
#define _T4Mode _BIT7


#define _VBI_FLASH_ON	_FALSE
#define _ROWS_16			0
#define _ROWS_32			1
#define _ROWS_NO_TYPE		_ROWS_16	//jerry0413A
#define _DER_COMMAND		_FALSE	//  _TRUE  : Enable "delete to end of row(der)" command
                                	//  _FALSE : Disable "delete to end of row(der)" command
#define _TEXT_RESTART		_TRUE	//  _TRUE  : Enable "text restart/resume text display" function
                                	//  _FALSE : Disable "text restart/resume text display" function(Dell-Type)
#define _LR_COL_MORE_PIXEL	_TRUE	//	_TRUE  : Enable Left/Right Column More Pixel
									//	_FALSE : Disable Left/Right Column More Pixel
/*======================== MACROS ============================================*/
#define Variable_BitValue(VARIABLE, BIT_POSITION) ((VARIABLE >> BIT_POSITION) & 0x01)
#define Variable_BitSet(VARIABLE, BIT_POSITION)  (VARIABLE |= (0x01 << BIT_POSITION))
#define Variable_BitClear(VARIABLE, BIT_POSITION) (VARIABLE &= (~(0x01 << BIT_POSITION)))

/*======================== TYPES =============================================*/

/*======================== VARIABLES =========================================*/
#ifdef _CLOSECAPTION_C
    #define EXTERN
#else
    #define EXTERN   extern
#endif                                  /* def _MODULE_C */

EXTERN UINT8 CCSystemState;
EXTERN UINT8 CaptionMode;
EXTERN unsigned char xdata	CC_System_Mode;		//VBI_ENABLE(osd)
EXTERN bit bCCInterrupt;						//VBI_INTERRUPT
extern bit bCcStartFlag;
#undef EXTERN

/*======================== FUNCTIONS =========================================*/

void CCcSetSystemMode(void);

/*==================== Function  Prototypes ==================*/
/**
 * This function shall initialize the related VBI variables, including color palette,
 * screen memory, display memory.
 *
 *
 * @param 	None
 *
 * @return	None
 *
 * @ingroup 	vbi
 */
void CCcInitVariables(void);

#if 0
/*==================== Function  Prototypes ==================*/
/**
 * This function shall set the scroll row index table.
 *
 *
 * @param 	mode 	if mode == 1, scroll row; else reset(not scroll)
 *
 * @return	None
 *
 * @ingroup 	vbi
 */
void CVbiScrollRowIndexTable(unsigned char mode);

/*==================== Function  Prototypes ==================*/
/**
 * This function shall set the scroll row index table.
 *
 *
 * @param 	None
 *
 * @return	None
 *
 * @ingroup 	vbi
 */
void CVbiCcScrollRowOnTimer(void);	//jerry0413B

/*==================== Function  Prototypes ==================*/
/**
 * This function shall set the VBI system mode to CC1, CC2, CC3, CC4,
 * T1, T2, T3, or T4
 *
 *
 * @param 	None
 *
 * @return	None
 *
 * @ingroup 	vbi
 */
void CVbiSetCCSystemMode(void);
#endif

/*==================== Function  Prototypes ==================*/
/**
 * This function shall initialize the VBI module including screen and display memories.
 *
 *
 * @param 	None
 *
 * @return	None
 *
 * @ingroup 	vbi
 */
void CCcInitial(void);

/*==================== Function  Prototypes ==================*/
/**
 * This function shall execute the VBI decode engine to parsing closecaption or teltext
 * control words and strings..
 *
 *
 * @param 	None
 *
 * @return	None
 *
 * @ingroup 	vbi
 */
void CCcDecoder(void);

/*==================== Function  Prototypes ==================*/
/**
 * This function enables the VBI module.
 *
 *
 * @param 	None
 *
 * @return	None
 *
 * @ingroup 	vbi
 */
void CCcEnable(void);

/*==================== Function  Prototypes ==================*/
/**
 * This function disables the VBI module.
 *
 *
 * @param 	None
 *
 * @return	None
 *
 * @ingroup 	vbi
 */
void CCcDisable(void);
#else
#define CVbiDecoder()

#endif // VBI_ENABLE
#endif // _CLOSECAPTION_H_


/**
*
* @}
*/


