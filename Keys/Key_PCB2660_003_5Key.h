#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)

#define _FUNC_EN_CHK_KEY_DOWN       0
#define _FUNC_EN_CHK_KEY_UP         0

#define _MENU_KEY_MASK              _BIT1
#define _LEFT_KEY_MASK              _BIT2
#define _RIGHT_KEY_MASK             _BIT3
#define _AV1_KEY_MASK               _BIT4
#define _AV2_KEY_MASK               _BIT5
#define _SOURCE_KEY_MASK            _BIT6

#ifdef __KEY__

// Key map
SKeyToOsdEvent code tKONoSignal[] =
{
    {_SOURCE_KEY_MESSAGE,		_OE_CHANGE_SOURCE},
    {_IR_SOURCE_KEY_MESSAGE,	_OE_CHANGE_SOURCE},

	// End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};
//------------------------------------------------------------
// Key map
SKeyToOsdEvent code tKOPublic[] =
{  
    // Shortcut key message
    {_SOURCE_KEY_MESSAGE,       _OE_CHANGE_SOURCE },
    {_IR_SOURCE_KEY_MESSAGE,	_OE_CHANGE_SOURCE },
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
    {_DISPLAY_KEY_MESSAGE,      _OE_DISPLAY       },

    
    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};
//------------------------------------------------------------
// Key map
SKeyToOsdEvent code tKOMenuNone[] =
{
    {_IR_SOURCE_KEY_MESSAGE,	_OE_CHANGE_SOURCE      },
	{_SOURCE_KEY_MESSAGE,		_OE_CHANGE_SOURCE      },
	{_MENU_KEY_MESSAGE,         _OE_ENTER_SUBMENU      },	
	{_RIGHT_KEY_MESSAGE,		_OE_SC_VOLUME          },
    {_LEFT_KEY_MESSAGE,         _OE_SC_VOLUME          },
    {_UP_KEY_MESSAGE,           _OE_SC_CH_INC          },    
    {_DOWN_KEY_MESSAGE,         _OE_SC_CH_DEC          },

    {_IR_MENU_KEY_MESSAGE,		_OE_ENTER_SUBMENU      },
    {_IR_UP_KEY_MESSAGE,        _OE_SC_CH_INC          },
    {_IR_DOWN_KEY_MESSAGE,      _OE_SC_CH_DEC          },
    {_IR_LEFT_KEY_MESSAGE,      _OE_SC_VOLUME          },
    {_IR_RIGHT_KEY_MESSAGE,     _OE_SC_VOLUME          },    
    
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

 	// End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG              },
};
//------------------------------------------------------------
// Key map
SKeyToOsdEvent code tKOMainMenu[] =
{
	{_SOURCE_KEY_MESSAGE,		_OE_RETURN_UPMENU},
    {_MENU_KEY_MESSAGE,         _OE_ENTER_SUBMENU},
    {_LEFT_KEY_MESSAGE,         _OE_MENU_PREV    },
    {_RIGHT_KEY_MESSAGE,        _OE_MENU_NEXT    },

    {_IR_MENU_KEY_MESSAGE,		_OE_RETURN_UPMENU},
    {_IR_UP_KEY_MESSAGE,        _OE_MENU_PREV    },
    {_IR_DOWN_KEY_MESSAGE,      _OE_MENU_NEXT    },
    {_IR_RIGHT_KEY_MESSAGE,     _OE_ENTER_SUBMENU}, 
   
    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG        },
};
//------------------------------------------------------------
// Key map
SKeyToOsdEvent code tKOSubMenu[] =
{
	{_SOURCE_KEY_MESSAGE,		_OE_RETURN_UPMENU},
    {_MENU_KEY_MESSAGE,         _OE_ENTER_SUBMENU},
    {_LEFT_KEY_MESSAGE,         _OE_MENU_PREV    },
    {_RIGHT_KEY_MESSAGE,        _OE_MENU_NEXT    },

    {_IR_MENU_KEY_MESSAGE,      _OE_RETURN_UPMENU},
    {_IR_UP_KEY_MESSAGE,        _OE_MENU_PREV    },
    {_IR_DOWN_KEY_MESSAGE,      _OE_MENU_NEXT    },
    {_IR_LEFT_KEY_MESSAGE,      _OE_ADJ_DEC      },
    {_IR_RIGHT_KEY_MESSAGE,     _OE_ADJ_INC      },

    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG        },
};
//------------------------------------------------------------
SKeyToOsdEvent code tKOSubMenu1[] =
{
	{_SOURCE_KEY_MESSAGE,		_OE_RETURN_UPMENU},
    {_MENU_KEY_MESSAGE,         _OE_ENTER_SUBMENU},
    {_LEFT_KEY_MESSAGE,         _OE_MENU_PREV    },
    {_RIGHT_KEY_MESSAGE,        _OE_MENU_NEXT    },

    {_IR_MENU_KEY_MESSAGE,      _OE_RETURN_UPMENU},
    {_IR_UP_KEY_MESSAGE,        _OE_MENU_PREV    },
    {_IR_DOWN_KEY_MESSAGE,      _OE_MENU_NEXT    },
    {_IR_LEFT_KEY_MESSAGE,      _OE_ADJ_DEC      },
    {_IR_RIGHT_KEY_MESSAGE,     _OE_ADJ_INC      },

    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG        },
};
//------------------------------------------------------------
SKeyToOsdEvent code tKOAdjust[] =
{
	{_SOURCE_KEY_MESSAGE,		_OE_RETURN_UPMENU},
    {_MENU_KEY_MESSAGE,         _OE_RETURN_UPMENU},
    {_LEFT_KEY_MESSAGE,         _OE_ADJ_DEC      },
    {_RIGHT_KEY_MESSAGE,        _OE_ADJ_INC      },

    {_IR_MENU_KEY_MESSAGE,      _OE_RETURN_UPMENU},
    {_IR_UP_KEY_MESSAGE,        _OE_MENU_PREV    },
    {_IR_DOWN_KEY_MESSAGE,      _OE_MENU_NEXT    },
    {_IR_LEFT_KEY_MESSAGE,      _OE_ADJ_DEC      },
    {_IR_RIGHT_KEY_MESSAGE,     _OE_ADJ_INC      },

    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG        },
};
//------------------------------------------------------------

SKeyToOsdEvent code tKOSource[] =
{      
    {_SOURCE_KEY_MESSAGE,       _OE_RETURN_UPMENU},
    {_LEFT_KEY_MESSAGE,         _OE_MENU_PREV    },
    {_RIGHT_KEY_MESSAGE,        _OE_MENU_NEXT    },
    {_MENU_KEY_MESSAGE,         _OE_ENTER_SUBMENU}, 

    {_IR_MENU_KEY_MESSAGE,      _OE_RETURN_UPMENU},
    {_IR_UP_KEY_MESSAGE,        _OE_MENU_PREV    },
    {_IR_DOWN_KEY_MESSAGE,      _OE_MENU_NEXT    },
    {_IR_RIGHT_KEY_MESSAGE,     _OE_ADJ_INC      },

    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG        },
};
//------------------------------------------------------------
SKeyToOsdEvent code tKOShortCut[] =
{
    {_MENU_KEY_MESSAGE,         _OE_RETURN_UPMENU},
    {_LEFT_KEY_MESSAGE,         _OE_ADJ_DEC      },
    {_RIGHT_KEY_MESSAGE,        _OE_ADJ_INC      },
 
    {_IR_MENU_KEY_MESSAGE,      _OE_RETURN_UPMENU},
    {_IR_UP_KEY_MESSAGE,        _OE_MENU_PREV    },
    {_IR_DOWN_KEY_MESSAGE,      _OE_MENU_NEXT    },
    {_IR_RIGHT_KEY_MESSAGE,     _OE_ADJ_INC      },

    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG        },
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
    
    
    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG                    },

};
//------------------------------------------------------------

#else               //#ifdef __PCB2660_003_KEY__

// Key map
extern SKeyToOsdEvent code tKONoSignal[];
extern SKeyToOsdEvent code tKOPublic[];
extern SKeyToOsdEvent code tKOMenuNone[];
extern SKeyToOsdEvent code tKOMainMenu[];
extern SKeyToOsdEvent code tKOSubMenu[];
extern SKeyToOsdEvent code tKOSubMenu1[];
extern SKeyToOsdEvent code tKOSource[];
extern SKeyToOsdEvent code tKOShortCut[];
extern SKeyToOsdEvent code tKOShortCutVolume[];
extern SKeyToOsdEvent code tKOShortInputCHMenu[];
extern SKeyToOsdEvent code tKOAdjust[];


#endif              //#ifdef __PCB2660_003_KEY__

BYTE CKeyScan(void);
void CKeyMessageProc(void);

#endif              //#if(_KEY_TYPE == _KT_PCB2660_003)
