//----------------------------------------------------------------------------------------------------
// ID Code      : HdmiModeTable.h No.0000
// Update Note  : 
//
//----------------------------------------------------------------------------------------------------

//--------------------------------------------------
// Mode Define
// We have two kind of mode set. One is Preset mode 
// and another is User mode. If you have to add a new
// mode, please add it into "Preset Mode" and modify
// the defination of _MAX_PRESET_MODE.
//--------------------------------------------------
#define _MAX_HDMI_PRESET_MODE            56
/*

#define _MODE_FIRST                 252
#define _MODE_EXIST                 253
#define _MODE_NOSUPPORT             254
#define _MODE_NOSIGNAL              255
*/

//--------------------------------------------------
// Hdmi Preset Mode
//--------------------------------------------------
/*
enum HdmiPresetModeDef
{
    _MODE_640x480P_60HZ = 0,        // Mode 00:
    _MODE_720x240P_60HZ,            // Mode 01:
    _MODE_720x288P_50HZ,            // Mode 02:
    _MODE_720x480P_60HZ,            // Mode 03:
    _MODE_720x480I_60HZ,            // Mode 04:
    _MODE_720x576P_50HZ,            // Mode 05:
    _MODE_720x576I_50HZ,            // Mode 06:
    _MODE_1280x720P_50HZ,           // Mode 07:
    _MODE_1280x720P_60HZ,           // Mode 08:
    _MODE_1440x480P_60HZ,           // Mode 09:
    _MODE_1440x576P_50HZ,           // Mode 10:
    _MODE_1920x1080P_50HZ,          // Mode 11:
    _MODE_1920x1080P_60HZ,          // Mode 12:
    _MODE_1920x1080I_50HZ,          // Mode 13:
    _MODE_1920x1080I_60HZ,          // Mode 14:
    _MODE_2880x240P_60HZ,           // Mode 15:
    _MODE_2880x288P_50HZ,           // Mode 16:
    _MODE_2880x480I_60HZ,           // Mode 17:
    _MODE_2880x576I_50HZ,           // Mode 18:
};
*/
/*
//--------------------------------------------------
// Defination of Mode Detection Tolerance
//--------------------------------------------------
#define _HFREQ_TOLERANCE            10      // kHz. Ex: 1.5kHz ==> 15
#define _VFREQ_TOLERANCE            10      // Hz.  Ex: 1.5Hz ==> 15


//--------------------------------------------------
// Defination of Mode Polarity
//--------------------------------------------------
#define _SYNC_HN_VN                 0x01
#define _SYNC_HP_VN                 0x02
#define _SYNC_HN_VP                 0x04
#define _SYNC_HP_VP                 0x08
*/

#ifdef __MAIN__

#if(_DISP_INFO_BY_MODE == _ON)

DisplayTableType code tDISPLAY_PRESET_TABLE[_MAX_PRESET_MODE] =
{
    //--------------------------------------------------
    // Preset Modes
    //--------------------------------------------------
    {   // Mode 0 : 640 x 350 x 70 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 1 : 640 x 350 x 85 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 2 : 720 x 400 x 70 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 3 : 720 x 400 x 85 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 4 : 640 x 480 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 5 : 640 x 480 x 66 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 6 : 640 x 480 x 72 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 7 : 640 x 480 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 8 : 640 x 480 x 85 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 9 : 800 x 600 x 56 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 10 : 800 x 600 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 11 : 800 x 600 x 72 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 12 : 800 x 600 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 13 : 800 x 600 x 85 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 14 : 832 x 624 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 15 : 1024 x 768 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 16 : 1024 x 768 x 70 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 17 : 1024 x 768 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 18 : 1024 x 768 x 85 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 19 : 1024 x 800 x 73 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 20 : 1024 x 800 x 85 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 21 : 1152 x 864 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 22 : 1152 x 864 x 70 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 23 : 1152 x 864 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 24 : 1152 x 864 x 85 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 25 : 1152 x 870 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 26 : 1152 x 900 x 66 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 27 : 1152 x 900 x 76 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 28 : 1280 x 720 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 29 : 1280 x 720 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 30 : 1280 x 768 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 31 : 1280 x 768 x 70 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 32 : 1280 x 768 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 33 : 1280 x 960 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 34 : 1280 x 960 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 35 : 1280 x 960 x 85 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 36 : 1280 x 1024 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 37 : 1280 x 1024 x 70 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 38 : 1280 x 1024 x 75 Hz
        1512,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 39 : 1280 x 1024 x 85 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 40 : 1440 x 900 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 41 : 1440 x 900 x 60 Hz (Reduced Blanking)
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 42 : 1440 x 900 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 43 : 1600 x 1200 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 44 : 1600 x 1200 x 65 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 45 : 1600 x 1200 x 70 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 46 : 1600 x 1200 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 47 : 1600 x 1200 x 85 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 48 : 1680 x 1050 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 49 : 1680 x 1050 x 60 Hz (Reduced Blanking)
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 50 : 1680 x 1050 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 51 : 1680 x 1050 x 75 Hz (Reduced Blanking)
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },
};

#endif  // End of #if(_DHTOTAL_BY_MODE == _ON)

#else

//extern ModeTableType code tINPUTMODE_PRESET_TABLE[_MAX_PRESET_MODE];

#if(_DISP_INFO_BY_MODE == _ON)

extern DisplayTableType code tDISPLAY_PRESET_TABLE[_MAX_PRESET_MODE];

#endif

#endif
