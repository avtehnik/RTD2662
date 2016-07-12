

#define __OSDTABLE002__


#include "Core\Header\Include.h"


#if(_OSD_TYPE == _OSD002)

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
        NULL,           							// funcpMenuRun MenuRun
    },
};
//------------------------------------------------------------

code SMenuItem tMenuExitItem[] =
{
    {   // Active
        _EN_PUB_PROCFUNC,        					// BYTE Option;
        tKOMenuNone,    							// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        _P_MAIN_MENU,      							// SMenu *SubMenu,                         // 可以为NULL
        NULL,           							// void (*Proc)(void);                     // 可以为NULL
        CEnable,        							// bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CDrawNull,      							// void (*Draw)(BYTE ucDrawID);            // 不能为NULL,原因同上
        NULL,           							// funcpMenuRun MenuRun
    },
};
//------------------------------------------------------------

code SMenuItem tMainMenuItem[] =
{
    {   // _MI_COLOR
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMainMenu,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        _P_COLOR_MENU,                              // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawCOLOR,                               // funcpDraw Draw                          // 不能为NULL,原因同上
        CMICOLORRun,                                // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_ADJUST
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMainMenu,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        _P_ADJUST_MENU,                             // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CMIVGAEnable,                         		// funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawADJUST,                              // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIADJUSTRun,                               // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_OSD
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMainMenu,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        _P_OSD_MENU,                                // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawOSD,                                 // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIOSDRun,                                  // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_TV
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMainMenu,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        _P_TV_MENU,                                 // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CMITVEnable,                               	// funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawTV,                                  // funcpDraw Draw                          // 不能为NULL,原因同上
        CMITVRun,                                   // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_FUNCTION
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMainMenu,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        _P_FUNC_MENU,                               // int SubMenuID                           // 可以为NULL
        NULL,                                		// SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawFUNCTION,                            // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIFUNCTIONRun,                             // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_EXIT
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMainMenu,                            			// SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        _P_MENU_EXIT,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawEXIT,                                // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIEXITRun,                                 // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
};
//------------------------------------------------------------
code SMenuItem tColorMenuItem[] =
{
    {   // _MI_BRIGHTNESS
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawBrightness,                          // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIBrightnessRun,                           // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_CONTRAST
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        //BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawContrast,                            // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIContrastRun,                             // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_HUE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        //BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CMIVedioEnable,                             // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawHue,                                 // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIHueRun,                                  // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_SATURATION
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        //BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CMIVedioEnable,                             // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawSaturation,                          // funcpDraw Draw                          // 不能为NULL,原因同上
        CMISaturationRun,                           // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_COLORTEMP
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        //BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CMIVGAEnable,                               // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawColorTemp,                           // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIColorTempRun,                            // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_COLORRETURN
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        //BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawColorReturn,                         // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIColorReturnRun,                          // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
};
//------------------------------------------------------------
code SMenuItem tAdjustMenuItem[] =
{
    {   // _MI_AUTOCONFIG
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CMIVGAEnable,                               // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawAutoConfig,                          // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIAutoConfigRun,                           // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_HPOSITION
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CMIVGAEnable,                               // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawHPosition,                           // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIHPositionRun,                            // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_VPOSITION
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CMIVGAEnable,                               // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawVPosition,                           // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIVPositionRun,                            // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_PHASE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CMIVGAEnable,                               // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawPhase,                               // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIPhaseRun,                                // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_CLOCK
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CMIVGAEnable,                               // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawClock,                               // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIClockRun,                                // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_ADJUSTRETURN
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                               	    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawAdjustReturn,                        // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIAdjustReturnRun,                         // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
};
//------------------------------------------------------------
code SMenuItem tOsdMenuItem[] =
{
    {   // _MI_LANGUAGE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawLanguage,                            // funcpDraw Draw                          // 不能为NULL,原因同上
        CMILanguageRun,                             // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_HPOSITION
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawOSDHPosition,                           // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIOSDHPositionRun,                            // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_VPOSITION
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawOSDVPosition,                           // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIOSDVPositionRun,                            // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_TIMER
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawTimer,                               // funcpDraw Draw                          // 不能为NULL,原因同上
        CMITimerRun,                                // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_DOUBLE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawDouble,                              // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIDoubleRun,                               // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_TRANSPARENT
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawTransparent,                         // funcpDraw Draw                          // 不能为NULL,原因同上
        CMITransparentRun,                          // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_OSDRETURN
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawOsdReturn,                           // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIOsdReturnRun,                            // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    
};
//------------------------------------------------------------
code SMenuItem tTVMenuItem[] =
{
    {   // _MI_SYSTEM
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CMITVFMEnable,                              // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawSystem,                              // funcpDraw Draw                          // 不能为NULL,原因同上
        CMISystemRun,                               // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_CHANNEL
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CMITVEnable,                                // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawChannel,                             // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIChannelRun,                              // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_AUTOSEARCH
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CMITVEnable,                                // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawAutoSearch,                          // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIAutoSearchRun,                           // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_MANUALSEARCH
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CMITVFMEnable,                              // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawManualSearch,                        // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIManualSearchRun,                         // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_TUNING
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CMITVEnable,                                // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawTuning,                              // funcpDraw Draw                          // 不能为NULL,原因同上
        CMITuningRun,                               // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_SKIP
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CMITVEnable,                                // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawSkip,                                // funcpDraw Draw                          // 不能为NULL,原因同上
        CMISkipRun,                                 // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
#if(_SLEEP_FUNC)
    {   // _MI_AUTOPOWERDOWN
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CMITVFMEnable,                              // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawAutoPowerDown,                       // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIAutoPowerDownRun,                        // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
#endif
    {   // _MI_BLUESCREEN
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CMITVFMEnable,                              // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawBlueScreen,                          // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIBlueScreenRun,                           // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_TVRETURN
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawTVReturn,                            // funcpDraw Draw                          // 不能为NULL,原因同上
        CMITVReturnRun,                             // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
};
//------------------------------------------------------------
code SMenuItem tFuncMenuItem[] =
{
    {   // _MI_RESET
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawReset,                               // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIResetRun,                                // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
#if(_DISPLAY_RATIO)
    {   // _MI_DISPLAYRATIO
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawDisplayRatio,                        // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIDisplayRatioRun,                         // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
#endif
    {   // _MI_VOLUME
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawVolume,                              // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIVolumeRun,                               // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_MUTE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawMute,                                // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIMuteRun,                                 // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    }, 
#if (_SOUND_PROCESSOR)
    {   // _MI_BALANCE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawBalance,                             // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIBalanceRun,                              // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_BASS
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawBass,                                // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIBassRun,                                 // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_TREBLE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawTreble,                              // funcpDraw Draw                          // 不能为NULL,原因同上
        CMITrebleRun,                               // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
   #if(AUDIO_TYPE != _AUDIO_SC7313)
    {   // _MI_SRS
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawSRS,                                 // funcpDraw Draw                          // 不能为NULL,原因同上
        CMISRSRun,                                  // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_BBE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawBBE,                                 // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIBBERun,                                  // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
   #endif
#endif
#if(_FM_DEVICE)
    {   // _MI_FM
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawFM,                                  // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIFMRun,                                   // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
#endif
    {   // _MI_FUNCRETURN
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // 可以为NULL
        NULL,                                       // int SubMenuID                           // 可以为NULL
        NULL,                                       // funcpProc Proc                          // 可以为NULL
        CEnable,                                    // funcpEnable Enable                      // 不能为NULL,因为调用的地方多
        CMIDrawFuncReturn,                          // funcpDraw Draw                          // 不能为NULL,原因同上
        CMIFuncReturnRun,                           // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
};
//------------------------------------------------------------


code SMenuItem tShortMenuItem[] =
{
    {   // _MI_SMBRIGHT,
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option;
        tKOShortBriMenu,   							// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        0,      									// SMenu *SubMenu,                         // 可以为NULL
        NULL,           							// void (*Proc)(void);                     // 可以为NULL
        CEnable,        							// bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawSMBright,                            // funcpDraw Draw                          // 不能为NULL,原因同上
        CMISMBrightRun,                             // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_SMVOLUME,
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option;
        tKOShortVolMenu,   							// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        0,      									// SMenu *SubMenu,                         // 可以为NULL
        NULL,           							// void (*Proc)(void);                     // 可以为NULL
        CEnable,        							// bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawSMVolume,                            // funcpDraw Draw                          // 不能为NULL,原因同上
        CMISMVolumeRun,                             // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_SMMUTE,
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option;
        tKOShortMute,      							// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        0,      									// SMenu *SubMenu,                         // 可以为NULL
        NULL,           							// void (*Proc)(void);                     // 可以为NULL
        CEnable,        							// bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawSMMute,                              // funcpDraw Draw                          // 不能为NULL,原因同上
        CMISMMuteRun,                               // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
    {   // _MI_SMINPUT_CH,
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option;
        tKOShortInputCHMenu,						// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // 可以为NULL
        0,      									// SMenu *SubMenu,                         // 可以为NULL
        NULL,           							// void (*Proc)(void);                     // 可以为NULL
        CMITVEnable,       							// bit (*Enable)(void);                    // 不能为NULL,因为调用的地方多.如果为空要增加很多额外的
        CMIDrawSMInputCh,                           // funcpDraw Draw                          // 不能为NULL,原因同上
        CMISMInputChRun,                            // funcpMenuRun MenuRun                    // 不能为NULL,原因同上
    },
};
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
	{	//_P_MENU_EXIT
	    _P_MENU_EXIT,                                               //TMenuItem *ParentMenu;
	    0,                                                          //BYTE ParentMenuItemIndex;
	    sizeof(tMenuExitItem)/sizeof(SMenuItem),                    //BYTE MenuItemCount;
	    tMenuExitItem,                                              //TMenuItem *Menu;
	    CCloseOSD,                                                  //void (*Draw)(BYTE ucDrawID);
	},
	// 主菜单
	{	//_P_MAIN_MENU
	    _P_MENU_NONE,                                               //TMenuItem *ParentMenu;
	    0,                                                          //BYTE ParentMenuItemIndex;
	    sizeof(tMainMenuItem)/sizeof(SMenuItem),                    //BYTE MenuItemCount;
	    tMainMenuItem,                                              //TMenuItem *Menu;
	    CPDrawMainMenu,                                              //void (*Draw)(BYTE ucDrawID);
	},
	// 子菜单
	{	//_P_COLOR_MENU
	    _P_MAIN_MENU,                                               //TMenuItem *ParentMenu;
	    _MI_COLOR,                                                  //BYTE ParentMenuItemIndex;
	    sizeof(tColorMenuItem)/sizeof(SMenuItem),                  	//BYTE MenuItemCount;
	    tColorMenuItem,                                             //TMenuItem *Menu;
	    CPDrawColorMenu,                                            //void (*Draw)(BYTE ucDrawID);
	},
    {   //_P_ADJUST_MENU
        _P_MAIN_MENU,                                               //TMenuItem *ParentMenu;
        _MI_ADJUST,                                                 //BYTE ParentMenuItemIndex;
        sizeof(tAdjustMenuItem)/sizeof(SMenuItem),                  //BYTE MenuItemCount;
        tAdjustMenuItem,                                            //TMenuItem *Menu;
        CPDrawAdjustMenu,                                           //void (*Draw)(BYTE ucDrawID);
    },
    {   //_P_OSD_MENU
        _P_MAIN_MENU,                                               //TMenuItem *ParentMenu;
        _MI_OSD,                                                    //BYTE ParentMenuItemIndex;
        sizeof(tOsdMenuItem)/sizeof(SMenuItem),                     //BYTE MenuItemCount;
        tOsdMenuItem,                                               //TMenuItem *Menu;
        CPDrawOsdMenu,                                              //void (*Draw)(BYTE ucDrawID);
    },
    {   //_P_TV_MENU
        _P_MAIN_MENU,                                               //TMenuItem *ParentMenu;
        _MI_TV,                                                     //BYTE ParentMenuItemIndex;
        sizeof(tTVMenuItem)/sizeof(SMenuItem),                      //BYTE MenuItemCount;
        tTVMenuItem,                                                //TMenuItem *Menu;
        CPDrawTVMenu,                                               //void (*Draw)(BYTE ucDrawID);
    },
    {   //_P_FUNC_MENU
        _P_MAIN_MENU,                                               //TMenuItem *ParentMenu;
        _MI_FUNCTION,                                               //BYTE ParentMenuItemIndex;
        sizeof(tFuncMenuItem)/sizeof(SMenuItem),                    //BYTE MenuItemCount;
        tFuncMenuItem,                                              //TMenuItem *Menu;
        CPDrawFuncMenu,                                             //void (*Draw)(BYTE ucDrawID);
    }, 

    //快捷菜单
    {   //_P_SHORT_MENU   
	    _P_MENU_NONE,                                               //TMenuItem *ParentMenu;
	    0,                                                          //BYTE ParentMenuItemIndex;
        sizeof(tShortMenuItem)/sizeof(SMenuItem),                   //BYTE MenuItemCount;
        tShortMenuItem,                                             //TMenuItem *Menu;
        CPDrawShowMenu,                                             //void (*Draw)(BYTE ucDrawID);
    }, 
	
};
//------------------------------------------------------------



#endif 	//#if(_OSD_TYPE == _OSD002)

