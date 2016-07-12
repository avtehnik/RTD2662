#if(_OSD_TYPE == _OSD001)

#define CURRENT_MENU			g_tMenu[g_ucPageIndex]
#define CURRENT_MENU_ITEM       g_tMenu[g_ucPageIndex].Menu[g_ucMenuItemIndex]

//---- language type define--------------
#define ENGLISH                     0
#define LNG_DEU                     1
#define LNG_FRA                     2
#define LNG_ITA                     3
#define LNG_ESP                     4
#define LNG_JAP                     5
#define LNG_CHI_S                   6
#define LNG_CHI_T                   7

//---- language mask---------------------
#define ENGLISH_EN                  1
#define LNG_FRA_EN                  0
#define LNG_ITA_EN                  0
#define LNG_DEU_EN                  0
#define LNG_ESP_EN                  0
#define LNG_JAP_EN                  0
#define LNG_CHI_S_EN                0
#define LNG_CHI_T_EN                0


#ifdef __OSDPROC001__

//SMenu *g_pMenu = &tMenuNone;
BYTE g_ucPageIndex = 0;
BYTE g_ucMenuItemIndex = 0;
BYTE ucOSDAdjTemp = 0;
WORD code usLANGUAGE_MASK  =  ( ENGLISH_EN   << ENGLISH ) |
                              ( LNG_FRA_EN   << LNG_FRA ) |
                              ( LNG_ITA_EN   << LNG_ITA ) |
                              ( LNG_DEU_EN   << LNG_DEU ) |
                              ( LNG_ESP_EN   << LNG_ESP ) |
                              ( LNG_JAP_EN   << LNG_JAP ) |
                              ( LNG_CHI_S_EN << LNG_CHI_S ) |
                              ( LNG_CHI_T_EN << LNG_CHI_T );  


#else  

//extern SMenu *g_pMenu;
extern BYTE g_ucPageIndex;
extern BYTE g_ucMenuItemIndex;
extern BYTE ucOSDAdjTemp;
extern WORD code usLANGUAGE_MASK;

#endif
// extand function & Var


void COsdHandler(void);
void CNotUse(void);

void COsdSystemFlowProc(void);
void COsdEventMsgProc(void);
void COsdDispFirstTimeLoadFont(void);
void COsdDispOsdTimerEvent(void);
BYTE CFoundKeyMsgToOsdEvent(SKeyToOsdEvent *tMsgTable);
void CCoverKeyMsgToOsdEvent(SKeyToOsdEvent *tMsgTable,BYTE bUserPublicKeyEvnet);
void CDrawCurrentMenu(void);
bit CEnable(void);
void CMenuProc(void);
void CChangeMenuItem(BYTE ucMode);
void CEnterSubMenu(void);
void CReturnUpMenu(void);
void CMenuRun(BYTE ucMode);
void InitOsdFrame(void);
void CClearClientOSD(void);
void OSDSlider(BYTE row, BYTE col, BYTE length, BYTE value, BYTE range,BYTE color);
void CShowNote(void);
void CShowNoSignal(void);

void DbgShowOSDState(void);





#endif		//#if(_OSD_TYPE == _OSD001)

