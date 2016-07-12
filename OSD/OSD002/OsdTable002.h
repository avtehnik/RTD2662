#if(_OSD_TYPE == _OSD002)


//------------------------------------------------------------
// MENU PAGE DEFINE
enum
{
	_P_MENU_NONE = 0,
    _P_MENU_EXIT,
	_P_MAIN_MENU,

	//sub menu 
	_P_COLOR_MENU,
	_P_ADJUST_MENU,
	_P_OSD_MENU,
	_P_TV_MENU,
	_P_FUNC_MENU,

	// short menu
	_P_SHORT_MENU,
	
	
};
//------------------------------------------------------------

// _P_MENU_NONE Menu Item define
enum
{
    _MENU_NONE = 0,
    _MENU_NOSIGNAL,
};
//------------------------------------------------------------

// _P_MAIN_MENU Menu Item define
enum
{
    _MI_COLOR = 0,
    _MI_ADJUST,
    _MI_OSD,
    _MI_TV,
    _MI_FUNCTION,
    _MI_EXIT,
};

//------------------------------------------------------------
// Color Page define
enum
{
    _MI_BRIGHTNESS = 0,
    _MI_CONTRAST,
    _MI_HUE,
    _MI_SATURATION,
    _MI_COLORTEMP,
    _MI_COLORRETURN,
};
//------------------------------------------------------------
// Adjust page define
enum
{
    _MI_AUTOCONFIG = 0,
    _MI_HPOSITION,
    _MI_VPOSITION,
    _MI_PHASE,
    _MI_CLOCK,
    _MI_ADJUSTRETURN,
};
//------------------------------------------------------------
// osd page define
enum
{
    _MI_LANGUAGE = 0,
    _MI_OSDHPOSITION,
    _MI_OSDVPOSITION,
    _MI_TIMER,
    _MI_DOUBLE,
    _MI_TRANSPARENT,
    _MI_OSDRETURN,
};
//------------------------------------------------------------

// Tv page define
enum
{
    _MI_SYSTEM = 0,
    _MI_CHANNEL,
    _MI_AUTOSEARCH,
    _MI_MANUALSEARCH,
    _MI_TUNING,
    _MI_SKIP,
#if(_SLEEP_FUNC)
    _MI_AUTOPOWERDOWN,
#endif
    _MI_BLUESCREEN,
    _MI_TVRETURN,
};
//------------------------------------------------------------
// Func page define
enum
{
	_MI_RESET = 0,
#if(_DISPLAY_RATIO)
	_MI_DISPLAY_RATIO,
#endif
	_MI_VOLUME,
	_MI_MUTE,
#if (_SOUND_PROCESSOR)
	_MI_BALANCE,
	_MI_BASS,
	_MI_TREBLE,
 #if(AUDIO_TYPE != _AUDIO_SC7313)
	_MI_SRS,
	_MI_BBE,
 #endif
#endif
#if(_FM_DEVICE)
    _MI_FM,
#endif
	_MI_FUNC_RETURN,
};
//------------------------------------------------------------
enum
{
    _MI_SMBRIGHT = 0,
    _MI_SMVOLUME,
    _MI_SMMUTE,
    _MI_SMINPUT_CH
};
//------------------------------------------------------------

#ifdef __OSDTABLE002__

#else


#endif

extern code SMenu g_tMenu[];

// extand function & Var


#endif		//#if(_OSD_TYPE == _OSD002)

