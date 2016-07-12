#define __OSDTV007___

#include "Core\Header\include.h"

#if(_OSD_TYPE == _OSD007)

#if(_VIDEO_TV_SUPPORT) 
//------------------------------------------------------------
void MTVNoneProc(void)
{
    switch(ucKeyMessage)
    {
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MPublicNoneMenu();             break;
        case VK_LEFT:        MTVNoneLR(0);                  break;
        case VK_RIGHT:       MTVNoneLR(1);                  break;
        
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
          //  CShowTVNumber(stTvInfo.CurChn,_SHOW_CH_TV_NUMBER | _SHOW_CH_TV_TYPE | _SHOW_CH_SOUND_TYPE);
            break;
                
#if(_USE_UD_LR_KEY_MSG)// && CUSTOM_CODE != IR_CHUNGHOP_RMH02)
        case VK_F_DOWN:
#endif
        case VK_IR_CHINC:
            CChangeChannel(_NEXT_CHANNEL); // Next channel
            ucOsdEventMsg = _SAVE_EE_TV_DATA_MSG;
            break;
                    
#if(_USE_UD_LR_KEY_MSG)// && CUSTOM_CODE != IR_CHUNGHOP_RMH02)
        case VK_F_UP:
#endif
        case VK_IR_CHDEC:
            CChangeChannel(_PREV_CHANNEL); // Prev channel
            ucOsdEventMsg = _SAVE_EE_TV_DATA_MSG;
            break;
            
        case VK_IR_NUM0:
        case VK_IR_NUM1:
        case VK_IR_NUM2:
        case VK_IR_NUM3:
        case VK_IR_NUM4:
        case VK_IR_NUM5:
        case VK_IR_NUM6:
        case VK_IR_NUM7:
        case VK_IR_NUM8:
        case VK_IR_NUM9:
#if(0)
            {
                BYTE ucMaxChannel = CloadMaxChannelNumber();
    
                CForceBackGroundToBlack();
                ucPrevChannel = stTvInfo.CurChn;
                stTvInfo.CurChn = ucKeyMessage - VK_IR_NUM0;
                stTvInfo.CurChn = (stTvInfo.CurChn > ucMaxChannel) ? ucMaxChannel : stTvInfo.CurChn;
                CSetTVChannel(stTvInfo.CurChn);
                CShowTVNumber(stTvInfo.CurChn,_SHOW_CH_TV_NUMBER | _SHOW_CH_TV_TYPE | _SHOW_CH_SOUND_TYPE);
                
                ucOsdEventMsg = _SAVE_EE_VEDIOCOLOR_MSG;
            }
            
#else

            STVInputCHNumber();
#endif
            break;
        case VK_IR_INPUTCH:  STVInputCHEnter();              break;
        case VK_IR_RETURN:   STVReturnCH();                  break; 
    }
    
}

//------------------------------------------------------------
void MTVNoneLR(BYTE LR)
{
#if(1)
    if(LR)
    {
        CChangeChannel(_PREV_CHANNEL);  // Prev channel
    }
    else
    {
        CChangeChannel(_NEXT_CHANNEL);  // Next channel
    }
    
    ucOsdEventMsg = _SAVE_EE_TV_DATA_MSG; 
#else

    LR = LR;
    GotoAdjustVolume();
#endif
}  

//------------------------------------------------------------

//----------- Shortcut key proc ---------------------------
#define _INPUT_NO_NUMBER       0
#define _INPUT_ONE_NUMBER      1
#define _INPUT_TWO_NUMBER      2
#define _INPUT_THREE_NUMBER    3

void STVInputCHEnter(void)
{
    BYTE ucInputState = GET_INPUTCH_STATE() + 1;
    
    iInputCHCount = _INPUT_CH_TIMEOUT_COUNT;
    // Reset input number and state
    ucCurrentInputNumber = 0;
    ucCurrentInputState  = _INPUT_NO_NUMBER;  // 0: no input number   1: input one number     2: input two number    3: input three number
    
    if (ucInputState > 3)
    {   // Input state err reset input state to input one channel -
        ucInputState = 1;
        SET_INPUTCH_STATE(0);
        CEepromSaveTvData();
    }
    
    COsdFxDisableOsd();
    SetOsdMap(tMsgOsdMap);
    SetOSDDouble(OSD_DOUBLE_HEIGHT_ENABLE | OSD_DOUBLE_WIDTH_ENABLE);
 //   SetRowCmds(ROW_COUNT,COL_WIDTH);
    COsdFxCodeWrite(ucCloseAllWindow);
    CClearWindow(0x20);

#if(_OSD_DISPLAY_SIZE_ADJ)
    if (GET_OSD_SIZE())
    {
        OSDPosition(12*10, 18*3, 38, 1, 0x03);
        DirectWOSDRam(0x00, 0x03, THE_BYTE0, 0x80|0x03);  // Row 0~2 character double height and width
    }
    else
#endif
        OSDPosition(12*10, 18*3, 44, 1, 0x03);

//    OSDPosition(30,30,38,1,0x01);
    
    Gotoxy(1, 0, BYTE_DISPLAY);         
    for(;ucInputState > 0;ucInputState--)
        OutputChar(0x2d);  // Show "-"
    
    COsdFxEnableOsd();
    CTimerReactiveTimerEvent(SEC(stOsdUserData.OsdTimeout),COsdDispOsdTimerEvent);
    ucOsdState = ITEM_SHORTCUT_INPUTCH_NUM;
}
           
//---------------------------------------------------------
void SInputCHNumber(void)
{
    BYTE ucInputState = GET_INPUTCH_STATE() + 1;
    
    if (iInputCHCount > 0)
        iInputCHCount--;
            
    switch(ucKeyMessage)
    {
        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
          //  COsdFxDisableOsd();
            iInputCHCount = 0;
            break;
#else
        case VK_MENU:
         //   COsdFxDisableOsd();
         //   MTVNoneProc();
            iInputCHCount = 0;
            break;
#endif
        case VK_IR_NUM0:
        case VK_IR_NUM1:
        case VK_IR_NUM2:
        case VK_IR_NUM3:
        case VK_IR_NUM4:
        case VK_IR_NUM5:
        case VK_IR_NUM6:
        case VK_IR_NUM7:
        case VK_IR_NUM8:
        case VK_IR_NUM9:
            iInputCHCount = _INPUT_CH_TIMEOUT_COUNT;
            SInceptNumber(ucKeyMessage - VK_IR_NUM0);
            break;
            
        case VK_IR_INPUTCH:
            iInputCHCount = _INPUT_CH_TIMEOUT_COUNT;
            ucInputState = ValueInRangeChange(1, 3, ucInputState, _LOOP | 0x01);
            SET_INPUTCH_STATE(ucInputState-1);
            CEepromSaveOsdUserData();
            
            // Reset input number and state
            ucCurrentInputNumber = 0;
            ucCurrentInputState  = 0;  // 0: no input number   1: input one number     2: input two number    3: input three number
            break;
            
        default:
            COthterKeyAction();
            
            if (ucOsdState != ITEM_SHORTCUT_INPUTCH_NUM)
                return;
            else           
                break;
    }  
    
    SShowCurrentInputState(ucInputState);
    
    if (ucInputState == ucCurrentInputState || iInputCHCount == 0)
    {
        BYTE ucMaxChannel = CloadMaxChannelNumber();
                                
        iInputCHCount = _INPUT_CH_TIMEOUT_COUNT;
        if (ucCurrentInputState == 0)// || ucPrevChannel == ((ucCurrentInputNumber > ucMaxChannel) ? ucMaxChannel : ucCurrentInputNumber))
        {
            COsdDispOsdTimerEvent();
            return;
        }

        CMuteOn();
      //  CForceBackGroundToBlack();
        ucOsdState = _MENU_NONE;
        CModeResetTVMode();
        CTimerDelayXms(200);
        
        ucPrevChannel =  stTvInfo.CurChn;
        stTvInfo.CurChn = (ucCurrentInputNumber > ucMaxChannel) ? ucMaxChannel : ucCurrentInputNumber;
        CSetTVChannel(stTvInfo.CurChn);
        CShowTVNumber(stTvInfo.CurChn,_SHOW_CH_TV_NUMBER | _SHOW_CH_TV_TYPE | _SHOW_CH_SOUND_TYPE);
        gmi_CI2CWriteIfPllDM(ucTVType, _TUNER_MUTE_OFF, _NORMAL_MODE);
        bChangeChannel = 1;
        CTimerDelayXms(500);
        ucOsdEventMsg = _SAVE_EE_TV_DATA_MSG;
    }
}

//---------------------------------------------------------
void SInceptNumber(const WORD ucNumber)
{
    switch(ucCurrentInputState)
    { 
        case _INPUT_NO_NUMBER: // not input number
            ucCurrentInputNumber = ucNumber;
            ucCurrentInputState  = _INPUT_ONE_NUMBER;
            break;
            
        case _INPUT_ONE_NUMBER: // Input on number alrady
        case _INPUT_TWO_NUMBER: // Input two number alrady
            ucCurrentInputNumber = (ucCurrentInputNumber*10) + ucNumber;
            ucCurrentInputState  = (ucCurrentInputState == _INPUT_TWO_NUMBER) ? _INPUT_THREE_NUMBER : _INPUT_TWO_NUMBER;
            break;
            /*
            case _INPUT_TWO_NUMBER: // Input two number alrady
            ucCurrentInputNumber = (ucCurrentInputNumber*10) + ucNumber;
            ucCurrentInputState  = _INPUT_THREE_NUMBER;
            break;*/
    }
}

//---------------------------------------------------------
void SShowCurrentInputState(WORD ucInputState)
{
    Gotoxy(1, 0, BYTE_DISPLAY); 
    
    switch(ucCurrentInputState)
    {
        case _INPUT_NO_NUMBER: // not input number
            for(;ucInputState > 0;ucInputState--)
                OutputChar(0x2d);  // Show "-"
            OutputChar(0x00);  // Show " "
            OutputChar(0x00);  // Show " "
            break;
            
        case _INPUT_ONE_NUMBER: // Input on number alrady
            CShowNumber1(ucCurrentInputNumber,1);
            break;
            
        case _INPUT_TWO_NUMBER: // Input two number alrady
            CShowNumber1(ucCurrentInputNumber,2);
            break;
            
        case _INPUT_THREE_NUMBER: // Input three number alrady
            CShowNumber1(ucCurrentInputNumber,3);
            break;
    }
}

//---------------------------------------------------------
void STVInputCHNumber(void)
{
    STVInputCHEnter();
    ucOsdState = ITEM_SHORTCUT_INPUTCH_NUM;
    SInputCHNumber();
}

//---------------------------------------------------------
void STVReturnCH(void)
{
    pData[0]        = stTvInfo.CurChn;
    stTvInfo.CurChn = ucPrevChannel;
    ucPrevChannel   = pData[0];
    
    CMuteOn();
    CModeResetTVMode();
    CSetTVChannel(stTvInfo.CurChn);
    CShowTVNumber(stTvInfo.CurChn, _SHOW_CH_TV_NUMBER | _SHOW_CH_TV_TYPE | _SHOW_CH_SOUND_TYPE);
    ucOsdEventMsg = _SAVE_EE_TV_DATA_MSG;
    bChangeChannel = 0;
}

//------------------------------------------------------------
void CDrawTVFunction(void)
{
    CTextOutEx(sAutoSearch[GET_LANGUAGE()], 1, 4);       // "Auto Search"
    CTextOutEx(sManualSearch[GET_LANGUAGE()], 1, 5);     // "Manual Search"
    CTextOutEx(sTuning[GET_LANGUAGE()], 1, 6);           // "Tuning"
    CTextOutEx(sChannel[GET_LANGUAGE()], 1, 7);          // "Channel"
    CTextOutEx(sTVSystem[GET_LANGUAGE()], 1, 8);         // "TV System"
    CTextOutEx(sSwap[GET_LANGUAGE()], 1, 9);             // "Swap"
    CTextOutEx(sSkip[GET_LANGUAGE()], 1, 10);            // "Skip"
    CTextOutEx(sExit[GET_LANGUAGE()], 1, 11);            // "Exit"
}

//----------------------------------------------------------------------------------------------------
//   TV function Sub item
void MTVFuncSubItemProc(void)
{
    switch(ucKeyMessage)
    {
        // Select item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
        case VK_F_RIGHT:
#endif
        case VK_MENU:        MTVFuncSubItemMenu();                break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
#endif
        case VK_LEFT:        MTVFuncSubItemLR(1);                 break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_DOWN:
#endif
        case VK_RIGHT:       MTVFuncSubItemLR(0);                 break;

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER:       CExitToMainItem(MENU_MAIN_TV_FUNC);  break;
#endif
            
        // Other key
        default:             COthterKeyAction();                  break;
    }
}

//----------------------------------------------------------------------------------------------------
#if(_TV_SEARCH_SHOW_TYPE == _TV_SEARCH_SHOW_FREQ)
void CShowFreq(WORD iFreqN)
{
    DWORD lFreqTemp = 0;

    // Get PIF freq
    lFreqTemp = (((float)iFreqN/_TUNER_BP) - ((float)_PIF_FREQ/1000))*100;

    Gotoxy(10, _MESSAGE_V_POSITION, BYTE_DISPLAY); 
    iFreqN = lFreqTemp/100;  // MHz  
    CShowNumber1(iFreqN, 0);
    OutputChar(0x2E); // "."

    iFreqN = lFreqTemp%100;  // KHz
    CShowNumber1(iFreqN, 2);

    OutputChar('M');
    OutputChar('H');
    OutputChar('z');
    OutputChar(0x00); // " "
}

void CShowCurrentChannelFreq(void)
{
    WORD iFreq = 0;

    iFreq = CLoadChannelFreq(stTvInfo.CurChn);
    CShowFreq(iFreq);
}
#endif

//----------------------------------------------------------------------------------------------------
void MTVFuncSubItemMenu(void)
{
    CClearMsg(_CLEAR_AND_SELECT_SUB_ITEM);

    Gotoxy(14, _MESSAGE_V_POSITION, BYTE_DISPLAY);

    switch(ucOsdState)
    {
        case MENU_AUTO_SEARCH:
            CTvAutoSearch();
            CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
            break;

        case MENU_MANUAL_SEARCH:       
#if(_TV_SEARCH_SHOW_TYPE == _TV_SEARCH_SHOW_FREQ)
            CShowCurrentChannelFreq();
#endif
            ucOsdState = MENU_MANUAL_SEARCH_ADJ;   
            break;

        case MENU_TUNING:
#if(_TV_SEARCH_SHOW_TYPE == _TV_SEARCH_SHOW_FREQ)
            CShowCurrentChannelFreq();
#endif
            ucOsdState = MENU_TUNING_ADJ;        
            break;

        case MENU_CHANNEL:     
            CShowNumber1(stTvInfo.CurChn, 0);
            ucOsdState = MENU_CHANNEL_ADJ;        
            break;

        case MENU_TV_SYSTEM: 
            CCenterTextout(sTVType[ucTVType],ROW(_MESSAGE_V_POSITION),COL(0),30);
            ucOsdState   = MENU_TV_SYSTEM_ADJ; 
            ucOSDAdjTemp = ucTVType;
            break;

            /*
        case MENU_SOUND_SYSTEM:  // Not use
            break;
                     */
        case MENU_SWAP:     
            CShowNumber1(stTvInfo.CurChn, 0);
            ucPrevChannel = stTvInfo.CurChn;
            ucOsdState = MENU_SWAP_ADJ;        
            break;

        case MENU_SKIP: 
            ucOsdState = CLoadChannelSkip(stTvInfo.CurChn);
            CCenterTextout(sOn_Off[ucOsdState][GET_LANGUAGE()],ROW(_MESSAGE_V_POSITION),COL(0),30);
            ucOsdState = MENU_SKIP_ADJ;        
            break;

        case MENU_SUB_TV_FUNC_CLOSE: 
            CExitToMainItem(MENU_MAIN_TV_FUNC); 
            break;
    }        
}

//----------------------------------------------------------------------------------------------------
void MTVFuncSubItemLR(BYTE LR)
{
    ucOsdState = ValueInRangeChange(MENU_AUTO_SEARCH, MENU_SUB_TV_FUNC_CLOSE, ucOsdState, _LOOP | LR);

    CGotoNextSubItem(ucOsdState - MENU_AUTO_SEARCH);
}



//--------- TVSystem adjust proc ----------------------------------
void MTVSystemAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MTVSystemAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MTVSystemAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MTVSystemAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MTVSystemAdjLR(0);        break;

        // Other key
        default:             COthterKeyAction();       break;
    }
}

//----------------------------------------------------------------------------------------------------
void MTVSystemAdjMenu(void)
{
    ucOsdState = MENU_TV_SYSTEM;
    
    ucTVType     = ucOSDAdjTemp;
    ucOSDAdjTemp = 0;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
    // Save adjust result        
    CSaveChannelColorType(stTvInfo.CurChn, ucTVType);
    
    gmi_CI2CWriteIfPllDM(ucTVType, _TUNER_MUTE_OFF, _NORMAL_MODE);
    CSetTvColor(ucTVType);
}

//----------------------------------------------------------------------------------------------------
bit bSearchedTVType(BYTE ucTvType)
{
    switch(ucTvType) 
    {
        case _TV_NTSC_M    :    // 60Hz Sound 4.5M  NTSC M
#if(_TV_NTSC_M_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_NTSC_4_BG :    // 60Hz Sound 5.5M  NTSC 4/BG 
#if(_TV_NTSC_4_BG_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_NTSC_4_DK :    // 60Hz Sound 6.5M  NTSC 4/DK 
#if(_TV_NTSC_4_DK_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_NTSC_4_I  :    // 60Hz Sound 6.0M  NTSC 4/I
#if(_TV_NTSC_4_I_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_PAL_M     :    // 60Hz Sound 4.5M  PAL M  
#if(_TV_PAL_M_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_PAL_BG    :    // 50Hz Sound 5.5M  PAL B/G
#if(_TV_PAL_BG_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_PAL_I     :    // 50Hz Sound 6.0M  PAL I
#if(_TV_PAL_I_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_PAL_DK    :    // 50Hz Sound 6.5M  PAL D/K
#if(_TV_PAL_DK_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_PAL_N     :    // 50Hz Sound 4.5M  PAL N 
#if(_TV_PAL_N_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_SECAM_BG  :    // 50Hz Sound 5.5M  SECAM B/G
#if(_TV_SECAM_BG_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_SECAM_DK  :    // 50Hz Sound 6.5M  SECAM D/K
#if(_TV_SECAM_DK_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_SECAM_L   :    // 50Hz Sound 6.5M  SECAM L  
#if(_TV_SECAM_L_SUPPORT)
            return 1;
#endif
            break;
        
        case _TV_SECAM_LL  :    // 50Hz Sound 6.5M  Secam L' 
#if(_TV_SECAM_LL_SUPPORT)
            return 1;
#endif
            break;
    } // end switch 
    
    return 0;
}

//----------------------------------------------------------------------------------------------------
void MTVSystemAdjLR(BYTE LR)
{             
    for(pData[15] = 0; pData[15] < (_MAX_TV_TYPE + 1); pData[15]++)
    {
        ucOSDAdjTemp = ValueInRangeChange(1, _MAX_TV_TYPE, ucOSDAdjTemp, _LOOP | LR);
        
        if (bSearchedTVType(ucOSDAdjTemp))
            break;
    }
    
    CClearMsg(_CLEAR_MSG_ONLY);
    
    CCenterTextout(sTVType[ucOSDAdjTemp],ROW(_MESSAGE_V_POSITION),COL(0),30);
}

/*
//--------- Sound System ADJUST PROC ----------------------------------
void MSoundSystemAdjProc(void)
{
    switch(ucKeyMessage)
    {
    case VK_MENU:        MSoundSystemAdjMenu();       break;
    case VK_LEFT:        MSoundSystemAdjLR(1);        break;
    case VK_RIGHT:       MSoundSystemAdjLR(0);        break;
    case VK_ENTER:       MSoundSystemAdjEnter();      break;
        
    default:             COthterKeyAction();          break;
    }
}

//----------------------------------------------------------------------------------------------------
void MSoundSystemAdjMenu(void)
{
    ucOsdState = MENU_SOUND_SYSTEM;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MSoundSystemAdjLR(BYTE LR)
{
    BYTE ucSoundType = CLoadChannelSoundType(stTvInfo.CurChn);
    
    ucSoundType = ValueInRangeChange(0, 3, ucSoundType, LR, 1);
    
    Gotoxy(14, _MESSAGE_V_POSITION, BYTE_DISPLAY);
    Textout(sTVSoundType[ucSoundType]);
    
    // Save adjust result
    CSaveChannelSoundType(stTvInfo.CurChn, ucSoundType);
    
    //    gmi_CWrite9886(ucSoundType); // set 9886
}

//----------------------------------------------------------------------------------------------------
void MSoundSystemAdjEnter(void)
{
}
//----------------------------------------------------------------------------------------------------
  */


//--------- Auto Search PROC ----------------------------------
void MAutoSearchAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MAutoSearchAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MAutoSearchAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MAutoSearchAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MAutoSearchAdjLR(0);        break;

        // Other key
        default:             COthterKeyAction();         break;
    }
}

//----------------------------------------------------------------------------------------------------
void MAutoSearchAdjMenu(void)
{
    ucOsdState = MENU_AUTO_SEARCH;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MAutoSearchAdjLR(BYTE LR)
{
    LR = 0;
}

//----------------------------------------------------------------------------------------------------
#if(_TV_SEARCH_SHOW_TYPE == _TV_SEARCH_SHOW_SLIDER)
void CShowAutoSearchSliderInOSD(BYTE ucCurrentValue)
{
    SLIDER1(ucCurrentValue);
}
#endif

#if(_TV_SEARCH_SHOW_TYPE == _TV_SEARCH_SHOW_FREQ)
void CShowAutoSearchSliderInOSD(WORD ucCurrentValue)
{
    CShowFreq(ucCurrentValue);
}                           
#endif

//----------------------------------------------------------------------------------------------------
void CShowAutoSerachTotal(BYTE ucSearchTotal)
{
    Gotoxy(3, _MESSAGE_V_POSITION, BYTE_DISPLAY);
    CShowNumber1(ucSearchTotal, 0);
}

//----------------------------------------------------------------------------------------------------

#define _STOP_AUTO_SEARCH_KEY_REPT_COUNT       4
bit CKeyStopAutoSearch(void)
{
   if (_MENU_KEY_MASK == CKeyScan() || VK_ENTER == CIRKeyScan())
      return 1;

   return 0;
}

//----------------------------------------------------------------------------------------------------

//--------- Manual Search proc ----------------------------------
void MManualSearchAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MManualSearchAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MManualSearchAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MManualSearchAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MManualSearchAdjLR(0);        break;

        // Other key
        default:             COthterKeyAction();           break;
    }
}

//----------------------------------------------------------------------------------------------------
void MManualSearchAdjMenu(void)
{
    ucOsdState = MENU_MANUAL_SEARCH;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MManualSearchAdjLR(BYTE LR)
{
    CManualSearch((bit)LR,stTvInfo.CurChn);
    CTimerDelayXms(200);
}

//--------- Tuning proc ----------------------------------
void MTuningAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MTuningAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MTuningAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MTuningAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MTuningAdjLR(0);        break;

        // Other key
        default:             COthterKeyAction();     break;
    }
}

//----------------------------------------------------------------------------------------------------
void MTuningAdjMenu(void)
{
    ucOsdState = MENU_TUNING;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MTuningAdjLR(BYTE LR)
{
    SET_KEYREPEATENABLE();
                               
#if(_TV_SEARCH_SHOW_TYPE != _TV_SEARCH_SHOW_FREQ)
    Gotoxy(14, _MESSAGE_V_POSITION, BYTE_DISPLAY);
    Textout(sTuningState[LR]);
#endif

    CTuningCurrentChannel((bit)LR,stTvInfo.CurChn);

#if(_TV_SEARCH_SHOW_TYPE == _TV_SEARCH_SHOW_FREQ)
    CShowCurrentChannelFreq();
#endif              
    CLR_CLEAR_OSD_EN();
}

//--------- Channel PROC ----------------------------------
void MChannelAdjProc(void)
{             
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MChannelAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MChannelAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MChannelAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MChannelAdjLR(0);        break;

        // Other key
        default:             COthterKeyAction();      break;
    }
}
//----------------------------------------------------------------------------------------------------
void MChannelAdjMenu(void)
{
    ucOsdState = MENU_CHANNEL;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MChannelAdjLR(BYTE LR)
{
    stTvInfo.CurChn = ValueInRangeChange(0,CloadMaxChannelNumber(),stTvInfo.CurChn,_LOOP | LR);
  
    CMuteOn();
    CModeResetTVMode();
    CClearMsg(_CLEAR_MSG_ONLY);

    CSetTVChannel(stTvInfo.CurChn);
    ucPrevChannel =  stTvInfo.CurChn;
    
    Gotoxy(14,_MESSAGE_V_POSITION,BYTE_DISPLAY);
    CShowNumber1(stTvInfo.CurChn, 0);
    bChangeChannel = 0;
    // Save current channel
    ucOsdEventMsg  = _SAVE_EE_TV_DATA_MSG;
    CLR_CLEAR_OSD_EN();
}


//--------- Swap PROC ----------------------------------
void MSwapAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MSwapAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MSwapAdjMenu();       break;


        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MSwapAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MSwapAdjLR(0);        break;

        // Other key
        default:             COthterKeyAction();   break;
    }
}

//----------------------------------------------------------------------------------------------------
void MSwapAdjMenu(void)
{
    WORD ucSwapFreq        = CLoadChannelFreq(stTvInfo.CurChn);
    BYTE ucSwapColorSystem = CLoadChannelColorType(stTvInfo.CurChn);
    BYTE ucSwapSoundSystem = CLoadChannelSoundType(stTvInfo.CurChn);
    
    if (stTvInfo.CurChn == ucPrevChannel)
        return;

    CAdjustBackgroundColor(0x00, 0x00, 0x00);     
    CScalerSetBit(_VDISP_CTRL_28, ~_BIT5, _BIT5);
    
    CSaveChannelFreq(CLoadChannelFreq(ucPrevChannel), stTvInfo.CurChn);
    CSaveChannelColorType(CLoadChannelColorType(ucPrevChannel), stTvInfo.CurChn);
    CSaveChannelSoundType(CLoadChannelSoundType(ucPrevChannel), stTvInfo.CurChn);
    
    CSaveChannelFreq(ucSwapFreq, ucPrevChannel);
    CSaveChannelColorType(ucSwapColorSystem, ucPrevChannel);
    CSaveChannelSoundType(ucSwapSoundSystem, ucPrevChannel);  
    
    CSetTVChannel(stTvInfo.CurChn);
    
    ucOsdState = MENU_SWAP;
    CClearMsg(_CLEAR_MSG_ONLY);
    ShowMode();
    CSetItemWindowState(_SELECT_SUB_WINDOW, _MOVE_STATE);
    CTimerDelayXms(100);
    CScalerSetBit(_VDISP_CTRL_28, ~_BIT5, 0x00);
    bChangeChannel = 0;
}

//----------------------------------------------------------------------------------------------------
void MSwapAdjLR(BYTE LR)
{
    CClearMsg(_CLEAR_MSG_ONLY);

    stTvInfo.CurChn = ValueInRangeChange(0,CloadMaxChannelNumber(),stTvInfo.CurChn,_LOOP | LR);
    
    CAdjustBackgroundColor(0x00, 0x00, 0x00);     
    CScalerSetBit(_VDISP_CTRL_28, ~_BIT5, _BIT5);
    
    CSetTVChannel(stTvInfo.CurChn);
    
    Gotoxy(14,_MESSAGE_V_POSITION,BYTE_DISPLAY);
    CShowNumber1(stTvInfo.CurChn, 0);
    CTimerDelayXms(100);
    CScalerSetBit(_VDISP_CTRL_28, ~_BIT5, 0x00);

    CLR_CLEAR_OSD_EN();
    bChangeChannel = 0;
}

//--------- Skip PROC ----------------------------------
void MSkipAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MSkipAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MSkipAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MSkipAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MSkipAdjLR(0);        break;

        // Other key
        default:             COthterKeyAction();   break;
    }
}

//----------------------------------------------------------------------------------------------------
void MSkipAdjMenu(void)
{
    ucOsdState = MENU_SKIP;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MSkipAdjLR(BYTE LR)
{
    CClearMsg(_CLEAR_MSG_ONLY);

    LR = CLoadChannelSkip(stTvInfo.CurChn);
    
    LR = 1 - LR;
    
    // Save current channel skip state
    CSaveChannelSkip((bit)LR, stTvInfo.CurChn);
    
    CCenterTextout(sOn_Off[LR][GET_LANGUAGE()],ROW(_MESSAGE_V_POSITION),COL(0),30);
}

//----------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------
//
// ucOption:   0x01: Only show ucTvNumber          _SHOW_CH_TV_NUMBER
//             0x02: Show tv type                  _SHOW_CH_TV_TYPE
//             0x04: Show sound type               _SHOW_CH_SOUND_TYPE
//
//-------------------------------------------------------------------------
void CShowTVNumber(const BYTE ucTvNumber, const BYTE ucOption)
{
    BYTE y;

    CInitOSDMainFrame();
    SetOSDDouble(0x03);
#if(_OSD_DISPLAY_SIZE_ADJ)
    if (GET_OSD_SIZE())
    {
        OSDPosition(12*10, 18*3, 38, 1, 0x03);
        DirectWOSDRam(0x00, 0x03, THE_BYTE0, 0x80|0x03);  // Row 0~2 character double height and width
    }
    else
#endif
        OSDPosition(12*10, 18*3, 44, 1, 0x03);
    
#if(_SLEEP_FUNC)
    bTimerOnScreen = 0;
#endif
    ucOsdState     = MENU_SHOW_MESSAGE_SATAE;
    
    OSDLine(0, 0, 10, 0x20, BYTE_COLOR);
    OSDLine(1, 0, 10, 0x20, BYTE_COLOR);

    y = 0;
    if(ucOption & _SHOW_CH_TV_NUMBER)
    {
        Gotoxy(1,y,BYTE_DISPLAY);         
        CShowNumber1(ucTvNumber, 0);
        y++;
    }
    if(ucOption & _SHOW_CH_TV_TYPE)
    {
        CTextOutEx(sTVType[ucTVType],1,y);
        y++;
    }
    /*  if(ucOption & _SHOW_CH_SOUND_TYPE)
    {
    RightAlignTextOut(sTVSoundType[CLoadChannelSoundType(stTvInfo.CurChn)], 8, y);
    y++;
}*/

    COsdFxEnableOsd();  
    CTimerReactiveTimerEvent(SEC(5),COsdDispOsdTimerEvent);
}

//-------------------------------------------------------------------------



#endif  //#if(_VIDEO_TV_SUPPORT)
#endif  //#if(OSD_TYPE == OSD007)
