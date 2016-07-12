#if(_OSD_TYPE == _OSD003)


//------------------------------------------------------
typedef void (*funcpProc)(void);
typedef bit (*funcpEnable)(void);



typedef enum 
{
    _NONE_MSG,
    
    // system osd event begin
    _SHOW_NOSIGNAL_MSG,
    _SHOW_NOCABLE_MSG,
    _SHOW_NOSUPPORT_MSG,
    _SAVE_EE_MODEUSERDATA_MSG,
    _SAVE_EE_SYSTEMDATA_MSG,
    _SAVE_EE_OSDUSERDATA_MSG,
    _SAVE_EE_ADCDATA_MSG,
    _SAVE_EE_COLORPROC0_MSG,
    _SAVE_EE_COLORPROC1_MSG,
    _SAVE_EE_TV_DATA_MSG,
    _SAVE_EE_AUDIO_DATA_MSG,
    _SAVE_EE_HUE_SAT_DATA_MSG,
    _ENTER_FACTORY_MODE_MSG,
    _DO_AUTO_CONFIG,
    _DO_SHOW_NOTE,
    _CHANGE_SOURCE_MSG,

    // system osd event end
    
    
    _OE_USER_CMD,
    // user osd event begin
    _OE_MENU_NEXT,
    _OE_MENU_PREV,
    _OE_ENTER_SUBMENU,
    _OE_RETURN_UPMENU,
    _OE_ADJ_INC,
    _OE_ADJ_DEC,

    // Factory event
    _OE_FAC_OPEN,

    // Shortcut key event
    _OE_CHANGE_SOURCE,
    _OE_SC_BRIGHTNESS,
    _OE_SC_VOLUME,
    _OE_SC_MUTE,
    _OE_DISPLAY,
    _OE_SC_CH_DEC,
    _OE_SC_CH_INC,
    _OE_SC_INPUT_CH,
    _OE_SC_INPUT_NUM0,
    _OE_SC_INPUT_NUM1,
    _OE_SC_INPUT_NUM2,
    _OE_SC_INPUT_NUM3,
    _OE_SC_INPUT_NUM4,
    _OE_SC_INPUT_NUM5,
    _OE_SC_INPUT_NUM6,
    _OE_SC_INPUT_NUM7,
    _OE_SC_INPUT_NUM8,
    _OE_SC_INPUT_NUM9,
    _OE_SC_INPUT_CHANGE_CH,
    _OE_SC_RETURN

}EOsdEvent;
//------------------------------------------------------

// Option bit define's
#define _EN_PUB_KEYEVENT                _BIT0
#define _DISABLE_NOT_SHOW				_BIT1
#define _KEYMAP_EN_IN_NOSIGNAL			_BIT2

typedef struct 
{
    BYTE Option;                            
    SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
    funcpProc Proc;                         // 可以为NULL
    funcpEnable Enable;                     // 不能为NULL,因为调用的地方多.如果为空要增加很多代码    
}SMenuItem;
//------------------------------------------------------

typedef struct 
{
    BYTE code *Font;		//Font 
	BYTE Width;				//Width
}STitle;
//------------------------------------------------------



#endif		//#if(_OSD_TYPE == _OSD003)

