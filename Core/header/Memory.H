//----------------------------------------------------------------------------------------------------
// ID Code      : RTD2528R_Memory.h No.0000
// Update Note  : 
//
//----------------------------------------------------------------------------------------------------

//--------------------------------------------------
// Definitions of Compress Group Number
//--------------------------------------------------
#define _COMPRESS_GROUP_NUMBER          0x320   //800 pixel

//--------------------------------------------------
// Definitions of OD start address 
//--------------------------------------------------
#define _OD_START_ADDRESS               0x000000

//--------------------------------------------------
// Definitions of Low Bit Noise Reduction Threshold 
//--------------------------------------------------
#define _OD_LBNRT_ENABLE                _ON
#define _OD_LBNRT_MODE                  _NEWMODE
#define _OD_LBNRT_LEVEL                 8

//--------------------------------------------------
// Definitions of OD Channel
//--------------------------------------------------
#define _OD_TABLE_SINGLY        0
#define _OD_TABLE_COMMON        3

//----------------------------------------------------------------------------------------------------

#ifdef __RTD2528R_MEMORY__

//--------------------------------------------------
// Global Variables
//--------------------------------------------------

//--------------------------------------------------
// Function Prototypes
//--------------------------------------------------
void CMemorySDRAMReset(void);
void CMemoryLoadODLUT(BYTE ucColor);
void CMemoryLoadODTable(BYTE *pChannelArray);
void CMemorySetODOnOff(BYTE ucSelect);
void CMemorySetODCompress(void);
void CMemorySetODFIFO(void);

#else

//--------------------------------------------------
// Extern Function Prototypes
//--------------------------------------------------
extern void CMemorySDRAMReset(void);
extern void CMemoryLoadODLUT(BYTE ucColor);
extern void CMemoryLoadODTable(BYTE *pChannelArray);
extern void CMemorySetODOnOff(BYTE ucSelect);
extern void CMemorySetODCompress(void);
extern void CMemorySetODFIFO(void);

#endif
