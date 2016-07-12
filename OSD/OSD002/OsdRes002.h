#if(_OSD_TYPE == _OSD002)


#define _MAINMENU_WIDTH					25
#define _MAINMENU_HEIGHT				22


#ifdef __OSDRES002__

#else
extern BYTE code tUserMenuOsdMap[];
extern BYTE code tMainWindowStyle[];
extern BYTE code tNoteWindowStyle[];
extern BYTE code tSubMenuItemSelectWindowStyle[];
extern BYTE code tAdjustWindowStyle[];
extern BYTE code tPALETTE_0[];

extern code BYTE *tColorPalettes[];

extern BYTE code tColorIco_Normal[];
extern BYTE code tColorIco_Select[];
extern BYTE code tColorIco_Disable[];
extern BYTE code tColorIco_Sel1[];
                 
extern code BYTE sSourceVGA[];
extern code BYTE sSourceAV[];
extern code BYTE sSourceSV[];
extern code BYTE sSourceTV[];
extern code BYTE sSourceDVI[];
extern code BYTE sSourceHDMI[];
extern code BYTE sSourceYPBPR[];

extern BYTE code tAdjustIco_Normal[];
extern BYTE code tAdjustIco_Select[];
extern BYTE code tAdjustIco_Disable[];
extern BYTE code tAdjustIco_Sel1[];
                 
extern BYTE code tOsdIco_Normal[];
extern BYTE code tOsdIco_Select[];
extern BYTE code tOsdIco_Disable[];
extern BYTE code tOsdIco_Sel1[];
                 
extern BYTE code tTVIco_Normal[];
extern BYTE code tTVIco_Select[];
extern BYTE code tTVIco_Disable[];
extern BYTE code tTVIco_Sel1[];
                 
extern BYTE code tFuncIco_Normal[];
extern BYTE code tFuncIco_Select[];
extern BYTE code tFuncIco_Disable[];
extern BYTE code tFuncIco_Sel1[];
                 
extern BYTE code tExitIco_Normal[];
extern BYTE code tExitIco_Select[];
extern BYTE code tExitIco_Disable[];
extern BYTE code tExitIco_Sel1[]; 

extern code BYTE *sAutoConfig[];
extern code BYTE *sAutoPowerDown[];
extern code BYTE *sAutoSearch[];
extern code BYTE *sBalance[];
extern code BYTE *sBass[];
extern code BYTE *sBBE[];
extern code BYTE *sBlueScreen[];
extern code BYTE *sBrightness[];
extern code BYTE *sChannel[];
extern code BYTE *sClock[];
extern code BYTE *sColorTemp[];
extern code BYTE *sContrast[];
extern code BYTE *sDisplayRatio[];
extern code BYTE *sDouble[];
extern code BYTE *sHPosition[];
extern code BYTE *sHue[];
extern code BYTE *sLanguage[];
extern code BYTE *sMSearch[];
extern code BYTE *sMute[];
extern code BYTE *sPhase[];
extern code BYTE *sReset[];
extern code BYTE *sReturn[];
extern code BYTE *sSaturation[];
extern code BYTE *sSkip[];
extern code BYTE *sSRS[];
extern code BYTE *sSystem[];
extern code BYTE *sTimer[];
extern code BYTE *sTransparent[];
extern code BYTE *sTreble[];
extern code BYTE *sTuning[];
extern code BYTE *sVPosition[];
extern code BYTE *sVolume[];
extern code BYTE *sLanguageName[];
extern code BYTE *sOn[];
extern code BYTE *sOff[];
extern code BYTE *SOnOff[2][10];
extern code BYTE *sNoSignal[];
extern code BYTE *sNotsupport[];
extern code BYTE *sNoCable[];
extern code BYTE *sColor[];
extern code BYTE *sAdjust[];
extern code BYTE *sTV[];
extern code BYTE *sOSD[];
extern code BYTE *sFunction[];
extern code BYTE *sExit[];

extern code BYTE * sTVType[14];
extern code BYTE sPAL[];
extern code BYTE sNTSC[];
extern code BYTE * sFull[];
extern code BYTE * sDM4_3[];
extern code BYTE * sColorTempType[5];
extern code BYTE sFM[];
extern code BYTE * sYPbPrMode[];

extern code BYTE tSelectIcon[];

extern BYTE code tFntGlobalCharWidth[];
extern BYTE code tFntChi_SCharWidth[];
extern BYTE code tFntChi_TCharWidth[];
extern BYTE code tFntRusCharWidth[];
extern BYTE code tFntJapCharWidth[];
extern BYTE code tFntKorCharWidth[];
extern BYTE code tFntVolumeCharWidth[];
extern BYTE code FntGlobal[];
extern BYTE code FntChi_S[];
extern BYTE code FntChi_T[];
extern BYTE code FntRus[];
extern BYTE code FntJap[];
extern BYTE code FntKor[];
extern BYTE code FntMainIcon[];
extern BYTE code FntVolume[];
extern BYTE code FntMute[];

#endif				//#ifdef __OSDRES001__


// extand function & Var

#endif		//#if(_OSD_TYPE == _OSD002)
