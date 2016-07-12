#define __OSDAV007___

#include "Core\Header\include.h"

#if(_OSD_TYPE == _OSD007)

#if(_VIDEO_SUPPORT)

//------------------------------------------------------------   
void MAVNoneProc(void)
{
    switch(ucKeyMessage)
    {
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER:       
#endif
        case VK_MENU:        MPublicNoneMenu();   break;
        case VK_LEFT:        MAVNoneLR(0);        break;
        case VK_RIGHT:       MAVNoneLR(1);        break;

        case VK_IR_MUTE:
            SSetMuteState();
            ucOsdEventMsg = _SAVE_EE_OSDUSERDATA_MSG;
            break;
            
#if(_USE_UD_LR_KEY_MSG)// && CUSTOM_CODE != IR_CHUNGHOP_RMH02)
        case VK_F_LEFT:
        case VK_F_RIGHT:
#endif
        case VK_IR_VOLDEC:
        case VK_IR_VOLINC:
            GotoAdjustVolume(); 
            break;

        case VK_IR_DISPLAY:
            CDisplayCurrentSourceMessage();
            break;
    }
}

//------------------------------------------------------------
void MAVNoneLR(BYTE LR)
{
    GotoAdjustVolume();
    LR = 0;  
}

//------------------------------------------------------------


//--------- AV HUE proc ----------------------------------
void MAVHueAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MAVHueMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER:
#endif
        case VK_MENU:        MAVHueMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MAVHueLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MAVHueLR(0);        break;
           
        // Other key
        default:             COthterKeyAction(); break;
    }
}

//------------------------------------------------------------
void MAVHueMenu(void)
{
    ucOsdState = MENU_AV_HUE;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//------------------------------------------------------------
void MAVHueLR(BYTE  LR)
{
    SET_KEYREPEATENABLE();     
    stHueSatData.Hue = ValueInRangeChange(0,100,stHueSatData.Hue,_NON_LOOP | LR);
    SLIDER1(GET_HUE());
    if(bSourceVideo())
        gmi_CAdjustVDCHue(GET_HUE());
    else
        CAdjustYpbprhue(GET_HUE());
    ucOsdEventMsg = _SAVE_EE_HUE_SAT_DATA_MSG;
}

//--------- AV Saturation proc ----------------------------------
void MAVSaturationAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MAVSaturationMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER:       
#endif
        case VK_MENU:        MAVSaturationMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MAVSaturationLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MAVSaturationLR(0);        break;
           
        default:             COthterKeyAction();        break;
    }
}

//------------------------------------------------------------
void MAVSaturationMenu(void)
{
    ucOsdState = MENU_AV_SATURATION;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//------------------------------------------------------------
void MAVSaturationLR(BYTE  LR)
{
    SET_KEYREPEATENABLE();
    stHueSatData.Saturation = ValueInRangeChange(0,100,stHueSatData.Saturation,_NON_LOOP | LR);
    SLIDER1(GET_SATURATION());
    if(bSourceVideo())
        CVideoSetSaturation(GET_SATURATION());
    else
        CAdjustYpbprSaturation(GET_SATURATION());
    ucOsdEventMsg = _SAVE_EE_HUE_SAT_DATA_MSG;
}

#endif  //#if(_VIDEO_SUPPORT)

#endif  //#if(OSD_TYPE == OSD007)
