#if(_KEY_TYPE == _KT_PCB2660_007)

#define _FUNC_EN_CHK_KEY_DOWN       0
#define _FUNC_EN_CHK_KEY_UP         0

#define _MENU_KEY_MASK              _BIT1
#define _LEFT_KEY_MASK              _BIT2
#define _RIGHT_KEY_MASK             _BIT3
#define _UP_KEY_MASK                _BIT4
#define _DOWN_KEY_MASK              _BIT5
#define _SOURCE_KEY_MASK            _BIT6


#ifdef __KEY__


#else               //#ifdef __PCB2660_003_KEY__


#endif              //#ifdef __PCB2660_003_KEY__

BYTE CKeyScan(void);
void CKeyMessageProc(void);

#endif              //#if(_KEY_TYPE == _KT_PCB2660_003)
