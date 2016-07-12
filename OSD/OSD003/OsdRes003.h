#if(_OSD_TYPE == _OSD003)



#ifdef __OSDRES003__

#else
extern BYTE code tUserMenuOsdMap[];
extern BYTE code tFactoryMenuOsdMap[];

extern BYTE code tMsgOsdMap[];
extern BYTE code tPALETTE_0[];
extern BYTE code tMainWindowStyle[];
extern BYTE code tPopupMenuWindowStyle[];

extern BYTE code tColorIco_Normal[];
extern BYTE code tColorIco_Select[];
extern BYTE code tColorIco_Disable[];
      
extern BYTE code tAdjustIco_Normal[];
extern BYTE code tAdjustIco_Select[];
extern BYTE code tAdjustIco_Disable[];
       
extern BYTE code tOsdIco_Normal[];
extern BYTE code tOsdIco_Select[];
extern BYTE code tOsdIco_Disable[];
     
extern BYTE code tTVIco_Normal[];
extern BYTE code tTVIco_Select[];
extern BYTE code tTVIco_Disable[];
      
extern BYTE code tFuncIco_Normal[];
extern BYTE code tFuncIco_Select[];
extern BYTE code tFuncIco_Disable[];
    
extern BYTE code tSoundIco_Normal[];
extern BYTE code tSoundIco_Select[];
extern BYTE code tSoundIco_Disable[];

extern code STitle tMainTitle[][_LANGUAGE_CNT];

extern code BYTE *tIcon_Normal[];
extern code BYTE *tIcon_Select[];
extern code BYTE *tIcon_Disable[];

extern code BYTE sVGA[];
extern code BYTE sDVI[];
extern code BYTE sHDMI[];
extern code BYTE sYPBPR[];
extern code BYTE sSVideo[];
extern code BYTE sAV[];
extern code BYTE sTV[];
extern code BYTE sSpace[];
extern code BYTE s16_9[];
extern code BYTE s4_3[];
extern code BYTE sAuto[];

extern code BYTE sNTSC_M[];
extern code BYTE sNTSC_4_BG[];
extern code BYTE sNTSC_4_DK[];
extern code BYTE sNTSC_4_I[];
extern code BYTE sPAL_M[];

extern code BYTE sPAL_BG[];
extern code BYTE sPAL_I[];
extern code BYTE sPAL_DK[];
extern code BYTE sPAL_N[];

extern code BYTE sSECAM_BG[];
extern code BYTE sSECAM_DK[];
extern code BYTE sSECAM_L[];
extern code BYTE sSECAM_LL[];



extern code BYTE *sAutoConfig[];
extern code BYTE *sAutoPowerDown[];
extern code BYTE *sAutoSearch[];
extern code BYTE *sBalance[];
extern code BYTE *sBass[];
extern code BYTE *sBBE[];
extern code BYTE *sBlueScreen[];
extern code BYTE *sSharpness[];
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
extern code BYTE *sManualSearch[];
extern code BYTE *sPhase[];
extern code BYTE *sReset[];
extern code BYTE *sSaturation[];
extern code BYTE *sSkip[];
extern code BYTE *sSwap[];
extern code BYTE *sAFC[];
extern code BYTE *sSRS[];
extern code BYTE *sSystem[];
extern code BYTE *sTimer[];
extern code BYTE *sTransparent[];
extern code BYTE *sTreble[];
extern code BYTE *sTuning[];
extern code BYTE *sVolume[];
extern code BYTE *sVPosition[];

extern code BYTE *sNoSignal[];
extern code BYTE *sNotSupport[];

extern code BYTE *sUser[];
extern code BYTE *s9300[];
extern code BYTE *s6500[];

extern code BYTE *sOK[];
extern code BYTE *sCancel[];
extern code BYTE *sLanguageName[];

extern code BYTE *sOn[];
extern code BYTE *sOff[];
extern code BYTE *SOnOff[2][10];

extern code BYTE *s15Min[];
extern code BYTE *s30Min[];
extern code BYTE *s45Min[];
extern code BYTE *s60Min[];
extern code BYTE *s75Min[];
extern code BYTE *s90Min[];
extern code BYTE *s105Min[];
extern code BYTE *s120Min[];
//---------------------------------------------------------------------------
extern code BYTE sMhz[];
extern code BYTE *sSearchUP[];
extern code BYTE *sSearchDown[];

//---------------------------------------------------------------------------
extern code BYTE * sYPbPrMode[];
extern code BYTE sPAL[];
extern code BYTE sNTSC[];
extern code BYTE * sTVType[14];
extern code BYTE *sTVTypeN[2];

extern BYTE code sFacAdjustColor[];
extern BYTE code sFacGain[];
extern BYTE code sFacOffset[];
extern BYTE code sFac9300[];
extern BYTE code sFac6500[];
extern BYTE code sFacRGB[];
extern BYTE code sBurnIn[];
extern BYTE code sGamma[];
extern BYTE code sFacNR[];
extern BYTE code sFacExit[];
extern BYTE code sFacOn[];
extern BYTE code sFacOff[];
//---------------------------------------------------------------------------
extern BYTE code tGlobalCharWidth[];
extern BYTE code tFntVolumeCharWidth[];
extern BYTE code FntGlobal[];
extern BYTE code FntKor[];
extern BYTE code FntJap[];
extern BYTE code FntRus[];
#if(_CHINESE_FONT_TYPE == _CHINESE_1_FONT)
extern BYTE code tFntChiS[];
extern BYTE code tFntChiT[];
extern BYTE code tFntChiGlobal[];
#else
extern BYTE code FntChi_S[];
extern BYTE code FntChi_T[];
extern BYTE code tFntLangaugeNameCharWidth[];
extern BYTE code FntLangaugeName[];

extern BYTE code FntAdjustPage_S[];
extern BYTE code FntColorPage_S[];
extern BYTE code FntFuncPage_S[];
extern BYTE code FntOSDPage_S[];
extern BYTE code FntPublic_CHI_S[];
extern BYTE code FntSoundPage_S[];
extern BYTE code FntTVPage_S[];
extern BYTE code FntOther_CHI_S[];


extern BYTE code FntAdjustPage_T[];
extern BYTE code FntColorPage_T[];
extern BYTE code FntFuncPage_T[];
extern BYTE code FntOSDPage_T[];
extern BYTE code FntPublic_CHI_T[];
extern BYTE code FntSoundPage_T[];
extern BYTE code FntTVPage_T[];
extern BYTE code FntOther_CHI_T[];
#endif
extern BYTE code FntMainIcon[];

extern BYTE code tFntRusCharWidth[];
extern BYTE code tFntJapCharWidth[];
extern BYTE code tFntKorCharWidth[];

#endif				//#ifdef __OSDRES003__


// extand function & Var
// Title
extern BYTE code FntColorEng_Title[];
extern BYTE code FntAdjustEng_Title[];
extern BYTE code FntTVEng_Title[];
extern BYTE code FntOSDEng_Title[];
extern BYTE code FntFunctionEng_Title[];
extern BYTE code FntSoundEng_Title[];
extern BYTE code FntVolume[];
extern BYTE code FntMute[];
extern BYTE code FntInputState[];

extern BYTE code FntTitleAdjust_CHIS[];
extern BYTE code FntTitleFunc_CHIS[];
extern BYTE code FntTitleOSD_CHIS[];
extern BYTE code FntTitleSound_CHIS[];
extern BYTE code FntTitleTV_CHIS[];
extern BYTE code FntTitleColor_CHIS[];

extern BYTE code FntTitleAdjust_CHIT[];
extern BYTE code FntTitleFunc_CHIT[];
extern BYTE code FntTitleOSD_CHIT[];
extern BYTE code FntTitleSound_CHIT[];
extern BYTE code FntTitleTV_CHIT[];
extern BYTE code FntTitleColor_CHIT[];
extern BYTE code FntColorKor_Title[];
extern BYTE code FntAdjustKor_Title[];
extern BYTE code FntFunctionKor_Title[];
extern BYTE code FntOSDKor_Title[];
extern BYTE code FntSoundKor_Title[];

// Logo
extern BYTE code FntLogo[];
extern BYTE code FntLogoDotUpSide0[];
extern BYTE code FntLogoDotDownSide0_2Bit[];
extern BYTE code FntLogoDot1_2Bit[];
extern BYTE code FntLogoDot2_2Bit[];
extern BYTE code FntLogoDot3[];

#endif		//#if(_OSD_TYPE == _OSD003)
