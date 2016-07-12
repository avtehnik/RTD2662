//----------------------------------------------------------------------------------------------------
// ID Code      : Mcu.c No.0002
// Update Note  :
//
//----------------------------------------------------------------------------------------------------

#define __MCU__

#include  "Core\Header\Include.h"

#if(_MCU_TYPE == _REALTEK_RTD3580D_EMCU)
/**
* CMcuInitial
* Initialize the MCU _REALTEK_RTD3580D_EMCU
* @param <none>
* @return {none}
*
*/
void CMcuInitial(void)
{
    IE      = 0x00;                         // Disable all interrupts
    TMOD    = 0x11;                         // Program Timer0 & Timer1 to Mode#1
    TR0     = 0;                            // Stop Timer0
    TF0     = 0;                            // Clear Timer0 Overflow Bit
    TL0     = _TIMER0_COUNT_LBYTE;          // Load Timer0 low-byte   (for 1ms)
    TH0     = _TIMER0_COUNT_HBYTE;          // Load Timer0 high-byte  (for 1ms)
    TR1     = 0;                            // Stop Timer1
    TF1     = 0;                            // Clear Timer1 Overflow Bit
    IE      = 0x8a;                         // Enable interrupts of Timer0

	MCU_WATCHDOG_TIMER_FFEA		= 0x00; 	//dis wdt, wdt default enable
    MCU_WATCHDOG_TIMER_FFEA		|= 0x40;	//clr wdt.//eric 20070627
    MCU_CTRL_FFED				= 0x80; 		//FlashDIV=1
    MCU_HDMI_DDC_ENA_FF2C		= 0x00;  		//disable HDMI DDC channel

    MCU_COMMON_INST_EN_FF60		= 0x68;              
    MCU_COMMON_OP_CODE_FF61		= 0x01;             // wrsr
    MCU_FLASH_PROG_ISP0_FF64	= 0x0c;            // state reg
    MCU_COMMON_INST_EN_FF60		= 0x68 | 0x01;    

//Gary for Interior HDMI  DDC 	20070711
// HDMI DDC connected to DDC2
#if ( (_HDMI_EDID==_ON) && (_HDMI_DDC_CHANNEL_SELECT==_DDC2) )
	          
    MCU_DVI_DDC_ENA_FF1E  	= 0x02;
	MCU_HDMI_DDC_ENA_FF2C 	= 0x00;  //disable HDMI DDC channel
    MCU_DDCRAM_PART_FF21  	= 0x2b;  //addcram_st=2(0xfd00),dddcram_st=20(0xfd80),hddcram_st=3 
    
// HDMI DDC connected to DDC3
#elif( (_HDMI_EDID==_ON) && (_HDMI_DDC_CHANNEL_SELECT==_DDC3) )

	MCU_DVI_DDC_ENA_FF1E  	= 0x00;  //disable DVI DDC channel
	MCU_HDMI_DDC_ENA_FF2C 	= 0x02;  
	MCU_DDCRAM_PART_FF21  	= 0x3a;  //addcram_st=3(0xFd80),dddcram_st=2(0xfd80),hddcram_st=2(0xfe00) 	

#else
	
	MCU_DVI_DDC_ENA_FF1E  	= 0x00;  //Disable DVI DDC channel
	MCU_HDMI_DDC_ENA_FF2C 	= 0x00;  //disable HDMI DDC channel
    MCU_DDCRAM_PART_FF21  	= 0x3f;  //addcram_st=3,dddcram_st=3,hddcram_st=3 (Xram=640 Byte) 

#endif	

#if (_VGA_EDID == _ON)
	MCU_VGA_DDC_ENA_FF1B 	= 0x02;  
#else
	MCU_VGA_DDC_ENA_FF1B 	= 0x00;   //Disable ADC DDC channel
#endif

    MCU_PIN_SHARE_CTRL04_FF9A |= 0x05; 		//P6.6/P6.7 opendrain output for I2C master 
	MCU_PORT_READ_CTRL_FFC0 = 0xfd; 		//read All GPIO value from bus,except p3 
	
	MCU_BANK_SWITCH_CTRL_FFFC = 0x0B; 		// enable global XFR & enable bank switching func(Pbank)
	MCU_BANK_START_FFFD       = 0x01;
	MCU_BANK_SEL_FFFE         = 0x00;

	MCU_CLOCK_CTRL_FFEE 		|= 0x40;		    //keep mcu peripheral running while mcu stopped by spi flash access
	
    #if (_MCU_PWM_SUPPORT)
    {
    	MCU_PWML_FF46   |= 0x80;				// PWM_W_DB_EN	
    	MCU_PWM_EN_FF48 = _MCU_PWM_SUPPORT;	    // PWM output enable
		MCU_PWM_CK_FF49 = _BIT0;				// second stage output

		if (_MCU_PWM0_SUPPORT == _ON)
		{
			MCU_PWM03_M_FF3B 		= 0;	//_MCU_PWM0_FIRST_STAGE_DIV;
			MCU_PWM01_N_MSB_FF3D 	= 0;	//(_MCU_PWM0_SECOND_STAGE_DIV >> 4) & 0x0f;
			MCU_PWM0_N_LSB_FF3E		= 66;	//(_MCU_PWM0_SECOND_STAGE_DIV >> 0) & 0xff;
		}
    }
    #endif

#if(_FAST_READ == _ON)
	CMCUSetFlashClk();
#endif // End of #if(_FAST_READ == _ON)

	MCU_COMMON_INST_EN_FF60 = 0x68;		//Write after WREN & Write_No=1
	MCU_COMMON_OP_CODE_FF61 = 0x01;		//Instruction Code(WRSR:0x01)
	MCU_FLASH_PROG_ISP0_FF64 = 0x80;	//write byte(SRWD=1) 
	MCU_COMMON_INST_EN_FF60 |= 0x01;	//com_inst_en
}

#if(_FAST_READ == _ON)
void CMCUSetFlashClk(void)
{
   //   M2PLL Enable
    MCU_SCA_INF_CTRL_FFF3 = 0x20; //BWR data enable, Non_INC
    MCU_SCA_INF_ADDR_FFF4 = 0x9f; //DDC_addr
    MCU_SCA_INF_DATA_FFF5 = 0x01; //DDC_data, page-1
    MCU_SCA_INF_ADDR_FFF4 = 0xE4; //M2-PLL Reg Ctrl Address
    MCU_SCA_INF_DATA_FFF5 = 0x00; //Enable M2PLL

    //  Power-saving mode Enable
    MCU_SCA_INF_ADDR_FFF4 = 0x01; //DDC_addr- Host Ctrl
    MCU_SCA_INF_DATA_FFF5 = 0x00; //DDC_data - Disable power-saving mode

    //  M2PLL output enable
    MCU_SCA_INF_ADDR_FFF4 = 0xE0; //M2-PLL-CTRL0
    MCU_SCA_INF_DATA_FFF5 = 0x82; //M2PLL output enable
    
    //  Enable FastRead mode
    MCU_CEN_CTRL_FF76 = ( ((0x3)<<4) | ((0x1)<<2) | ((0x1)<<0) );  //ChipEnable Timing Setup

#if (_TURBO_MODE==_ON)
    MCU_FAST_READ_OP_CODE_FF6B = 0x3B;  //Fast Dual data read for winbond flash only
    MCU_READ_INSTRUCTION_FF6C |= ( ((0x2)<<6) | ((0x1)<<5) | ((0x0)<<4) | ((0x0)<<2) | ((0x0)<<0) ); //Fast Read mode, DI@half cycle, Dout@one cycle
#else
    MCU_FAST_READ_OP_CODE_FF6B = 0x0B;  //Fast Read for all kind of flash
    MCU_READ_INSTRUCTION_FF6C |= ( ((0x1)<<6) | ((0x1)<<5) | ((0x0)<<4) | ((0x0)<<2) | ((0x0)<<0) ); //Fast Read mode, DI@half cycle, Dout@one cycle
#endif   
 
    CMCUFlashClkDiv(_FLASH_CLK_DIV);    //Flash CLK
    CMCUClkDiv(_MCU_CLK_DIV);      //MCU=FlashClk/2
    MCU_CTRL_FFED |= 0x02; //Switch to PLL
}


void CMCUFlashClkDiv(BYTE clkdiv) // _FlashClkDiv(x=0-15): SPI Flash Clock Generator (OSC/PLL°£¥HDIV:from 0~15) 
{ 
    clkdiv &= 0x0F;
    clkdiv = (clkdiv << 2);
    clkdiv |= (MCU_CTRL_FFED & 0xC3);
    MCU_CTRL_FFED = clkdiv;     
}

void CMCUClkDiv(BYTE clkdiv)  // _MCUClkDiv(x=0-15): 8051 Clock Generator (Flash_Clk/DIV:from 0~15)
{ 
    clkdiv &= 0x0F;
    clkdiv = (clkdiv << 2);
    clkdiv |= (MCU_CLOCK_CTRL_FFEE & 0xC3);
    MCU_CLOCK_CTRL_FFEE = clkdiv;     
}
#endif //End of #if(_FAST_READ == _ON)

#endif


