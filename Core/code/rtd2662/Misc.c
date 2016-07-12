//----------------------------------------------------------------------------------------------------
// ID Code      : Misc.c No.0002
// Update Note  :
//
//----------------------------------------------------------------------------------------------------

#define __MISC__

#include "Core\Header\Include.h"

//----------------------------------------------------------------------------------------------------
// Polling Events
//----------------------------------------------------------------------------------------------------

#if(_HSYNC_TYPE_DETECTION == _AUTO_RUN)
/**
 * CMiscHsyncTypeAutoRunFlagPollingEvent
 * Hsync Type Detection Auto Run flag polling event
 * @param <none>
 * @return {_TRUE if event occurs,_FALSE if not}
 *
*/
//--------------------------------------------------
// Description  : Hsync Type Detection Auto Run flag polling event
// Input Value  : None
// Output Value : Return _TRUE if event occurs
//--------------------------------------------------
bit CMiscHsyncTypeAutoRunFlagPollingEvent(void)
{
    if((bit)CScalerGetBit(_VSYNC_COUNTER_LEVEL_MSB_4C, _BIT7))
        return _TRUE;
    else
        return _FALSE;
}
#endif	// End of #if(_HSYNC_TYPE_DETECTION == _AUTO_RUN)

/**
 * CMiscModeMeasurePollingEvent
 * Measure start/end polling event
 * @param <none>
 * @return {none}
 *
*/
//--------------------------------------------------
// Description  : Measure start/end polling event
// Input Value  : None
// Output Value : Return _TRUE if measure finished
//--------------------------------------------------
bit CMiscModeMeasurePollingEvent(void)
{
    if(!(bit)CScalerGetBit(_MEAS_HS_PERIOD_H_52, _BIT5))
        return _TRUE;
    else
        return _FALSE;
}

bit CMiscMeasureResultPOPPollingEvent(void)
{
    if(!(bit)CScalerGetBit(_MEAS_HS_PERIOD_H_52, _BIT6))
        return _TRUE;
    else
        return _FALSE;
}

#if((_TMDS_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Auto measure start/end polling event
// Input Value  : None
// Output Value : Return _TRUE if auto measure finished
//--------------------------------------------------
bit CMiscAutoMeasurePollingEvent(void)
{
	if(!(bit)CScalerGetBit(_AUTO_ADJ_CTRL1_7D, _BIT0))
       	return _TRUE;
    else
       	return _FALSE;
}
#endif

//--------------------------------------------------
// Description  : Apply double buffer polling event
// Input Value  : None
// Output Value : Return _TRUE if apply double buffer finished
//--------------------------------------------------
bit CMiscApplyDoubleBufferPollingEvent(void)
{
    if(!(bit)CScalerGetBit(_VGIP_CTRL_10, _BIT5))
        return _TRUE;
    else
        return _FALSE;
}

#if(((_TMDS_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON)) && (_DVI_LONG_CABLE_SUPPORT == _ON))
//--------------------------------------------------
// Description  : TMDS transition measure polling event
// Input Value  : None
// Output Value : Return _TRUE if measure finished
//--------------------------------------------------
bit CMiscTMDSMeasureEvent(void)
{
	CScalerPageSelect(_PAGE2);
 	if(!(bit)CScalerGetBit(_P2_TMDS_MEAS_RESULT0_A2, _BIT7))
       	return _TRUE;
    else
       	return _FALSE;
}
#endif  // End of #if(((_TMDS_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON)) && (_DVI_LONG_CABLE_SUPPORT == _ON))


//----------------------------------------------------------------------------------------------------
// Misc Functions
//----------------------------------------------------------------------------------------------------

//--------------------------------------------------
// Description  : Enable double buffer
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CMiscEnableDoubleBuffer(void)
{
    CScalerSetBit(_VGIP_CTRL_10, ~(_BIT4), _BIT4);
}

//--------------------------------------------------
// Description  : Disable double buffer
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CMiscDisableDoubleBuffer(void)
{
    CScalerSetBit(_VGIP_CTRL_10, ~(_BIT4), 0x00);
}

//--------------------------------------------------
// Description  : Apply double buffer
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CMiscApplyDoubleBuffer(void)
{
	BYTE ucTimeout=12;
 	if((bit)CScalerGetBit(_VGIP_CTRL_10, _BIT4))
    {
      	CScalerSetBit(_VGIP_CTRL_10, ~(_BIT5), _BIT5);
		do
    		{
        		CTimerDelayXms(5);
        		if(CMiscApplyDoubleBufferPollingEvent())
        		{
            		break;
        		}
    		}
    		while(--ucTimeout);	
    }
}

//--------------------------------------------------
// Description  : Clear status Reg[02] and Reg[03]
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CMiscClearStatusRegister(void)
{
    CScalerSetByte(_STATUS0_02, 0x00);
    CScalerSetByte(_STATUS1_03, 0x00);
}

//--------------------------------------------------
// Description  : Set pin share
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CMiscSetPinShare(void)
{
		
	MCU_PIN_SHARE_CTRL00_FF96 = (((BYTE)_PIN_58_59_DDC1_ENABLE<<7) | (_PIN_58<<5) | (_PIN_59<<3) | (_PIN_50));
    MCU_PIN_SHARE_CTRL01_FF97 = (((BYTE)_PIN_51<<6) | (_PIN_64<<3) | (_PIN_65));
    MCU_PIN_SHARE_CTRL02_FF98 = (((BYTE)_PIN_52<<6) | (_PIN_66<<3) | (_PIN_67));
    MCU_PIN_SHARE_CTRL03_FF99 = (((BYTE)_PIN_53<<6) | (_PIN_69<<3) | (_PIN_70));
    MCU_PIN_SHARE_CTRL04_FF9A = (((BYTE)_PIN_55<<5) | (_PIN_56_57_IIC_ENABLE<<4) | (_PIN_56<<2) | (_PIN_57));
    MCU_PIN_SHARE_CTRL05_FF9B = (((BYTE)_PIN_68<<4) | (_PIN_71));
    MCU_PIN_SHARE_CTRL06_FF9C = (((BYTE)_PIN_54<<6) | (_PIN_96<<3) | (_PIN_97));
    MCU_PIN_SHARE_CTRL07_FF9D = (((BYTE)_PIN_74to83<<6) | (_PIN_99<<3) | (_PIN_100));
    MCU_PIN_SHARE_CTRL08_FF9E = (((BYTE)_PIN_102<<3) | (_PIN_105));
    MCU_PIN_SHARE_CTRL09_FF9F = (((BYTE)_PIN_98<<6) | (_PIN_101<<3) | (_PIN_108));
    MCU_PIN_SHARE_CTRL0A_FFA0 = (((BYTE)_PIN_103<<4) | (_PIN_104<<1));
    MCU_PIN_SHARE_CTRL0B_FFA1 = (((BYTE)_PIN_109<<4) | (_PIN_110));
    MCU_PIN_SHARE_CTRL0C_FFA2 = (((BYTE)_PIN_111<<4) | (_PIN_112));
    MCU_PIN_SHARE_CTRL0D_FFA3 = (((BYTE)_PIN_113<<4) | (_PIN_114));
    MCU_PIN_SHARE_CTRL0E_FFA4 = (((BYTE)_PIN_124<<6) | (_PIN_123<<4) | (_PIN_122<<2) | (_PIN_121));
	MCU_FFA6 = 0xFF;

}


//----------------------------------------------------------------------------------------------------
// Debug Functions
//----------------------------------------------------------------------------------------------------

#if(_DEBUG_EN)
//--------------------------------------------------
// Description  : ISP process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CMiscIspack(void)
{
    BYTE halt = 0;

    do
    {
        if(bRunCommand)
        {
            switch(ucDdcciData[0])
            {

                case 0x80:
                    halt = ucDdcciData[1];
                    break;

                // andy extand 
                case 0x10:
                     ucVirtualKey = ucDdcciData[1];
                     break;                    

                case 0x41:
                    MCU_I2C_IRQ_CTRL2_FF2A  |= 0x20;
                    CScalerRead(ucDdcciData[1], 1, pData, _NON_AUTOINC);
                    TxBUF= pData[0];
                    MCU_I2C_DATA_OUT_FF26 = pData[0];
                    break;

                case 0x44:
                    MCU_I2C_IRQ_CTRL2_FF2A  |= 0x20;
                    CI2cRead(ucDdcciData[2], ucDdcciData[1], 1, pData);
                    TxBUF = pData[0];
                    MCU_I2C_DATA_OUT_FF26 = TxBUF;
                    //CUartPrintf("I2C Addr:", ucDdcciData[2]);
                    //CUartPrintf("Sub Addr:", ucDdcciData[1]);
                    //CUartPrintf("Read Data:", pData[0]);
                    
                    break;

                // for RTD & I2c Device
                case 0x22:
                	ucDdcciData[2] = ucDdcciData[1];
                	break;

                case 0x28:
                    ucDdcciData[3] = ucDdcciData[1];
                    break;

                case 0x24:
                    CI2cWrite(ucDdcciData[2], ucDdcciData[1], 1, &ucDdcciData[3]);
                    //CUartPrintf("I2C Addr:", ucDdcciData[2]);
                    //CUartPrintf("Sub Addr:", ucDdcciData[1]);
                    //CUartPrintf("Write Data:", ucDdcciData[3]);
                    
                    break;
                    
                case 0x20:
					CScalerSetByte(ucDdcciData[2], ucDdcciData[1]);
					break;

                default:

                    break;
			}

            bRunCommand=0;
            ucDdcciCommandNumber = 0;
        }
    }
    while(halt != 0);
}

/**
 * CMiscIspDebugProc
 * Debug tool process
 * @param <none>
 * @return {none}
 *
 */
void CMiscIspDebugProc(void)
{
    CMiscIspack();
}
#endif

//--------------------------------------------------
void GetVirtualKey(void)
{
    if(ucKeyMessage == _NONE_KEY_MESSAGE)
    {
        ucKeyMessage = ucVirtualKey;
    }
    ucVirtualKey = _NONE_KEY_MESSAGE;
}


//--------------------------------------------------

// Description  : ISP for RTD3580D Embeded MCU Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CDdcciInitial(void) 
{     
#if( (_HDMI_EDID == _ON) || _VGA_EDID )
	UINT16 cnt;
#endif

	MCU_VGA_DDC_ENA_FF1B		= 0x00;		// close ddc1  
    MCU_DVI_DDC_ENA_FF1E		= 0x00; 	// close ddc2
    MCU_HDMI_DDC_ENA_FF2C		= 0x00; 	// close ddc3

	MCU_IRQ_PRIORITY_FF01		= 0x01;     // assign int1 (IRQ2)

    MCU_I2C_SET_SLAVE_FF23		= 0x62;
	MCU_I2C_IRQ_CTRL_FF28		= 0x00;

	MCU_I2C_IRQ_CTRL_FF28		|= 0x80;	// MCU_I2C_IRQ_CTRL_AWI_EN	(DCC1?)
    MCU_I2C_IRQ_CTRL_FF28		|= 0x40;	// MCU_I2C_IRQ_CTRL_DWI_EN	(DCC2?)
    MCU_I2C_IRQ_CTRL_FF28		|= 0x20;	// MCU_I2C_IRQ_CTRL_DDC_128VSI1_EN
    MCU_I2C_IRQ_CTRL_FF28		|= 0x10;	// MCU_I2C_IRQ_CTRL_STOP1_EN
    MCU_I2C_IRQ_CTRL_FF28		|= 0x08;	// MCU_I2C_IRQ_CTRL_DOI_EN
    MCU_I2C_IRQ_CTRL_FF28		|= 0x04;	// MCU_I2C_IRQ_CTRL_DII_EN
    MCU_I2C_IRQ_CTRL_FF28		|= 0x02;	// MCU_I2C_IRQ_CTRL_SUBI_EN
    MCU_I2C_IRQ_CTRL_FF28		|= 0x01;	// MCU_I2C_IRQ_CTRL_SLVI_EN
    
	MCU_I2C_IRQ_CTRL2_FF2A  	= 0xC0; 	// Auto_Rst_data,Rst_Data_buf

	MCU_I2C_IRQ_CTRL2_FF2A		|= 0x08;	// MCU_I2C_IRQ_CTRL2_DDC_128VSI2_EN
    MCU_I2C_IRQ_CTRL2_FF2A		|= 0x04;	// MCU_I2C_IRQ_CTRL2_DDC_BUF_FULL_EN
    //MCU_I2C_IRQ_CTRL2_FF2A	|= 0x02;	// MCU_I2C_IRQ_CTRL2_DDC_BUF_EMPTY_EN
    MCU_I2C_IRQ_CTRL2_FF2A		|= 0x01;	// MCU_I2C_IRQ_CTRL2_HWI_EN	(DCC3?)

    MCU_I2C_CHANNEL_CTRL_FF2B	= 0x00; 	// ADC DDC 0-CH_SEL Control
	
//gary for Interior HDMI  DDC 	20070711

#if(_HDMI_EDID == _ON)

	for(cnt=0;cnt<256;cnt++) 
		MCU_DDCRAM_HDMI[cnt] = tHDMI_EDID_DATA[cnt];

#endif

#if(_DVI_EDID == _ON)

	for(cnt=0;cnt<128;cnt++) 
		MCU_DDCRAM_DVI[cnt] = tDVI_EDID_DATA[cnt];

#endif

#if(_VGA_EDID == _ON)

	for(cnt=0;cnt<128;cnt++) 
		MCU_DDCRAM_VGA[cnt] = tVGA_EDID_DATA[cnt];
#endif

#if(_HDMI_EDID==_ON)

	// HDMI connected to DDC2
    #if(_HDMI_DDC_CHANNEL_SELECT == _DDC2)
		MCU_DVI_DDC_ENA_FF1E  = 0x07;  // open ddc2
    #endif

	// HDMI connected to DDC3
    #if(_HDMI_DDC_CHANNEL_SELECT == _DDC3)
    	MCU_HDMI_DDC_ENA_FF2C = 0x07; // open ddc3
    #endif

#endif // #if(_HDMI_EDID==_ON)

#if(_DVI_EDID==_ON)

    // DVI connected to DDC2
    #if(_DVI_DDC_CHANNEL_SELECT == _DDC2)
		MCU_DVI_DDC_ENA_FF1E  = 0x07;  // open ddc2
    #endif

    // DVI connected to DDC3
    #if(_DVI_DDC_CHANNEL_SELECT == _DDC3)
    	MCU_HDMI_DDC_ENA_FF2C = 0x07; // open ddc3
    #endif

#endif // #if(_HDMI_EDID==_ON)
      
#if(_VGA_EDID == _ON)

	// VGA connected to DDC1
    MCU_VGA_DDC_ENA_FF1B = 0x07; // open ddc1       
  
#endif

    //IE |= 0x04;								// Enable INT1 Interrupt source
}


