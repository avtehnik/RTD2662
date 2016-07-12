#if(_OSD_TYPE == _OSD001)


//------------------------------------------------------------
// MENU PAGE DEFINE'S
enum
{
	_P_MENU_NONE = 0,
	_P_MAIN_MENU,
    _P_SC_MENU,   // Shortcut key menu
//    _P_SHOW_MUTE,
};
//------------------------------------------------------------

// _P_MENU_NONE Menu Item define's
enum
{
    _MENU_NONE = 0,
    _MENU_NOSIGNAL,
};
//------------------------------------------------------------

// _P_MAIN_MENU Menu Item define's
enum
{
    _MI_BRIGHTNESS = 0,
    _MI_CONTRAST,
    _MI_HUE,
    _MI_SATURATION,
    _MI_PHASE,
    _MI_CLOCK,
    _MI_DISPLAY_MODE,
    _MI_AUTO_ADJUST,
    _MI_TV_SYSTEM,
    _MI_AUTO_SEARCH,
    _MI_MANUAL_SEARCH,
    _MI_TUNNING,
    _MI_SWAP,
    _MI_CHANNEL,
    _MI_SKIP,
    _MI_LANGUAGE,
    _MI_BLUE,
    _MI_VOLUME,
    _MI_EXIT,
};
//------------------------------------------------------------


// _P_SC_MENU Menu Item define's
enum
{
    _SC_MUTE = 0,
    _SC_VOLUME,

};
//------------------------------------------------------------

#ifdef __OSDTABLE001__

#else


#endif




extern code SMenu g_tMenu[];

// extand function & Var


#endif		//#if(_OSD_TYPE == _OSD001)

