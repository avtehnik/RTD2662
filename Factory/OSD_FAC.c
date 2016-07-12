#include "Core\Header\Include.h"

#if(_FAC_OSD)

#define FACTORYSUBMENU_LINECOLOR(row,color)		OSDLine(row, COL(15), LENGTH(38), color, BYTE_COLOR)
#define FACTORYSUBMENU_TEXTOUT(str,row)			TextOutCalcWidth(str,row,20,30,14 * 12)


//-----------------------------------------------------------
void EnterFacBurnin(void)
{
	if(GET_BURNIN_STATE()==_BURNIN_ON)
    {	
    	SET_BURNIN_STATE(0);
    	OSDClear(6, 1, 17, 5, 0x00,BYTE_DISPLAY);
    	TextOutCalcWidth(sFacOff,ROW(6),COL(17),5,5*12);
    }
    else
    {
    	SET_BURNIN_STATE(1);
    	OSDClear(6, 1, 17, 5, 0x00,BYTE_DISPLAY);
		TextOutCalcWidth(sFacOn,ROW(6),COL(17),5,5*12);
	}
}


void DrawFactoryMenu()
{
    BYTE y = 0;

    COsdFxDisableOsd();

    SetOsdMap(tFactoryMenuOsdMap);
    COsdFxCodeWrite(ucCloseAllWindow);

    OSDClear(ROW(0), HEIGHT(9), COL(0), WIDTH(35), 0x8C, BYTE_ATTRIB);
    OSDClear(ROW(0), HEIGHT(9), COL(0), WIDTH(35), 0x00, BYTE_DISPLAY);
	OSDClear(ROW(0), HEIGHT(9), COL(0), WIDTH(35), 0x20, BYTE_COLOR);
    SetOSDDouble(0x00);  

	ucOsdState = _MI_FAC_AUTOCOLOR;
	COsdFxDrawWindow(0,0,									//WORD usXStart,WORD usYStart,  
					450,150,	//WORD usXEnd,WORD usYEnd,  
					tMainWindowStyle);						//BYTE *pStyle)

	OSDPosition(450,150,3, 3,0x03);
   

	CTextOutBase(sFacAdjustColor,COL(1),ROW(1));
/*
	CTextOutEx(sFacGain,COL(1),ROW(2));
	CTextOutEx(sFacOffset,COL(1),ROW(3));
	CTextOutEx(sFac9300,COL(1),ROW(4));
	CTextOutEx(sFac6500,COL(1),ROW(5));
*/
	TextOutCalcWidth(sFacGain,ROW(2),COL(1),16,16 * 12);
	TextOutCalcWidth(sFacOffset,ROW(3),COL(1),16,16 * 12);
	TextOutCalcWidth(sFac9300,ROW(4),COL(1),16,16 * 12);
	TextOutCalcWidth(sFac6500,ROW(5),COL(1),16,16 * 12);
	TextOutCalcWidth(sBurnIn,ROW(6), COL(1),16,16 * 12);
	//CTextOutBase(sFacRGB,COL(17),ROW(2));
	//CTextOutBase(sFacRGB,COL(17),ROW(3));
	//CTextOutBase(sFacRGB,COL(17),ROW(4));
	//CTextOutBase(sFacRGB,COL(17),ROW(5));
	Gotoxy(COL(17),ROW(2), BYTE_DISPLAY);
	Textout(sFacRGB);
	Gotoxy(COL(17),ROW(3), BYTE_DISPLAY);
	Textout(sFacRGB);
	Gotoxy(COL(17),ROW(4), BYTE_DISPLAY);
	Textout(sFacRGB);
	Gotoxy(COL(17),ROW(5), BYTE_DISPLAY);
	Textout(sFacRGB);
	
	CTextOutBase(sFacExit,COL(1),ROW(7));
	
	
	for(;y<8;y++)
    {
		SETCOLOR_FACMAINMENU_NORLINE(y,_MENU_NORMAL_COLOR);
    }
		
	SETCOLOR_FACMAINMENU_SELLINE(1,_MENU_SECECT_COLOR);
	CFacShowNumber(18,2,stAdcData.AdcGain[_RED]);
	CFacShowNumber(25,2,stAdcData.AdcGain[_GREEN]);
	CFacShowNumber(31,2,stAdcData.AdcGain[_BLUE]);

	CFacShowNumber(18,3,stAdcData.AdcOffset[_RED]);
	CFacShowNumber(25,3,stAdcData.AdcOffset[_GREEN]);
	CFacShowNumber(31,3,stAdcData.AdcOffset[_BLUE]);

    SET_COLOR_TEMP_TYPE(_CT_9300);
	CEepromLoadColorTempData();
	CFacShowNumber(18,4,stColorTempData.ColorTemp[3 + _RED]);
	CFacShowNumber(25,4,stColorTempData.ColorTemp[3 + _GREEN]);
	CFacShowNumber(31,4,stColorTempData.ColorTemp[3 + _BLUE]);

	SET_COLOR_TEMP_TYPE(_CT_6500);
	CEepromLoadColorTempData();
	CFacShowNumber(18,5,stColorTempData.ColorTemp[3 + _RED]);
	CFacShowNumber(25,5,stColorTempData.ColorTemp[3 + _GREEN]);
	CFacShowNumber(31,5,stColorTempData.ColorTemp[3 + _BLUE]);

   	if(GET_BURNIN_STATE()==_BURNIN_ON)
    {	
    	TextOutCalcWidth(sFacOn,ROW(6),COL(17),5,5*12);
    }
    else
    {
		TextOutCalcWidth(sFacOff,ROW(6),COL(17),5,5*12);
	}
	
	COsdFxEnableOsd();
	bOSDTimeOut=0;
	
}
//---------------------------------------------------------------------------
void MFactoryMenuAdj(BYTE ucMode)
{    
    // ucMode : _NEXT or _Prev
    BYTE ucNewItem = AdjustMenuItem(_MI_FAC_AUTOCOLOR,_MI_FAC_EXIT,ucMode);

    if(ucNewItem == ucOsdState)
    {
    	return;
    }
    
    // 1. Clear Current Menu
    SETCOLOR_FACMAINMENU_SELLINE(ucOsdState+1-_MI_FAC_AUTOCOLOR,_MENU_NORMAL_COLOR);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 3. Draw New Item   
    SETCOLOR_FACMAINMENU_SELLINE(ucOsdState+1-_MI_FAC_AUTOCOLOR,_MENU_SECECT_COLOR);

   	// 4. Change RGB
   	switch(ucOsdState)
   	{
   		case _MI_FAC_9300:      
   		SET_COLOR_TEMP_TYPE(_CT_9300);
   		CEepromLoadColorTempData();
		CAdjustContrast();
		break;
		
   		case _MI_FAC_6500:		
   		SET_COLOR_TEMP_TYPE(_CT_6500);
   		CEepromLoadColorTempData();
		CAdjustContrast();
		break;
   	}
}

void ExitFacMenu(void)
{
	COsdDispOsdTimerEvent();
	bOSDTimeOut = 1;
}

void MFactoryEnterSub(void)
{
    // ucMode : _INC or _DEC
    switch(ucOsdState)
    {
        case _MI_FAC_AUTOCOLOR:    
            CAutoDoWhiteBalance();
            CFacShowNumber(18,2,stAdcData.AdcGain[_RED]);
    		CFacShowNumber(25,2,stAdcData.AdcGain[_GREEN]);
    		CFacShowNumber(31,2,stAdcData.AdcGain[_BLUE]);
    
    		CFacShowNumber(18,3,stAdcData.AdcOffset[_RED]);
    		CFacShowNumber(25,3,stAdcData.AdcOffset[_GREEN]);
    		CFacShowNumber(31,3,stAdcData.AdcOffset[_BLUE]);
            break;

        case _MI_FAC_9300:
        	SETCOLOR_FACMAINMENU_SELLINE(ucOsdState+1-_MI_FAC_AUTOCOLOR,_MENU_NORMAL_COLOR);
        	ucOsdState=_MI_FAC_9300_R;
        	OSDLine(ROW(4), COL(16), LENGTH(5), _MENU_SECECT_COLOR, BYTE_COLOR);			
            break;

        case _MI_FAC_6500:             
            SETCOLOR_FACMAINMENU_SELLINE(ucOsdState+1-_MI_FAC_AUTOCOLOR,_MENU_NORMAL_COLOR);
            ucOsdState=_MI_FAC_6500_R;
            OSDLine(ROW(5), COL(16), LENGTH(5), _MENU_SECECT_COLOR, BYTE_COLOR);         
            break;
        	
        case _MI_FAC_GAIN:           
            SETCOLOR_FACMAINMENU_SELLINE(ucOsdState+1-_MI_FAC_AUTOCOLOR,_MENU_NORMAL_COLOR);
            ucOsdState=_MI_FAC_GAIN_R;
            OSDLine(ROW(2), COL(16), LENGTH(5), _MENU_SECECT_COLOR, BYTE_COLOR);         
            break;
			
        case _MI_FAC_OFFSET: 
			SETCOLOR_FACMAINMENU_SELLINE(ucOsdState+1-_MI_FAC_AUTOCOLOR,_MENU_NORMAL_COLOR);
            ucOsdState=_MI_FAC_OFFSET_R;
            OSDLine(ROW(3), COL(16), LENGTH(5), _MENU_SECECT_COLOR, BYTE_COLOR);         
            break;
            
        case _MI_FAC_BURNIN:	
        	EnterFacBurnin();
			break;

        case _MI_FAC_EXIT: 		
            ExitFacMenu();                      
			break;
    }
}


//---------------------------------------------------------------------------

void MFactoryProc()
{
    switch(ucOsdEventMsg)
    {
//        case _OE_ADJ_INC:           MFactoryValueAdj(_INC);              break;
//        case _OE_ADJ_DEC:           MFactoryValueAdj(_DEC);              break;
        case _OE_MENU_NEXT:         MFactoryMenuAdj(_NEXT);              break;
        case _OE_MENU_PREV:         MFactoryMenuAdj(_PREV);              break;
        case _OE_ENTER_SUBMENU:     MFactoryEnterSub();                  break;
        case _OE_RETURN_UPMENU:     						             break;

    }
    
}

void MFac9300ReturnMenu()
{
    OSDLine(ROW(4),COL(16+(ucOsdState-_MI_FAC_9300_R)*6),LENGTH(6),_MENU_NORMAL_COLOR,BYTE_COLOR);
    ucOsdState=_MI_FAC_9300;
    SETCOLOR_FACMAINMENU_SELLINE(4, _MENU_SECECT_COLOR);
}

void MFac9300MenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev

    BYTE ucNewItem;
    if(ucMode==_INC)
    { 	
    	if(ucOsdState>_MI_FAC_9300_R-1 && ucOsdState<_MI_FAC_9300_B)
    		ucNewItem=ucOsdState+1;
    	else
    		ucNewItem=_MI_FAC_9300;
    }
    else
	{
	    if(ucOsdState>_MI_FAC_9300_R && ucOsdState<_MI_FAC_9300_B+1)
    		ucNewItem=ucOsdState-1;
    	else
    		ucNewItem=_MI_FAC_9300;
	}
    // 1. Clear Current Menu
	OSDLine(ROW(4),COL(16+(ucOsdState-_MI_FAC_9300_R)*6),LENGTH(6),_MENU_NORMAL_COLOR,BYTE_COLOR);


    // 2. Change ucOsdState
    ucOsdState = ucNewItem;

    // 3. Draw New Item
    if(ucOsdState>_MI_FAC_9300_R-1 && ucOsdState<_MI_FAC_9300_B+1)
    	OSDLine(ROW(4),COL(16+(ucOsdState-_MI_FAC_9300_R)*6),LENGTH(6),_MENU_SECECT_COLOR,BYTE_COLOR);
    else
    	SETCOLOR_FACMAINMENU_SELLINE(4,_MENU_SECECT_COLOR);

}


void MFac9300ValAdj(BYTE ucMode)
{
	BYTE y;
	SET_COLOR_TEMP_TYPE(_CT_9300);
	CEepromLoadColorTempData();
    // ucMode : _INC or _DEC
    SET_KEYREPEATENABLE();
    switch(ucOsdState)
    {
    	case _MI_FAC_9300_R :
    	    y= ValueInRangeChange(0, 255,stColorTempData.ColorTemp[3 + _RED], _NON_LOOP | ucMode);
    		stColorTempData.ColorTemp[3 + _RED]=y;
    		ucOsdEventMsg = _SAVE_EE_COLORPROC1_MSG;
    		CAdjustContrast();
			CFacShowNumber(18,4,y); 
			break;
			
		case _MI_FAC_9300_G :
    	    y= ValueInRangeChange(0, 255,stColorTempData.ColorTemp[3 + _GREEN], _NON_LOOP | ucMode);
    		stColorTempData.ColorTemp[3 + _GREEN]=y;
    		ucOsdEventMsg = _SAVE_EE_COLORPROC1_MSG;
    		CAdjustContrast();
			CFacShowNumber(25,4,y); 
			break;
			
    	case _MI_FAC_9300_B:
    	    y= ValueInRangeChange(0, 255,stColorTempData.ColorTemp[3 + _BLUE], _NON_LOOP | ucMode);
    		stColorTempData.ColorTemp[3 + _BLUE]=y;
    		ucOsdEventMsg = _SAVE_EE_COLORPROC1_MSG;
    		CAdjustContrast();
			CFacShowNumber(31,4,y); 
			break;
			
    }
}


void MFac9300Proc(void)
{
    switch(ucOsdEventMsg)
    {
        case _OE_ADJ_INC:           MFac9300ValAdj(_INC);                        break;
        case _OE_ADJ_DEC:           MFac9300ValAdj(_DEC);                        break;
        case _OE_MENU_NEXT:         MFac9300MenuAdj(_NEXT);                      break;
        case _OE_MENU_PREV:         MFac9300MenuAdj(_PREV);             		 break;
       // case _OE_ENTER_SUBMENU:     MFactoryEnterSub();  		      			 break;
        case _OE_RETURN_UPMENU:     MFac9300ReturnMenu();          break;

    }
}

void MFacGainReturnMenu()
{
    OSDLine(ROW(2),COL(16+(ucOsdState-_MI_FAC_GAIN_R)*6),LENGTH(6),_MENU_NORMAL_COLOR,BYTE_COLOR);
    ucOsdState=_MI_FAC_GAIN;
    SETCOLOR_FACMAINMENU_SELLINE(2, _MENU_SECECT_COLOR);
}

void MFacGainMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev

    BYTE ucNewItem;
    if(ucMode==_INC)
    { 	
    	if(ucOsdState>_MI_FAC_GAIN_R-1 && ucOsdState<_MI_FAC_GAIN_B)
    		ucNewItem=ucOsdState+1;
    	else
    		ucNewItem=_MI_FAC_GAIN;
    }
    else
	{
	    if(ucOsdState>_MI_FAC_GAIN_R && ucOsdState<_MI_FAC_GAIN_B+1)
    		ucNewItem=ucOsdState-1;
    	else
    		ucNewItem=_MI_FAC_GAIN;
	}
    // 1. Clear Current Menu
	OSDLine(ROW(2),COL(16+(ucOsdState-_MI_FAC_GAIN_R)*6),LENGTH(6),_MENU_NORMAL_COLOR,BYTE_COLOR);


    // 2. Change ucOsdState
    ucOsdState = ucNewItem;

    // 3. Draw New Item
    if(ucOsdState>_MI_FAC_GAIN_R-1 && ucOsdState<_MI_FAC_GAIN_B+1)
    	OSDLine(ROW(2),COL(16+(ucOsdState-_MI_FAC_GAIN_R)*6),LENGTH(6),_MENU_SECECT_COLOR,BYTE_COLOR);
    else
    	SETCOLOR_FACMAINMENU_SELLINE(2,_MENU_SECECT_COLOR);

}

void MFacGainValAdj(BYTE ucMode)
{
	BYTE y;

    // ucMode : _INC or _DEC
    SET_KEYREPEATENABLE();
    switch(ucOsdState)
    {
    	case _MI_FAC_GAIN_R :
    	    y= ValueInRangeChange(0, 255,stAdcData.AdcGain[_RED], _NON_LOOP | ucMode);
    		stAdcData.AdcGain[_RED]=y;
    		ucOsdEventMsg = _SAVE_EE_ADCDATA_MSG;
    		CAdjustAdcGain();
			CFacShowNumber(18,2,y); 
			break;
			
		case _MI_FAC_GAIN_G :
    	    y= ValueInRangeChange(0, 255,stAdcData.AdcGain[_GREEN], _NON_LOOP | ucMode);
    		stAdcData.AdcGain[_GREEN]=y;
    		ucOsdEventMsg = _SAVE_EE_ADCDATA_MSG;
    		CAdjustAdcGain();
			CFacShowNumber(25,2,y); 
			break;
			
    	case _MI_FAC_GAIN_B:
    	    y= ValueInRangeChange(0, 255,stAdcData.AdcGain[_BLUE], _NON_LOOP | ucMode);
    		stAdcData.AdcGain[_BLUE]=y;
    		ucOsdEventMsg = _SAVE_EE_ADCDATA_MSG;
    		CAdjustAdcGain();
			CFacShowNumber(31,2,y); 
			break;
			
    }
}


void MFacGainProc(void)
{
    switch(ucOsdEventMsg)
    {
        case _OE_ADJ_INC:          	MFacGainValAdj(_INC);                   break;
        case _OE_ADJ_DEC:           MFacGainValAdj(_DEC);                   break;
        case _OE_MENU_NEXT:         MFacGainMenuAdj(_NEXT);          		break;
        case _OE_MENU_PREV:         MFacGainMenuAdj(_PREV);          		break;
       // case _OE_ENTER_SUBMENU:     MFactoryEnterSub();  		      		break;
        case _OE_RETURN_UPMENU:     MFacGainReturnMenu();          			break;

    }
}

void MFacOffsetReturnMenu()
{
    OSDLine(ROW(3),COL(16+(ucOsdState-_MI_FAC_OFFSET_R)*6),LENGTH(6),_MENU_NORMAL_COLOR,BYTE_COLOR);
    ucOsdState=_MI_FAC_OFFSET;
    SETCOLOR_FACMAINMENU_SELLINE(3, _MENU_SECECT_COLOR);
}

void MFacOffsetMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev

       BYTE ucNewItem;
    if(ucMode==_INC)
    { 	
    	if(ucOsdState>_MI_FAC_OFFSET_R-1 && ucOsdState<_MI_FAC_OFFSET_B)
    		ucNewItem=ucOsdState+1;
    	else
    		ucNewItem=_MI_FAC_OFFSET;
    }
    else
	{
	    if(ucOsdState>_MI_FAC_OFFSET_R && ucOsdState<_MI_FAC_OFFSET_B+1)
    		ucNewItem=ucOsdState-1;
    	else
    		ucNewItem=_MI_FAC_OFFSET;
	}
    // 1. Clear Current Menu
	OSDLine(ROW(3),COL(16+(ucOsdState-_MI_FAC_OFFSET_R)*6),LENGTH(6),_MENU_NORMAL_COLOR,BYTE_COLOR);


    // 2. Change ucOsdState
    ucOsdState = ucNewItem;

    // 3. Draw New Item
    if(ucOsdState>_MI_FAC_OFFSET_R-1 && ucOsdState<_MI_FAC_OFFSET_B+1)
    	OSDLine(ROW(3),COL(16+(ucOsdState-_MI_FAC_OFFSET_R)*6),LENGTH(6),_MENU_SECECT_COLOR,BYTE_COLOR);
    else
    	SETCOLOR_FACMAINMENU_SELLINE(3,_MENU_SECECT_COLOR);

}


void MFacOffsetValAdj(BYTE ucMode)
{
	BYTE y;

    // ucMode : _INC or _DEC
    SET_KEYREPEATENABLE();
    switch(ucOsdState)
    {
    	case _MI_FAC_OFFSET_R :
    	    y= ValueInRangeChange(0, 255,stAdcData.AdcOffset[_RED], _NON_LOOP | ucMode);
    		stAdcData.AdcOffset[_RED]=y;
    		ucOsdEventMsg = _SAVE_EE_ADCDATA_MSG;
    		CAdjustAdcOffset();
			CFacShowNumber(18,3,y); 
			break;
			
		case _MI_FAC_OFFSET_G :
    	    y= ValueInRangeChange(0, 255,stAdcData.AdcOffset[_GREEN], _NON_LOOP | ucMode);
    		stAdcData.AdcOffset[_GREEN]=y;
    		ucOsdEventMsg = _SAVE_EE_ADCDATA_MSG;
    		CAdjustAdcOffset();
			CFacShowNumber(25,3,y); 
			break;
			
    	case _MI_FAC_OFFSET_B:
    	    y= ValueInRangeChange(0, 255,stAdcData.AdcOffset[_BLUE], _NON_LOOP | ucMode);
    		stAdcData.AdcOffset[_BLUE]=y;
    		ucOsdEventMsg = _SAVE_EE_ADCDATA_MSG;
    		CAdjustAdcOffset();
			CFacShowNumber(31,3,y); 
			break;
			
    }
}

void MFacOffsetProc(void)
{
    switch(ucOsdEventMsg)
    {
        case _OE_ADJ_INC:           MFacOffsetValAdj(_INC);                    	break;
        case _OE_ADJ_DEC:           MFacOffsetValAdj(_DEC);                     break;
        case _OE_MENU_NEXT:         MFacOffsetMenuAdj(_NEXT);          			break;
        case _OE_MENU_PREV:         MFacOffsetMenuAdj(_PREV);          			break;
       // case _OE_ENTER_SUBMENU:     MFactoryEnterSub();  		       			break;
        case _OE_RETURN_UPMENU:     MFacOffsetReturnMenu();          			break;

    }
}

void MFac6500ReturnMenu()
{
    OSDLine(ROW(5),COL(16+(ucOsdState-_MI_FAC_6500_R)*6),LENGTH(6),_MENU_NORMAL_COLOR,BYTE_COLOR);
    ucOsdState=_MI_FAC_6500;
    SETCOLOR_FACMAINMENU_SELLINE(5, _MENU_SECECT_COLOR);
}

void MFac6500MenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev

       BYTE ucNewItem;
    if(ucMode==_INC)
    { 	
    	if(ucOsdState>_MI_FAC_6500_R-1 && ucOsdState<_MI_FAC_6500_B)
    		ucNewItem=ucOsdState+1;
    	else
    		ucNewItem=_MI_FAC_6500;
    }
    else
	{
	    if(ucOsdState>_MI_FAC_6500_R && ucOsdState<_MI_FAC_6500_B+1)
    		ucNewItem=ucOsdState-1;
    	else
    		ucNewItem=_MI_FAC_6500;
	}
    // 1. Clear Current Menu
	OSDLine(ROW(5),COL(16+(ucOsdState-_MI_FAC_6500_R)*6),LENGTH(6),_MENU_NORMAL_COLOR,BYTE_COLOR);


    // 2. Change ucOsdState
    ucOsdState = ucNewItem;

    // 3. Draw New Item
    if(ucOsdState>_MI_FAC_6500_R-1 && ucOsdState<_MI_FAC_6500_B+1)
    	OSDLine(ROW(5),COL(16+(ucOsdState-_MI_FAC_6500_R)*6),LENGTH(6),_MENU_SECECT_COLOR,BYTE_COLOR);
    else
    	SETCOLOR_FACMAINMENU_SELLINE(5,_MENU_SECECT_COLOR);

}

void MFac6500ValAdj(BYTE ucMode)
{
	BYTE y;
	SET_COLOR_TEMP_TYPE(_CT_6500);
	CEepromLoadColorTempData();
    // ucMode : _INC or _DEC
    SET_KEYREPEATENABLE();
    switch(ucOsdState)
    {
    	case _MI_FAC_6500_R :
    	    y= ValueInRangeChange(0, 255,stColorTempData.ColorTemp[3 + _RED], _NON_LOOP | ucMode);
    		stColorTempData.ColorTemp[3 + _RED]=y;
    		ucOsdEventMsg = _SAVE_EE_COLORPROC1_MSG;
			CFacShowNumber(18,5,y);
			CAdjustContrast();
			break;
			
		case _MI_FAC_6500_G :
    	    y= ValueInRangeChange(0, 255,stColorTempData.ColorTemp[3 + _GREEN], _NON_LOOP | ucMode);    		
    		stColorTempData.ColorTemp[3 + _GREEN]=y;
    		ucOsdEventMsg = _SAVE_EE_COLORPROC1_MSG;
    		CAdjustContrast();
			CFacShowNumber(25,5,y); 
			break;
			
    	case _MI_FAC_6500_B:
    	    y= ValueInRangeChange(0, 255,stColorTempData.ColorTemp[3 + _BLUE], _NON_LOOP | ucMode);
    		stColorTempData.ColorTemp[3 + _BLUE]=y;
    		ucOsdEventMsg = _SAVE_EE_COLORPROC1_MSG;
    		CAdjustContrast();
			CFacShowNumber(31,5,y); 
			break;
			
    }
}


void MFac6500Proc(void)
{
    switch(ucOsdEventMsg)
    {
        case _OE_ADJ_INC:           MFac6500ValAdj(_INC);                        break;
        case _OE_ADJ_DEC:           MFac6500ValAdj(_DEC);                        break;
        case _OE_MENU_NEXT:         MFac6500MenuAdj(_NEXT);                      break;
        case _OE_MENU_PREV:         MFac6500MenuAdj(_PREV);             		 break;
       // case _OE_ENTER_SUBMENU:     MFactoryEnterSub();  		      			 break;
        case _OE_RETURN_UPMENU:     MFac6500ReturnMenu();          break;

    }
}

#endif



