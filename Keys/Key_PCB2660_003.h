#if(_KEY_TYPE == _KT_PCB2660_003)

#define _FUNC_EN_CHK_KEY_DOWN       0
#define _FUNC_EN_CHK_KEY_UP         0

#define _MENU_KEY_MASK              _BIT1
#define _LEFT_KEY_MASK              _BIT2
#define _RIGHT_KEY_MASK             _BIT3
#define _UP_KEY_MASK                _BIT4
#define _DOWN_KEY_MASK              _BIT5
#define _SOURCE_KEY_MASK            _BIT6
#define _FAC_KEY_MASK               (_MENU_KEY_MASK | _LEFT_KEY_MASK)

#if(_KEY1_TYPE == KEY1_RESET)
    #define _RESET_KEY_MASK		    _BIT7/*Modified for sleep key,AndyLiu 20080313*/
#else
    #define _SLEEP_KEY_MASK			_BIT7/*Modified for sleep key,AndyLiu 20080313*/
#endif

#ifdef __KEY__

// Key map
SKeyToOsdEvent code tKONoSignal[] =
{
    {_SOURCE_KEY_MESSAGE,		_OE_CHANGE_SOURCE},

	// End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};

//------------------------------------------------------------
// Key map
SKeyToOsdEvent code tKOPublic[] =
{         /*
    {_MENU_KEY_MESSAGE,         _OE_RETURN_UPMENU },
    {_RIGHT_KEY_MESSAGE,        _OE_MENU_NEXT     },
    {_LEFT_KEY_MESSAGE,         _OE_MENU_PREV     },
                    */
	{_MENU_KEY_MESSAGE,         _OE_ENTER_SUBMENU },
	{_RIGHT_KEY_MESSAGE,		_OE_SC_VOLUME     },
    {_LEFT_KEY_MESSAGE,         _OE_SC_VOLUME     },
    {_UP_KEY_MESSAGE,           _OE_SC_CH_INC     },
    {_DOWN_KEY_MESSAGE,         _OE_SC_CH_DEC     }, 
    {_DISPLAY_KEY_MESSAGE,      _OE_DISPLAY       },
    {_ESC_KEY_MESSAGE,			_OE_RETURN_UPMENU },

    // Shortcut key message
    {_SOURCE_KEY_MESSAGE,       _OE_CHANGE_SOURCE },
    {_MUTE_KEY_MESSAGE,         _OE_SC_MUTE       },
    {_VOL_DEC_KEY_MESSAGE,      _OE_SC_VOLUME     },
    {_VOL_INC_KEY_MESSAGE,      _OE_SC_VOLUME     },
    {_CH_DEC_KEY_MESSAGE,       _OE_SC_CH_DEC     },
    {_CH_INC_KEY_MESSAGE,       _OE_SC_CH_INC     },
    {_NUM_0_KEY_MESSAGE,        _OE_SC_INPUT_NUM0 },
    {_NUM_1_KEY_MESSAGE,        _OE_SC_INPUT_NUM1 },
    {_NUM_2_KEY_MESSAGE,        _OE_SC_INPUT_NUM2 },
    {_NUM_3_KEY_MESSAGE,        _OE_SC_INPUT_NUM3 },
    {_NUM_4_KEY_MESSAGE,        _OE_SC_INPUT_NUM4 },
    {_NUM_5_KEY_MESSAGE,        _OE_SC_INPUT_NUM5 },
    {_NUM_6_KEY_MESSAGE,        _OE_SC_INPUT_NUM6 },
    {_NUM_7_KEY_MESSAGE,        _OE_SC_INPUT_NUM7 },
    {_NUM_8_KEY_MESSAGE,        _OE_SC_INPUT_NUM8 },
    {_NUM_9_KEY_MESSAGE,        _OE_SC_INPUT_NUM9 },
    {_INPUT_CH_KEY_MESSAGE,     _OE_SC_INPUT_CH   },
    {_RETURN_KEY_MESSAGE,       _OE_SC_RETURN     },
    
    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};
//------------------------------------------------------------
// Key map
SKeyToOsdEvent code tKOMenuNone[] =
{
	{_MENU_KEY_MESSAGE,         _OE_ENTER_SUBMENU      },
	{_SOURCE_KEY_MESSAGE,		_OE_CHANGE_SOURCE      },
	{_RIGHT_KEY_MESSAGE,		_OE_SC_VOLUME          },
    {_LEFT_KEY_MESSAGE,         _OE_SC_VOLUME          },
    {_UP_KEY_MESSAGE,           _OE_SC_CH_INC          },
    {_DOWN_KEY_MESSAGE,         _OE_SC_CH_DEC          },
    {_MUTE_KEY_MESSAGE,         _OE_SC_MUTE            },
    {_VOL_DEC_KEY_MESSAGE,      _OE_SC_VOLUME          },
    {_VOL_INC_KEY_MESSAGE,      _OE_SC_VOLUME          },
    {_CH_DEC_KEY_MESSAGE,       _OE_SC_CH_DEC          },
    {_CH_INC_KEY_MESSAGE,       _OE_SC_CH_INC          },
    {_NUM_0_KEY_MESSAGE,        _OE_SC_INPUT_NUM0      },
    {_NUM_1_KEY_MESSAGE,        _OE_SC_INPUT_NUM1      },
    {_NUM_2_KEY_MESSAGE,        _OE_SC_INPUT_NUM2      },
    {_NUM_3_KEY_MESSAGE,        _OE_SC_INPUT_NUM3      },
    {_NUM_4_KEY_MESSAGE,        _OE_SC_INPUT_NUM4      },
    {_NUM_5_KEY_MESSAGE,        _OE_SC_INPUT_NUM5      },
    {_NUM_6_KEY_MESSAGE,        _OE_SC_INPUT_NUM6      },
    {_NUM_7_KEY_MESSAGE,        _OE_SC_INPUT_NUM7      },
    {_NUM_8_KEY_MESSAGE,        _OE_SC_INPUT_NUM8      },
    {_NUM_9_KEY_MESSAGE,        _OE_SC_INPUT_NUM9      },
    {_INPUT_CH_KEY_MESSAGE,     _OE_SC_INPUT_CH        },
    {_RETURN_KEY_MESSAGE,       _OE_SC_RETURN          },
    {_DISPLAY_KEY_MESSAGE,      _OE_DISPLAY            },
    {_FAC_KEY_MESSAGE,			_OE_FAC_OPEN		   },
    {_AUTO_KEY_MESSAGE, 		_DO_AUTO_CONFIG        },  // ESC    
    

 	// End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG              },
};
//------------------------------------------------------------
// Key map
SKeyToOsdEvent code tKOMainMenu[] =
{
    {_MENU_KEY_MESSAGE,         _OE_ENTER_SUBMENU },
    {_UP_KEY_MESSAGE,           _OE_MENU_PREV},
    {_DOWN_KEY_MESSAGE,         _OE_MENU_NEXT},
    {_RIGHT_KEY_MESSAGE,        _OE_ENTER_SUBMENU },
                   /*
    // Shortcut key message
    {_SOURCE_KEY_MESSAGE,       _OE_CHANGE_SOURCE },
    {_MUTE_KEY_MESSAGE,         _OE_SC_MUTE       },
    {_VOL_DEC_KEY_MESSAGE,      _OE_SC_VOLUME     },
    {_VOL_INC_KEY_MESSAGE,      _OE_SC_VOLUME     },
    {_CH_DEC_KEY_MESSAGE,       _OE_SC_CH_DEC     },
    {_CH_INC_KEY_MESSAGE,       _OE_SC_CH_INC     },
    {_NUM_0_KEY_MESSAGE,        _OE_SC_INPUT_NUM0 },
    {_NUM_1_KEY_MESSAGE,        _OE_SC_INPUT_NUM1 },
    {_NUM_2_KEY_MESSAGE,        _OE_SC_INPUT_NUM2 },
    {_NUM_3_KEY_MESSAGE,        _OE_SC_INPUT_NUM3 },
    {_NUM_4_KEY_MESSAGE,        _OE_SC_INPUT_NUM4 },
    {_NUM_5_KEY_MESSAGE,        _OE_SC_INPUT_NUM5 },
    {_NUM_6_KEY_MESSAGE,        _OE_SC_INPUT_NUM6 },
    {_NUM_7_KEY_MESSAGE,        _OE_SC_INPUT_NUM7 },
    {_NUM_8_KEY_MESSAGE,        _OE_SC_INPUT_NUM8 },
    {_NUM_9_KEY_MESSAGE,        _OE_SC_INPUT_NUM9 },
    {_INPUT_CH_KEY_MESSAGE,     _OE_SC_INPUT_CH   },
    {_RETURN_KEY_MESSAGE,       _OE_SC_RETURN     },
                  */
    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};
//------------------------------------------------------------
// Key map
SKeyToOsdEvent code tKOSubMenu[] =
{
    {_MENU_KEY_MESSAGE,         _OE_ENTER_SUBMENU},
    {_UP_KEY_MESSAGE,           _OE_MENU_PREV},
    {_DOWN_KEY_MESSAGE,         _OE_MENU_NEXT},
    {_LEFT_KEY_MESSAGE,         _OE_ADJ_DEC},
    {_RIGHT_KEY_MESSAGE,        _OE_ADJ_INC},

    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};
//------------------------------------------------------------
// Key map
SKeyToOsdEvent code tKOSubMenu1[] =
{
    {_MENU_KEY_MESSAGE,         _OE_ENTER_SUBMENU},
    {_UP_KEY_MESSAGE,           _OE_MENU_PREV},
    {_DOWN_KEY_MESSAGE,         _OE_MENU_NEXT},
    {_LEFT_KEY_MESSAGE,         _OE_ADJ_DEC},
    {_RIGHT_KEY_MESSAGE,        _OE_ADJ_INC},

    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};
//------------------------------------------------------------
SKeyToOsdEvent code tKOSource[] =
{
    {_SOURCE_KEY_MESSAGE,       _OE_RETURN_UPMENU},
    {_MENU_KEY_MESSAGE,         _OE_RETURN_UPMENU},
    {_UP_KEY_MESSAGE,           _OE_MENU_PREV},
    {_DOWN_KEY_MESSAGE,         _OE_MENU_NEXT},
    {_RIGHT_KEY_MESSAGE,        _OE_ADJ_INC},

    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};
//------------------------------------------------------------
SKeyToOsdEvent code tKOShortCut[] =
{
    {_MENU_KEY_MESSAGE,         _OE_RETURN_UPMENU},
    {_LEFT_KEY_MESSAGE,         _OE_ADJ_DEC},
    {_RIGHT_KEY_MESSAGE,        _OE_ADJ_INC},

    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};
//------------------------------------------------------------
SKeyToOsdEvent code tKOShortCutVolume[] =
{
    {_MENU_KEY_MESSAGE,         _OE_RETURN_UPMENU},
    {_VOL_DEC_KEY_MESSAGE,      _OE_ADJ_DEC},
    {_LEFT_KEY_MESSAGE,         _OE_ADJ_DEC},
    {_VOL_INC_KEY_MESSAGE,      _OE_ADJ_INC},
    {_RIGHT_KEY_MESSAGE,        _OE_ADJ_INC},

    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
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
    {_MENU_KEY_MESSAGE,         _OE_RETURN_UPMENU            },
    {_DISPLAY_KEY_MESSAGE,      _OE_DISPLAY                  },
    
    
    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG                    },

};
//------------------------------------------------------------

SKeyToOsdEvent code tKOFactory[] =
{
    {_LEFT_KEY_MESSAGE,           _OE_MENU_PREV       },
    {_RIGHT_KEY_MESSAGE,          _OE_MENU_NEXT       },
    {_MENU_KEY_MESSAGE,           _OE_ENTER_SUBMENU   },

    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG             },
};

//------------------------------------------------------------
SKeyToOsdEvent code tKOFactorySub[] =
{
    {_MENU_KEY_MESSAGE,          _OE_MENU_NEXT      },
    {_LEFT_KEY_MESSAGE,          _OE_ADJ_INC        },
	{_RIGHT_KEY_MESSAGE,         _OE_ADJ_DEC        },
	
    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG           },
};


#else               //#ifdef __PCB2660_003_KEY__

// Key map
extern SKeyToOsdEvent code tKONoSignal[];
extern SKeyToOsdEvent code tKOPublic[];
extern SKeyToOsdEvent code tKOMenuNone[];
extern SKeyToOsdEvent code tKOMainMenu[];
extern SKeyToOsdEvent code tKOSubMenu[];
extern SKeyToOsdEvent code tKOSubMenu1[];
extern SKeyToOsdEvent code tKOSource[];
extern SKeyToOsdEvent code tKOFactory[];
extern SKeyToOsdEvent code tKOFactorySub[];
extern SKeyToOsdEvent code tKOShortCut[];
extern SKeyToOsdEvent code tKOShortCutVolume[];
extern SKeyToOsdEvent code tKOShortInputCHMenu[];


#endif              //#ifdef __PCB2660_003_KEY__

void CKeyMessageProc(void);

#endif              //#if(_KEY_TYPE == _KT_PCB2660_003)
