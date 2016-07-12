#if(_OSD_TYPE == _OSD007)

#if(_VIDEO_SUPPORT)
//--------------------------------------------------

void OSDAVProc(void);

void MAVNoneProc(void);
void MAVNoneLR(BYTE LR);

void MAVHueAdjProc(void);
void MAVHueMenu(void);
void MAVHueLR(BYTE  LR);

void MAVSaturationAdjProc(void);
void MAVSaturationMenu(void);
void MAVSaturationLR(BYTE  LR);

//--------------------------------------------------
#endif  //#if(_VIDEO_SUPPORT)
#endif  //#if(OSD_TYPE == OSD007)
