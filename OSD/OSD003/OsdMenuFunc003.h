#if(_OSD_TYPE == _OSD003)

#ifdef __OSDDRAW003__

#else

#endif

// extand function & Var
bit CEnable(void);
bit CVideoEnable(void);
bit CVideoNTSCEnable(void);
bit CVgaEnable(void);
bit CHDMIEnable(void);
bit CDviEnable(void);
bit CTVEnable(void);

bit CMIVgaEnable(void);
bit CMIDVIEnable(void);
bit CMIHDMIEnable(void);
bit CMIYPBPREnable(void);
bit CMISVEnable(void);
bit CMIAVEnable(void);
bit CMITVEnable(void);

bit CEngEnable(void);
bit CCHI_S_Enable(void);
bit CFRA_Enable(void);
bit CITA_Enable(void);
bit CDEU_Enable(void);
bit CESP_Enable(void);
bit CCHI_T_Enable(void);
bit CJAP_Enable(void);
bit CKOR_Enable(void);
bit CRUS_Enable(void);

bit CEnNtsc_M(void);
bit CEnNtsc_BG(void);
bit CEnNtsc_DK(void);
bit CEnNtsc_I(void);
bit CEnPal_M(void);
bit CEnPal_BG(void);
bit CEnPal_DK(void);
bit CEnPal_I(void);
bit CEnPal_N(void);
bit CEnSecam_BG(void);
bit CEnSecam_DK(void);
bit CEnSecam_L(void);
bit CEnSecam_LL(void);
bit COSDDoubleEN(void);
bit CAFCEnable(void);

void CShowVGAMode(BYTE x,BYTE y);
void CShowMode(BYTE x,BYTE y);

void InitMainOsd(void);
void DrawMainMenuItem(BYTE ucItem,BYTE ucState);
void DrawMainItemTitle(BYTE ucItem);
void DrawMainMenu(void);
void DrawColorPage(void);
void DrawAdjustPage(void);
void DrawOSDPage(void);
void DrawTVPage(void);
void DrawFuncPage(void);
void DrawSoundPage(void);
void DrawSubMenu(BYTE ucPageIndex);


bit MDisplayRatioEnable(void);
bit MSoundEnable(void);
bit MNJW1144Enable(void);

void MMenuNoneProc(void);
void MMenuNoneEnterSubMenu(void);
//---------------------------------------------------------------------------
// MainMenu
void MMainMenuProc(void);
void MMainMenuValueAdj(BYTE ucMode);
void MMainMenuMenuAdj(BYTE ucMode);
void MMainMenuEnterSubMenu(void);
void MMainMenuReturnUpMenu(void);
//---------------------------------------------------------------------------
// Color
void MColorProc(void);
void MColorValueAdj(BYTE ucMode);
void MColorMenuAdj(BYTE ucMode);
void MColorEnterSubMenu(void);
void MColorReturnUpMenu(void);
//---------------------------------------------------------------------------
// Brightness Adjust
void MBrightnessProc(void);
void MBrightnessValueAdj(BYTE ucMode);
void MBrightnessReturnUpMenu(void);
//---------------------------------------------------------------------------
// Contrast Adjust
void MContrastProc(void);
void MContrastValueAdj(BYTE ucMode);
void MContrastReturnUpMenu(void);
//---------------------------------------------------------------------------
// Hue Adjust
void MHueProc(void);
void MHueValueAdj(BYTE ucMode);
void MHueReturnUpMenu(void);
//---------------------------------------------------------------------------
// Saturation Adjust
void MSaturationProc(void);
void MSaturationValueAdj(BYTE ucMode);
void MSaturationReturnUpMenu(void);
//---------------------------------------------------------------------------
// ColorTemp
void EnterColorTempMenu(void);
void MColorTempProc(void);
void MColorTempValueAdj(BYTE ucMode);
void MColorTempMenuAdj(BYTE ucMode);
void MColorTempEnterSubMenu(void);
void MColorTempReturnUpMenu(void);
//---------------------------------------------------------------------------
// ColorTemp User
void DrawColorUSERMenuItem(BYTE ucItem,BYTE ucState);
void EnterColorTempUserMenu(void);
void ClearColorUSERMenu(void);
void MColorUserProc(void);
void MColorUserValueAdj(BYTE ucMode);
void MColorUserMenuAdj(BYTE ucMode);
void MColorUserReturnUpMenu(void);
void MColorUserEnterSubMenu(void);
void ColorRAdjust(BYTE ucMode);
void ColorGAdjust(BYTE ucMode);
void ColorBAdjust(BYTE ucMode);

void MRProc(void);
void MRValueAdj(BYTE ucMode);
void MRReturnUpMenu(void);
void MGProc(void);
void MGValueAdj(BYTE ucMode);
void MGReturnUpMenu(void);
void MBProc(void);
void MBValueAdj(BYTE ucMode);
void MBReturnUpMenu(void);

//---------------------------------------------------------------------------
// Adjust
void MAdjustProc(void);
void MAdjustValueAdj(BYTE ucMode);
void MAdjustMenuAdj(BYTE ucMode);
void MAdjustEnterSubMenu(void);
void MAdjustReturnUpMenu(void);
//---------------------------------------------------------------------------
// AutoAdjust
void EnterAutoConfigMenu(void);
void MAutoAdjustProc(void);
void MAutoAdjustValueAdj(BYTE ucMode);
void MAutoAdjustMenuAdj(BYTE ucMode);
void MAutoAdjustEnterSubMenu(void);
void MAutoAdjustReturnUpMenu(void);
//---------------------------------------------------------------------------
// Adjust\\H Position Adjust
void MAdjustHPositionProc(void);
void MAdjustHPositionValueAdj(BYTE ucMode);
void MAdjustHPositionReturnUpMenu(void);
//---------------------------------------------------------------------------
// Adjust\\V Position Adjust
void MAdjustVPositionProc(void);
void MAdjustVPositionValueAdj(BYTE ucMode);
void MAdjustVPositionReturnUpMenu(void);
//---------------------------------------------------------------------------
// Adjust\\Phase Adjust
void MAdjustPhaseProc(void);
void MAdjustPhaseValueAdj(BYTE ucMode);
void MAdjustPhaseReturnUpMenu(void);
//---------------------------------------------------------------------------
// Adjust\\Clock Adjust
void MAdjustClockProc(void);
void MAdjustClockValueAdj(BYTE ucMode);
void MAdjustClockReturnUpMenu(void);
//---------------------------------------------------------------------------
// OSD
void MOSDProc(void);
void MOSDValueAdj(BYTE ucMode);
void MOSDMenuAdj(BYTE ucMode);
void MOSDEnterSubMenu(void);
void MOSDReturnUpMenu(void);
//---------------------------------------------------------------------------
// Language
void EnterLanguageMenu(void);
void MLanguageProc(void);
void MLanguageValueAdj(BYTE ucMode);
void MLanguageMenuAdj(BYTE ucMode);
void MLanguageEnterSubMenu(void);
void MLanguageReturnUpMenu(void);
//---------------------------------------------------------------------------
// HPosition Adjust
void MHPositionProc(void);
void MHPositionValueAdj(BYTE ucMode);
void MHPositionReturnUpMenu(void);
//---------------------------------------------------------------------------
// VPosition Adjust
void MVPositionProc(void);
void MVPositionValueAdj(BYTE ucMode);
void MVPositionReturnUpMenu(void);
//---------------------------------------------------------------------------
// Timer
void MTimerProc(void);
void MTimerAdjValue(BYTE ucMode);
void MTimerReturnUpMenu(void);
//---------------------------------------------------------------------------
// Transparent
void MTransparentProc(void);
void MTransparentReturnUpMenu(void);
//---------------------------------------------------------------------------
// Double
void EnterDoubleMenu(void);
void MDoubleProc(void);
void MDoubleValueAdj(BYTE ucMode);
void MDoubleMenuAdj(BYTE ucMode);
void MDoubleEnterSubMenu(void);
void MDoubleReturnUpMenu(void);
//---------------------------------------------------------------------------
// OSD H/V position
void COSDHPositionAdj(BYTE ucMode);
void COSDVPositionAdj(BYTE ucMode);
//---------------------------------------------------------------------------
// Transparent
void CTransparentAdj(BYTE ucMode);
//---------------------------------------------------------------------------
// TV
void MTVProc(void);
void MTVValueAdj(BYTE ucMode);
void MTVMenuAdj(BYTE ucMode);
void MTVEnterSubMenu(void);
void MTVReturnUpMenu(void);

void MChannelProc(void);
void MChannelReturnUpMenu(void);
//---------------------------------------------------------------------------
// System
void EnterSystemMenu(void);
void MSystemProc(void);
void MSystemValueAdj(BYTE ucMode);
void MSystemMenuAdj(BYTE ucMode);
void MSystemEnterSubMenu(void);
void MSystemReturnUpMenu(void);
//---------------------------------------------------------------------------
// AutoSearch
void EnterAutoSearchMenu(void);
void MAutoSearchProc(void);
void MAutoSearchValueAdj(BYTE ucMode);
void MAutoSearchMenuAdj(BYTE ucMode);
void MAutoSearchEnterSubMenu(void);
void MAutoSearchReturnUpMenu(void);
bit CKeyStopAutoSearch(void);
void CShowAutoSerachTotal(BYTE ucSearchTotal);
void CShowFreq(WORD iFreqN, BYTE x, BYTE y);
void CShowAutoSearchSliderInOSD(WORD ucCurrentValue);
//---------------------------------------------------------------------------
// ManualSearch
void EnterMSearchMenu(void);
void MManualSearchProc(void);
void MManualSearchValueAdj(BYTE ucMode);
void MManualSearchMenuAdj(BYTE ucMode);
void MManualSearchEnterSubMenu(void);
void MManualSearchReturnUpMenu(void);
//---------------------------------------------------------------------------
// Tuning
void CTuningAdj(BYTE ucMode);
void MTuningProc(void);
void MTuningReturnUpMenu(void);
//---------------------------------------------------------------------------
// Skip
void EnterSkipMenu(void);
void MSkipProc(void);
void MSkipValueAdj(BYTE ucMode);
void MSkipMenuAdj(BYTE ucMode);
void MSkipEnterSubMenu(void);
void MSkipReturnUpMenu(void);
//---------------------------------------------------------------------------
//AFC
void EnterAFCMenu(void);
void MAFCProc(void);
void MAFCValueAdj(BYTE ucMode);
void MAFCMenuAdj(BYTE ucMode);
void MAFCEnterSubMenu(void);
void MAFCReturnUpMenu(void);
//---------------------------------------------------------------------------
// Function
void MFunctionProc(void);
void MFunctionValueAdj(BYTE ucMode);
void MFunctionMenuAdj(BYTE ucMode);
void MFunctionEnterSubMenu(void);
void MFunctionReturnUpMenu(void);
//---------------------------------------------------------------------------
// Reset
void EnterResetMenu(void);
void MResetProc(void);
void MResetValueAdj(BYTE ucMode);
void MResetMenuAdj(BYTE ucMode);
void MResetEnterSubMenu(void);
void MResetReturnUpMenu(void);
//---------------------------------------------------------------------------
// DisplayRatio
void EnterDisplayRatioMenu(void);
void MDisplayRatioProc(void);
void MDisplayRatioValueAdj(BYTE ucMode);
void MDisplayRatioMenuAdj(BYTE ucMode);
void MDisplayRatioEnterSubMenu(void);
void MDisplayRatioReturnUpMenu(void);
//---------------------------------------------------------------------------
// AutoPowerDown
void EnterADPMenu(void);
void MAutoPowerDownProc(void);
void MAutoPowerDownValueAdj(BYTE ucMode);
void MAutoPowerDownMenuAdj(BYTE ucMode);
void MAutoPowerDownEnterSubMenu(void);
void MAutoPowerDownReturnUpMenu(void);
//---------------------------------------------------------------------------
// BlueScreen
void EnterBlueScreenMenu(void);
void MBlueScreenProc(void);
void MBlueScreenValueAdj(BYTE ucMode);
void MBlueScreenMenuAdj(BYTE ucMode);
void MBlueScreenEnterSubMenu(void);
void MBlueScreenReturnUpMenu(void);
//---------------------------------------------------------------------------
// Sharpness
void MSharpnessAdjValue(BYTE ucMode);
void MSharpnessProc(void);
void MSharpnessReturnUpMenu(void);

// Sound
void MSoundProc(void);
void MSoundValueAdj(BYTE ucMode);
void MSoundMenuAdj(BYTE ucMode);
void MSoundEnterSubMenu(void);
void MSoundReturnUpMenu(void);
//---------------------------------------------------------------------------
// Volume Adjust
void MVolumeProc(void);
void MVolumeValueAdj(BYTE ucMode);
void MVolumeReturnUpMenu(void);
//---------------------------------------------------------------------------
// Balance Adjust
void MBalanceProc(void);
void MBalanceValueAdj(BYTE ucMode);
void MBalanceReturnUpMenu(void);
//---------------------------------------------------------------------------
// Bass Adjust
void MBassProc(void);
void MBassValueAdj(BYTE ucMode);
void MBassReturnUpMenu(void);
//---------------------------------------------------------------------------
// Treble Adjust
void MTrebleProc(void);
void MTrebleValueAdj(BYTE ucMode);
void MTrebleReturnUpMenu(void);

//---------------------------------------------------------------------------
// Source
void DrawSourceMenu(void);
void MSourceProc(void);
void MSourceValueAdj(BYTE ucMode);
void MSourceMenuAdj(BYTE ucMode);
void MSourceEnterSubMenu(void);
void MSourceReturnUpMenu(void);
//---------------------------------------------------------------------------
// Short menu \ Brightness
void MScBrightnessProc(void);
void MScBrgithnessValueAdj(BYTE ucMode);
void MScBrgithnessReturnUpMenu(void);
//---------------------------------------------------------------------------
// Short menu \ Volume
void MScVolumeProc(void);
void MScVolumeValueAdj(BYTE ucMode);
void MScVolumeReturnUpMenu(void);

//---------------------------------------------------------------------------
// Short menu \ Input ch num
void MScInputChNumProc(void); 
void SInceptNumber(const WORD ucNumber);
void SShowCurrentInputState(BYTE ucInputState);

void EnterSCVolume(void);
void EnterSCBright(void);
void EnterSCInputNum(void);

//---------------------------------------------------------------------------
void CShowMode(BYTE x, BYTE y);
void CDisplayCurrentSourceMessage(void);

//---------------------------------------------------------------------------
void CSetOSDPosition(WORD OSDWidth, WORD OSDHeight, BYTE PosX, BYTE PosY);
void OSDSlider(BYTE row, BYTE col, BYTE length, BYTE value, BYTE range,BYTE color) small;

//---------------------------------------------------------------------------
void CSetItemStartEnd(void (*ReDrawPageProc)(void));
BYTE CGetPopupMenuRow(BYTE ucBaseRowStart, ucFirstItem);

void LoadLanguageFont();

#endif		//#if(_OSD_TYPE == _OSD003)
