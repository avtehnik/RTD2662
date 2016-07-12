#if(_OSD_TYPE == _OSD002)


#define _SHOW_TV_NO_SIGNAL      0

#define CURRENT_MENU			g_tMenu[g_ucPageIndex]
#define CURRENT_MENU_ITEM       g_tMenu[g_ucPageIndex].Menu[g_ucMenuItemIndex]


// Menu func define
#define FMI_DISABLE_MENIITEM_LINE(x)				OSDLine(ROW(x), COL(5), LENGTH(26), 0x50, BYTE_COLOR)	
#define FMI_DRAW_PAGE_TITLE(str)					CCenterTextout(str,ROW(4),COL(0),WIDTH(25))

#define DRAW_SLIDER(value)							OSDSlider(ROW(18), COL(4), LENGTH(12), value, 100, 0x60)
#define DRAW_DIALOG_SLIDER(value)					OSDSlider(ROW(2),  COL(3), LENGTH(12), value, 100, 0x60)

#define _DIALOG_WIDTH								25
#define _DIALOG_HEIGHT								3


//---- language type define--------------
#define ENGLISH                     0
#define LNG_FRA                     1
#define LNG_ITA                     2
#define LNG_DEU                     3
#define LNG_ESP                     4
#define LNG_CHI_S                   5
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
#define LNG_JAP_EN                  1
#define LNG_KOR_EN                  1
#define LNG_RUS_EN                  1


#ifdef __OSDPROC002__

bit bOSDOnScreen = 0;
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

//SMenu *g_pMenu = &tMenuNone;
BYTE g_ucPageIndex = 0;
BYTE g_ucMenuItemIndex = 0;


#else

extern bit bOSDOnScreen;
//extern SMenu *g_pMenu;
extern BYTE g_ucPageIndex;
extern BYTE g_ucMenuItemIndex;
extern WORD code usLANGUAGE_MASK;


#endif
// extand function & Var

void COsdHandler(void);
void CNotUse(void);

void COsdSystemFlowProc(void);
void COsdEventMsgProc(void);
void COsdDispOsdTimerEvent(void);
BYTE CFoundKeyMsgToOsdEvent(SKeyToOsdEvent *tMsgTable);
void CCoverKeyMsgToOsdEvent(SKeyToOsdEvent *tMsgTable,BYTE bUserPublicKeyEvnet);
void CDrawCurrentMenu(void) small;
void CDrawSubMenu(void) small;
bit CEnable(void);
//bit CDisable(void);
void CMenuProc(void);
void CChangeMenuItem(BYTE ucMode);
void CEnterSubMenu(void);
void CReturnUpMenu(void);
void CMenuRun(BYTE ucMode);

void InitOsdFrame(void);
void OSDSlider(BYTE row, BYTE col, BYTE length, BYTE value, BYTE range,BYTE color);

void DbgShowOSDState(void);

void DrawExitPage(void);
void DrawFuncPage(void);
void DrawTvPage(void);
void DrawOsdPage(void);
void DrawAdjustPage(void);
void DrawColorPage(void);
void DrawMainPage(void);

void CShowNote(void);
void CShowNoSignal(void);

#endif		//#if(_OSD_TYPE == _OSD002)

