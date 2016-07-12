
#define __OSDDRAW003__

#include "Core\Header\Include.h"

#if(_OSD_TYPE == _OSD003)
//-------------------------------------------------------------------

bit CEnable(void)
{
    return 1;
}

//----------------------------------------------------------------------------------------------------
bit CVideoEnable(void)
{
    if(bSourceVideo() || _SOURCE_YPBPR == _GET_INPUT_SOURCE() || _SOURCE_HDMI == _GET_INPUT_SOURCE())
        return 1;
    else return 0;
}

//------------------------------------------------------------------------
bit CVideoNTSCEnable(void)
{
    if((bSourceVideo() && (ucVideoType == ZNTSC || ucVideoType == ZNTSC_443 || ucVideoType == ZNTSC_50)) &&
       (_SOURCE_YPBPR != _GET_INPUT_SOURCE()))
        return 1;
    else return 0;
}

//------------------------------------------------------------------------
bit CVgaEnable(void)
{
    if(_GET_INPUT_SOURCE() == _SOURCE_VGA)
        return 1;
    else return 0;
}

//---------------------------------------------------------------------------
/*
bit CHDMIEnable(void)
{
    if(_GET_INPUT_SOURCE() == _SOURCE_HDMI)
        return 1;
    else return 0;
} 

//---------------------------------------------------------------------------
bit CDviEnable(void)
{
    if(_GET_INPUT_SOURCE() == _SOURCE_DVI)
        return 1;
    else return 0;
}   */

//---------------------------------------------------------------------------
bit CTVEnable(void)
{
    if(_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV)
        return 1;
    else return 0;
}

//---------------------------------------------------------------------------
bit MDisplayRatioEnable(void)
{
    if(CCalcRatio() >= 75)      // ÆÁµÄ±ÈÀý 4:3 »ò 5:4
        return _FAIL;
    
    return _TRUE;
}

//---------------------------------------------------------------------------
bit MSoundEnable(void)
{
	#if (_SOUND_PROCESSOR)
    return _TRUE;
	#else
    return _FALSE;
	#endif
}

//---------------------------------------------------------------------------
bit MNJW1144Enable(void)
{
	#if(AUDIO_TYPE == _AUDIO_NJW1144)
    return 1;
	#else
    return 0;
	#endif
}

//---------------------------------------------------------------------------
#if(_CHANGE_SOURCE_METHOD == _CHANGE_SOURCE_METHOD_0)
bit CMIVgaEnable(void)
{
    return _VGA_SUPPORT;
}

//---------------------------------------------------------------------------
bit CMIDVIEnable(void)
{
    return _TMDS_SUPPORT;
}

//---------------------------------------------------------------------------
bit CMIHDMIEnable(void)
{
    return _HDMI_SUPPORT;
}

//---------------------------------------------------------------------------
bit CMIYPBPREnable(void)
{
    return _YPBPR_SUPPORT;
}

//---------------------------------------------------------------------------
bit CMISVEnable(void)
{
    return _VIDEO_SV_SUPPORT;
}

//---------------------------------------------------------------------------
bit CMIAVEnable(void)
{
    return _VIDEO_AV_SUPPORT;
}
#endif // #if(_CHANGE_SOURCE_METHOD == _CHANGE_SOURCE_METHOD_0)
//---------------------------------------------------------------------------
bit CMITVEnable(void)
{
    return _VIDEO_TV_SUPPORT;
}

//---------------------------------------------------------------------------
bit CEngEnable(void)
{
    return ENGLISH_EN;
}

//---------------------------------------------------------------------------
bit CCHI_S_Enable(void)
{
    return LNG_CHI_S_EN;
}

//---------------------------------------------------------------------------
bit CFRA_Enable(void)
{
    return LNG_FRA_EN;
}

//---------------------------------------------------------------------------
bit CITA_Enable(void)
{
    return LNG_ITA_EN;
}

//---------------------------------------------------------------------------
bit CDEU_Enable(void)
{
    return LNG_DEU_EN;
}

//---------------------------------------------------------------------------
bit CESP_Enable(void)
{
    return LNG_ESP_EN;
}

//---------------------------------------------------------------------------
bit CCHI_T_Enable(void)
{
    return LNG_CHI_T_EN;
}

//---------------------------------------------------------------------------
bit CJAP_Enable(void)
{
    return LNG_JAP_EN;
}

//---------------------------------------------------------------------------
bit CKOR_Enable(void)
{
    return LNG_KOR_EN;
}

//---------------------------------------------------------------------------
bit CRUS_Enable(void)
{
    return LNG_RUS_EN;
}

//---------------------------------------------------------------------------
bit CEnNtsc_M(void)
{
	#if(_VIDEO_TV_SUPPORT)
    return _TV_NTSC_M_SUPPORT;
	#else
    return 0;
	#endif
}

//---------------------------------------------------------------------------
bit CEnNtsc_BG(void)
{
	#if(_VIDEO_TV_SUPPORT)
    return _TV_NTSC_4_BG_SUPPORT;
	#else
    return 0;
	#endif
}

//---------------------------------------------------------------------------
bit CEnNtsc_DK(void)
{
	#if(_VIDEO_TV_SUPPORT)
    return _TV_NTSC_4_DK_SUPPORT;
	#else
    return 0;
	#endif
}

//---------------------------------------------------------------------------
bit CEnNtsc_I(void)
{
	#if(_VIDEO_TV_SUPPORT)
    return _TV_NTSC_4_I_SUPPORT;
	#else
    return 0;
	#endif
}

//---------------------------------------------------------------------------
bit CEnPal_M(void)
{
	#if(_VIDEO_TV_SUPPORT)
    return _TV_PAL_M_SUPPORT;
	#else
    return 0;
	#endif
}

//---------------------------------------------------------------------------
bit CEnPal_BG(void)
{
	#if(_VIDEO_TV_SUPPORT)
    return _TV_PAL_BG_SUPPORT;
	#else
    return 0;
	#endif
}

//---------------------------------------------------------------------------
bit CEnPal_DK(void)
{
	#if(_VIDEO_TV_SUPPORT)
    return _TV_PAL_DK_SUPPORT;
	#else
    return 0;
	#endif
}

//---------------------------------------------------------------------------
bit CEnPal_I(void)
{
	#if(_VIDEO_TV_SUPPORT)
    return _TV_PAL_I_SUPPORT;
	#else
    return 0;
	#endif
}

//---------------------------------------------------------------------------
bit CEnPal_N(void)
{
	#if(_VIDEO_TV_SUPPORT)
    return _TV_PAL_N_SUPPORT;
	#else
    return 0;
	#endif
}

//---------------------------------------------------------------------------
bit CEnSecam_BG(void)
{
	#if(_VIDEO_TV_SUPPORT)
    return _TV_SECAM_BG_SUPPORT;
	#else
    return 0;
	#endif
}

//---------------------------------------------------------------------------
bit CEnSecam_DK(void)
{
	#if(_VIDEO_TV_SUPPORT)
    return _TV_SECAM_DK_SUPPORT;
	#else
    return 0;
	#endif
}

//---------------------------------------------------------------------------
bit CEnSecam_L(void)
{
	#if(_VIDEO_TV_SUPPORT)
    return _TV_SECAM_L_SUPPORT;
	#else
    return 0;
	#endif
}

//---------------------------------------------------------------------------
bit CEnSecam_LL(void)
{
	#if(_VIDEO_TV_SUPPORT)
    return _TV_SECAM_LL_SUPPORT;
	#else
    return 0;
	#endif
}

//---------------------------------------------------------------------------
bit COSDDoubleEN(void)
{
    if(Panel[ucPanelSelect]->DHWidth < 1280 || Panel[ucPanelSelect]->DVHeight < 1024)
        return _FALSE;
    
    return _TRUE;
}
//---------------------------------------------------------------------------
bit CAFCEnable(void)
{
#if(_TV_AFC)
    return _TRUE;
#endif

    return _FALSE;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
BYTE StateColor(BYTE State)
{
    switch(State)
    {
    case _ST_NORMAL:    return _MENU_NORMAL_COLOR;
    case _ST_SELECT:    return _MENU_SECECT_COLOR;
    case _ST_ADJUST:    return _MENU_ADJUST_COLOR; 
    case _ST_DISABLE:   
    default:            return _MENU_DISABLE_COLOR;     
    }
}

//---------------------------------------------------------------------------
void CreatePopupMenu(BYTE ucRow,BYTE ucHeight)
{
    WORD usWindowLeft;
    WORD usWindowTop;
    WORD usWindowRight;
    WORD usWindowBottom;
    
    BYTE i;
    BYTE x;
    BYTE iCurrRow;
    for(i=0;i<ucHeight;i++)
    {
        iCurrRow = ucRow + i;
        if(iCurrRow % 2)
            x = 20;
        else 
            x = 27;
        
        OSDLine(iCurrRow, COL(x), WIDTH(19), 0x00, BYTE_DISPLAY);
        OSDLine(iCurrRow, COL(x), WIDTH(19), 0x8C, BYTE_ATTRIB);
    }   
    
    usWindowLeft = 21 * 12;
    usWindowRight = (21 + 18) * 12;
    usWindowTop = (WORD)ucRow * 18;
    usWindowBottom = (WORD)(ucRow + ucHeight) * 18;
    
    COsdFxDrawWindow(usWindowLeft, usWindowTop, usWindowRight, usWindowBottom, tPopupMenuWindowStyle);
}

//---------------------------------------------------------------------------
void ClearPopupMenu(BYTE ucRow,BYTE ucHeight)
{
    BYTE i;
    BYTE x;
    BYTE iCurrRow; 
    
    for(i=0;i<ucHeight;i++)
    {
        iCurrRow = ucRow + i;
        if(iCurrRow % 2)
        {
            x = 20;
            SETCOLOR_SUBMENU_SELLINE(iCurrRow);
        }
        else 
        {
            x = 27;
        }
        
        OSDLine(iCurrRow, COL(x), WIDTH(19), 0x00, BYTE_DISPLAY);
        OSDLine(iCurrRow, COL(x), WIDTH(19), 0x8C, BYTE_ATTRIB);
    }
    
    COsdFxCloseWindow(4);
}

//---------------------------------------------------------------------------
void DrawAPopupMenuItem(BYTE *str,BYTE ItemIndex,BYTE ucRowStart,BYTE ucColStart,BYTE State)
{
    BYTE c;
    //BYTE x;
    BYTE ucColor = StateColor(State);
    
    ItemIndex = ItemIndex + ucRowStart + 1;
    
    if(State == _ST_SELECT)
        c = 0x57;   // Select Icon
    else
        c = 0x01;   // Clear Select Icon
    
    if(ItemIndex % 2)
        ucColStart += 21;
    else
        ucColStart += 27;
    
    OSDLine(ROW(ItemIndex), COL(ucColStart), LENGTH(19), ucColor, BYTE_COLOR);
    
    Gotoxy(COL(ucColStart + 1),ROW(ItemIndex),BYTE_DISPLAY);
    OutputChar(c);
    
    CTextOutEx(str, COL(ucColStart + 3), ROW(ItemIndex));
}

//---------------------------------------------------------------------------
void InitMainOsd(void)
{
    BYTE i;
    
    InitOsdFrame();
    SetOSDDouble((GET_OSD_SIZE() ? 0x03 : 0x00)  | OSD_WINDOWCHAR_BLENDING);   
    
    // Draw Top Line
    OSDLine(ROW(3), COL(1), LENGTH(37), 0xA6, THE_BYTE0);
    OSDLine(ROW(3), COL(1), LENGTH(37), 0xA4, THE_BYTE1);
    OSDLine(ROW(3), COL(1), LENGTH(37), 0x11, THE_BYTE2);
    
    // Draw Bottom Line
    OSDLine(ROW(16), COL(1), LENGTH(37), 0xA6, THE_BYTE0);
    OSDLine(ROW(16), COL(1), LENGTH(37), 0xA4, THE_BYTE1);
    OSDLine(ROW(16), COL(1), LENGTH(37), 0x11, THE_BYTE2);
    
    // Draw Left Line
    for(i=0;i<12;i++)
    {
        Gotoxy(5 , 4 + i , ALL_BYTE);
        CScalerSendAddr(_OSD_DATA_PORT_92 , _NON_AUTOINC);
        *(&MCU_SCA_INF_DATA_FFF5) = 0xA6;
        *(&MCU_SCA_INF_DATA_FFF5) = 0xA5;
        *(&MCU_SCA_INF_DATA_FFF5) = 0x11;
    }
    
    // set submenu selet line color
    for(i=0;i<6;i++)
    {
        SETCOLOR_SUBMENU_SELLINE(SHOWINDEX_TO_LINE(i) + 1);
    }
    
    // Draw Window
    COsdFxDrawWindow(0,0,                                       //WORD usXStart,WORD usYStart,  
        _MAINMENU_WIDTH + 20,_MAINMENU_HEIGHT,                  //WORD usXEnd,WORD usYEnd,  
        tMainWindowStyle);                                      //BYTE *pStyle)
    
    // set osd position
    if (GET_OSD_SIZE())
    {
        SetOSDDouble(0x03 | OSD_WINDOWCHAR_BLENDING);
    }
    else
    {
        SetOSDDouble(OSD_WINDOWCHAR_BLENDING);
    }
    CSetOSDPosition(_MAINMENU_WIDTH, _MAINMENU_HEIGHT, stOsdUserData.OsdHPos, stOsdUserData.OsdVPos);

    COsdFxEnableOsd();
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawMainMenuItem(BYTE ucItem,BYTE ucState)
{
    BYTE y;
    BYTE *tIcon;
    
    y = GetShowIndex(ucItem,_MI_COLOR,_MI_SOUND);
    
    if(y == _NOT_SHOW)
        return;
    
    y = SHOWINDEX_TO_LINE(y);
    
    if(!g_tMenuItem[ucItem].Enable())
    {
        ucState = _ST_DISABLE;  
    }
    
    switch(ucState)
    {
    case _ST_NORMAL:
        tIcon = tIcon_Normal[ucItem - _MI_COLOR];
        break;
    case _ST_SELECT:
        tIcon = tIcon_Select[ucItem - _MI_COLOR];
        break;
    case _ST_DISABLE:
        tIcon = tIcon_Disable[ucItem - _MI_COLOR];
        break;
    }
    
    Draw2bit3x2Icon(tIcon,1,y);
}

//---------------------------------------------------------------------------
// ucItem : MainMenu\_MI_COLOR,_MI_ADJUST,_MI_OSD,_MI_TV,_MI_FUNCTION,_MI_SOUND,
void DrawMainItemTitle(BYTE ucItem)
{
    BYTE i;
    BYTE n;
    BYTE x; 
    BYTE Width;
    BYTE code *tFont;
    
    tFont = tMainTitle[ucItem - _MI_COLOR][GET_LANGUAGE()].Font;
    Width = tMainTitle[ucItem - _MI_COLOR][GET_LANGUAGE()].Width;
    
    CScalerLoadHardwareVLCFont(tFont, 0xE8);
    
    // 39 : OSD Width
    x = (39 - Width)/2;
    n = 0xE8;
    
    Gotoxy(x,1,BYTE_DISPLAY);
    CScalerSendAddr(_OSD_DATA_PORT_92 , _NON_AUTOINC);
    for(i=0;i<Width;i++)
    {
        *(&MCU_SCA_INF_DATA_FFF5) = n++;
    }
    
    Gotoxy(x,2,BYTE_DISPLAY);
    CScalerSendAddr(_OSD_DATA_PORT_92 , _NON_AUTOINC);
    for(i=0;i<Width;i++)
    {
        *(&MCU_SCA_INF_DATA_FFF5) = n++;
    }   
}

//---------------------------------------------------------------------------
void DrawMainMenu(void)
{
    BYTE i;
    BYTE ucMode;
    InitMainOsd();
#if(_CHINESE_FONT_TYPE == _CHINESE_2_FONT)    
    LoadCHIFont(_LF_COLOR_PAGE);
#endif    
    for(i=_MI_COLOR;i<=_MI_SOUND;i++)
    {
        if(i == ucOsdState)
        {
            ucMode = _ST_SELECT;
            DrawMainItemTitle(i);
        }
        else
        {
            ucMode = _ST_NORMAL;
        }
        DrawMainMenuItem(i,     ucMode);
    }
    
    DrawSubMenu(ucOsdState);
}

//---------------------------------------------------------------------------
void SubMenuTextOut(BYTE *str,BYTE y,BYTE ucColor,BYTE State)
{
    // set color
    SUBMENU_LINECOLOR(y,ucColor);
    // draw menu item 
    SUBMENU_TEXTOUT(str,y);
    
    // draw select line
    if(State == _ST_SELECT || State == _ST_ADJUST)
    {
        DRAW_SUBMENU_SELLINE(y + 1);
    }
    else
    {
        CLEAR_SUBMENU_SELLINE(y + 1);
    }
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawBright(BYTE State)
{
    BYTE y;
    BYTE ucColor,ucColor1;
    
    // get display line
    y = GetShowIndex(_MI_BRIGHTNESS,BEGIN(_MI_BRIGHTNESS),END(_MI_COLORTEMP));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    if(State == _ST_ADJUST)
    {
        ucColor1 = StateColor(_ST_SELECT);
    }
    else
    {
        ucColor1 = ucColor;
    }
    
    y = SHOWINDEX_TO_LINE(y);
    
    SubMenuTextOut(sBrightness[GET_LANGUAGE()],y,ucColor1,State);
    
    // draw slider
    OSD_SLIDER(y,stConBriData.Brightness,ucColor);
    
}

//---------------------------------------------------------------------------
void BrightAdjust(BYTE ucMode)
{
    BYTE y;
    
    // ucMode : _INC or _DEC
    SET_KEYREPEATENABLE();
    stConBriData.Brightness = ValueInRangeChange(0, 100, stConBriData.Brightness, _NON_LOOP | ucMode);
    CAdjustBrightness();
    ucOsdEventMsg = _SAVE_EE_COLORPROC0_MSG;
    
    // get display line
    y = GetShowIndex(_MI_BRIGHTNESS,BEGIN(_MI_BRIGHTNESS),END(_MI_COLORTEMP));
    
    if(y == _NOT_SHOW)
        return;
    
    y = SHOWINDEX_TO_LINE(y);
    
	#if(_KEY_TYPE == _KT_PCB2660_003)
    OSD_SLIDER(y,stConBriData.Brightness,_MENU_SECECT_COLOR);
	#endif
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    OSD_SLIDER(y,stConBriData.Brightness,_MENU_ADJUST_COLOR);
	#endif
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawContrast(BYTE State)
{
    BYTE y;
    BYTE ucColor;
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    BYTE ucColor1;
	#endif
    
    // get display line
    y = GetShowIndex(_MI_CONTRAST,BEGIN(_MI_BRIGHTNESS),END(_MI_COLORTEMP));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    if(State == _ST_ADJUST)
    {
        ucColor1 = StateColor(_ST_SELECT);
    }
    else
    {
        ucColor1 = ucColor;
    }
	#endif      
    y = SHOWINDEX_TO_LINE(y);
    
	#if(_KEY_TYPE == _KT_PCB2660_003)
    SubMenuTextOut(sContrast[GET_LANGUAGE()],y,ucColor,State);
	#endif
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    SubMenuTextOut(sContrast[GET_LANGUAGE()],y,ucColor1,State);
	#endif
    // draw slider
    OSD_SLIDER(y,stConBriData.Contrast,ucColor);
}

//---------------------------------------------------------------------------
void ContrastAdjust(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    BYTE y;
    
    SET_KEYREPEATENABLE();
    stConBriData.Contrast = ValueInRangeChange(0, 100, stConBriData.Contrast, _NON_LOOP | ucMode);
    CAdjustContrast();
    ucOsdEventMsg = _SAVE_EE_COLORPROC0_MSG;
    
    
    // get display line
    y = GetShowIndex(_MI_CONTRAST,BEGIN(_MI_BRIGHTNESS),END(_MI_COLORTEMP));
    
    if(y == _NOT_SHOW)
        return;
    
    y = SHOWINDEX_TO_LINE(y);
	#if(_KEY_TYPE == _KT_PCB2660_003)   
    OSD_SLIDER(y,stConBriData.Contrast,_MENU_SECECT_COLOR);
	#endif
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    OSD_SLIDER(y,stConBriData.Contrast,_MENU_ADJUST_COLOR);
	#endif
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawHue(BYTE State)
{
    BYTE y;
    BYTE ucColor;
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)  
    BYTE ucColor1;
	#endif
    
    // get display line
    y = GetShowIndex(_MI_HUE,BEGIN(_MI_BRIGHTNESS),END(_MI_COLORTEMP));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    if(State == _ST_ADJUST)
    {
        ucColor1 = StateColor(_ST_SELECT);
    }
    else
    {
        ucColor1 = ucColor;
    }
	#endif  
    
    y = SHOWINDEX_TO_LINE(y);
    
	#if(_KEY_TYPE == _KT_PCB2660_003)
    SubMenuTextOut(sHue[GET_LANGUAGE()],y,ucColor,State);
	#endif
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    SubMenuTextOut(sHue[GET_LANGUAGE()],y,ucColor1,State);
	#endif
    // draw slider
    OSD_SLIDER(y,GET_HUE(),ucColor);  
}

//---------------------------------------------------------------------------
void HueAdjust(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    BYTE y;
    
    SET_KEYREPEATENABLE();
    stHueSatData.Hue = ValueInRangeChange(0, 100, stHueSatData.Hue, _NON_LOOP | ucMode);
    if(bSourceVideo())
        gmi_CAdjustVDCHue(GET_HUE());
    else
        CAdjustYpbprhue(GET_HUE());
    ucOsdEventMsg = _SAVE_EE_HUE_SAT_DATA_MSG;
    
    
    // get display line
    y = GetShowIndex(_MI_HUE,BEGIN(_MI_BRIGHTNESS),END(_MI_COLORTEMP));
    
    if(y == _NOT_SHOW)
        return;
    
    y = SHOWINDEX_TO_LINE(y);
	#if(_KEY_TYPE == _KT_PCB2660_003)
    OSD_SLIDER(y,GET_HUE(),_MENU_SECECT_COLOR);
	#endif
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    OSD_SLIDER(y,GET_HUE(),_MENU_ADJUST_COLOR);
	#endif   
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawSaturation(BYTE State)
{
    BYTE y;
    BYTE ucColor;
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)  
    BYTE ucColor1;
	#endif  
    
    // get display line
    y = GetShowIndex(_MI_SATURATION,BEGIN(_MI_BRIGHTNESS),END(_MI_COLORTEMP));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    if(State == _ST_ADJUST)
    {
        ucColor1 = StateColor(_ST_SELECT);
    }
    else
    {
        ucColor1 = ucColor;
    }
	#endif  
    
	#if(_KEY_TYPE == _KT_PCB2660_003)
    SubMenuTextOut(sSaturation[GET_LANGUAGE()],y,ucColor,State);
	#endif
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    SubMenuTextOut(sSaturation[GET_LANGUAGE()],y,ucColor1,State);
	#endif
    // draw slider
    OSD_SLIDER(y,GET_SATURATION(),ucColor);
}

//---------------------------------------------------------------------------
void SaturationAdjust(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    BYTE y;
    
    SET_KEYREPEATENABLE();
    stHueSatData.Saturation = ValueInRangeChange(0, 100, stHueSatData.Saturation, _NON_LOOP | ucMode);
    if(bSourceVideo())
        CVideoSetSaturation(GET_SATURATION());
    else
        CAdjustYpbprSaturation(GET_SATURATION());
    ucOsdEventMsg = _SAVE_EE_HUE_SAT_DATA_MSG;            
    
    
    // get display line
    y = GetShowIndex(_MI_SATURATION,BEGIN(_MI_BRIGHTNESS),END(_MI_COLORTEMP));
    
    if(y == _NOT_SHOW)
        return;
    
    y = SHOWINDEX_TO_LINE(y);
    
	#if(_KEY_TYPE == _KT_PCB2660_003)   
    OSD_SLIDER(y,GET_SATURATION(),_MENU_SECECT_COLOR);
	#endif
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)    
    OSD_SLIDER(y,GET_SATURATION(),_MENU_ADJUST_COLOR);
	#endif  
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawColorTemp(BYTE State)
{
    BYTE y;
    BYTE ucColor;
    char *pStr;
    
    // get display line
    y = GetShowIndex(_MI_COLORTEMP,BEGIN(_MI_BRIGHTNESS),END(_MI_COLORTEMP));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
    SubMenuTextOut(sColorTemp[GET_LANGUAGE()],y,ucColor,State);
    
    switch(GET_COLOR_TEMP_TYPE())
    {
    case _CT_9300:          pStr = s9300[GET_LANGUAGE()];       break;
    case _CT_6500:          pStr = s6500[GET_LANGUAGE()];       break;
    case _CT_USER:
    default:                pStr = sUser[GET_LANGUAGE()];       break;
    }       
    
    SUBMENU_RIGHT_TEXTOUT(pStr, y);  
}

//---------------------------------------------------------------------------
// ucItem : MainMenu\Color\_MI_BRIGHTNESS,_MI_CONTRAST,_MI_HUE,_MI_SATURATION,_MI_COLORTEMP,
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawColorPageMenuItem(BYTE ucItem,BYTE ucState)
{
    if(!g_tMenuItem[ucItem].Enable())
    {
        ucState = _ST_DISABLE;  
    }
    
    switch(ucItem)
    {
    case _MI_BRIGHTNESS:        DrawBright(ucState);        break;
    case _MI_CONTRAST:          DrawContrast(ucState);      break;
    case _MI_HUE:               DrawHue(ucState);           break;
    case _MI_SATURATION:        DrawSaturation(ucState);    break;
    case _MI_COLORTEMP:         DrawColorTemp(ucState);     break;
    }
}

//---------------------------------------------------------------------------
//  SUBMENU_TEXTOUT(sSpace,Row);
void DrawPageNullLine(BYTE MenuBegin,BYTE MenuEnd)
{
    BYTE ucCount = GetShowCount(MenuBegin,MenuEnd);
    
    for(;ucCount<6;ucCount++)
    {
        SUBMENU_TEXTOUT(sSpace,SHOWINDEX_TO_LINE(ucCount));
    }
}

//---------------------------------------------------------------------------
// MainMenu\Color\_MI_BRIGHTNESS,_MI_CONTRAST,_MI_HUE,_MI_SATURATION,_MI_COLORTEMP,
void DrawColorPage(void)
{
    BYTE i;
    BYTE ucState;
    
    for(i=_MI_BRIGHTNESS;i<=_MI_COLORTEMP;i++)
    {
        if(i == ucOsdState)
        {
            ucState = _ST_SELECT;
        }
        else
        {
            ucState = _ST_NORMAL;
        }
        
        DrawColorPageMenuItem(i,        ucState);
    }
    DrawPageNullLine(_MI_BRIGHTNESS,_MI_COLORTEMP);
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawAutoAdjust(BYTE State)
{
    BYTE y;
    BYTE ucColor;
    
    // get display line
    y = GetShowIndex(_MI_AUTOADJUST,BEGIN(_MI_AUTOADJUST),END(_MI_CLOCK));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
    SubMenuTextOut(sAutoConfig[GET_LANGUAGE()],y,ucColor,State);
    
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawHPosition(BYTE State)
{
    BYTE y;
    BYTE ucColor;
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)      
    BYTE ucColor1;
	#endif  
    
    // get display line
    y = GetShowIndex(_MI_HPOSITION,BEGIN(_MI_AUTOADJUST),END(_MI_CLOCK));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    if(State == _ST_ADJUST)
    {
        ucColor1 = StateColor(_ST_SELECT);
    }
    else
    {
        ucColor1 = ucColor;
    }
	#endif  
    
    y = SHOWINDEX_TO_LINE(y);
    
	#if(_KEY_TYPE == _KT_PCB2660_003)
        SubMenuTextOut(sHPosition[GET_LANGUAGE()],y,ucColor,State);
	#endif
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    SubMenuTextOut(sHPosition[GET_LANGUAGE()],y,ucColor1,State);
	#endif
    
    // draw slider
    OSD_SLIDER(y,COsdCtrlGetHPosition(),ucColor); 
}

//---------------------------------------------------------------------------
void HPositionAdjust(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    BYTE y;
    
    SET_KEYREPEATENABLE();
    
    stModeUserData.HPosition = ValueInRangeChange(stModeUserCenterData.CenterHPos - _HPOSITION_BIAS,
        stModeUserCenterData.CenterHPos + _HPOSITION_BIAS,
        stModeUserData.HPosition,_NON_LOOP | ucMode);
    
    ucOsdEventMsg = _SAVE_EE_MODEUSERDATA_MSG;
    CAdjustHPosition();
    
    // get display line
    y = GetShowIndex(_MI_HPOSITION,BEGIN(_MI_AUTOADJUST),END(_MI_CLOCK));
    
    if(y == _NOT_SHOW)
        return;
    
    y = SHOWINDEX_TO_LINE(y);
	#if(_KEY_TYPE == _KT_PCB2660_003)
    OSD_SLIDER(y,COsdCtrlGetHPosition(),_MENU_SECECT_COLOR);
	#endif
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    OSD_SLIDER(y,COsdCtrlGetHPosition(),_MENU_ADJUST_COLOR);
	#endif
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawVPosition(BYTE State)
{
    BYTE y;
    BYTE ucColor;
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)  
    BYTE ucColor1;
	#endif
    
    // get display line
    y = GetShowIndex(_MI_VPOSITION,BEGIN(_MI_AUTOADJUST),END(_MI_CLOCK));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    if(State == _ST_ADJUST)
    {
        ucColor1 = StateColor(_ST_SELECT);
    }
    else
    {
        ucColor1 = ucColor;
    }   
	#endif
    
    y = SHOWINDEX_TO_LINE(y);
    
	#if(_KEY_TYPE == _KT_PCB2660_003)
    SubMenuTextOut(sVPosition[GET_LANGUAGE()],y,ucColor,State);
	#endif
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    SubMenuTextOut(sVPosition[GET_LANGUAGE()],y,ucColor1,State);
	#endif
    // draw slider
    OSD_SLIDER(y,COsdCtrlGetVPosition(),ucColor);  
}

//---------------------------------------------------------------------------
void VPositionAdjust(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    BYTE y;
    
    SET_KEYREPEATENABLE();
    
    stModeUserData.VPosition = ValueInRangeChange(stModeUserCenterData.CenterVPos - _VPOSITION_BIAS,
        stModeUserCenterData.CenterVPos + _VPOSITION_BIAS,
        stModeUserData.VPosition,
        _NON_LOOP | ucMode);
    
    ucOsdEventMsg = _SAVE_EE_MODEUSERDATA_MSG;
    CAdjustVPosition();
    
    // get display line
    y = GetShowIndex(_MI_VPOSITION,BEGIN(_MI_AUTOADJUST),END(_MI_CLOCK));
    
    if(y == _NOT_SHOW)
        return;
    
    y = SHOWINDEX_TO_LINE(y);
	#if(_KEY_TYPE == _KT_PCB2660_003)
    OSD_SLIDER(y,COsdCtrlGetVPosition(),_MENU_SECECT_COLOR);
	#endif
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    OSD_SLIDER(y,COsdCtrlGetVPosition(),_MENU_ADJUST_COLOR);
	#endif
}

//---------------------------------------------------------------------------
void PhaseAdjust(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    BYTE y;
    
    SET_KEYREPEATENABLE();
    
    stModeUserData.Phase = ValueInRangeChange(0, 63, stModeUserData.Phase, _NON_LOOP | ucMode);
    
    ucOsdEventMsg = _SAVE_EE_MODEUSERDATA_MSG;
    CAdjustPhase(stModeUserData.Phase);
    
    // get display line
    y = GetShowIndex(_MI_PHASE,BEGIN(_MI_AUTOADJUST),END(_MI_CLOCK));
    
    if(y == _NOT_SHOW)
        return;
    
    y = SHOWINDEX_TO_LINE(y);
	#if(_KEY_TYPE == _KT_PCB2660_003)
    OSDSlider(y, 30, 10, stModeUserData.Phase, 63, _MENU_SECECT_COLOR);
	#endif
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    OSDSlider(y, 30, 10, stModeUserData.Phase, 63, _MENU_ADJUST_COLOR);
	#endif
}

//---------------------------------------------------------------------------
void ClockAdjust(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    BYTE y;
    
    SET_KEYREPEATENABLE();
    
    // stModeUserData.VPosition = ValueInRangeChange(stModeUserCenterData.CenterVPos - _VPOSITION_BIAS,stModeUserCenterData.CenterVPos + _VPOSITION_BIAS,stModeUserData.VPosition,_NON_LOOP | ucMode);
    stModeUserData.Clock = ValueInRangeChange(COsdFxGetAdcClockRange(_GET_CLOCKRANGE_MIN), COsdFxGetAdcClockRange(_GET_CLOCKRANGE_MAX), stModeUserData.Clock, _NON_LOOP | ucMode);
    
    ucOsdEventMsg = _SAVE_EE_MODEUSERDATA_MSG;
	   //080324
///	CAdjustAdcClock(stModeUserData.Clock);
	CAdjustAdcClock(stModeUserData.Clock, 2);
    
    // get display line
    y = GetShowIndex(_MI_CLOCK,BEGIN(_MI_AUTOADJUST),END(_MI_CLOCK));
    
    if(y == _NOT_SHOW)
        return;
    
    y = SHOWINDEX_TO_LINE(y);
	#if(_KEY_TYPE == _KT_PCB2660_003)
    OSD_SLIDER(y,COsdCtrlGetClock(),_MENU_SECECT_COLOR);
	#endif
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    OSD_SLIDER(y,COsdCtrlGetClock(),_MENU_ADJUST_COLOR);
	#endif
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawPhase(BYTE State)
{
    BYTE y;
    BYTE ucColor;
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)  
    BYTE ucColor1;
	#endif
    
    // get display line
    y = GetShowIndex(_MI_PHASE,BEGIN(_MI_AUTOADJUST),END(_MI_CLOCK));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    if(State == _ST_ADJUST)
    {
        ucColor1 = StateColor(_ST_SELECT);
    }
    else
    {
        ucColor1 = ucColor;
    }       
	#endif
    
    y = SHOWINDEX_TO_LINE(y);
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    SubMenuTextOut(sPhase[GET_LANGUAGE()],y,ucColor1,State);
	#endif
	#if(_KEY_TYPE == _KT_PCB2660_003)
    SubMenuTextOut(sPhase[GET_LANGUAGE()],y,ucColor,State);
	#endif
    // draw slider
    OSDSlider(y, 30, 10, stModeUserData.Phase, 63, ucColor);
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawClock(BYTE State)
{
    BYTE y;
    BYTE ucColor;
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)  
    BYTE ucColor1;
	#endif  
    
    // get display line
    y = GetShowIndex(_MI_CLOCK,BEGIN(_MI_AUTOADJUST),END(_MI_CLOCK));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    if(State == _ST_ADJUST)
    {
        ucColor1 = StateColor(_ST_SELECT);
    }
    else
    {
        ucColor1 = ucColor;
    }   
	#endif  
    
    y = SHOWINDEX_TO_LINE(y);
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    SubMenuTextOut(sClock[GET_LANGUAGE()],y,ucColor1,State);
	#endif
    
	#if(_KEY_TYPE == _KT_PCB2660_003)
    SubMenuTextOut(sClock[GET_LANGUAGE()],y,ucColor,State);
	#endif
    
    // draw slider
    OSD_SLIDER(y,COsdCtrlGetClock(),ucColor);
    
}

//---------------------------------------------------------------------------
// ucItem : MainMenu\Adjust\_MI_AUTOADJUST,_MI_HPOSITION,_MI_VPOSITION,_MI_PHASE,_MI_CLOCK,
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawAdjustPageMenuItem(BYTE ucItem,BYTE ucState)
{
    if(!g_tMenuItem[ucItem].Enable())
    {
        ucState = _ST_DISABLE;  
    }
    
    switch(ucItem)
    {
    case _MI_AUTOADJUST:        DrawAutoAdjust(ucState);        break;
    case _MI_HPOSITION:         DrawHPosition(ucState);         break;
    case _MI_VPOSITION:         DrawVPosition(ucState);         break;
    case _MI_PHASE:             DrawPhase(ucState);             break;
    case _MI_CLOCK:             DrawClock(ucState);             break;
    }
}

//---------------------------------------------------------------------------
// MainMenu\Adjust\_MI_AUTOADJUST,_MI_HPOSITION,_MI_VPOSITION,_MI_PHASE,_MI_CLOCK,
void DrawAdjustPage(void)
{
    BYTE i;
    BYTE ucState;
    
    for(i=_MI_AUTOADJUST;i<=_MI_CLOCK;i++)
    {
        if(i == ucOsdState)
        {
            ucState = _ST_SELECT;
        }
        else
        {
            ucState = _ST_NORMAL;
        }
        
        DrawAdjustPageMenuItem(i,       ucState);
    }
    DrawPageNullLine(_MI_AUTOADJUST,_MI_CLOCK);
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawLanguage(BYTE State)
{
    BYTE y;
    BYTE ucColor;
    
    // get display line
    y = GetShowIndex(_MI_LANGUAGE,BEGIN(_MI_LANGUAGE),END(_MI_TRANSPARENT));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
    SubMenuTextOut(sLanguage[GET_LANGUAGE()],y,ucColor,State);
    
    SUBMENU_RIGHT_TEXTOUT(sLanguageName[GET_LANGUAGE()],y);
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawOSDHPosition(BYTE State)
{
    BYTE y;
    BYTE ucColor;
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)  
    BYTE ucColor1;
	#endif
    
    // get display line
    y = GetShowIndex(_MI_OSD_HPOSITION,BEGIN(_MI_LANGUAGE),END(_MI_TRANSPARENT));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    if(State == _ST_ADJUST)
    {
        ucColor1 = StateColor(_ST_SELECT);
    }
    else
    {
        ucColor1 = ucColor;
    }   
	#endif  
    
    y = SHOWINDEX_TO_LINE(y);
	#if(_KEY_TYPE == _KT_PCB2660_003)
    SubMenuTextOut(sHPosition[GET_LANGUAGE()],y,ucColor,State);
	#endif
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    SubMenuTextOut(sHPosition[GET_LANGUAGE()],y,ucColor1,State);
	#endif
    // draw slider
    OSD_SLIDER(y,stOsdUserData.OsdHPos,ucColor);
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawOSDVPosition(BYTE State)
{
    BYTE y;
    BYTE ucColor;
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)  
    BYTE ucColor1;
	#endif  
    
    // get display line
    y = GetShowIndex(_MI_OSD_VPOSITION,BEGIN(_MI_LANGUAGE),END(_MI_TRANSPARENT));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)      
    if(State == _ST_ADJUST)
    {
        ucColor1 = StateColor(_ST_SELECT);
    }
    else
    {
        ucColor1 = ucColor;
    }   
    
    SubMenuTextOut(sVPosition[GET_LANGUAGE()],y,ucColor1,State);
	#endif
	#if(_KEY_TYPE == _KT_PCB2660_003)
    SubMenuTextOut(sVPosition[GET_LANGUAGE()],y,ucColor,State);
	#endif
    
    // draw slider
    OSD_SLIDER(y,stOsdUserData.OsdVPos,ucColor);
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawOSDTimer(BYTE State)
{
    BYTE y;
    BYTE ucColor;
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)  
    BYTE ucColor1;
	#endif  
    
    // get display line
    y = GetShowIndex(_MI_TIMER,BEGIN(_MI_LANGUAGE),END(_MI_TRANSPARENT));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    if(State == _ST_ADJUST)
    {
        ucColor1 = StateColor(_ST_SELECT);
    }
    else
    {
        ucColor1 = ucColor;
    }   
    
    SubMenuTextOut(sTimer[GET_LANGUAGE()],y,ucColor1,State);
	#endif
    
	#if(_KEY_TYPE == _KT_PCB2660_003)
    SubMenuTextOut(sTimer[GET_LANGUAGE()],y,ucColor,State);
	#endif
    
    OSDLine(y, _MSG_COL, LENGTH(10), ucColor, BYTE_COLOR);
    if (stOsdUserData.OsdTimeout < 5)
    {
        stOsdUserData.OsdTimeout = 0;
        SUBMENU_RIGHT_TEXTOUT(sOff[GET_LANGUAGE()], y);
    }
    else
    {       
        CShowNumber(_MSG_COL, y, GET_OSDTIMEOUT());
    }
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawDouble(BYTE State)
{
    BYTE y;
    BYTE ucColor;
    BYTE *pStr;
    
    // get display line
    y = GetShowIndex(_MI_DOUBLE,BEGIN(_MI_LANGUAGE),END(_MI_TRANSPARENT));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
    SubMenuTextOut(sDouble[GET_LANGUAGE()],y,ucColor,State);
    
    if(GET_OSD_SIZE())
        pStr = sOn[GET_LANGUAGE()];
    else pStr = sOff[GET_LANGUAGE()];
    SUBMENU_RIGHT_TEXTOUT(pStr, y);
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawTransparent(BYTE State)
{
    BYTE y;
    BYTE ucColor;
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)  
    BYTE ucColor1;
	#endif  
    
    // get display line
    y = GetShowIndex(_MI_TRANSPARENT,BEGIN(_MI_LANGUAGE),END(_MI_TRANSPARENT));
    
    if(y == _NOT_SHOW)
    {
        return;
    }
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)  
    if(State == _ST_ADJUST)
    {
        ucColor1 = StateColor(_ST_SELECT);
    }
    else
    {
        ucColor1 = ucColor;
    }   
    
    SubMenuTextOut(sTransparent[GET_LANGUAGE()],y,ucColor1,State);
	#endif
    
	#if(_KEY_TYPE == _KT_PCB2660_003)   
    SubMenuTextOut(sTransparent[GET_LANGUAGE()],y,ucColor,State);
	#endif  
    
    OSDLine(y, _MSG_COL, LENGTH(10), ucColor, BYTE_COLOR);
    if (0 == GET_OSDBLENDING())
        SUBMENU_RIGHT_TEXTOUT(sOff[GET_LANGUAGE()], y);
    else
        CShowNumber(_MSG_COL, y, GET_OSDBLENDING());
}

//---------------------------------------------------------------------------
// ucItem : MainMenu\OSD\_MI_LANGUAGE,_MI_OSD_HPOSITION,_MI_OSD_VPOSITION,_MI_TIMER,_MI_DOUBLE,_MI_TRANSPARENT,
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawOsdPageMenuItem(BYTE ucItem,BYTE ucState)
{
    if(!g_tMenuItem[ucItem].Enable())
    {   
        ucState = _ST_DISABLE;  
    }
    
    switch(ucItem)
    {
    case _MI_LANGUAGE:              DrawLanguage(ucState);              break;
    case _MI_OSD_HPOSITION:         DrawOSDHPosition(ucState);          break;
    case _MI_OSD_VPOSITION:         DrawOSDVPosition(ucState);          break;
    case _MI_TIMER:                 DrawOSDTimer(ucState);              break;
    case _MI_DOUBLE:                DrawDouble(ucState);                break;
    case _MI_TRANSPARENT:           DrawTransparent(ucState);           break;
    }
}

//---------------------------------------------------------------------------
// MainMenu\OSD\_MI_LANGUAGE,_MI_OSD_HPOSITION,_MI_OSD_VPOSITION,_MI_TIMER,_MI_DOUBLE,_MI_TRANSPARENT,
void DrawOSDPage(void)
{
    BYTE i;
    BYTE ucState;
    
    for(i=_MI_LANGUAGE;i<=_MI_TRANSPARENT;i++)
    {
        if(i == ucOsdState)
        {
            ucState = _ST_SELECT;
        }
        else
        {
            ucState = _ST_NORMAL;
        }
        
        DrawOsdPageMenuItem(i,      ucState);
    }
    DrawPageNullLine(_MI_LANGUAGE,_MI_TRANSPARENT);
    
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawChannel(BYTE State)
{
    BYTE y;
    BYTE ucColor;
    
    // get display line
    y = GetShowIndex(_MI_CHANNEL,BEGIN(ucStartItem),END(ucEndItem));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
    SubMenuTextOut(sChannel[GET_LANGUAGE()],y,ucColor,State);
    CShowNumber(_MSG_COL, y, stTvInfo.CurChn);
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawSystem(BYTE State)
{
	#if(_VIDEO_TV_SUPPORT)
    BYTE y;
    BYTE ucColor;
    BYTE *pStr;
    
    // get display line
    y = GetShowIndex(_MI_SYSTEM,BEGIN(ucStartItem),END(ucEndItem));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
    SubMenuTextOut(sSystem[GET_LANGUAGE()],y,ucColor,State);
    
    switch(ucTVType)
    {
    case _TV_NTSC_M:        pStr = sNTSC_M;         break;
    case _TV_NTSC_4_BG:     pStr = sNTSC_4_BG;      break;
    case _TV_NTSC_4_DK:     pStr = sNTSC_4_DK;      break;
    case _TV_NTSC_4_I:      pStr = sNTSC_4_I;       break;
    case _TV_PAL_M:         pStr = sPAL_M;          break;
        
    case _TV_PAL_BG:        pStr = sPAL_BG;         break;
    case _TV_PAL_I:         pStr = sPAL_I;          break;
    case _TV_PAL_DK:        pStr = sPAL_DK;         break;
    case _TV_PAL_N:         pStr = sPAL_N;          break;
        
    case _TV_SECAM_BG:      pStr = sSECAM_BG;       break;
    case _TV_SECAM_DK:      pStr = sSECAM_DK;       break;
    case _TV_SECAM_L:       pStr = sSECAM_L;        break;
    case _TV_SECAM_LL:      pStr = sSECAM_LL;       break;
        
    }
    
    OSDLine(y, COL(_MSG_COL), LENGTH(12), 0x00, BYTE_DISPLAY);
#if (_NTSC_SEARCH_TABLE)
    pStr = sTVTypeN[_GET_TV_TYPE()];
#endif
    SUBMENU_RIGHT_TEXTOUT(pStr, y);
	#else 
    State = State;
	#endif   
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawAutoSearch(BYTE State)
{
    BYTE y;
    BYTE ucColor;
    
    // get display line
    y = GetShowIndex(_MI_AUTOSEARCH,BEGIN(ucStartItem),END(ucEndItem));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
    SubMenuTextOut(sAutoSearch[GET_LANGUAGE()],y,ucColor,State);
    
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawManualSearch(BYTE State)
{
    BYTE y;
    BYTE ucColor;
    
    // get display line
    y = GetShowIndex(_MI_MANUALSEARCH,BEGIN(ucStartItem),END(ucEndItem));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
    SubMenuTextOut(sManualSearch[GET_LANGUAGE()],y,ucColor,State);
    
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawTuning(BYTE State)
{
#if(_VIDEO_TV_SUPPORT)
    BYTE y;
    BYTE ucColor;
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)  
    BYTE ucColor1;
#endif  
    
    // get display line
    y = GetShowIndex(_MI_TUNING,BEGIN(ucStartItem),END(ucEndItem));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    if(State == _ST_ADJUST)
    {
        ucColor1 = StateColor(_ST_SELECT);
    }
    else
    {
        ucColor1 = ucColor;
    }       
    
    SubMenuTextOut(sTuning[GET_LANGUAGE()],y,ucColor1,State);
#endif
    
#if(_KEY_TYPE == _KT_PCB2660_003)
    SubMenuTextOut(sTuning[GET_LANGUAGE()],y,ucColor,State);
#endif
    
    OSDLine(y, _MSG_COL, LENGTH(10), ucColor, BYTE_COLOR);
    CShowFreq(CLoadChannelFreq(stTvInfo.CurChn), _MSG_COL, y);

#else

    State = State;

#endif

}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawSkip(BYTE State)
{
	#if(_VIDEO_TV_SUPPORT)
    BYTE y;
    BYTE ucColor;
    BYTE *pStr;
    bit fSkip;
    
    // get display line
    y = GetShowIndex(_MI_SKIP,BEGIN(ucStartItem),END(ucEndItem));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
    SubMenuTextOut(sSkip[GET_LANGUAGE()],y,ucColor,State);
    
    fSkip = CLoadChannelSkip(stTvInfo.CurChn);
    
    if(fSkip)
        pStr = sOn[GET_LANGUAGE()];
    else 
        pStr = sOff[GET_LANGUAGE()];
    
    SUBMENU_RIGHT_TEXTOUT(pStr, y);
	#else   
    State = State;
	#endif
}
//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawSwap(BYTE State)
{
#if(_VIDEO_TV_SUPPORT)

    BYTE y;
    BYTE ucColor;
    
    // get display line
    y = GetShowIndex(_MI_SWAP,BEGIN(ucStartItem),END(ucEndItem));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
    SubMenuTextOut(sSwap[GET_LANGUAGE()],y,ucColor,State);
    
    CShowNumber(_MSG_COL, y, stTvInfo.CurChn);

#else
    
    State = State;

#endif
}
//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawAFC(BYTE State)
{
#if(_VIDEO_TV_SUPPORT && _TV_AFC)

    BYTE y;
    BYTE ucColor;
    
    // get display line
    y = GetShowIndex(_MI_AFC,BEGIN(ucStartItem),END(ucEndItem));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
    SubMenuTextOut(sAFC[GET_LANGUAGE()],y,ucColor,State);
                        
    SUBMENU_RIGHT_TEXTOUT(SOnOff[GET_AFC_MODE()][GET_LANGUAGE()], y);

#else
    
    State = State;

#endif
}//---------------------------------------------------------------------------

// ucItem : MainMenu\TV\_MI_CHANNEL,_MI_SYSTEM,_MI_AUTOSEARCH,_MI_MANUALSEARCH,_MI_TUNING,_MI_SKIP,
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawTVPageMenuItem(BYTE ucItem,BYTE ucState)
{
    if(!g_tMenuItem[ucItem].Enable())
    {
        ucState = _ST_DISABLE;  
    }
    
    switch(ucItem)
    {
    case _MI_CHANNEL:               DrawChannel(ucState);               break;
    case _MI_SYSTEM:                DrawSystem(ucState);                break;
    case _MI_AUTOSEARCH:            DrawAutoSearch(ucState);            break;
    case _MI_MANUALSEARCH:          DrawManualSearch(ucState);          break;
    case _MI_TUNING:                DrawTuning(ucState);                break;
    case _MI_SKIP:                  DrawSkip(ucState);                  break;
    case _MI_SWAP:                  DrawSwap(ucState);                  break;
    case _MI_AFC:                   DrawAFC(ucState);                   break;
    }
}

//---------------------------------------------------------------------------
// MainMenu\TV\_MI_CHANNEL,_MI_SYSTEM,_MI_AUTOSEARCH,_MI_MANUALSEARCH,_MI_TUNING,_MI_SKIP,
void DrawTVPage(void)
{
    BYTE i;
    BYTE ucState;
    
    for(i=ucStartItem;i<=ucEndItem;i++)
    {
        if(i == ucOsdState)
        {
            ucState = _ST_SELECT;
        }
        else
        {
            ucState = _ST_NORMAL;
        }
        
        DrawTVPageMenuItem(i,       ucState);
    }
    DrawPageNullLine(ucStartItem,ucEndItem);
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawReset(BYTE State)
{
    BYTE y;
    BYTE ucColor;
    
    // get display line
    y = GetShowIndex(_MI_RESET,BEGIN(_MI_RESET),END(_MI_SHARPNESS));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
    SubMenuTextOut(sReset[GET_LANGUAGE()],y,ucColor,State);
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawDisplayRatio(BYTE State)
{
    BYTE y;
    BYTE ucColor;
    BYTE *pStr;
    
    // get display line
    y = GetShowIndex(_MI_DISPLAYRATIO,BEGIN(_MI_RESET),END(_MI_SHARPNESS));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
    SubMenuTextOut(sDisplayRatio[GET_LANGUAGE()],y,ucColor,State);
    
	if(GET_DISPLAYMODE() == _DISPMODE_FULL)
	{
		pStr = s16_9;
	}
	else if(GET_DISPLAYMODE() == _DISPMODE_43)
	{
		pStr = s4_3;
	}
	else
	{
		pStr = sAuto;
	}
    
    SUBMENU_RIGHT_TEXTOUT(pStr, y);
    
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawAutoPowerDown(BYTE State)
{
    BYTE y;
    BYTE ucColor;
    BYTE *pStr;
    
    // get display line
    y = GetShowIndex(_MI_AUTOPOWERDOWN,BEGIN(_MI_RESET),END(_MI_SHARPNESS));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
    SubMenuTextOut(sAutoPowerDown[GET_LANGUAGE()],y,ucColor,State);
    
    switch(_GET_POWER_DOWN_TIME())
    {
    case 0x00:          pStr = sOff[GET_LANGUAGE()];    break;
    case 0x01:          pStr = s15Min[GET_LANGUAGE()];  break;
    case 0x02:          pStr = s30Min[GET_LANGUAGE()];  break;
    case 0x03:          pStr = s45Min[GET_LANGUAGE()];  break;
    case 0x04:          pStr = s60Min[GET_LANGUAGE()];  break;
    case 0x05:          pStr = s75Min[GET_LANGUAGE()];  break;
    case 0x06:          pStr = s90Min[GET_LANGUAGE()];  break;
    case 0x07:          pStr = s105Min[GET_LANGUAGE()]; break;
    case 0x08:          pStr = s120Min[GET_LANGUAGE()]; break;
    }
    
    SUBMENU_RIGHT_TEXTOUT(pStr, y);
    
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawBlueScreen(BYTE State)
{
    BYTE y;
    BYTE ucColor;
    BYTE *pStr;
    
    // get display line
    y = GetShowIndex(_MI_BLUESCREEN,BEGIN(_MI_RESET),END(_MI_SHARPNESS));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
    SubMenuTextOut(sBlueScreen[GET_LANGUAGE()],y,ucColor,State);
    
    if(_GET_BLUE_BACKGROUND())
    {
        pStr = sOn[GET_LANGUAGE()];
    }
    else
    {
        pStr = sOff[GET_LANGUAGE()];
    }
    
    SUBMENU_RIGHT_TEXTOUT(pStr, y);
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawSharpness(BYTE State)
{
    BYTE y;
    BYTE ucColor;
    
    // get display line
    y = GetShowIndex(_MI_SHARPNESS,BEGIN(_MI_RESET),END(_MI_SHARPNESS));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
    SubMenuTextOut(sSharpness[GET_LANGUAGE()],y,ucColor,State);
       
    CShowNumber(_MSG_COL, y, GET_PEAKING_CORING());
}

//---------------------------------------------------------------------------  
// ucItem : MainMenu\Function\_MI_RESET,_MI_DISPLAYRATIO,_MI_AUTOPOWERDOWN,_MI_BLUESCREEN,_MI_SHARPNESS
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawFuncPageMenuItem(BYTE ucItem,BYTE ucState)
{
    if(!g_tMenuItem[ucItem].Enable())
    {
        ucState = _ST_DISABLE;  
    }
    
    switch(ucItem)
    {
    case _MI_RESET:             DrawReset(ucState);             break;
    case _MI_DISPLAYRATIO:      DrawDisplayRatio(ucState);      break;
    case _MI_AUTOPOWERDOWN:     DrawAutoPowerDown(ucState);     break;
    case _MI_BLUESCREEN:        DrawBlueScreen(ucState);        break;
    case _MI_SHARPNESS:         DrawSharpness(ucState);         break;
    }
}

//---------------------------------------------------------------------------
// MainMenu\Function\_MI_RESET,_MI_DISPLAYRATIO,_MI_AUTOPOWERDOWN,_MI_BLUESCREEN,_MI_SHARPNESS
void DrawFuncPage(void)
{
    BYTE i;
    BYTE ucState;
    
    for(i=_MI_RESET;i<=_MI_SHARPNESS;i++)
    {
        if(i == ucOsdState)
        {
            ucState = _ST_SELECT;
        }
        else
        {
            ucState = _ST_NORMAL;
        }
        
        DrawFuncPageMenuItem(i,     ucState);
    }
    DrawPageNullLine(_MI_RESET,_MI_SHARPNESS);
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawVolume(BYTE State)
{
    BYTE y;
    BYTE ucColor;
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)  
    BYTE ucColor1;
	#endif  
    
    // get display line
    y = GetShowIndex(_MI_VOLUME,BEGIN(_MI_VOLUME),END(_MI_BBE));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)      
    if(State == _ST_ADJUST)
    {
        ucColor1 = StateColor(_ST_SELECT);
    }
    else
    {
        ucColor1 = ucColor;
    }   
    
    SubMenuTextOut(sVolume[GET_LANGUAGE()],y,ucColor1,State);
	#endif
    
	#if(_KEY_TYPE == _KT_PCB2660_003)
    SubMenuTextOut(sVolume[GET_LANGUAGE()],y,ucColor,State);
	#endif
    
    // draw slider
    OSD_SLIDER(y,GET_VOLUME(),ucColor);

}

//---------------------------------------------------------------------------
void VolumeAdjust(BYTE ucMode)
{
    BYTE y;
    
    SET_KEYREPEATENABLE();
    stAudioData.Volume = ValueInRangeChange(0, 100, stAudioData.Volume, _NON_LOOP | ucMode);
    ucOsdEventMsg = _SAVE_EE_AUDIO_DATA_MSG;

    if(GET_VOLUME() != 0)
    {
		CLR_AUDIO_MUTE();
    }                        //20080304
    
    // get display line
    y = GetShowIndex(_MI_VOLUME,BEGIN(_MI_VOLUME),END(_MI_BBE));
    
    if(y == _NOT_SHOW)
        return;
    
    y = SHOWINDEX_TO_LINE(y);
	#if(_KEY_TYPE == _KT_PCB2660_003)
    OSD_SLIDER(y,GET_VOLUME(),_MENU_SECECT_COLOR);
	#endif
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    OSD_SLIDER(y,GET_VOLUME(),_MENU_ADJUST_COLOR);
	#endif

    if (_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV && bTVNoSignal == 1)
        return;

    CSetVolume();
}

//---------------------------------------------------------------------------
void CBalanceAdjust(BYTE ucMode)
{
    BYTE y;
	#if(_KEY_TYPE == _KT_PCB2660_003)
    BYTE ucColor;
	#endif
    
    // get display line
    y = GetShowIndex(_MI_BALANCE,BEGIN(_MI_VOLUME),END(_MI_BBE));
    y = SHOWINDEX_TO_LINE(y);
	#if(_KEY_TYPE == _KT_PCB2660_003)
    // get display color
    ucColor = StateColor(_ST_SELECT);
	#endif
    
    CLR_AUDIO_MUTE();
    SET_KEYREPEATENABLE();
    stAudioData.Balance = ValueInRangeChange(0, 100, stAudioData.Balance, _NON_LOOP | ucMode);
	#if(_KEY_TYPE == _KT_PCB2660_003)
    OSD_SLIDER(y, stAudioData.Balance, ucColor);
	#endif
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    OSD_SLIDER(y, stAudioData.Balance, _MENU_ADJUST_COLOR);
	#endif
    
	#if(_SOUND_PROCESSOR == _ON)
    CSetAudioProcessor(stAudioData.Balance, stAudioData.Bass, stAudioData.Treble);
	#endif
    ucOsdEventMsg = _SAVE_EE_AUDIO_DATA_MSG;
}

//---------------------------------------------------------------------------
void CBassAdjust(BYTE ucMode)
{
    BYTE y;
	#if(_KEY_TYPE == _KT_PCB2660_003)
    BYTE ucColor;
	#endif
    
    // get display line
    y = GetShowIndex(_MI_BASS,BEGIN(_MI_VOLUME),END(_MI_BBE));
    y = SHOWINDEX_TO_LINE(y);
    // get display color
	#if(_KEY_TYPE == _KT_PCB2660_003)
    ucColor = StateColor(_ST_SELECT);
	#endif
    
    CLR_AUDIO_MUTE();
    SET_KEYREPEATENABLE();
    stAudioData.Bass = ValueInRangeChange(0, 100, stAudioData.Bass, _NON_LOOP | ucMode);
	#if(_KEY_TYPE == _KT_PCB2660_003)
    OSD_SLIDER(y, stAudioData.Bass, ucColor);
	#endif
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    OSD_SLIDER(y, stAudioData.Bass, _MENU_ADJUST_COLOR);
	#endif
	#if(_SOUND_PROCESSOR == _ON)
    CSetAudioProcessor(stAudioData.Balance, stAudioData.Bass, stAudioData.Treble);
	#endif
    ucOsdEventMsg = _SAVE_EE_AUDIO_DATA_MSG;
}

//---------------------------------------------------------------------------
void CTrebleAdjust(BYTE ucMode)
{
    BYTE y;
	#if(_KEY_TYPE == _KT_PCB2660_003)
    BYTE ucColor;
	#endif
    
    // get display line
    y = GetShowIndex(_MI_TREBLE,BEGIN(_MI_VOLUME),END(_MI_BBE));
    y = SHOWINDEX_TO_LINE(y);
	#if(_KEY_TYPE == _KT_PCB2660_003)
    // get display color
    ucColor = StateColor(_ST_SELECT);
	#endif
    
    CLR_AUDIO_MUTE();
    SET_KEYREPEATENABLE();
    stAudioData.Treble = ValueInRangeChange(0, 100, stAudioData.Treble, _NON_LOOP | ucMode);
	#if(_KEY_TYPE == _KT_PCB2660_003)
    OSD_SLIDER(y, stAudioData.Treble, ucColor);
	#endif
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    OSD_SLIDER(y, stAudioData.Treble, _MENU_ADJUST_COLOR);
	#endif
    
	#if(_SOUND_PROCESSOR == _ON)
    CSetAudioProcessor(stAudioData.Balance, stAudioData.Bass, stAudioData.Treble);
	#endif
    ucOsdEventMsg = _SAVE_EE_AUDIO_DATA_MSG;
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawBalance(BYTE State)
{
    BYTE y;
    BYTE ucColor;
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)  
    BYTE ucColor1;
	#endif  
    
    // get display line
    y = GetShowIndex(_MI_BALANCE,BEGIN(_MI_VOLUME),END(_MI_BBE));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    if(State == _ST_ADJUST)
    {
        ucColor1 = StateColor(_ST_SELECT);
    }
    else
    {
        ucColor1 = ucColor;
    }   
    
    SubMenuTextOut(sBalance[GET_LANGUAGE()],y,ucColor1,State);
	#endif  
	#if(_KEY_TYPE == _KT_PCB2660_003)
    SubMenuTextOut(sBalance[GET_LANGUAGE()],y,ucColor,State);
	#endif
    // draw slider
    OSD_SLIDER(y, stAudioData.Balance, ucColor);
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawBass(BYTE State)
{
    BYTE y;
    BYTE ucColor;
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)  
    BYTE ucColor1;
	#endif
    
    // get display line
    y = GetShowIndex(_MI_BASS,BEGIN(_MI_VOLUME),END(_MI_BBE));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    if(State == _ST_ADJUST)
    {
        ucColor1 = StateColor(_ST_SELECT);
    }
    else
    {
        ucColor1 = ucColor;
    }
    SubMenuTextOut(sBass[GET_LANGUAGE()],y,ucColor1,State);
	#endif
    
	#if(_KEY_TYPE == _KT_PCB2660_003)
    SubMenuTextOut(sBass[GET_LANGUAGE()],y,ucColor,State);
	#endif
    
    // draw slider
    OSD_SLIDER(y, stAudioData.Bass, ucColor);
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawTreble(BYTE State)
{
    BYTE y;
    BYTE ucColor;
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)  
    BYTE ucColor1;
	#endif
    
    // get display line
    y = GetShowIndex(_MI_TREBLE,BEGIN(_MI_VOLUME),END(_MI_BBE));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    y = SHOWINDEX_TO_LINE(y);
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)  
    if(State == _ST_ADJUST)
    {
        ucColor1 = StateColor(_ST_SELECT);
    }
    else
    {
        ucColor1 = ucColor;
    }
    SubMenuTextOut(sTreble[GET_LANGUAGE()],y,ucColor1,State);
	#endif
    
	#if(_KEY_TYPE == _KT_PCB2660_003)
    SubMenuTextOut(sTreble[GET_LANGUAGE()],y,ucColor,State);
	#endif
    // draw slider
    OSD_SLIDER(y, stAudioData.Treble, ucColor);
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawSRS(BYTE State)
{
    BYTE y;
    BYTE ucColor;
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    BYTE ucColor1;
	#endif
    
    // get display line
    y = GetShowIndex(_MI_SRS,BEGIN(_MI_VOLUME),END(_MI_BBE));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    if(State == _ST_ADJUST)
    {
        ucColor1 = StateColor(_ST_SELECT);
    }
    else
    {
        ucColor1 = ucColor;
    }
    SubMenuTextOut(sSRS[GET_LANGUAGE()],y,ucColor1,State);
	#endif
	#if(_KEY_TYPE == _KT_PCB2660_003)
    SubMenuTextOut(sSRS[GET_LANGUAGE()],y,ucColor,State);
	#endif
    // draw slider
    //  OSD_SLIDER(y, stAudioData.Balance, ucColor);
}

//---------------------------------------------------------------------------
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawBBE(BYTE State)
{
    BYTE y;
    BYTE ucColor;
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    BYTE ucColor1;
	#endif
    
    // get display line
    y = GetShowIndex(_MI_BBE,BEGIN(_MI_VOLUME),END(_MI_BBE));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(State);
    
    y = SHOWINDEX_TO_LINE(y);
    
	#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    if(State == _ST_ADJUST)
    {
        ucColor1 = StateColor(_ST_SELECT);
    }
    else
    {
        ucColor1 = ucColor;
    }   
    SubMenuTextOut(sBBE[GET_LANGUAGE()],y,ucColor1,State);
	#endif
    
	#if(_KEY_TYPE == _KT_PCB2660_003)
    SubMenuTextOut(sBBE[GET_LANGUAGE()],y,ucColor,State);
	#endif
    
    // draw slider
    //  OSD_SLIDER(y, stAudioData.Balance, ucColor);
}

//---------------------------------------------------------------------------
// ucItem : MainMenu\Sound\_MI_VOLUME,_MI_BALANCE,_MI_BASS,_MI_TREBLE,_MI_SRS,_MI_BBE,
//ucState : _ST_NORMAL,_ST_SELECT,_ST_DISABLE 
void DrawSoundPageMenuItem(BYTE ucItem,BYTE ucState)
{
    if(!g_tMenuItem[ucItem].Enable())
    {
        ucState = _ST_DISABLE;  
    }
    
    switch(ucItem)
    {
    case _MI_VOLUME:        DrawVolume(ucState);        break;
    case _MI_BALANCE:       DrawBalance(ucState);       break;
    case _MI_BASS:          DrawBass(ucState);          break;
    case _MI_TREBLE:        DrawTreble(ucState);        break;
    case _MI_SRS:           DrawSRS(ucState);           break;
    case _MI_BBE:           DrawBBE(ucState);           break;
    }
}

//---------------------------------------------------------------------------
// MainMenu\Sound\_MI_VOLUME,_MI_BALANCE,_MI_BASS,_MI_TREBLE,_MI_SRS,_MI_BBE,
void DrawSoundPage(void)
{
    BYTE i;
    BYTE ucState;
    
    for(i=_MI_VOLUME;i<=_MI_BBE;i++)
    {
        if(i == ucOsdState)
        {
            ucState = _ST_SELECT;
        }
        else
        {
            ucState = _ST_NORMAL;
        }
        
        DrawSoundPageMenuItem(i,        ucState);
    }
    DrawPageNullLine(_MI_VOLUME,_MI_BBE);
}

//---------------------------------------------------------------------------
// ucPageIndex : MainMenu\_MI_COLOR,_MI_ADJUST,_MI_OSD,_MI_TV,_MI_FUNCTION,_MI_SOUND,
void DrawSubMenu(BYTE ucPageIndex)
{
    switch(ucPageIndex)
    {
    case _MI_COLOR:             DrawColorPage();        break;
    case _MI_ADJUST:            DrawAdjustPage();       break;
    case _MI_OSD:               DrawOSDPage();          break;
    case _MI_TV:                DrawTVPage();           break;
    case _MI_FUNCTION:          DrawFuncPage();         break;
    case _MI_SOUND:             DrawSoundPage();        break;
    }
    
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void MMenuNoneProc(void)
{
    if (!CTVEnable() && ucOsdEventMsg >= _OE_SC_CH_DEC) // Only for TV
    {
        return;
    }
    
    switch(ucOsdEventMsg)
    {
        // Enter main menu
    case _OE_ENTER_SUBMENU:     MMenuNoneEnterSubMenu();        break;
        
        // Enter Source menu
    case _OE_CHANGE_SOURCE:
        if(_SLEEP_STATE == ucCurrState)
        {
        	CModeSetFreeRun();
            CPowerLVDSOn();
            CModeResetMode();
            CPowerPanelOn();
            CPowerLightPowerOn();
        }
        else
        {
            if (bLIGHTPOWER == _LIGHT_OFF)
               CPowerLightPowerOn();
        }

#if(_CHANGE_SOURCE_METHOD == _CHANGE_SOURCE_METHOD_0)
        DrawSourceMenu();               
#elif(_CHANGE_SOURCE_METHOD == _CHANGE_SOURCE_METHOD_1)
        ucOsdEventMsg = _CHANGE_SOURCE_MSG;
        bChangeSource();
#endif
        break;

#if(_FAC_OSD) 
    case _OE_FAC_OPEN:          DrawFactoryMenu();              break;
#endif
        // Enter short cut menu
    case _OE_SC_BRIGHTNESS:     EnterSCBright();                break;
    case _OE_SC_VOLUME:         
#if(_CHINESE_FONT_TYPE == _CHINESE_2_FONT)
        LoadCHIFont(_LF_SOUND_PAGE);
#endif
        EnterSCVolume();                
        break;
        
    case _OE_SC_MUTE:           CSetMuteState();                break;
    case _OE_DISPLAY:           CDisplayCurrentSourceMessage(); break;
        
#if(_VIDEO_TV_SUPPORT)

    case _OE_SC_CH_INC: 
    case _OE_SC_CH_DEC:
        if (!CMITVEnable())
            return;
        CChangeChannel((ucOsdEventMsg == _OE_SC_CH_DEC) ? 0 : 1);
        COsdDispOsdTimerEvent();
        bDrawMute = 0;
        break;
        
    case _OE_SC_INPUT_NUM0:
    case _OE_SC_INPUT_NUM1:
    case _OE_SC_INPUT_NUM2:
    case _OE_SC_INPUT_NUM3:
    case _OE_SC_INPUT_NUM4:
    case _OE_SC_INPUT_NUM5:
    case _OE_SC_INPUT_NUM6:
    case _OE_SC_INPUT_NUM7:
    case _OE_SC_INPUT_NUM8:
    case _OE_SC_INPUT_NUM9:
        COsdDispOsdTimerEvent();
        EnterSCInputNum();              
        MScInputChNumProc();
        break;
    case _OE_SC_INPUT_CH:       EnterSCInputNum();              break;
    case _OE_SC_RETURN:
        COsdDispOsdTimerEvent();
        pData[0]        = stTvInfo.CurChn;
        stTvInfo.CurChn = ucPrevChannel;
        ucPrevChannel   = pData[0];
        
        CMuteOn();
        CModeResetTVMode();
        CSetTVChannel(stTvInfo.CurChn);
        ucOsdEventMsg = _SAVE_EE_TV_DATA_MSG;
        break;
#endif
    }
}    
//---------------------------------------------------------------------------
void MMenuNoneEnterSubMenu(void)
{
    // Draw osd
    ucOsdState = _MI_COLOR;
    
    DrawMainMenu();
    CShowMode(13,17);
    
    bDrawMute = 0;
    COsdFxEnableOsd();
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
// MainMenu\Color,Adjust,OSD,TV,Function,Sound,
// MainMenu\_MI_COLOR,_MI_ADJUST,_MI_OSD,_MI_TV,_MI_FUNCTION,_MI_SOUND,
void MMainMenuProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MMainMenuValueAdj(_INC);            break;
    case _OE_ADJ_DEC:           MMainMenuValueAdj(_DEC);            break;
    case _OE_MENU_NEXT:         MMainMenuMenuAdj(_NEXT);            break;
    case _OE_MENU_PREV:         MMainMenuMenuAdj(_PREV);            break;
    case _OE_ENTER_SUBMENU:     MMainMenuEnterSubMenu();            break;
    case _OE_RETURN_UPMENU:     MMainMenuReturnUpMenu();            break;
        
    }
}
//---------------------------------------------------------------------------
void MMainMenuValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    ucMode = ucMode;        // test code
}
//---------------------------------------------------------------------------
void MainMenuItemChgClear(void)
{
    BYTE i;
    
    // Clear Title
    OSDClear(ROW(1), HEIGHT(2), COL(0), WIDTH(39), 0x00, BYTE_DISPLAY);
    
    // clear sub menu
    for(i=0;i<6;i++)
    {
        OSDLine(SHOWINDEX_TO_LINE(i), COL(7), LENGTH(38), 0x00, BYTE_DISPLAY);
        OSDLine(SHOWINDEX_TO_LINE(i), COL(7), LENGTH(38), 0x8C, BYTE_ATTRIB);
    }
    
}
//---------------------------------------------------------------------------
void MMainMenuMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev
    
    BYTE ucNewItem = AdjustMenuItem(_MI_COLOR,_MI_SOUND,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    DrawMainMenuItem(ucOsdState,    _ST_NORMAL);
    MainMenuItemChgClear();
    
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 3. Draw New Item
    
#if(_CHINESE_FONT_TYPE == _CHINESE_2_FONT)    
    LoadCHIFont(ucOsdState - _MI_COLOR);
    if(ucOsdState == _MI_OSD)
        COsdLoad1BitFont(FntLangaugeName,0x60,0x18,tFntLangaugeNameCharWidth);
#endif    
    DrawMainMenuItem(ucOsdState,    _ST_SELECT);
    DrawMainItemTitle(ucOsdState);

    switch(ucOsdState)
    {
    case _MI_COLOR:             
    case _MI_ADJUST:
    case _MI_OSD:
    case _MI_FUNCTION:
    case _MI_SOUND:
        ucStartItem = 0;
        ucEndItem   = 0;
        break;

    case _MI_TV:
        ucStartItem = _MI_CHANNEL;
        ucEndItem   = _MI_SKIP;
        break;

    }

    DrawSubMenu(ucOsdState);
    
    
}
//---------------------------------------------------------------------------
void MMainMenuEnterSubMenu(void)
{
    // 1. Before Enter SubMenu
    // Insert code to here ...
    
    
    // 2. Change ucOsdState
    switch(ucOsdState)
    {
    case _MI_COLOR:                 
        ucOsdState = _MI_BRIGHTNESS;        
        DrawColorPageMenuItem(ucOsdState,_ST_SELECT);
        break;
    case _MI_ADJUST:            
        ucOsdState = _MI_AUTOADJUST; 
        DrawAdjustPageMenuItem(ucOsdState,_ST_SELECT);
        break;
    case _MI_OSD:               
        ucOsdState = _MI_LANGUAGE;          
        DrawOsdPageMenuItem(ucOsdState,_ST_SELECT);
        break;
    case _MI_TV:                
        ucOsdState  = ucStartItem;//_MI_CHANNEL;           
        DrawTVPageMenuItem(ucOsdState,_ST_SELECT);
        break;
    case _MI_FUNCTION:          
        ucOsdState = _MI_RESET;             
        DrawFuncPageMenuItem(ucOsdState,_ST_SELECT);
        break;
    case _MI_SOUND:             
        ucOsdState = _MI_VOLUME;            
        DrawSoundPageMenuItem(ucOsdState,_ST_SELECT);
        break;
    }
    
    // 3. Now enter sub menu
    // Insert code to here ...
    
    
}
//---------------------------------------------------------------------------
void MMainMenuReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    // Insert code to here ...
    
    // 2. Change ucOsdState
    COsdDispOsdTimerEvent();
    // 3. Now Return to upmenu
    // Insert code to here ...
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// MainMenu\Color\Brightness,Contrast,Hue,Saturation,ColorTemp,
// MainMenu\Color\_MI_BRIGHTNESS,_MI_CONTRAST,_MI_HUE,_MI_SATURATION,_MI_COLORTEMP,
void MColorProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MColorValueAdj(_INC);               break;
    case _OE_ADJ_DEC:           MColorValueAdj(_DEC);               break;
    case _OE_MENU_NEXT:         MColorMenuAdj(_NEXT);               break;
    case _OE_MENU_PREV:         MColorMenuAdj(_PREV);               break;
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    case _OE_ENTER_SUBMENU:     MColorEnterSubMenu();               break;
#endif
    case _OE_RETURN_UPMENU:     MColorReturnUpMenu();               break;
    }
}
//---------------------------------------------------------------------------
void MColorValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    switch(ucOsdState)
    {
    case _MI_BRIGHTNESS:          
        BrightAdjust(ucMode);
        break;

    case _MI_CONTRAST:            
        ContrastAdjust(ucMode);
        break;

    case _MI_HUE:                 
        HueAdjust(ucMode);
        break;

    case _MI_SATURATION:      
        SaturationAdjust(ucMode);
        break;

    case _MI_COLORTEMP:           
        EnterColorTempMenu();               
        break;
    }
}
//---------------------------------------------------------------------------
void MColorMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev
    BYTE ucNewItem = AdjustMenuItem(_MI_BRIGHTNESS,_MI_COLORTEMP,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    // Insert code to here
    DrawColorPageMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 3. Draw New Item
    DrawColorPageMenuItem(ucOsdState,_ST_SELECT);
    
}

//---------------------------------------------------------------------------
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
void MColorEnterSubMenu(void)
{
    // 1. Before Enter SubMenu
    // Insert code to here ...
    
    
    // 2. Change ucOsdState
    switch(ucOsdState)
    {
    case _MI_BRIGHTNESS: 
        DrawBright(_ST_ADJUST);
        ucOsdState = _MI_BRIGHTADJ;
        break;

    case _MI_CONTRAST:
        DrawContrast(_ST_ADJUST);
        ucOsdState = _MI_CONTRASTADJ;
        break;

    case _MI_HUE:
        DrawHue(_ST_ADJUST);
        ucOsdState = _MI_HUEADJ;
        break;

    case _MI_SATURATION:    
        DrawSaturation(_ST_ADJUST);
        ucOsdState = _MI_SATURATIONADJ;
        break;

    case _MI_COLORTEMP:
        DrawColorTemp(_ST_ADJUST);
        EnterColorTempMenu();       
        break;
    }
}
#endif

//---------------------------------------------------------------------------
void MColorReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawColorPageMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_COLOR;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}
//---------------------------------------------------------------------------


#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
//---------------------------------------------------------------------------
// MainMenu\Color\Brightness\BrigntAdj
// MainMenu\Color\Brightness\_MI_BRIGHTADJ
void MBrightnessProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           
        MBrightnessValueAdj(_INC);          
        break;
        
    case _OE_ADJ_DEC:           
        MBrightnessValueAdj(_DEC);          
        break;
        
    case _OE_MENU_NEXT:         
        MBrightnessReturnUpMenu();
        MColorMenuAdj(_NEXT);               
        break;
        
    case _OE_MENU_PREV:         
        MBrightnessReturnUpMenu();
        MColorMenuAdj(_PREV);               
        break;
        
    case _OE_ENTER_SUBMENU:     
        MColorEnterSubMenu();               
        break;
        
    case _OE_RETURN_UPMENU:     
        MBrightnessReturnUpMenu();          
        break;
        
    }
}
//---------------------------------------------------------------------------
void MBrightnessValueAdj(BYTE ucMode)
{
    BrightAdjust(ucMode);
}
//---------------------------------------------------------------------------
void MBrightnessReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawBright(_ST_SELECT);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_BRIGHTNESS;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
} 
//---------------------------------------------------------------------------
// MainMenu\Color\Contrast\ContrastAdj
// MainMenu\Color\Contrast\_MI_CONTRASTADJ
void MContrastProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           
        MContrastValueAdj(_INC);            
        break;
        
    case _OE_ADJ_DEC:           
        MContrastValueAdj(_DEC);            
        break;
        
    case _OE_MENU_NEXT:         
        MContrastReturnUpMenu();
        MColorMenuAdj(_NEXT);               
        break;
        
    case _OE_MENU_PREV:         
        MContrastReturnUpMenu();
        MColorMenuAdj(_PREV);               
        break;
        
    case _OE_ENTER_SUBMENU:     
        MColorEnterSubMenu();               
        break;
        
    case _OE_RETURN_UPMENU:     
        MContrastReturnUpMenu();            
        break;
    }
}
//---------------------------------------------------------------------------
void MContrastValueAdj(BYTE ucMode)
{
    ContrastAdjust(ucMode);
}
//---------------------------------------------------------------------------
void MContrastReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawContrast(_ST_SELECT);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_CONTRAST;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}
//---------------------------------------------------------------------------
// MainMenu\Color\Hue\HueAdj
// MainMenu\Color\Hue\_MI_HUEADJ
void MHueProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           
        MHueValueAdj(_INC);               
        break;
        
    case _OE_ADJ_DEC:           
        MHueValueAdj(_DEC);               
        break;
        
    case _OE_MENU_NEXT:         
        MHueReturnUpMenu();
        MColorMenuAdj(_NEXT);             
        break;
        
    case _OE_MENU_PREV:         
        MHueReturnUpMenu();
        MColorMenuAdj(_PREV);             
        break;
        
    case _OE_ENTER_SUBMENU:     
        MColorEnterSubMenu();             
        break;
        
    case _OE_RETURN_UPMENU:     
        MHueReturnUpMenu();               
        break;
        
    }
}
//---------------------------------------------------------------------------
void MHueValueAdj(BYTE ucMode)
{
    HueAdjust(ucMode);
}
//---------------------------------------------------------------------------
void MHueReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawHue(_ST_SELECT);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_HUE;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}
//---------------------------------------------------------------------------
// MainMenu\Color\Saturation\SaturationAdj 
// MainMenu\Color\Saturation\_MI_SATURATIONADJ
void MSaturationProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           
        MSaturationValueAdj(_INC);            
        break;
        
    case _OE_ADJ_DEC:           
        MSaturationValueAdj(_DEC);            
        break;
        
    case _OE_MENU_NEXT:         
        MSaturationReturnUpMenu();
        MColorMenuAdj(_NEXT);                 
        break;
        
    case _OE_MENU_PREV:         
        MSaturationReturnUpMenu();
        MColorMenuAdj(_PREV);                
        break;
        
    case _OE_ENTER_SUBMENU:     
        MColorEnterSubMenu();                 
        break;
        
    case _OE_RETURN_UPMENU:     
        MSaturationReturnUpMenu();            
        break;
        
    }
}
//---------------------------------------------------------------------------
void MSaturationValueAdj(BYTE ucMode)
{
    SaturationAdjust(ucMode);
}
//---------------------------------------------------------------------------
void MSaturationReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawSaturation(_ST_SELECT);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_SATURATION;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}
#endif

//---------------------------------------------------------------------------
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
void DrawAPopupMenuItem1(BYTE *str,BYTE ItemIndex,BYTE ucRowStart,BYTE ucColStart,BYTE State)
{
    BYTE c;
    //BYTE x;
    BYTE ucColor = StateColor(State);
    
    ItemIndex = ItemIndex + ucRowStart + 1;
    
    if(State == _ST_DISABLE || State == _ST_NORMAL)
        c = 0x01;   // Clear Select Icon
    else
        c = 0x57;   // Select Icon
    
    if(ItemIndex % 2)
        ucColStart += 21;
    else
        ucColStart += 27;
    
    OSDLine(ROW(ItemIndex), COL(ucColStart), LENGTH(19), ucColor, BYTE_COLOR);
    
    Gotoxy(COL(ucColStart + 1),ROW(ItemIndex),BYTE_DISPLAY);
    OutputChar(c);
    
    CTextOutEx(str, COL(ucColStart + 3), ROW(ItemIndex));
    
}
#endif

//---------------------------------------------------------------------------
#define _PM_COLORTMP_ROW_START                      11
#define _PM_COLORTMP_ROW_HEIGHT                     5
#define _PM_COLORTMP_COL_START                      3

void DrawColorTempMenuItem(BYTE ucItem,BYTE ucState)
{
    BYTE y;
    BYTE *pStr;
    
    if(!g_tMenuItem[ucItem].Enable())
    {
        ucState = _ST_DISABLE;  
    }
    
    // get display line
    y = GetShowIndex(ucItem,BEGIN(_MI_9300),END(_MI_USER));
    
    if(y == _NOT_SHOW)
        return;
    
    
    switch(ucItem)
    {
    case _MI_9300:          pStr = s9300[GET_LANGUAGE()];   break;
    case _MI_6500:          pStr = s6500[GET_LANGUAGE()];   break;
    case _MI_USER:          pStr = sUser[GET_LANGUAGE()];   break;
    }
    
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    DrawAPopupMenuItem1(pStr,y,_PM_COLORTMP_ROW_START,_PM_COLORTMP_COL_START,ucState);
#elif(_KEY_TYPE == _KT_PCB2660_003)
    DrawAPopupMenuItem(pStr,y,_PM_COLORTMP_ROW_START,_PM_COLORTMP_COL_START,ucState);
#endif    
}

//---------------------------------------------------------------------------
void EnterColorTempMenu(void)
{
    BYTE i;
    BYTE ucMode;
    
    CreatePopupMenu(_PM_COLORTMP_ROW_START, _PM_COLORTMP_ROW_HEIGHT);
    
    switch(GET_COLOR_TEMP_TYPE())
    {
    case _CT_9300:      ucOsdState = _MI_9300;      break;
    case _CT_6500:      ucOsdState = _MI_6500;      break;
    case _CT_USER:      
    default:            ucOsdState = _MI_USER;      break;
    }
    
    for(i=_MI_9300;i<=_MI_USER;i++)
    {
        if(i == ucOsdState)
            ucMode = _ST_SELECT;
        else
            ucMode = _ST_NORMAL;
        
        DrawColorTempMenuItem(i,ucMode);
    }
    
}
//---------------------------------------------------------------------------
void ClearColorTempMenu(void)
{
    ClearPopupMenu(_PM_COLORTMP_ROW_START, _PM_COLORTMP_ROW_HEIGHT);
}
//---------------------------------------------------------------------------


// MainMenu\Color\ColorTemp\9300,6500,User,
// MainMenu\Color\ColorTemp\_MI_9300,_MI_6500,_MI_USER,
void MColorTempProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           
        break;
        
    case _OE_ADJ_DEC:           
        break;
        
    case _OE_MENU_NEXT:         
        MColorTempMenuAdj(_NEXT);           
        break;
        
    case _OE_MENU_PREV:         
        MColorTempMenuAdj(_PREV);           
        break;
        
    case _OE_ENTER_SUBMENU:     
        MColorTempEnterSubMenu();           
        break;
        
    case _OE_RETURN_UPMENU:     
        MColorTempReturnUpMenu();           
        break;
    }
} 

//---------------------------------------------------------------------------
void MColorTempMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev
    
    BYTE ucNewItem = AdjustMenuItem(_MI_9300,_MI_USER,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    DrawColorTempMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    switch(ucOsdState)
    {
    case _MI_9300:     SET_COLOR_TEMP_TYPE(_CT_9300);   break;
    case _MI_6500:     SET_COLOR_TEMP_TYPE(_CT_6500);   break;
    case _MI_USER:     SET_COLOR_TEMP_TYPE(_CT_USER);   break;
    }
    
    CEepromLoadColorTempData();
    CAdjustContrast();
    ucOsdEventMsg = _SAVE_EE_SYSTEMDATA_MSG;
    
    // 3. Draw New Item
#if(_KEY_TYPE == _KT_PCB2660_003)
    DrawColorTempMenuItem(ucOsdState,_ST_SELECT);
#endif
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    DrawColorTempMenuItem(ucOsdState,_ST_ADJUST);
#endif
}
//---------------------------------------------------------------------------
void MColorTempEnterSubMenu(void)
{
    if (GET_COLOR_TEMP_TYPE() == _CT_USER)
        EnterColorTempUserMenu();
    else
        MColorTempReturnUpMenu();
}
//---------------------------------------------------------------------------
void MColorTempReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    ClearColorTempMenu();
    
    // 2. Change ucOsdState
    ucOsdState = _MI_COLORTEMP;
    
    // 3. Now Return to upmenu
    DrawColorPage();
}

//---------------------------------------------------------------------------
#define _PM_COLORUSER_ROW_START                     11
#define _PM_COLORUSER_ROW_HEIGHT                    5
#define _PM_COLORUSER_COL_START                     3

void DrawColorUSERMenuItem(BYTE ucItem,BYTE ucState)
{        
    BYTE color;
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    BYTE ucRow, ucCol;
    BYTE ucValue;
#endif
    // get display color
    color = StateColor(ucState);
    
    switch(ucItem)
    {
    case _MI_USER_R:   
#if(_KEY_TYPE == _KT_PCB2660_003)
        if (_ST_SELECT == ucState)
               color = 0xF0;
        OSDSlider(12, 30, 8, stColorTempData.ColorTemp[_RED], 255,color);     
#endif
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
        ucValue = stColorTempData.ColorTemp[_RED];
        ucRow = 12;
        ucCol = 30;
        if (_ST_ADJUST== ucState)
        {
            color = 0xF0;               
        }
#endif
        break;
        
    case _MI_USER_G:
#if(_KEY_TYPE == _KT_PCB2660_003)           
        if (_ST_SELECT == ucState)
               color = 0xD0;
        OSDSlider(13, 24, 8, stColorTempData.ColorTemp[_GREEN], 255,color);   
#endif
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
        ucValue = stColorTempData.ColorTemp[_GREEN];
        ucRow = 13;
        ucCol = 24;
        if (_ST_ADJUST== ucState)
        {
            color = 0xD0;
            
        }
#endif
        break;
        
    case _MI_USER_B:
#if(_KEY_TYPE == _KT_PCB2660_003)           
        if (_ST_SELECT == ucState)
               color = 0xE0;
        OSDSlider(14, 30, 8, stColorTempData.ColorTemp[_BLUE], 255,color);
#endif   
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
        ucRow = 14;
        ucCol = 30;
        ucValue = stColorTempData.ColorTemp[_BLUE];
        if (_ST_ADJUST== ucState)
        {
            color = 0xE0;
        }
#endif
        break;
    }
    
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    OSDSlider(ucRow, ucCol, 8, ucValue, 255,color);
#endif
    
}

//---------------------------------------------------------------------------
void EnterColorTempUserMenu(void)
{
    BYTE i;
    BYTE ucMode;
    
    CreatePopupMenu(_PM_COLORUSER_ROW_START, _PM_COLORUSER_ROW_HEIGHT);
    
    ucOsdState = _MI_USER_R;
    
    OSDLine(12, COL(29), LENGTH(1), 0xF0, BYTE_COLOR);
    Gotoxy(29, 12, BYTE_DISPLAY);
    OutputChar(0x26); // "R"
    OSDLine(13, COL(23), LENGTH(2), 0xD0, BYTE_COLOR);
    Gotoxy(23, 13, BYTE_DISPLAY);
    OutputChar(0x17); // "G"
    OutputChar(0x18); // "G"
    OSDLine(14, COL(29), LENGTH(1), 0xE0, BYTE_COLOR);
    Gotoxy(29, 14, BYTE_DISPLAY);
    OutputChar(0x12); // "B"
    
    for(i=_MI_USER_R;i<=_MI_USER_B;i++)
    {
        if(i == ucOsdState)
            ucMode = _ST_SELECT;
        else
            ucMode = _ST_NORMAL;
        
        DrawColorUSERMenuItem(i,ucMode);
    }
    
}
//---------------------------------------------------------------------------
void ClearColorUSERMenu(void)
{
    ClearPopupMenu(_PM_COLORUSER_ROW_START, _PM_COLORUSER_ROW_HEIGHT);
}
//---------------------------------------------------------------------------
// MainMenu\Color\ColorTemp\9300,6500,User,
// MainMenu\Color\ColorTemp\_MI_USER_R,_MI_USER_G,_MI_USER_B,
void MColorUserProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MColorUserValueAdj(_INC);           break;
    case _OE_ADJ_DEC:           MColorUserValueAdj(_DEC);           break;
    case _OE_MENU_NEXT:         MColorUserMenuAdj(_NEXT);           break;
    case _OE_MENU_PREV:         MColorUserMenuAdj(_PREV);           break;
    case _OE_ENTER_SUBMENU:  
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)        
        MColorUserEnterSubMenu();   
        break;
#endif
    case _OE_RETURN_UPMENU:     MColorUserReturnUpMenu();           break;
        
    }
}
//---------------------------------------------------------------------------
void MColorUserValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    switch(ucOsdState)
    {
    case _MI_USER_R:     
        ColorRAdjust(ucMode);   
        break;
    case _MI_USER_G:     
        ColorGAdjust(ucMode);   
        break;
    case _MI_USER_B:     
        ColorBAdjust(ucMode);  
        break;
    }
    DrawColorUSERMenuItem(ucOsdState,_ST_SELECT);
    
    CAdjustContrast();
    ucOsdEventMsg = _SAVE_EE_COLORPROC1_MSG;
}
//---------------------------------------------------------------------------
void MColorUserMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev
    
    BYTE ucNewItem = AdjustMenuItem(_MI_USER_R,_MI_USER_B,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    DrawColorUSERMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 1. Clear Current Menu
    DrawColorUSERMenuItem(ucOsdState,_ST_SELECT);
}
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
void MColorUserEnterSubMenu(void)
{
    // 1. Before Enter SubMenu
    // Insert code to here ...
    
    
    // 2. Change ucOsdState
    switch(ucOsdState)
    {
    case _MI_USER_R:       
        DrawColorUSERMenuItem(ucOsdState,_ST_ADJUST);
        ucOsdState = _MI_USER_RADJ;
        break;
    case _MI_USER_G:
        DrawColorUSERMenuItem(ucOsdState,_ST_ADJUST);
        ucOsdState = _MI_USER_GADJ;
        break;
    case _MI_USER_B:
        DrawColorUSERMenuItem(ucOsdState,_ST_ADJUST);
        ucOsdState = _MI_USER_BADJ;
        break;
        
    }
    
    // 3. Now enter sub menu
    // Insert code to here ...
}
#endif

//---------------------------------------------------------------------------
void MColorUserReturnUpMenu(void)
{
    ClearColorUSERMenu();
    EnterColorTempMenu();
}

#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
//---------------------------------------------------------------------------
//
//
void MRProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           
        MRValueAdj(_INC);               
        break;
        
    case _OE_ADJ_DEC:           
        MRValueAdj(_DEC);               
        break;
        
    case _OE_MENU_NEXT:   
        MRReturnUpMenu();
        MColorUserMenuAdj(_NEXT);
        break;
        
    case _OE_MENU_PREV: 
        MRReturnUpMenu();
        MColorUserMenuAdj(_PREV);
        break;
        
    case _OE_ENTER_SUBMENU: 
        
        break;
        
    case _OE_RETURN_UPMENU:     
        MRReturnUpMenu();               
        break;
        
    }
}
//---------------------------------------------------------------------------
void MRValueAdj(BYTE ucMode)
{
    ColorRAdjust(ucMode);
    CAdjustContrast();
    ucOsdEventMsg = _SAVE_EE_COLORPROC1_MSG;    
}
//---------------------------------------------------------------------------
void MRReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawColorUSERMenuItem(_MI_USER_R, _ST_SELECT);  
    
    // 2. Change ucOsdState
    ucOsdState = _MI_USER_R;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
    
}
//---------------------------------------------------------------------------
//
//
void MGProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           
        MGValueAdj(_INC);               
        break;
        
    case _OE_ADJ_DEC:           
        MGValueAdj(_DEC);               
        break;
        
    case _OE_MENU_NEXT:   
        MGReturnUpMenu();
        MColorUserMenuAdj(_NEXT);
        break;
        
    case _OE_MENU_PREV: 
        MGReturnUpMenu();
        MColorUserMenuAdj(_PREV);
        break;
        
    case _OE_ENTER_SUBMENU:    
        break;
        
    case _OE_RETURN_UPMENU:     
        MGReturnUpMenu();               
        break;
        
    }
}
//---------------------------------------------------------------------------
void MGValueAdj(BYTE ucMode)
{
    ColorGAdjust(ucMode);
    CAdjustContrast();
    ucOsdEventMsg = _SAVE_EE_COLORPROC1_MSG;    
}
//---------------------------------------------------------------------------
void MGReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawColorUSERMenuItem(_MI_USER_G, _ST_SELECT);  
    
    // 2. Change ucOsdState
    ucOsdState = _MI_USER_G;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
    
}
//---------------------------------------------------------------------------
//
//
void MBProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           
        MBValueAdj(_INC);               
        break;
        
    case _OE_ADJ_DEC:           
        MBValueAdj(_DEC);               
        break;
        
    case _OE_MENU_NEXT:
        MBReturnUpMenu();
        MColorUserMenuAdj(_NEXT);
        break;
        
    case _OE_MENU_PREV:
        MBReturnUpMenu();
        MColorUserMenuAdj(_PREV);
        break;
        
    case _OE_ENTER_SUBMENU:
        break;
        
    case _OE_RETURN_UPMENU:     
        MBReturnUpMenu();               
        break;
        
    }
}
//---------------------------------------------------------------------------
void MBValueAdj(BYTE ucMode)
{
    ColorBAdjust(ucMode);
    CAdjustContrast();
    ucOsdEventMsg = _SAVE_EE_COLORPROC1_MSG;
}
//---------------------------------------------------------------------------
void MBReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawColorUSERMenuItem(_MI_USER_B, _ST_SELECT);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_USER_B;
    
    // 3. Now Return to upmenu
    // Insert code to here ...   
}
#endif



//---------------------------------------------------------------------------
void ColorRAdjust(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    SET_KEYREPEATENABLE();
    stColorTempData.ColorTemp[_RED] = ValueInRangeChange(0, 255, stColorTempData.ColorTemp[_RED], _NON_LOOP | ucMode);
    
#if(_KEY_TYPE == _KT_PCB2660_003)
    DrawColorUSERMenuItem(_MI_USER_R, _ST_SELECT);
#endif
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    DrawColorUSERMenuItem(_MI_USER_R, _ST_ADJUST);
#endif
}
//---------------------------------------------------------------------------
void ColorGAdjust(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    SET_KEYREPEATENABLE();
    stColorTempData.ColorTemp[_GREEN] = ValueInRangeChange(0, 255, stColorTempData.ColorTemp[_GREEN], _NON_LOOP | ucMode);
    
#if(_KEY_TYPE == _KT_PCB2660_003)
    DrawColorUSERMenuItem(_MI_USER_G, _ST_SELECT);
#endif
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    DrawColorUSERMenuItem(_MI_USER_G, _ST_ADJUST);
#endif
}
//---------------------------------------------------------------------------
void ColorBAdjust(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    SET_KEYREPEATENABLE();
    stColorTempData.ColorTemp[_BLUE] = ValueInRangeChange(0, 255, stColorTempData.ColorTemp[_BLUE], _NON_LOOP | ucMode);
    
    
#if(_KEY_TYPE == _KT_PCB2660_003)
    DrawColorUSERMenuItem(_MI_USER_B, _ST_SELECT);
#endif
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    DrawColorUSERMenuItem(_MI_USER_B, _ST_ADJUST);
#endif
}

//---------------------------------------------------------------------------
// MainMenu\Adjust\AutoAdjust,HPosition,VPosition,Phase,Clock,
// MainMenu\Adjust\_MI_AUTOADJUST,_MI_HPOSITION,_MI_VPOSITION,_MI_PHASE,_MI_CLOCK,
void MAdjustProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MAdjustValueAdj(_INC);              break;
    case _OE_ADJ_DEC:           MAdjustValueAdj(_DEC);              break;
    case _OE_MENU_NEXT:         MAdjustMenuAdj(_NEXT);              break;
    case _OE_MENU_PREV:         MAdjustMenuAdj(_PREV);              break;
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    case _OE_ENTER_SUBMENU:     MAdjustEnterSubMenu();              break;
#endif
    case _OE_RETURN_UPMENU:     MAdjustReturnUpMenu();              break;
        
    }
}
//---------------------------------------------------------------------------
void MAdjustValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    switch(ucOsdState)
    {
    case _MI_AUTOADJUST:        EnterAutoConfigMenu();          break;
    case _MI_HPOSITION:         HPositionAdjust(ucMode);        break;
    case _MI_VPOSITION:         VPositionAdjust(ucMode);        break;
    case _MI_PHASE:             PhaseAdjust(ucMode);            break;
    case _MI_CLOCK:             ClockAdjust(ucMode);            break;
    }
}
//---------------------------------------------------------------------------
void MAdjustMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev
    
    BYTE ucNewItem = AdjustMenuItem(_MI_AUTOADJUST,_MI_CLOCK,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    DrawAdjustPageMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 3. Draw New Item
    DrawAdjustPageMenuItem(ucOsdState,_ST_SELECT);
    
}

//---------------------------------------------------------------------------
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
void MAdjustEnterSubMenu(void)
{
    // 1. Before Enter SubMenu
    // Insert code to here ...
    
    
    // 2. Change ucOsdState
    switch(ucOsdState)
    {
    case _MI_AUTOADJUST: 
        DrawAutoAdjust(_ST_ADJUST);
        EnterAutoConfigMenu();
        break;
                                
    case _MI_HPOSITION:
        DrawHPosition(_ST_ADJUST);
        ucOsdState = _MI_ADJUST_HPOSITIONADJ;
        break;
                                
    case _MI_VPOSITION:
        DrawVPosition(_ST_ADJUST);
        ucOsdState = _MI_ADJUST_VPOSITIONADJ;
        break;
        
    case _MI_PHASE: 
        DrawPhase(_ST_ADJUST);
        ucOsdState = _MI_ADJUST_PHASEADJ;
        break;
        
    case _MI_CLOCK:                                                                                                 
        DrawClock(_ST_ADJUST);
        ucOsdState = _MI_ADJUST_CLOCKADJ;
        break;
    }
}
#endif
//---------------------------------------------------------------------------
void MAdjustReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawAdjustPageMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_ADJUST;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}
//---------------------------------------------------------------------------

#define _PM_AUTOCONFIG_ROW_START                    4
#define _PM_AUTOCONFIG_ROW_HEIGHT                   4
#define _PM_AUTOCONFIG_COL_START                    3

void DrawAutoConfigMenuItem(BYTE ucItem,BYTE ucState)
{
    BYTE y;
    BYTE *pStr;
    
    if(!g_tMenuItem[ucItem].Enable())
    {
        ucState = _ST_DISABLE;  
    }
    
    // get display line
    y = GetShowIndex(ucItem,BEGIN(_MI_AUTOADJUST_OK),END(_MI_AUTOADJUST_CANCEL));
    
    if(y == _NOT_SHOW)
        return;
    
    
    switch(ucItem)
    {
    case _MI_AUTOADJUST_OK:         pStr = sOK[GET_LANGUAGE()];     break;
    case _MI_AUTOADJUST_CANCEL:     pStr = sCancel[GET_LANGUAGE()]; break;
    }
    
    DrawAPopupMenuItem(pStr,y,_PM_AUTOCONFIG_ROW_START,_PM_AUTOCONFIG_COL_START,ucState);
    
}

//---------------------------------------------------------------------------
void EnterAutoConfigMenu(void)
{
    CreatePopupMenu(_PM_AUTOCONFIG_ROW_START, _PM_AUTOCONFIG_ROW_HEIGHT);
    
    ucOsdState = _MI_AUTOADJUST_CANCEL;
    
    DrawAutoConfigMenuItem(_MI_AUTOADJUST_OK,_ST_NORMAL);
    DrawAutoConfigMenuItem(_MI_AUTOADJUST_CANCEL,_ST_SELECT);   
}
//---------------------------------------------------------------------------
void ClearAutoConfigMenu(void)
{
    ClearPopupMenu(_PM_AUTOCONFIG_ROW_START, _PM_AUTOCONFIG_ROW_HEIGHT);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// MainMenu\Adjust\AutoAdjust\AutoAdjust_OK,AutoAdjust_Cancel,
// MainMenu\Adjust\AutoAdjust\_MI_AUTOADJUST_OK,_MI_AUTOADJUST_CANCEL,
void MAutoAdjustProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MAutoAdjustValueAdj(_INC);          break;
    case _OE_ADJ_DEC:           MAutoAdjustValueAdj(_DEC);          break;
    case _OE_MENU_NEXT:         MAutoAdjustMenuAdj(_NEXT);          break;
    case _OE_MENU_PREV:         MAutoAdjustMenuAdj(_PREV);          break;
    case _OE_ENTER_SUBMENU:     MAutoAdjustEnterSubMenu();          break;
    case _OE_RETURN_UPMENU:     MAutoAdjustReturnUpMenu();          break;
        
    }
}
//---------------------------------------------------------------------------
void MAutoAdjustValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    ucMode = ucMode;        // test code
}
//---------------------------------------------------------------------------
void MAutoAdjustMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev
    
    BYTE ucNewItem = AdjustMenuItem(_MI_AUTOADJUST_OK,_MI_AUTOADJUST_CANCEL,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    DrawAutoConfigMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 3. Draw New Item
    DrawAutoConfigMenuItem(ucOsdState,_ST_SELECT);
    
}
//---------------------------------------------------------------------------
void MAutoAdjustEnterSubMenu(void)
{
    bit fDoAuto = 0;
    
    if(ucOsdState == _MI_AUTOADJUST_OK)
        fDoAuto = 1;
    
    MAutoAdjustReturnUpMenu();
    
    if(fDoAuto)
    {
        CAutoDoAutoConfig();
        CAutoDoWhiteBalance();
        DrawHPosition(_ST_NORMAL);
        DrawVPosition(_ST_NORMAL);
        DrawPhase(_ST_NORMAL);
        DrawClock(_ST_NORMAL);
        
    }
}
//---------------------------------------------------------------------------
void MAutoAdjustReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    ClearAutoConfigMenu();
    
    // 2. Change ucOsdState
    ucOsdState = _MI_AUTOADJUST;
    
    // 3. Now Return to upmenu
    DrawAdjustPage();
}

#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
//---------------------------------------------------------------------------
// MainMenu\Adjust\HPosition\HPositionAdj
// MainMenu\Adjust\HPosition\_MI_ADJUST_HPOSITIONADJ
void MAdjustHPositionProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MAdjustHPositionValueAdj(_INC);               break;
    case _OE_ADJ_DEC:           MAdjustHPositionValueAdj(_DEC);               break;
    case _OE_MENU_NEXT:         MColorMenuAdj(_NEXT);                         break;
    case _OE_MENU_PREV:         MColorMenuAdj(_PREV);                         break;
    case _OE_ENTER_SUBMENU:     MColorEnterSubMenu();                         break;
    case _OE_RETURN_UPMENU:     MAdjustHPositionReturnUpMenu();               break;
        
    }
}
//---------------------------------------------------------------------------
void MAdjustHPositionValueAdj(BYTE ucMode)
{
    HPositionAdjust(ucMode);
}
//---------------------------------------------------------------------------
void MAdjustHPositionReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawHPosition(_ST_SELECT);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_HPOSITION;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}
//---------------------------------------------------------------------------
// MainMenu\Adjust\VPosition\VPositionAdj
// MainMenu\Adjust\VPosition\_MI_ADJUST_VPOSITIONADJ
void MAdjustVPositionProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:          
        MAdjustVPositionValueAdj(_INC);               
        break;
        
    case _OE_ADJ_DEC:          
        MAdjustVPositionValueAdj(_DEC);               
        break;
        
    case _OE_MENU_NEXT:         
        MAdjustVPositionReturnUpMenu();
        MAdjustMenuAdj(_NEXT);
        break;
        
    case _OE_MENU_PREV:         
        MAdjustVPositionReturnUpMenu();
        MAdjustMenuAdj(_PREV);
        break;
        
    case _OE_ENTER_SUBMENU:     
        
        break;
        
    case _OE_RETURN_UPMENU:     
        MAdjustVPositionReturnUpMenu();               
        break;
    }
}
//---------------------------------------------------------------------------
void MAdjustVPositionValueAdj(BYTE ucMode)
{
    VPositionAdjust(ucMode);
}
//---------------------------------------------------------------------------
void MAdjustVPositionReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawVPosition(_ST_SELECT);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_VPOSITION;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}
//---------------------------------------------------------------------------
// MainMenu\Adjust\Phase\PhaseAdj
// MainMenu\Adjust\Phase\_MI_PHASEADJ
void MAdjustPhaseProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:          
        MAdjustPhaseValueAdj(_INC);               
        break;
        
    case _OE_ADJ_DEC:          
        MAdjustPhaseValueAdj(_DEC);
        break;
        
    case _OE_MENU_NEXT:       
        MAdjustPhaseReturnUpMenu();
        MAdjustMenuAdj(_NEXT);
        break;
        
    case _OE_MENU_PREV:        
        MAdjustPhaseReturnUpMenu();
        MAdjustMenuAdj(_PREV);
        break;
        
    case _OE_ENTER_SUBMENU:     
        
        break;
        
    case _OE_RETURN_UPMENU:     
        MAdjustPhaseReturnUpMenu();               
        break;
        
    }
}
//---------------------------------------------------------------------------
void MAdjustPhaseValueAdj(BYTE ucMode)
{
    PhaseAdjust(ucMode);
}
//---------------------------------------------------------------------------
void MAdjustPhaseReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawPhase(_ST_SELECT);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_PHASE;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}
//---------------------------------------------------------------------------
// MainMenu\Adjust\Clock\ClockAdj
// MainMenu\Adjust\Clock\_MI_CLOCKADJ
void MAdjustClockProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:          
        MAdjustClockValueAdj(_INC);               
        break;
        
    case _OE_ADJ_DEC:          
        MAdjustClockValueAdj(_DEC);               
        break;
        
    case _OE_MENU_NEXT:         
        MAdjustClockReturnUpMenu();
        MAdjustMenuAdj(_NEXT);
        break;
                                
    case _OE_MENU_PREV:         
        MAdjustClockReturnUpMenu();       
        MAdjustMenuAdj(_PREV);
        break;
                                
    case _OE_ENTER_SUBMENU:     
        
        break;
        
    case _OE_RETURN_UPMENU:     
        MAdjustClockReturnUpMenu();               
        break;
    }
}
//---------------------------------------------------------------------------
void MAdjustClockValueAdj(BYTE ucMode)
{
    ClockAdjust(ucMode);
}
//---------------------------------------------------------------------------
void MAdjustClockReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawClock(_ST_SELECT);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_CLOCK;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}
//---------------------------------------------------------------------------
#endif


//---------------------------------------------------------------------------
// MainMenu\OSD\Language,HPosition,VPosition,Timer,Double,Transparent,
// MainMenu\OSD\_MI_LANGUAGE,_MI_OSD_HPOSITION,_MI_OSD_VPOSITION,_MI_TIMER,_MI_DOUBLE,_MI_TRANSPARENT,
void MOSDProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MOSDValueAdj(_INC);                 break;
    case _OE_ADJ_DEC:           MOSDValueAdj(_DEC);                 break;
    case _OE_MENU_NEXT:         MOSDMenuAdj(_NEXT);                 break;
    case _OE_MENU_PREV:         MOSDMenuAdj(_PREV);                 break;
    case _OE_ENTER_SUBMENU:     MOSDEnterSubMenu();                 break;
    case _OE_RETURN_UPMENU:     MOSDReturnUpMenu();                 break;
        
    }
}
//---------------------------------------------------------------------------
void MOSDValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    // 1. Before Enter SubMenu
    // Insert code to here ...
    ucMode = ucMode;
    
    // 2. Change ucOsdState
    switch(ucOsdState)
    {
    case _MI_LANGUAGE:          EnterLanguageMenu();                break;
    case _MI_OSD_HPOSITION:     COSDHPositionAdj(ucMode);           break;
    case _MI_OSD_VPOSITION:     COSDVPositionAdj(ucMode);           break;
    case _MI_TIMER:             MTimerAdjValue(ucMode);             break;
    case _MI_DOUBLE:            EnterDoubleMenu();                  break;
    case _MI_TRANSPARENT:       CTransparentAdj(ucMode);            break;
    }
    
    // 3. Now enter sub menu
    // Insert code to here ...
    
}
//---------------------------------------------------------------------------
void MOSDMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev
    
    BYTE ucNewItem = AdjustMenuItem(_MI_LANGUAGE,_MI_TRANSPARENT,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    DrawOsdPageMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 3. Draw New Item
    DrawOsdPageMenuItem(ucOsdState,_ST_SELECT);
    
}
//---------------------------------------------------------------------------
void MOSDEnterSubMenu(void)
{
    // 1. Before Enter SubMenu
    // Insert code to here ...
    
    
    // 2. Change ucOsdState
    switch(ucOsdState)
    {
    case _MI_LANGUAGE:
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
        DrawLanguage(_ST_ADJUST);
#endif
        EnterLanguageMenu();
        break;

#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    case _MI_OSD_HPOSITION:
        DrawOSDHPosition(_ST_ADJUST);
        ucOsdState = _MI_OSD_HPOSITIONADJ;
        break;

    case _MI_OSD_VPOSITION:
        DrawOSDVPosition(_ST_ADJUST);
        ucOsdState = _MI_OSD_VPOSITIONADJ;
        break;
        
    case _MI_TIMER:
        DrawOSDTimer(_ST_ADJUST);
        ucOsdState = _MI_TIMERADJ;
        break;
#endif

    case _MI_DOUBLE:
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
        DrawDouble(_ST_ADJUST);
        EnterDoubleMenu();
#endif
#if(_KEY_TYPE == _KT_PCB2660_003)
        ucOsdState = _MI_DOUBLE_ON;
#endif
        break;

#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    case _MI_TRANSPARENT:
        DrawTransparent(_ST_ADJUST);
        ucOsdState = _MI_TRANSPARENTADJ;
        break;
#endif
    }
    
    // 3. Now enter sub menu
    // Insert code to here ...
    
    
}
//---------------------------------------------------------------------------
void MOSDReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawOsdPageMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_OSD;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}
//---------------------------------------------------------------------------

#define _PM_LANGUAGE_ROW_START                      4
//#define _PM_LANGUAGE_ROW_HEIGHT                       5
#define _PM_LANGUAGE_COL_START                      1

void DrawLangaugeMenuItem(BYTE ucItem,BYTE ucState)
{
    BYTE y;
    
    if(!g_tMenuItem[ucItem].Enable())
    {
        ucState = _ST_DISABLE;  
    }
    
    // get display line
    y = GetShowIndex(ucItem,BEGIN(_MI_ENGLISH),END(_MI_RUS));
    
    if(y == _NOT_SHOW)
        return;
    
    DrawAPopupMenuItem(sLanguageName[ucItem - _MI_ENGLISH],y,_PM_LANGUAGE_ROW_START,_PM_LANGUAGE_COL_START,ucState);
    
}

//---------------------------------------------------------------------------
void EnterLanguageMenu(void)
{
    BYTE i;
    BYTE ucMode;
    BYTE ucCount;
    
    ucCount = GetShowCount(BEGIN(_MI_ENGLISH),END(_MI_RUS));
    
    CreatePopupMenu(_PM_LANGUAGE_ROW_START, ucCount + 2);
    
    ucOsdState = GET_LANGUAGE() + _MI_ENGLISH;
    
    for(i=_MI_ENGLISH;i<=_MI_RUS;i++)
    {
        if(i == ucOsdState)
            ucMode = _ST_SELECT;
        else
            ucMode = _ST_NORMAL;
        
        DrawLangaugeMenuItem(i,ucMode);
    }
    
}
//---------------------------------------------------------------------------
void ClearLangaugeMenu(void)
{
    BYTE ucCount;
    
    ucCount = GetShowCount(BEGIN(_MI_ENGLISH),END(_MI_RUS));
    
    ClearPopupMenu(_PM_LANGUAGE_ROW_START, ucCount + 2);
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
// MainMenu\OSD\Language\English,CHI_S,FRA,ITA,DEU,ESP,CHI_T,JAP,KOR,RUS,
// MainMenu\OSD\Language\_MI_ENGLISH,_MI_CHI_S,_MI_FRA,_MI_ITA,_MI_DEU,_MI_ESP,_MI_CHI_T,_MI_JAP,_MI_KOR,_MI_RUS,
void MLanguageProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MLanguageValueAdj(_INC);            break;
    case _OE_ADJ_DEC:           MLanguageValueAdj(_DEC);            break;
    case _OE_MENU_NEXT:         MLanguageMenuAdj(_NEXT);            break;
    case _OE_MENU_PREV:         MLanguageMenuAdj(_PREV);            break;
    case _OE_ENTER_SUBMENU:     MLanguageEnterSubMenu();            break;
    case _OE_RETURN_UPMENU:     MLanguageReturnUpMenu();            break;
        
    }
}
//---------------------------------------------------------------------------
void MLanguageValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    ucMode = ucMode;        // test code
}
//---------------------------------------------------------------------------
void MLanguageMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev
    
    BYTE ucNewItem = AdjustMenuItem(_MI_ENGLISH,_MI_RUS,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    DrawLangaugeMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 3. Draw New Item
    DrawLangaugeMenuItem(ucOsdState,_ST_SELECT);
}
//---------------------------------------------------------------------------
void MLanguageEnterSubMenu(void)
{
    SET_LANGUAGE(ucOsdState - _MI_ENGLISH);
    MainMenuItemChgClear();
    
#if(_CHINESE_FONT_TYPE == _CHINESE_2_FONT)
    LoadCHIFont(_LF_OSD_PAGE);
#endif
    LoadLanguageFont();
    DrawMainItemTitle(_MI_OSD);
    MLanguageReturnUpMenu();
    
    ucOsdEventMsg = _SAVE_EE_OSDUSERDATA_MSG;            
}
//---------------------------------------------------------------------------
void MLanguageReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    ClearLangaugeMenu();
    
    // 2. Change ucOsdState
    ucOsdState = _MI_LANGUAGE;
    
    // 3. Now Return to upmenu
    DrawOSDPage();
}
//---------------------------------------------------------------------------
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
void MTimerProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:      MTimerAdjValue(_INC);     break;
    case _OE_ADJ_DEC:      MTimerAdjValue(_DEC);     break;
    case _OE_MENU_NEXT:    
        MTimerReturnUpMenu();     
        MOSDMenuAdj(_NEXT);
        break;
                                
    case _OE_MENU_PREV:
        MTimerReturnUpMenu();
        MOSDMenuAdj(_PREV);
        break;
                                
    case _OE_ENTER_SUBMENU:
        break;
        
    case _OE_RETURN_UPMENU: MTimerReturnUpMenu();    break;
                                
    }
}

//---------------------------------------------------------------------------
void MTimerReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    //  DrawBright(_ST_SELECT);
    DrawOSDTimer(_ST_SELECT);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_TIMER;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}
#endif

//---------------------------------------------------------------------------
void MTimerAdjValue(BYTE ucMode)
{
    BYTE y;
    BYTE idata ucTemp = GET_OSDTIMEOUT()/5;
    
    // get display line
    y = GetShowIndex(_MI_TIMER,BEGIN(_MI_LANGUAGE),END(_MI_TRANSPARENT));
    
    if(y == _NOT_SHOW)
        return;
    
    y = SHOWINDEX_TO_LINE(y);
    
    OSDClear(ROW(y), HEIGHT(1), COL(_MSG_COL), WIDTH(3), 0x8C, BYTE_ATTRIB);
    OSDClear(ROW(y), HEIGHT(1), COL(_MSG_COL), WIDTH(3), 0x00, BYTE_DISPLAY);
    
    ucTemp = ValueInRangeChange(0, 12, ucTemp, _LOOP | ucMode);
    SET_OSDTIMEOUT(ucTemp * 5);
    
    // draw
    OSDLine(ROW(y), _MSG_COL, LENGTH(10), StateColor(_ST_ADJUST), BYTE_COLOR);
    
    if (ucTemp == 0)
        SUBMENU_RIGHT_TEXTOUT(sOff[GET_LANGUAGE()], y);
    else
        CShowNumber(_MSG_COL, y, GET_OSDTIMEOUT());
    
    ucOsdEventMsg = _SAVE_EE_OSDUSERDATA_MSG;
}

#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
//---------------------------------------------------------------------------
// MainMenu\OSD\HPosition\HPositionAdj
// MainMenu\OSD\HPosition\_MI_OSD_HPOSITIONADJ
void MHPositionProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:
        MHPositionValueAdj(_INC);               
        break;
        
    case _OE_ADJ_DEC:
        MHPositionValueAdj(_DEC);
        break;
        
    case _OE_MENU_NEXT:
        MHPositionReturnUpMenu(); 
        MOSDMenuAdj(_NEXT);
        break;
        
    case _OE_MENU_PREV:         
        MHPositionReturnUpMenu(); 
        MOSDMenuAdj(_PREV);
        break;
        
    case _OE_ENTER_SUBMENU:     
        
        break;
        
    case _OE_RETURN_UPMENU:     
        MHPositionReturnUpMenu();               
        break;
        
    }
}
//---------------------------------------------------------------------------
void MHPositionValueAdj(BYTE ucMode)
{
    COSDHPositionAdj(ucMode);
}
//---------------------------------------------------------------------------
void MHPositionReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawOSDHPosition(_ST_SELECT);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_OSD_HPOSITION;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}
//---------------------------------------------------------------------------
// MainMenu\OSD\VPosition\VPositionAdj
// MainMenu\OSD\VPosition\_MI_OSD_VPOSITIONADJ
void MVPositionProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           
        MVPositionValueAdj(_INC);               
        break;
        
    case _OE_ADJ_DEC:           
        MVPositionValueAdj(_DEC);               
        break;
        
    case _OE_MENU_NEXT:
        MVPositionReturnUpMenu();
        MOSDMenuAdj(_NEXT);
        break;
        
    case _OE_MENU_PREV:
        MVPositionReturnUpMenu();
        MOSDMenuAdj(_PREV);
        break;
        
    case _OE_ENTER_SUBMENU:
        
        break;
        
    case _OE_RETURN_UPMENU:     
        MVPositionReturnUpMenu();               
        break;
        
    }
}
//---------------------------------------------------------------------------
void MVPositionValueAdj(BYTE ucMode)
{
    COSDVPositionAdj(ucMode);
}
//---------------------------------------------------------------------------
void MVPositionReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawOSDVPosition(_ST_SELECT);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_OSD_VPOSITION;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}

//---------------------------------------------------------------------------
#endif


#define _PM_DOUBLE_ROW_START                        11
#define _PM_DOUBLE_ROW_HEIGHT                       4
#define _PM_DOUBLE_COL_START                        3

void DrawDoubleMenuItem(BYTE ucItem,BYTE ucState)
{
    BYTE y;
    BYTE *pStr;
    
    if(!g_tMenuItem[ucItem].Enable())
    {
        ucState = _ST_DISABLE;  
    }
    
    // get display line
    y = GetShowIndex(ucItem,BEGIN(_MI_DOUBLE_ON),END(_MI_DOUBLE_OFF));
    
    if(y == _NOT_SHOW)
        return;
    
    
    switch(ucItem)
    {
    case _MI_DOUBLE_ON:         pStr = sOn[GET_LANGUAGE()];     break;
    case _MI_DOUBLE_OFF:        pStr = sOff[GET_LANGUAGE()];    break;
    }
    
    DrawAPopupMenuItem(pStr,y,_PM_DOUBLE_ROW_START,_PM_DOUBLE_COL_START,ucState);
    
}

//---------------------------------------------------------------------------
void EnterDoubleMenu(void)
{
    BYTE i;
    BYTE ucMode;
    
    CreatePopupMenu(_PM_DOUBLE_ROW_START, _PM_DOUBLE_ROW_HEIGHT);
    
    if(GET_OSD_SIZE())
        ucOsdState = _MI_DOUBLE_ON;
    else 
        ucOsdState = _MI_DOUBLE_OFF;
    
    for(i=_MI_DOUBLE_ON;i<=_MI_DOUBLE_OFF;i++)
    {
        if(i == ucOsdState)
            ucMode = _ST_SELECT;
        else
            ucMode = _ST_NORMAL;
        
        DrawDoubleMenuItem(i,ucMode);
    }
    
}
//---------------------------------------------------------------------------
void ClearDoubleMenu(void)
{
    ClearPopupMenu(_PM_DOUBLE_ROW_START, _PM_DOUBLE_ROW_HEIGHT);
}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------
// MainMenu\OSD\Double\Double_On,Double_Off,
// MainMenu\OSD\Double\_MI_DOUBLE_ON,_MI_DOUBLE_OFF,
void MDoubleProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MDoubleValueAdj(_INC);              break;
    case _OE_ADJ_DEC:           MDoubleValueAdj(_DEC);              break;
    case _OE_MENU_NEXT:         MDoubleMenuAdj(_NEXT);              break;
    case _OE_MENU_PREV:         MDoubleMenuAdj(_PREV);              break;
    case _OE_ENTER_SUBMENU:     MDoubleEnterSubMenu();              break;
    case _OE_RETURN_UPMENU:     MDoubleReturnUpMenu();              break;
        
    }
}
//---------------------------------------------------------------------------
void MDoubleValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    ucMode = ucMode;        // test code
}
//---------------------------------------------------------------------------
void MDoubleMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev
    
    BYTE ucNewItem = AdjustMenuItem(_MI_DOUBLE_ON,_MI_DOUBLE_OFF,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    DrawDoubleMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 3. Draw New Item
    DrawDoubleMenuItem(ucOsdState,_ST_SELECT);
    
}
//---------------------------------------------------------------------------
void MDoubleEnterSubMenu(void)
{
    BYTE ucOldSize = GET_OSD_SIZE();
    
    switch(ucOsdState)
    {
    case _MI_DOUBLE_ON:      SET_OSD_SIZE(1);           break;
    case _MI_DOUBLE_OFF:     SET_OSD_SIZE(0);           break;
    }
    
    MDoubleReturnUpMenu();   
    
    if (ucOldSize == GET_OSD_SIZE())
        return;
    
    COsdFxDisableOsd();
    if (GET_OSD_SIZE())
    {
        SetOSDDouble(0x03 | OSD_WINDOWCHAR_BLENDING);
    }
    else
    {
        SetOSDDouble(OSD_WINDOWCHAR_BLENDING);
    }
    CSetOSDPosition(_MAINMENU_WIDTH, _MAINMENU_HEIGHT, stOsdUserData.OsdHPos, stOsdUserData.OsdVPos);

    COsdFxEnableOsd();
    ucOsdEventMsg = _SAVE_EE_SYSTEMDATA_MSG;
}
//---------------------------------------------------------------------------
void MDoubleReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    ClearDoubleMenu();
    
    // 2. Change ucOsdState
    ucOsdState = _MI_DOUBLE;
    
    // 3. Now Return to upmenu
    DrawOSDPage();
}
//---------------------------------------------------------------------------
void COSDHPositionAdj(BYTE ucMode)
{
    BYTE y;
#if(_KEY_TYPE == _KT_PCB2660_003)
    BYTE ucColor;
#endif
    
    // get display line
    y = GetShowIndex(_MI_OSD_HPOSITION,BEGIN(_MI_LANGUAGE),END(_MI_TRANSPARENT));   
    y = SHOWINDEX_TO_LINE(y);
    // get display color
#if(_KEY_TYPE == _KT_PCB2660_003)
    ucColor = StateColor(_ST_SELECT);
#endif
    
    SET_KEYREPEATENABLE();
    stOsdUserData.OsdHPos = ValueInRangeChange(0, 100, stOsdUserData.OsdHPos, _NON_LOOP | ucMode);
#if(_KEY_TYPE == _KT_PCB2660_003)
    OSD_SLIDER(y,stOsdUserData.OsdHPos,ucColor);
#endif
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    OSD_SLIDER(y,stOsdUserData.OsdHPos,_MENU_ADJUST_COLOR);
#endif
    CSetOSDPosition(_MAINMENU_WIDTH, _MAINMENU_HEIGHT, stOsdUserData.OsdHPos, stOsdUserData.OsdVPos);
    
    ucOsdEventMsg = _SAVE_EE_OSDUSERDATA_MSG;            
}
//---------------------------------------------------------------------------
void COSDVPositionAdj(BYTE ucMode)
{
    BYTE y;
#if(_KEY_TYPE == _KT_PCB2660_003)
    BYTE ucColor;
#endif
    
    // get display line
    y = GetShowIndex(_MI_OSD_VPOSITION,BEGIN(_MI_LANGUAGE),END(_MI_TRANSPARENT));   
    y = SHOWINDEX_TO_LINE(y);
    // get display color
#if(_KEY_TYPE == _KT_PCB2660_003)
    ucColor = StateColor(_ST_SELECT);
#endif
    
    SET_KEYREPEATENABLE();
    stOsdUserData.OsdVPos = ValueInRangeChange(0, 100, stOsdUserData.OsdVPos, _NON_LOOP | ucMode);
#if(_KEY_TYPE == _KT_PCB2660_003)
    OSD_SLIDER(y,stOsdUserData.OsdVPos,ucColor);
#endif
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    OSD_SLIDER(y,stOsdUserData.OsdVPos,_MENU_ADJUST_COLOR);
#endif
    
    CSetOSDPosition(_MAINMENU_WIDTH, _MAINMENU_HEIGHT, stOsdUserData.OsdHPos, stOsdUserData.OsdVPos);
    
    ucOsdEventMsg = _SAVE_EE_OSDUSERDATA_MSG;            
}

//---------------------------------------------------------------------------
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
void MTransparentProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:
        CTransparentAdj(_INC);
        break;
        
    case _OE_ADJ_DEC:
        CTransparentAdj(_DEC); 
        break;
        
    case _OE_MENU_NEXT:
        MTransparentReturnUpMenu();
        MOSDMenuAdj(_NEXT);               
        break;
        
    case _OE_MENU_PREV:
        MTransparentReturnUpMenu();
        MOSDMenuAdj(_PREV);               
        break;
        
    case _OE_ENTER_SUBMENU:     
        //                              MColorEnterSubMenu();               
        break;
        
    case _OE_RETURN_UPMENU: 
        MTransparentReturnUpMenu();               
        break;
    }
}

//---------------------------------------------------------------------------
void MTransparentReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawTransparent(_ST_SELECT);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_TRANSPARENT;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}
#endif
//---------------------------------------------------------------------------
void CTransparentAdj(BYTE ucMode)
{
    BYTE y;
    
    // get display line
    y = GetShowIndex(_MI_TRANSPARENT,BEGIN(_MI_LANGUAGE),END(_MI_TRANSPARENT));
    y = SHOWINDEX_TO_LINE(y);
    
    stOsdUserData.OsdBlending = ValueInRangeChange(0, 7, stOsdUserData.OsdBlending, _LOOP | ucMode);
    OSDClear(ROW(y), HEIGHT(1), COL(_MSG_COL), WIDTH(3), 0x8C, BYTE_ATTRIB);
    OSDClear(ROW(y), HEIGHT(1), COL(_MSG_COL), WIDTH(3), 0x00, BYTE_DISPLAY);
    OSDLine(ROW(y), _MSG_COL, LENGTH(10), StateColor(_ST_ADJUST), BYTE_COLOR);
    if (0 == GET_OSDBLENDING())
        SUBMENU_RIGHT_TEXTOUT(sOff[GET_LANGUAGE()], y);
    else
        CShowNumber(_MSG_COL, y, GET_OSDBLENDING());
    CScalerSetBit(_OVERLAY_CTRL_6C, 0x23, ((stOsdUserData.OsdBlending & 0x07) << 2));
    
    ucOsdEventMsg = _SAVE_EE_OSDUSERDATA_MSG;                        
}
//---------------------------------------------------------------------------
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
void MTuningProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC: 
        CTuningAdj(_INC);      
        break;
        
    case _OE_ADJ_DEC:           
        CTuningAdj(_DEC);          
        break;
        
    case _OE_MENU_NEXT:       
        MTuningReturnUpMenu();
        MTVMenuAdj(_NEXT);
        break;
        
    case _OE_MENU_PREV:
        MTuningReturnUpMenu();
        MTVMenuAdj(_PREV);
        break;
        
    case _OE_ENTER_SUBMENU:
        break;
        
    case _OE_RETURN_UPMENU:  
        MTuningReturnUpMenu();        
        break;
    }
}

//---------------------------------------------------------------------------
void MTuningReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawTuning(_ST_SELECT);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_TUNING;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}
#endif
//---------------------------------------------------------------------------
void CTuningAdj(BYTE ucMode)
{
#if(_VIDEO_TV_SUPPORT)
    BYTE y;
    
    // get display line
    y = GetShowIndex(_MI_TUNING,BEGIN(ucStartItem),END(ucEndItem));
    y = SHOWINDEX_TO_LINE(y);
    
    SET_KEYREPEATENABLE();                                              
    CTuningCurrentChannel((bit)ucMode, stTvInfo.CurChn);
    CShowFreq(CLoadChannelFreq(stTvInfo.CurChn), _MSG_COL, y);
#else
    ucMode = ucMode;
#endif
}

//---------------------------------------------------------------------------
void CAdjChannel(BYTE ucMode)
{
#if(_VIDEO_TV_SUPPORT)
    BYTE y;
    
    // get display line
    y = GetShowIndex(_MI_CHANNEL,BEGIN(ucStartItem),END(ucEndItem));
    
    if(y == _NOT_SHOW)
        return;
    
    y = SHOWINDEX_TO_LINE(y);
    
    CMuteOn();
    
    OSDClear(ROW(y), HEIGHT(1), COL(_MSG_COL), WIDTH(3), 0x8C, BYTE_ATTRIB);
    OSDClear(ROW(y), HEIGHT(1), COL(_MSG_COL), WIDTH(3), 0x00, BYTE_DISPLAY);
    
#if(_FM_DEVICE)
    if (1 == bFM)
    {
        stTvInfo.ucFMCurrCh = ValueInRangeChange(0, CloadMaxChannelNumber(), stTvInfo.ucFMCurrCh, _LOOP | ucMode);
        CSetTVChannel(stTvInfo.ucFMCurrCh);
        CShowNumber(_MSG_COL, y, stTvInfo.CurChn);
        ucPrevChannel =  stTvInfo.ucFMCurrCh;
        CSetVolume();
    }
    else
#endif
    {
        CModeResetTVMode();
        stTvInfo.CurChn = ValueInRangeChange(0, CloadMaxChannelNumber(), stTvInfo.CurChn, _LOOP | ucMode);
        CSetTVChannel(stTvInfo.CurChn);
        CShowNumber(_MSG_COL, y, stTvInfo.CurChn);
        ucPrevChannel =  stTvInfo.CurChn;
    }
    
	DrawSystem(_ST_NORMAL);
    DrawTuning(_ST_NORMAL);
    DrawSkip(_ST_NORMAL);
    
    bChangeChannel = 0;
    ucOsdEventMsg  = _SAVE_EE_TV_DATA_MSG;
    CLR_CLEAR_OSD_EN();

#else

    ucMode = ucMode;

#endif    
}

//---------------------------------------------------------------------------
void CAdjustSwap(BYTE ucMode)
{
#if(_VIDEO_TV_SUPPORT)
    BYTE y;
    
    // get display line
    y = GetShowIndex(_MI_SWAP,BEGIN(ucStartItem),END(ucEndItem));
    
    if(y == _NOT_SHOW)
        return;
    
    y = SHOWINDEX_TO_LINE(y);
    
    CMuteOn();
    
    OSDClear(ROW(y), HEIGHT(1), COL(_MSG_COL), WIDTH(3), 0x8C, BYTE_ATTRIB);
    OSDClear(ROW(y), HEIGHT(1), COL(_MSG_COL), WIDTH(3), 0x00, BYTE_DISPLAY);
    
    CModeResetTVMode();
    stTvInfo.CurChn = ValueInRangeChange(0, CloadMaxChannelNumber(), stTvInfo.CurChn, _LOOP | ucMode);
    CSetTVChannel(stTvInfo.CurChn);
    CShowNumber(_MSG_COL, y, stTvInfo.CurChn);
    //ucPrevChannel =  stTvInfo.CurChn;
    
	DrawSystem(_ST_NORMAL);
    DrawTuning(_ST_NORMAL);
    DrawSkip(_ST_NORMAL);
    
    bChangeChannel = 0;
    ucOsdEventMsg  = _SAVE_EE_TV_DATA_MSG;
    CLR_CLEAR_OSD_EN();

#else

    ucMode = ucMode;

#endif    
}

//---------------------------------------------------------------------------
// MainMenu\TV\Channel,System,AutoSearch,ManualSearch,Tuning,Skip,
// MainMenu\TV\_MI_CHANNEL,_MI_SYSTEM,_MI_AUTOSEARCH,_MI_MANUALSEARCH,_MI_TUNING,_MI_SKIP,
void MTVProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MTVValueAdj(_INC);                  break;
    case _OE_ADJ_DEC:           MTVValueAdj(_DEC);                  break;
    case _OE_MENU_NEXT:         MTVMenuAdj(_NEXT);                  break;
    case _OE_MENU_PREV:         MTVMenuAdj(_PREV);                  break;
    case _OE_ENTER_SUBMENU:     MTVEnterSubMenu();                  break;
    case _OE_RETURN_UPMENU:     MTVReturnUpMenu();                  break;
        
    }
}
//---------------------------------------------------------------------------
#if(_VIDEO_TV_SUPPORT)
#if(_NTSC_SEARCH_TABLE)
void CSystemAdj(BYTE ucMode)
{
    BYTE y;
    
	ucMode = ucMode;

    // get display line
    y = GetShowIndex(_MI_SYSTEM,BEGIN(_MI_CHANNEL),END(_MI_SKIP));
    
    if(y == _NOT_SHOW)
        return;
    
    y = SHOWINDEX_TO_LINE(y);
    
    if(_GET_TV_TYPE())
	   _SET_TV_TYPE(0);
	else
	   _SET_TV_TYPE(1);

	ucMode = CloadMaxChannelNumber();
    if (stTvInfo.CurChn > ucMode || ucPrevChannel > ucMode)
    {
	    stTvInfo.CurChn = ucMode;
	    ucPrevChannel =  stTvInfo.ucFMCurrCh;
		DrawTuning(_ST_NORMAL);
		DrawSkip(_ST_NORMAL);
    }
    OSDClear(ROW(y), HEIGHT(1), COL(_MSG_COL), WIDTH(4), 0x8C, BYTE_ATTRIB);
    OSDClear(ROW(y), HEIGHT(1), COL(_MSG_COL), WIDTH(4), 0x00, BYTE_DISPLAY);
    SUBMENU_RIGHT_TEXTOUT(sTVTypeN[_GET_TV_TYPE()], y);
    CEepromSaveTvData();
}
#endif
#endif  // #if(_VIDEO_TV_SUPPORT)

//---------------------------------------------------------------------------
void MTVValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    switch(ucOsdState)
    {
    case _MI_CHANNEL:           CAdjChannel(ucMode);                break;
#if(_VIDEO_TV_SUPPORT)
#if(_NTSC_SEARCH_TABLE)
    case _MI_SYSTEM:            CSystemAdj(ucMode);                 break;
#else
    case _MI_SYSTEM:            EnterSystemMenu();                  break;
#endif
#endif
    case _MI_AUTOSEARCH:        EnterAutoSearchMenu();              break;
    case _MI_MANUALSEARCH:      EnterMSearchMenu();                 break;
    case _MI_TUNING:            CTuningAdj(ucMode);                 break;
    case _MI_SKIP:              EnterSkipMenu();                    break;
    case _MI_SWAP:              CAdjustSwap(ucMode);                break;
    case _MI_AFC:               EnterAFCMenu();                     break;
    }
}
//---------------------------------------------------------------------------
void CSwapSetup(void)
{
#if(_VIDEO_TV_SUPPORT)
    WORD ucSwapFreq        = CLoadChannelFreq(stTvInfo.CurChn);
    BYTE ucSwapColorSystem = CLoadChannelColorType(stTvInfo.CurChn);
    BYTE ucSwapSoundSystem = CLoadChannelSoundType(stTvInfo.CurChn);

    if (ucOsdState != _MI_SWAP)
        return;

    if (ucPrevChannel != stTvInfo.CurChn)
    {
        CAdjustBackgroundColor(0x00, 0x00, 0x00);     
        CScalerSetBit(_VDISP_CTRL_28, ~_BIT5, _BIT5);
        
        CSaveChannelFreq(CLoadChannelFreq(ucPrevChannel), stTvInfo.CurChn);
        CSaveChannelColorType(CLoadChannelColorType(ucPrevChannel), stTvInfo.CurChn);
        CSaveChannelSoundType(CLoadChannelSoundType(ucPrevChannel), stTvInfo.CurChn);
        
        CSaveChannelFreq(ucSwapFreq, ucPrevChannel);
        CSaveChannelColorType(ucSwapColorSystem, ucPrevChannel);
        CSaveChannelSoundType(ucSwapSoundSystem, ucPrevChannel);  
        
        CSetTVChannel(stTvInfo.CurChn);
    #if(_FM_DEVICE)
        if (1 == bFM)
        {
            CSetVolume();
        }
        else
    #endif
        {
            CModeResetTVMode();
        }        
        
        CTimerDelayXms(100);
        CScalerSetBit(_VDISP_CTRL_28, ~_BIT5, 0x00);
        bChangeChannel = 0;
        ucOsdEventMsg  = _SAVE_EE_TV_DATA_MSG;
        CLR_CLEAR_OSD_EN();

    }
#endif
}
//---------------------------------------------------------------------------
void MTVMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev
    BYTE ucNewItem;

    ucNewItem = AdjustMenuItem(_MI_CHANNEL,_MI_AFC,ucMode);
    if(ucNewItem == ucOsdState)
        return;

    // 1. Clear Current Menu
    DrawTVPageMenuItem(ucOsdState,_ST_NORMAL);

    // 2. Change ucOsdState
    ucOsdState = ucNewItem;

#if(_VIDEO_TV_SUPPORT)
    if (ucOsdState == _MI_SWAP)
       ucPrevChannel = stTvInfo.CurChn;
#endif
        
    CSetItemStartEnd(DrawTVPage);
    
    // 3. Draw New Item
    DrawTVPageMenuItem(ucOsdState,_ST_SELECT);
    
}
//---------------------------------------------------------------------------
void MTVEnterSubMenu(void)
{

    // 1. Before Enter SubMenu
    // Insert code to here ...


    // 2. Change ucOsdState
    switch(ucOsdState)
    {
        case _MI_CHANNEL:
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
			DrawChannel(_ST_ADJUST);    
			ucOsdState = _MI_OSD_CHANNELADJ;    	
#endif
        	break;
        	
        case _MI_SYSTEM:
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
			DrawSystem(_ST_ADJUST);
			EnterSystemMenu();        	
#endif        
			ucOsdState = _MI_S_PAL_I;
        	break;
        	
        case _MI_AUTOSEARCH:
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
        	DrawAutoSearch(_ST_ADJUST);
        	EnterAutoSearchMenu();
#endif
			ucOsdState = _MI_AUTOSEARCH_OK;                	     
        	break;
        	
        case _MI_MANUALSEARCH:
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
        	DrawManualSearch(_ST_ADJUST);
        	EnterMSearchMenu();        	 
#endif			  
			ucOsdState = _MI_MANUALSEARCH_UP;
        	break;
        case _MI_TUNING: 
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
        	DrawTuning(_ST_ADJUST);        	
         	ucOsdState = _MI_TUNINGADJ; 
#endif        
        	break;
        	
        case _MI_SKIP:      
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
        	DrawSkip(_ST_ADJUST);
        	EnterSkipMenu();
#endif        
			ucOsdState = _MI_SKIP_ON;           
        	break;

        case _MI_SWAP:              break;
        case _MI_AFC:               break;

    }

    // 3. Now enter sub menu
    // Insert code to here ...


}
//---------------------------------------------------------------------------
void MTVReturnUpMenu(void)
{
    CSwapSetup();

    // 1. Before Return UpMenu
    DrawTVPageMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_TV;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}

//---------------------------------------------------------------------------
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
void MChannelProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           
        CAdjChannel(_INC);               
        break;
        
    case _OE_ADJ_DEC:           
        CAdjChannel(_DEC);               
        break;
        
    case _OE_MENU_NEXT:    
        MChannelReturnUpMenu();
        MTVMenuAdj(_NEXT);
        break;
                                
    case _OE_MENU_PREV:         
        MChannelReturnUpMenu();
        MTVMenuAdj(_PREV);
        break;
        
    case _OE_ENTER_SUBMENU:     
        break;
        
    case _OE_RETURN_UPMENU:     
        MChannelReturnUpMenu();               
        break;
        
    }
}

//---------------------------------------------------------------------------
void MChannelReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawChannel(_ST_SELECT);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_CHANNEL;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}
#endif


//---------------------------------------------------------------------------
#define _PM_SYSTEM_ROW_START             4
//#define _PM_LANGUAGE_ROW_HEIGHT          5
#define _PM_SYSTEM_COL_START             1
#if(_VIDEO_TV_SUPPORT)

void DrawSystemMenuItem(BYTE ucItem,BYTE ucState)
{
    BYTE y;
    BYTE *pStr;
    
    if(!g_tMenuItem[ucItem].Enable())
    {
        ucState = _ST_DISABLE;  
    }
    
    // get display line
    y = GetShowIndex(ucItem,BEGIN(_MI_S_NTSC_M),END(_MI_S_SECAM_LL));
    
    if(y == _NOT_SHOW)
        return;
    
    switch(ucItem)
    {
    case _MI_S_NTSC_M:          pStr = sNTSC_M;         break;
    case _MI_S_NTSC_4_BG:       pStr = sNTSC_4_BG;      break;
    case _MI_S_NTSC_4_DK:       pStr = sNTSC_4_DK;      break;
    case _MI_S_NTSC_4_I:        pStr = sNTSC_4_I;       break;
    case _MI_S_TV_PAL_M:        pStr = sPAL_M;          break;
    case _MI_S_PAL_BG:          pStr = sPAL_BG;         break;
    case _MI_S_PAL_I:           pStr = sPAL_I;          break;
    case _MI_S_PAL_DK:          pStr = sPAL_DK;         break;
    case _MI_S_PAL_N:           pStr = sPAL_N;          break;
    case _MI_S_SECAM_BG:        pStr = sSECAM_BG;       break;
    case _MI_S_SECAM_DK:        pStr = sSECAM_DK;       break;
    case _MI_S_SECAM_L:         pStr = sSECAM_L;        break;
    case _MI_S_SECAM_LL:        pStr = sSECAM_LL;       break;
    }
    
    DrawAPopupMenuItem(pStr,y,_PM_SYSTEM_ROW_START,_PM_SYSTEM_COL_START,ucState);
    
}
#endif

//---------------------------------------------------------------------------
void EnterSystemMenu(void)
{
#if(_VIDEO_TV_SUPPORT)
    BYTE i;
    BYTE ucMode;
    BYTE ucCount;
    
    ucCount = GetShowCount(BEGIN(_MI_S_NTSC_M),END(_MI_S_SECAM_LL));
    
    CreatePopupMenu(_PM_SYSTEM_ROW_START, ucCount + 2);
    
    ucOsdState = ucTVType + _MI_S_NTSC_M - 1;
    
    for(i=_MI_S_NTSC_M;i<=_MI_S_SECAM_LL;i++)
    {
        if(i == ucOsdState)
            ucMode = _ST_SELECT;
        else
            ucMode = _ST_NORMAL;
        
        DrawSystemMenuItem(i,ucMode);
    }
#endif    
}
//---------------------------------------------------------------------------
void ClearSystemMenu(void)
{
    BYTE ucCount;
    
    ucCount = GetShowCount(BEGIN(_MI_S_NTSC_M),END(_MI_S_SECAM_LL));
    
    ClearPopupMenu(_PM_SYSTEM_ROW_START, ucCount + 2);
}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------
// MainMenu\TV\System\S_NTSC_M,S_NTSC_4_BG,S_NTSC_4_DK,S_NTSC_4_I,S_TV_PAL_M,S_PAL_BG,S_PAL_I,S_PAL_DK,S_PAL_N,S_SECAM_BG,S_SECAM_DK,S_SECAM_L,S_SECAM_LL,
// MainMenu\TV\System\_MI_S_NTSC_M,_MI_S_NTSC_4_BG,_MI_S_NTSC_4_DK,_MI_S_NTSC_4_I,_MI_S_TV_PAL_M,_MI_S_PAL_BG,_MI_S_PAL_I,_MI_S_PAL_DK,_MI_S_PAL_N,_MI_S_SECAM_BG,_MI_S_SECAM_DK,_MI_S_SECAM_L,_MI_S_SECAM_LL,
void MSystemProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MSystemValueAdj(_INC);              break;
    case _OE_ADJ_DEC:           MSystemValueAdj(_DEC);              break;
    case _OE_MENU_NEXT:         MSystemMenuAdj(_NEXT);              break;
    case _OE_MENU_PREV:         MSystemMenuAdj(_PREV);              break;
    case _OE_ENTER_SUBMENU:     MSystemEnterSubMenu();              break;
    case _OE_RETURN_UPMENU:     MSystemReturnUpMenu();              break;
        
    }
}
//---------------------------------------------------------------------------
void MSystemValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    ucMode = ucMode;        // test code
}
//---------------------------------------------------------------------------
void MSystemMenuAdj(BYTE ucMode)
{
#if(_VIDEO_TV_SUPPORT)
    
    BYTE ucNewItem = AdjustMenuItem(_MI_S_NTSC_M,_MI_S_SECAM_LL,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    DrawSystemMenuItem(ucOsdState,  _ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    ucTVType = ucOsdState - _MI_S_NTSC_M + 1;
    
    CSaveChannelColorType(stTvInfo.CurChn, ucTVType);
    gmi_CI2CWriteIfPllDM(ucTVType, _TUNER_MUTE_OFF, _NORMAL_MODE);
    CSetTvColor(ucTVType);
    ucTVSyncFailCount = 251;
    CLR_CLEAR_OSD_EN();
    
    OSDClear(ROW(17), HEIGHT(1), COL(14), WIDTH(20), 0x8C, BYTE_ATTRIB);
    OSDClear(ROW(17), HEIGHT(1), COL(14), WIDTH(20), 0x00, BYTE_DISPLAY);
    CShowMode(13,17);
    
    // 3. Draw New Item
    DrawSystemMenuItem(ucOsdState,  _ST_SELECT);
#else
    ucMode = ucMode;
#endif
}
//---------------------------------------------------------------------------
void MSystemEnterSubMenu(void)
{
#if(_VIDEO_TV_SUPPORT)
    CSaveChannelColorType(stTvInfo.CurChn,ucOsdState - _MI_S_NTSC_M+1);
#endif
    MSystemReturnUpMenu();
}
//---------------------------------------------------------------------------
void MSystemReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    ClearSystemMenu();
    
    // 2. Change ucOsdState
    ucOsdState = _MI_SYSTEM;
    
    // 3. Now Return to upmenu
    DrawTVPage();
}
//---------------------------------------------------------------------------



#define _PM_AUTOSEARCH_ROW_START                    8
#define _PM_AUTOSEARCH_ROW_HEIGHT                   4
#define _PM_AUTOSEARCH_COL_START                    3

void DrawAutoSearchMenuItem(BYTE ucItem,BYTE ucState)
{
    BYTE y;
    BYTE *pStr;
    
    if(!g_tMenuItem[ucItem].Enable())
    {
        ucState = _ST_DISABLE;  
    }
    
    // get display line
    y = GetShowIndex(ucItem,BEGIN(_MI_AUTOSEARCH_OK),END(_MI_AUTOSEARCH_CANCEL));
    
    if(y == _NOT_SHOW)
        return;
    
    
    switch(ucItem)
    {
    case _MI_AUTOSEARCH_OK:         pStr = sOK[GET_LANGUAGE()];     break;
    case _MI_AUTOSEARCH_CANCEL:     pStr = sCancel[GET_LANGUAGE()]; break;
    }
    
    DrawAPopupMenuItem(pStr,y,CGetPopupMenuRow(_PM_AUTOSEARCH_ROW_START,_MI_CHANNEL),_PM_AUTOSEARCH_COL_START,ucState);
    
}

//---------------------------------------------------------------------------
void EnterAutoSearchMenu(void)
{
    CreatePopupMenu(CGetPopupMenuRow(_PM_AUTOSEARCH_ROW_START,_MI_CHANNEL), _PM_AUTOSEARCH_ROW_HEIGHT);
    
    ucOsdState = _MI_AUTOSEARCH_CANCEL;
    
    DrawAutoSearchMenuItem(_MI_AUTOSEARCH_OK,_ST_NORMAL);
    DrawAutoSearchMenuItem(_MI_AUTOSEARCH_CANCEL,_ST_SELECT);   
}
//---------------------------------------------------------------------------
void ClearAutoSearchMenu(void)
{
    ClearPopupMenu(CGetPopupMenuRow(_PM_AUTOSEARCH_ROW_START,_MI_CHANNEL), _PM_AUTOSEARCH_ROW_HEIGHT);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// MainMenu\TV\AutoSearch\AutoSearch_OK,AutoSearch_Cancel,
// MainMenu\TV\AutoSearch\_MI_MANUALSEARCH_UP,_MI_MANUALSEARCH_DOWN,
void MAutoSearchProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MAutoSearchValueAdj(_INC);          break;
    case _OE_ADJ_DEC:           MAutoSearchValueAdj(_DEC);          break;
    case _OE_MENU_NEXT:         MAutoSearchMenuAdj(_NEXT);          break;
    case _OE_MENU_PREV:         MAutoSearchMenuAdj(_PREV);          break;
    case _OE_ENTER_SUBMENU:     MAutoSearchEnterSubMenu();          break;
    case _OE_RETURN_UPMENU:     MAutoSearchReturnUpMenu();          break;
        
    }
}
//---------------------------------------------------------------------------
void MAutoSearchValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    ucMode = ucMode;  
}
//---------------------------------------------------------------------------
void MAutoSearchMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev
    
    BYTE ucNewItem = AdjustMenuItem(_MI_AUTOSEARCH_OK,_MI_AUTOSEARCH_CANCEL,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    DrawAutoSearchMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 3. Draw New Item
    DrawAutoSearchMenuItem(ucOsdState,_ST_SELECT);
    
}
//---------------------------------------------------------------------------
void MAutoSearchEnterSubMenu(void)
{
#if(_VIDEO_TV_SUPPORT)
    bit fAutoSearch = 0;
    BYTE y;
    
    if(ucOsdState == _MI_AUTOSEARCH_OK)
        fAutoSearch = 1;
    
    MAutoSearchReturnUpMenu();
    
    // get display line
    y = GetShowIndex(_MI_AUTOSEARCH, BEGIN(ucStartItem), END(ucEndItem));
    y = SHOWINDEX_TO_LINE(y);
    
    if(fAutoSearch)
    {
        ucStartItem = _MI_CHANNEL;
        ucEndItem   = _MI_SKIP;
        for(y=0;y<6;y++)
        {
            OSDLine(SHOWINDEX_TO_LINE(y), COL(7), LENGTH(38), 0x00, BYTE_DISPLAY);
            OSDLine(SHOWINDEX_TO_LINE(y), COL(7), LENGTH(38), 0x8C, BYTE_ATTRIB);
        }
        DrawTVPage();
        y = GetShowIndex(_MI_AUTOSEARCH, BEGIN(ucStartItem), END(ucEndItem));
        y = SHOWINDEX_TO_LINE(y);
        OSDLine(SHOWINDEX_TO_LINE(0), COL(_MSG_COL), LENGTH(3), StateColor(_ST_SELECT), BYTE_COLOR);
    	CScalerPageSelect(_PAGE8);		
        CScalerSetBit(_P8_OUTPUT_CTRL_A7, ~_BIT5, _BIT5);
        CTvAutoSearch();
    	CScalerPageSelect(_PAGE8);		
        CScalerSetBit(_P8_OUTPUT_CTRL_A7, ~_BIT5, 0x00);
        
        OSDClear(ROW(y), HEIGHT(1), COL(_MSG_COL), WIDTH(10), 0x8C, BYTE_ATTRIB);
        OSDClear(ROW(y), HEIGHT(1), COL(_MSG_COL), WIDTH(10), 0x00, BYTE_DISPLAY);
        
        OSDLine(SHOWINDEX_TO_LINE(0), COL(_MSG_COL), LENGTH(3), StateColor(_ST_NORMAL), BYTE_COLOR);
        CShowNumber(_MSG_COL, SHOWINDEX_TO_LINE(0), stTvInfo.CurChn);
        
		DrawChannel(_ST_NORMAL);
        DrawTuning(_ST_NORMAL);
        DrawSkip(_ST_NORMAL);
    }
#endif
}
//---------------------------------------------------------------------------
void MAutoSearchReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    ClearAutoSearchMenu();
    
    // 2. Change ucOsdState
    ucOsdState = _MI_AUTOSEARCH;
    
    // 3. Now Return to upmenu
    DrawTVPage();
}
//---------------------------------------------------------------------------


#define _PM_MSEARCH_ROW_START                   10
#define _PM_MSEARCH_ROW_HEIGHT                  4
#define _PM_MSEARCH_COL_START                   0

void DrawMSearchMenuItem(BYTE ucItem,BYTE ucState)
{
    BYTE y;
    BYTE *pStr;
    
    if(!g_tMenuItem[ucItem].Enable())
    {
        ucState = _ST_DISABLE;  
    }
    
    // get display line
    y = GetShowIndex(ucItem,BEGIN(_MI_MANUALSEARCH_UP),END(_MI_MANUALSEARCH_DOWN));
    
    if(y == _NOT_SHOW)
        return;
    
    
    switch(ucItem)
    {
    case _MI_MANUALSEARCH_UP:       pStr = sSearchUP[GET_LANGUAGE()];       break;
    case _MI_MANUALSEARCH_DOWN:     pStr = sSearchDown[GET_LANGUAGE()];     break;
    }
    
    DrawAPopupMenuItem(pStr,y,CGetPopupMenuRow(_PM_MSEARCH_ROW_START,_MI_CHANNEL),_PM_MSEARCH_COL_START,ucState);
    
}

//---------------------------------------------------------------------------
void EnterMSearchMenu(void)
{                   
    CreatePopupMenu(CGetPopupMenuRow(_PM_MSEARCH_ROW_START,_MI_CHANNEL), _PM_MSEARCH_ROW_HEIGHT);
    
    ucOsdState = _MI_MANUALSEARCH_UP;
    
    DrawMSearchMenuItem(_MI_MANUALSEARCH_UP,_ST_SELECT);
    DrawMSearchMenuItem(_MI_MANUALSEARCH_DOWN,_ST_NORMAL);  
}
//---------------------------------------------------------------------------
void ClearMSearchMenu(void)
{
    ClearPopupMenu(CGetPopupMenuRow(_PM_MSEARCH_ROW_START,_MI_CHANNEL), _PM_MSEARCH_ROW_HEIGHT);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// MainMenu\TV\ManualSearch\ManualSearch_OK,ManualSearch_Cancel,
// MainMenu\TV\ManualSearch\_MI_MANUALSEARCH_UP,_MI_MANUALSEARCH_DOWN,
void MManualSearchProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MManualSearchValueAdj(_INC);        break;
    case _OE_ADJ_DEC:           MManualSearchValueAdj(_DEC);        break;
    case _OE_MENU_NEXT:         MManualSearchMenuAdj(_NEXT);        break;
    case _OE_MENU_PREV:         MManualSearchMenuAdj(_PREV);        break;
    case _OE_ENTER_SUBMENU:     MManualSearchEnterSubMenu();        break;
    case _OE_RETURN_UPMENU:     MManualSearchReturnUpMenu();        break;
        
    }
}
//---------------------------------------------------------------------------
void MManualSearchValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    ucMode = ucMode;        // test code
}
//---------------------------------------------------------------------------
void MManualSearchMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev
    
    BYTE ucNewItem = AdjustMenuItem(_MI_MANUALSEARCH_UP,_MI_MANUALSEARCH_DOWN,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    DrawMSearchMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 3. Draw New Item
    DrawMSearchMenuItem(ucOsdState,_ST_SELECT);
    
}
//---------------------------------------------------------------------------
void MManualSearchEnterSubMenu(void)
{
#if(_VIDEO_TV_SUPPORT)
    bit fSearch = 0;
    BYTE y;
    
    switch(ucOsdState)
    {
    case _MI_MANUALSEARCH_UP:       fSearch = 1;        break;
    case _MI_MANUALSEARCH_DOWN:     fSearch = 0;        break;
    }
    
    MManualSearchReturnUpMenu();
    
    // get display line
    y = GetShowIndex(_MI_MANUALSEARCH, BEGIN(ucStartItem), END(ucEndItem));
    y = SHOWINDEX_TO_LINE(y);
    
	CScalerPageSelect(_PAGE8);		
    CScalerSetBit(_P8_OUTPUT_CTRL_A7, ~_BIT5, _BIT5);
    CManualSearch(fSearch, stTvInfo.CurChn);
	CScalerPageSelect(_PAGE8);		
    CScalerSetBit(_P8_OUTPUT_CTRL_A7, ~_BIT5, 0x00);
    
    OSDClear(ROW(y), HEIGHT(1), COL(_MSG_COL), WIDTH(10), 0x8C, BYTE_ATTRIB);
    OSDClear(ROW(y), HEIGHT(1), COL(_MSG_COL), WIDTH(10), 0x00, BYTE_DISPLAY);
    
	DrawChannel(_ST_NORMAL);
    DrawTuning(_ST_NORMAL);
    DrawSkip(_ST_NORMAL);
    CTimerDelayXms(200);
#endif
}
//---------------------------------------------------------------------------
void MManualSearchReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    ClearMSearchMenu();
    
    // 2. Change ucOsdState
    ucOsdState = _MI_MANUALSEARCH;
    
    // 3. Now Return to upmenu
    DrawTVPage();
}
//---------------------------------------------------------------------------

#define _PM_SKIP_ROW_START                      12
#define _PM_SKIP_ROW_HEIGHT                     4
#define _PM_SKIP_COL_START                      3

void DrawSkipMenuItem(BYTE ucItem,BYTE ucState)
{
    BYTE y;
    BYTE *pStr;
    
    if(!g_tMenuItem[ucItem].Enable())
    {
        ucState = _ST_DISABLE;  
    }
    
    // get display line
    y = GetShowIndex(ucItem,BEGIN(_MI_SKIP_ON),END(_MI_SKIP_OFF));
    
    if(y == _NOT_SHOW)
        return;
    
    
    switch(ucItem)
    {
    case _MI_SKIP_ON:           pStr = sOn[GET_LANGUAGE()];     break;
    case _MI_SKIP_OFF:          pStr = sOff[GET_LANGUAGE()];    break;
    }
    
    DrawAPopupMenuItem(pStr,y,CGetPopupMenuRow(_PM_SKIP_ROW_START,_MI_CHANNEL),_PM_SKIP_COL_START,ucState);
}
//---------------------------------------------------------------------------
void EnterSkipMenu(void)
{
#if(_VIDEO_TV_SUPPORT)
    BYTE i;
    BYTE ucMode;
    
    CreatePopupMenu(CGetPopupMenuRow(_PM_SKIP_ROW_START,_MI_CHANNEL), _PM_SKIP_ROW_HEIGHT);
    
    if(CLoadChannelSkip(stTvInfo.CurChn))
    {
        ucOsdState = _MI_SKIP_ON;
    }
    else
    {
        ucOsdState = _MI_SKIP_OFF;
    }
    
    for(i=_MI_SKIP_ON;i<=_MI_SKIP_OFF;i++)
    {
        if(i == ucOsdState)
            ucMode = _ST_SELECT;
        else
            ucMode = _ST_NORMAL;
        
        DrawSkipMenuItem(i,ucMode);
    }
#endif    
}
//---------------------------------------------------------------------------
void ClearSkipMenu(void)
{                      
    ClearPopupMenu(CGetPopupMenuRow(_PM_SKIP_ROW_START,_MI_CHANNEL), _PM_SKIP_ROW_HEIGHT);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// MainMenu\TV\Skip\Skip_On,Skip_Off,
// MainMenu\TV\Skip\_MI_SKIP_ON,_MI_SKIP_OFF,
void MSkipProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MSkipValueAdj(_INC);                break;
    case _OE_ADJ_DEC:           MSkipValueAdj(_DEC);                break;
    case _OE_MENU_NEXT:         MSkipMenuAdj(_NEXT);                break;
    case _OE_MENU_PREV:         MSkipMenuAdj(_PREV);                break;
    case _OE_ENTER_SUBMENU:     MSkipEnterSubMenu();                break;
    case _OE_RETURN_UPMENU:     MSkipReturnUpMenu();                break;
        
    }
}
//---------------------------------------------------------------------------
void MSkipValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    ucMode = ucMode;        // test code
}
//---------------------------------------------------------------------------
void MSkipMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev
    
    BYTE ucNewItem = AdjustMenuItem(_MI_SKIP_ON,_MI_SKIP_OFF,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    DrawSkipMenuItem(ucOsdState,    _ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 3. Draw New Item
    DrawSkipMenuItem(ucOsdState,    _ST_SELECT);
}
//---------------------------------------------------------------------------
void MSkipEnterSubMenu(void)
{
#if(_VIDEO_TV_SUPPORT)
    bit fSkip = 0;

    switch(ucOsdState)
    {
    case _MI_SKIP_ON:           fSkip = 1;          break;
    case _MI_SKIP_OFF:          fSkip = 0;          break;
    }
    
    CSaveChannelSkip(fSkip, stTvInfo.CurChn);
    MSkipReturnUpMenu();
#endif
}
//---------------------------------------------------------------------------
void MSkipReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    ClearSkipMenu();
    
    // 2. Change ucOsdState
    ucOsdState = _MI_SKIP;
    
    // 3. Now Return to upmenu
    DrawTVPage();
}
//---------------------------------------------------------------------------
#define _PM_AFC_ROW_START                      12
#define _PM_AFC_ROW_HEIGHT                     4
#define _PM_AFC_COL_START                      3

#if(_VIDEO_TV_SUPPORT && _TV_AFC)
void DrawAFCMenuItem(BYTE ucItem,BYTE ucState)
{
    BYTE y;
    BYTE *pStr;
    
    if(!g_tMenuItem[ucItem].Enable())
    {
        ucState = _ST_DISABLE;  
    }
    
    // get display line
    y = GetShowIndex(ucItem,BEGIN(_MI_AFC_ON),END(_MI_AFC_OFF));
    
    if(y == _NOT_SHOW)
        return;
    
    
    switch(ucItem)
    {
    case _MI_AFC_ON:           pStr = sOn[GET_LANGUAGE()];     break;
    case _MI_AFC_OFF:          pStr = sOff[GET_LANGUAGE()];    break;
    }
    
    DrawAPopupMenuItem(pStr,y,_PM_AFC_ROW_START,_PM_AFC_COL_START,ucState);
}
#endif

//---------------------------------------------------------------------------
void EnterAFCMenu(void)
{
#if(_VIDEO_TV_SUPPORT && _TV_AFC)
    BYTE i;
    BYTE ucMode;

    CreatePopupMenu(_PM_AFC_ROW_START, _PM_AFC_ROW_HEIGHT);
    
    if(GET_AFC_MODE())
    {
        ucOsdState = _MI_AFC_ON;
    }
    else
    {
        ucOsdState = _MI_AFC_OFF;
    }
    
    for(i=_MI_AFC_ON;i<=_MI_AFC_OFF;i++)
    {
        if(i == ucOsdState)
            ucMode = _ST_SELECT;
        else
            ucMode = _ST_NORMAL;
        
        DrawAFCMenuItem(i,ucMode);
    }
#endif    
}
//---------------------------------------------------------------------------
void ClearAFCMenu(void)
{
    ClearPopupMenu(_PM_AFC_ROW_START, _PM_AFC_ROW_HEIGHT);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// MainMenu\TV\AFC\AFC_On,AFC_Off,
// MainMenu\TV\AFC\_MI_AFC_ON,_MI_AFC_OFF,
void MAFCProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MAFCValueAdj(_INC);                break;
    case _OE_ADJ_DEC:           MAFCValueAdj(_DEC);                break;
    case _OE_MENU_NEXT:         MAFCMenuAdj(_NEXT);                break;
    case _OE_MENU_PREV:         MAFCMenuAdj(_PREV);                break;
    case _OE_ENTER_SUBMENU:     MAFCEnterSubMenu();                break;
    case _OE_RETURN_UPMENU:     MAFCReturnUpMenu();                break;
        
    }
}
//---------------------------------------------------------------------------
void MAFCValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    ucMode = ucMode;        // test code
}
//---------------------------------------------------------------------------
void MAFCMenuAdj(BYTE ucMode)
{
#if (_TV_AFC)
    // ucMode : _NEXT or _Prev
    
    BYTE ucNewItem = AdjustMenuItem(_MI_AFC_ON,_MI_AFC_OFF,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    DrawAFCMenuItem(ucOsdState,    _ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 3. Draw New Item
    DrawAFCMenuItem(ucOsdState,    _ST_SELECT);
#else
    ucMode = 0;
#endif
}
//---------------------------------------------------------------------------
void MAFCEnterSubMenu(void)
{
#if(_VIDEO_TV_SUPPORT)
    #if (_TV_AFC)
    BYTE AFC = 0;

    switch(ucOsdState)
    {
    case _MI_AFC_ON:           
        AFCState = _TV_AFC_START;
        AFC = 1;          
        break;

    case _MI_AFC_OFF:          
        AFC = 0;          
        break;
    }
    
    SET_AFC_MODE(AFC);
    ucOsdEventMsg = _SAVE_EE_TV_DATA_MSG;
    #endif
    MAFCReturnUpMenu();
#endif
}
//---------------------------------------------------------------------------
void MAFCReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    ClearAFCMenu();
    
    // 2. Change ucOsdState
    ucOsdState = _MI_AFC;
    
    // 3. Now Return to upmenu
    DrawTVPage();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// MainMenu\Function\Reset,DisplayRatio,AutoPowerDown,BlueScreen,
// MainMenu\Function\_MI_RESET,_MI_DISPLAYRATIO,_MI_AUTOPOWERDOWN,_MI_BLUESCREEN,_MI_SHARPNESS
void MFunctionProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MFunctionValueAdj(_INC);            break;
    case _OE_ADJ_DEC:           MFunctionValueAdj(_DEC);            break;
    case _OE_MENU_NEXT:         MFunctionMenuAdj(_NEXT);            break;
    case _OE_MENU_PREV:         MFunctionMenuAdj(_PREV);            break;
    case _OE_ENTER_SUBMENU:     MFunctionEnterSubMenu();            break;
    case _OE_RETURN_UPMENU:     MFunctionReturnUpMenu();            break;
        
    }
}
//---------------------------------------------------------------------------
void MFunctionValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC   
    switch(ucOsdState)
    {
    case _MI_RESET:             EnterResetMenu();                   break;
    case _MI_DISPLAYRATIO:      EnterDisplayRatioMenu();            break;
    case _MI_AUTOPOWERDOWN:     EnterADPMenu();                     break;
    case _MI_BLUESCREEN:        EnterBlueScreenMenu();              break;
    case _MI_SHARPNESS:         MSharpnessAdjValue(ucMode);         break;
    }
    
    
    
}
//---------------------------------------------------------------------------
void MFunctionMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev
    
    BYTE ucNewItem = AdjustMenuItem(_MI_RESET,_MI_SHARPNESS,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    DrawFuncPageMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 3. Draw New Item
    DrawFuncPageMenuItem(ucOsdState,_ST_SELECT);
    
}
//---------------------------------------------------------------------------
void MFunctionEnterSubMenu(void)
{
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    switch(ucOsdState)
    {
    case _MI_RESET:     
        DrawReset(_ST_ADJUST);
        EnterResetMenu();
        ucOsdState = _MI_RESET_CANCEL;          
        break;

    case _MI_DISPLAYRATIO:      
        DrawDisplayRatio(_ST_ADJUST);
        EnterDisplayRatioMenu();
        break;

    case _MI_AUTOPOWERDOWN: 
        DrawAutoPowerDown(_ST_ADJUST);
        EnterADPMenu();
        break;

    case _MI_BLUESCREEN:
        DrawBlueScreen(_ST_ADJUST);
        EnterBlueScreenMenu();
        break;

    case _MI_SHARPNESS:
        DrawSharpness(_ST_ADJUST);
        ucOsdState = _MI_SHARPNESS_ADJ;
        break;
    }
#endif
    // 3. Now enter sub menu
    // Insert code to here ...
    
}
//---------------------------------------------------------------------------
void MFunctionReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawFuncPageMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_FUNCTION;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}
//---------------------------------------------------------------------------
#define _PM_RESET_ROW_START                 4
#define _PM_RESET_ROW_HEIGHT                4
#define _PM_RESET_COL_START                 3

void DrawResetMenuItem(BYTE ucItem,BYTE ucState)
{
    BYTE y;
    BYTE *pStr;
    
    if(!g_tMenuItem[ucItem].Enable())
    {
        ucState = _ST_DISABLE;  
    }
    
    // get display line
    y = GetShowIndex(ucItem,BEGIN(_MI_RESET_OK),END(_MI_RESET_CANCEL));
    
    if(y == _NOT_SHOW)
        return;
    
    
    switch(ucItem)
    {
    case _MI_RESET_OK:          pStr = sOK[GET_LANGUAGE()];     break;
    case _MI_RESET_CANCEL:      pStr = sCancel[GET_LANGUAGE()]; break;
    }
    
    DrawAPopupMenuItem(pStr,y,_PM_RESET_ROW_START,_PM_RESET_COL_START,ucState);
    
}

//---------------------------------------------------------------------------
void EnterResetMenu(void)
{
    CreatePopupMenu(_PM_RESET_ROW_START, _PM_RESET_ROW_HEIGHT);
    
    ucOsdState = _MI_RESET_CANCEL;
    
    DrawResetMenuItem(_MI_RESET_OK,_ST_NORMAL);
    DrawResetMenuItem(_MI_RESET_CANCEL,_ST_SELECT); 
}
//---------------------------------------------------------------------------
void ClearResetMenu(void)
{
    ClearPopupMenu(_PM_RESET_ROW_START, _PM_RESET_ROW_HEIGHT);
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
// MainMenu\Function\Reset\Reset_OK,Reset_Cancel,
// MainMenu\Function\Reset\_MI_RESET_OK,_MI_RESET_CANCEL,
void MResetProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MResetValueAdj(_INC);               break;
    case _OE_ADJ_DEC:           MResetValueAdj(_DEC);               break;
    case _OE_MENU_NEXT:         MResetMenuAdj(_NEXT);               break;
    case _OE_MENU_PREV:         MResetMenuAdj(_PREV);               break;
    case _OE_ENTER_SUBMENU:     MResetEnterSubMenu();               break;
    case _OE_RETURN_UPMENU:     MResetReturnUpMenu();               break;
        
    }
}
//---------------------------------------------------------------------------
void MResetValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    ucMode = ucMode;        // test code
}
//---------------------------------------------------------------------------
void MResetMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev
    
    BYTE ucNewItem = AdjustMenuItem(_MI_RESET_OK,_MI_RESET_CANCEL,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    DrawResetMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 3. Draw New Item
    DrawResetMenuItem(ucOsdState,_ST_SELECT);
    
}
//---------------------------------------------------------------------------
void MResetEnterSubMenu(void)
{
    bit fDoReset = 0;
    
    if(ucOsdState == _MI_RESET_OK)
        fDoReset = 1;
    
    if(fDoReset)
    {
        CDoReset();
    }
    MResetReturnUpMenu();
}
//---------------------------------------------------------------------------
void MResetReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    ClearResetMenu();
    
    // 2. Change ucOsdState
    ucOsdState = _MI_RESET;
    
    // 3. Now Return to upmenu
    DrawFuncPage();
}
//---------------------------------------------------------------------------



#define _PM_DISPLAYRATIO_ROW_START                  6
#define _PM_DISPLAYRATIO_ROW_HEIGHT					5
#define _PM_DISPLAYRATIO_COL_START                  3

void DrawDisplayRatioMenuItem(BYTE ucItem,BYTE ucState)
{
    BYTE y;
    BYTE *pStr;
    
    if(!g_tMenuItem[ucItem].Enable())
    {
        ucState = _ST_DISABLE;  
    }
    
    // get display line
	y = GetShowIndex(ucItem,BEGIN(_MI_DISPLAYRATIO_FULL),END(_MI_DISPLAYRATIO_AUTO));

	if(y == _NOT_SHOW)
		return;


	switch(ucItem)
	{
		case _MI_DISPLAYRATIO_FULL:		
			pStr = s16_9;					
			break;
			
		case _MI_DISPLAYRATIO_4_3:		
			pStr = s4_3;					
			break;

		case _MI_DISPLAYRATIO_AUTO:
			pStr = sAuto;
			break;
	}
	
    DrawAPopupMenuItem(pStr,y,_PM_DISPLAYRATIO_ROW_START,_PM_DISPLAYRATIO_COL_START,ucState);
    
}

//---------------------------------------------------------------------------
void EnterDisplayRatioMenu(void)
{
    BYTE i;
    BYTE ucMode;
    
    CreatePopupMenu(_PM_DISPLAYRATIO_ROW_START, _PM_DISPLAYRATIO_ROW_HEIGHT);
    
    if(GET_DISPLAYMODE() == _DISPMODE_FULL)
    {
        ucOsdState = _MI_DISPLAYRATIO_FULL;
    }
	else if(GET_DISPLAYMODE() == _DISPMODE_43)
	{
		ucOsdState = _MI_DISPLAYRATIO_4_3;
	}
	else
	{
		ucOsdState = _MI_DISPLAYRATIO_AUTO;
	}

//	for(i=_MI_DISPLAYRATIO_FULL;i<=_MI_DISPLAYRATIO_4_3;i++)
	for(i=_MI_DISPLAYRATIO_FULL;i<=_MI_DISPLAYRATIO_AUTO;i++)
    {
        if(i == ucOsdState)
        {
            ucMode = _ST_SELECT;
        }
        else
        {   
            ucMode = _ST_NORMAL;
        }
        
        DrawDisplayRatioMenuItem(i,     ucMode);
    }
}
//---------------------------------------------------------------------------
void ClearDisplayRatioMenu(void)
{
    ClearPopupMenu(_PM_DISPLAYRATIO_ROW_START, _PM_DISPLAYRATIO_ROW_HEIGHT);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// MainMenu\Function\DisplayRatio\DisplayRatio_Full,DisplayRatio_4_3,
// MainMenu\Function\DisplayRatio\_MI_DISPLAYRATIO_FULL,_MI_DISPLAYRATIO_4_3,
void MDisplayRatioProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MDisplayRatioValueAdj(_INC);        break;
    case _OE_ADJ_DEC:           MDisplayRatioValueAdj(_DEC);        break;
    case _OE_MENU_NEXT:         MDisplayRatioMenuAdj(_NEXT);        break;
    case _OE_MENU_PREV:         MDisplayRatioMenuAdj(_PREV);        break;
    case _OE_ENTER_SUBMENU:     MDisplayRatioEnterSubMenu();        break;
    case _OE_RETURN_UPMENU:     MDisplayRatioReturnUpMenu();        break;
        
    }
}
//---------------------------------------------------------------------------
void MDisplayRatioValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    ucMode = ucMode;        // test code
}
//---------------------------------------------------------------------------
void MDisplayRatioMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev
    
    BYTE ucNewItem = AdjustMenuItem(_MI_DISPLAYRATIO_FULL,_MI_DISPLAYRATIO_AUTO,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    DrawDisplayRatioMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 3. Draw New Item
    DrawDisplayRatioMenuItem(ucOsdState,_ST_SELECT);
}
//---------------------------------------------------------------------------
void MDisplayRatioEnterSubMenu(void)
{
    switch(ucOsdState)
    {
        case _MI_DISPLAYRATIO_FULL:       
        	SET_DISPLAYMODE(_DISPMODE_FULL);	
        	break;
        	
        case _MI_DISPLAYRATIO_4_3:        
        	SET_DISPLAYMODE(_DISPMODE_43);	
        	break;

        case _MI_DISPLAYRATIO_AUTO:
        	SET_DISPLAYMODE(_DISPMODE_AUTO);	
        	break;
    }
    
    MDisplayRatioReturnUpMenu();
    
    CLR_CLEAR_OSD_EN();
    CEepromSaveSystemData();

    CPowerLightPowerOff();        
    CMuteOn();
/*    
	bDoAspectRatioFlag = _TRUE;
	if (bSourceVideo())
    {
		CVideoDisplaySet();
    }
	else
    {
		if(0)//GET_INPUTSOURCE_TYPE() == _SOURCE_DVI)
		{
		 	stModeInfo.IHWidth = HDMI_H_Width;
		 	stModeInfo.IVHeight = HDMI_V_Height;
		}
		CModeDisplayActiveMode();
	}
	bDoAspectRatioFlag = _FALSE;
    CPowerLightPowerOn(); */       
    ucTVSyncFailCount = 250;
    CModeResetMode();
}
//---------------------------------------------------------------------------
void MDisplayRatioReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    ClearDisplayRatioMenu();
    
    // 2. Change ucOsdState
    ucOsdState = _MI_DISPLAYRATIO;
    
    // 3. Now Return to upmenu
    DrawFuncPage();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


#define _PM_ADP_ROW_START                       4
#define _PM_ADP_ROW_HEIGHT                      11
#define _PM_ADP_COL_START                       1

void DrawADPMenuItem(BYTE ucItem,BYTE ucState)
{
    BYTE y;
    BYTE *pStr;
    
    if(!g_tMenuItem[ucItem].Enable())
    {
        ucState = _ST_DISABLE;  
    }
    
    // get display line
    y = GetShowIndex(ucItem,BEGIN(_MI_AUTOPOWERDOWN_OFF),END(_MI_APD_120));
    
    if(y == _NOT_SHOW)
        return;
    
    switch(ucItem)
    {
    case _MI_AUTOPOWERDOWN_OFF: pStr = sOff[GET_LANGUAGE()];    break;
    case _MI_APD_15:            pStr = s15Min[GET_LANGUAGE()];  break;
    case _MI_APD_30:            pStr = s30Min[GET_LANGUAGE()];  break;
    case _MI_APD_45:            pStr = s45Min[GET_LANGUAGE()];  break;
    case _MI_APD_60:            pStr = s60Min[GET_LANGUAGE()];  break;
    case _MI_APD_75:            pStr = s75Min[GET_LANGUAGE()];  break;
    case _MI_APD_90:            pStr = s90Min[GET_LANGUAGE()];  break;
    case _MI_APD_105:           pStr = s105Min[GET_LANGUAGE()]; break;
    case _MI_APD_120:           pStr = s120Min[GET_LANGUAGE()]; break;
    }
    
    DrawAPopupMenuItem(pStr,y,_PM_ADP_ROW_START,_PM_ADP_COL_START,ucState);
}
//---------------------------------------------------------------------------
void EnterADPMenu(void)
{
    BYTE i;
    BYTE ucMode;
    
    CreatePopupMenu(_PM_ADP_ROW_START, _PM_ADP_ROW_HEIGHT);
    
    switch(_GET_POWER_DOWN_TIME())
    {
    case 0x00:          ucOsdState = _MI_AUTOPOWERDOWN_OFF;     break;
    case 0x01:          ucOsdState = _MI_APD_15;                break;
    case 0x02:          ucOsdState = _MI_APD_30;                break;
    case 0x03:          ucOsdState = _MI_APD_45;                break;
    case 0x04:          ucOsdState = _MI_APD_60;                break;
    case 0x05:          ucOsdState = _MI_APD_75;                break;
    case 0x06:          ucOsdState = _MI_APD_90;                break;
    case 0x07:          ucOsdState = _MI_APD_105;               break;
    case 0x08:          ucOsdState = _MI_APD_120;               break;
    }
    
    
    for(i=_MI_AUTOPOWERDOWN_OFF;i<=_MI_APD_120;i++)
    {
        if(i == ucOsdState)
            ucMode = _ST_SELECT;
        else
            ucMode = _ST_NORMAL;
        
        DrawADPMenuItem(i,ucMode);
    }
    
}
//---------------------------------------------------------------------------
void ClearADPMenu(void)
{
    ClearPopupMenu(_PM_ADP_ROW_START, _PM_ADP_ROW_HEIGHT);
}
//---------------------------------------------------------------------------




// MainMenu\Function\AutoPowerDown\AutoPowerDown_Off,APD_15,APD_30,APD_45,APD_60,APD_75,APD_90,
// MainMenu\Function\AutoPowerDown\_MI_AUTOPOWERDOWN_OFF,_MI_APD_15,_MI_APD_30,_MI_APD_45,_MI_APD_60,_MI_APD_75,_MI_APD_90,
void MAutoPowerDownProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MAutoPowerDownValueAdj(_INC);       break;
    case _OE_ADJ_DEC:           MAutoPowerDownValueAdj(_DEC);       break;
    case _OE_MENU_NEXT:         MAutoPowerDownMenuAdj(_NEXT);       break;
    case _OE_MENU_PREV:         MAutoPowerDownMenuAdj(_PREV);       break;
    case _OE_ENTER_SUBMENU:     MAutoPowerDownEnterSubMenu();       break;
    case _OE_RETURN_UPMENU:     MAutoPowerDownReturnUpMenu();       break;
        
    }
}
//---------------------------------------------------------------------------
void MAutoPowerDownValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    ucMode = ucMode;        // test code
}
//---------------------------------------------------------------------------
void MAutoPowerDownMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev
    
    BYTE ucNewItem = AdjustMenuItem(_MI_AUTOPOWERDOWN_OFF,_MI_APD_120,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    DrawADPMenuItem(ucOsdState, _ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 3. Draw New Item
    DrawADPMenuItem(ucOsdState, _ST_SELECT);
}
//---------------------------------------------------------------------------
void MAutoPowerDownEnterSubMenu(void)
{
#if(_VIDEO_TV_SUPPORT)
    _SET_POWER_DOWN_TIME(ucOsdState - _MI_AUTOPOWERDOWN_OFF);
    MAutoPowerDownReturnUpMenu();
    ucOsdEventMsg = _SAVE_EE_TV_DATA_MSG;
    
    ucAutoPowerDownTime = _GET_POWER_DOWN_TIME() * 15;
    if (0 == ucAutoPowerDownTime) // Auto power down time off
    {
        ucAutoPowerDownTime = 0xff;
    }
    
    ucMinuteCount = 0;  // Reset count
#endif
}
//---------------------------------------------------------------------------
void MAutoPowerDownReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    ClearADPMenu();
    
    // 2. Change ucOsdState
    ucOsdState = _MI_AUTOPOWERDOWN;
    
    // 3. Now Return to upmenu
    DrawFuncPage();
}
//---------------------------------------------------------------------------

//#define _PM_BLUESCREEN_ROW_START                      10
#define _PM_BLUESCREEN_ROW_HEIGHT                       4
#define _PM_BLUESCREEN_COL_START                        3

void DrawBlueScreenMenuItem(BYTE ucItem,BYTE ucState)
{
    BYTE y;
    BYTE *pStr;
    
    BYTE ucBlueScreenRowStart;
    
    if(!g_tMenuItem[ucItem].Enable())
    {
        ucState = _ST_DISABLE;  
    }
    
    // get display line
    y = GetShowIndex(ucItem,BEGIN(_MI_BLUESCREEN_ON),END(_MI_BLUESCREEN_OFF));
    
    if(y == _NOT_SHOW)
        return;
    
    
    switch(ucItem)
    {
    case _MI_BLUESCREEN_ON:         pStr = sOn[GET_LANGUAGE()];     break;
    case _MI_BLUESCREEN_OFF:        pStr = sOff[GET_LANGUAGE()];    break;
    }
    
    ucBlueScreenRowStart = GetShowIndex(_MI_BLUESCREEN,BEGIN(_MI_RESET),END(_MI_SHARPNESS));
    
    ucBlueScreenRowStart = SHOWINDEX_TO_LINE(ucBlueScreenRowStart);
    DrawAPopupMenuItem(pStr,y,ucBlueScreenRowStart,_PM_BLUESCREEN_COL_START,ucState);
    
}
//---------------------------------------------------------------------------
void EnterBlueScreenMenu(void)
{
    BYTE i;
    BYTE ucMode;
    
    BYTE ucBlueScreenRowStart = GetShowIndex(_MI_BLUESCREEN,BEGIN(_MI_RESET),END(_MI_SHARPNESS));
    ucBlueScreenRowStart = SHOWINDEX_TO_LINE(ucBlueScreenRowStart);
    
    CreatePopupMenu(ucBlueScreenRowStart, _PM_BLUESCREEN_ROW_HEIGHT);
    
    if(_GET_BLUE_BACKGROUND())
        ucOsdState = _MI_BLUESCREEN_ON;
    else ucOsdState = _MI_BLUESCREEN_OFF;
    
    for(i=_MI_BLUESCREEN_ON;i<=_MI_BLUESCREEN_OFF;i++)
    {
        if(i == ucOsdState)
            ucMode = _ST_SELECT;
        else
            ucMode = _ST_NORMAL;
        
        DrawBlueScreenMenuItem(i,ucMode);
    }
    
}
//---------------------------------------------------------------------------
void ClearBlueScreenMenu(void)
{
    BYTE ucBlueScreenRowStart = GetShowIndex(_MI_BLUESCREEN,BEGIN(_MI_RESET),END(_MI_SHARPNESS));
    ucBlueScreenRowStart = SHOWINDEX_TO_LINE(ucBlueScreenRowStart);
    ClearPopupMenu(ucBlueScreenRowStart, _PM_BLUESCREEN_ROW_HEIGHT);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// MainMenu\Function\BlueScreen\BlueScreen_On,BlueScreen_Off,
// MainMenu\Function\BlueScreen\_MI_BLUESCREEN_ON,_MI_BLUESCREEN_OFF,
void MBlueScreenProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MBlueScreenValueAdj(_INC);          break;
    case _OE_ADJ_DEC:           MBlueScreenValueAdj(_DEC);          break;
    case _OE_MENU_NEXT:         MBlueScreenMenuAdj(_NEXT);          break;
    case _OE_MENU_PREV:         MBlueScreenMenuAdj(_PREV);          break;
    case _OE_ENTER_SUBMENU:     MBlueScreenEnterSubMenu();          break;
    case _OE_RETURN_UPMENU:     MBlueScreenReturnUpMenu();          break;
        
    }
}
//---------------------------------------------------------------------------
void MBlueScreenValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    ucMode = ucMode;        // test code
}
//---------------------------------------------------------------------------
void MBlueScreenMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev
    
    BYTE ucNewItem = AdjustMenuItem(_MI_BLUESCREEN_ON,_MI_BLUESCREEN_OFF,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    DrawBlueScreenMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 3. Draw New Item
    DrawBlueScreenMenuItem(ucOsdState,_ST_SELECT);
}
//---------------------------------------------------------------------------
void MBlueScreenEnterSubMenu(void)
{
    switch(ucOsdState)
    {
    case _MI_BLUESCREEN_ON:     _SET_BLUE_BACKGROUND(1);            break;
    case _MI_BLUESCREEN_OFF:    _SET_BLUE_BACKGROUND(0);            break;
    }
    
    ucOsdEventMsg = _SAVE_EE_SYSTEMDATA_MSG;
    MBlueScreenReturnUpMenu();
}
//---------------------------------------------------------------------------
void MBlueScreenReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    ClearBlueScreenMenu();
    
    // 2. Change ucOsdState
    ucOsdState = _MI_BLUESCREEN;
    
    // 3. Now Return to upmenu
    DrawFuncPage();
}

//---------------------------------------------------------------------------
void MSharpnessAdjValue(BYTE ucMode)
{
    BYTE y;
    BYTE ucTemp = GET_PEAKING_CORING();
                                      
    SET_KEYREPEATENABLE();
    // get display line
    y = GetShowIndex(_MI_SHARPNESS,BEGIN(_MI_RESET),END(_MI_SHARPNESS));
    
    if(y == _NOT_SHOW)
        return;
    
    y = SHOWINDEX_TO_LINE(y);
    
    OSDClear(ROW(y), HEIGHT(1), COL(_MSG_COL), WIDTH(3), 0x8C, BYTE_ATTRIB);
    OSDClear(ROW(y), HEIGHT(1), COL(_MSG_COL), WIDTH(3), 0x00, BYTE_DISPLAY);
    
    ucTemp = ValueInRangeChange(0, 100, ucTemp, _NON_LOOP | ucMode);
    SET_PEAKING_CORING(ucTemp);
    
    // draw
    OSDLine(ROW(y), _MSG_COL, LENGTH(10), StateColor(_ST_ADJUST), BYTE_COLOR);
    
    CShowNumber(_MSG_COL, y, ucTemp);
    CAdjustPeakingCoding();

    ucOsdEventMsg = _SAVE_EE_SYSTEMDATA_MSG;
}


#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
//---------------------------------------------------------------------------
// MainMenu\Sound\Volume\VolumeAdj
// MainMenu\Sound\Volume\_MI_VOLUMEADJ
void MSharpnessProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           
        MSharpnessAdjValue(_INC);               
        break;
        
    case _OE_ADJ_DEC:           
        MSharpnessAdjValue(_DEC);               
        break;
        
    case _OE_MENU_NEXT:
        MSharpnessReturnUpMenu();
        MFunctionMenuAdj(_NEXT);
        break;
        
    case _OE_MENU_PREV:
        MSharpnessReturnUpMenu();
        MFunctionMenuAdj(_PREV);
        break;
        
    case _OE_ENTER_SUBMENU:     
        
        break;
        
    case _OE_RETURN_UPMENU:     
        MSharpnessReturnUpMenu(); 
        break;
        
    }
}

//---------------------------------------------------------------------------
void MSharpnessReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawSharpness(_ST_SELECT);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_SHARPNESS;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}
#endif

//---------------------------------------------------------------------------
// MainMenu\Sound\Volume,Balance,Bass,Treble,SRS,BBE,
// MainMenu\Sound\_MI_VOLUME,_MI_BALANCE,_MI_BASS,_MI_TREBLE,_MI_SRS,_MI_BBE,
void MSoundProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MSoundValueAdj(_INC);               break;
    case _OE_ADJ_DEC:           MSoundValueAdj(_DEC);               break;
    case _OE_MENU_NEXT:         MSoundMenuAdj(_NEXT);               break;
    case _OE_MENU_PREV:         MSoundMenuAdj(_PREV);               break;
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    case _OE_ENTER_SUBMENU:     MSoundEnterSubMenu();               break;
#endif
    case _OE_RETURN_UPMENU:     MSoundReturnUpMenu();               break;
        
    }
}
//---------------------------------------------------------------------------
void MSoundValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    switch(ucOsdState)
    {
    case _MI_VOLUME:            VolumeAdjust(ucMode);               break;
    case _MI_BALANCE:           CBalanceAdjust(ucMode);             break;
    case _MI_BASS:              CBassAdjust(ucMode);                break;
    case _MI_TREBLE:            CTrebleAdjust(ucMode);              break;
    case _MI_SRS:                                                   break;
    case _MI_BBE:                                                   break;
    }
    
    
    
}
//---------------------------------------------------------------------------
void MSoundMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev
    
    BYTE ucNewItem = AdjustMenuItem(_MI_VOLUME,_MI_BBE,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    DrawSoundPageMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 3. Draw New Item
    DrawSoundPageMenuItem(ucOsdState,_ST_SELECT);
    
}

#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
//---------------------------------------------------------------------------
void MSoundEnterSubMenu(void)
{
    // 1. Before Enter SubMenu
    // Insert code to here ...
    
    
    // 2. Change ucOsdState
    switch(ucOsdState)
    {
    case _MI_VOLUME:
        DrawVolume(_ST_ADJUST);
        ucOsdState = _MI_VOLUMEADJ;
        break;
    case _MI_BALANCE:
        DrawBalance(_ST_ADJUST);
        ucOsdState = _MI_BALANCEADJ;
        break;
    case _MI_BASS:
        DrawBass(_ST_ADJUST);
        ucOsdState = _MI_BASSADJ;
        break;
    case _MI_TREBLE:
        DrawTreble(_ST_ADJUST);
        ucOsdState = _MI_TREBLEADJ;
        break;
    case _MI_SRS:
        //DrawSRS(_ST_ADJUST);
        //ucOsdState = _MI_SRSADJ;
        break;
    case _MI_BBE:
        //DrawBBE(_ST_ADJUST);
        //ucOsdState = _MI_BBEADJ;
        break;
    }    
}
#endif

//---------------------------------------------------------------------------
void MSoundReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawSoundPageMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_SOUND;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}

#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
//---------------------------------------------------------------------------
// MainMenu\Sound\Volume\VolumeAdj
// MainMenu\Sound\Volume\_MI_VOLUMEADJ
void MVolumeProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           
        MVolumeValueAdj(_INC);               
        break;
        
    case _OE_ADJ_DEC:           
        MVolumeValueAdj(_DEC);               
        break;
        
    case _OE_MENU_NEXT:
        MVolumeReturnUpMenu();
        MSoundMenuAdj(_NEXT);
        break;
        
    case _OE_MENU_PREV:
        MVolumeReturnUpMenu();
        MSoundMenuAdj(_PREV);
        break;
        
    case _OE_ENTER_SUBMENU:     
        break;
        
    case _OE_RETURN_UPMENU:     
        MVolumeReturnUpMenu(); 
        break;
        
    }
}

//---------------------------------------------------------------------------
void MVolumeValueAdj(BYTE ucMode)
{
    VolumeAdjust(ucMode);
}

//---------------------------------------------------------------------------
void MVolumeReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawVolume(_ST_SELECT);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_VOLUME;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}

//---------------------------------------------------------------------------
// MainMenu\Sound\Balance\BalanceAdj
// MainMenu\Sound\Balance\_MI_BALANCEADJ
void MBalanceProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           
        MBalanceValueAdj(_INC);               
        break;
        
    case _OE_ADJ_DEC:           
        MBalanceValueAdj(_DEC);               
        break;
        
    case _OE_MENU_NEXT:         
        MBalanceReturnUpMenu();
        MSoundMenuAdj(_NEXT);               
        break;
        
    case _OE_MENU_PREV:         
        MBalanceReturnUpMenu();
        MSoundMenuAdj(_PREV);               
        break;
        
    case _OE_ENTER_SUBMENU:     
        break;
        
    case _OE_RETURN_UPMENU:     
        MBalanceReturnUpMenu();               
        break;
        
    }
}

//---------------------------------------------------------------------------
void MBalanceValueAdj(BYTE ucMode)
{
    CBalanceAdjust(ucMode);
}

//---------------------------------------------------------------------------
void MBalanceReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawBalance(_ST_SELECT);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_BALANCE;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}

//---------------------------------------------------------------------------
// MainMenu\Sound\Bass\BassAdj
// MainMenu\Sound\Bass\_MI_BASSADJ
void MBassProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           
        MBassValueAdj(_INC);               
        break;
        
    case _OE_ADJ_DEC:           
        MBassValueAdj(_DEC);               
        break;
        
    case _OE_MENU_NEXT:         
        MBassReturnUpMenu();
        MSoundMenuAdj(_NEXT);               
        break;
        
    case _OE_MENU_PREV:         
        MBassReturnUpMenu();
        MSoundMenuAdj(_PREV);               
        break;
        
    case _OE_ENTER_SUBMENU:    
        break;
        
    case _OE_RETURN_UPMENU:     
        MBassReturnUpMenu();              
        break;
        
    }
}

//---------------------------------------------------------------------------
void MBassValueAdj(BYTE ucMode)
{
    CBassAdjust(ucMode);
}

//---------------------------------------------------------------------------
void MBassReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawBass(_ST_SELECT);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_BASS;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}

//---------------------------------------------------------------------------
// MainMenu\Sound\Treble\TrebleAdj
// MainMenu\Sound\Treble\_MI_TREBLEADJ
void MTrebleProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           
        MTrebleValueAdj(_INC);               
        break;
        
    case _OE_ADJ_DEC:           
        MTrebleValueAdj(_DEC);               
        break;
        
    case _OE_MENU_NEXT:         
        MTrebleReturnUpMenu();
        MSoundMenuAdj(_NEXT);              
        break;
        
    case _OE_MENU_PREV:         
        MTrebleReturnUpMenu();
        MSoundMenuAdj(_PREV);
        break;
        
    case _OE_ENTER_SUBMENU:     
        
        break;
    case _OE_RETURN_UPMENU:     
        MTrebleReturnUpMenu();               
        break;
        
    }
}

//---------------------------------------------------------------------------
void MTrebleValueAdj(BYTE ucMode)
{
    CTrebleAdjust(ucMode);
}

//---------------------------------------------------------------------------
void MTrebleReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    DrawTreble(_ST_SELECT);
    
    // 2. Change ucOsdState
    ucOsdState = _MI_TREBLE;
    
    // 3. Now Return to upmenu
    // Insert code to here ...
}
#endif

//---------------------------------------------------------------------------

#if(_CHANGE_SOURCE_METHOD == _CHANGE_SOURCE_METHOD_0)
void DrawSourceMenuItem(BYTE ucItem,BYTE ucState)
{
    BYTE y;
    BYTE ucColor;
    BYTE code *pStr;
    
    // get display line
    y = GetShowIndex(ucItem,BEGIN(_MI_SOURCE_VGA),END(_MI_SOURCE_TV));
    
    if(y == _NOT_SHOW)
        return;
    
    // get display color
    ucColor = StateColor(ucState);
    
    y = SHOWINDEX_TO_LINE1(y);
    
    // set color
    SUBMENU_LINECOLOR1(y,ucColor);
    // draw menu item 
    
    switch(ucItem)
    {
    case _MI_SOURCE_VGA:            pStr = sVGA;        break;
    case _MI_SOURCE_DVI:            pStr = sDVI;        break;
    case _MI_SOURCE_HDMI:           pStr = sHDMI;       break;
    case _MI_SOURCE_YPBPR:          pStr = sYPBPR;      break;
    case _MI_SOURCE_SV:             pStr = sSVideo;     break;
    case _MI_SOURCE_AV:             pStr = sAV;         break;
    case _MI_SOURCE_TV:             pStr = sTV;         break;
    }
    
    
    SUBMENU_TEXTOUT1(pStr,y);
    
    // draw select line
    if(ucState == _ST_SELECT)
    {
        DRAW_SUBMENU_SELLINE1(y + 1);
    }
    else
    {
        CLEAR_SUBMENU_SELLINE1(y + 1);
    }
}

//---------------------------------------------------------------------------
#define _SOURCE_MENU_WIDTH              (12 * 12 - 4)           
#define _SOURCE_MENU_HEIGHT(n)          ((2+(n * 2)) * 18 + 4)

void DrawSourceMenu(void)
{
    BYTE i;
    BYTE ucMode;
    BYTE ucShowCount = GetShowCount(BEGIN(_MI_SOURCE_VGA),END(_MI_SOURCE_TV));
    
    if (ucCurrState == _SLEEP_STATE)
    {
        ucTVSyncFailCount = 250;
        CModeResetMode();
        ucCurrState = _NOSIGNAL_STATE;
        CPowerPanelOn();
        CPowerLightPowerOn();
    }
    
    InitOsdFrame();
    OSDClear(ROW(14), HEIGHT(1), COL(0), WIDTH(46), 0x8C, BYTE_ATTRIB);
    OSDClear(ROW(14), HEIGHT(1), COL(0), WIDTH(46), 0x00, BYTE_DISPLAY);
    OSDClear(ROW(14), HEIGHT(1), COL(0), WIDTH(46), 0x20, BYTE_COLOR);
    SetOSDDouble((GET_OSD_SIZE() ? 0x03 : 0x00) | OSD_WINDOWCHAR_BLENDING);   
   
    for(i=0;i<ucShowCount;i++)
    {
        ucMode = (i * 2) + 2;
        SETCOLOR_SUBMENU_SELLINE1(ucMode);
    }
    
    switch(_GET_INPUT_SOURCE())
    {
    case _SOURCE_VGA:           ucOsdState = _MI_SOURCE_VGA;        break;
    case _SOURCE_DVI:           ucOsdState = _MI_SOURCE_DVI;        break;
    case _SOURCE_HDMI:          ucOsdState = _MI_SOURCE_HDMI;       break;
    case _SOURCE_YPBPR:         ucOsdState = _MI_SOURCE_YPBPR;      break;
    case _SOURCE_VIDEO_SV:      ucOsdState = _MI_SOURCE_SV;         break;
    case _SOURCE_VIDEO_AV:      ucOsdState = _MI_SOURCE_AV;         break;
    case _SOURCE_VIDEO_TV:      ucOsdState = _MI_SOURCE_TV;         break;
    }
    
    for(i=_MI_SOURCE_VGA;i<=_MI_SOURCE_TV;i++)
    {
        if(i == ucOsdState)
            ucMode = _ST_SELECT;
        else 
            ucMode = _ST_NORMAL;
        
        DrawSourceMenuItem(i,ucMode);   
    }
    
    // Draw Window
    COsdFxDrawWindow(0,0,                                       //WORD usXStart,WORD usYStart,  
        _SOURCE_MENU_WIDTH,_SOURCE_MENU_HEIGHT(ucShowCount),    //WORD usXEnd,WORD usYEnd,  
        tMainWindowStyle);                                      //BYTE *pStyle)
    
    i = 0;
    ucMode = 0;
    if (!GET_OSD_SIZE())
    {
        i = 3;
        ucMode = 3;
    }
    
    OSDPosition(_SOURCE_MENU_WIDTH,_SOURCE_MENU_HEIGHT(ucShowCount),0+i,0+ucMode,0x03);
    COsdFxEnableOsd();
}

//---------------------------------------------------------------------------
// MainMenu\Source\VGA,DVI,HDMI,SV,AV,TV,
// MainMenu\Source\_MI_SOURCE_VGA,_MI_SOURCE_DVI,_MI_SOURCE_HDMI,_MI_SOURCE_SV,_MI_SOURCE_AV,_MI_SOURCE_TV,
void MSourceProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MSourceValueAdj(_INC);              break;
    case _OE_ADJ_DEC:           MSourceValueAdj(_DEC);              break;
    case _OE_MENU_NEXT:         MSourceMenuAdj(_NEXT);              break;
    case _OE_MENU_PREV:         MSourceMenuAdj(_PREV);              break;
#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
    case _OE_ENTER_SUBMENU:     MSourceEnterSubMenu();              break;
#endif
    case _OE_RETURN_UPMENU:     MSourceReturnUpMenu();              break;
        
    }
    
}

//---------------------------------------------------------------------------
void MSourceValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    ucMode = _GET_INPUT_SOURCE();
    
    switch(ucOsdState)
    {
    case _MI_SOURCE_VGA:        _SET_INPUT_SOURCE(_SOURCE_VGA);         break;
    case _MI_SOURCE_DVI:        _SET_INPUT_SOURCE(_SOURCE_DVI);         break;
    case _MI_SOURCE_HDMI:       _SET_INPUT_SOURCE(_SOURCE_HDMI);        break;
    case _MI_SOURCE_YPBPR:      _SET_INPUT_SOURCE(_SOURCE_YPBPR);       break;
    case _MI_SOURCE_SV:         _SET_INPUT_SOURCE(_SOURCE_VIDEO_SV);    break;
    case _MI_SOURCE_AV:         _SET_INPUT_SOURCE(_SOURCE_VIDEO_AV);    break;
    case _MI_SOURCE_TV:         _SET_INPUT_SOURCE(_SOURCE_VIDEO_TV);    break;
    }
    
    COsdDispOsdTimerEvent();
    if(ucMode != _GET_INPUT_SOURCE())
    {                
        ucCurrState   = _SEARCH_STATE;
        ucOsdEventMsg = _CHANGE_SOURCE_MSG;        
    }
}

//---------------------------------------------------------------------------
void MSourceMenuAdj(BYTE ucMode)
{
    // ucMode : _NEXT or _Prev
    
    BYTE ucNewItem = AdjustMenuItem(_MI_SOURCE_VGA,_MI_SOURCE_TV,ucMode);
    if(ucNewItem == ucOsdState)
        return;
    
    // 1. Clear Current Menu
    DrawSourceMenuItem(ucOsdState,_ST_NORMAL);
    
    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 3. Draw New Item
    DrawSourceMenuItem(ucOsdState,_ST_SELECT);
    
}

#if(_KEY_TYPE == _KT_PCB2660_003_5KEY)
//---------------------------------------------------------------------------
void MSourceEnterSubMenu(void)
{
    // 1. Before Enter SubMenu
    // Insert code to here ...
    BYTE ucMode = _GET_INPUT_SOURCE();
    
    
    // 2. Change ucOsdState
    switch(ucOsdState)
    {
    case _MI_SOURCE_VGA:
        _SET_INPUT_SOURCE(_SOURCE_VGA);
        break;
        
    case _MI_SOURCE_DVI:
        _SET_INPUT_SOURCE(_SOURCE_DVI);
        break;
        
    case _MI_SOURCE_HDMI:
        _SET_INPUT_SOURCE(_SOURCE_HDMI);
        break;
        
    case _MI_SOURCE_YPBPR:                                                
        _SET_INPUT_SOURCE(_SOURCE_YPBPR);
        break;
        
    case _MI_SOURCE_SV:
        _SET_INPUT_SOURCE(_SOURCE_VIDEO_SV);
        break;
        
    case _MI_SOURCE_AV:
        _SET_INPUT_SOURCE(_SOURCE_VIDEO_AV);
        break;
        
    case _MI_SOURCE_TV:
        _SET_INPUT_SOURCE(_SOURCE_VIDEO_TV);
        break;
    }
    
    // 3. Now enter sub menu
    // Insert code to here ...
    
    COsdDispOsdTimerEvent();
    if(ucMode != _GET_INPUT_SOURCE())
    {                
        ucOsdEventMsg = _CHANGE_SOURCE_MSG;        
    }
    
}
#endif

//---------------------------------------------------------------------------
void MSourceReturnUpMenu(void)
{
    // 1. Before Return UpMenu
    // Insert code to here ...
    
    // 2. Change ucOsdState
    // ucOsdState = _MI_MENU_NONE;
    // COsdFxDisableOsd();
    COsdDispOsdTimerEvent();
    // 3. Now Return to upmenu
    // Insert code to here ...
}
//---------------------------------------------------------------------------
#endif // #if(_CHANGE_SOURCE_METHOD == _CHANGE_SOURCE_METHOD_0)


#define _SHORT_CUT_MENU_WIDTH               (27 * 12)
#define _SHORT_CUT_MENU_HEIGHT              (6 * 18)

#define SC_MENU_TEXTOUT(str)                CCenterTextout(str,ROW(1),2,23)
#define SC_SLIDER(value)                    OSDSlider(ROW(3), COL(3), LENGTH(17), value, 100, 0x10)

//---------------------------------------------------------------------------
void DrawShortCuteMenu(void)
{
    InitOsdFrame();
    SetOSDDouble((GET_OSD_SIZE() ? 0x03 : 0x00) | OSD_WINDOWCHAR_BLENDING);   
    
    // Draw Top Line
    OSDLine(ROW(2), COL(2), LENGTH(23), 0xA6, THE_BYTE0);
    OSDLine(ROW(2), COL(2), LENGTH(23), 0xA4, THE_BYTE1);
    OSDLine(ROW(2), COL(2), LENGTH(23), 0x11, THE_BYTE2);
    
    // Draw Bottom Line
    OSDLine(ROW(4), COL(2), LENGTH(23), 0xA6, THE_BYTE0);
    OSDLine(ROW(4), COL(2), LENGTH(23), 0xA4, THE_BYTE1);
    OSDLine(ROW(4), COL(2), LENGTH(23), 0x11, THE_BYTE2);
    
    // Draw Window
    COsdFxDrawWindow(0,0,                               //WORD usXStart,WORD usYStart,  
        _SHORT_CUT_MENU_WIDTH,_SHORT_CUT_MENU_HEIGHT,       //WORD usXEnd,WORD usYEnd,  
        tMainWindowStyle);                  //BYTE *pStyle)
    
    CSetOSDPosition(_SHORT_CUT_MENU_WIDTH, _SHORT_CUT_MENU_HEIGHT, 50, 100);   
}

//---------------------------------------------------------------------------
void EnterSCBright(void)
{
    ucOsdState = _MI_SC_BRIGHTNESS;
    DrawShortCuteMenu();
    SC_MENU_TEXTOUT(sBrightness[GET_LANGUAGE()]);
    SC_SLIDER(stConBriData.Brightness);
    COsdFxEnableOsd();
    SET_KEYREPEATENABLE();
}

//---------------------------------------------------------------------------
void EnterSCVolume(void)
{
    ucOsdState = _MI_SC_VOLUME;
    DrawShortCuteMenu();
    SC_MENU_TEXTOUT(sVolume[GET_LANGUAGE()]);
    SC_SLIDER(GET_VOLUME());
    COsdFxEnableOsd();
    SET_KEYREPEATENABLE();
    CLR_AUDIO_MUTE();
    ucOsdEventMsg = _SAVE_EE_AUDIO_DATA_MSG;
    if (_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV && bTVNoSignal == 1)
        return;

    CSetVolume();
}

//---------------------------------------------------------------------------
#if(_VIDEO_TV_SUPPORT)
#define _INPUT_NO_NUMBER       0
#define _INPUT_ONE_NUMBER      1
#define _INPUT_TWO_NUMBER      2
#define _INPUT_THREE_NUMBER    3
WORD iInpuNumCount = 0;
void EnterSCInputNum(void)
{
    BYTE ucInputState = GET_INPUTCH_STATE() + 1;
    
    COsdLoad1BitFont(FntInputState,0x7A,1,tFntVolumeCharWidth);
    
    // iInputCHCount = _INPUT_CH_TIMEOUT_COUNT;
    // Reset input number and state
    ucCurrentInputNumber = 0;
    // 0: no input number   1: input one number     2: input two number    3: input three number
    ucCurrentInputState  = _INPUT_NO_NUMBER;  
    
    if (ucInputState > 3)
    {   // Input state err reset input state to input one channel -
        ucInputState = 1;
        SET_INPUTCH_STATE(0);
        CEepromSaveTvData();
    }
    
    ucOsdState = _MI_SC_INPUT_CH_NUM;
    bChangeChannel = 0;
    COsdFxDisableOsd();
#if(_LOGO_ENABLE)
    if (bLoadLogoFont)
    {       
        SetOsdMap(tUserMenuOsdMap);
        
        // Load global font 
        // insert code to here 
        COsdLoad1BitFont(FntGlobal,0x00,0x5F,tGlobalCharWidth);
        CScalerLoadHardwareVLCFont(FntMainIcon,0x80 * 2);
        
    	//Load Languege Font
    	LoadLanguageFont();
        bLoadLogoFont = 0;
    }
#endif

    SetOSDDouble(0x03);
    SetOsdMap(tMsgOsdMap);
    
    // Init OSD Ram
    OSDClear(0, 8, 0, 10, 0x8C, BYTE_ATTRIB);
    OSDClear(0, 8, 0, 10, 0x00, BYTE_DISPLAY);
    OSDClear(0, 8, 0, 10, 0xF0, BYTE_COLOR);
    
    COsdFxCodeWrite(ucCloseAllWindow);
    
    OSDPosition(_MAINMENU_WIDTH,_MAINMENU_HEIGHT,64,1,0x03);
    
    Gotoxy(1, 0, BYTE_DISPLAY);         
    for(; ucInputState > 0; ucInputState--)
        OutputChar(0x7A);  // Show "-"
    
    
    COsdFxEnableOsd();
    CTimerReactiveTimerEvent(SEC(20),COsdDispOsdTimerEvent);
    bOSDTimeOut   = 0;
    iInpuNumCount = 0;
}
#endif
//---------------------------------------------------------------------------

void MScBrightnessProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MScBrgithnessValueAdj(_INC);              break;
    case _OE_ADJ_DEC:           MScBrgithnessValueAdj(_DEC);              break;
    case _OE_RETURN_UPMENU:     MScBrgithnessReturnUpMenu();              break;
        
    }
    
}

//---------------------------------------------------------------------------
void MScBrgithnessValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    SET_KEYREPEATENABLE();
    stConBriData.Brightness = ValueInRangeChange(0, 100, stConBriData.Brightness, _NON_LOOP | ucMode);
    CAdjustBrightness();
    ucOsdEventMsg = _SAVE_EE_COLORPROC0_MSG;
    
    SC_SLIDER(stConBriData.Brightness);    
}

//---------------------------------------------------------------------------
void MScBrgithnessReturnUpMenu(void)
{
    ucOsdState = _MI_MENU_NONE;
    COsdFxDisableOsd();
}

//---------------------------------------------------------------------------
void MScVolumeProc(void)
{
    switch(ucOsdEventMsg)
    {
    case _OE_ADJ_INC:           MScVolumeValueAdj(_INC);              break;
    case _OE_ADJ_DEC:           MScVolumeValueAdj(_DEC);              break;
    case _OE_RETURN_UPMENU:     MScVolumeReturnUpMenu();              break;
        
    }
}

//---------------------------------------------------------------------------
void MScVolumeValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    SET_KEYREPEATENABLE();
    stAudioData.Volume = ValueInRangeChange(0, 100, stAudioData.Volume, _NON_LOOP | ucMode);
    ucOsdEventMsg = _SAVE_EE_AUDIO_DATA_MSG;
    SC_SLIDER(GET_VOLUME()); 
    if (_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV && bTVNoSignal == 1)
        return;
    CSetVolume();
}
//---------------------------------------------------------------------------
void MScVolumeReturnUpMenu(void)
{
    ucOsdState = _MI_MENU_NONE;
    COsdFxDisableOsd();
}

//---------------------------------------------------------------------------
void MScInputChNumProc(void)
{
#if(_VIDEO_TV_SUPPORT)
    BYTE idata ucInputState = GET_INPUTCH_STATE() + 1;
    
    iInpuNumCount++;

    if (iInpuNumCount > 900)
        ucOsdEventMsg = _OE_RETURN_UPMENU;

    switch(ucOsdEventMsg)
    {        
    case _OE_SC_INPUT_NUM0:
    case _OE_SC_INPUT_NUM1:
    case _OE_SC_INPUT_NUM2:
    case _OE_SC_INPUT_NUM3:
    case _OE_SC_INPUT_NUM4:
    case _OE_SC_INPUT_NUM5:
    case _OE_SC_INPUT_NUM6:
    case _OE_SC_INPUT_NUM7:
    case _OE_SC_INPUT_NUM8:
    case _OE_SC_INPUT_NUM9:
        SInceptNumber(ucOsdEventMsg - _OE_SC_INPUT_NUM0);
        iInpuNumCount = 0;
        break;
        
    case _OE_SC_INPUT_CHANGE_CH:
        //            iInputCHCount = _INPUT_CH_TIMEOUT_COUNT;
        ucInputState = ValueInRangeChange(1, 3, ucInputState, _LOOP | 0x01);
        SET_INPUTCH_STATE(ucInputState-1);
        CEepromSaveTvData();
        
        // Reset input number and state
        ucCurrentInputNumber = 0;
        // 0: no input number   1: input one number     2: input two number    3: input three number
        ucCurrentInputState  = 0;
        iInpuNumCount        = 0;
        break;
        
    case _OE_RETURN_UPMENU:
        if (_INPUT_NO_NUMBER == ucCurrentInputState)
            COsdDispOsdTimerEvent();
        else
            ucInputState = ucCurrentInputState;
        break;
    }
    
    SShowCurrentInputState(ucInputState);
    
    if (ucInputState == ucCurrentInputState)
    {
        BYTE ucMaxChannel = CloadMaxChannelNumber();
        
        CMuteOn();
        COsdDispOsdTimerEvent();
        CModeResetTVMode();
        CTimerDelayXms(200);
        
#if(_FM_DEVICE)
        if (1 == bFM)
        {
            ucPrevChannel =  stTvInfo.ucFMCurrCh;
            stTvInfo.ucFMCurrCh = (ucCurrentInputNumber > ucMaxChannel) ? ucMaxChannel : ucCurrentInputNumber;
            CSetTVChannel(stTvInfo.ucFMCurrCh);
            CShowTVNumber(stTvInfo.ucFMCurrCh, _SHOW_CH_TV_NUMBER);
        }
        else
#endif   
        {
            ucPrevChannel =  stTvInfo.CurChn;
            stTvInfo.CurChn = (ucCurrentInputNumber > ucMaxChannel) ? ucMaxChannel : ucCurrentInputNumber;
            CSetTVChannel(stTvInfo.CurChn);
            //            CShowTVNumber(stTvInfo.CurChn,_SHOW_CH_TV_NUMBER | _SHOW_CH_TV_TYPE | _SHOW_CH_SOUND_TYPE);
            gmi_CI2CWriteIfPllDM(ucTVType, _TUNER_MUTE_OFF, _NORMAL_MODE);
        }
        
        ucOsdEventMsg = _SAVE_EE_TV_DATA_MSG;
    }
    
//    CTimerReactiveTimerEvent(SEC(10), COsdDispOsdTimerEvent);
    bOSDTimeOut = 0;
#endif
}

#if(_VIDEO_TV_SUPPORT)
//---------------------------------------------------------------------------
void SInceptNumber(const WORD ucNumber)
{
    switch(ucCurrentInputState)
    { 
    case _INPUT_NO_NUMBER: // not input number
        ucCurrentInputNumber = ucNumber;
        ucCurrentInputState  = _INPUT_ONE_NUMBER;
        break;
        
    case _INPUT_ONE_NUMBER: // Input on number alrady
    case _INPUT_TWO_NUMBER: // Input two number alrady
        ucCurrentInputNumber = (ucCurrentInputNumber*10) + ucNumber;
        ucCurrentInputState  = (ucCurrentInputState == _INPUT_TWO_NUMBER) ? _INPUT_THREE_NUMBER : _INPUT_TWO_NUMBER;
        break;
        /*
        case _INPUT_TWO_NUMBER: // Input two number alrady
        ucCurrentInputNumber = (ucCurrentInputNumber*10) + ucNumber;
        ucCurrentInputState  = _INPUT_THREE_NUMBER;
        break;*/
    }
}

//---------------------------------------------------------------------------
void SShowCurrentInputState(BYTE ucInputState)
{
    Gotoxy(1, 0, BYTE_DISPLAY); 
    
    switch(ucCurrentInputState)
    {
    case _INPUT_NO_NUMBER: // not input number
        for(;ucInputState > 0;ucInputState--)
            OutputChar(0x7A);  // Show "-"
        OutputChar(0x01);  // Show " "
        OutputChar(0x01);  // Show " "
        break;
        
    case _INPUT_ONE_NUMBER: // Input on number alrady
        CShowNumber1(ucCurrentInputNumber,1);
        break;
        
    case _INPUT_TWO_NUMBER: // Input two number alrady
        CShowNumber1(ucCurrentInputNumber,2);
        break;
        
    case _INPUT_THREE_NUMBER: // Input three number alrady
        CShowNumber1(ucCurrentInputNumber,3);
        break;
    }
}

//---------------------------------------------------------------------------
bit CKeyStopAutoSearch(void)
{
    if (_MENU_KEY_MASK == CKeyScan() || _MENU_KEY_MESSAGE == CIRKeyScan())
        return 1;
    
    return 0;
}

//-----------------------------------------------------------------------
void CShowAutoSerachTotal(BYTE ucSearchTotal)
{
    CShowNumber(_MSG_COL, SHOWINDEX_TO_LINE(0), ucSearchTotal);    
}

//-----------------------------------------------------------------------
void CShowFreq(WORD iFreqN, BYTE x, BYTE y)
{
    DWORD lFreqTemp = 0;
    BYTE  xx = 6;
    
    // Get PIF freq
#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)  
    if (bFM)
        lFreqTemp = (((float)iFreqN/_FM_TUNER_BP) - ((float)_PIF_FREQ/1000))*100;
    else
#endif
        lFreqTemp = (((float)iFreqN/_TUNER_BP) - ((float)_PIF_FREQ/1000))*100;
    
    iFreqN = lFreqTemp/100;  // MHz
    Gotoxy(x, y, BYTE_DISPLAY);
    CShowNumber1(iFreqN, 0);
    OutputChar(0x5F); // "."
    if (iFreqN < 100)
        xx = 5;
    
    iFreqN = lFreqTemp%100;  // KHz
    CShowNumber1(iFreqN, 2);
    
    CTextOutEx(sMhz, x+xx, y);
}     

//-----------------------------------------------------------------------
void CShowAutoSearchSliderInOSD(WORD ucCurrentValue)
{
    BYTE ucY;
    
    ucY = (ucOsdState == _MI_AUTOSEARCH) ? SHOWINDEX_TO_LINE(2) : SHOWINDEX_TO_LINE(3);
    CShowFreq(ucCurrentValue, _MSG_COL, ucY);
}
#endif

//---------------------------------------------------------------------------
void CShowVGAMode(BYTE x,BYTE y)
{
    if (stModeInfo.IVFreq == 0) 
        return;

    Gotoxy(x, y, BYTE_DISPLAY);
    CShowNumber1(stModeInfo.IHWidth, 0);
    OutputChar(0x2D);  // "X"
    CShowNumber1(stModeInfo.IVHeight, 0);
    OutputChar(0x01);  // " "
    CShowNumber1((stModeInfo.IVFreq/10), 0);
    OutputChar(0x19);  // "H"
    OutputChar(0x2F);  // "Z"
    OutputChar(0x01);  // " "
}
//---------------------------------------------------------------------------
#if(_HDMI_SUPPORT == _ON)


BYTE code s480I[] = {0x34,0x38,0x30,0x1A,0x00};
BYTE code s480P[] = {0x34,0x38,0x30,0x23,0x00};
BYTE code s576I[] = {0x35,0x37,0x36,0x1A,0x00};
BYTE code s576P[] = {0x35,0x37,0x36,0x23,0x00};
BYTE code s720P[] = {0x37,0x32,0x30,0x23,0x00};
BYTE code s1080I[] = {0x31,0x30,0x38,0x30,0x1A,0x00};
BYTE code s1080P[] = {0x31,0x30,0x38,0x30,0x23,0x00};

void CShowHDMIMode(BYTE x,BYTE y,bit bShowTable)
{        
    if (stModeInfo.IVFreq == 0) 
        return;

    if(bShowTable)
    {
        BYTE *p;
        
        switch(ucHDMIMode)
        {
        case _HM_480I:      p = s480I;      break;
        case _HM_480P:      p = s480P;      break;      
        case _HM_576I:      p = s576I;      break;
        case _HM_576P:      p = s576P;      break;
        case _HM_720P:      p = s720P;      break;
        case _HM_1080I:     p = s1080I;     break;
        case _HM_1080P:     
        default:            p = s1080P;     break;
        }
        if(x)
        {
            x = 19 - StrLen(p)/2;
            CTextOutEx(p, x, y);
            return;
        }
        
        CTextOutEx(p, x, y);
    }
    else
    {         
    	WORD ucLen;
    	WORD IHWidth_Tmp,IVHeight_Tmp;
    
    	IHWidth_Tmp  = stModeInfo.IHWidth;
    	IVHeight_Tmp = stModeInfo.IVHeight;
    
    	CScalerPageSelect(_PAGE2);
    	CScalerGetDataPortByte(_P2_HDMI_ADDR_PORT_C9, _P2_HDMI_VCR_50, 1, pData, _NON_AUTOINC);
    	stModeInfo.IVHeight = HDMI_V_Height;
    
    	if((pData[0]&0x0F) == 0x01)			// 2 times
    		stModeInfo.IHWidth = HDMI_H_Width*2;
    	else if((pData[0]&0x0F) == 0x03)	// 4 times
    		stModeInfo.IHWidth = HDMI_H_Width*4;
    	else
            stModeInfo.IHWidth = HDMI_H_Width;
    
    	ucLen = stModeInfo.IVHeight;
    	CScalerRead(_IPV_ACT_LEN_H_1A, 1, pData, _AUTOINC);
    
    	if (pData[0] & _BIT5)
    		ucLen = stModeInfo.IVHeight*2;
    
    	if (GET_INTERLACE_MODE())
        {
    		if(stModeInfo.IVFreq>=598 && stModeInfo.IVFreq<=599)			//60Hz
    			stModeInfo.IVFreq += 2;
    		else if(stModeInfo.IVFreq>=498 && stModeInfo.IVFreq<=499)	//50Hz
    			stModeInfo.IVFreq += 2;
    	}
    
        Gotoxy(x, y, BYTE_DISPLAY);
        CShowNumber1((stModeInfo.IHWidth > 1920) ? 1920 : stModeInfo.IHWidth, 0);
        OutputChar(0x2D);  // "X"
        CShowNumber1((ucLen > 1200) ? 1200 : ucLen, 0);
        OutputChar(0x2D);  // "X"
        CShowNumber1(stModeInfo.IVFreq/10, 0);
        OutputChar(0x19);  // "H"
        OutputChar(0x2F);  // "Z"
        OutputChar(0x01);  // " "
    
    	stModeInfo.IHWidth  = IHWidth_Tmp;
    	stModeInfo.IVHeight = IVHeight_Tmp;
    }
}
#endif

//---------------------------------------------------------------------------
void CShowMode(BYTE x,BYTE y)
{
    switch(_GET_INPUT_SOURCE())
    {
	#if(_HDMI_SUPPORT == _ON)
    case _SOURCE_HDMI:
//    case _SOURCE_DVI: 
        if(ucHDMIMode == _HM_OTHER)
        {
            CShowHDMIMode(x,y,0);
        }
        else
        {
            CShowHDMIMode(x,y,1);
        }
        break;
	#endif 
     
	#if(1)//_HDMI_SUPPORT == _OFF)
    case _SOURCE_DVI: 
	#endif 
    case _SOURCE_VGA:
        CShowVGAMode(x,y);     
        break;

	#if(_YPBPR_SUPPORT == _ON)
    case _SOURCE_YPBPR:
        if (stModeInfo.ModeCurr < _MAX_YPBPR_MODE)
        {
            if(!x)
                CTextOutEx(sYPbPrMode[stModeInfo.ModeCurr], x,y);
            else
                CTextOutEx(sYPbPrMode[stModeInfo.ModeCurr], (19 - StrLen(sYPbPrMode[stModeInfo.ModeCurr])/2), y);
        }
        break;
	#endif
        
	#if(_VIDEO_SUPPORT == _ON)
    case _SOURCE_VIDEO_AV:
    case _SOURCE_VIDEO_SV:
    case _SOURCE_VIDEO_YUV:
    case _SOURCE_VIDEO_SCART:
    case _SOURCE_VIDEO_TV:
        if(ucVideoType == ZNTSC || ucVideoType == ZNTSC_443 || ucVideoType == ZNTSC_50)
        {
            if(!x)
                CTextOutEx(sNTSC, x,y);
            else
                CTextOutEx(sNTSC, (19 - StrLen(sNTSC)/2), y);
        }
        else
        {
            if(!x)
                CTextOutEx(sPAL, x,y);
            else
                CTextOutEx(sPAL, (19 - StrLen(sPAL)/2), y);
        }
        break;
	#endif
        
	#if(0)//_VIDEO_TV_SUPPORT)
    case _SOURCE_VIDEO_TV:
        {
            //CShowNumber(0, 1, stTvInfo.CurChn);
            if(!x)
                CTextOutEx(sTVType[ucTVType], x,y);
            else
                CTextOutEx(sTVType[ucTVType], (19 - StrLen(sTVType[ucTVType])/2), y);
        }
        break;
	#endif
    }
}    

//---------------------------------------------------------------------------
#define _MSG_WIDTH                  (20 * 12 + 4)   
#define _MSG_HEIGHT                 (2 * 18)
void CDisplayCurrentSourceMessage(void)
{
    BYTE *pStr;
    
    ucOsdState = _MI_MENU_NONE;
    COsdFxDisableOsd();
#if(_LOGO_ENABLE)
    if (bLoadLogoFont)
    {       
        SetOsdMap(tUserMenuOsdMap);
        
        // Load global font 
        // insert code to here 
        COsdLoad1BitFont(FntGlobal,0x00,0x5F,tGlobalCharWidth);
        CScalerLoadHardwareVLCFont(FntMainIcon,0x80 * 2);
        
    	//Load Languege Font
    	LoadLanguageFont();
        bLoadLogoFont = 0;
    }
#endif
    
    SetOsdMap(tMsgOsdMap);
    COsdFxCodeWrite(ucCloseAllWindow);
    
    // Init osd
    // insert code to here
    OSDClear(ROW(0), HEIGHT(8), COL(0), WIDTH(20), 0x8C, BYTE_ATTRIB);
    OSDClear(ROW(0), HEIGHT(8), COL(0), WIDTH(20), 0x00, BYTE_DISPLAY);
    OSDClear(ROW(0), HEIGHT(8), COL(0), WIDTH(20), 0xF0, BYTE_COLOR);
    SetOSDDouble(0x03);   
    OSDPosition(_OSD_DOUBLE_WIDTH(_MSG_WIDTH), _OSD_DOUBLE_HEIGHT(_MSG_HEIGHT), 0, 0, 0x03);
    
    // TextOut
    switch(_GET_INPUT_SOURCE())
    {
    case _SOURCE_VGA:           pStr = sVGA;        break;
    case _SOURCE_DVI:           pStr = sDVI;        break;
    case _SOURCE_HDMI:          pStr = sHDMI;       break;
    case _SOURCE_YPBPR:         pStr = sYPBPR;      break;
    case _SOURCE_VIDEO_SV:      pStr = sSVideo;     break;
    case _SOURCE_VIDEO_AV:      pStr = sAV;         break;
	case _SOURCE_VIDEO_TV:		
        CShowNumber(0, 1, stTvInfo.CurChn);
        pStr = sTV;			
        break;
	}
	CTextOutEx(pStr,ROW(0),0);

    CShowMode(0, 2);

    CTimerReactiveTimerEvent(SEC(5), COsdDispOsdTimerEvent);
    COsdFxEnableOsd();
    bOSDTimeOut  = 0;
#if(_SLEEP_FUNC)
    bOSDOnScreen = 1;
#endif
    
}

//---------------------------------------------------------------------------
void CSetOSDPosition(WORD OSDWidth, WORD OSDHeight, BYTE PosX, BYTE PosY)
{
    if (GET_OSD_SIZE())
        OSDPosition(_OSD_DOUBLE_WIDTH(OSDWidth), _OSD_DOUBLE_HEIGHT(OSDHeight), PosX, PosY, 0x03);
    else
        OSDPosition(OSDWidth, OSDHeight, PosX, PosY, 0x03);
}

//----------------------------------------------------------------------------------------------------
#define _SLIDER_BEGIN				0x04
void OSDSlider(BYTE row, BYTE col, BYTE length, BYTE value, BYTE range,BYTE color) small
{
    unsigned int bound;
    unsigned char i,c;
    OSDLine(row, col, length + 6, color, THE_BYTE2);   // Set Slider Attribute. 4 extra columns for space/numbers/space
    bound   = length * value;
    
    Gotoxy(col,row,THE_BYTE1);
    OutputChar(_SLIDER_BEGIN);          // Left Border
    for (i = 1; i <= length; i++)
    {
        if (bound)
        {
            if(bound >= range)
            {
                c       = _SLIDER_BEGIN + 7;
                bound   = bound - range;
            }
            else
            {
                color   = (bound << 4) / range;
                bound   = 0;
                if (4 > color)                    c = _SLIDER_BEGIN + 2;
                else if (7 > color)               c = _SLIDER_BEGIN + 3;
                else if (10 > color)              c = _SLIDER_BEGIN + 4;
                else if (13 > color)              c = _SLIDER_BEGIN + 5;
                else                              c = _SLIDER_BEGIN + 6;
            }
        }
        else
        {
            c = _SLIDER_BEGIN + 1;
        }
        OutputChar(c);
    }
    OutputChar(_SLIDER_BEGIN + 8);    // Right Border
    CShowNumber(col + length + 2, row,value);
}                                      

//----------------------------------------------------------------------------------------------------
void CSetItemStartEnd(void (*ReDrawPageProc)(void))
{
    BYTE temp = 0;

    // Find current item start and end
    if (ucOsdState < ucStartItem)
    {
        ucStartItem = ucOsdState;
        ucEndItem   = ucStartItem + 5;
        temp = 1;
    }
    else if (ucOsdState - ucStartItem > 5)
    {
        ucStartItem = ucOsdState - 5;
        ucEndItem   = ucStartItem + 5;
        temp = 1;
    }

    if (temp)
    {
        // clear sub menu
        for(temp=0; temp<6; temp++)
        {
            OSDLine(SHOWINDEX_TO_LINE(temp), COL(7), LENGTH(38), 0x00, BYTE_DISPLAY);
            OSDLine(SHOWINDEX_TO_LINE(temp), COL(7), LENGTH(38), 0x8C, BYTE_ATTRIB);
        }
        // ReDraw page
        ReDrawPageProc();
    }
}

//----------------------------------------------------------------------------------------------------
BYTE CGetPopupMenuRow(BYTE ucBaseRowStart, ucFirstItem)
{
    BYTE ucTemp = ucBaseRowStart-((ucStartItem-ucFirstItem)*2);

    return ucTemp;
} 

#if(_CHINESE_FONT_TYPE == _CHINESE_1_FONT && _LOGO_ENABLE)
//----------------------------------------------------------
void LoadLanguageFont(void)
{
    // load language font

	switch(GET_LANGUAGE())
	{
	#if(LNG_JAP_EN)
		case LNG_JAP:
            COsdLoad1BitFont(FntJap,0x80,0x57,tFntJapCharWidth);
            break;
    #endif
    #if(LNG_KOR_EN)
        case LNG_KOR:
            COsdLoad1BitFont(FntKor,0x80,0x68,tFntKorCharWidth);
            break;
    #endif
    #if(LNG_RUS_EN)
		case LNG_RUS:
			COsdLoad1BitFont(FntRus,0x80,0x21,tFntRusCharWidth);
            break;
    #endif
#if(_CHINESE_FONT_TYPE == _CHINESE_1_FONT)
    #if(LNG_CHI_S_EN)
		case LNG_CHI_S:
			COsdLoad1BitFontWidth12(tFntChiGlobal,0x80,0x34);
			COsdLoad1BitFontWidth12(tFntChiS,0xC0,0x1D);
            break;
    #endif
    #if(LNG_CHI_T_EN)
		case LNG_CHI_T:
			COsdLoad1BitFontWidth12(tFntChiGlobal,0x80,0x34);
			COsdLoad1BitFontWidth12(tFntChiT,0xC0,0x1D);
            break;
    #endif
#endif
	}

}  
#endif

#endif      //#if(_OSD_TYPE == _OSD003)
