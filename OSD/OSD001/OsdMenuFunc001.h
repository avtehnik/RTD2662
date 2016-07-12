#if(_OSD_TYPE == _OSD001)


#ifdef __OSDDRAW001__

#else

#endif


// extand function & Var
void CDrawNull(BYTE ucDrawID);
bit  CMIVedio8Enable(void);
bit  CMIVGAEnable(void);
bit  CMITVEnable(void);
void CPDrawMainMenu(BYTE ucDrawID);
void CClearMsg(void);

void CMIMenuNoneRun(BYTE ucMode);

void CMIDrawBrightness(BYTE ucDrawID);
void CMIBrightnessRun(BYTE ucMode);

void CMIDrawContrast(BYTE ucDrawID);
void CMIContrastRun(BYTE ucMode);

void CMIHueRun(BYTE ucMode);
void CMIDrawHue(BYTE ucDrawID);

void CMIDrawSaturation(BYTE ucDrawID);
void CMISaturationRun(BYTE ucMode);

void CMIDrawPhase(BYTE ucDrawID);
void CMIPhaseRun(BYTE ucMode);

void CMIDrawClock(BYTE ucDrawID);
void CMIClockRun(BYTE ucMode);

void CMIDrawAutoAdjust(BYTE ucDrawID);
void CMIAutoAdjustRun(BYTE ucMode);

void CDrawDisplayModeState(void);
void CMIDrawDisplayMode(BYTE ucDrawID);
void CMIDisplayModeRun(BYTE ucMode);

void CMIDrawAutoSearch(BYTE ucDrawID);
void CShowFreq(WORD iFreqN);
void CShowCurrentChannelFreq(void);
void CShowAutoSearchSliderInOSD(WORD ucCurrentValue);
void CMIAutoSearchRun(BYTE ucMode);
void CShowAutoSerachTotal(BYTE ucSearchTotal);

void CMIDrawManualSearch(BYTE ucDrawID);
void CMIManualSearchRun(BYTE ucMode);

void CMIDrawTunning(BYTE ucDrawID);
void CMITunningRun(BYTE ucMode);

void CMIDrawTVSystem(BYTE ucDrawID);
void CMITVSystemRun(BYTE ucMode);

void CMIDrawSwap(BYTE ucDrawID);
void CMISwapRun(BYTE ucMode);

void CMIDrawChannel(BYTE ucDrawID);
void CMIChannelRun(BYTE ucMode);

void CMIDrawSkip(BYTE ucDrawID);
void CMISkipRun(BYTE ucMode);

void CMIDrawLanguage(BYTE ucDrawID);
void CMILanguageRun(BYTE ucMode);

void CMIDrawBlue(BYTE ucDrawID);
void CMIBlueRun(BYTE ucMode);

void CMIDrawVolume(BYTE ucDrawID);
void CMIVolumeRun(BYTE ucMode);



void CMIDrawExit(BYTE ucDrawID);
void CMIExitRun(BYTE ucMode);



void CPDrawSCMenu(BYTE ucDrawID);

void CDrawSCMute(BYTE ucDrawID);
void CSCMuteRun(BYTE ucMode);



void CDrawMuteState(void);
void CSetMuteState(void);
void CShowTVNumber(BYTE ucNumber, BYTE ucOption);

#endif		//#if(_OSD_TYPE == _OSD001)