
#define _DISPLAY_RATIO            _DISABLE

#ifdef __RTDACCESS__
//__SCALER__

//--------------------------------------------------
// Panel Style : 
//(_PANEL_TTL / _PANEL_HZ / _PANEL_LVDS / _PANEL_RSDS) |
//_AUTOCALC_PIXCLK |
//(_LVDS_MAP1 / _LVDS_MAP2) | 
//(_DISP_24_BIT / _DISP_18_BIT) |
//_RSDS_GC_SWAP |
//_RSDS_HL_SWAP |
//_RSDS_PN_SWAP |


//--------------------------------------------------
// Panel Configuration :
//_DHS_MASK |
//_DISP_EO_SWAP |
//_DISP_RB_SWAP |
//_DISP_ML_SWAP |
//(_DISP_SINGLE_PORT / _DISP_DOUBLE_PORT) |
//_DVS_INVERT |
//_DHS_INVERT |
//_DEN_INVERT,

//--------------------------------------------------
// 800x600
code PanelType Panel0 =
{
	// Panel Style
    _PANEL_LVDS |		//_PANEL_TTL,_PANEL_HZ,_PANEL_LVDS,_PANEL_RSDS
    //_AUTOCALC_PIXCLK |
    _LVDS_MAP2 |		//_LVDS_MAP1,_LVDS_MAP2
    _DISP_18_BIT | 		//_DISP_24_BIT,_DISP_18_BIT
    //_RSDS_GC_SWAP |
    //_RSDS_HL_SWAP |
    //_RSDS_PN_SWAP |
    0x00,                            

	// Panel Configuration
	//_DHS_MASK |
	//_DISP_EO_SWAP |
	//_DISP_RB_SWAP |
	//_DISP_ML_SWAP |
	_DISP_SINGLE_PORT |	//_DISP_SINGLE_PORT,_DISP_DOUBLE_PORT
	//_DVS_INVERT |
	//_DHS_INVERT |
	//_DEN_INVERT |
	0x00,


	32,         // Display Horizontal Start Position
	800,       // Display Horizontal Width

	1052,       // Display Horizontal Total Clock Number in One Display Line

	852,       // Display Horizontal Total Clock Number in One Display Line for CVBS PAL
	952,       // Display Horizontal Total Clock Number in One Display Line for CVBS NTSC

	32,         // Display Vertical Start Position
	600,       // Display Vertical Height

	850,       // Display Vertical Total Line Number in One Frame

	16,         // Display H Sync Width
	3,          // Display V Sync Height

	75,         // Typical Pixel Clock in MHz

	1100,		// H Sync Max Freq Unit in 0.1 kHZ
	100,		// H Sync Min Freq Unit in 0.1 kHZ
	880,		// V Sync Max Freq Unit in 0.1 HZ
	490,		// V Sync Min Freq Unit in 0.1 HZ

    // TTL setting   
    //(2 << 4) |  // Delay
    //(1 << 1) |  // DCLK output enable
    0x00,         // DCLK Polarity

};

//--------------------------------------------------
//1024x768
code PanelType Panel1 =
{
	// Panel Style
    _PANEL_LVDS |		//_PANEL_TTL,_PANEL_HZ,_PANEL_LVDS,_PANEL_RSDS
    //_AUTOCALC_PIXCLK |
    _LVDS_MAP2 |		//_LVDS_MAP1,_LVDS_MAP2
    _DISP_18_BIT | 		//_DISP_24_BIT,_DISP_18_BIT
    //_RSDS_GC_SWAP |
    //_RSDS_HL_SWAP |
    //_RSDS_PN_SWAP |
    0x00,                            

	// Panel Configuration
	//_DHS_MASK |
	//_DISP_EO_SWAP |
	//_DISP_RB_SWAP |
	//_DISP_ML_SWAP |
	_DISP_SINGLE_PORT |	//_DISP_SINGLE_PORT,_DISP_DOUBLE_PORT
	//_DVS_INVERT |
	//_DHS_INVERT |
	//_DEN_INVERT |
	0x00,


	32,         // Display Horizontal Start Position
	1024,       // Display Horizontal Width

	1452,       // Display Horizontal Total Clock Number in One Display Line

	1452,       // Display Horizontal Total Clock Number in One Display Line for CVBS PAL
	1380,       // Display Horizontal Total Clock Number in One Display Line for CVBS NTSC

	12,         // Display Vertical Start Position
	768,       // Display Vertical Height

	852,       // Display Vertical Total Line Number in One Frame

	16,         // Display H Sync Width
	3,          // Display V Sync Height

	75,         // Typical Pixel Clock in MHz

	1100,		// H Sync Max Freq Unit in 0.1 kHZ
	100,		// H Sync Min Freq Unit in 0.1 kHZ
	880,		// V Sync Max Freq Unit in 0.1 HZ
	490,		// V Sync Min Freq Unit in 0.1 HZ

    // TTL setting   
    //(2 << 4) |  // Delay
    //(1 << 1) |  // DCLK output enable
    0x00,         // DCLK Polarity

};

//--------------------------------------------------
//1280x800
code PanelType Panel2 =
{
	// Panel Style
    _PANEL_LVDS |		//_PANEL_TTL,_PANEL_HZ,_PANEL_LVDS,_PANEL_RSDS
    //_AUTOCALC_PIXCLK |
    _LVDS_MAP2 |		//_LVDS_MAP1,_LVDS_MAP2
    _DISP_18_BIT | 		//_DISP_24_BIT,_DISP_18_BIT
    //_RSDS_GC_SWAP |
    //_RSDS_HL_SWAP |
    //_RSDS_PN_SWAP |
    0x00,                            

	// Panel Configuration
	//_DHS_MASK |
	//_DISP_EO_SWAP |
	//_DISP_RB_SWAP |
	//_DISP_ML_SWAP |
	_DISP_SINGLE_PORT |	//_DISP_SINGLE_PORT,_DISP_DOUBLE_PORT
	//_DVS_INVERT |
	//_DHS_INVERT |
	//_DEN_INVERT |
	0x00,


	32,         // Display Horizontal Start Position
	1280,       // Display Horizontal Width

	1652,       // Display Horizontal Total Clock Number in One Display Line

	1652,       // Display Horizontal Total Clock Number in One Display Line for CVBS PAL
	1652,       // Display Horizontal Total Clock Number in One Display Line for CVBS NTSC

	12,         // Display Vertical Start Position
	800,       // Display Vertical Height

	952,       // Display Vertical Total Line Number in One Frame

	16,         // Display H Sync Width
	3,          // Display V Sync Height

	75,          // Typical Pixel Clock in MHz

	1100,		// H Sync Max Freq Unit in 0.1 kHZ
	100,		// H Sync Min Freq Unit in 0.1 kHZ
	880,		// V Sync Max Freq Unit in 0.1 HZ
	490,		// V Sync Min Freq Unit in 0.1 HZ

    // TTL setting   
    //(2 << 4) |  // Delay
    //(1 << 1) |  // DCLK output enable
    0x00,         // DCLK Polarity

};

//--------------------------------------------------
//1440x1050
code PanelType Panel3 =
{
	// Panel Style
    _PANEL_LVDS |		//_PANEL_TTL,_PANEL_HZ,_PANEL_LVDS,_PANEL_RSDS
    //_AUTOCALC_PIXCLK |
    _LVDS_MAP2 |		//_LVDS_MAP1,_LVDS_MAP2
    _DISP_18_BIT | 		//_DISP_24_BIT,_DISP_18_BIT
    //_RSDS_GC_SWAP |
    //_RSDS_HL_SWAP |
    //_RSDS_PN_SWAP |
    0x00,                            

	// Panel Configuration
	//_DHS_MASK |
	//_DISP_EO_SWAP |
	//_DISP_RB_SWAP |
	//_DISP_ML_SWAP |
	_DISP_DOUBLE_PORT |	//_DISP_SINGLE_PORT,_DISP_DOUBLE_PORT
	//_DVS_INVERT |
	//_DHS_INVERT |
	//_DEN_INVERT |
	0x00,


	32,         // Display Horizontal Start Position
	1440,       // Display Horizontal Width

	1660,       // Display Horizontal Total Clock Number in One Display Line

	1660,       // Display Horizontal Total Clock Number in One Display Line for CVBS PAL
	1660,       // Display Horizontal Total Clock Number in One Display Line for CVBS NTSC

	16,         // Display Vertical Start Position
	1050,        // Display Vertical Height

	1152,       // Display Vertical Total Line Number in One Frame

	12,         // Display H Sync Width
	3,          // Display V Sync Height

	90,         // Typical Pixel Clock in MHz

	1100,		// H Sync Max Freq Unit in 0.1 kHZ
	100,		// H Sync Min Freq Unit in 0.1 kHZ
	880,		// V Sync Max Freq Unit in 0.1 HZ
	490,		// V Sync Min Freq Unit in 0.1 HZ

    // TTL setting   
    //(2 << 4) |  // Delay
    //(1 << 1) |  // DCLK output enable
    0x00,         // DCLK Polarity

};

//--------------------------------------------------
//1680x1050
code PanelType Panel4 =
{
	// Panel Style
    _PANEL_LVDS |		//_PANEL_TTL,_PANEL_HZ,_PANEL_LVDS,_PANEL_RSDS
    //_AUTOCALC_PIXCLK |
    _LVDS_MAP1 |//_LVDS_MAP1 |		//_LVDS_MAP1,_LVDS_MAP2
    _DISP_24_BIT | 		//_DISP_24_BIT,_DISP_18_BIT
    //_RSDS_GC_SWAP |
    //_RSDS_HL_SWAP |
    //_RSDS_PN_SWAP |
    0x00,                            

	// Panel Configuration
	//_DHS_MASK |
	//_DISP_EO_SWAP |
	//_DISP_RB_SWAP |
	//_DISP_ML_SWAP |
	_DISP_DOUBLE_PORT |	//_DISP_SINGLE_PORT,_DISP_DOUBLE_PORT
	//_DVS_INVERT |
	_DHS_INVERT |
	//_DEN_INVERT |
	0x00,


	32,         // Display Horizontal Start Position
	1680,       // Display Horizontal Width

	1850,       // Display Horizontal Total Clock Number in One Display Line

	1850,       // Display Horizontal Total Clock Number in One Display Line for CVBS PAL
	1850,       // Display Horizontal Total Clock Number in One Display Line for CVBS NTSC

	16,         // Display Vertical Start Position
	1050,       // Display Vertical Height

	1100,       // Display Vertical Total Line Number in One Frame

	16,         // Display H Sync Width
	3,          // Display V Sync Height

	165,        // Typical Pixel Clock in MHz

	1100,		// H Sync Max Freq Unit in 0.1 kHZ
	100,		// H Sync Min Freq Unit in 0.1 kHZ
	880,		// V Sync Max Freq Unit in 0.1 HZ
	490,		// V Sync Min Freq Unit in 0.1 HZ


    // TTL setting   
    //(2 << 4) |  // Delay
    //(1 << 1) |  // DCLK output enable
    0x00,         // DCLK Polarity

};

//--------------------------------------------------
// Select panel
BYTE idata ucPanelSelect = 3;


//--------------------------------------------------
code PanelType *Panel[] = 
{
     &Panel0, // 800x600
     &Panel1, // 1024x768
     &Panel2, // 1280x800
     &Panel3, // 1440x1050
     &Panel4, // 1680x1050
};

//--------------------------------------------------
BYTE code g_ucPanelCnt = sizeof(Panel)/3;

#if(_VGA_EDID)
BYTE code tVGA_EDID_DATA[] =
{
    0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x4a,0x8b,0x00,0x00,0x01,0x01,0x01,0x01,
    0x1e,0x0c,0x01,0x01,0x0e,0x24,0x1b,0x78,0xe8,0x8a,0x01,0x9a,0x58,0x52,0x8b,0x28,
    0x1e,0x50,0x54,0xff,0xff,0x80,0x61,0x40,0x61,0x4f,0x61,0x59,0x71,0x4f,0x81,0x40,
    0x81,0x59,0x81,0x99,0xa9,0x40,0x00,0x00,0x00,0xfc,0x00,0x31,0x37,0x27,0x27,0x20,
    0x4c,0x43,0x44,0x0a,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xfc,0x00,0x4d,0x6f,0x6e,
    0x69,0x74,0x6f,0x72,0x0a,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xfd,0x00,0x2b,
    0x55,0x14,0x5c,0x0e,0x00,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xff,
    0x00,0x30,0x30,0x30,0x30,0x30,0x31,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0xbd,
};
#endif

#if(_DVI_EDID)
BYTE code tDVI_EDID_DATA[] =
{
    0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x26,0xCD,0x68,0x46,0x00,0x00,0x00,0x00,
    0x23,0x0c,0x01,0x03,0x81,0x24,0x1D,0x78,0xeF,0x0D,0xC2,0xa0,0x57,0x47,0x98,0x27,
    0x12,0x48,0x4F,0xBF,0xEF,0x00,0x81,0x80,0x81,0x8F,0x61,0x40,0x61,0x59,0x45,0x40,
    0x45,0x59,0x31,0x40,0x31,0x59,0xBC,0x34,0x00,0x98,0x51,0x00,0x2A,0x40,0x10,0x90,
    0x13,0x00,0x68,0x22,0x11,0x00,0x00,0x1e,0x00,0x00,0x00,0xFF,0x00,0x30,0x0A,0x20,
    0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xFC,0x00,0x41,
    0x53,0x34,0x36,0x33,0x37,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xFD,
    0x00,0x38,0x55,0x18,0x50,0x0E,0x00,0x0A,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x06,
};
#endif


#else	// else of . #ifdef __MAIN__


extern code PanelType *Panel[];
extern BYTE code g_ucPanelCnt;
extern BYTE code tVGA_EDID_DATA[];
extern BYTE code tDVI_EDID_DATA[];
extern BYTE idata ucPanelSelect;

#endif	// endif of . #ifdef __MAIN__




