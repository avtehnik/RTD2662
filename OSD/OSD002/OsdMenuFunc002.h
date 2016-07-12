#if(_OSD_TYPE == _OSD002)

#define _SHOW_NUM_POS_X       11
#define _SHOW_NUM_POS_Y       18

#ifdef __OSDDRAW002__

#else

#endif


// extand function & Var
void CDrawNull(BYTE ucDrawID);
bit  CMIVedio8Enable(void);
bit CMIVedioEnable(void);
bit CMIVGAEnable(void);
bit CMITVEnable(void);
bit CMITVFMEnable(void);

void CClearSubMenu(void);
void Draw2bit3x2Icon(BYTE *tIcon,BYTE x,BYTE y);
void SubMenuItemSelect(BYTE ucItem);
void SubMenuItemClr(BYTE ucItem);
void CClearAdjustMenu(void);


// Page darw func
void CCloseOSD(BYTE ucDrawID);
void CPDrawMainMenu(BYTE ucDrawID);
void CPDrawColorMenu(BYTE ucDrawID);
void CPDrawAdjustMenu(BYTE ucDrawID);
void CPDrawOsdMenu(BYTE ucDrawID);
void CPDrawTVMenu(BYTE ucDrawID);
void CPDrawFuncMenu(BYTE ucDrawID);


// main menu Item
void CMIDrawCOLOR(BYTE ucDrawID);
void CMICOLORRun(BYTE ucMode);
void CMIDrawADJUST(BYTE ucDrawID);
void CMIADJUSTRun(BYTE ucMode);
void CMIDrawOSD(BYTE ucDrawID);
void CMIOSDRun(BYTE ucMode);
void CMIDrawTV(BYTE ucDrawID);
void CMITVRun(BYTE ucMode);
void CMIDrawFUNCTION(BYTE ucDrawID);
void CMIFUNCTIONRun(BYTE ucMode);
void CMIDrawEXIT(BYTE ucDrawID);
void CMIEXITRun(BYTE ucMode);

// Color page function
void CMIDrawBrightness(BYTE ucDrawID);
void CMIBrightnessRun(BYTE ucMode);
void CMIDrawContrast(BYTE ucDrawID);
void CMIContrastRun(BYTE ucMode);
void CMIDrawHue(BYTE ucDrawID);
void CMIHueRun(BYTE ucMode);
void CMIDrawSaturation(BYTE ucDrawID);
void CMISaturationRun(BYTE ucMode);
void CMIDrawColorTemp(BYTE ucDrawID);
void CMIColorTempRun(BYTE ucMode);
void CMIDrawColorReturn(BYTE ucDrawID);
void CMIColorReturnRun(BYTE ucMode);

// Adjust Menu function
void CMIDrawAutoConfig(BYTE ucDrawID);
void CMIAutoConfigRun(BYTE ucMode);
void CMIDrawHPosition(BYTE ucDrawID);
void CMIHPositionRun(BYTE ucMode);
void CMIDrawVPosition(BYTE ucDrawID);
void CMIVPositionRun(BYTE ucMode);
void CMIDrawPhase(BYTE ucDrawID);
void CMIPhaseRun(BYTE ucMode);
void CMIDrawClock(BYTE ucDrawID);
void CMIClockRun(BYTE ucMode);
void CMIDrawAdjustReturn(BYTE ucDrawID);
void CMIAdjustReturnRun(BYTE ucMode);

// OSD Page function
void CMIDrawLanguage(BYTE ucDrawID);
void CMILanguageRun(BYTE ucMode);
void CMIDrawOSDHPosition(BYTE ucDrawID);
void CMIOSDHPositionRun(BYTE ucMode);
void CMIDrawOSDVPosition(BYTE ucDrawID);
void CMIOSDVPositionRun(BYTE ucMode);
void CMIDrawTimer(BYTE ucDrawID);
void CMITimerRun(BYTE ucMode);
void CMIDrawDouble(BYTE ucDrawID);
void CMIDoubleRun(BYTE ucMode);
void CMIDrawTransparent(BYTE ucDrawID);
void CMITransparentRun(BYTE ucMode);
void CMIDrawOsdReturn(BYTE ucDrawID);
void CMIOsdReturnRun(BYTE ucMode);

// TV page function
void CMIDrawSystem(BYTE ucDrawID);
void CMISystemRun(BYTE ucMode);

void CMIDrawChannel(BYTE ucDrawID);
void CMIChannelRun(BYTE ucMode);

void CMIDrawAutoSearch(BYTE ucDrawID);
void CMIAutoSearchRun(BYTE ucMode);
bit CKeyStopAutoSearch(void);
void CShowAutoSerachTotal(BYTE ucSearchTotal);
void CShowFreq(WORD iFreqN);
void CShowCurrentChannelFreq(void);
void CShowAutoSearchSliderInOSD(WORD ucCurrentValue);

void CMIDrawManualSearch(BYTE ucDrawID);
void CMIManualSearchRun(BYTE ucMode);

void CMIDrawTuning(BYTE ucDrawID);
void CMITuningRun(BYTE ucMode);

void CMIDrawSkip(BYTE ucDrawID);
void CMISkipRun(BYTE ucMode);

void CMIDrawAutoPowerDown(BYTE ucDrawID);
void CMIAutoPowerDownRun(BYTE ucMode);

void CMIDrawBlueScreen(BYTE ucDrawID);
void CMIBlueScreenRun(BYTE ucMode);

void CMIDrawTVReturn(BYTE ucDrawID);
void CMITVReturnRun(BYTE ucMode);

// Func page function
void CMIDrawReset(BYTE ucDrawID);
void CMIResetRun(BYTE ucMode);

void CMIDrawDisplayRatio(BYTE ucDrawID);
void CMIDisplayRatioRun(BYTE ucMode);

void CMIDrawVolume(BYTE ucDrawID);
void CMIVolumeRun(BYTE ucMode);

void CMIDrawMute(BYTE ucDrawID);
void CMIMuteRun(BYTE ucMode);

void CMIDrawBalance(BYTE ucDrawID);
void CMIBalanceRun(BYTE ucMode);

void CMIDrawBass(BYTE ucDrawID);
void CMIBassRun(BYTE ucMode);

void CMIDrawTreble(BYTE ucDrawID);
void CMITrebleRun(BYTE ucMode);

void CMIDrawSRS(BYTE ucDrawID);
void CMISRSRun(BYTE ucMode);

void CMIDrawBBE(BYTE ucDrawID);
void CMIBBERun(BYTE ucMode);

void CMIDrawFM(BYTE ucDrawID);
void CMIFMRun(BYTE ucMode);

void CMIDrawFuncReturn(BYTE ucDrawID);
void CMIFuncReturnRun(BYTE ucMode);


//======= Shortcut key Menu ===========
void CPDrawShowMenu(BYTE ucDrawID);

void CMIDrawSMBright(BYTE ucDrawID);
void CMISMBrightRun(BYTE ucMode);

void CMIDrawSMVolume(BYTE ucDrawID);
void CMISMVolumeRun(BYTE ucMode);

void CMIDrawSMMute(BYTE ucDrawID);
void CMISMMuteRun(BYTE ucMode);

void CMIDrawSMInputCh(BYTE ucDrawID);
void CMISMInputChRun(BYTE ucMode);
void SInceptNumber(const WORD ucNumber);
void SShowCurrentInputState(WORD ucInputState);

//================= end ================



#endif		//#if(_OSD_TYPE == _OSD002)
