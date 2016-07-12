//----------------------------------------------------------------------------------------------------
// ID Code      : Key.h No.0000
// Update Note  : 
//
//----------------------------------------------------------------------------------------------------
#define _ABS(VALUE1,VALUE2)      (VALUE1 > VALUE2 ? (VALUE1) - (VALUE2) : (VALUE2) - (VALUE1))

//--------------------------------------------------
// Macro of Key Scan Ready Flag
//--------------------------------------------------
#define GET_KEYSCANREADY()          ((bit)(ucKeyControl & _BIT0))
#define SET_KEYSCANREADY()          (ucKeyControl |= _BIT0)
#define CLR_KEYSCANREADY()          (ucKeyControl &= ~_BIT0)


//--------------------------------------------------
// Macro of Key Scan Start Flag
//--------------------------------------------------
#define GET_KEYSCANSTART()          ((bit)(ucKeyControl & _BIT1))
#define SET_KEYSCANSTART()          (ucKeyControl |= _BIT1)
#define CLR_KEYSCANSTART()          (ucKeyControl &= ~_BIT1)


//--------------------------------------------------
// Macro of Key Repeat Start
//--------------------------------------------------
#define GET_KEYREPEATSTART()        (bit)(ucKeyControl & _BIT2)
#define SET_KEYREPEATSTART()        ucKeyControl |= _BIT2
#define CLR_KEYREPEATSTART()        ucKeyControl &= ~_BIT2


//--------------------------------------------------
// Macro of Key Repeat Function Enable
// If you want to use repeat function, please set this flag. If not, please clear it.
//--------------------------------------------------
#define GET_KEYREPEATENABLE()       (bit)(ucKeyControl & _BIT3)
#define SET_KEYREPEATENABLE()       ucKeyControl |= _BIT3
#define CLR_KEYREPEATENABLE()       ucKeyControl &= ~_BIT3


//----------------------------------------------------------------------------------------------------

//--------------------------------------------------
// Definitions of Key Repeat Start Time (Unit in sec)
//--------------------------------------------------
#define _KEY_REPEAT_START_TIME      0.5

//--------------------------------------------------
// Definitions of Key Mask
//--------------------------------------------------
#define _NONE_KEY_MASK              0x00

#define _POWER_KEY_MASK             _BIT0

//--------------------------------------------------
// Definitions of Key Message
//--------------------------------------------------
enum
{
    _NONE_KEY_MESSAGE = 0,   				//0x00
    _POWER_KEY_MESSAGE,       				//0x01
    
    _MENU_KEY_MESSAGE, 						//0x02
    _AUTO_KEY_MESSAGE, 						//0x03
    _SOURCE_KEY_MESSAGE,					//0x04
    _ENTER_KEY_MESSAGE,  					//0x05
    _EXIT_KEY_MESSAGE,   					//0x06
    _RESET_KEY_MESSAGE,   					//0x07
    _SLEEP_KEY_MESSAGE,//Modified for sleep key,AndyLiu 20080313   //0x08

    _RIGHT_KEY_MESSAGE,  					//0x09
    _LEFT_KEY_MESSAGE,   					//0x0a
    _UP_KEY_MESSAGE,     					//0x0b
    _DOWN_KEY_MESSAGE,						//0x0c

	/*#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
	//_IR_LEFT_KEY_MESSAGE,
    _IR_SOURCE_KEY_MESSAGE,
	_IR_MENU_KEY_MESSAGE,
    _IR_RIGHT_KEY_MESSAGE,
    _IR_LEFT_KEY_MESSAGE,
    _IR_UP_KEY_MESSAGE,
    _IR_DOWN_KEY_MESSAGE,
	#endif*/
    _IR_MODE_KEY_MESSAGE,     				//0x0d
    _IR_SOURCE_KEY_MESSAGE,   				//0x0e
	_IR_MENU_KEY_MESSAGE,					//0x0f
    _IR_RIGHT_KEY_MESSAGE,					//0x10
    _IR_LEFT_KEY_MESSAGE,					//0x11
    _IR_UP_KEY_MESSAGE,       				//0x12
    _IR_DOWN_KEY_MESSAGE,     				//0x13
    _IR_SCREEN_KEY_MESSAGE,    				//0x14
    _IR_DISPRATIO_KEY_MESSAGE,//Modified for DISPRAIO key,AndyLiu 20080328   //0x15
    _IR_SCREEN_UD_KEY_MESSAGE,// jokerxie 08-05-05 for SCREEN UP DOWN			//0x16
    _IR_SCREEN_LR_KEY_MESSAGE,// jokerxie 08-05-05 for SCREEN LEFT RIGHT		//0x17

    _MUTE_KEY_MESSAGE,  					//0x18
    _VOL_DEC_KEY_MESSAGE, 					//0x19
    _VOL_INC_KEY_MESSAGE,      				//0x1a
    _CH_DEC_KEY_MESSAGE,	 				//0x1c
    _CH_INC_KEY_MESSAGE,					//0x1d
    _DISPLAY_KEY_MESSAGE=0x50,   			//0x1c
    _ESC_KEY_MESSAGE,
    _NUM_0_KEY_MESSAGE,
    _NUM_1_KEY_MESSAGE,
    _NUM_2_KEY_MESSAGE,
    _NUM_3_KEY_MESSAGE,
    _NUM_4_KEY_MESSAGE,
    _NUM_5_KEY_MESSAGE,
    _NUM_6_KEY_MESSAGE,
    _NUM_7_KEY_MESSAGE,
    _NUM_8_KEY_MESSAGE,
    _NUM_9_KEY_MESSAGE,
    _INPUT_CH_KEY_MESSAGE,

  	#if(_OSD_TYPE == _OSD007)
    _IR_MENU_KEY_MESSAGE,
    _IR_LEFT_KEY_MESSAGE,
    _IR_RIGHT_KEY_MESSAGE,
    _IR_UP_KEY_MESSAGE,
    _IR_DOWN_KEY_MESSAGE,
  	#endif

    _AV1_KEY_MESSAGE,
    _AV2_KEY_MESSAGE,
    _FAC_KEY_MESSAGE,

    _IR_FUNC_BRI_DEC,
    _IR_FUNC_BRI_INC,
    _IR_FUNC_CON_DEC,
    _IR_FUNC_CON_INC,
    _IR_FUNC_COLOR_DEC,
    _IR_FUNC_COLOR_INC,
    _IR_FUNC_VOL_DEC,
    _IR_FUNC_VOL_INC,

    _RETURN_KEY_MESSAGE  
};


#ifdef __KEY__

//--------------------------------------------------
// Global Variables
//--------------------------------------------------
BYTE idata ucKeyControl;
BYTE idata ucKeyMessage;
BYTE idata ucKeyStatePrev;
BYTE idata ucKeyStateCurr;
  
#else

//--------------------------------------------------
// Extern Global Variables
//--------------------------------------------------
extern BYTE idata ucKeyControl;
extern BYTE idata ucKeyMessage;
extern BYTE idata ucKeyStatePrev;
extern BYTE idata ucKeyStateCurr;


#endif


//--------------------------------------------------
// Function Prototypes
//--------------------------------------------------
void CKeyHandler(void);
void CKeyCheckPowerKey(void);
void CKeyInitial(void);
bit CKeyScanReady(void);
void CKeyScanReadyTimerEvent(void);
void CKeyRepeatEnableTimerEvent(void);
void CKeyMessageConvert(BYTE ucKeyMask, BYTE ucKeyMsg);
BYTE CKeyScan(void);
void CKeyPowerKeyMix(void);
bit CKeyPowerKeyProc(void);
void CKeyMessageProc(void);

bit CKeyCheckExitKey(void);
void CKeyCheckEnterFactoryMenu(void);
bit CCheckAutoPowerKey(void);
bit CCheckAutoPowerKey(void);
//void CIrProc(void);
BYTE CheckKeyDown(BYTE KeyMask,BYTE Cnt);
BYTE CheckKeyUp(BYTE KeyMask,BYTE Cnt);
#if(_KEY_SCAN_TYPE == _KEY_SCAN_AD)
void CGetADCValue(BYTE *pBuf);
extern BYTE idata ucKeyADValue;
#endif
//----------------------------------------------------------------------------------------------------


