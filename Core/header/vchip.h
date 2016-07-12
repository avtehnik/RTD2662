/*=============================================================
 * Copyright (c)	  Realtek Semiconductor Corporation, 2005 *
 * All rights reserved. 									  *
 *============================================================*/

/*======================= Description ========================*/
/**
 * @file
 * A brief decription of thie file.
 * A detail decription of thie file.
 * @Author yourname
 * @date { date description }
 * @version { version number }
 *
 * @Note									 (optional)
 * This note consists of two paragraphs.
 * This is the first paragraph.
 *
 * @par
 * And this is the second paragraph.
 *
 * @todo { paragraph describing what is to be done }  (optional)
 *
 * @warning { warning message } 			 (optional)
 *
 * @bug { bug description } 				 (optional)
 *
 * More normal text if needed.  			 (optional)
 */

/*=============================================================*/
//#ifdef	CONFIG_TV_NTSC

#ifndef _VCHIP_H
#define _VCHIP_H
/*==============================================================================
	Copyright (C) 2004-2005 Realtek Semiconductor Corp.
	All rights reserved.
==============================================================================*/

/*=== DESCRIPTION ============================================================*/
/**
 * @file Vchip.h
 * @brief Header file of V-chip function.
 * @author  	 Bill Tsai
 * @date		 2005/01/24
 * @version 	 0.01
 */

/*=== EXTERNAL DEPENDENCY ====================================================*/

/*=== CONSTANTS ==============================================================*/

/*=== MACROS =================================================================*/

/*=== TYPES ==================================================================*/

#ifdef CONFIG_VBI_VCHIP
/**
 * total class of XDS
 */
typedef enum {
	XDSC_None = 0x00,
	XDSC_CurrentStart = 0x01,
	XDSC_CurrentCont = 0x02,
	XDSC_FutureStart = 0x03,
	XDSC_FutureCont = 0x04,
	XDSC_ChannelStart = 0x05,
	XDSC_ChannelCont = 0x06,
	XDSC_MiscStart = 0x07,
	XDSC_MiscCont = 0x08,
	XDSC_PublicStart = 0x09,
	XDSC_PublicCont = 0x0A,
	XDSC_ReservedStart = 0x0B,
	XDSC_ReservedCont = 0x0C,
	XDSC_PrivateStart = 0x0D,
	XDSC_PrivateCont = 0x0E,
	XDSC_End = 0x0F
}eXDS_Class;

/**
 * type of current class
 */
typedef enum {
	XDST_None = 0x00,
	XDST_ID = 0x01,
	XDST_Time = 0x02,
	XDST_Title = 0x03,
	XDST_Type = 0x04,
	XDST_Advisory = 0x05,
	XDST_Audio = 0x06,
	XDST_Caption = 0x07,
	XDST_Analog = 0x08,
	XDST_AspectRatio = 0x09
}eXDS_C1Type;

/**
 * type of content advisory
 */
typedef enum {
	XDSA_None = 0x00,
	XDSA_MPA = 0x01,
	XDSA_USTV = 0x02,
	XDSA_CaEn = 0x03,
	XDSA_CaFr = 0x04,
	XDSA_Reserved = 0x05,
	XDSA_Total
}eXDS_Advisory;

/**
 * MPA rating
 */
typedef enum {
	XDSMPA_None = 0x00,
	XDSMPA_G = 0x01,
	XDSMPA_PG = 0x02,
	XDSMPA_PG13 = 0x03,
	XDSMPA_R = 0x04,
	XDSMPA_NC17 = 0x05,
	XDSMPA_X = 0x06,
	XDSMPA_NotRated = 0x07
}eXDS_MPARating;



/**
 * US TV rating
 */
typedef enum {
	XDSUSTV_None = 0x00,
	XDSUSTV_Y = 0x01,
	XDSUSTV_Y7 = 0x02,
	XDSUSTV_G = 0x03,
	XDSUSTV_PG = 0x04,
	XDSUSTV_14 = 0x05,
	XDSUSTV_MA = 0x06,
	XDSUSTV_NotRated = 0x07
}eXDS_USTVRating;

/**
 * Canadian English rating
 */
typedef enum {
	XDSCAEN_E = 0x00,
	XDSCAEN_C = 0x01,
	XDSCAEN_C8p = 0x02,
	XDSCAEN_G = 0x03,
	XDSCAEN_PG = 0x04,
	XDSCAEN_14p = 0x05,
	XDSCAEN_18p = 0x06,
	XDSCAEN_NotRated = 0x07
}eXDS_CaEnRating;

/**
 * Canadian French rating
 */
typedef enum {
	XDSCAFR_E = 0x00,
	XDSCAFR_G = 0x01,
	XDSCAFR_8p = 0x02,
	XDSCAFR_13p = 0x03,
	XDSCAFR_16p = 0x04,
	XDSCAFR_18p = 0x05,
	XDSCAFR_NotRated1 = 0x06,
	XDSCAFR_NotRated2 = 0x07
}eXDS_CaFrRating;

/**
 * A XDS Module
 */
typedef struct _XDSMODULE {
	eXDS_Class CurrClass;   	// current class
	eXDS_C1Type CurrType;   	// current type
	eXDS_Class PrevClass;   	// previous class
	eXDS_C1Type PrevType;   	// previous type
	eXDS_Advisory CurrAdvisory; // current rating system
	UINT8 CurrRating;   		// current rating
	eXDS_Advisory PrevAdvisory; // current rating system
	UINT8 PrevRating;   		// current rating
}tXDS_Module;

/*=== VARIABLES ==============================================================*/
#ifdef _VCHIP_C
#define EXTERN
#else
#define EXTERN   extern
#endif  								/* def _VCHIP_C */

EXTERN BIT VchipBlockStatus;		// blocking status
EXTERN BIT bVchip_CanInitial;

EXTERN UINT8 Vchip_TimeCnt;
EXTERN tXDS_Module xdata VchipM;  // hill added
EXTERN BIT bitFlag;

#undef EXTERN

/*=== FUNCTIONS ==============================================================*/
void Vchip_Init(void);   // Init Vchip module
void Vchip_ParseXDSCmd(UINT8 data1, UINT8 data2); // Parse XDS command
void Vchip_InsertCharacterFunction(UINT8 data1, UINT8 data2); // Insert character
BIT Vchip_CheckBlocking(void);// blocking display
BIT Vchip_NeedBlocking(void); // Compare rating
#endif
#endif 
