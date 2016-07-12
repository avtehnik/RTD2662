#define _IR_C


#include "Core\Header\include.h"


BYTE ucIrQueue[8];
BYTE keystate = 0;
BYTE ucPrevKey = _NONE_KEY_MESSAGE;
BYTE idata ucRepKeyCount = 0;
static UINT8 idata ucIrdaStatus;
static void CIrdaReadData(void);

//--------------------------------------------------
// Description  : Get IR key status
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE CIRKeyScan(void)
{
	BYTE temp; 
    BYTE keystate = _NONE_KEY_MESSAGE;
    BYTE ucCount;
	
	ucIrdaStatus = MCU_IR_STATUS_FF89;
	if (ucIrdaStatus&(_BIT4|_BIT3))
    {
		CIrdaReadData();			
		if(((UINT16 *)ucIrQueue)[0]==CUSTOM_CODE) 
        {
			if(!(ucIrdaStatus&_BIT2))
            {
				if(ucIrQueue[2]==(~ucIrQueue[3])) 
                {
					temp = ucIrQueue[2];

                    // Search key message
                    for(ucCount = 0; ucCount < ((sizeof(IRKeyMsg))/2); ucCount++)
                    {
                       if (temp == IRKeyMsg[ucCount][0])
                       {
                           keystate = IRKeyMsg[ucCount][1];
                           break;
                       }
                    }

                    ucRepKeyCount = 0;
	            }
	        }   // if(!(ucIrdaStatus&_BIT2))
            else if (ucIrdaStatus&_BIT2)  
            {   //Repeat command
                ucRepKeyCount++;
                if (ucRepKeyCount > 2)
                {
                    if (ucRepKeyCount > 250)
                        ucRepKeyCount = 3;

                    if (GET_KEYREPEATENABLE())
                        keystate = ucPrevKey;
                }
    		}
        }  // if(((UINT16 *)ucIrQueue)[0]==CUSTOM_CODE)
    }      // if (ucIrdaStatus&(_BIT4|_BIT3))
	
	return keystate;
}

UINT8 code tIrdaInitial[12] =
{

//24.3Mhz/512
	0x60,//			IR_CTRL1_FF80	
	0x03,//0a,//03//		IR_DEBOUNCE_FF81
	0x65,//			IR_BURST_LENGTH_FF82
	0x32,//			IR_SILENCE_LENGTH_FF83
	0x19,//			IR_REPEAT_LENGTH_FF84
	0x19,//			IR_MOD_LENGTH_FF85
	0x19,//			IR_DATA0_LENGTH_FF86
	0x4d,//			IR_DATA1_LENGTH_FF87
	
	0x9F,//			IR_CTRL2_FF88
	
	0xa2,//0xa0,//0X97,//			IR_ONE_CMD_TIME_FF90
	0xb8,//0xb4,//0xaf,//0Xa5,//			IR_IDLE_TIME_FF91
	0x00,//			IR_CTRL3_FF92

};

void CIrdaInitial(void)
{
	MCU_IR_CTRL1_FF80			=	tIrdaInitial[0];		
	MCU_IR_DEBOUNCE_FF81		=	tIrdaInitial[1];		
	MCU_IR_BURST_LENGTH_FF82	=	tIrdaInitial[2];			
	MCU_IR_SILENCE_LENGTH_FF83  =	tIrdaInitial[3];				
	MCU_IR_REPEAT_LENGTH_FF84   =	tIrdaInitial[4];				
	MCU_IR_MOD_LENGTH_FF85	    =	tIrdaInitial[5];			
	MCU_IR_DATA0_LENGTH_FF86	=	tIrdaInitial[6];		
	MCU_IR_DATA1_LENGTH_FF87	=	tIrdaInitial[7];
	
	MCU_IR_CTRL2_FF88			=	tIrdaInitial[8];	  	

	MCU_IR_ONE_CMD_TIME_FF90	=	tIrdaInitial[9];						
   	MCU_IR_IDLE_TIME_FF91		=	tIrdaInitial[10];						
 	MCU_IR_CTRL3_FF92			=	tIrdaInitial[11];				

	MCU_IR_INTRQ_FF93			=	0x00;//0x00;		
	MCU_IR_STATUS_FF89		   |=   _BIT0;//|_BIT1;//enable IR
}

static void CIrdaReadData(void)
{	
	ucIrQueue[0] =	MCU_IR_DATA2_FF8C;
	ucIrQueue[1] =	MCU_IR_DATA3_FF8D;
	ucIrQueue[2] =	MCU_IR_DATA4_FF8E;
	ucIrQueue[3] =	MCU_IR_DATA5_FF8F;
}



