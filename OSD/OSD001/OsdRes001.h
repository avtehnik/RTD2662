#if(_OSD_TYPE == _OSD001)

#define _MAINMENU_WIDTH					20
#define _MAINMENU_HEIGHT				3

#ifdef __OSDRES001__

#else
extern BYTE code tUserMenuOsdMap[];
extern BYTE code tOSD_WINDOW4_STYLE[];
extern BYTE code tPALETTE_0[];

extern code BYTE sSourceVGA[];
extern code BYTE sSourceAV[];
extern code BYTE sSourceSV[];
extern code BYTE sSourceTV[];
extern code BYTE sSourceDVI[];
extern code BYTE sSourceHDMI[];
extern code BYTE sSourceYPBPR[];
extern code BYTE * sNosignal[];

extern code BYTE * sBrightness[];
extern code BYTE * sContrast[];
extern code BYTE * sHue[];
extern code BYTE * sSaturation[];
extern code BYTE * sPhase[];
extern code BYTE * sClock[];
extern code BYTE * sLanguage[];
extern code BYTE * sAutoAdjust[];
extern code BYTE * sAutoAdjusting[];
extern code BYTE * sAutoSearch[];
extern code BYTE * sExit[];
extern code BYTE * sDisplayMode[];
extern code BYTE * sFull[];
extern code BYTE * sDM4_3[];
#if(_VIDEO_TV_SUPPORT)
extern code BYTE sMhz[];
extern code BYTE sPixel[];
extern code BYTE * sAutoSearch[];
extern code BYTE * sManualSearch[];
extern code BYTE * sTunning[];
extern code BYTE * sSwap[];
extern code BYTE * sChannel[];
extern code BYTE * sSkip[];
extern code BYTE * sTVSystem[];
extern code BYTE * sTVType[14];
#endif //#if(_VIDEO_TV_SUPPORT)
extern code BYTE * sLanguage[];
extern code BYTE * sBlue[];
extern code BYTE * sVolume[];
extern code BYTE * sOnOff[2][8];
extern code BYTE * sLanguageName[];

extern BYTE code tFntGlobalCharWidth[];
extern BYTE code tFntVolumeCharWidth[];
extern BYTE code FntGlobal[];
extern BYTE code FntVolume[];
extern BYTE code FntMute[];

#endif				//#ifdef __OSDRES001__


// extand function & Var

#endif		//#if(_OSD_TYPE == _OSD001)