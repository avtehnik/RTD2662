#if(_KEY_TYPE == _KT_PCB2660_002)

#define _FUNC_EN_CHK_KEY_DOWN       0
#define _FUNC_EN_CHK_KEY_UP         0

#define _MENU_KEY_MASK              _BIT1
#define _LEFT_KEY_MASK              _BIT2
#define _RIGHT_KEY_MASK             _BIT3
#define _UP_KEY_MASK                _BIT4
#define _DOWN_KEY_MASK              _BIT5
#define _SOURCE_KEY_MASK            _BIT6


#ifdef __KEY__


// 公用按键消息转表
SKeyToOsdEvent code tKOPublic[] = 
{
    {_MENU_KEY_MESSAGE,         _OE_RETURN_UPMENU },
    {_RIGHT_KEY_MESSAGE,        _OE_MENU_NEXT     },
    {_LEFT_KEY_MESSAGE,         _OE_MENU_PREV     },

    // Shortcut key message
    {_SOURCE_KEY_MESSAGE,       _OE_CHANGE_SOURCE },
    {_MUTE_KEY_MESSAGE,         _OE_SC_MUTE       },
    {_VOL_DEC_KEY_MESSAGE,      _OE_SC_VOLUME     },
    {_VOL_INC_KEY_MESSAGE,      _OE_SC_VOLUME     },
    {_CH_DEC_KEY_MESSAGE,       _OE_SC_CH_DEC     },
    {_CH_INC_KEY_MESSAGE,       _OE_SC_CH_INC     },
    {_NUM_0_KEY_MESSAGE,        _OE_SC_NUM0       },
    {_NUM_1_KEY_MESSAGE,        _OE_SC_NUM1       },
    {_NUM_2_KEY_MESSAGE,        _OE_SC_NUM2       },
    {_NUM_3_KEY_MESSAGE,        _OE_SC_NUM3       },
    {_NUM_4_KEY_MESSAGE,        _OE_SC_NUM4       },
    {_NUM_5_KEY_MESSAGE,        _OE_SC_NUM5       },
    {_NUM_6_KEY_MESSAGE,        _OE_SC_NUM6       },
    {_NUM_7_KEY_MESSAGE,        _OE_SC_NUM7       },
    {_NUM_8_KEY_MESSAGE,        _OE_SC_NUM8       },
    {_NUM_9_KEY_MESSAGE,        _OE_SC_NUM9       },
    {_INPUT_CH_KEY_MESSAGE,     _OE_SC_INPUT_CH   },
    {_RETURN_KEY_MESSAGE,       _OE_SC_RETURN     },
    
    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },

};
//------------------------------------------------------------
// 无信号按键消息转表
SKeyToOsdEvent code tKONoSignal[] = 
{
    {_SOURCE_KEY_MESSAGE,       _OE_CHANGE_SOURCE },

    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG},

};
//------------------------------------------------------------
// 无菜单按键消息转表
SKeyToOsdEvent code tKOMenuNone[] = 
{
    {_MENU_KEY_MESSAGE,         _OE_ENTER_SUBMENU      },

    // Shortcut key message
    {_SOURCE_KEY_MESSAGE,       _OE_CHANGE_SOURCE      }, 
    {_RIGHT_KEY_MESSAGE,        _OE_SC_VOLUME          },
    {_LEFT_KEY_MESSAGE,         _OE_SC_VOLUME          },
    {_UP_KEY_MESSAGE,           _OE_SC_CH_INC          },
    {_DOWN_KEY_MESSAGE,         _OE_SC_CH_DEC          },
    {_MUTE_KEY_MESSAGE,         _OE_SC_MUTE            },
    {_VOL_DEC_KEY_MESSAGE,      _OE_SC_VOLUME          },
    {_VOL_INC_KEY_MESSAGE,      _OE_SC_VOLUME          },
    {_CH_DEC_KEY_MESSAGE,       _OE_SC_CH_DEC          },
    {_CH_INC_KEY_MESSAGE,       _OE_SC_CH_INC          },
    {_NUM_0_KEY_MESSAGE,        _OE_SC_NUM0            },
    {_NUM_1_KEY_MESSAGE,        _OE_SC_NUM1            },
    {_NUM_2_KEY_MESSAGE,        _OE_SC_NUM2            },
    {_NUM_3_KEY_MESSAGE,        _OE_SC_NUM3            },
    {_NUM_4_KEY_MESSAGE,        _OE_SC_NUM4            },
    {_NUM_5_KEY_MESSAGE,        _OE_SC_NUM5            },
    {_NUM_6_KEY_MESSAGE,        _OE_SC_NUM6            },
    {_NUM_7_KEY_MESSAGE,        _OE_SC_NUM7            },
    {_NUM_8_KEY_MESSAGE,        _OE_SC_NUM8            },
    {_NUM_9_KEY_MESSAGE,        _OE_SC_NUM9            },
    {_INPUT_CH_KEY_MESSAGE,     _OE_SC_INPUT_CH        },
    {_RETURN_KEY_MESSAGE,       _OE_SC_RETURN          },

    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG              },

};
//------------------------------------------------------------
// 主菜单消息转换
SKeyToOsdEvent code tKOMainMenu[] = 
{
    {_DOWN_KEY_MESSAGE,         _OE_ENTER_SUBMENU},
    {_UP_KEY_MESSAGE,           _OE_ENTER_SUBMENU},
    
    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG},
};
//------------------------------------------------------------

SKeyToOsdEvent code tKOMenuItem[] = 
{
    {_RIGHT_KEY_MESSAGE,        _OE_ADJ_INC},
    {_LEFT_KEY_MESSAGE,         _OE_ADJ_DEC},
    {_DOWN_KEY_MESSAGE,         _OE_MENU_NEXT},
    {_UP_KEY_MESSAGE,           _OE_MENU_PREV},
    
    
    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG},

};

//------------------------------------------------------------
// Shortcut key volume
SKeyToOsdEvent code tKOShortVolMenu[] = 
{
    {_RIGHT_KEY_MESSAGE,        _OE_ADJ_INC   },
    {_LEFT_KEY_MESSAGE,         _OE_ADJ_DEC   },
    {_UP_KEY_MESSAGE,           _OE_SC_CH_INC },
    {_DOWN_KEY_MESSAGE,         _OE_SC_CH_DEC },
    
    
    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG     },

};

//------------------------------------------------------------
// Shortcut key brightness
SKeyToOsdEvent code tKOShortBriMenu[] = 
{
    {_RIGHT_KEY_MESSAGE,        _OE_ADJ_INC},
    {_LEFT_KEY_MESSAGE,         _OE_ADJ_DEC},
    
    
    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG  },

};

//------------------------------------------------------------
// Shortcut key Mute
SKeyToOsdEvent code tKOShortMute[] =
{
    {_RIGHT_KEY_MESSAGE,        _OE_SC_VOLUME},
    {_LEFT_KEY_MESSAGE,         _OE_SC_VOLUME},

    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG    },
};

//------------------------------------------------------------
// Shortcut key inputch
SKeyToOsdEvent code tKOShortInputCHMenu[] = 
{
    {_NUM_0_KEY_MESSAGE,        _OE_SC_INPUT_NUM0            },
    {_NUM_1_KEY_MESSAGE,        _OE_SC_INPUT_NUM1            },
    {_NUM_2_KEY_MESSAGE,        _OE_SC_INPUT_NUM2            },
    {_NUM_3_KEY_MESSAGE,        _OE_SC_INPUT_NUM3            },
    {_NUM_4_KEY_MESSAGE,        _OE_SC_INPUT_NUM4            },
    {_NUM_5_KEY_MESSAGE,        _OE_SC_INPUT_NUM5            },
    {_NUM_6_KEY_MESSAGE,        _OE_SC_INPUT_NUM6            },
    {_NUM_7_KEY_MESSAGE,        _OE_SC_INPUT_NUM7            },
    {_NUM_8_KEY_MESSAGE,        _OE_SC_INPUT_NUM8            },
    {_NUM_9_KEY_MESSAGE,        _OE_SC_INPUT_NUM9            },
    {_INPUT_CH_KEY_MESSAGE,     _OE_SC_INPUT_CHANGE_CH       },
    {_MENU_KEY_MESSAGE,         _OE_RUN                      },
    
    
    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG                    },

};
//------------------------------------------------------------



#else               //#ifdef __PCB2660_002_KEY__

extern SKeyToOsdEvent code tKOPublic[];
extern SKeyToOsdEvent code tKONoSignal[];
extern SKeyToOsdEvent code tKOMenuNone[];
extern SKeyToOsdEvent code tKOMenuRun[];
extern SKeyToOsdEvent code tKOMainMenu[];
extern SKeyToOsdEvent code tKOMenuItem[];
extern SKeyToOsdEvent code tKOShortVolMenu[];
extern SKeyToOsdEvent code tKOShortBriMenu[];
extern SKeyToOsdEvent code tKOShortMute[];
extern SKeyToOsdEvent code tKOShortInputCHMenu[];

#endif              //#ifdef __PCB2660_002_KEY__

BYTE CKeyScan(void);
void CKeyMessageProc(void);

#endif              //#if(_KEY_TYPE == _KT_PCB2660_002)
