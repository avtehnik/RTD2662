//----------------------------------------------------------------------------------------------------
// ID Code      : Int.c No.0002
// Update Note  :
//
//----------------------------------------------------------------------------------------------------

#include "Core\Header\Include.h"

#if defined(CONFIG_VBI_ENABLE)
void VBI_GetData();
#else
#define	VBI_GetData();
#endif

BYTE idata ucKeyADValue;

//--------------------------------------------------
// Timer0 Interrupt (375 us)
//--------------------------------------------------
void IntProcTimer0(void) interrupt 1
{
#if(0)
	static BYTE data ucTimer0Cnt = 0x00;

    TR0 = _ON;
    TL0 = _TIMER0_COUNT_LBYTE;
    TH0 = _TIMER0_COUNT_HBYTE;

    bNotifyTimer0Int = _TRUE;

    if(--ucTimer0Cnt)
    {

    }
    else
    {
        if(bTimer0Ctrl == _FALSE)
        {
            CTimerDecreaseTimerCnt();
        }
        ucTimer0Cnt = 10;
    }

#else
	static BYTE data ucTimer0Cnt = 0x00;
	static BYTE data ucTimerCnt = 10;

	
	EA = 0;
	TR0 = _ON;

	TL0 = _TIMER0_COUNT_LBYTE;	
	TH0 = _TIMER0_COUNT_HBYTE;
	
	
	if((++ucTimer0Cnt) >= _EVENT_PERIOD) 
	{
		ucTimer0Cnt = 0;
		bNotifyTimer0Int = _TRUE;
		if(ucTimerCnt)
			ucTimerCnt--;
			
		else if(bTimer0Ctrl == _FALSE) 
		{

			CTimerDecreaseTimerCnt();
			ucTimerCnt = 0x0a; 	//including the above 1.125ms, this will
								//give about 5 sec delay before OSD
								//menu/channel# got turn off
		}

#if(_VIDEO_TV_SUPPORT)
#if(_SLEEP_FUNC)
	    if (0xff != ucAutoPowerDownTime && 0x00 != ucAutoPowerDownTime)
	    {
	        ucMinuteCount++;
           if(ucMinuteCount == 1000)
               ucAutoPowerDownTime--;
           if (ucMinuteCount == _ONE_MINUTE_COUNT)  // 1 minute
               ucMinuteCount = 0;
       }
#endif
#endif
		}
		EA = 1;
#endif	
}

//--------------------------------------------------
#if(_RS232_EN)

//--------------------------------------------------
void UartRxData(void)
{
	if (fUartStart == 0) 
	{
		pUartData[0] = SBUF;
		fUartStart = 1;
		switch(pUartData[0])
		{
			case UartCMD_DebugModeEnter:  		// Enter debug mode
			case UartCMD_DebugModeExit:  		// Exit debug mode
				ucUartRxCount = 4;
				break;
			case UartCMD_CScalerRead:  			// Read RTD2553V
			case UartCMD_I2CRead:  				// Read I2C
			case UartCMD_I2CWrite:  			// Write I2C
				ucUartRxCount = 3;
				break;
			case UartCMD_CScalerWrite:  		// Write RTD2553V
				ucUartRxCount = 2;
				break;
			default:
				fUartStart = 0;
				break;
		}

		ucUartRxIndex = 1;
	}
	else 
	{
		pUartData[ucUartRxIndex] = SBUF;
		ucUartRxIndex++;
		if (ucUartRxIndex > ucUartRxCount)
		{
			fUartRxCmdSuccess = 1;
			fUartStart = 0;
		}
	}
}

//--------------------------------------------------
void IntProcUart(void) interrupt 4
{
	ES = 0; // disable uart interrupt.
	if (TI) 
	{
		TI = 0;
	}
	else if (RI) 
	{
		UartRxData();
		RI = 0;
	}
	ES = 1;
}


#endif
//--------------------------------------------------

void IntProcDdcc0(void)  interrupt 0
{
    BYTE tempbuf;

	EA=0;

	IE0 = 0;

    //bLED1 ^= 1;
	//bLED2 ^= bLED1;

	/*MCU_I2C_IRQ_CTRL2_FF2A  &= 0xDF; //host write/read enable
    if(!bRunCommand)
    {
        tempbuf = MCU_I2C_STATUS_FF27;   

        if(tempbuf & 0x08)
            MCU_I2C_DATA_OUT_FF26 = TxBUF;       

        if(tempbuf & 0x01) 
            ucDdcciCommandNumber = 0;

        if(tempbuf & 0x02) 
            ucDdcciCommandNumber=0;
        		
        if(tempbuf & 0x04)
        {
            if(ucDdcciCommandNumber==0)
                ucDdcciData[ucDdcciCommandNumber] = MCU_I2C_SUB_IN_FF24;

            ucDdcciCommandNumber++;
            ucDdcciData[ucDdcciCommandNumber] = MCU_I2C_DATA_IN_FF25;
            bRunCommand=_TRUE; 
        }

        MCU_I2C_STATUS_FF27 = tempbuf & 0xc0;
    }*/

    EA=1;
}

void IntProcDdcci(void)  interrupt 2
{
    BYTE tempbuf;

	EA=0;

	tempbuf = MCU_IRQ_STATUS_FF00;

	if (tempbuf & 0x01)					// DDC_IRQ_EVENT
	{	
	    MCU_IRQ_STATUS_FF00 &= ~0x01;

		MCU_I2C_IRQ_CTRL2_FF2A  |= 0x20;
	
		tempbuf = MCU_I2C_STATUS_FF27;
	
		if(tempbuf & 0x80)							// A_WR_I
			MCU_I2C_STATUS_FF27 &= ~0x80;
		if(tempbuf & 0x40)							// D_WR_I
			MCU_I2C_STATUS_FF27 &= ~0x40;
		if(tempbuf & 0x20)							// DDC_128VS1_I
			MCU_I2C_STATUS_FF27 &= ~0x20;
		if(tempbuf & 0x10)							// STOP_I
			MCU_I2C_STATUS_FF27 &= ~0x10;
	
		if(tempbuf & 0x08)							// D_OUT_I
		{
			MCU_I2C_DATA_OUT_FF26 = ucKeyADValue;
			//bLED2 ^= 1;
		}

		if(tempbuf & 0x04)							// D_IN_I
		{
			tempbuf = MCU_I2C_SUB_IN_FF24;
			tempbuf = MCU_I2C_DATA_IN_FF25;
			//bLED1 ^= 1;
		}
	
		if(tempbuf & 0x02)							// SUB_I
		{
			MCU_I2C_STATUS_FF27 &= ~0x02;

			//bLED1 ^= 1;
			//bLED2 = 0;
		}

		if(tempbuf & 0x01)							// SLV_I
		{
	    	MCU_I2C_STATUS_FF27 &= ~0x01;

			//bLED1 ^= 1;
			//bLED2 = 0;
		}

		MCU_I2C_IRQ_CTRL2_FF2A  &= ~0x20;
	}

    IE1 = 0;

	EA=1;
}

#if defined(CONFIG_VBI_ENABLE)

void IntProc_Timer1(void) interrupt 3
{
	ET1 = 0;  	// Disable Timer 1 interrupt
	VBI_GetData();
	TL1 = _TIMER1_COUNT_LBYTE;  // (for 1ms)
	TH1 = _TIMER1_COUNT_HBYTE;  // Load Timer1 hifh-byte  (for 1ms)
	TR1 = 1;    // Start Timer1
	ET1 = 1;	// Enable Timer 1 interrupt
}

/**
 * The VBI interrupt service routine.
 */
void VBI_GetData(void) //VBI INTERRUPT handler
{
	ClearVerLineCompSts();
}

#endif

