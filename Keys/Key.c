//----------------------------------------------------------------------------------------------------
// ID Code      : Key.c No.0001
// Update Note  : 
//
//----------------------------------------------------------------------------------------------------

#define __KEY__

#include "Core\Header\include.h"
               
//--------------------------------------------------
// Description  : Key scan process     
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CKeyHandler(void)
{
    // Clear the key message
    ucKeyMessage = _NONE_KEY_MESSAGE;
    
    if(CKeyScanReady())// || _ACTIVE_STATE != ucCurrState)
    {
        // Store previous key state
        ucKeyStatePrev = ucKeyStateCurr;
        
        // Get current key state
        ucKeyStateCurr = CKeyScan();
           
        // Power key process, return if power key is pressed
        if(CKeyPowerKeyProc())
            return;
        
        // Convert key state to key message, store in (ucKeyNotify)
        CKeyMessageProc();

    	#if(_REMOTE_CONTROLLER != _IR_NONE) 
        {
            if(ucKeyMessage == _NONE_KEY_MESSAGE)
            {        
               ucKeyMessage = CIRKeyScan();
                                         
               if (ucKeyMessage != _NONE_KEY_MESSAGE)
                  ucPrevKey = ucKeyMessage;                   
            }
        }
    	#endif
    }
    
	#if(_DEBUG_TOOL == _ISP_FOR_RTD3580D_EMCU)
    GetVirtualKey();
    
    if(ucKeyMessage == _POWER_KEY_MESSAGE)
        SET_POWERSWITCH();
	#endif

    // debug info
    //if(ucKeyMessage != _NONE_KEY_MESSAGE)
	//	CUartPrintf("KeyMessage:",ucKeyMessage);
}

//--------------------------------------------------
// Description  : Check power key process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
/*
void CKeyCheckPowerKey(void)
{
    // Store previous key state
    ucKeyStatePrev = ucKeyStateCurr;
    
    // Get current key state
    ucKeyStateCurr = CKeyScan();
    
    // Power key process
    CKeyPowerKeyProc();
}
*/
//--------------------------------------------------
// Description  : Initial key status
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CKeyInitial(void)
{
	CLR_KEYSCANREADY();
    CLR_KEYSCANSTART();
}

//--------------------------------------------------
// Description  : Key scan ready process. We wait 0.02 sec in order to keep the keypad debounce
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit CKeyScanReady(void)
{
    if(GET_KEYSCANSTART() && GET_KEYSCANREADY())
    {
		CLR_KEYSCANSTART();  //
		CLR_KEYSCANREADY();  //
        return _TRUE;
    }
    else if(!GET_KEYSCANSTART())
    {
        // Wait 0.02 sec in order to keep the keypad debounce
        SET_KEYSCANSTART();
        //CTimerReactiveTimerEvent(SEC(0.02), CKeyScanReadyTimerEvent);
        CTimerReactiveTimerEvent(SEC(0.09), CKeyScanReadyTimerEvent);
        
        return _FALSE;
    }
    else
    {
        return _FALSE;
    }  
}

//--------------------------------------------------
// Description  : Key scan ready timer event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CKeyScanReadyTimerEvent(void)
{
    SET_KEYSCANREADY();
}

//--------------------------------------------------
// Description  : Key repeat enable timer event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CKeyRepeatEnableTimerEvent(void)
{
    SET_KEYREPEATSTART();
}

//--------------------------------------------------
// Description  : Key message translation
// Input Value  : ucKeyMask     --> Key mask
//                ucKeyMsg      --> Key message
// Output Value : None
//--------------------------------------------------
void CKeyMessageConvert(BYTE ucKeyMask, BYTE ucKeyMsg)
{
    if((ucKeyStatePrev ^ ucKeyStateCurr) == ucKeyMask)
    {
        ucKeyMessage = ucKeyMsg;
    }
    else
    { 
        if(GET_KEYREPEATENABLE())
        {
            if(GET_KEYREPEATSTART())
            {
                ucKeyMessage = ucKeyMsg;
                //CLR_KEYREPEATSTART();
            }
            else
            {
                CTimerActiveTimerEvent(SEC(_KEY_REPEAT_START_TIME),CKeyRepeatEnableTimerEvent);
            }
        }
    }
}

//--------------------------------------------------
// Description  : Power key process
// Input Value  : None
// Output Value : Return _TRUE if power key is pressed
//--------------------------------------------------
bit CKeyPowerKeyProc(void)
{
    if(ucKeyStateCurr == _POWER_KEY_MASK)
    {
        if((ucKeyStatePrev ^ ucKeyStateCurr) == _POWER_KEY_MASK)
        {
            CTimerDelayXms(25);
            ucKeyStateCurr = CKeyScan();
            
            if((ucKeyStatePrev ^ ucKeyStateCurr) == _POWER_KEY_MASK)
            {
                CKeyPowerKeyMix();
                SET_POWERSWITCH();
                return _TRUE;
            }
        }
    }
    
    return _FALSE;
}
//--------------------------------------------------
// Description  : We can add some settings here while combo key with power key
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CKeyPowerKeyMix(void)
{
/*
    switch(ucKeyStateCurr)
    {

	default:
	    break;
    }
*/
}

//--------------------------------------------------
#if(_FUNC_EN_CHK_KEY_DOWN)
BYTE CheckKeyDown(BYTE KeyMask,BYTE Cnt)
{
    BYTE i = 0;
    while(i < Cnt)
    {
        if(CKeyScan() == KeyMask)
    	{
    	    return 1;
    	}
    	CTimerDelayXms(20);
    	i++;
    }
    return 0;
}
#endif

//--------------------------------------------------
#if(_FUNC_EN_CHK_KEY_UP)
BYTE CheckKeyUp(BYTE KeyMask,BYTE Cnt)
{
    BYTE i = 0;
    while(i < Cnt)
    {
        if(CKeyScan() != KeyMask)
    	{
    	    return 1;
    	}
    	CTimerDelayXms(20);
    	i++;
    }
    return 0;
}
#endif

#if(_KEY_SCAN_TYPE == _KEY_SCAN_AD)
//--------------------------------------------------
// Description  : Get key status
// Input Value  : None
// Output Value : Return Key status
//--------------------------------------------------
void CGetADCValue(BYTE *pBuf)
{
	BYTE xdata *p;
    BYTE i = 0;

	MCU_ADC_ACONTROL_FF08 = 0x82;			//start adc convert(STRT_ADC_ACKT=1) 

	while(MCU_ADC_ACONTROL_FF08 & 0x80)
	{
		_nop_();
	}

#if(AD_KEY0 != MCU_ADC_NONE)
	p = (0xFF09 + AD_KEY0);			
	pBuf[i] = *p;
    i++;
#endif

#if(AD_KEY1 != MCU_ADC_NONE)
	p = (0xFF09 + AD_KEY1);			
	pBuf[i] = *p;
    i++;
#endif

#if(AD_KEY2 != MCU_ADC_NONE)
	p = (0xFF09 + AD_KEY2);			
	pBuf[i] = *p;
    i++;
#endif

#if(AD_KEY3 != MCU_ADC_NONE)
	p = (0xFF09 + AD_KEY3);			
	pBuf[i] = *p;
    i++;
#endif

#if(AD_KEY4 != MCU_ADC_NONE)
	p = (0xFF09 + AD_KEY4);			
	pBuf[i] = *p;
#endif

	pBuf[0] >>= 2;
	pBuf[1] >>= 2;
	pBuf[2] >>= 2;
	pBuf[3] >>= 2;
	pBuf[4] >>= 2;
}
#endif
