

#define __OSDTABLE001__


#include "Core\Header\Include.h"


#if(_OSD_TYPE == _OSD001)

//------------------------------------------------------------




// Menu item's define


//------------------------------------------------------------
code SMenuItem tMenuNoneItem[] =
{
    {   // Active
        _EN_PUB_PROCFUNC,        					// BYTE Option;
        tKOMenuNone,    							// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        _P_MAIN_MENU,      							// SMenu *SubMenu,                         // 可以为NULL
        NULL,           							// void (*Proc)(void);                     // 可以为NULL
        CEnable,        							// bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CDrawNull,      							// void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMIMenuNoneRun,    							// funcpMenuRun MenuRun
    },/*
    {   // No signel / not support / no cable
        _EN_PUB_PROCFUNC,  							// BYTE Option;
        tKONoSignal,    							// SKeyToOsdEvent *KeyMsgToOsdEvnet;        // 可以为NULL
        _P_MAIN_MENU,      							// SMenu *SubMenu,                         // 可以为NULL
        NULL,           							// void (*Proc)(void);                     // 可以为NULL
        CEnable,        							// bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CDrawNull,      							// void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMIMenuNoneRun,    							// funcpMenuRun MenuRun
    },*/

};
//------------------------------------------------------------
/*
enum
{
    _MI_BRIGHTNESS = 0,
    _MI_CONTRAST,
    _MI_HUE,
    _MI_SATURATION,
    _MI_PHASE,
    _MI_CLOCK,
    _MI_DISPLAY_MODE,		// 
Full  4:3
    _MI_AUTO_ADJUST,
    //_MI_AUTO_SEARCH,
    _MI_EXIT,
};
*/


code SMenuItem tMainMenuItem[] =
{
    {   // _MI_BRIGHTNESS
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,     	//BYTE Option;
        NULL,    				//SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        NULL,           		// SMenu *SubMenu,                         // 可以为NULL
        NULL,           		// void (*Proc)(void);                     // 可以为NULL
        CEnable,        		// bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawBrightness,      	// void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMIBrightnessRun, 		// funcpMenuRun MenuRun
    },
    {   // _MI_CONTRAST
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,     	// BYTE Option;
        NULL,    				// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        NULL,           	  	// SMenu *SubMenu,                         // 可以为NULL
        NULL,           		// void (*Proc)(void);                     // 可以为NULL
        CEnable,        		// bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawContrast,  		// void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMIContrastRun, 		// funcpMenuRun MenuRun
    },
    {   // _MI_HUE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,    				// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        NULL,                   // SMenu *SubMenu,                         // 可以为NULL
        NULL,                   // void (*Proc)(void);                     // 可以为NULL
        CMIVedio8Enable,       	// bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawHue,          	// void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMIHueRun,         		// funcpMenuRun MenuRun
    },
    {   // _MI_SATURATION
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,    				// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        NULL,                   // SMenu *SubMenu,                         // 可以为NULL
        NULL,                   // void (*Proc)(void);                     // 可以为NULL
        CMIVedio8Enable,    	// bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawSaturation,     	// void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMISaturationRun,       // funcpMenuRun MenuRun
    },
    {   // _MI_PHASE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,    				// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        NULL,                   // SMenu *SubMenu,                         // 可以为NULL
        NULL,                   // void (*Proc)(void);                     // 可以为NULL
        CMIVGAEnable,        	// bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawPhase,      		// void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMIPhaseRun,       		// funcpMenuRun MenuRun
    },
    {   // _MI_CLOCK
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,    				// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        NULL,                   // SMenu *SubMenu,                         // 可以为NULL
        NULL,                   // void (*Proc)(void);                     // 可以为NULL
        CMIVGAEnable,        	// bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawClock,      		// void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMIClockRun,       		// funcpMenuRun MenuRun
    },
    {   // _MI_DISPLAY_MODE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        tKOMenuRun,    			// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        NULL,                   // SMenu *SubMenu,                         // 可以为NULL
        NULL,                   // void (*Proc)(void);                     // 可以为NULL
        CEnable,           		// bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawDisplayMode,     // void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMIDisplayModeRun,      // funcpMenuRun MenuRun
    },
    {   // _MI_AUTO_ADJUST
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        tKOMenuRun,             // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        NULL,                   // SMenu *SubMenu,                         // 可以为NULL
        NULL,                   // void (*Proc)(void);                     // 可以为NULL
        CMIVGAEnable,           // bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawAutoAdjust,      // void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMIAutoAdjustRun,       // funcpMenuRun MenuRun
    },
                
#if(_VIDEO_TV_SUPPORT)
    //--------------------------------- TV item ------------------------------------
    {   // _MI_TV_SYSTEM
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,                   // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        NULL,                   // SMenu *SubMenu,                         // 可以为NULL
        NULL,                   // void (*Proc)(void);                     // 可以为NULL
        CMITVEnable,            // bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawTVSystem,        // void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMITVSystemRun,         // funcpMenuRun MenuRun
    },
    {   // _MI_AUTO_SEARCH
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,                   // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        NULL,                   // SMenu *SubMenu,                         // 可以为NULL
        NULL,                   // void (*Proc)(void);                     // 可以为NULL
        CMITVEnable,            // bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawAutoSearch,      // void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMIAutoSearchRun,       // funcpMenuRun MenuRun
    },              
    {   // _MI_MANUAL_SEARCH
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,                   // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        NULL,                   // SMenu *SubMenu,                         // 可以为NULL
        NULL,                   // void (*Proc)(void);                     // 可以为NULL
        CMITVEnable,            // bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawManualSearch,    // void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMIManualSearchRun,     // funcpMenuRun MenuRun
    },              
    {   // _MI_TUNNING
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,                   // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        NULL,                   // SMenu *SubMenu,                         // 可以为NULL
        NULL,                   // void (*Proc)(void);                     // 可以为NULL
        CMITVEnable,            // bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawTunning,         // void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMITunningRun,          // funcpMenuRun MenuRun
    },              
    {   // _MI_SWAP
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,                   // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        NULL,                   // SMenu *SubMenu,                         // 可以为NULL
        NULL,                   // void (*Proc)(void);                     // 可以为NULL
        CMITVEnable,            // bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawSwap,            // void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMISwapRun,             // funcpMenuRun MenuRun
    },              
    {   // _MI_CHANNEL
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,                   // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        NULL,                   // SMenu *SubMenu,                         // 可以为NULL
        NULL,                   // void (*Proc)(void);                     // 可以为NULL
        CMITVEnable,            // bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawChannel,         // void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMIChannelRun,          // funcpMenuRun MenuRun
    },              
    {   // _MI_SKIP
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,                   // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        NULL,                   // SMenu *SubMenu,                         // 可以为NULL
        NULL,                   // void (*Proc)(void);                     // 可以为NULL
        CMITVEnable,            // bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawSkip,            // void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMISkipRun,             // funcpMenuRun MenuRun
    },              
    //-------------------------------- TV item end ----------------------------------
#endif // #if(_VIDEO_TV_SUPPORT)

    {   // _MI_LANGUAGE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,                   // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        NULL,                   // SMenu *SubMenu,                         // 可以为NULL
        NULL,                   // void (*Proc)(void);                     // 可以为NULL
        CEnable,                // bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawLanguage,        // void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMILanguageRun,         // funcpMenuRun MenuRun
    },              
    {   // _MI_BLUE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,                   // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        NULL,                   // SMenu *SubMenu,                         // 可以为NULL
        NULL,                   // void (*Proc)(void);                     // 可以为NULL
        CEnable,                // bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawBlue,            // void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMIBlueRun,             // funcpMenuRun MenuRun
    },              
    {   // _MI_VOLUME
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,                   // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        NULL,                   // SMenu *SubMenu,                         // 可以为NULL
        NULL,                   // void (*Proc)(void);                     // 可以为NULL
        CEnable,                // bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawVolume,          // void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMIVolumeRun,           // funcpMenuRun MenuRun
    },              
    
    {   // _MI_EXIT
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        tKOMenuRun,    			// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        NULL,                   // SMenu *SubMenu,                         // 可以为NULL
        NULL,                   // void (*Proc)(void);                     // 可以为NULL
        CEnable,           		// bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawExit,      		// void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CMIExitRun,       		// funcpMenuRun MenuRun
    },
    
    
};
//------------------------------------------------------------


code SMenuItem tSCMenuItem[] =
{
    {   // _SC_MUTE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,     	//BYTE Option;
        tKOMenuRun,				//SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        NULL,           		// SMenu *SubMenu,                         // 可以为NULL
        NULL,           		// void (*Proc)(void);                     // 可以为NULL
        CEnable,        		// bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CDrawSCMute,          	// void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        CSCMuteRun,     		// funcpMenuRun MenuRun
    },
};
//------------------------------------------------------------


// Menu's define



//------------------------------------------------------------

code SMenu g_tMenu[] = 
{
	{	//_P_MENU_NONE
	    NULL,                                                       //TMenuItem *ParentMenu;
	    0,                                                          //BYTE ParentMenuItemIndex;
	    sizeof(tMenuNoneItem)/sizeof(SMenuItem),                    //BYTE MenuItemCount;
	    tMenuNoneItem,                                              //TMenuItem *Menu;
	    CDrawNull,                                           		//void (*Draw)(BYTE ucDrawID);
	},
	{	//_P_MAIN_MENU
	    _P_MENU_NONE,                                               //TMenuItem *ParentMenu;
	    0,                                                          //BYTE ParentMenuItemIndex;
	    sizeof(tMainMenuItem)/sizeof(SMenuItem),                    //BYTE MenuItemCount;
	    tMainMenuItem,                                              //TMenuItem *Menu;
	    CPDrawMainMenu,                                             //void (*Draw)(BYTE ucDrawID);
	},
	{	//_P_SC_MENU
	    _P_MENU_NONE,                                               //TMenuItem *ParentMenu;
	    0,                                                          //BYTE ParentMenuItemIndex;
	    sizeof(tSCMenuItem)/sizeof(SMenuItem),                      //BYTE MenuItemCount;
	    tSCMenuItem,                                                //TMenuItem *Menu;
	    CPDrawSCMenu,                                               //void (*Draw)(BYTE ucDrawID);
	},

    /*
    {   //_P_SHOW_MUTE
	    _P_MENU_NONE,                                               //TMenuItem *ParentMenu;
	    0,                                                          //BYTE ParentMenuItemIndex;
	    sizeof(tMenuNoneItem)/sizeof(SMenuItem),                    //BYTE MenuItemCount;
	    tMenuNoneItem,                                              //TMenuItem *Menu;
	    CDrawMuteState,                                             //void (*Draw)(BYTE ucDrawID);
    } */
};
//------------------------------------------------------------

#endif 	//#if(_OSD_TYPE == _OSD001)

