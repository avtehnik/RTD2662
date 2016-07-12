//----------------------------------------------------------------------------------------------------
// ID Code      : Misc.h No.0001
// Update Note  :
//
//----------------------------------------------------------------------------------------------------

//--------------------------------------------------
// Definitions of
//--------------------------------------------------


//----------------------------------------------------------------------------------------------------

#ifdef __MISC__

//--------------------------------------------------
// Global Variables
//--------------------------------------------------

BYTE ucVirtualKey = 0;
BYTE ucDdcciCommandNumber = 0;
BYTE TxBUF=0;
bit bRunCommand=0;
BYTE idata ucDdcciData[4];

//--------------------------------------------------
// Function Prototypes
//--------------------------------------------------
bit CMiscScalerResetEvent(void);
//bit CMiscStableFlagPollingEvent(void);
bit CMiscHsyncTypeAutoRunFlagPollingEvent(void);
bit CMiscModeMeasurePollingEvent(void);
bit CMiscAutoMeasurePollingEvent(void);
bit CMiscApplyDoubleBufferPollingEvent(void);
bit CMiscMeasureResultPOPPollingEvent(void);
bit CMiscTMDSMeasureEvent(void);
void CMiscEnableDoubleBuffer(void);
void CMiscDisableDoubleBuffer(void);
void CMiscApplyDoubleBuffer(void);
void CMiscClearStatusRegister(void);
void CMiscSetPinShare(void);
void CMiscKingmice(void);
void CMiscIspack(void);
void CMiscIspDebugProc(void);

void CDdcciInitial(void);

#else

//--------------------------------------------------
// Extern Global Variables
//--------------------------------------------------
extern BYTE ucVirtualKey;
extern BYTE ucDdcciCommandNumber;
extern bit bRunCommand;
extern idata BYTE ucDdcciData[4];
extern BYTE TxBUF;

//--------------------------------------------------
// Extern Function Prototypes
//--------------------------------------------------
extern bit CMiscScalerResetEvent(void);
//extern bit CMiscStableFlagPollingEvent(void);
extern bit CMiscHsyncTypeAutoRunFlagPollingEvent(void);
extern bit CMiscMeasureResultPOPPollingEvent(void);
extern bit CMiscModeMeasurePollingEvent(void);
extern bit CMiscAutoMeasurePollingEvent(void);
extern bit CMiscTMDSMeasureEvent(void);
extern void CMiscEnableDoubleBuffer(void);
extern void CMiscDisableDoubleBuffer(void);
extern void CMiscApplyDoubleBuffer(void);
extern void CMiscClearStatusRegister(void);
extern void CMiscSetPinShare(void);
extern void CMiscIspDebugProc(void);

extern void CDdcciInitial(void);

#endif

void GetVirtualKey(void);

//----------------------------------------------------------------------------------------------------

