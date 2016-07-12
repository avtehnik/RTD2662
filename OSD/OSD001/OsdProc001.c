

#define __OSDPROC001__

#include "Core\Header\Include.h"

#if(_OSD_TYPE == _OSD001)

//--------------------------------------------------
void COsdHandler(void)
{
    bit fPublicFunc = 1;
    bit fTest = 0;

    COsdSystemFlowProc();
    
    COsdEventMsgProc();

    if (_PWOFF_STATE == ucCurrState)
        return;

    // Key Message -> Osd Message
    if(ucCurrState == _ACTIVE_STATE)
        CCoverKeyMsgToOsdEvent(CURRENT_MENU_ITEM.KeyMsgToOsdEvnet,CURRENT_MENU_ITEM.Option & _EN_PUB_KEYEVENT);
    else CCoverKeyMsgToOsdEvent(tKONoSignal, _EN_PUB_KEYEVENT);

    // debug info
    //if(ucKeyMessage != _NONE_KEY_MESSAGE)
	//	CUartPrintf("Osd Event:",ucOsdEventMsg);
		

    // 执行当前菜单的私有处理函数
    if(CURRENT_MENU_ITEM.Proc != NULL)
    {
        fPublicFunc = CURRENT_MENU_ITEM.Proc();
    }

    // 执行公有的处理函数
    if(fPublicFunc && (CURRENT_MENU_ITEM.Option & _EN_PUB_PROCFUNC))
    {
         CMenuProc();         
    }
    
    if ((ucKeyMessage != _NONE_KEY_MESSAGE))
//     && (g_ucPageIndex != _P_SHOW_MUTE))
       CTimerReactiveTimerEvent(SEC(GET_OSDTIMEOUT()), COsdDispOsdTimerEvent);

	DbgShowOSDState();              

	if(fTest)
	{
 		CNotUse();
	}

}
//--------------------------------------------------
void DbgShowOSDState(void)
{
    static BYTE ucPageIndexBak = 0;
    static BYTE ucMenuItemIndexBak = 0;

	if(ucPageIndexBak != g_ucPageIndex)
	{
		ucPageIndexBak = g_ucPageIndex;
#if(_UART_SND_EN == _ON)
		CUartPrintf("PageIndex:",g_ucPageIndex);
#endif
	}
	if(ucMenuItemIndexBak != g_ucMenuItemIndex)
	{
		ucMenuItemIndexBak = g_ucMenuItemIndex;
#if(_UART_SND_EN == _ON)
		CUartPrintf("MenuItemIndex:",g_ucMenuItemIndex);
#endif
	}     
}
//--------------------------------------------------
void CNotUse(void)
{
	CAdjustMZHueSat(0);
	CEepromSaveHueSatData();
	CIRKeyScan();
	CKeyScanReadyTimerEvent();
	CKeyRepeatEnableTimerEvent();
	CAutoDoAutoConfig();

	CAutoDoWhiteBalance();
	CEepromSaveOsdUserData();
	CEepromSaveBriConData();
	CEepromSaveColorTempData();
	CEepromSaveTvData();
	CScalerWriteAmount(0,0,0,0);
	CScalerLoadHardwareVLCFont(0,0);


	SetOsdMap(0);
	SetOSDRamAddress();
	DirectWOSDRam(0, 0, 0, 0);
	SetRowCmds();
	Gotoxy(0, 0, 0);
	OutputChar(0);

	COsdFxCloseWindow(0);
	ValueInRangeChange(0, 0, 0, 0);
	SetOSDDouble(0);
	Textout(0);
	StrLen(0);
	OSDPosition(0, 0, 0, 0, 0);
	OSDClear(0, 0, 0, 0, 0,0);
	COsdFxCodeWrite(0);
	COsdFxEnableOsd();
	COsdFxDisableOsd();
	COsdFxDrawWindow(0, 0, 0, 0, 0);
	VPosGuage();
	HPosGuage();
	ClockGuage();
	COsdFxGetAdcClockRange(0);
	InitBurnIn();
	BurnInRun();

	//GetNextLanguage(0);
	//GetPrevLanguage(0);
	//CheckLanguage();
	//FirstLanguage();

    CDrawCurrentMenu();

    CTextOutRightAlign(0,0,0);

     
}

//--------------------------------------------------
void COsdSystemFlowProc(void)
{        
    switch(ucCurrState)
    {         
        case _PWOFF_STATE:
            break;
            
        case _INITIAL_STATE:
            if(GET_FIRST_LOADFONT() == _TRUE)
            {
                CLR_FIRST_LOADFONT();
                COsdDispFirstTimeLoadFont();
                g_ucMenuItemIndex = _MENU_NONE;
            }
            break;
            
        case _SEARCH_STATE:
            break;
            
        case _ACTIVE_STATE:
            if(GET_OSD_READYFORDISPLAY() == _TRUE)
            {
             //   g_ucMenuItemIndex = _MENU_NONE;
                
                CLR_OSD_READYFORDISPLAY();
                CAdjustBackgroundColor(0x00, 0x00, 0x00);
                
                //LED_ACTIVE();
                CSetVolume();

                if (GET_FIRST_SHOW_NOTE())
                   ucOsdEventMsg = _DO_SHOW_NOTE;
            }
            
            break;
            
        case _NOSUPPORT_STATE:
            if(GET_OSD_READYFORDISPLAY() == _TRUE)
            {
        		g_ucMenuItemIndex = _MENU_NOSIGNAL;
                
                //LED_NOSIGNAL();
                CLR_OSD_READYFORDISPLAY();
                CAdjustBackgroundColor(0x00, 0x00, (_GET_BLUE_BACKGROUND()) ? 0xFF : 0x00);
                if (GET_FIRST_SHOW_NOTE())
                   ucOsdEventMsg = _DO_SHOW_NOTE;
                
                CTimerReactiveTimerEvent(SEC(3), CModeNoSupportEvent);
            }
            
            break;
            
        case _NOSIGNAL_STATE:
            if(GET_OSD_READYFORDISPLAY() == _TRUE)
            {
                g_ucMenuItemIndex = _MENU_NOSIGNAL;

        		// ??? LED_NOSIGNAL();
    
                CLR_OSD_READYFORDISPLAY(); 
    
                CAdjustBackgroundColor(0x00, 0x00, (_GET_BLUE_BACKGROUND()) ? 0xFF : 0x00);
                if (GET_FIRST_SHOW_NOTE())
                   ucOsdEventMsg = _DO_SHOW_NOTE;
                
                if((bVGACONNECT && _SOURCE_VGA == _GET_INPUT_SOURCE()))
                {
                    CTimerReactiveTimerEvent(SEC(3), CModeNoCableEvent);
                }
                else
                {
                    CTimerReactiveTimerEvent(SEC(3), CModeNoSignalEvent);
                     
                    CTimerActiveTimerEvent(SEC(6), CModePowerSavingEvent);
                }
            }
            
            break;
            
        case _SLEEP_STATE:
            break;
            
        default:
            break;
    }
}

//-----------------------------------------------------------
void COsdEventMsgProc(void)
{                  
    if(ucOsdEventMsg > _OE_USER_CMD)
    {
         ucOsdEventMsg = _NONE_MSG;
         return;
    }

    switch(ucOsdEventMsg)
    {
        case _SHOW_NOSIGNAL_MSG:
        case _SHOW_NOCABLE_MSG:
        case _SHOW_NOSUPPORT_MSG:
    		CShowNoSignal();
            break;
            
        case _SAVE_EE_MODEUSERDATA_MSG:
            CEepromSaveModeData(stModeInfo.ModeCurr);
            break;
            
        case _SAVE_EE_SYSTEMDATA_MSG:
            CEepromSaveSystemData();
            break;
            
        case _SAVE_EE_OSDUSERDATA_MSG:
            CEepromSaveOsdUserData();
            break;
            
        case _SAVE_EE_ADCDATA_MSG:
            CEepromSaveAdcData();
            break;
            
        case _SAVE_EE_COLORPROC0_MSG:
            CEepromSaveBriConData();
            break;
            
        case _SAVE_EE_COLORPROC1_MSG:
            CEepromSaveColorTempData();
            break;

        case _SAVE_EE_AUDIO_DATA_MSG:
            CEepromSaveAudioData();
            break;

        case _SAVE_EE_HUE_SAT_DATA_MSG:
            CEepromSaveHueSatData();
            break;

        case _ENTER_FACTORY_MODE_MSG:
            break;
            
        case _SAVE_EE_TV_DATA_MSG:
            CEepromSaveTvData();
            break;

        case _CHANGE_SOURCE_MSG:
            ucTVSyncFailCount = 250;
            CModeResetMode();
        	CLR_SOURCE_AUTOCHANGE();
        	CEepromSaveSystemData();
            CShowNote();  
            break;
            
        case _DO_AUTO_CONFIG:
            break;   
                 /*
        case _OE_SET_MUTE_STATE:    
            CSetMuteState();                   
            break;
                     */
        case _DO_SHOW_NOTE:
            CLR_FIRST_SHOW_NOTE();
            CShowNote();
            break;
            
        default:
            break;
    }
    
    ucOsdEventMsg = _NONE_MSG;
}

//----------------------------------------------------------------------------------------------------
void COsdDispFirstTimeLoadFont(void)
{    
#if(_UART_SND_EN == _ON)
    CUartSendString("FirstTimeLoadFont\n");
#endif    
    COsdFxDisableOsd();
    COsdColorPalette(tPALETTE_0);
    
    SetOsdMap(tUserMenuOsdMap);
    
    COsdLoad1BitFont(FntGlobal,   0x00,     123, tFntGlobalCharWidth);
}
//-----------------------------------------------------------
void COsdDispOsdTimerEvent(void)
{
    COsdFxDisableOsd();
    g_ucPageIndex = _P_MENU_NONE;
    g_ucMenuItemIndex = _MENU_NONE;

    if (GET_AUDIO_MUTE())
       CDrawMuteState();
}

//-----------------------------------------------------------
BYTE CFoundKeyMsgToOsdEvent(SKeyToOsdEvent *tMsgTable)
{
     BYTE i;

     if(ucKeyMessage == _NONE_KEY_MESSAGE)
     {
          //ucOsdEventMsg = _NONE_MSG;
          return 0;
     }
                        
     i = 0;
     while(1)
     {
         if(tMsgTable[i].KeyMessage == _NONE_KEY_MESSAGE)
         {
              //ucOsdEventMsg = _NONE_MSG;
              // End flag
              return 1;
         }
         if(ucKeyMessage == tMsgTable[i].KeyMessage)
         {
              ucOsdEventMsg = tMsgTable[i].OsdEvent;
              return 0;
         }

         i++;
     }
     return 1;
}                                        
//---------------------------------------------------------------------------

void CCoverKeyMsgToOsdEvent(SKeyToOsdEvent *tMsgTable,BYTE bUserPublicKeyEvnet)
{
     bit bFoundPublic = 1;

     if(tMsgTable != NULL)
         bFoundPublic = CFoundKeyMsgToOsdEvent(tMsgTable);

     if(bFoundPublic && bUserPublicKeyEvnet)
     {
         CFoundKeyMsgToOsdEvent(tKOPublic);
     }
}
//---------------------------------------------------------------------------

void CDrawCurrentMenu(void)
{
     BYTE i = 0;

     while(i < CURRENT_MENU.MenuItemCount)
     {
          CURRENT_MENU.Menu[i].Draw(_DRAW_MENU_ITEM);

          if(!CURRENT_MENU.Menu[i].Enable())
          {
              CURRENT_MENU.Menu[i].Draw(_DRAW_DISABLE);
          }
          i++;
     }

     CURRENT_MENU_ITEM.Draw(_DRAW_SELECT);
}
//----------------------------------------------------------------------------------------------------
bit CEnable(void)
{
     return 1;
}

//----------------------------------------------------------------------------------------------------
void CSCKeyMenuRun(BYTE ucEvent)
{
    switch(ucEvent)
    {
    case _OE_SET_MUTE_STATE:
        g_ucPageIndex     = _P_SC_MENU;
        g_ucMenuItemIndex = _SC_MUTE;
        if(CURRENT_MENU.Menu[g_ucMenuItemIndex].Enable())
           CURRENT_MENU_ITEM.MenuRun(0);
        break;
    }
}

//----------------------------------------------------------------------------------------------------
void CMenuProc(void)
{
    switch(ucOsdEventMsg)
    {
        case _OE_MENU_NEXT:         CChangeMenuItem(_INC);             break;
        case _OE_MENU_PREV:         CChangeMenuItem(_DEC);             break;
        case _OE_ENTER_SUBMENU:     CEnterSubMenu();                   break;
        case _OE_RETURN_UPMENU:     CReturnUpMenu();                   break;
        case _OE_ADJ_INC:           CMenuRun(_MENU_ADJ_INC);           break;
        case _OE_ADJ_DEC:           CMenuRun(_MENU_ADJ_DEC);           break;
        case _OE_RUN:               CMenuRun(_MENU_RUN);               break;    
        case _OE_CHANGE_SOURCE:     
            if(_SLEEP_STATE == ucCurrState)
               CModeResetMode();
            ChangeSourceHandler();             
            break;

        case _OE_SET_MUTE_STATE:    CSCKeyMenuRun(ucOsdEventMsg);      break;
    }

}
//----------------------------------------------------------------------------------------------------
void CChangeMenuItem(BYTE ucMode)
{
     BYTE i;
     BYTE ucNewItem;

     CLR_KEYREPEATENABLE();

     //如果菜单只有一项,直接返回
     if(CURRENT_MENU.MenuItemCount <= 1)
     {
          return;
     }

     // 计算下一项菜单，或是上一菜单
     i = 0;

     ucNewItem = ValueInRangeChange(0, CURRENT_MENU.MenuItemCount - 1, g_ucMenuItemIndex, ucMode | _LOOP);

     while(i < CURRENT_MENU.MenuItemCount)
     {
         if(CURRENT_MENU.Menu[ucNewItem].Enable())
         {
             break;
         }

         ucNewItem = ValueInRangeChange(0, CURRENT_MENU.MenuItemCount - 1, ucNewItem, ucMode | _LOOP);
         i++;
     }

     if(ucNewItem == g_ucMenuItemIndex)
     {
         return;
     }

     CURRENT_MENU_ITEM.Draw(_DRAW_NORMARL);

     // Change menu item
     g_ucMenuItemIndex = ucNewItem;

     CURRENT_MENU_ITEM.Draw(_DRAW_SELECT);
}
//----------------------------------------------------------------------------------------------------
void CEnterSubMenu(void)
{
     if(CURRENT_MENU_ITEM.SubMenuID == NULL)
     {
          return;
     }
     
     CURRENT_MENU.Draw(_DRAW_BEFORE_ENTER_SUBMENU);
     g_ucPageIndex = CURRENT_MENU_ITEM.SubMenuID;
     g_ucMenuItemIndex = 0;

     CURRENT_MENU.Draw(_DRAW_ENTER_MENU);
}
//----------------------------------------------------------------------------------------------------
void CReturnUpMenu(void)
{
     if(CURRENT_MENU.ParentMenuID == NULL)
     {
         return;
     }

     CURRENT_MENU.Draw(_DRAW_BEFORE_RETURN_PARENTMENU);

     g_ucPageIndex = CURRENT_MENU.ParentMenuID;
     g_ucMenuItemIndex = CURRENT_MENU.ParentMenuItemIndex;

     CURRENT_MENU.Draw(_DRAW_FROM_SUBMENU_RETURN);
}
//----------------------------------------------------------------------------------------------------
void CMenuRun(BYTE ucMode)
{
     if(CURRENT_MENU_ITEM.MenuRun != NULL)
     {
         CURRENT_MENU_ITEM.MenuRun(ucMode);
     }
}
//----------------------------------------------------------------------------------------------------
void InitOsdFrame(void)
{
    COsdFxDisableOsd();
    SetOSDDouble(0);
    SetOsdMap(tUserMenuOsdMap);

    // Init OSD Ram
    OSDClear(0, GET_OSD_MAP_ROWCOUNT(), 0, 30, 0x8C, BYTE_ATTRIB);
    OSDClear(0, GET_OSD_MAP_ROWCOUNT(), 0, 30, 0x00, BYTE_DISPLAY);
    OSDLine(0, 0, 30, 0x70, BYTE_COLOR);
    OSDClear(1, GET_OSD_MAP_ROWCOUNT() - 1, 0, 30, 0x60, BYTE_COLOR);
    
    COsdFxCodeWrite(ucCloseAllWindow);
    
    COsdFxDrawWindow(0,0,									//WORD usXStart,WORD usYStart,  
    				 _MAINMENU_WIDTH * 12,_MAINMENU_HEIGHT * 18,		//WORD usXEnd,WORD usYEnd,  
    				 tOSD_WINDOW4_STYLE);					//BYTE *pStyle)

    				 
}

//---------------------------------------------------------------------------
void CClearClientOSD(void)
{ 
    OSDClear(0, _MAINMENU_HEIGHT, 0, _MAINMENU_WIDTH + 3, 0x00, BYTE_DISPLAY);
    OSDClear(0, _MAINMENU_HEIGHT, 0, _MAINMENU_WIDTH + 3, 0x8c, BYTE_ATTRIB);
    OSDClear(1, _MAINMENU_HEIGHT, 0, _MAINMENU_WIDTH + 3, 0x60, BYTE_COLOR);
}

//---------------------------------------------------------------------------
void OSDSlider(BYTE row, BYTE col, BYTE length, BYTE value, BYTE range,BYTE color)
{
    unsigned int bound;
    unsigned char i,c;
    OSDLine(row, col, length + 6, color, THE_BYTE2);   // Set Slider Attribute. 4 extra columns for space/numbers/space
    bound   = length * value;
    
    Gotoxy(col,row,THE_BYTE1);
    OutputChar(0x21);          // Left Border
    for (i = 1; i <= length; i++)
    {
        if (bound)
        {
            if(bound >= range)
            {
                c       = 0x28;
                bound   = bound - range;
            }
            else
            {
                color   = (bound << 4) / range;
                bound   = 0;
                if (4 > color)                    c = 0x23;
                else if (7 > color)               c = 0x24;
                else if (10 > color)              c = 0x25;
                else if (13 > color)              c = 0x26;
                else                              c = 0x27;
            }
        }
        else
        {
            c = 0x22;
        }
        OutputChar(c);
    }
    OutputChar(0x29);    // Right Border

    CShowNumber(col + length + 2, row,value);
}

//---------------------------------------------------------------------------
void CShowNoSignal(void)
{
	InitOsdFrame();
	OSDPosition(_MAINMENU_WIDTH * 12,_MAINMENU_HEIGHT * 18,50,50,0x03);
	CCenterTextout(sNosignal[GET_LANGUAGE()],ROW(1),COL(0),_MAINMENU_WIDTH);
	COsdFxEnableOsd();
}

//---------------------------------------------------------------------------
void CShowNote(void)
{
    COsdFxDisableOsd();
    SetOSDDouble(0x03);//SHOW_COLOR(5) | OSD_WINDOWCHAR_BLENDING);
    SetOsdMap(tUserMenuOsdMap);

    // Init OSD Ram
    OSDClear(0, GET_OSD_MAP_ROWCOUNT(), 0, 30, 0x8C, BYTE_ATTRIB);
    OSDClear(0, GET_OSD_MAP_ROWCOUNT(), 0, 30, 0x00, BYTE_DISPLAY);
    OSDLine(0, 0, 30, 0x40, BYTE_COLOR);
    OSDClear(1, GET_OSD_MAP_ROWCOUNT() - 1, 0, 30, 0x60, BYTE_COLOR);
    
    COsdFxCodeWrite(ucCloseAllWindow);
    OSDPosition(_MAINMENU_WIDTH * 12,_MAINMENU_HEIGHT * 18,1,1,0x03);

    switch(_GET_INPUT_SOURCE())
    {
    case _SOURCE_VGA:         CTextOutEx(sSourceVGA, 0, 0);    break;
    case _SOURCE_DVI:         CTextOutEx(sSourceDVI, 0, 0);    break;
    case _SOURCE_VIDEO_AV:    CTextOutEx(sSourceAV, 0, 0);     break;
    case _SOURCE_VIDEO_SV:    CTextOutEx(sSourceSV, 0, 0);     break;
    case _SOURCE_VIDEO_TV:    CTextOutEx(sSourceTV, 0, 0);     break;
    case _SOURCE_HDMI:        CTextOutEx(sSourceHDMI, 0, 0);   break;
    case _SOURCE_YPBPR:       CTextOutEx(sSourceYPBPR, 0, 0);  break;
    }
    COsdFxEnableOsd();
    CPowerPanelOn();  
    CPowerLightPowerOn();
    CTimerReactiveTimerEvent(SEC(5), COsdDispOsdTimerEvent);
}



#endif			//#if(_OSD_TYPE == _OSD001)
