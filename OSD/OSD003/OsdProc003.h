#if(_OSD_TYPE == _OSD003)


//---------------------------------------
// TV no signal show "No Signal" definition
#define _SHOW_TV_NO_SIGNAL          1

//---------------------------------------
// For change source method
#define _CHANGE_SOURCE_METHOD_0     0
#define _CHANGE_SOURCE_METHOD_1     1

#define _CHANGE_SOURCE_METHOD       _CHANGE_SOURCE_METHOD_0

//---------------------------------------
// For chinese font width select
/*      BL.lin
      _CHINESE_1_FONT -> Mark	LoadCHI_T_Font ~ ?PR?OSDPROC003,
	                     Mark   LoadCHI_S_Font ~ ?PR?OSDPROC003
*/
#define _CHINESE_1_FONT             0
#define _CHINESE_2_FONT             1

#define _CHINESE_FONT_TYPE          _CHINESE_2_FONT

// Menu func define
#define CURRENT_MENU_ITEM			g_tMenuItem[ucOsdState]

//---- language type define--------------
#define ENGLISH                     0
#define LNG_CHI_S                   1
#define LNG_FRA                     2
#define LNG_ITA                     3
#define LNG_DEU                     4
#define LNG_ESP                     5
#define LNG_CHI_T                   6
#define LNG_JAP                     7
#define LNG_KOR                     8
#define LNG_RUS                     9

//---- language mask---------------------
#define ENGLISH_EN                  1
#define LNG_FRA_EN                  1
#define LNG_ITA_EN                  1
#define LNG_DEU_EN                  1
#define LNG_ESP_EN                  1
#define LNG_CHI_S_EN                1
#define LNG_CHI_T_EN                1
#define LNG_JAP_EN                  0
#define LNG_KOR_EN                  0
#define LNG_RUS_EN                  1

#define _LANGUAGE_CNT				10
#define _NOT_SHOW					0xFF

#define _ST_NORMAL					1
#define _ST_SELECT					2
#define _ST_DISABLE					3
#define _ST_ADJUST					4



#define _LF_COLOR_PAGE				0
#define _LF_ADJUST_PAGE				1
#define _LF_OSD_PAGE				2
#define _LF_TV_PAGE					3
#define _LF_FUNC_PAGE				4
#define _LF_SOUND_PAGE				5
#define _LF_OTHER					6

#define BEGIN(x)					x
#define END(x)						x

#define _MAINMENU_WIDTH					            (WIDTH(39)* 12)		
#define _MAINMENU_HEIGHT				            (HEIGHT(18) * 18)

                                        
#define _OSD_DOUBLE_WIDTH(width)                    (width + (Panel[ucPanelSelect]->DHWidth/2) + 40)
#define _OSD_DOUBLE_HEIGHT(height)                  (height + (Panel[ucPanelSelect]->DVHeight/2) + 8)

#define _DIALOG_WIDTH				                (27 * 12) + 20		
#define _DIALOG_HEIGHT				                (7 * 18 - 4)

#define _LOGO_WIDTH                                 (21*12)
#define _LOGO_HEIGHT                                (6*18)

// 20 : SubMenuItem Str Max Length
// 14 * 12 : SubMenuItem Str 显示长度为 14 格的宽度
#define SUBMENU_TEXTOUT(str,row)			        TextOutCalcWidth(str,row,7,20,14 * 12)
#define SUBMENU_TEXTOUT1(str,row)			        CTextOutEx(str, 2, row)

#define SUBMENU_LINECOLOR(row,color)		        OSDLine(row, COL(7), LENGTH(38), color, BYTE_COLOR)
#define SUBMENU_LINECOLOR1(row,color)		        OSDLine(row, COL(2), LENGTH(10), color, BYTE_COLOR)

#define _MENU_NORMAL_COLOR					        0x40
#define _MENU_SECECT_COLOR					        0x10
#define _MENU_DISABLE_COLOR					        0x70
#define _MENU_ADJUST_COLOR					        0x20


//#define OSD_SLIDER(row,value,color)			OSDSlider(row, 33, 5, value, 100,color)
#define OSD_SLIDER(row,value,color)			        OSDSlider(row, 30, 10, value, 100,color)

#define DRAW_SUBMENU_SELLINE(y)				        OSDLine(y, COL(7), LENGTH(31), 0x0D, BYTE_DISPLAY)
#define CLEAR_SUBMENU_SELLINE(y)			        OSDLine(y, COL(7), LENGTH(31), 0x00, BYTE_DISPLAY)
#define SETCOLOR_SUBMENU_SELLINE(y)			        OSDLine(y, COL(7), LENGTH(31), 0x20, BYTE_COLOR)
#define SETCOLOR_FACMAINMENU_SELLINE(y,color)       OSDLine(y, COL(1), LENGTH(14), color, BYTE_COLOR)
#define SETCOLOR_FACMAINMENU_NORLINE(y,color)       OSDLine(y, COL(1), LENGTH(35), color, BYTE_COLOR)

#define DRAW_SUBMENU_SELLINE1(y)			        OSDLine(y, COL(2), LENGTH(6), 0x0D, BYTE_DISPLAY)
#define CLEAR_SUBMENU_SELLINE1(y)			        OSDLine(y, COL(2), LENGTH(6), 0x00, BYTE_DISPLAY)
#define SETCOLOR_SUBMENU_SELLINE1(y)		        OSDLine(y, COL(2), LENGTH(6), 0x20, BYTE_COLOR)

#define SHOWINDEX_TO_LINE(y)				        (4 + y * 2)
#define SHOWINDEX_TO_LINE1(y)				        (1 + y * 2)

#define _MSG_COL                                    34
//#define SUBMENU_RIGHT_TEXTOUT(str,y)				CCenterTextout(str, y, COL(27), WIDTH(17))
#define SUBMENU_RIGHT_TEXTOUT(str,y)				CTextOutEx(str, COL(_MSG_COL), y)

#ifdef __OSDPROC003__

bit bOSDOnScreen = 0;
bit bDrawMute    = 0;
#if(_SHOW_TV_NO_SIGNAL)
BYTE ucSignalOSDState = 0;
#endif
WORD code usLANGUAGE_MASK  =  ( ENGLISH_EN   << ENGLISH ) |
                              ( LNG_FRA_EN   << LNG_FRA ) |
                              ( LNG_ITA_EN   << LNG_ITA ) |
                              ( LNG_DEU_EN   << LNG_DEU ) |
                              ( LNG_ESP_EN   << LNG_ESP ) |
                              ( LNG_CHI_S_EN << LNG_CHI_S ) |
                              ( LNG_CHI_T_EN << LNG_CHI_T ) |  
                              ( LNG_JAP_EN   << LNG_JAP ) |
                              ( LNG_KOR_EN   << LNG_KOR ) |
                              ( LNG_RUS_EN   << LNG_RUS );




#if(_VIDEO_TV_SUPPORT)
BYTE ucNoSigCount = 0;
#if(_SHOW_TV_NO_SIGNAL)
BYTE data ucLogoMoveCount = 0;
#endif
#endif

#if(_LOGO_ENABLE)
bit bLoadLogoFont = 0;
#endif
BYTE ucStartItem = 0;
BYTE ucEndItem   = 0;
    

#else

extern bit bOSDOnScreen;
extern bit bDrawMute;
#if(_SHOW_TV_NO_SIGNAL)
extern BYTE ucSignalOSDState;
extern BYTE data ucLogoMoveCount;
#endif
extern WORD code usLANGUAGE_MASK;

#if(_LOGO_ENABLE)
extern bit bLoadLogoFont;
#endif
extern BYTE ucStartItem;
extern BYTE ucEndItem;

#endif
// extand function & Var


void COsdHandler(void);
void CNotUse(void);

void CKeyOSDMsgCover(void);

void COsdSystemFlowProc(void);
void COsdEventMsgProc(void);

void COsdDispFirstTimeLoadFont(void);
#if(_CHINESE_FONT_TYPE == _CHINESE_2_FONT)
void LoadLanguageFont();
void LoadCHIFont(BYTE ucPage);
void LoadCHI_T_Font(BYTE ucPage);
void LoadCHI_S_Font(BYTE ucPage);
#endif

void COsdDispOsdTimerEvent(void);
void InitOsdFrame(void);
BYTE CFoundKeyMsgToOsdEvent(SKeyToOsdEvent *tMsgTable);
void CCoverKeyMsgToOsdEvent(SKeyToOsdEvent *tMsgTable,BYTE bUserPublicKeyEvnet);
void DbgShowOSDState(void);
void CShowNote(void);
void CShowNoSignal(void);
void CShowAutoAdjust(void);
void CShowTVNumber(BYTE ucNumber, BYTE ucOption);


BYTE AdjustMenuItem(BYTE ucBeginItem,BYTE ucEndItem,BYTE ucMode);
BYTE GetShowIndex(BYTE ucMenuItem,BYTE ucBeginItem,BYTE ucEndItem);
BYTE GetShowCount(BYTE ucBeginItem,BYTE ucEndItem);

void Draw2bit3x2Icon(BYTE *tIcon,BYTE x,BYTE y);
void TextOutCalcWidth(BYTE *pStr,BYTE row,BYTE col,BYTE ucMaxLength,BYTE ucDisplayPixcel);

void COsdLoad1BitFontWidth12(BYTE *pFont,WORD usOffset,BYTE ucFntCount);

//---------------------------------------------------------------------------
void CDrawMuteState(void);
void CSetMuteState(void);
void ChangeSourceState(void);
void CCheckTVSignal(void);

void CDrawLogo(BYTE ucDouble);
void CPattenChange(void);

#endif		//#if(_OSD_TYPE == _OSD003)

