#if(_OSD_TYPE == _OSD003)

enum
{
	_MI_MENU_NONE,

	// MainMenu
	_MI_COLOR,
	_MI_ADJUST,
	_MI_OSD,
	_MI_TV,
	_MI_FUNCTION,
	_MI_SOUND,

	// MainMenu\Color
	_MI_BRIGHTNESS,
	_MI_CONTRAST,
	_MI_HUE,
	_MI_SATURATION,
	_MI_COLORTEMP,

#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
	// MainMenu\Color\Brightness
	_MI_BRIGHTADJ,
	// MainMenu\Color\Contrast
	_MI_CONTRASTADJ,
	// MainMenu\Color\Contrast
	_MI_HUEADJ,
	// MainMenu\Color\Saturation
	_MI_SATURATIONADJ,
#endif	

	// MainMenu\Color\ColorTemp
	_MI_9300,
	_MI_6500,
	_MI_USER,
	
	// MainMenu\Color\ColorTemp\USER\R\G\B
	_MI_USER_R,
	_MI_USER_G,
	_MI_USER_B,

#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
	// MainMenu\Color\ColorTemp\USER\R\G\B
	_MI_USER_RADJ,
	_MI_USER_GADJ,
	_MI_USER_BADJ,
#endif
	
	// MainMenu\Adjust
	_MI_AUTOADJUST,
	_MI_HPOSITION,
	_MI_VPOSITION,
	_MI_PHASE,
	_MI_CLOCK,

	// MainMenu\Adjust\AutoAdjust
	_MI_AUTOADJUST_OK,
	_MI_AUTOADJUST_CANCEL,
	
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
	// MainMenu\Adjust\HPositionAdj
	_MI_ADJUST_HPOSITIONADJ,
	// MainMenu\Adjust\VPositionAdj
	_MI_ADJUST_VPOSITIONADJ,
	// MainMenu\Adjust\PhaseAdj
	_MI_ADJUST_PHASEADJ,
	// MainMenu\Adjust\PhaseAdj
	_MI_ADJUST_CLOCKADJ,
#endif
	
	// MainMenu\OSD
	_MI_LANGUAGE,
	_MI_OSD_HPOSITION,
	_MI_OSD_VPOSITION,
	_MI_TIMER,
	_MI_DOUBLE,
	_MI_TRANSPARENT,

	// MainMenu\OSD\Language
	_MI_ENGLISH,
	_MI_CHI_S,
	_MI_FRA,
	_MI_ITA,
	_MI_DEU,
	_MI_ESP,
	_MI_CHI_T,
	_MI_JAP,
	_MI_KOR,
	_MI_RUS,

#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
	// MainMenu\OSD\HPosition
	_MI_OSD_HPOSITIONADJ,
	// MainMenu\OSD\VPosition
	_MI_OSD_VPOSITIONADJ,	

	// MainMenu\OSD\TimerADJ
	_MI_TIMERADJ,
#endif

	// MainMenu\OSD\Double
	_MI_DOUBLE_ON,
	_MI_DOUBLE_OFF,

#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
	_MI_TRANSPARENTADJ,
#endif	

	// MainMenu\TV
	_MI_CHANNEL,
	_MI_SYSTEM,
	_MI_AUTOSEARCH,
	_MI_MANUALSEARCH,
	_MI_TUNING,
	_MI_SKIP,
    _MI_SWAP,
    _MI_AFC,
	//
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)	
	_MI_OSD_CHANNELADJ,
#endif	

	// MainMenu\TV\System
	_MI_S_NTSC_M,
	_MI_S_NTSC_4_BG,
	_MI_S_NTSC_4_DK,
	_MI_S_NTSC_4_I,
	_MI_S_TV_PAL_M,
	_MI_S_PAL_BG,
	_MI_S_PAL_I,
	_MI_S_PAL_DK,
	_MI_S_PAL_N,
	_MI_S_SECAM_BG,
	_MI_S_SECAM_DK,
	_MI_S_SECAM_L,
	_MI_S_SECAM_LL,

	// MainMenu\TV\AutoSearch
	_MI_AUTOSEARCH_OK,
	_MI_AUTOSEARCH_CANCEL,
    
	// MainMenu\TV\ManualSearch
	_MI_MANUALSEARCH_UP,
	_MI_MANUALSEARCH_DOWN,
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
	_MI_TUNINGADJ,
#endif	
	// MainMenu\TV\Skip
	_MI_SKIP_ON,
	_MI_SKIP_OFF,
	
	// MainMenu\TV\AFC
	_MI_AFC_ON,
	_MI_AFC_OFF,

	// MainMenu\Function
	_MI_RESET,
	_MI_DISPLAYRATIO,
	_MI_AUTOPOWERDOWN,
	_MI_BLUESCREEN,
	_MI_SHARPNESS,

	// MainMenu\Function\Reset
	_MI_RESET_OK,
	_MI_RESET_CANCEL,

	// MainMenu\Function\DisplayRatio
	_MI_DISPLAYRATIO_FULL,
	_MI_DISPLAYRATIO_4_3,
	_MI_DISPLAYRATIO_AUTO,

	// MainMenu\Function\AutoPowerDown
	_MI_AUTOPOWERDOWN_OFF,
	_MI_APD_15,
	_MI_APD_30,
	_MI_APD_45,
	_MI_APD_60,
	_MI_APD_75,
	_MI_APD_90,
	_MI_APD_105,
	_MI_APD_120,

	// MainMenu\Function\BlueScreen
	_MI_BLUESCREEN_ON,
	_MI_BLUESCREEN_OFF,

#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    _MI_SHARPNESS_ADJ,
#endif	

	// MainMenu\Sound
	_MI_VOLUME,
	_MI_BALANCE,
	_MI_BASS,
	_MI_TREBLE,
	_MI_SRS,
	_MI_BBE,

#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
	// MainMenu\Sound\Volume
	_MI_VOLUMEADJ,
	// MainMenu\Sound\Balance
	_MI_BALANCEADJ,
	// MainMenu\Sound\Bass
	_MI_BASSADJ,
	// MainMenu\Sound\Treble
	_MI_TREBLEADJ,
	// MainMenu\Sound\SRS
	//_MI_SRSADJ,
	// MainMenu\Sound\BBE
	//_MI_BBEADJ,
#endif

#if(_CHANGE_SOURCE_METHOD == _CHANGE_SOURCE_METHOD_0)
	//Source Switch Menu
	// MainMenu\Source
	_MI_SOURCE_VGA,
	_MI_SOURCE_DVI,
	_MI_SOURCE_HDMI,
    _MI_SOURCE_YPBPR,
	_MI_SOURCE_AV,
	_MI_SOURCE_SV,
	_MI_SOURCE_TV,
#endif

	//Short cut menu

	_MI_SC_BRIGHTNESS,
	_MI_SC_VOLUME,
    _MI_SC_INPUT_CH_NUM,

    //Factory menu
    
#if(_FAC_OSD)
    _MI_FAC_AUTOCOLOR,
	_MI_FAC_GAIN,
	_MI_FAC_OFFSET,
	_MI_FAC_9300,
	_MI_FAC_6500,
	_MI_FAC_BURNIN,
    _MI_GAMMA,
    _MI_FAC_NR,
	_MI_FAC_EXIT,
	
	_MI_FAC_9300_R,
	_MI_FAC_9300_G,
	_MI_FAC_9300_B,

	_MI_FAC_6500_R,
	_MI_FAC_6500_G,
	_MI_FAC_6500_B,

	_MI_FAC_GAIN_R,
	_MI_FAC_GAIN_G,
	_MI_FAC_GAIN_B,

	_MI_FAC_OFFSET_R,
	_MI_FAC_OFFSET_G,
	_MI_FAC_OFFSET_B,

    _MI_FAC_GAMMA_ADJ,

#endif
};


#ifdef __OSDTABLE003__

#else


#endif

// extand function & Var
extern code SMenuItem g_tMenuItem[];

#endif		//#if(_OSD_TYPE == _OSD003)

