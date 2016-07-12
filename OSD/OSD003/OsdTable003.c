

#define __OSDTABLE003__


#include "Core\Header\Include.h"


#if(_OSD_TYPE == _OSD003)

//------------------------------------------------------------

// Menu item's define
// Option : _DISABLE_NOT_SHOW,_EN_PUB_KEYEVENT,_KEYMAP_EN_IN_NOSIGNAL
code SMenuItem g_tMenuItem[] = 
{
    // _MI_MENU_NONE
    {
        0,                      //BYTE Option;
        tKOMenuNone,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MMenuNoneProc,          //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Color(_MI_COLOR)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MMainMenuProc,          //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Adjust(_MI_ADJUST)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MMainMenuProc,          //funcpProc Proc;
        CVgaEnable,             //funcpEnable Enable;
    },
    // MainMenu\OSD(_MI_OSD)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MMainMenuProc,          //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\TV(_MI_TV)
    {
	#if(_VIDEO_TV_SUPPORT)
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MMainMenuProc,          //funcpProc Proc;
        CTVEnable,              //funcpEnable Enable;
	#else
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MMainMenuProc,          //funcpProc Proc;
        CMITVEnable,            //funcpEnable Enable;
	#endif
    },
    // MainMenu\Function(_MI_FUNCTION)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MMainMenuProc,          //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Sound(_MI_SOUND)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MMainMenuProc,          //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Color\Brightness(_MI_BRIGHTNESS)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MColorProc,             //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Color\Contrast(_MI_CONTRAST)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MColorProc,             //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Color\Hue(_MI_HUE)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MColorProc,             //funcpProc Proc;
        CVideoNTSCEnable,       //funcpEnable Enable;
    },
    // MainMenu\Color\Saturation(_MI_SATURATION)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MColorProc,             //funcpProc Proc;
        CVideoEnable,           //funcpEnable Enable;
    },
    // MainMenu\Color\ColorTemp(_MI_COLORTEMP)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOSubMenu1,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MColorProc,             //funcpProc Proc;
        CVgaEnable,             //funcpEnable Enable;
    },
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    // MainMenu\Color\Brightness\BrgintAdj(_MI_BRIGHTADJ)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOAdjust,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MBrightnessProc,        //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Color\Contrast\ContrastAdj(_MI_CONTRASTADJ)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOAdjust,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MContrastProc,        //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },    
    // MainMenu\Color\Hue\HueAdj(_MI_HUEADJ)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOAdjust,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MHueProc,             //funcpProc Proc;
        CVideoNTSCEnable,       //funcpEnable Enable;
    },
    // MainMenu\Color\Saturation\SaturationAdj(_MI_SATURATIONADJ)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOAdjust,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSaturationProc,             //funcpProc Proc;
        CVideoEnable,           //funcpEnable Enable;
    },
	#endif
    // MainMenu\Color\ColorTemp\9300(_MI_9300)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MColorTempProc,         //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Color\ColorTemp\6500(_MI_6500)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MColorTempProc,         //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Color\ColorTemp\User(_MI_USER)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MColorTempProc,         //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },    
    // MainMenu\Color\ColorTemp\User(_MI_USER_R)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MColorUserProc,         //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },    
    // MainMenu\Color\ColorTemp\User(_MI_USER_G)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MColorUserProc,         //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },    
    // MainMenu\Color\ColorTemp\User(_MI_USER_B)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MColorUserProc,         //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    //MainMenu\Color\ColorTemp\User\RAdj(_MI_USER_RADJ)
    {
    	_EN_PUB_KEYEVENT,
    	tKOAdjust,
    	MRProc,
    	CEnable,
    },
    //MainMenu\Color\ColorTemp\User\GAdj(_MI_USER_GADJ)
    {
    	_EN_PUB_KEYEVENT,
    	tKOAdjust,
    	MGProc,
    	CEnable,
    },
    //MainMenu\Color\ColorTemp\User\BAdj(_MI_USER_BADJ)
    {
    	_EN_PUB_KEYEVENT,
    	tKOAdjust,
    	MBProc,
    	CEnable,
    },
	#endif		
    // MainMenu\Adjust\AutoAdjust(_MI_AUTOADJUST)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu1,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAdjustProc,            //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Adjust\HPosition(_MI_HPOSITION)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAdjustProc,            //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Adjust\VPosition(_MI_VPOSITION)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAdjustProc,            //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Adjust\Phase(_MI_PHASE)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAdjustProc,            //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Adjust\Clock(_MI_CLOCK)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAdjustProc,            //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Adjust\AutoAdjust\AutoAdjust_OK(_MI_AUTOADJUST_OK)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAutoAdjustProc,        //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Adjust\AutoAdjust\AutoAdjust_Cancel(_MI_AUTOADJUST_CANCEL)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAutoAdjustProc,        //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    // MainMenu\Adjust\HPosition(_MI_ADJUST_HPOSITIONADJ)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOAdjust,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAdjustHPositionProc,   //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Adjust\VPosition(_MI_ADJUST_VPOSITIONADJ)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOAdjust,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAdjustVPositionProc,   //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
	// MainMenu\Adjust\PhaseAdj (_MI_ADJUST_PHASEADJ)
	{
	    _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOAdjust,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAdjustPhaseProc,   //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
	},
	// MainMenu\Adjust\ClockAdj (_MI_ADJUST_CLOCKADJ)
	{
	    _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOAdjust,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAdjustClockProc,   //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
	},
	#endif  
    // MainMenu\OSD\Language(_MI_LANGUAGE)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu1,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MOSDProc,               //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\OSD\HPosition(_MI_OSD_HPOSITION)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MOSDProc,               //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\OSD\VPosition(_MI_OSD_VPOSITION)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MOSDProc,               //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\OSD\Timer(_MI_TIMER)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MOSDProc,               //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\OSD\Double(_MI_DOUBLE)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOSubMenu1,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MOSDProc,               //funcpProc Proc;
        COSDDoubleEN,           //funcpEnable Enable;
    },
    // MainMenu\OSD\Transparent(_MI_TRANSPARENT)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MOSDProc,               //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },

    // MainMenu\OSD\Language\English(_MI_ENGLISH)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MLanguageProc,          //funcpProc Proc;
        CEngEnable,             //funcpEnable Enable;
    },
    // MainMenu\OSD\Language\CHI_S(_MI_CHI_S)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MLanguageProc,          //funcpProc Proc;
        CCHI_S_Enable,          //funcpEnable Enable;
    },
    // MainMenu\OSD\Language\FRA(_MI_FRA)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MLanguageProc,          //funcpProc Proc;
        CFRA_Enable,            //funcpEnable Enable;
    },
    // MainMenu\OSD\Language\ITA(_MI_ITA)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MLanguageProc,          //funcpProc Proc;
        CITA_Enable,            //funcpEnable Enable;
    },
    // MainMenu\OSD\Language\DEU(_MI_DEU)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MLanguageProc,          //funcpProc Proc;
        CDEU_Enable,            //funcpEnable Enable;
    },
    // MainMenu\OSD\Language\ESP(_MI_ESP)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MLanguageProc,          //funcpProc Proc;
        CESP_Enable,            //funcpEnable Enable;
    },
    // MainMenu\OSD\Language\CHI_T(_MI_CHI_T)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MLanguageProc,          //funcpProc Proc;
        CCHI_T_Enable,          //funcpEnable Enable;
    },
    // MainMenu\OSD\Language\JAP(_MI_JAP)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MLanguageProc,          //funcpProc Proc;
        CJAP_Enable,            //funcpEnable Enable;
    },
    // MainMenu\OSD\Language\KOR(_MI_KOR)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MLanguageProc,          //funcpProc Proc;
        CKOR_Enable,            //funcpEnable Enable;
    },
    // MainMenu\OSD\Language\RUS(_MI_RUS)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MLanguageProc,          //funcpProc Proc;
        CRUS_Enable,            //funcpEnable Enable;
    },
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    // MainMenu\OSD\HPosition
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOAdjust,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MHPositionProc,               //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },    
    // MainMenu\OSD\VPosition
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOAdjust,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MVPositionProc,               //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },    
    // MainMenu\OSD\Timer\TimerADJ(_MI_TIMERADJ)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOAdjust,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MTimerProc,               //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },  
	#endif  
    // MainMenu\OSD\Double\Double_On(_MI_DOUBLE_ON)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MDoubleProc,            //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\OSD\Double\Double_Off(_MI_DOUBLE_OFF)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MDoubleProc,            //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    // MainMenu\OSD\Transparent\TransparentADJ(_MI_TIMERADJ)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOAdjust,             	//SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MTransparentProc,       //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    }, 
	#endif  
    // MainMenu\TV\Channel(_MI_CHANNEL)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MTVProc,                //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\TV\System(_MI_SYSTEM)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu1,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MTVProc,                //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\TV\AutoSearch(_MI_AUTOSEARCH)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu1,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MTVProc,                //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\TV\ManualSearch(_MI_MANUALSEARCH)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu1,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MTVProc,                //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\TV\Tuning(_MI_TUNING)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MTVProc,                //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\TV\Skip(_MI_SKIP)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu1,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MTVProc,                //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\TV\Swap(_MI_SWAP)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MTVProc,                //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\TV\AFC(_MI_AFC)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOSubMenu1,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MTVProc,                //funcpProc Proc;
        CAFCEnable,             //funcpEnable Enable;
    },
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)    
    // MainMenu\TV\Channel(_MI_CHANNEL)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOAdjust,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MChannelProc,           //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
	#endif    
    // MainMenu\TV\System\S_NTSC_M(_MI_S_NTSC_M)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSystemProc,            //funcpProc Proc;
        CEnNtsc_M,              //funcpEnable Enable;
    },
    // MainMenu\TV\System\S_NTSC_4_BG(_MI_S_NTSC_4_BG)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSystemProc,            //funcpProc Proc;
        CEnNtsc_BG,             //funcpEnable Enable;
    },
    // MainMenu\TV\System\S_NTSC_4_DK(_MI_S_NTSC_4_DK)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSystemProc,            //funcpProc Proc;
        CEnNtsc_DK,             //funcpEnable Enable;
    },
    // MainMenu\TV\System\S_NTSC_4_I(_MI_S_NTSC_4_I)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSystemProc,            //funcpProc Proc;
        CEnNtsc_I,              //funcpEnable Enable;
    },
    // MainMenu\TV\System\S_TV_PAL_M(_MI_S_TV_PAL_M)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSystemProc,            //funcpProc Proc;
        CEnPal_M,               //funcpEnable Enable;
    },
    // MainMenu\TV\System\S_PAL_BG(_MI_S_PAL_BG)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSystemProc,            //funcpProc Proc;
        CEnPal_BG,              //funcpEnable Enable;
    },
    // MainMenu\TV\System\S_PAL_I(_MI_S_PAL_I)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSystemProc,            //funcpProc Proc;
        CEnPal_I,               //funcpEnable Enable;
    },
    // MainMenu\TV\System\S_PAL_DK(_MI_S_PAL_DK)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSystemProc,            //funcpProc Proc;
        CEnPal_DK,              //funcpEnable Enable;
    },
    // MainMenu\TV\System\S_PAL_N(_MI_S_PAL_N)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSystemProc,            //funcpProc Proc;
        CEnPal_N,               //funcpEnable Enable;
    },
    // MainMenu\TV\System\S_SECAM_BG(_MI_S_SECAM_BG)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSystemProc,            //funcpProc Proc;
        CEnSecam_BG,            //funcpEnable Enable;
    },
    // MainMenu\TV\System\S_SECAM_DK(_MI_S_SECAM_DK)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSystemProc,            //funcpProc Proc;
        CEnSecam_DK,            //funcpEnable Enable;
    },
    // MainMenu\TV\System\S_SECAM_L(_MI_S_SECAM_L)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSystemProc,            //funcpProc Proc;
        CEnSecam_L,             //funcpEnable Enable;
    },
    // MainMenu\TV\System\S_SECAM_LL(_MI_S_SECAM_LL)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSystemProc,            //funcpProc Proc;
        CEnSecam_LL,            //funcpEnable Enable;
    },

    // MainMenu\TV\AutoSearch\AutoSearch_OK(_MI_AUTOSEARCH_OK)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAutoSearchProc,        //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\TV\AutoSearch\AutoSearch_Cancel(_MI_AUTOSEARCH_CANCEL)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAutoSearchProc,        //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\TV\ManualSearch\ManualSearch_Up(_MI_MANUALSEARCH_UP)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MManualSearchProc,      //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\TV\ManualSearch\ManualSearch_Down(_MI_MANUALSEARCH_DOWN)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MManualSearchProc,      //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)    
    // MainMenu\TV\Tuning(_MI_TUNING)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOAdjust,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MTuningProc,           //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
	#endif    
    // MainMenu\TV\Skip\Skip_On(_MI_SKIP_ON)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSkipProc,              //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\TV\Skip\Skip_Off(_MI_SKIP_OFF)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSkipProc,              //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },

    // MainMenu\TV\AFC\AFC_On(_MI_AFC_ON)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAFCProc,              //funcpProc Proc;
        CAFCEnable,                //funcpEnable Enable;
    },
    // MainMenu\TV\AFC\AFC_Off(_MI_AFC_OFF)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAFCProc,              //funcpProc Proc;
        CAFCEnable,                //funcpEnable Enable;
    },
    
    // MainMenu\Function\Reset(_MI_RESET)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu1,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFunctionProc,          //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Function\DisplayRatio(_MI_DISPLAYRATIO)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOSubMenu1,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFunctionProc,          //funcpProc Proc;
        MDisplayRatioEnable,    //funcpEnable Enable;
    },
    // MainMenu\Function\AutoPowerDown(_MI_AUTOPOWERDOWN)
    {
        _EN_PUB_KEYEVENT| _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOSubMenu1,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFunctionProc,          //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Function\BlueScreen(_MI_BLUESCREEN)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOSubMenu1,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFunctionProc,          //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Function\Sharpness(_MI_SHARPNESS)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu1,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFunctionProc,          //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },

    // MainMenu\Function\Reset\Reest_OK(_MI_RESET_OK)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MResetProc,             //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Function\Reset\Reset_Cancel(_MI_RESET_CANCEL)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MResetProc,             //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Function\DisplayRatio\DisplayRatio_Full(_MI_DISPLAYRATIO_FULL)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MDisplayRatioProc,      //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Function\DisplayRatio\DisplayRatio_4_3(_MI_DISPLAYRATIO_4_3)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MDisplayRatioProc,      //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Function\AutoPowerDown\AutoPowerDown_Off(_MI_AUTOPOWERDOWN_OFF)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MDisplayRatioProc,      //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Function\AutoPowerDown\AutoPowerDown_Off(_MI_AUTOPOWERDOWN_OFF)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAutoPowerDownProc,     //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Function\AutoPowerDown\APD_15(_MI_APD_15)
    {
        _EN_PUB_KEYEVENT| _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAutoPowerDownProc,     //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Function\AutoPowerDown\APD_30(_MI_APD_30)
    {
        _EN_PUB_KEYEVENT| _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAutoPowerDownProc,     //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Function\AutoPowerDown\APD_45(_MI_APD_45)
    {
        _EN_PUB_KEYEVENT| _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAutoPowerDownProc,     //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Function\AutoPowerDown\APD_60(_MI_APD_60)
    {
        _EN_PUB_KEYEVENT| _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAutoPowerDownProc,     //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Function\AutoPowerDown\APD_75(_MI_APD_75)
    {
        _EN_PUB_KEYEVENT| _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAutoPowerDownProc,     //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Function\AutoPowerDown\APD_90(_MI_APD_90)
    {
        _EN_PUB_KEYEVENT| _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAutoPowerDownProc,     //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Function\AutoPowerDown\APD_105(_MI_APD_105)
    {
        _EN_PUB_KEYEVENT| _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAutoPowerDownProc,     //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Function\AutoPowerDown\APD_120(_MI_APD_120)
    {
        _EN_PUB_KEYEVENT| _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MAutoPowerDownProc,     //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },

    // MainMenu\Function\BlueScreen\BlueScreen_On(_MI_BLUESCREEN_ON)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MBlueScreenProc,        //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Function\BlueScreen\BlueScreen_Off(_MI_BLUESCREEN_OFF)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOMainMenu,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MBlueScreenProc,        //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    // MainMenu\Function\Sharpness\SharpnessADJ(_MI_SHARPNESS_ADJ)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOAdjust,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSharpnessProc,         //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },   	
	#endif   
    // MainMenu\Sound\Volume(_MI_VOLUME)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSoundProc,             //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    // MainMenu\Sound\Balance(_MI_BALANCE)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSoundProc,             //funcpProc Proc;
        MSoundEnable,           //funcpEnable Enable;
    },
    // MainMenu\Sound\Bass(_MI_BASS)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSoundProc,             //funcpProc Proc;
        MSoundEnable,           //funcpEnable Enable;
    },
    // MainMenu\Sound\Treble(_MI_TREBLE)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSoundProc,             //funcpProc Proc;
        MSoundEnable,           //funcpEnable Enable;
    },
    // MainMenu\Sound\SRS(_MI_SRS)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSoundProc,             //funcpProc Proc;
        MNJW1144Enable,         //funcpEnable Enable;
    },
    // MainMenu\Sound\BBE(_MI_BBE)
    {
        _EN_PUB_KEYEVENT | _DISABLE_NOT_SHOW,       //BYTE Option;
        tKOSubMenu,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSoundProc,             //funcpProc Proc;
        MNJW1144Enable,         //funcpEnable Enable;
    },
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
   	// MainMenu\Sound\Volume\VolumeADJ(_MI_VOLUMEADJ)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOAdjust,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MVolumeProc,             //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },   	
   	// MainMenu\Sound\Balance\BalanceADJ(_MI_BALANCEADJ)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOAdjust,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MBalanceProc,             //funcpProc Proc;
        MSoundEnable,                //funcpEnable Enable;
    },   	
   	// MainMenu\Sound\Bass\BassADJ(_MI_BASSADJ)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOAdjust,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MBassProc,             //funcpProc Proc;
        MSoundEnable,                //funcpEnable Enable;
    },   	   	
   	// MainMenu\Sound\Treble\TrebleADJ(_MI_TREBLEADJ)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOAdjust,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MTrebleProc,            //funcpProc Proc;
        MSoundEnable,           //funcpEnable Enable;
    },   	   	
	#endif
#if(_CHANGE_SOURCE_METHOD == _CHANGE_SOURCE_METHOD_0)
	// Source
    // Source\VGA(_MI_SOURCE_VGA)
    {
        _DISABLE_NOT_SHOW | _KEYMAP_EN_IN_NOSIGNAL,       //BYTE Option;
        tKOSource,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSourceProc,            //funcpProc Proc;
        CMIVgaEnable,           //funcpEnable Enable;
    },
    // Source\DVI(_MI_SOURCE_DVI)
    {
        _DISABLE_NOT_SHOW | _KEYMAP_EN_IN_NOSIGNAL,       //BYTE Option;
        tKOSource,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSourceProc,            //funcpProc Proc;
        CMIDVIEnable,             //funcpEnable Enable;
    },
    // Source\HDMI(_MI_SOURCE_HDMI)
    {
        _DISABLE_NOT_SHOW | _KEYMAP_EN_IN_NOSIGNAL,       //BYTE Option;
        tKOSource,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSourceProc,            //funcpProc Proc;
        CMIHDMIEnable,            //funcpEnable Enable;
    },
    // Source\YPBPR(_MI_SOURCE_YPBPR)
    {
        _DISABLE_NOT_SHOW | _KEYMAP_EN_IN_NOSIGNAL,       //BYTE Option;
        tKOSource,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSourceProc,            //funcpProc Proc;
        CMIYPBPREnable,         //funcpEnable Enable;
    },
    // Source\AV(_MI_SOURCE_AV)
    {
        _DISABLE_NOT_SHOW | _KEYMAP_EN_IN_NOSIGNAL,       //BYTE Option;
        tKOSource,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSourceProc,            //funcpProc Proc;
        CMIAVEnable,            //funcpEnable Enable;
    },
    // Source\SV(_MI_SOURCE_SV)
    {
        _DISABLE_NOT_SHOW | _KEYMAP_EN_IN_NOSIGNAL,       //BYTE Option;
        tKOSource,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSourceProc,            //funcpProc Proc;
        CMISVEnable,            //funcpEnable Enable;
    },
    // Source\TV(_MI_SOURCE_TV)
    {
        _DISABLE_NOT_SHOW | _KEYMAP_EN_IN_NOSIGNAL,       //BYTE Option;
        tKOSource,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MSourceProc,            //funcpProc Proc;
        CMITVEnable,            //funcpEnable Enable;
    },
#endif
    
    // Short Cut menu\Brightness(_MI_SC_BRIGHTNESS)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOShortCut,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MScBrightnessProc,      //funcpProc Proc;
        CEnable,            	//funcpEnable Enable;
    },

    // Short Cut menu\Volume(_MI_SC_VOLUME)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOShortCutVolume,      //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MScVolumeProc,      	//funcpProc Proc;
        CEnable,            	//funcpEnable Enable;
    },
  
    // Short Cut menu\Input ch number(_MI_SC_INPUT_CH_NUM)
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOShortInputCHMenu,    //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MScInputChNumProc,    	//funcpProc Proc;
        CMITVEnable,           	//funcpEnable Enable;
    },
//------------------------------------------------------------
	#if(_FAC_OSD)
    //Factory menu
    //Factory menu/(AUTOCLOR)_MI_FAC_AUTOCOLOR
    {
    	_DISABLE_NOT_SHOW,      //BYTE Option;
        tKOFactory,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFactoryProc,           //funcpProc Proc;
        CEnable,           //funcpEnable Enable;
    },
    //Factory menu/(GAIN)_MI_FAC_GAIN
    {
    	_DISABLE_NOT_SHOW | _KEYMAP_EN_IN_NOSIGNAL,       //BYTE Option;
        tKOFactory,             //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFactoryProc,           //funcpProc Proc;
        CEnable,           //funcpEnable Enable;
    },
    //Factory menu/(OFFSET)_MI_FAC_OFFSET
    {
    	_DISABLE_NOT_SHOW | _KEYMAP_EN_IN_NOSIGNAL,       //BYTE Option;
        tKOFactory,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFactoryProc,            //funcpProc Proc;
        CEnable,           //funcpEnable Enable;
    },
    //Factory menu/(9300)_MI_FAC_9300
    {
    	_DISABLE_NOT_SHOW | _KEYMAP_EN_IN_NOSIGNAL,       //BYTE Option;
        tKOFactory,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFactoryProc,            //funcpProc Proc;
        CEnable,           //funcpEnable Enable;
    },
    //Factory menu/(6500)_MI_FAC_6500
    {
    	_DISABLE_NOT_SHOW | _KEYMAP_EN_IN_NOSIGNAL,       //BYTE Option;
        tKOFactory,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFactoryProc,            //funcpProc Proc;
        CEnable,           //funcpEnable Enable;
    },
    //Factory menu/(BURNIN)_MI_FAC_BURNIN
    {
    	_DISABLE_NOT_SHOW | _KEYMAP_EN_IN_NOSIGNAL,       //BYTE Option;
        tKOFactory,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFactoryProc,            //funcpProc Proc;
        CEnable,           //funcpEnable Enable;
    },
    //Factory menu/(GAMMA)_MI_GAMMA
    {
    	_DISABLE_NOT_SHOW | _KEYMAP_EN_IN_NOSIGNAL,       //BYTE Option;
        tKOFactory,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFactoryProc,            //funcpProc Proc;
        CEnable,           //funcpEnable Enable;
    },
    //Factory menu/(N.R)_MI_FAC_NR
    {
    	_DISABLE_NOT_SHOW | _KEYMAP_EN_IN_NOSIGNAL,       //BYTE Option;
        tKOFactory,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFactoryProc,            //funcpProc Proc;
        CEnable,           //funcpEnable Enable;
    },
    //Factory menu/(EXIT)_MI_FAC_EXIT
    {
    	_DISABLE_NOT_SHOW | _KEYMAP_EN_IN_NOSIGNAL,       //BYTE Option;
        tKOFactory,              //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFactoryProc,            //funcpProc Proc;
        CEnable,           //funcpEnable Enable;
    },
    //Factory menu/(9300_R) _MI_FAC_9300_R
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOFactorySub,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFac9300Proc,        //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    //Factory menu/(9300_G) _MI_FAC_9300_G
    /*{
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOFactorySub,          //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFacGammaProc,          //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },*/
    //Factory menu/(9300_B) _MI_FAC_9300_B
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOFactorySub,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFac9300Proc,        //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    //Factory menu/(6500_R) _MI_FAC_6500_R
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOFactorySub,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFac6500Proc,        //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    }, 
 	//Factory menu/(6500_G) _MI_FAC_6500_G
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOFactorySub,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFac6500Proc,        //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    }, 
    //Factory menu/(6500_B) _MI_FAC_6500_B
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOFactorySub,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFac6500Proc,        //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    }, 
    //Factory menu/(GAIN_R) _MI_FAC_GAIN_R
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOFactorySub,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFacGainProc,        //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    }, 
    //Factory menu/(GAIN_G) _MI_FAC_GAIN_G
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOFactorySub,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFacGainProc,        //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    }, 
    //Factory menu/(GAIN_B) _MI_FAC_GAIN_B
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOFactorySub,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFacGainProc,        //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    //Factory menu/(OFFSET_R) _MI_FAC_OFFSET_R
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOFactorySub,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFacOffsetProc,        //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    //Factory menu/(OFFSET_G) _MI_FAC_OFFSET_G
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOFactorySub,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFacOffsetProc,        //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },
    //Factory menu/(OFFSET_B) _MI_FAC_OFFSET_B
    {
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOFactorySub,            //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFacOffsetProc,        //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },

    //Factory menu/(GAMMA) _MI_FAC_GAMMA_ADJ
    /*{
        _EN_PUB_KEYEVENT,       //BYTE Option;
        tKOFactorySub,          //SKeyToOsdEvent *KeyMsgToOsdEvnet;
        MFacGammaProc,          //funcpProc Proc;
        CEnable,                //funcpEnable Enable;
    },*/
#endif
};
//------------------------------------------------------------

#endif 	//#if(_OSD_TYPE == _OSD003)

