#if(_OSD_TYPE == _OSD007)

#if(_TMDS_SUPPORT || _VGA_SUPPORT || _YPBPR_SUPPORT || _HDMI_SUPPORT)
//--------------------------------------------------

void OSDVGAProc();                                       

// Color temp sub page
#if(_COLOR_TEMP)
void CDrawColorTempSubItem(void);
void MColorTempSubItemProc(void);
void MColorTempSubItemMenu(void);
void MColorTempSubItemLR(BYTE LR);

void MColorTempUserItemProc(void);
void MColorTempUserItemMenu(void);
void MColorTempUserItemLR(BYTE LR);
#endif


#if(_VGA_SUPPORT || _YPBPR_SUPPORT)
void CDrawPicturePage(void);
void MPictureSubItemProc(void);
void MPictureSubItemLR(BYTE LR);
void MPictureSubItemMenu(void);
#endif

void MNoneProc(void);
void MNoneLR(BYTE  LR);

#if(_VGA_SUPPORT)
void MPhaseAdjProc(void);
void MPhaseAdjMenu(void);
void MPhaseAdjLR(BYTE  LR);

void MClockAdjProc(void);
void MClockAdjMenu(void);
void MClockAdjLR(BYTE  LR);

void MHPosAdjProc(void);
void MHPosAdjMenu(void);
void MHPosAdjLR(BYTE  LR);

void MVPosAdjProc(void);
void MVPosAdjMenu(void);
void MVPosAdjLR(BYTE  LR);
#endif


void DoAuto(void);
//--------------------------------------------------
#endif  //#if(_TMDS_SUPPORT || _VGA_SUPPORT || _YPBPR_SUPPORT || _HDMI_SUPPORT)

#endif  //#if(OSD_TYPE == OSD007)
