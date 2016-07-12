//----------------------------------------------------------------------------------------------------
// ID Code      : ModeTable.h No.0001
// Update Note  :
//
//----------------------------------------------------------------------------------------------------
#define _MODE_FIRST                 	252
#define _MODE_EXIST                 	253
#define _MODE_NOSUPPORT          		254
#define _MODE_NOSIGNAL              	255

//--------------------------------------------------
// Preset Mode
//--------------------------------------------------
enum PresetModeDef
{
	    _MODE_640x350_70HZ = 0,         	// Mode 00: 640x350_70Hz, 720x350_70Hz
	   // _MODE_640x350_85HZ,             	// Mode 01: 640x350_85Hz
	    _MODE_640x400_56HZ,					// Mode 02: 640x400_56Hz
	    _MODE_640x400_70HZ,					// Mode 03: 640x400_70Hz, 720x400_70Hz
	    _MODE_720x400_70HZ,             	// Mode 04: 640x400_70Hz, 720x400_70Hz
	    _MODE_640x400_701HZ,          		// Mode 05: 640x400_70.1Hz
	    _MODE_640x400_85HZ,           		// Mode 06: 640x400_85Hz, 720x400_85Hz
	    _MODE_720x400_85HZ,             	// Mode 07: 640x400_85Hz, 720x400_85Hz
	    _MODE_640x480_60HZ,             	// Mode 08:
	    _MODE_640x480_66HZ,             	// Mode 09:
	    _MODE_640x480_72HZ,             	// Mode 10:
	    _MODE_640x480_75HZ,             	// Mode 11:
	    _MODE_640x480_85HZ,             	// Mode 12:
	    _MODE_800x600_56HZ,             	// Mode 13:
	    _MODE_800x600_60HZ,             	// Mode 14:
	    _MODE_800x600_72HZ,             	// Mode 15:
	    _MODE_800x600_75HZ,             	// Mode 16:
	    _MODE_800x600_85HZ,             	// Mode 17:
//	    _MODE_832x624_75HZ,             	// Mode 18:
	    _MODE_1024x768_60HZ,            	// Mode 18:
    	_MODE_1024x768_66HZ,          		// Mode 19:
	    _MODE_1024x768_70HZ,            	// Mode 20:
	    _MODE_1024x768_72HZ,            	// Mode 21:
	    _MODE_1024x768_75HZ,            	// Mode 22:
	    _MODE_1024x768_85HZ,            	// Mode 23:
	    _MODE_1024x800_73HZ,            	// Mode 24:
	    _MODE_1024x800_85HZ,            	// Mode 25:
	    _MODE_1152x864_60HZ,            	// Mode 26:
	    _MODE_1152x864_70HZ,            	// Mode 27:
	    _MODE_1152x864_75HZ,            	// Mode 28:
	    _MODE_1152x864_85HZ,            	// Mode 29:
	    _MODE_1152x870_75HZ,            	// Mode 30:
	    _MODE_1152x900_66HZ,            	// Mode 31:
	    _MODE_1152x900_76HZ,            	// Mode 32:
	    _MODE_1280x720_60HZ,            	// Mode 33:
	    _MODE_1280x720_75HZ,            	// Mode 34:
	    _MODE_1280x768_60HZ,            	// Mode 35:
	    _MODE_1280x768_70HZ,            	// Mode 36:
	    _MODE_1280x768_75HZ,            	// Mode 37:
	    _MODE_1280x960_60HZ,            	// Mode 38:
	    _MODE_1280x960_75HZ,            	// Mode 39:
	    _MODE_1280x960_85HZ,            	// Mode 40:
	    _MODE_1280x1024_60HZ,           	// Mode 41:
	    _MODE_1280x1024_70HZ,           	// Mode 42:
	    _MODE_1280x1024_75HZ,           	// Mode 43:
	    _MODE_1280x1024_85HZ,           	// Mode 44:
	    _MODE_1600x1200_60HZ,           	// Mode 45:
	    _MODE_1600x1200_65HZ,           	// Mode 46:
	    _MODE_1600x1200_70HZ,           	// Mode 47:
	    _MODE_1600x1200_75HZ,           	// Mode 48:
	    _MODE_1600x1200_85HZ,           	// Mode 49:
	    
	    _MODE_1680x1050_60HZ,           	// Mode 50:
	    _MODE_1680x1050_60HZ_RB,           	// Mode 51:
	    _MODE_1680x1050_75HZ,            	// Mode 52:
	    _MODE_1680x1050_75HZ_RB,            // Mode 53:
	    
    	_MODE_1920x1200_60HZ,           	// Mode 54:
    	_MODE_1920x1200_60HZ_RB,        	// Mode 55:
    	_MODE_1920x1200_75HZ,           	// Mode 56:
    	_MODE_1920x1440_60HZ,           	// Mode 57:	 
		_MODE_1440x480i_60HZ,           	// Mode 58:
    	_MODE_1920x1080i_60HZ,          	// Mode 59:
    	_MODE_1920x1080_60HZ,           	// Mode 60:
    	_MODE_1920x1080_60HZ_RB,        	// Mode 61:    	
    	
    	_MODE_1440x900_60HZ,            	// Mode 62:
        _MODE_1440x900_60HZ_RB,         	// Mode 63:
        _MODE_1440x900_75HZ,            	// Mode 64:

		_MODE_1280x720_50HZ,            	// Mode 65:
		_MODE_1920x1080i_50HZ,          	// Mode 66:
    	_MODE_1920x1080_50HZ,           	// Mode 67:
    	
	    // end
        _MAX_PRESET_MODE,
};


//--------------------------------------------------
// Defination of Mode Detection Tolerance
//--------------------------------------------------
#define _HFREQ_TOLERANCE            10			// kHz. Ex: 1.5kHz ==> 15
#define _VFREQ_TOLERANCE            (10 + 2)	// Hz.  Ex: 1.5Hz ==> 15

//--------------------------------------------------
// Defination of Mode Polarity
//--------------------------------------------------
#define _SYNC_HN_VN                 0x01
#define _SYNC_HP_VN                 0x02
#define _SYNC_HN_VP                 0x04
#define _SYNC_HP_VP                 0x08


#ifdef __MODE__

ModeTableType code tINPUTMODE_PRESET_TABLE[_MAX_PRESET_MODE] =
{
    //--------------------------------------------------
    // Preset Modes
    //--------------------------------------------------
    {   // Mode 0 : 640 x 350 x 70 Hz
        0 | _SYNC_HP_VN,                                                    // Polarity Flags,
        640, 350,                                                           // InputWidth, InputHeight,
        315, 700,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        800, 449,                                                           // IHTotal, IVTotal,
        144, 62,                                                            // IHStartPos, IVStartPos,
    },
      /*
    {   // Mode 1 : 640 x 350 x 85 Hz
        0 | _SYNC_HP_VN,                                                    // Polarity Flags,
        640, 350,                                                           // InputWidth, InputHeight,
        378, 850,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE + 5, _VFREQ_TOLERANCE + 5,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        832, 445,                                                           // IHTotal, IVTotal,
        160, 63,                                                            // IHStartPos, IVStartPos,
    }, */

    {   // Mode 2 : 640 x 400 x 56 Hz
        0 |  _SYNC_HN_VN,                        			    			// Polarity Flags,
        640, 400,                                                           // InputWidth, InputHeight,
        248, 560,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        848, 440,                                                           // IHTotal, IVTotal,
        144, 33,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 3 : 640 x 400 x 70 Hz
        //0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,        // Polarity Flags,
        //0 | _SYNC_HN_VP | _SYNC_HP_VP | _SYNC_HN_VN,                      // Polarity Flags,
        0 | _SYNC_HN_VP | _SYNC_HP_VP ,                        				// Polarity Flags,
        640, 400,                                                           // InputWidth, InputHeight,
        315, 700,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        900, 449,                                                           // IHTotal, IVTotal,
        162, 37,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 4 : 720 x 400 x 70 Hz
        //0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,        // Polarity Flags,
        //0 | _SYNC_HN_VP | _SYNC_HP_VP | _SYNC_HN_VN,                      // Polarity Flags,
        0 | _SYNC_HN_VP | _SYNC_HP_VP ,                        				// Polarity Flags,
        720, 400,                                                           // InputWidth, InputHeight,
        315, 700,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        900, 449,                                                           // IHTotal, IVTotal,
        162, 37,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 5 : 720 x 400 x 70.1 Hz
        0 | _SYNC_HN_VN ,                        			    			// Polarity Flags,
        720, 400,                                                           // InputWidth, InputHeight,
        315, 700,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        800, 449,                                                           // IHTotal, IVTotal,
        144, 37,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 6 : 640 x 400 x 85 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        640, 400,                                                           // InputWidth, InputHeight,
        380, 850,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE + 5, _VFREQ_TOLERANCE + 5,                         // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        832, 445,                                                           // IHTotal, IVTotal,
        161, 43,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 7 : 720 x 400 x 85 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        720, 400,                                                           // InputWidth, InputHeight,
        380, 850,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE + 5, _VFREQ_TOLERANCE + 5,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        936, 446,                                                           // IHTotal, IVTotal,
        180, 45,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 8 : 640 x 480 x 60 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        640, 480,                                                           // InputWidth, InputHeight,
        315, 600,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        800, 525,                                                           // IHTotal, IVTotal,
        144, 35,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 9 : 640 x 480 x 66 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        640, 480,                                                           // InputWidth, InputHeight,
        350, 666,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        864, 525,                                                           // HTotal, VTotal,
        160, 42,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 10 : 640 x 480 x 72 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        640, 480,                                                           // InputWidth, InputHeight,
        378, 728,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        832, 520,                                                           // HTotal, VTotal,
        168, 31,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 11 : 640 x 480 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        640, 480,                                                           // InputWidth, InputHeight,
        375, 750,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        840, 500,                                                           // IHTotal, IVTotal,
        184, 19,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 12 : 640 x 480 x 85 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        640, 480,                                                           // InputWidth, InputHeight,
        433, 850,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        832, 510,                                                           // IHTotal, IVTotal,
        136, 28,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 13 : 800 x 600 x 56 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        800, 600,                                                           // InputWidth, InputHeight,
        351, 562,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1024, 625,                                                          // HTotal, VTotal,
        200, 24,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 14 : 800 x 600 x 60 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        800, 600,                                                           // InputWidth, InputHeight,
        378, 603,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1056, 628,                                                          // IHTotal, IVTotal,
        216, 27,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 15 : 800 x 600 x 72 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        800, 600,                                                           // InputWidth, InputHeight,
        480, 720,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1040, 666,                                                          // HTotal, VTotal,
        184, 29,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 16 : 800 x 600 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        800, 600,                                                           // InputWidth, InputHeight,
        468, 750,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1056, 625,                                                          // IHTotal, IVTotal,
        240, 24,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 17 : 800 x 600 x 85 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        800, 600,                                                           // InputWidth, InputHeight,
        536, 850,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1048, 631,                                                          // IHTotal, IVTotal,
        216, 30,                                                            // IHStartPos, IVStartPos,
    },

	//eric 200706020
    /*{   // Mode 18 : 832 x 624 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        832, 624,                                                           // InputWidth, InputHeight,
        497, 745,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1152, 667,                                                          // IHTotal, IVTotal,
        288, 42,                                                            // IHStartPos, IVStartPos,
    },*/

    {   // Mode 18 : 1024 x 768 x 60 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HP_VP,                        // Polarity Flags,
        1024, 768,                                                          // InputWidth, InputHeight,
        483, 600,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1344, 806,                                                          // IHTotal, IVTotal,
        296, 35,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 19 : 1024 x 768 x 66 Hz
        0 | _SYNC_HN_VN ,                        			     			// Polarity Flags,
        1024, 768,                                                          // InputWidth, InputHeight,
        540, 660,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1328, 816,                                                          // IHTotal, IVTotal,
        288, 40,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 20 : 1024 x 768 x 70 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HP_VP,                        // Polarity Flags,
        1024, 768,                                                          // InputWidth, InputHeight,
        564, 700,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1328, 806,                                                          // HTotal, VTotal,
        280, 35,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 21 : 1024 x 768 x 72 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HP_VP | _SYNC_HN_VP,          // Polarity Flags,
        1024, 768,                                                          // InputWidth, InputHeight,
        577, 721,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1328, 800,                                                          // HTotal, VTotal,
        280, 35,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 22 : 1024 x 768 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HP_VP,                        // Polarity Flags,
        1024, 768,                                                          // InputWidth, InputHeight,
        600, 750,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1312, 800,                                                          // IHTotal, IVTotal,
        272, 31,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 23 : 1024 x 768 x 85 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1024, 768,                                                          // InputWidth, InputHeight,
        682, 850,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1376, 808,                                                          // IHTotal, IVTotal,
        304, 39,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 24 : 1024 x 800 x 73 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1024, 800,                                                          // InputWidth, InputHeight,
        620, 740,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1328, 837,                                                          // IHTotal, IVTotal,
        264, 35,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 25 : 1024 x 800 x 85 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1024, 800,                                                          // InputWidth, InputHeight,
        715, 850,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1320, 837,                                                          // IHTotal, IVTotal,
        280, 35,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 26 : 1152 x 864 x 60 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1152, 864,                                                          // InputWidth, InputHeight,
        537, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1512, 894,                                                          // HTotal, VTotal,
        300, 30,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 27 : 1152 x 864 x 70 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1152, 864,                                                          // InputWidth, InputHeight,
        642, 702,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1472, 914,                                                          // HTotal, VTotal,
        288, 49,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 28 : 1152 x 864 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1152, 864,                                                          // InputWidth, InputHeight,
        675, 750,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1600, 900,                                                          // IHTotal, IVTotal,
        384, 35,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 29 : 1152 x 864 x 85 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1152, 864,                                                          // InputWidth, InputHeight,
        770, 850,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1576, 907,                                                          // HTotal, VTotal,
        360, 42,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 30 : 1152 x 870 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1152, 870,                                                          // InputWidth, InputHeight,
        686, 750,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1456, 915,                                                          // HTotal, VTotal,
        272, 42,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 31 : 1152 x 900 x 66 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1152, 900,                                                          // InputWidth, InputHeight,
        618, 660,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1528, 937,                                                          // HTotal, VTotal,
        336, 35,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 32 : 1152 x 900 x 76 Hz
//        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        // For 1440x900 75Hz _SYNC_HN_VP
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HP_VP,                        // Polarity Flags,
        1152, 900,                                                          // InputWidth, InputHeight,
        718, 766,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1504, 937,                                                          // HTotal, VTotal,
        320, 35,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 33 : 1280 x 720 x 60 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1280, 720,                                                          // InputWidth, InputHeight,
        447, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1656, 746,                                                          // HTotal, VTotal,
        339, 25,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 34 : 1280 x 720 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1280, 720,                                                          // InputWidth, InputHeight,
        564, 750,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1688, 751,                                                          // HTotal, VTotal,
        340, 31,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 35 : 1280 x 768 x 60 Hz
        0 | _SYNC_HN_VP,                                                    // Polarity Flags,
        1280, 768,                                                          // InputWidth, InputHeight,
        477, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1668, 794,                                                          // HTotal, VTotal,
        332, 26,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 36 : 1280 x 768 x 70 Hz
        0 | _SYNC_HN_VP,                                                    // Polarity Flags,
        1280, 768,                                                          // InputWidth, InputHeight,
        560, 700,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1692, 799,                                                          // HTotal, VTotal,
        336, 31,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 37 : 1280 x 768 x 75 Hz
        0 | _SYNC_HN_VP,                                                    // Polarity Flags,
        1280, 768,                                                          // InputWidth, InputHeight,
        601, 750,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1706, 801,                                                          // HTotal, VTotal,
        346, 33,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 38 : 1280 x 960 x 60 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1280, 960,                                                          // InputWidth, InputHeight,
        600, 600,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1800, 1000,                                                         // IHTotal, IVTotal,
        424, 39,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 39 : 1280 x 960 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1280, 960,                                                          // InputWidth, InputHeight,
        750, 750,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1680, 1000,                                                         // HTotal, VTotal,
        368, 39,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 40 : 1280 x 960 x 85 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1280, 960,                                                          // InputWidth, InputHeight,
        860, 850,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1728, 1011,                                                         // IHTotal, IVTotal,
        384, 50,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 41 : 1280 x 1024 x 60 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1280, 1024,                                                         // InputWidth, InputHeight,
        640, 600,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1688, 1066,                                                         // IHTotal, IVTotal,
        360, 41,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 42 : 1280 x 1024 x 70 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1280, 1024,                                                         // InputWidth, InputHeight,
        746, 700,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1722, 1065,                                                         // HTotal, VTotal,
        359, 40,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 43 : 1280 x 1024 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1280, 1024,                                                         // InputWidth, InputHeight,
        800, 750,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1688, 1066,                                                         // IHTotal, IVTotal,
        392, 41,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 44 : 1280 x 1024 x 85 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1280, 1024,                                                         // InputWidth, InputHeight,
        911, 850,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1728, 1072,                                                         // IHTotal, IVTotal,
        384, 47,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 45 : 1600 x 1200 x 60 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1600, 1200,                                                         // InputWidth, InputHeight,
        750, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2160, 1250,                                                         // HTotal, VTotal,
        496, 49,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 46 : 1600 x 1200 x 65 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1600, 1200,                                                         // InputWidth, InputHeight,
        812, 650,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2160, 1250,                                                         // HTotal, VTotal,
        496, 49,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 47 : 1600 x 1200 x 70 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1600, 1200,                                                         // InputWidth, InputHeight,
        875, 700,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2160, 1250,                                                         // HTotal, VTotal,
        496, 49,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 48 : 1600 x 1200 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1600, 1200,                                                         // InputWidth, InputHeight,
        937, 750,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2160, 1250,                                                         // HTotal, VTotal,
        496, 49,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 49 : 1600 x 1200 x 85 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1600, 1200,                                                         // InputWidth, InputHeight,
        1062, 850,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2160, 1250,                                                         // HTotal, VTotal,
        496, 49,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 50 : 1680 x 1050 x 60 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1680, 1050,                                                         // InputWidth, InputHeight,
        653, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2240, 1089,                                                         // HTotal, VTotal,
        456, 36,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 51 : 1680 x 1050 x 60 Hz (Reduced Blanking)
        0 | _SYNC_HP_VN,                                                    // Polarity Flags,
        1680, 1050,                                                         // InputWidth, InputHeight,
        647, 599,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2160, 1080,                                                         // HTotal, VTotal,
        112, 27,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 52 : 1680 x 1050 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1680, 1050,                                                         // InputWidth, InputHeight,
        823, 749,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2272, 1099,                                                         // HTotal, VTotal,
        472, 46,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 53 : 1680 x 1050 x 75 Hz (Reduced Blanking)
        0 | _SYNC_HP_VN,                                                    // Polarity Flags,
        1680, 1050,                                                         // InputWidth, InputHeight,
        815, 750,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1840, 1088,                                                         // HTotal, VTotal,
        112, 35,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 54 : 1920 x 1200 x 60 Hz 
        0 | _SYNC_HN_VN | _SYNC_HN_VP,                                      // Polarity Flags,
        1920, 1200,                                                         // InputWidth, InputHeight,
        746, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2592, 1245,                                                         // HTotal, VTotal,
        536, 42,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 55 : 1920 x 1200 x 60 Hz (Reduced Blanking)
        0 | _SYNC_HP_VN,                                                    // Polarity Flags,
        1920, 1200,                                                         // InputWidth, InputHeight,
        740, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2080, 1235,                                                         // HTotal, VTotal,
        112, 32,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 56 : 1920 x 1200 x 75 Hz 
        0 | _SYNC_HN_VN | _SYNC_HN_VP,                                      // Polarity Flags,
        1920, 1200,                                                         // InputWidth, InputHeight,
        940, 750,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2608, 1255,                                                         // HTotal, VTotal,
        552, 52,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 57 : 1920 x 1440 x 60 Hz 
        0 | _SYNC_HN_VN | _SYNC_HN_VP | _SYNC_HP_VP,                        // Polarity Flags,
        1920, 1440,                                                         // InputWidth, InputHeight,
        900, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2600, 1500,                                                         // HTotal, VTotal,
        552, 59,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 58 : 1440 x 480i x 60 Hz 
        0 | _SYNC_HN_VN | _SYNC_HN_VP | _SYNC_HP_VP,                        // Polarity Flags,
        1440, 240,                                                          // InputWidth, InputHeight,
        157, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1716, 525,                                                          // HTotal, VTotal,
        276, 59,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 59 : 1920 x 1080i x 60 Hz 
        0 | _SYNC_HN_VN | _SYNC_HN_VP | _SYNC_HP_VP,                        // Polarity Flags,
        1920, 540,                                                          // InputWidth, InputHeight,
        337, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2200, 562,                                                          // HTotal, VTotal,
        236, 33,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 60 : 1920 x 1080p x 60 Hz
        0 | _SYNC_HN_VP,                                                    // Polarity Flags,
        1920, 1080,                                                         // InputWidth, InputHeight,
        672, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2576, 1120,                                                         // HTotal, VTotal,
        528, 37,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 61 : 1920 x 1080 x 60 Hz (Reduced Blanking)
        0 | _SYNC_HP_VN,                                                    // Polarity Flags,
        1920, 1080,                                                         // InputWidth, InputHeight,
        666, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2080, 1111,                                                         // HTotal, VTotal,
        112, 29,                                                            // HStartPos, VStartPos,
    },

   {   // Mode 62 : 1440 x 900 x 60 Hz
        0 | _SYNC_HN_VP | _SYNC_HN_VN | _SYNC_HP_VP,                        // Polarity Flags,
        1440, 900,                                                          // InputWidth, InputHeight,
        559, 598,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1904, 934,                                                          // HTotal, VTotal,
        384, 31,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 63 : 1440 x 900 x 60 Hz  (Reduced Blanking)
        0 | _SYNC_HP_VN | _SYNC_HN_VN,                                                    // Polarity Flags,
        1440, 900,                                                          // InputWidth, InputHeight,
        557, 602,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1600, 926,                                                          // HTotal, VTotal,
        112, 23,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 64 : 1440 x 900 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1440, 900,                                                          // InputWidth, InputHeight,
        706, 750,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1936, 942,                                                          // HTotal, VTotal,
        400, 39,                                                            // HStartPos, VStartPos,
    },

	{   // Mode 65 : 1280 x 720p x 50 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1280, 720,                                                          // InputWidth, InputHeight,
        370, 500,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1632, 741,                                                          // HTotal, VTotal,
        304, 20,                                                            // HStartPos, VStartPos,
    },

	{   // Mode 66 : 1920 x 1080i x 50 Hz 
        0 | _SYNC_HN_VN | _SYNC_HN_VP | _SYNC_HP_VP,                        // Polarity Flags,
        1920, 540,                                                          // InputWidth, InputHeight,
        283, 500,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2200, 562,                                                          // HTotal, VTotal,
        236, 33,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 67 : 1920 x 1080p x 50 Hz
        0 | _SYNC_HN_VP,                                                    // Polarity Flags,
        1920, 1080,                                                         // InputWidth, InputHeight,
        560, 500,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2576, 1120,                                                         // HTotal, VTotal,
        528, 37,                                                            // HStartPos, VStartPos,
    },
};

#if(_DISP_INFO_BY_MODE == _ON)

DisplayTableType code tDISPLAY_PRESET_TABLE[_MAX_PRESET_MODE] =
{
    //--------------------------------------------------
    // Preset Modes
    //--------------------------------------------------
    {   // Mode 0 : 640 x 350 x 70 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 1 : 640 x 350 x 85 Hz
        1440,                                                               // DHTotal,
        1280, 852,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 2 : 640 x 400 x 56 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 3 : 640 x 400 x 70 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 4 : 720 x 400 x 70 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 5 : 640 x 400 x 70.1 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 6 : 640 x 400 x 85 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 7 : 720 x 400 x 85 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 8 : 640 x 480 x 60 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 9 : 640 x 480 x 66 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 10 : 640 x 480 x 72 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 11 : 640 x 480 x 75 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 12 : 640 x 480 x 85 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 13 : 800 x 600 x 56 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 14 : 800 x 600 x 60 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 15 : 800 x 600 x 72 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 16 : 800 x 600 x 75 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 17 : 800 x 600 x 85 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 18 : 832 x 624 x 75 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 19 : 1024 x 768 x 60 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 20 : 1024 x 768 x 66 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 21 : 1024 x 768 x 70 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 22 : 1024 x 768 x 75 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 23 : 1024 x 768 x 85 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 24 : 1024 x 800 x 73 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 25 : 1024 x 800 x 85 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 26 : 1152 x 864 x 60 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 27 : 1152 x 864 x 70 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 28 : 1152 x 864 x 75 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 29 : 1152 x 864 x 85 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 30 : 1152 x 870 x 75 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 31 : 1152 x 900 x 66 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 32 : 1152 x 900 x 76 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 33 : 1280 x 720 x 60 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 34 : 1280 x 720 x 75 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 35 : 1280 x 768 x 60 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 36 : 1280 x 768 x 70 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 37 : 1280 x 768 x 75 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 38 : 1280 x 960 x 60 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 39 : 1280 x 960 x 75 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 40 : 1280 x 960 x 85 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 41 : 1280 x 1024 x 60 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 42 : 1280 x 1024 x 70 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 43 : 1280 x 1024 x 75 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 44 : 1280 x 1024 x 85 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 45 : 1600 x 1200 x 60 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 46 : 1600 x 1200 x 65 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 47 : 1600 x 1200 x 70 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 48 : 1600 x 1200 x 75 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 49 : 1600 x 1200 x 85 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 50 : 1680 x 1050 x 60 Hz
        1472,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 51 : 1680 x 1050 x 75 Hz
        1472,                                                               // DHTotal,
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
};

#endif  // End of #if(_DHTOTAL_BY_MODE == _ON)

#else


extern ModeTableType code tINPUTMODE_PRESET_TABLE[_MAX_PRESET_MODE];

#if(_DISP_INFO_BY_MODE == _ON)

extern DisplayTableType code tDISPLAY_PRESET_TABLE[_MAX_PRESET_MODE];

#endif

#endif

