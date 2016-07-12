#if(_OSD_TYPE == _OSD007)


#ifdef __OSD007_LCD_OSD__

#define ROW_COUNT    15
#define COL_WIDTH    30

#define FONT_SELECT_ADDRESS           (ucRow_Count + 1)
//ROW_COUNT * COL_WIDTH + ROW_COUNT + 1 = 466
#define FONT_BASE_ADDRESS             ((ROW_COUNT * COL_WIDTH) + ROW_COUNT + 1)//466

//#define FONT_BASE_ADDRESS			0x1D2

//-----------------------------------------------------------------
BYTE code tUserMenuOsdMap[] =
{
    15,         // Row Count
    LOBYTE(FONT_BASE_ADDRESS),HIBYTE(FONT_BASE_ADDRESS),
    30,   // Row 0 char count
    30,   // Row 1 char count
    30,   // Row 2 char count
    30,   // Row 3 char count
    30,   // Row 4 char count
    30,   // Row 5 char count
    30,   // Row 6 char count
    30,   // Row 7 char count
    30,   // Row 8 char count
    30,   // Row 9
    30,   // Row 10
    30,   // Row 11
    30,   // Row 12
    30,   // 13
    30,   // 14
    30,   // 15
};

//-----------------------------------------------------------------
BYTE code tMsgOsdMap[] =
{
    8,         // Row Count
    LOBYTE(FONT_BASE_ADDRESS),HIBYTE(FONT_BASE_ADDRESS),
    20,   // Row 0 char count
    20,   // Row 1 char count
    20,   // Row 2 char count
    20,   // Row 3 char count
    20,   // Row 4 char count
    20,   // Row 5 char count
    20,   // Row 6 char count
    20,   // Row 7 char count
};

//------------------ Window attribute ------------------
// window 0/5/6/7
// window 1/2/3/4
//----------------------------------------------------------------------------------------------------
BYTE code tOSD_MAIN_WINDOW_STYLE[] =
{
    // OSD window number
    WINNO(_MAIN_WINDOW),

    //    Window shadow/border width or 3D button thickness in pixel unit(range: 1~8 pixel)
    // |  Window shadow/border height in line unit(range: 1~8 line)
    SB_THICKNESS(2) | SB_HEIGHT(2) ,   // [100h]Byte 0
    //    Window shadow color index in 16-color LUT for 3D window,it is the left-top/bottom border color(range: 0~15)
    // |  Window border color index in 16-color LUT for 3D window,it is the right-bottom/top border color(range: 0~15)
    SHADOW_COLOR(4) | BORDER_COLOR(4), // [100h]Byte 1
    //    R Gradient Polarity (range: R_GRADIENT_POLARITY_DEC --> Decrease   R_GRADIENT_POLARITY_INC --> Increase)
    R_GRADIENT_POLARITY_DEC |          // [100h]Byte 2
    //    G Gradient Polarity (range: G_GRADIENT_POLARITY_DEC --> Decrease   G_GRADIENT_POLARITY_INC --> Increase)
    G_GRADIENT_POLARITY_INC |
    //    B Gradient Polarity (range: B_GRADIENT_POLARITY_DEC --> Decrease   B_GRADIENT_POLARITY_INC --> Increase)
    B_GRADIENT_POLARITY_DEC |
    //    Gradient level(range: 0~3<1 step per level~Repeat 4step per level>)
    GRADIENT_LEVEL(0) |
    //    Enable red color gradient
    R_COLOR_GRADIENT_EN(0) |
    //    Enable green color gradient
    G_COLOR_GRADIENT_EN(0) |
    //    Enable blue color gradient
    B_COLOR_GRADIENT_EN(0),

    RESERVED,                          // [103h]Byte0
    //    Per gradient level(range: 0 --> 8 level/1~7 --> 1~7 level
    // |  window color index in 16-color LUT(range: 0~15)
    GRADIENT_PER_LEVEL(0) | WINDOW_COLOR(15), // [103h]Byte1
    //    Gradient function(range: 0 --> Disable   1 --> Enable)
    GRADIENT_FUNCTION_EN(0) |                // [103h]Byte2
    //    Gradient direction(range: 0 --> Horizontal   1 --> Vertical)
    GRADIENT_DIRECTION_HOR |
    //    Shadow/border/3D button(range: 0 --> Disable   1 --> Enable)
    SHADOW_BORDER_EN(1) |
    //    Window type(Range 0~7)
    WINDOW_TYPE(WT_3DBUTTON_TYPE1) |
    //    Window enable or disable
    WINDOW_ENABLE(1),
};
 
//----------------------------------------------------------------------------------------------------
BYTE code tOSD_LINE_WINDOW_STYLE[] =
{
    // OSD window number
    WINNO(_LINE_WINDOW),

    //    Window shadow/border width or 3D button thickness in pixel unit(range: 1~8 pixel)
    // |  Window shadow/border height in line unit(range: 1~8 line)
    SB_THICKNESS(0) | SB_HEIGHT(0) ,       // [104h]Byte0
    //    Window shadow color index in 16-color LUT for 3D window,it is the left-top/bottom border color(range: 0~15)
    // |  Window border color index in 16-color LUT for 3D window,it is the right-bottom/top border color(range: 0~15)
    SHADOW_COLOR(0) | BORDER_COLOR(0),     // [104h]Byte1

    RESERVED,                              // [104h]Byte2

    RESERVED,                              // [107h]Byte0
    //    Window color index in 16-color LUT(range: 0~15)
    WINDOW_COLOR(4),                       // [107h]Byte1
    //    Shadow/border/3D button(range: 0 --> Disable   1 --> Enable)
    SHADOW_BORDER_EN(0) |                  // [107h]Byte2
    //    Window type(Range 0~7)
    WINDOW_TYPE(WT_3DBUTTON_TYPE1) |
    //    Window enable or disable
    WINDOW_ENABLE(1),
};
  
//----------------------------------------------------------------------------------------------------
BYTE code tOSD_SELECT_MAIN_WINDOW_STYLE[] =
{
    // OSD window number
    WINNO(_SELECT_MAIN_WINDOW),

    //    Window shadow/border width or 3D button thickness in pixel unit(range: 1~8 pixel)
    // |  Window shadow/border height in line unit(range: 1~8 line)
    SB_THICKNESS(1) | SB_HEIGHT(1),       // [104h]Byte0
    //    Window shadow color index in 16-color LUT for 3D window,it is the left-top/bottom border color(range: 0~15)
    // |  Window border color index in 16-color LUT for 3D window,it is the right-bottom/top border color(range: 0~15)
    SHADOW_COLOR(9) | BORDER_COLOR(10),     // [104h]Byte1

    RESERVED,                              // [104h]Byte2

    RESERVED,                              // [107h]Byte0
    //    Window color index in 16-color LUT(range: 0~15)
    WINDOW_COLOR(4),                       // [107h]Byte1
    //    Shadow/border/3D button(range: 0 --> Disable   1 --> Enable)
    SHADOW_BORDER_EN(1) |                  // [107h]Byte2
    //    Window type(Range 0~7)
    WINDOW_TYPE(WT_3DBUTTON_TYPE1) |
    //    Window enable or disable
    WINDOW_ENABLE(1),
}; 


//----------------------------------------------------------------------------------------------------
BYTE code tOSD_SELECT_SUB_WINDOW_STYLE[] =
{
    // OSD window number
    WINNO(_SELECT_SUB_WINDOW),

    //    Window shadow/border width or 3D button thickness in pixel unit(range: 1~8 pixel)
    // |  Window shadow/border height in line unit(range: 1~8 line)
    SB_THICKNESS(1) | SB_HEIGHT(1),       // [104h]Byte0
    //    Window shadow color index in 16-color LUT for 3D window,it is the left-top/bottom border color(range: 0~15)
    // |  Window border color index in 16-color LUT for 3D window,it is the right-bottom/top border color(range: 0~15)
    SHADOW_COLOR(9) | BORDER_COLOR(10),     // [104h]Byte1

    RESERVED,                              // [104h]Byte2

    RESERVED,                              // [107h]Byte0
    //    Window color index in 16-color LUT(range: 0~15)
    WINDOW_COLOR(4),                       // [107h]Byte1
    //    Shadow/border/3D button(range: 0 --> Disable   1 --> Enable)
    SHADOW_BORDER_EN(1) |                  // [107h]Byte2
    //    Window type(Range 0~7)
    WINDOW_TYPE(WT_3DBUTTON_TYPE1) |
    //    Window enable or disable
    WINDOW_ENABLE(1),
}; 


//------------------------------------------------------------------------------
BYTE code tOSD_MINI_WINDOW_STYLE[] =
{
    // OSD window number
    WINNO(_SELECT_SUB_WINDOW),

    //    Window shadow/border width or 3D button thickness in pixel unit(range: 1~8 pixel)
    // |  Window shadow/border height in line unit(range: 1~8 line)
    SB_THICKNESS(1) | SB_HEIGHT(1) ,       // [104h]Byte0
    //    Window shadow color index in 16-color LUT for 3D window,it is the left-top/bottom border color(range: 0~15)
    // |  Window border color index in 16-color LUT for 3D window,it is the right-bottom/top border color(range: 0~15)
    SHADOW_COLOR(2) | BORDER_COLOR(2),     // [104h]Byte1

    RESERVED,                              // [104h]Byte2

    RESERVED,                              // [107h]Byte0
    //    Window color index in 16-color LUT(range: 0~15)
    WINDOW_COLOR(15),                       // [107h]Byte1
    //    Shadow/border/3D button(range: 0 --> Disable   1 --> Enable)
    SHADOW_BORDER_EN(1) |                  // [107h]Byte2
    //    Window type(Range 0~7)
    WINDOW_TYPE(WT_3DBUTTON_TYPE1) |
    //    Window enable or disable
    WINDOW_ENABLE(1),
};

//------------------------------------------------------------------------------
BYTE code tPALETTE_0[] =
{
0x9F,0xED,0xAB,    0xFF,0xFF,0xFF,    
0xFF,0x00,0x00,    0x00,0x00,0xFF,    
0x00,0x00,0x00,    0xFF,0xFF,0x00,    
0x00,0xFF,0xFF,    0xFF,0x00,0xFF,    
0xFF,0x80,0x00,    0xC0,0xC0,0xC0,    
0x80,0x80,0x80,    0x7A,0xB4,0x81,    
0x56,0xF0,0x6D,    0xCD,0xF8,0xD4,    
//0x9F,0xED,0xAB,    0x78,0xAE,0x6F,   //0xB4,0xF1,0xBF
0x9F,0xED,0xAB,    0xA0,0xBF,0x7D,
};

//------------------------------------------------------------------------------
code BYTE sBright_ENG[] = "Brightness";
code BYTE sBright_Deu[] = "Helligkeit";
code BYTE sBright_Fra[] = "Luminosit\x3D";
code BYTE sBright_Ita[] = "Luminosit\x3F";
code BYTE sBright_Spa[] = "Brillo";
code BYTE sBright_CHI_S[] = "\x7B\x7C";
//code BYTE sBright_CHI_T[] = "";
code BYTE *sBright[] = {sBright_ENG,sBright_Deu,sBright_Fra,sBright_Ita,sBright_Spa,sBright_CHI_S,sBright_CHI_S};

//------------------------------------------------------------------------------
code BYTE sContrast_ENG[] = "Contrast";
code BYTE sContrast_Deu[] = "Kontrast";
code BYTE sContrast_Fra[] = "Contraste";
code BYTE sContrast_Ita[] = "Contrasto";
code BYTE sContrast_Spa[] = "Contrste";
code BYTE sContrast_CHI_S[] = "\xC3\x7D\x7C";
//code BYTE sContrast_CHI_T[] = "";
code BYTE *sContrast[] = {sContrast_ENG,sContrast_Deu,sContrast_Fra,sContrast_Ita,sContrast_Spa,sContrast_CHI_S,sContrast_CHI_S};

#if(_COLOR_TEMP)
//------------------------------------------------------------------------------
code BYTE sColorTemp_ENG[] = "Color Temp.";
code BYTE sColorTemp_Deu[] = "Farbtemp.";
code BYTE sColorTemp_Fra[] = "Temp. Couleurs";
code BYTE sColorTemp_Ita[] = "Temperatura colore";
code BYTE sColorTemp_Spa[] = "Temp. de color";
code BYTE sColorTemp_CHI_S[] = "\x7F\xBD";
//code BYTE sContrast_CHI_T[] = "";
code BYTE *sColorTemp[] = {sColorTemp_ENG,sColorTemp_Deu,sColorTemp_Fra,sColorTemp_Ita,sColorTemp_Spa,sColorTemp_CHI_S,sColorTemp_CHI_S};

//------------------------------------------------------------------------------
code BYTE sColorTemp9300[] = "9300K";
code BYTE sColorTemp6500[] = "6500K";
code BYTE sColorTemp5800[] = "5800K";
code BYTE sColorTempSRGB[] = "SRGB";

code BYTE sColorTempUser_Eng[]   = "User";
code BYTE sColorTempUser_Deu[]   = "Benutzer";
code BYTE sColorTempUser_Fra[]   = "Utilisateur";
code BYTE sColorTempUser_Ita[]   = "Utente";
code BYTE sColorTempUser_Spa[]   = "Usuario";
code BYTE sColorTempUser_CHI_S[] = "\x9A\xB4";
//code BYTE sColorTempUser_CHI_T[] = "";

code BYTE *sColorTempUser[] = {sColorTempUser_Eng,sColorTempUser_Deu,sColorTempUser_Fra,sColorTempUser_Ita,sColorTempUser_Spa,sColorTempUser_CHI_S,sColorTempUser_CHI_S};
#endif

#if(_VGA_SUPPORT)
//------------------------------------------------------------------------------
code BYTE sPhase_ENG[] = "Phase";
code BYTE sPhase_Deu[] = "Phase";
code BYTE sPhase_Fra[] = "Phase";
code BYTE sPhase_Ita[] = "Fase";
code BYTE sPhase_Spa[] = "Fase";
code BYTE sPhase_CHI_S[] = "\x99\x83";
//code BYTE sPhase_CHI_T[] = "";

code BYTE *sPhase[] = {sPhase_ENG,sPhase_Deu,sPhase_Fra,sPhase_Ita,sPhase_Spa,sPhase_CHI_S,sPhase_CHI_S};

//------------------------------------------------------------------------------
code BYTE sClock_ENG[] = "Clock";
code BYTE sClock_Deu[] = "Takt";
code BYTE sClock_Fra[] = "Horloge";
code BYTE sClock_Ita[] = "Temporizzazione";
code BYTE sClock_Spa[] = "Reloj";
code BYTE sClock_CHI_S[] = "\xB7\xB5";
//code BYTE sClock_CHI_T[] = "";

code BYTE *sClock[] = {sClock_ENG,sClock_Deu,sClock_Fra,sClock_Ita,sClock_Spa,sClock_CHI_S,sClock_CHI_S};

//------------------------------------------------------------------------------
code BYTE sHPos_ENG[] = "H.Position";
code BYTE sHPos_Deu[] = "H.-Position";
code BYTE sHPos_Fra[] = "Position H.";
code BYTE sHPos_Ita[] = "Posizione Ori.";
code BYTE sHPos_Spa[] = "Posici\x3Fn H";
code BYTE sHPos_CHI_S[] = "\x81\x82\x83\x84"; 
//code BYTE sHPos_CHI_T[] = "";

code BYTE *sHPos[] = {sHPos_ENG,sHPos_Deu,sHPos_Fra,sHPos_Ita,sHPos_Spa,sHPos_CHI_S,sHPos_CHI_S};

//------------------------------------------------------------------------------
code BYTE sVPos_ENG[] = "V.Position";
code BYTE sVPos_Deu[] = "V.-Position";
code BYTE sVPos_Fra[] = "Position V.";
code BYTE sVPos_Ita[] = "Posizione Ver.";
code BYTE sVPos_Spa[] = "Posici\x3Fn V";
code BYTE sVPos_CHI_S[] = "\x85\x86\x83\x84";
//code BYTE sVPos_CHI_T[] = "";

code BYTE *sVPos[] = {sVPos_ENG,sVPos_Deu,sVPos_Fra,sVPos_Ita,sVPos_Spa,sVPos_CHI_S,sVPos_CHI_S};
#endif

//------------------------------------------------------------------------------
code BYTE sLanguage_ENG[] = "Language";
code BYTE sLanguage_Deu[] = "Sprache";
code BYTE sLanguage_Fra[] = "Langue";
code BYTE sLanguage_Ita[] = "Lingua";
code BYTE sLanguage_Spa[] = "Lenguaje";
code BYTE sLanguage_CHI_S[] = "\xAF\x80";
//code BYTE sLanguage_CHI_T[] = "";

code BYTE *sLanguage[] = {sLanguage_ENG,sLanguage_Deu,sLanguage_Fra,sLanguage_Ita,sLanguage_Spa,sLanguage_CHI_S,sLanguage_CHI_S};

//------------------------------------------------------------------------------
code BYTE sLangName_ENG[] = "English";
code BYTE sLangName_Deu[] = "Deutsch";
code BYTE sLangName_Fra[] = "Francais";
code BYTE sLangName_Ita[] = "Italiano";
code BYTE sLangName_Spa[] = "Espa\x60ol";
code BYTE sLangName_CHI_S[] = "\x04\x05\x06\x07";
code BYTE sLangName_CHI_T[] = "\x08\x09\x06\x07";

code BYTE *sLangName[] = {sLangName_ENG,sLangName_Deu,sLangName_Fra,sLangName_Ita,sLangName_Spa,sLangName_CHI_S,sLangName_CHI_T};

#if(_OSD_POSITION_ADJ_CTRL)
//------------------------------------------------------------------------------
code BYTE sOSDHPos_Eng[]   = "OSD H.Position";
code BYTE sOSDHPos_Deu[]   = "OSD H.-Position";
code BYTE sOSDHPos_Fra[]   = "Position H. OSD";
code BYTE sOSDHPos_Ita[]   = "Posizione Ori. OSD";
code BYTE sOSDHPos_Spa[]   = "Posici\x3Fn H OSD";
code BYTE sOSDHPos_CHI_S[] = "\xB2\xB3\x81\x82\x83\x84";
//code BYTE sOSDHPos_CHI_T[] = "";

code BYTE *sOSDHPosition[] = {sOSDHPos_Eng,sOSDHPos_Deu,sOSDHPos_Fra,sOSDHPos_Ita,sOSDHPos_Spa,sOSDHPos_CHI_S,sOSDHPos_CHI_S};

//------------------------------------------------------------------------------
code BYTE sOSDVPos_Eng[]   = "OSD V.Position";
code BYTE sOSDVPos_Deu[]   = "OSD V.-Position";
code BYTE sOSDVPos_Fra[]   = "Position V. OSD";
code BYTE sOSDVPos_Ita[]   = "Posizione Ver. OSD";
code BYTE sOSDVPos_Spa[]   = "Posici\x3Fn V OSD";
code BYTE sOSDVPos_CHI_S[] = "\xB2\xB3\x84\x85\x83\x84";
//code BYTE sOSDVPos_CHI_T[] = "";


code BYTE *sOSDVPosition[] = {sOSDVPos_Eng,sOSDVPos_Deu,sOSDVPos_Fra,sOSDVPos_Ita,sOSDVPos_Spa,sOSDVPos_CHI_S,sOSDVPos_CHI_S};
#endif  // end #if(_OSD_POSITION_ADJ_CTRL)

#if(_OSD_TIMEOUT_ADJ_CTRL)
//------------------------------------------------------------------------------
code BYTE sOSDTimeOut_Eng[]   = "OSD Timeout";
code BYTE sOSDTimeOut_Deu[]   = "OSD-Auszeit";
code BYTE sOSDTimeOut_Fra[]   = "Dur\x3D\x65 OSD";
code BYTE sOSDTimeOut_Ita[]   = "Timeout OSD";
code BYTE sOSDTimeOut_Spa[]   = "Tiemp. esp. OSD";
code BYTE sOSDTimeOut_CHI_S[] = "\xB2\xB3\xB6\x87\xB7\xB8";
//code BYTE sOSDTimeOut_CHI_T[] = "";

code BYTE *sOSDTimeOut[] = {sOSDTimeOut_Eng,sOSDTimeOut_Deu,sOSDTimeOut_Fra,sOSDTimeOut_Ita,sOSDTimeOut_Spa,sOSDTimeOut_CHI_S,sOSDTimeOut_CHI_S};
#endif

#if(_ALPHA_BLENDING_ADJ == _ON)
//------------------------------------------------------------------------------
code BYTE sOSDTranslucent_Eng[]   = "Translucent";
code BYTE sOSDTranslucent_Deu[]   = "Transparent";
code BYTE sOSDTranslucent_Fra[]   = "Translucide";
code BYTE sOSDTranslucent_Ita[]   = "Traslucido";
code BYTE sOSDTranslucent_Spa[]   = "Trasl\x5E\x63ido";
code BYTE sOSDTranslucent_CHI_S[] = "\xB2\xB3\x88\x89\x7C";
//code BYTE sOSDTranslucent_CHI_T[] = "";

code BYTE *sOSDTranslucent[] = {sOSDTranslucent_Eng,sOSDTranslucent_Deu,sOSDTranslucent_Fra,sOSDTranslucent_Ita,sOSDTranslucent_Spa,sOSDTranslucent_CHI_S,sOSDTranslucent_CHI_S};
#endif

#if(_OSD_DISPLAY_SIZE_ADJ == _ON)
//------------------------------------------------------------------------------
code BYTE sOSDSize_Eng[]   = "OSD Size";
code BYTE sOSDSize_Deu[]   = "OSD Grootte";
code BYTE sOSDSize_Fra[]   = "OSD Dimension";
code BYTE sOSDSize_Ita[]   = "OSD Dimensione";
code BYTE sOSDSize_Spa[]   = "OSD Dimension";
code BYTE sOSDSize_CHI_S[] = "\xB2\xB3\xB9\x8A";
//code BYTE sOSDSize_CHI_T[] = "";

code BYTE *sOSDSize[] = {sOSDSize_Eng,sOSDSize_Deu,sOSDSize_Fra,sOSDSize_Ita,sOSDSize_Spa,sOSDSize_CHI_S,sOSDSize_CHI_S};
#endif

//------------------------------------------------------------------------------
code BYTE sAuto_ENG[] = "Auto Config";
code BYTE sAuto_Deu[] = "Auto-konfigurieren";
code BYTE sAuto_Fra[] = "Config. Auto";
code BYTE sAuto_Ita[] = "Config. Autom.";
code BYTE sAuto_Spa[] = "Config. autom\x3Ftica";
code BYTE sAuto_CHI_S[] = "\x95\xA9\xAE\x98";
//code BYTE sAuto_CHI_T[] = "";

code BYTE *sAuto[] = {sAuto_ENG,sAuto_Deu,sAuto_Fra,sAuto_Ita,sAuto_Spa,sAuto_CHI_S,sAuto_CHI_S};


//------------------------------------------------------------------------------
code BYTE sAutoColor_ENG[] = "Auto Color";
code BYTE sAutoColor_Deu[] = "Automatische Farbe";
code BYTE sAutoColor_Fra[] = "Couleur Automatique";
code BYTE sAutoColor_Ita[] = "Colore Automatico";
code BYTE sAutoColor_Spa[] = "Color Autom\x3Ftico";
code BYTE sAutoColor_CHI_S[] = "\x7F\x90\x95\xA9\xAE\x98";
//code BYTE sAutoColor_CHI_T[] = "";

code BYTE *sAutoColor[] = {sAutoColor_ENG,sAutoColor_Deu,sAutoColor_Fra,sAutoColor_Ita,sAutoColor_Spa,sAutoColor_CHI_S,sAutoColor_CHI_S};

#if(_SOUND_PROCESSOR == _ENABLE)
//------------------------------------------------------------------------------
code BYTE sBalance_Eng[]   = "Balance";
code BYTE sBalance_Deu[]   = "Balance";
code BYTE sBalance_Fra[]   = "Balance";
code BYTE sBalance_Ita[]   = "Balance";
code BYTE sBalance_Spa[]   = "Balance";
code BYTE sBalance_CHI_S[] = "\x82\x96";
//code BYTE sBalance_CHI_T[] = "";

code BYTE *sBalance[] = {sBalance_Eng,sBalance_Deu,sBalance_Fra,sBalance_Ita,sBalance_Spa,sBalance_CHI_S,sBalance_CHI_S};

//------------------------------------------------------------------------------
code BYTE sBass_Eng[]   = "Bass";
code BYTE sBass_Deu[]   = "Bass";
code BYTE sBass_Fra[]   = "Bass";
code BYTE sBass_Ita[]   = "Bass";
code BYTE sBass_Spa[]   = "Bass";
code BYTE sBass_CHI_S[] = "\xA3\x8B";
//code BYTE sBass_CHI_T[] = "";

code BYTE *sBass[] = {sBass_Eng,sBass_Deu,sBass_Fra,sBass_Ita,sBass_Spa,sBass_CHI_S,sBass_CHI_S};

//------------------------------------------------------------------------------
code BYTE sTreble_Eng[]   = "Treble";
code BYTE sTreble_Deu[]   = "Treble";
code BYTE sTreble_Fra[]   = "Treble";
code BYTE sTreble_Ita[]   = "Treble";
code BYTE sTreble_Spa[]   = "Treble";
code BYTE sTreble_CHI_S[] = "\x97\x8B";
//code BYTE sTreble_CHI_T[] = "";

code BYTE *sTreble[] = {sTreble_Eng,sTreble_Deu,sTreble_Fra,sTreble_Ita,sTreble_Spa,sTreble_CHI_S,sTreble_CHI_S};

//------------------------------------------------------------------------------
code BYTE sSRS_Eng[]   = "SRS";
code BYTE sSRS_Deu[]   = "SRS";
code BYTE sSRS_Fra[]   = "SRS";
code BYTE sSRS_Ita[]   = "SRS";
code BYTE sSRS_Spa[]   = "SRS";
code BYTE sSRS_CHI_S[] = "\xB0\xB1";
//code BYTE sSRS_CHI_T[] = "";

code BYTE *sSRS[] = {sSRS_Eng,sSRS_Deu,sSRS_Fra,sSRS_Ita,sSRS_Spa,sSRS_CHI_S,sSRS_CHI_S};

//------------------------------------------------------------------------------
code BYTE sBBE_Eng[]   = "BBE";
code BYTE sBBE_Deu[]   = "BBE";
code BYTE sBBE_Fra[]   = "BBE";
code BYTE sBBE_Ita[]   = "BBE";
code BYTE sBBE_Spa[]   = "BBE";
code BYTE sBBE_CHI_S[] = "BBE";
//code BYTE sBBE_CHI_T[] = "";

code BYTE *sBBE[] = {sBBE_Eng,sBBE_Deu,sBBE_Fra,sBBE_Ita,sBBE_Spa,sBBE_CHI_S,sBBE_CHI_S};
#endif  // end #if(_SOUND_PROCESSOR == _ENABLE)

//------------------------------------------------------------------------------
code BYTE sReset_ENG[] = "Reset";
code BYTE sReset_Deu[] = "Zur\x5F\x63k-setzen";
code BYTE sReset_Fra[] = "R\x3Dinitialisation";
code BYTE sReset_Ita[] = "Ripristino";
code BYTE sReset_Spa[] = "Restaurar";
code BYTE sReset_CHI_S[] = "\xBE\x83";
//code BYTE sReset_CHI_T[] = "";

code BYTE *sReset[] = {sReset_ENG,sReset_Deu,sReset_Fra,sReset_Ita,sReset_Spa,sReset_CHI_S,sReset_CHI_S};

//------------------------------------------------------------------------------
code BYTE sExit_ENG[] = "Exit";
code BYTE sExit_Deu[] = "Ausgang";
code BYTE sExit_Fra[] = "Sortie";
code BYTE sExit_Ita[] = "Uscire";
code BYTE sExit_Spa[] = "Salida";
code BYTE sExit_CHI_S[] = "\x93\x94";
//code BYTE sExit_CHI_T[] = "";

code BYTE *sExit[] = {sExit_ENG,sExit_Deu,sExit_Fra,sExit_Ita,sExit_Spa,sExit_CHI_S,sExit_CHI_S};

//------------------------------------------------------------------------------
code BYTE sNoSignal_ENG[] = "No Signal";
code BYTE sNoSignal_Deu[] = "Kein Signal";
code BYTE sNoSignal_Fra[] = "Sans Signal";
code BYTE sNoSignal_Ita[] = "Senza Segnale";
code BYTE sNoSignal_Spa[] = "Sin Seg\x19\x41l";
code BYTE sNoSignal_CHI_S[] = "\xC4\xA4\xC7";
//code BYTE sNoSignal_CHI_T[] = "";

code BYTE *sNoSignal[] = {sNoSignal_ENG,sNoSignal_Deu,sNoSignal_Fra,sNoSignal_Ita,sNoSignal_Spa,sNoSignal_CHI_S,sNoSignal_CHI_S};

//------------------------------------------------------------------------------
code BYTE sNoCable_ENG[] = "Cable Not Connected";
code BYTE sNoCable_Deu[] = "Leitung nichtangeschlossen";
code BYTE sNoCable_Fra[] = "Cable nonconnec\x3D";
code BYTE sNoCable_Ita[] = "Cavo nonconnesso";
code BYTE sNoCable_Spa[] = "Cable noconectado";
code BYTE sNoCable_CHI_S[] = "\xA5\xC8\xA6\xC9";
//code BYTE sNoCable_CHI_T[] = "";

code BYTE *sNoCable[] = {sNoCable_ENG,sNoCable_Deu,sNoCable_Fra,sNoCable_Ita,sNoCable_Spa,sNoCable_CHI_S,sNoCable_CHI_S};

//------------------------------------------------------------------------------
code BYTE sNotSupport_ENG[] = "Not Support";
code BYTE sNotSupport_Deu[] = "Unerreichbar";
code BYTE sNotSupport_Fra[] = "Hors Limite";
code BYTE sNotSupport_Ita[] = "Fuori Rango";
code BYTE sNotSupport_Spa[] = "Fuera Ddalcance";
code BYTE sNotSupport_CHI_S[] = "\xA4\xC7\xA7\x94\xC5\xC6";
//code BYTE sNotSupport_CHI_T[] = "";

code BYTE *sNotSupport[] = {sNotSupport_ENG,sNotSupport_Deu,sNotSupport_Fra,sNotSupport_Ita,sNotSupport_Spa,sNotSupport_CHI_S,sNotSupport_CHI_S};

//------------------------------------------------------------------------------
//code BYTE sAVBright_ENG[] = "BRIGHT";			//V309
//code BYTE sAVBright_CHI_S[] = "\xAA\xAB\x86\x87";
//code BYTE sAVBright_CHI_T[] = "";
//code BYTE *sAVBright[] = {sBright_ENG,sBright_Deu,sBright_Fra,sBright_Ita,sBright_Spa,sBright_CHI_S,sBright_CHI_S};

//------------------------------------------------------------------------------
//code BYTE sAVContrast_ENG[] = "CONTRAST";		//V309
//code BYTE sAVContrast_CHI_S[] = "\xE0\xE1\xA4\xA5\x86\x87";
//code BYTE sAVContrast_CHI_T[] = "";
//code BYTE *sAVContrast[] = {sContrast_ENG,sContrast_Deu,sContrast_Fra,sContrast_Ita,sContrast_Spa,sContrast_CHI_S,sContrast_CHI_S};

//------------------------------------------------------------------------------
code BYTE sHue_ENG[] = "Hue";
code BYTE sHue_Deu[] = "Farbton";
code BYTE sHue_Fra[] = "Teinte";
code BYTE sHue_Ita[] = "Tonalit\x60";
code BYTE sHue_Spa[] = "Matiz";
code BYTE sHue_CHI_S[] = "\x7F\xAE";
//code BYTE sHue_CHI_T[] = "";

code BYTE *sHue[] = {sHue_ENG,sHue_Deu,sHue_Fra,sHue_Ita,sHue_Spa,sHue_CHI_S,sHue_CHI_S};

//------------------------------------------------------------------------------
code BYTE sSaturation_ENG[] = "Saturation";
code BYTE sSaturation_Deu[] = "S\x3Cttigung";
code BYTE sSaturation_Fra[] = "Saturation";
code BYTE sSaturation_Ita[] = "Saturazione";
code BYTE sSaturation_Spa[] = "Saturaci\x3Fn";
code BYTE sSaturation_CHI_S[] = "\xAD\x7E\x7C";
//code BYTE sSaturation_CHI_T[] = "";

code BYTE *sSaturation[] = {sSaturation_ENG,sSaturation_Deu,sSaturation_Fra,sSaturation_Ita,sSaturation_Spa,sSaturation_CHI_S,sSaturation_CHI_S};

//------------------------------------------------------------------------------
code BYTE sTVSystem_ENG[] = "TV System";
code BYTE sTVSystem_Deu[] = "TV System";
code BYTE sTVSystem_Fra[] = "Syst\x3Eme TV";
code BYTE sTVSystem_Ita[] = "Sistema TV";
code BYTE sTVSystem_Spa[] = "TV Sistema";
code BYTE sTVSystem_CHI_S[] = "\x90\x7F\xA0\xBF";
//code BYTE sTVSystem_CHI_T[] = "";

code BYTE *sTVSystem[] = {sTVSystem_ENG,sTVSystem_Deu,sTVSystem_Fra,sTVSystem_Ita,sTVSystem_Spa,sTVSystem_CHI_S,sTVSystem_CHI_S};

//------------------------------------------------------------------------------
code BYTE sSoundSystem_ENG[] = "Sound System";
code BYTE sSoundSystem_Deu[] = "Schall System";
code BYTE sSoundSystem_Fra[] = "Syst\x3Eme Sonore";
code BYTE sSoundSystem_Ita[] = "Sistema Suona";
code BYTE sSoundSystem_Spa[] = "Sistema Sonido";
code BYTE sSoundSystem_CHI_S[] = "\xEC\xED\x98\x99\xB8\xB9\xAC\xAD";
//code BYTE sSoundSystem_CHI_T[] = "";

code BYTE *sSoundSystem[] = {sSoundSystem_ENG,sSoundSystem_Deu,sSoundSystem_Fra,sSoundSystem_Ita,sSoundSystem_Spa,sSoundSystem_CHI_S,sSoundSystem_CHI_S};

//------------------------------------------------------------------------------
code BYTE sAutoSearch_ENG[] = "Auto Search";
code BYTE sAutoSearch_Deu[] = "Auto.Suche";
code BYTE sAutoSearch_Fra[] = "Recherche Auto";
code BYTE sAutoSearch_Ita[] = "Cerca Auta";
code BYTE sAutoSearch_Spa[] = "Auto-Selecci\x3Fn";
code BYTE sAutoSearch_CHI_S[] = "\x95\xA9\x9B\x9C";
//code BYTE sAutoSearch_CHI_T[] = "";

code BYTE *sAutoSearch[] = {sAutoSearch_ENG,sAutoSearch_Deu,sAutoSearch_Fra,sAutoSearch_Ita,sAutoSearch_Spa,sAutoSearch_CHI_S,sAutoSearch_CHI_S};

//------------------------------------------------------------------------------
code BYTE sManualSearch_ENG[] = "Manual Search";
code BYTE sManualSearch_Deu[] = "Manuelle Suche";
code BYTE sManualSearch_Fra[] = "Recher.Manuel";
code BYTE sManualSearch_Ita[] = "Cerca Manuale";
code BYTE sManualSearch_Spa[] = "Selec.Manual";
code BYTE sManualSearch_CHI_S[] = "\x9D\xA9\x9B\x9C";
//code BYTE sManualSearch_CHI_T[] = "";

code BYTE *sManualSearch[] = {sManualSearch_ENG,sManualSearch_Deu,sManualSearch_Fra,sManualSearch_Ita,sManualSearch_Spa,sManualSearch_CHI_S,sManualSearch_CHI_S};

//------------------------------------------------------------------------------
code BYTE sTuning_ENG[] = "Tuning";
code BYTE sTuning_Deu[] = "Abstimmung";
code BYTE sTuning_Fra[] = "R\x3Dglage";
code BYTE sTuning_Ita[] = "Girando";
code BYTE sTuning_Spa[] = "Fina Modifica";
code BYTE sTuning_CHI_S[] = "\x9E\xAE";
//code BYTE sTuning_CHI_T[] = "";

code BYTE *sTuning[] = {sTuning_ENG,sTuning_Deu,sTuning_Fra,sTuning_Ita,sTuning_Spa,sTuning_CHI_S,sTuning_CHI_S};
//------------------------------------------------------------------------------
code BYTE sTuning_Inc[] = "\x2C 1";  // +1
code BYTE sTuning_Dec[] = "\x2D 1";  // -1

code BYTE *sTuningState[] = {sTuning_Dec, sTuning_Inc};

//------------------------------------------------------------------------------
code BYTE sChannel_ENG[] = "Channel";
//code BYTE sChannel_Deu[] = "";
//code BYTE sChannel_Fra[] = "";
//code BYTE sChannel_Ita[] = "";
//code BYTE sChannel_Spa[] = "";
code BYTE sChannel_CHI_S[] = "\xC0\x9F";
//code BYTE sChannel_CHI_T[] = "";

code BYTE *sChannel[] = {sChannel_ENG,sChannel_ENG,sChannel_ENG,sChannel_ENG,sChannel_ENG,sChannel_CHI_S,sChannel_CHI_S};

//------------------------------------------------------------------------------
code BYTE sSwap_ENG[] = "Swap";
//code BYTE sSwap_Deu[] = "";
//code BYTE sSwap_Fra[] = "";
//code BYTE sSwap_Ita[] = "";
//code BYTE sSwap_Spa[] = "";
code BYTE sSwap_CHI_S[] = "\xC0\x9F\xA1\xC1";
//code BYTE sSwap_CHI_T[] = "";

code BYTE *sSwap[] = {sSwap_ENG,sSwap_ENG,sSwap_ENG,sSwap_ENG,sSwap_ENG,sSwap_CHI_S,sSwap_CHI_S};

//------------------------------------------------------------------------------
code BYTE sSkip_ENG[] = "Skip";
//code BYTE sSkip_Deu[] = "";
//code BYTE sSkip_Fra[] = "";
//code BYTE sSkip_Ita[] = "";
//code BYTE sSkip_Spa[] = "";
code BYTE sSkip_CHI_S[] = "\xC0\x9F\xA2\xC2";
//code BYTE sSkip_CHI_T[] = "";

code BYTE *sSkip[] = {sSkip_ENG,sSkip_ENG,sSkip_ENG,sSkip_ENG,sSkip_ENG,sSkip_CHI_S,sSkip_CHI_S};

//------------------------------------------------------------------------------
code BYTE sBlue_ENG[] = "Blue";
code BYTE sBlue_Deu[] = "Blau";
code BYTE sBlue_Fra[] = "Bleu";
code BYTE sBlue_Ita[] = "Blu";
code BYTE sBlue_Spa[] = "Azul";
code BYTE sBlue_CHI_S[] = "\xA8\x8F";
//code BYTE sBlue_CHI_T[] = "";

code BYTE *sBlue[] = {sBlue_ENG,sBlue_ENG,sBlue_ENG,sBlue_ENG,sBlue_ENG,sBlue_CHI_S,sBlue_CHI_S};

#if(_SLEEP_FUNC)
//------------------------------------------------------------------------------
code BYTE sAutoPowerDown_ENG[] = "Auto Power Down";//AUTO POWER DOWN";
//code BYTE sAutoPowerDown_Deu[] = "";
//code BYTE sAutoPowerDown_Fra[] = "";
//code BYTE sAutoPowerDown_Ita[] = "";
//code BYTE sAutoPowerDown_Spa[] = "";
code BYTE sAutoPowerDown_CHI_S[] = "\x95\xA9\xAA\xAB";
//code BYTE sAutoPowerDown_CHI_T[] = "";

code BYTE *sAutoPowerDown[] = {sAutoPowerDown_ENG,sAutoPowerDown_ENG,sAutoPowerDown_ENG,sAutoPowerDown_ENG,sAutoPowerDown_ENG,sAutoPowerDown_CHI_S,sAutoPowerDown_CHI_S};
#endif

#if(_IMAGE_COLOR_MODE)
//------------------------------------------------------------------------------
code BYTE sColorMode_ENG[]   = "Color Mode";
code BYTE sColorMode_Deu[]   = "Color Mode";
code BYTE sColorMode_Fra[]   = "Color Mode";
code BYTE sColorMode_Ita[]   = "Color Mode";
code BYTE sColorMode_Spa[]   = "Color Mode";
code BYTE sColorMode_CHI_S[] = "\x7F\x90\x91\x92";
//code BYTE sColorMode_CHI_T[] = "";

code BYTE *sColorMode[] = {sColorMode_ENG,sColorMode_Deu,sColorMode_Fra,sColorMode_Ita,sColorMode_Spa,sColorMode_CHI_S,sColorMode_CHI_S};

//------------------------------------------------------------------------------
code BYTE sColorMode0_Eng[]   = "Mode0";
code BYTE sColorMode0_Deu[]   = "Mode0";
code BYTE sColorMode0_Fra[]   = "Mode0";
code BYTE sColorMode0_Ita[]   = "Mode0";
code BYTE sColorMode0_Spa[]   = "Mode0";
code BYTE sColorMode0_CHI_S[] = "Mode0";
//code BYTE sColorMode0_CHI_T[] = "";

code BYTE *sColorMode0[] = {sColorMode0_Eng, sColorMode0_Deu, sColorMode0_Fra, sColorMode0_Ita, sColorMode0_Spa, sColorMode0_CHI_S, sColorMode0_CHI_S};

//------------------------------------------------------------------------------
code BYTE sColorMode1_Eng[]   = "Mode1";
code BYTE sColorMode1_Deu[]   = "Mode1";
code BYTE sColorMode1_Fra[]   = "Mode1";
code BYTE sColorMode1_Ita[]   = "Mode1";
code BYTE sColorMode1_Spa[]   = "Mode1";
code BYTE sColorMode1_CHI_S[] = "Mode1";
//code BYTE sColorMode1_CHI_T[] = "";

code BYTE *sColorMode1[] = {sColorMode1_Eng, sColorMode1_Deu, sColorMode1_Fra, sColorMode1_Ita, sColorMode1_Spa, sColorMode1_CHI_S, sColorMode1_CHI_S};

//------------------------------------------------------------------------------
code BYTE sColorMode2_Eng[]   = "Mode2";
code BYTE sColorMode2_Deu[]   = "Mode2";
code BYTE sColorMode2_Fra[]   = "Mode2";
code BYTE sColorMode2_Ita[]   = "Mode2";
code BYTE sColorMode2_Spa[]   = "Mode2";
code BYTE sColorMode2_CHI_S[] = "Mode2";
//code BYTE sColorMode2_CHI_T[] = "";

code BYTE *sColorMode2[] = {sColorMode2_Eng, sColorMode2_Deu, sColorMode2_Fra, sColorMode2_Ita, sColorMode2_Spa, sColorMode2_CHI_S, sColorMode2_CHI_S};

//------------------------------------------------------------------------------
code BYTE sColorMode3_Eng[]   = "Mode3";
code BYTE sColorMode3_Deu[]   = "Mode3";
code BYTE sColorMode3_Fra[]   = "Mode3";
code BYTE sColorMode3_Ita[]   = "Mode3";
code BYTE sColorMode3_Spa[]   = "Mode3";
code BYTE sColorMode3_CHI_S[] = "Mode3";
//code BYTE sColorMode3_CHI_T[] = "";

code BYTE *sColorMode3[] = {sColorMode3_Eng, sColorMode3_Deu, sColorMode3_Fra, sColorMode3_Ita, sColorMode3_Spa, sColorMode3_CHI_S, sColorMode3_CHI_S};

//------------------------------------------------------------------------------
code BYTE sColorMode4_Eng[]   = "Mode4";
code BYTE sColorMode4_Deu[]   = "Mode4";
code BYTE sColorMode4_Fra[]   = "Mode4";
code BYTE sColorMode4_Ita[]   = "Mode4";
code BYTE sColorMode4_Spa[]   = "Mode4";
code BYTE sColorMode4_CHI_S[] = "Mode4";
//code BYTE sColorMode4_CHI_T[] = "";

code BYTE *sColorMode4[] = {sColorMode4_Eng, sColorMode4_Deu, sColorMode4_Fra, sColorMode4_Ita, sColorMode4_Spa, sColorMode4_CHI_S, sColorMode4_CHI_S};

//------------------------------------------------------------------------------
code BYTE sColorMode5_Eng[]   = "Mode5";
code BYTE sColorMode5_Deu[]   = "Mode5";
code BYTE sColorMode5_Fra[]   = "Mode5";
code BYTE sColorMode5_Ita[]   = "Mode5";
code BYTE sColorMode5_Spa[]   = "Mode5";
code BYTE sColorMode5_CHI_S[] = "Mode5";
//code BYTE sColorMode5_CHI_T[] = "";

code BYTE *sColorMode5[] = {sColorMode5_Eng, sColorMode5_Deu, sColorMode5_Fra, sColorMode5_Ita, sColorMode5_Spa, sColorMode5_CHI_S, sColorMode5_CHI_S};
#endif

//------------------------------------------------------------------------------
code BYTE sVolume_ENG[] = "Volume";
code BYTE sVolume_Deu[] = "Lautst\x3Crke";
code BYTE sVolume_Fra[] = "Volume";
code BYTE sVolume_Ita[] = "Volume";
code BYTE sVolume_Spa[] = "Volumen";
code BYTE sVolume_CHI_S[] = "\x8B\x8C";
//code BYTE sVolume_CHI_T[] = "";

code BYTE *sVolume[] = {sVolume_ENG,sVolume_Deu,sVolume_Fra,sVolume_Ita,sVolume_Spa,sVolume_CHI_S,sVolume_CHI_S};

//------------------------------------------------------------------------------
code BYTE sMute_ENG[]   = "Volume Mute";
code BYTE sMute_Deu[]   = "Ton ausschalten";
code BYTE sMute_Fra[]   = "Eteindre le son";
code BYTE sMute_Ita[]   = "Togliere vol.";
code BYTE sMute_Spa[]   = "Descone. Sonido";
code BYTE sMute_CHI_S[] = "\xBA\x8B";
//code BYTE sMute_CHI_T[] = "";

code BYTE *sMute[] = {sMute_ENG,sMute_Deu,sMute_Fra,sMute_Ita,sMute_Spa,sMute_CHI_S,sMute_CHI_S};

#if(_SHARPNESS_ADJ)
//------------------------------------------------------------------------------
code BYTE sSharp_ENG[]   = "Sharp";
code BYTE sSharp_Deu[]   = "Bildsch\x3Crfe";
code BYTE sSharp_Fra[]   = "Nettete";
code BYTE sSharp_Ita[]   = "Definizione";
code BYTE sSharp_Spa[]   = "Nitidez";
code BYTE sSharp_CHI_S[] = "Sharp";
//code BYTE sSharp_CHI_T[] = "Sharp";

code BYTE *sSharp[] = {sSharp_ENG,sSharp_Deu,sSharp_Fra,sSharp_Ita,sSharp_Spa,sSharp_CHI_S};
#endif


//------------------------------------------------------------------------------
code BYTE sVGA[] = "VGA";
code BYTE sDVI[] = "DVI";
code BYTE sVIDEO[] = "AV";//VIDEO";
code BYTE sSVIDEO[] = "SVIDEO";
code BYTE sTV[]   = "TV";
code BYTE sYUV[]  = "YUV";
code BYTE sYPBPR[] = "YPbPr";
code BYTE sDVB[] = "DVB";
code BYTE sHDMI[] = "HDMI";
code BYTE sSCART[] = "SCART";

code BYTE sNTSC[] = "NTSC";
code BYTE sPAL[]  = "PAL";
//------------------------------------------------------------------------------
/*
#define _YPBPR_MODE_576I            0
#define _YPBPR_MODE_480I            1
#define _YPBPR_MODE_576P            2
#define _YPBPR_MODE_480P            3
#define _YPBPR_MODE_720P50          4
#define _YPBPR_MODE_720P60          5
#define _YPBPR_MODE_1080I50         6
#define _YPBPR_MODE_1080I60         7
#define _YPBPR_MODE_1080P50         8
#define _YPBPR_MODE_1080P60         9
                      */
code BYTE sYPbPrMode576I[]     = "576I";
code BYTE sYPbPrMode480I[]     = "480I";
code BYTE sYPbPrMode576P[]     = "576P";
code BYTE sYPbPrMode480P[]     = "480P";
code BYTE sYPbPrMode720P_50[]  = "720P 50HZ";
code BYTE sYPbPrMode720P_60[]  = "720P 60HZ";
code BYTE sYPbPrMode1080I_50[] = "1080I 50HZ";
code BYTE sYPbPrMode1080I_60[] = "1080I 60HZ";
code BYTE sYPbPrMode1080P_50[] = "1080P 50HZ";
code BYTE sYPbPrMode1080P_60[] = "1080P 60HZ";

code BYTE *sYPbPrMode[] =
{
   sYPbPrMode576I,     sYPbPrMode480I,     sYPbPrMode576P,
   sYPbPrMode480P,     sYPbPrMode720P_50,  sYPbPrMode720P_60,       
   sYPbPrMode1080I_50, sYPbPrMode1080I_60, sYPbPrMode1080P_50,
   sYPbPrMode1080P_60
};



//------------------------------------------------------------------------------
code BYTE sTVNTSC_M[]    = "NTSC M";
code BYTE sTVNTSC_4BG[]  = "NTSC 4 BG";
code BYTE sTVNTSC_4DK[]  = "NTSC 4 DK";
code BYTE sTVNTSC_4I[]   = "NTSC 4 I";
code BYTE sTVPAL_M[]     = "PAL M";
code BYTE sTVPAL_BG[]    = "PAL BG";
code BYTE sTVPAL_I[]     = "PAL I";
code BYTE sTVPAL_DK[]    = "PAL DK";
code BYTE sTVPAL_N[]     = "PAL N";
code BYTE sTVSECAM_BG[]  = "SECAM BG";
code BYTE sTVSECAM_DK[]  = "SECAM DK";
code BYTE sTVSECAM_L[]   = "SECAM";
code BYTE sTVSECAM_LL[]  = "SECAM L";
code BYTE sNone[]        = " ";
  /*
code BYTE sTVPAL_BG[]  = "PAL BG";
code BYTE sTVPAL_I[]   = "PAL I";
code BYTE sTVPAL_DK[]  = "PAL DK";
code BYTE sTVNTSC_MN[] = "NTSC MN";

code BYTE *sTVType[4] = {sTVPAL_BG,sTVPAL_I,sTVPAL_DK,sTVNTSC_MN};*/

code BYTE *sTVType[14] = 
{
    sNone,
    sTVNTSC_M,  sTVNTSC_4BG,sTVNTSC_4DK,sTVNTSC_4I,
    sTVPAL_M,   sTVPAL_BG,  sTVPAL_I,   sTVPAL_DK, sTVPAL_N,
    sTVSECAM_BG,sTVSECAM_DK,sTVSECAM_L, sTVSECAM_LL,
    
};

//------------------------------------------------------------------------------
code BYTE sTV65[] = "6.5M";
code BYTE sTV60[] = "6.0M";
code BYTE sTV55[] = "5.5M";
code BYTE sTV45[] = "4.5M";

code BYTE *sTVSoundType[4] = {sTV65,sTV60,sTV55,sTV45};

//------------------------------------------------------------------------------
/*
code BYTE sNoSkip_Eng[] = "No Skip";
//code BYTE sNoSkip_CHI_S[] = " ";

code BYTE *sSkipFunc[2][7] = 
{
    {sNoSkip_Eng,sNoSkip_Eng,sNoSkip_Eng,sNoSkip_Eng,sNoSkip_Eng,sNoSkip_Eng,sNoSkip_Eng},
    {sSkip_ENG,  sSkip_ENG,  sSkip_ENG,  sSkip_ENG  ,sSkip_ENG,  sSkip_CHI_S,sSkip_CHI_S}
};    */

//------------------------------------------------------------------------------
code BYTE sOn_Eng[]   = "On";
code BYTE sOn_Deu[]   = "Aus";
code BYTE sOn_Fra[]   = "Allume";
code BYTE sOn_Ita[]   = "Acceso";
code BYTE sOn_Spa[]   = "Ence";
code BYTE sOn_CHI_S[] = "\xBB";

code BYTE sOff_Eng[]   = "Off";
code BYTE sOff_Deu[]   = "Ein";
code BYTE sOff_Fra[]   = "Eteint";
code BYTE sOff_Ita[]   = "Off";
code BYTE sOff_Spa[]   = "Aag";
code BYTE sOff_CHI_S[] = "\xBC";

code BYTE *sOn_Off[2][7] =
{
     {sOff_Eng,sOff_Deu,sOff_Fra,sOff_Ita,sOff_Spa,sOff_CHI_S,sOff_CHI_S},
     {sOn_Eng, sOn_Deu, sOn_Fra, sOn_Ita, sOn_Spa, sOn_CHI_S, sOn_CHI_S}
};

//------------------------------------------------------------------------------
#if(_VGA_COLOR_SUPPORT == _ON)


// Vivid color Main
code BYTE sText[]    = "Text";
code BYTE sMovie[]   = "Movie";
code BYTE sGraphic[] = "Graphic";
code BYTE sGame[]    = "Game";
code BYTE sNormal[]  = "Normal";
code BYTE sUser[]    = "User";
//------------------------------------------------------------------------------

// User item
code BYTE sVividColor[] = "Vivid Color";
code BYTE sDCC[]        = "DCC";
code BYTE sICM[]        = "ICM";
code BYTE sColor[]      = "Color";
//------------------------------------------------------------------------------

// DCC item
code BYTE sDCCNormal[]  = "DCC Normal";
//------------------------------------------------------------------------------

// ICM
code BYTE sRed[]     = "Red";
code BYTE sGreen[]   = "Green";
code BYTE sYellow[]  = "Yellow";
code BYTE sCyan[]    = "Cyan";
code BYTE sMagenta[] = "Magenta";
//------------------------------------------------------------------------------

// color
code BYTE sPeaking[] = "Peaking";

#endif

//------------------------------------------------------------------------------
#else

extern BYTE code tUserMenuOsdMap[];
extern BYTE code tMsgOsdMap[];
extern BYTE code tOSD_MAIN_WINDOW_STYLE[];
extern BYTE code tOSD_MINI_WINDOW_STYLE[];
extern BYTE code tOSD_LINE_WINDOW_STYLE[];
extern BYTE code tOSD_SELECT_MAIN_WINDOW_STYLE[];
extern BYTE code tOSD_SELECT_SUB_WINDOW_STYLE[];
extern BYTE code tPALETTE_0[];

extern code BYTE *sBright[];
extern code BYTE *sContrast[];
#if(_COLOR_TEMP)
extern code BYTE *sColorTemp[];
extern code BYTE sColorTemp9300[];
extern code BYTE sColorTemp6500[];
extern code BYTE sColorTemp5800[];
extern code BYTE sColorTempSRGB[];
extern code BYTE *sColorTempUser[];
#endif
#if(_VGA_SUPPORT)
extern code BYTE *sPhase[];
extern code BYTE *sClock[];
extern code BYTE *sHPos[];
extern code BYTE *sVPos[];
#endif
extern code BYTE *sLanguage[];
extern code BYTE *sLangName[];
#if(_OSD_POSITION_ADJ_CTRL)
extern code BYTE *sOSDHPosition[];
extern code BYTE *sOSDVPosition[];
#endif
#if(_OSD_TIMEOUT_ADJ_CTRL)
extern code BYTE *sOSDTimeOut[];
#endif
#if(_ALPHA_BLENDING_ADJ == _ON)
extern code BYTE *sOSDTranslucent[];
#endif
#if(_OSD_DISPLAY_SIZE_ADJ == _ON)
extern code BYTE *sOSDSize[];
#endif

extern code BYTE *sAuto[];
extern code BYTE *sAutoColor[];
#if(_SOUND_PROCESSOR == _ENABLE)
extern code BYTE *sBalance[];
extern code BYTE *sBass[];
extern code BYTE *sTreble[];
extern code BYTE *sSRS[];
extern code BYTE *sBBE[];
#endif

extern code BYTE *sReset[];
extern code BYTE *sExit[];
extern code BYTE *sNoSignal[];
extern code BYTE *sNoCable[];
extern code BYTE *sNotSupport[];
//extern code BYTE *sAVBright[];		//V309
//extern code BYTE *sAVContrast[];	//V309
extern code BYTE *sHue[];
extern code BYTE *sSaturation[];

extern code BYTE *sTVSystem[];
extern code BYTE *sSoundSystem[];
extern code BYTE *sAutoSearch[];
extern code BYTE *sManualSearch[];
extern code BYTE *sTuning[];
extern code BYTE *sTuningState[];

extern code BYTE *sChannel[];
extern code BYTE *sSwap[];
extern code BYTE *sSkip[];
extern code BYTE *sBlue[];
extern code BYTE *sAutoPowerDown[];
#if(_IMAGE_COLOR_MODE)
extern code BYTE *sColorMode[];
extern code BYTE *sColorMode0[];
extern code BYTE *sColorMode1[];
extern code BYTE *sColorMode2[];
extern code BYTE *sColorMode3[];
extern code BYTE *sColorMode4[];
extern code BYTE *sColorMode5[];
#endif
extern code BYTE *sVolume[];
extern code BYTE *sMute[];
#if(_SHARPNESS_ADJ)
extern code BYTE *sSharp[];
#endif

extern code BYTE sVGA[];
extern code BYTE sDVI[];
extern code BYTE sVIDEO[];
extern code BYTE sSVIDEO[];
extern code BYTE sTV[];
extern code BYTE sYUV[];
extern code BYTE sNTSC[];
extern code BYTE sSCART[];  
extern code BYTE sPAL[];
extern code BYTE sYPBPR[];
extern code BYTE sDVB[];
extern code BYTE sHDMI[];
extern code BYTE *sTVType[14];
extern code BYTE *sTVSoundType[4];
//extern code BYTE *sSkipFunc[2][7];
extern code BYTE *sOn_Off[2][7];
extern code BYTE *sYPbPrMode[];

#if(_VGA_COLOR_SUPPORT == _ON)
extern code BYTE sText[];
extern code BYTE sMovie[];
extern code BYTE sGraphic[];
extern code BYTE sGame[];
extern code BYTE sNormal[];
extern code BYTE sUser[];
// User item
extern code BYTE sVividColor[];
extern code BYTE sDCC[];
extern code BYTE sICM[];
extern code BYTE sColor[];
// DCC item
extern code BYTE sDCCNormal[];
// ICM
extern code BYTE sRed[];
extern code BYTE sGreen[];
extern code BYTE sBlue_ENG[];
extern code BYTE sYellow[];
extern code BYTE sCyan[];
extern code BYTE sMagenta[];
extern code BYTE sICM[];
// color
extern code BYTE sPeaking[];
extern code BYTE sExit_ENG[];

#endif  // end #if(_VGA_COLOR_SUPPORT == _ON)

#endif  // end #ifdef __OSD007_LCD_OSD__


#endif  //#if(OSD_TYPE == OSD007)

