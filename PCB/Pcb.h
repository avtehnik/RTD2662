//----------------------------------------------------------------------------------------------------
// ID Code      : Pcb.h No.0001
// Update Note  :
//
//----------------------------------------------------------------------------------------------------

//--------------------------------------------------
// PCB Type
//--------------------------------------------------
#define _PCB_GMI2660_DEMO1         				0		// for 3580D single chip platform
#define _PCB_RTD2660_DEMO2                      1
#define _PCB_RTD2660_DEMO3                      2       // TB1338
#define _PCB_RTD2660_DEMO4                      3       // PCB800168?

#define _PCB_TYPE								_PCB_RTD2660_DEMO2
                                  
//--------------------------------------------------

#if(_PCB_TYPE == _PCB_GMI2660_DEMO1)
#include "pcb\Pcb_RTD3580D_LCDTV_DEMO_PCB1.h"
#endif

#if(_PCB_TYPE == _PCB_RTD2660_DEMO2)
#include "pcb\Pcb_RTD3580D_LCDTV_DEMO_PCB2.h"
#endif

#if(_PCB_TYPE == _PCB_RTD2660_DEMO3)
#include "pcb\Pcb_RTD3580D_LCDTV_DEMO_PCB3.h"
#endif

#if(_PCB_TYPE == _PCB_RTD2660_DEMO4)
#include "pcb\Pcb_RTD3580D_LCDTV_DEMO_PCB4.h"
#endif

 
