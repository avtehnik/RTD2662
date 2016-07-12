#include "Core\Header\include.h"

#if(_KEY_TYPE == _KT_PCB2660_003)

//--------------------------------------------------
// Description  : Get key status
// Input Value  : None
// Output Value : Return Key status
//--------------------------------------------------
BYTE CKeyScan(void)
{
    BYTE ucKeyState = _NONE_KEY_MASK;

#if(_KEY_SCAN_TYPE == _KEY_SCAN_NORMAL)

    if(!bKey_P54)   ucKeyState    = ucKeyState | _POWER_KEY_MASK;   //Power
    if(!bKey_P56)   ucKeyState    = ucKeyState | _DOWN_KEY_MASK;    //Down
    if(!bKey_P55)   ucKeyState    = ucKeyState | _UP_KEY_MASK;      //Up
    if(!bKey_P57)   ucKeyState    = ucKeyState | _LEFT_KEY_MASK;    //Left
    if(!bKey_P76)   ucKeyState    = ucKeyState | _RIGHT_KEY_MASK;   //Right
    if(!bKey_P34)   ucKeyState    = ucKeyState | _SOURCE_KEY_MASK;  //Source
    if(!bKey_P81)   ucKeyState    = ucKeyState | _MENU_KEY_MASK;    //Menu

#else

    CGetADCValue(&pData[0]);
    CGetADCValue(&pData[3]);

/*  if(_ABS(pData[0], pData[3]) < 3)
    {
        // AD key0
        if     (_ABS(pData[0], bAD0_Key_0) < 3)  ucKeyState = _POWER_KEY_MASK;
        else if(_ABS(pData[0], bAD0_Key_1) < 3)  ucKeyState = _POWER_KEY_MASK;
        else if(_ABS(pData[0], bAD0_Key_2) < 3)  ucKeyState = _POWER_KEY_MASK;
    }
*/  

	ucKeyADValue = pData[0];

    // AD key1
    if(_ABS(pData[0], pData[3]) < 3)
    {
        if     (_ABS(pData[0], bAD1_Key_7) < 3)  ucKeyState = _POWER_KEY_MASK;
        else if(_ABS(pData[0], bAD1_Key_4) < 3)  ucKeyState = _RIGHT_KEY_MASK;
        else if(_ABS(pData[0], bAD1_Key_2) < 3)  ucKeyState = _LEFT_KEY_MASK;
        else if(_ABS(pData[0], bAD1_Key_3) < 3)  ucKeyState = _MENU_KEY_MASK;
		else if(_ABS(pData[0], bAD1_Key_1) < 3)  ucKeyState = _RESET_KEY_MASK;
        else if(_ABS(pData[0], bAD1_Key_5) < 3)  ucKeyState = _UP_KEY_MASK;
		else if(_ABS(pData[0], bAD1_Key_6) < 3)  ucKeyState = _DOWN_KEY_MASK;
        else if(_ABS(pData[0], bAD1_Key_8) < 3)  ucKeyState = _SOURCE_KEY_MASK;
    }

#endif

    if(ucKeyState != _NONE_KEY_MASK)
       CKeyInitial();

    return ucKeyState;
}
//--------------------------------------------------
/*
void CScanAutoKey(void)
{
     if(GET_POWERSTATUS())
     {
         // check 3 sec do change source ???
         #if(_TMDS_SUPPORT)
         {
             if(CheckKeyUp(_AUTO_KEY_MASK,50))
                ucKeyMessage = _AUTO_KEY_MESSAGE;
             else ucKeyMessage = _SOURCE_KEY_MESSAGE;
         }
         #else
         {
             CKeyMessageConvert(_AUTO_KEY_MASK, _AUTO_KEY_MESSAGE);
         }
         #endif
     }
     else
     {
         if(CheckKeyDown(_AUTO_KEY_MASK | _POWER_KEY_MASK,20))
         {
             SET_POWERSWITCH();
             ucKeyMessage = _AUTO_POWER_KEY_MESSAGE;
         }
     }
}
*/
//--------------------------------------------------


void CKeyMessageProc(void)
{          
    switch(ucKeyStateCurr)
    {        
		#if(_FAC_OSD)  
        case _FAC_KEY_MASK:     //Factory key
            CKeyMessageConvert(_FAC_KEY_MASK, _FAC_KEY_MESSAGE);        
            break;
		#endif
        
        case _MENU_KEY_MASK:     //Menu
            CKeyMessageConvert(_MENU_KEY_MASK, _MENU_KEY_MESSAGE);        
            break;
        
        case _UP_KEY_MASK:	     //Up
            CKeyMessageConvert(_UP_KEY_MASK, _UP_KEY_MESSAGE);
            break;

        case _DOWN_KEY_MASK:	 //Dn
            CKeyMessageConvert(_DOWN_KEY_MASK, _DOWN_KEY_MESSAGE);
            break;
		 
        case _LEFT_KEY_MASK:     //Left
            CKeyMessageConvert(_LEFT_KEY_MASK, _LEFT_KEY_MESSAGE);
            break;

        case _RIGHT_KEY_MASK:    //Right
            CKeyMessageConvert(_RIGHT_KEY_MASK, _RIGHT_KEY_MESSAGE);
            break; 
               
        case _SOURCE_KEY_MASK:
            CKeyMessageConvert(_SOURCE_KEY_MASK, _SOURCE_KEY_MESSAGE);
            break;
	
		case _RESET_KEY_MASK:
			CKeyMessageConvert(_RESET_KEY_MASK, _RESET_KEY_MESSAGE);
			break;

        default:
            CLR_KEYREPEATSTART();
            CTimerCancelTimerEvent(CKeyRepeatEnableTimerEvent);
            break;
    }
} 
//--------------------------------------------------
              
#endif      //#if(_KEY_TYPE == _KT_PCB2660_003)
