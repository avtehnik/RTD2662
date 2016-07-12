#if(_OSD_TYPE == _OSD001)


//------------------------------------------------------
typedef bit (*funcpProc)(void);
typedef bit (*funcpEnable)(void);
typedef void  (*funcpDraw)(BYTE ucDrawID);
typedef void (*funcpMenuRun)(BYTE ucMode);


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
    _CHANGE_SOURCE_MSG,
    _DO_AUTO_CONFIG,
    _DO_SHOW_NOTE,


    // system osd event end
    
    
    _OE_USER_CMD,
    // user osd event begin
    _OE_MENU_NEXT,
    _OE_MENU_PREV,
    _OE_ENTER_SUBMENU,
    _OE_RETURN_UPMENU,
    _OE_ADJ_INC,
    _OE_ADJ_DEC,
    _OE_RUN,
    _OE_CHANGE_SOURCE,
    //---------------------------------------------------------
    //快捷菜单 
    _OE_SET_MUTE_STATE,
    _OE_ADJ_VOLUME_MENU,                // 进入调节音量快捷菜单
    _OE_ADJ_BRIGHTNESS_MENU,            // 进入调节亮度快捷菜单
    _OE_CHANNEL_INC,
    _OE_CHANNEL_DEC,
    //---------------------------------------------------------
    _OE_0,
    _OE_1,
    _OE_2,
    _OE_3,
    _OE_4,
    _OE_5,
    _OE_6,
    _OE_7,
    _OE_8,
    _OE_9,
    
}EOsdEvent;
//------------------------------------------------------
typedef enum 
{
    // Menu item draw ID
    _DRAW_MENU_ITEM,        //画菜单项
    _DRAW_NORMARL,          //标准状态
    _DRAW_SELECT,           //选中状态
    _DRAW_DISABLE,          //禁用状态

    // Menu Draw ID
    _DRAW_ENTER_MENU,              //进入当前的菜单时调用
    _DRAW_BEFORE_RETURN_PARENTMENU,//返回到上一级菜单之前...
    _DRAW_BEFORE_ENTER_SUBMENU,    //进入子菜单之前...
    _DRAW_FROM_SUBMENU_RETURN,     //从子菜单返回


    // 自定义项
    // ...
}EMenuDraw;
//------------------------------------------------------

// Option bit define's
#define _EN_PUB_KEYEVENT                _BIT0
#define _EN_PUB_PROCFUNC                _BIT1


typedef struct 
{
    BYTE Option;                            
    SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
    BYTE SubMenuID;                          // 可以为NULL
    funcpProc Proc;                         // 可以为NULL
    funcpEnable Enable;                     // 不能为NULL,因为调用的地方多.如果为空要增加很多代码
    funcpDraw Draw;                         // 不能为NULL,原因同上
    funcpMenuRun MenuRun;                   // 可以为NULL
    
}SMenuItem;
//------------------------------------------------------
typedef struct 
{
    BYTE ParentMenuID;
    BYTE ParentMenuItemIndex;
    BYTE MenuItemCount;
    SMenuItem *Menu;

    funcpDraw Draw;
}SMenu;
//------------------------------------------------------

#endif		//#if(_OSD_TYPE == _OSD001)

