//----------------------------------------------------------------------------------------------------
// ID Code      : Mode.h No.0001
// Update Note  :
//
//----------------------------------------------------------------------------------------------------

//--------------------------------------------------
// Definitions of
//--------------------------------------------------


//----------------------------------------------------------------------------------------------------

#ifdef __MODE__

/*

YUV->RGB matrix : (CR9C[4] = 0)

	- CR9C[1] = 0, CR9C[2] = 1,

	R = h00*Y + h01*(Cb-512) + h02*(Cr-512)
	G = h10*Y + h11*(Cb-512) + h12*(Cr-512)
	B = h20*Y + h21*(Cb-512) + h22*(Cr-512)

	- CR9C[1] = 1, CR9C[2] = 1,

	R = h00*(1.164*(Y-64)) + h01*(Cb-512) + h02*(Cr-512)
	G = h10*(1.164*(Y-64)) + h11*(Cb-512) + h12*(Cr-512)
	B = h20*(1.164*(Y-64)) + h21*(Cb-512) + h22*(Cr-512)

RGB->YUV matrix : (CR9C[4] = 1, CR9C[2:1] = 00)

	 Y = h00*R + h01*G + h02*B
	Cb = h10*R + h11*G + h12*B
	Cr = h20*R + h21*G + h22*B

	All ‘h’ coefficients are expressed as 2’s complement with 4-bit signed-extension, 2-bit integer	and 10-bit fractional number. (0x0400 means 1.0)

	When color conversion setting is YUV->RGB (CR9C[4]=0), h00, h10 and h20 is not effective(force to 1.0 internally).

	Integer part is only effective for h02, h21. For other coefficients, integer part must be the same as signed- extension.

	Coefficient Sequence (18-byte) : 

		h00 (High-byte), h00 (Low-byte),  h01 (High-byte), h01 (Low-byte),  h02 (High-byte), h02 (Low-byte),  h10 (High-byte), h10 (Low-byte),  h11 (High-byte),
		h11 (Low-byte),  h12 (High-byte), h12 (Low-byte),  h20 (High-byte), h20 (Low-byte),  h21 (High-byte), h21 (Low-byte),  h22 (High-byte), h22 (Low-byte).

	Default value: h00=0105h,h01=0202,h02=0063h,h10=ff69h,h11=fed8h,h12=01c0h,h20=01c0h,h21=fe89h,h22=ff8h

	0x01,0x05,0x02,0x02,0x00,0x63,
	0xff,0x69,0xfe,0xd8,0x01,0xc0,
	0x01,0xc0,0xfe,0x89,0xff,0x80,
*/

//RGB -> YUV
//RGB Source(OnSource601rgb)		
//REG 9C=0x11
//m_M11 = +0.2990 ;	m_M21 = -0.1687 ;	 m_M31 = +0.5000 ;
//m_M12 = +0.5870 ;	m_M22 = -0.3313 ;	 m_M32 = -0.4187 ;
//m_M13 = +0.1140 ;	m_M23 = +0.5000 ;	 m_M33 = -0.0813 ;
//M11 = 0x01,0x32 	//M12 = 0x02,0x59 	//M13 = 0x00,0x74 
//M21 = 0xFF,0x54 	//M22 = 0xFE,0xAD 	//M23 = 0x02,0x00 
//M31 = 0x02,0x00 	//M32 = 0xFE,0x54 	//M33 = 0xFF,0xAD

/*
	// Europe
    Y'= 0.299*R' + 0.587*G' + 0.114*B'
    Cb=-0.169*R' - 0.331*G' + 0.500*B'
    Cr= 0.500*R' - 0.419*G' - 0.081*B'
*/

BYTE code tRGB2YUV601_TABLE_FOR_RGB_SOURCE[] =
{                   
//20080114***
#if 0

	4,  _NON_AUTOINC,   _YUV2RGB_CTRL_9C,           0x00,	//reset data port addr to 0. 
	4,  _NON_AUTOINC,   _YUV2RGB_CTRL_9C,           0x08,	//enable YVU/RGB coeff access
	21, _NON_AUTOINC,   _YUV_RGB_COEF_DATA_9D,      0x01,0x32,0x02,0x59,0x00,0x74,
													0xFF,0x54,0xFE,0xAD,0x02,0x00,
													0x02,0x00,0xFE,0x54,0xFF,0xAD,
	4,  _NON_AUTOINC,   _YUV2RGB_CTRL_9C,			0x17,		//RGB->YUV & enable

#else

	4,  _NON_AUTOINC,   _YUV2RGB_CTRL_9C,           0x18,
    21, _NON_AUTOINC,   _YUV_RGB_COEF_DATA_9D,      0x01,0x32,0x02,0x59,0x00,0x75,
                                                    0xFF,0x53,0xFE,0xAD,0x02,0x00,
                                                    0x02,0x00,0xFE,0x53,0xFF,0xAD,
    4,  _NON_AUTOINC,   _YUV2RGB_CTRL_9C,           0x17,
	
#endif
//20080114###
    _END
};

//RGB Source(OnSource709rgb)		
//REG 9C=0x11
//m_M11 = 0.2974;	m_M21 = -0.1690;	m_M31 = 0.5000 ;	
//m_M12 = 0.5897;	m_M22 = -0.3310;	m_M32 = -0.4188;	
//m_M13 = 0.1129;	m_M23 = 0.5000;		m_M33 = -0.0812;
//M11 = 0x01,0x30	//M12 = 0x02,0x5B	//M13 = 0x00,0x73 
//M21 = 0xFF,0x53 	//M22 = 0xFE,0xAE 	//M23 = 0x01,0xFF 
//M31 = 0x02,0x00 	//M32 = 0xFE,0x54 	//M33 = 0xFF,0xAD

/*
//m_M11 = 0.2215;	m_M21 = -0.1145;	m_M31 = 0.5016 ;	
//m_M12 = 0.7154;	m_M22 = -0.3855;	m_M32 = -0.4556;	
//m_M13 = 0.0721;	m_M23 = 0.5000;		m_M33 = -0.0459;
//M11 = 0x01,0x30	//M12 = 0x02,0x5B	//M13 = 0x00,0x73 
//M21 = 0xFF,0x53 	//M22 = 0xFE,0xAE 	//M23 = 0x01,0xFF 
//M31 = 0x02,0x00 	//M32 = 0xFE,0x54 	//M33 = 0xFF,0xAD

    Y'= 0.2215*R' + 0.7154*G' + 0.0721*B'
    Cb=-0.1145*R' - 0.3855*G' + 0.5000*B'
    Cr= 0.5016*R' - 0.4556*G' - 0.0459*B'  
*/

BYTE code tRGB2YUV709_TABLE_FOR_RGB_SOURCE[] =
{
	4,  _NON_AUTOINC,   _YUV2RGB_CTRL_9C,             0x00,	//reset data port addr to 0. 
	4,  _NON_AUTOINC,   _YUV2RGB_CTRL_9C,             0x08,	//enable YVU/RGB coeff access
	//21, _NON_AUTOINC,   _YUV_RGB_COEF_DATA_9D,        0x01,0x30,0x02,0x5B,0x00,0x73,
	//												  0xFF,0x53,0xFE,0xAE,0x01,0xFF,
	//												  0x02,0x00,0xFE,0x54,0xFF,0xAD,
	21, _NON_AUTOINC,   _YUV_RGB_COEF_DATA_9D,        0x01,0x30,0x02,0x5B,0x00,0x73,
													  0xFF,0x53,0xFE,0xAE,0x01,0xFF,
													  0x02,0x00,0xFE,0x54,0xFF,0xAD,
	4,  _NON_AUTOINC,   _YUV2RGB_CTRL_9C,			  0x17,		//RGB->YUV & enable
    _END
};

	//!RGB Source(OnSource601rgb)		
	//REG 9C = 0x00
BYTE code tRGB2YUV601_TABLE_FOR_NON_RGB_SOURCE[] =
{
	4,  _NON_AUTOINC,   _YUV2RGB_CTRL_9C,             0x00,	//disable RGB->YUV conv 
    _END
};

	//!RGB Source(OnSource709rgb)		
	//REG 9C = 0x00
BYTE code tRGB2YUV709_TABLE_FOR_NON_RGB_SOURCE[] =
{
	4,  _NON_AUTOINC,   _YUV2RGB_CTRL_9C,             0x00,	//disable RGB->YUV conv 
    _END
};

/*

 Y: S(9,0)./ U(9,0) when CR C0[0]=0
 U, V: S(8,0).
 K11: U(12, 10) 12 bits, 2 bit integer and 10-bit fractional bits. (Default: 0x0400h)
 K13: U(11, 10) 11 bits, 1 bit integer and 10-bit fractional bits (Default: 0x048Fh)
 K22, K23: U(10, 10) 10 bits, all fractional bits (Default: K22: 0x0194h, K23: 0x0252h)
 K32: U(12, 10) 12 bits, 2 bit integer and 10-bit fractional bits (Default: 0x0820h)
 K11’: S(15,4)
 Roffset, Goffset, Boffset: S(14,4) 14 bits, 10 bit signed integer and 4-bit fractional bits. (Default: 0x000h)
 K13’: S(15,4)
 K22’, K23’: S(11,2)
 K32’: S(13,2)
 Rgain, Ggain, Bgain: U(10, 9) 10bits, 1 bit integer and 9-bit fractional bits. (Default: 0x0200h)

*/

//YUV->RGB
	//VGA source
	//page7 0xc0(2) = 0 & 0xc0(3) = 1	 
	//for 601: 
	//0x04, 0x00, // k11
	//0x05, 0x9B, // k13
	//0x01, 0x60, // k22
	//0x02, 0xDB, // k23
	//0x07, 0x16, // k32
	//0x00, 0x00, // R-offset
	//0x00, 0x00, // G-offset
	//0x00, 0x00, // B-offset

/*
    R'= Y' + 0.000*U' + 1.403*V'
    G'= Y' - 0.344*U' - 0.714*V'
    B'= Y' + 1.773*U' + 0.000*V
*/

BYTE code tYUV2RGB601_TABLE_FOR_RGB_SOURCE[] =
{
//20080114***
#if 1 
    4,  _NON_AUTOINC,   _PAGE_SELECT_9F,                _PAGE7,
    4,  _NON_AUTOINC,   _P7_YUV2RGB_CTRL_BF,        	0x02,		//enable YUV->RGB coeff access
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,         	0x0C,0x04,	//K11 MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x1C,0x00,	//K11 LSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x2C,0x05,	//K13 MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x3C,0x9B,	//K13 LSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x4C,0x01,	//K22 MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x5C,0x60,	//K22 LSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x6C,0x02,	//K23 MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x7C,0xDB,	//K23 LSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x8C,0x07,	//K32 MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x9C,0x16,	//K32 LSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xAC,0x00,	//ROffset MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xBC,0x00,	//ROffset LSB	
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xCC,0x00,	//GOffset MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xDC,0x00,	//GOffset LSB	
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xEC,0x00,	//BOffset MSB	
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xFC,0x00,	//GOffset LSB	
    4,  _NON_AUTOINC,   _P7_YUV2RGB_ACCESS_C0,      	0x08,
    4,  _NON_AUTOINC,   _P7_YUV2RGB_CTRL_BF,           	0x01,		//enable YUV->RGB conv
 #else
    4,  _NON_AUTOINC,   _PAGE_SELECT_9F,                _PAGE7,
    4,  _NON_AUTOINC,   _P7_YUV2RGB_CTRL_BF,            0x02,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x0C,0x04,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x1C,0x00,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x2C,0x05,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x3C,0x9B,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x4C,0x01,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x5C,0x56,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x6C,0x02,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x7C,0xDB,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x8C,0x07,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x9C,0x16,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xAC,0x00,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xBC,0x00,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xCC,0x00,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xDC,0x00,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xEC,0x00,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xFC,0x00,
    4,  _NON_AUTOINC,   _P7_YUV2RGB_ACCESS_C0,          0x0c,
    4,  _NON_AUTOINC,   _P7_YUV2RGB_CTRL_BF,            0x01,
 #endif
//20080114###
    _END
};

BYTE code tYUV2RGB601_TABLE_FOR_DVI_SOURCE[] =
{
//20080114***
#if 0 
    4,  _NON_AUTOINC,   _PAGE_SELECT_9F,                _PAGE7,
    4,  _NON_AUTOINC,   _P7_YUV2RGB_CTRL_BF,        	0x02,				//enable YUV->RGB coeff access
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,         	0x0C,0x04,	//K11 MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x1C,0xA7,	//K11 LSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x2C,0x05,	//K13 MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x3C,0x9B,	//K13 LSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x4C,0x01,	//K22 MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x5C,0x60,	//K22 LSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x6C,0x02,	//K23 MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x7C,0xDB,	//K23 LSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x8C,0x07,	//K32 MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x9C,0x16,	//K32 LSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xAC,0x00,	//ROffset MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xBC,0x00,	//ROffset LSB	
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xCC,0x00,	//GOffset MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xDC,0x00,	//GOffset LSB	
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xEC,0x00,	//BOffset MSB	
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xFC,0x00,	//GOffset LSB	
    4,  _NON_AUTOINC,   _P7_YUV2RGB_ACCESS_C0,     		0x0C,
    4,  _NON_AUTOINC,   _P7_YUV2RGB_CTRL_BF,           	0x01,		//enable YUV->RGB conv
 #else
     4,  _NON_AUTOINC,   _PAGE_SELECT_9F,                _PAGE7,
    4,  _NON_AUTOINC,   _P7_YUV2RGB_CTRL_BF,            0x02,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x0C,0x04,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x1C,0x00,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x2C,0x05,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x3C,0x9B,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x4C,0x01,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x5C,0x56,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x6C,0x02,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x7C,0xDB,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x8C,0x07,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x9C,0x16,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xAC,0x00,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xBC,0x00,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xCC,0x00,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xDC,0x00,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xEC,0x00,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xFC,0x00,
    4,  _NON_AUTOINC,   _P7_YUV2RGB_ACCESS_C0,          0x0c,
    4,  _NON_AUTOINC,   _P7_YUV2RGB_CTRL_BF,            0x01,
 #endif
//20080114###
    _END
};

	//!VGA source
	//page7 0xc0(2) = 1 & 0xc0(3) = 1
	//for 601:
	//0x04, 0xA7, // k11
	//0x05, 0x9B, // k13
	//0x01, 0x60, // k22
	//0x02, 0xDB, // k23
	//0x07, 0x16, // k32
	//0x00, 0x00, // R-offset
	//0x00, 0x00, // G-offset
	//0x00, 0x00, // B-offset
BYTE code tYUV2RGB601_TABLE_FOR_NON_RGB_SOURCE[] =
{
    4,  _NON_AUTOINC,   _PAGE_SELECT_9F,                _PAGE7,
    4,  _NON_AUTOINC,   _P7_YUV2RGB_CTRL_BF,            0x02,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x0C,0x04,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x1C,0x00,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x2C,0x05,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x3C,0x9B,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x4C,0x01,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x5C,0x56,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x6C,0x02,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x7C,0xDB,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x8C,0x07,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x9C,0x16,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xAC,0x00,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xBC,0x00,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xCC,0x00,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xDC,0x00,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xEC,0x00,
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xFC,0x00,
    4,  _NON_AUTOINC,   _P7_YUV2RGB_ACCESS_C0,          0x0c,
    4,  _NON_AUTOINC,   _P7_YUV2RGB_CTRL_BF,            0x07,
    _END
};

	//!VGA source
	//page7 0xc0(2) = 1 & 0xc0(3) = 1
	//for 709:
	//0x04, 0xA7, 	// k11
	//0x06, 0x4C, 	// k13
	//0x00, 0xBF, 	// k22
	//0x01, 0xDF, // k23
	//0x07, 0x6C, // k32
	//0x00, 0x00, // R-offset
	//0x00, 0x00, // G-offset
	//0x00, 0x00, // B-offset

/*
    R'= Y' + 0.0000*Cb + 1.5701*Cr
    G'= Y' - 0.1870*Cb - 0.4664*Cr
    B'= Y' - 1.8556*Cb + 0.0000*Cr
*/

BYTE code tYUV2RGB709_TABLE_FOR_NON_RGB_SOURCE[] =
{
    4,  _NON_AUTOINC,   _PAGE_SELECT_9F,                _PAGE7,
    4,  _NON_AUTOINC,   _P7_YUV2RGB_CTRL_BF,        	0x02,				//enable YUV->RGB coeff access
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,         	0x0C,0x04,	//K11 MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x1C,0xA7,	//K11 LSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x2C,0x06,	//K13 MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x3C,0x4C,	//K13 LSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x4C,0x00,	//K22 MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x5C,0xBF,	//K22 LSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x6C,0x01,	//K23 MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x7C,0xDF,	//K23 LSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x8C,0x07,	//K32 MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0x9C,0x6C,	//K32 LSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xAC,0x00,	//ROffset MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xBC,0x00,	//ROffset LSB	
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xCC,0x00,	//GOffset MSB
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xDC,0x00,	//GOffset LSB	
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xEC,0x00,	//BOffset MSB	
    5,  _AUTOINC,       _P7_YUV2RGB_ACCESS_C0,          0xFC,0x00,	//GOffset LSB	
    4,  _NON_AUTOINC,   _P7_YUV2RGB_ACCESS_C0,      	0x0C,
    4,  _NON_AUTOINC,   _P7_YUV2RGB_CTRL_BF,			0x07,				//enable YUV->RGB conv
    _END
};

//--------------------------------------------------
// Global Variables
//--------------------------------------------------
bit bShowOSDCurr = 0;
BYTE idata ucCurrState = _PWOFF_STATE;
BYTE idata ucModeControl = 0;
BYTE idata ucEvent0 = 255;
BYTE idata ucEvent1 = 255;
BYTE idata ucModeFound;
BYTE idata ucHStartBias;
BYTE idata ucVStartBias;
//BYTE idata ucPanelSelect;
WORD xdata HDMI_H_Width;
WORD xdata HDMI_V_Height;


//--------------------------------------------------
// Function Prototypes
//--------------------------------------------------
void CModeHandler(void);
bit CModeMeasureReady(void);
bit CModeMeasureData(void);
bit CModeDetect(void);
bit CModeDetectCommon(void);
bit CModeIsChange(void);
BYTE CModeSearchDisplayMode(void);
BYTE CModeSearchModeVGA(void);
bit CModeComparePresetModeVGA(BYTE ucModeCnt);
BYTE CModeSearchAcceptiveModeVGA(void);
BYTE CModeCheckFIFOModeVGA(BYTE ucModeCnt);
bit CModeCompareFIFOModeVGA(BYTE ucNum, BYTE ucModeCnt);
BYTE CModeSearchModeDVI(void);
bit CModeCompareModeDVI(BYTE ucModeCnt);
bit CModeDisplayActiveMode(void);
bit CModeSetupModeVGA(void);
bit CModeSetupModeDVI(void);
void CModeSetupDisplay(void);
void CModeSetupColorProcess(void);
void CModeSetupColorConversion(void);//jerry20070605
void CModeSetupEtcs(BYTE ucPar);
void CModeGetModeTableInfo(void);
void CModeStartUpVGA(void);
void CModeStartUpDVI(void);
BYTE CModeGetScaleSetting(void);
void CModeSetCaptureWindow(BYTE ucOption);
void CModeSetScaling(BYTE ucOption);
void CModeSetDisplay(BYTE ucOption);
void CModeModifyVTotal(void);
void CModeResetMode(void);
void CModeSetFreeRun(void);
bit CModeConnectIsChange(void);
void CModeAutoMeasureOn(void);
void CModeAutoMeasureOff(void);
void CModeSyncTimeoutCountDownEvent(void);
void CModeStableCountDownEvent(void);

void CModePowerSavingEvent(void);
/*
void CModeNoSignalEvent(void);
void CModeNoCableEvent(void);
void CModeNoSupportEvent(void);
*/
BYTE CModeGetScaleSetting(void);
void CModeHDMITimeoutCountDownEvent();
void CModeInterlaceCheck(void);//v003_interlace_check
void CModeDeInterlaceSetting(void);

void CModeNoSupportEvent(void);
void CModeNoSignalEvent(void);
void CModeNoCableEvent(void);

void CAccAdjust (BYTE mode);

#else

//--------------------------------------------------
// Extern Global Variables
//--------------------------------------------------
extern bit bShowOSDCurr;
extern BYTE idata ucCurrState;
extern BYTE idata ucModeControl;
extern BYTE idata ucHStartBias;
extern BYTE idata ucVStartBias;
//extern BYTE idata ucPanelSelect;
extern UINT16 xdata HDMI_H_Width,HDMI_V_Height;
extern BYTE idata ucModeFound;
extern BYTE idata ucEvent1;


//--------------------------------------------------
// Extern Function Prototypes
//--------------------------------------------------
extern void CModeHandler(void);
extern bit CModeMeasureReady(void);
extern bit CModeMeasureData(void);
extern bit CModeDetect(void);
extern bit CModeIsChange(void);
extern void CModeSetScaling(BYTE ucOption);
extern void CModeResetMode(void);
extern void CModeSetFreeRun(void);
extern void CModeSyncTimeoutCountDownEvent(void);
extern void CModeStableCountDownEvent(void);
extern void CModeSetupDisplay(void);
extern void CModeSetupColorProcess(void);
extern void CModeSetupColorConversion(void);//jerry20070605
extern void CModeSetupEtcs(BYTE ucPar);
extern void CModeStartUpVGA(void);
extern void CModeAutoMeasureOn(void);
extern void CModeAutoMeasureOff(void);
extern bit CModeDisplayActiveMode(void);
extern bit CModeConnectIsChange(void);
extern void CModePowerSavingEvent(void);
extern BYTE CModeGetScaleSetting(void);
extern bit CModeSetupModeVGA(void);
extern void CModeHDMITimeoutCountDownEvent();
extern void CModeInterlaceCheck(void);//v003_interlace_check
extern void CModeDeInterlaceSetting(void);
extern void CModeSetCaptureWindow(BYTE ucOption);
extern void CModeSetDisplay(BYTE ucOption);


extern void CModeNoSupportEvent(void);
extern void CModeNoSignalEvent(void);
extern void CModeNoCableEvent(void);

extern void CAccAdjust (BYTE mode);

#if (_HDMI_HOT_PLUG_OPTION == _ENABLE)   //2007-8-23 15:36
//eric 20070315
	void CModeHdmiHP(void);
//eric 20070315
	extern void CModeHdmiHP(void);
#endif
#endif


//--------------------------------------------------
// Macro of Sync Processor Measure Ready Flag
//--------------------------------------------------
#define GET_VIDEOMODECHANGE()       (bit)(ucInputSyncType & _BIT6)
#define SET_VIDEOMODECHANGE()       ucInputSyncType |= _BIT6
#define CLR_VIDEOMODECHANGE()       ucInputSyncType &= ~_BIT6

//--------------------------------------------------
// Macro of Start Display for OSD Flow
//--------------------------------------------------

#define GET_SHOW_NO_SIGNAL()        (bit)(ucModeControl & _BIT0)
#define SET_SHOW_NO_SIGNAL()        ucModeControl |= _BIT0
#define CLR_SHOW_NO_SIGNAL()        ucModeControl &= ~_BIT0

#define GET_OSD_READYFORDISPLAY()   (bit)(ucModeControl & _BIT1)
#define SET_OSD_READYFORDISPLAY()   ucModeControl |= _BIT1
#define CLR_OSD_READYFORDISPLAY()   ucModeControl &= ~_BIT1

//--------------------------------------------------
// Macro of Mode Stable Flag
//--------------------------------------------------
#define GET_MODESTABLE()            ((bit)(ucModeControl & _BIT2))
#define SET_MODESTABLE()            (ucModeControl |= _BIT2)
#define CLR_MODESTABLE()            (ucModeControl &= ~_BIT2)

//--------------------------------------------------
// Macro of Frame Sync Status
//--------------------------------------------------
#define GET_FRAMESYNCSTATUS()       ((bit)(ucModeControl & _BIT3))
#define SET_FRAMESYNCSTATUS()       (ucModeControl |= _BIT3)
#define CLR_FRAMESYNCSTATUS()       (ucModeControl &= ~_BIT3)

//--------------------------------------------------
// Macro of Start Display for show note flag  // add by eric 20070718
//--------------------------------------------------
#define GET_FIRST_SHOW_NOTE()       (bit)(ucModeControl & _BIT4)
#define SET_FIRST_SHOW_NOTE()        ucModeControl |= _BIT4
#define CLR_FIRST_SHOW_NOTE()        ucModeControl &= ~_BIT4

#define GET_CLEAR_OSD_EN()          (bit)(ucModeControl & _BIT5)
#define SET_CLEAR_OSD_EN()          ucModeControl |= _BIT5
#define CLR_CLEAR_OSD_EN()          ucModeControl &= ~_BIT5

//--------------------------------------------------
// Macro of Start Display
//--------------------------------------------------
#define GET_READYFORDISPLAY()       ((bit)(ucModeControl & _BIT7))
#define SET_READYFORDISPLAY()       (ucModeControl |= _BIT7)
#define CLR_READYFORDISPLAY()       (ucModeControl &= ~_BIT7)

//--------------------------------------------------
// Macro of Color Temperature
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE()        (stSystemData.ColorTemp & (_BIT3 | _BIT2 | _BIT1 | _BIT0))
#define SET_COLOR_TEMP_TYPE(x)       (stSystemData.ColorTemp = ((stSystemData.ColorTemp & ~(_BIT3 | _BIT2 | _BIT1 | _BIT0)) | x))


//----------------------------------------------------------------------------------------------------

