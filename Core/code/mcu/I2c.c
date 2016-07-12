//----------------------------------------------------------------------------------------------------
// ID Code      : I2c.c No.0000
// Update Note  :
//
//----------------------------------------------------------------------------------------------------

#define __I2C__

#include "Core\Header\Include.h"

//#undef CONFIG_VBI_ENABLE
//----------------------------------------------------------------------------------------------------
// I2C communication basic function
//----------------------------------------------------------------------------------------------------
void Delay5us(void)
{
#if(_MCU_TYPE == _REALTEK_RTD3580D_EMCU)
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
#else
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
#endif		
}

BYTE CI2cStart(BYTE ucDeviceAddr)
{

    SETI2CSCL();
    Delay5us();
    while(!(CHECKI2CSCL()));
    SETI2CSDA();
    CLRI2CSDA();
    Delay5us();
    CLRI2CSCL();

    return CI2cSendByte(ucDeviceAddr);
}

void CI2cStop(void)
{
    CLRI2CSDA();
    SETI2CSCL();
    Delay5us();
    SETI2CSDA();
}

BYTE CI2cGetAck(void)
{
    BYTE ack;

    SETI2CSDA();
    SETI2CSCL();
    Delay5us();
    ack = CHECKI2CSDA();
    CLRI2CSCL();
    SETI2CSDA();

    return ack;
}

void CI2cSendAck(void)
{
    CLRI2CSDA();
    SETI2CSCL();
    Delay5us();
    CLRI2CSCL();
}

void CI2cSendNoAck(void)
{
    SETI2CSDA();
    SETI2CSCL();
    Delay5us();
    CLRI2CSCL();
}


BYTE CI2cSendByte(BYTE ucValue)
{
    BYTE cnt;

    for(cnt=0;cnt<8;cnt++)
    {
        if((bit)(ucValue & 0x80))
            SETI2CSDA();
        else
            CLRI2CSDA();
        SETI2CSCL();
        Delay5us();
        CLRI2CSCL();
        ucValue = ucValue << 1;
    }
    if(CI2cGetAck())
    {
        CI2cStop();
        return _I2C_BUSY;
    }
    else
    {
        return _I2C_OK;
    }
}

BYTE CI2cGetByte(void)
{
    BYTE cnt, value;

    value = 0;
    SETI2CSDA();
    for(cnt=0;cnt<8;cnt++)
    {
        SETI2CSCL();
        Delay5us();
        value = (value << 1) | CHECKI2CSDA();
        CLRI2CSCL();
    }
    return value;
}

bit CI2cWriteStart(BYTE ucDeviceAddr, BYTE ucStartAddr)
{
    BYTE timeoutcnt, control;

    timeoutcnt  = _I2C_TIMEOUT_LIMIT;
    control     = ucDeviceAddr | _I2C_WR;
    while(CI2cStart(control) != _I2C_OK)
    {
		if(timeoutcnt)
        	timeoutcnt--;
        
        if(!timeoutcnt)
            return _FAIL;

    }
    if(CI2cSendByte(ucStartAddr) != _I2C_OK)
        return _FAIL;
    return _SUCCESS;
}


//--------------------------------------------------
// Description  : Read data from the selected device by I2C protocol
// Input Value  : ucDeviceAddr  --> Device address
//                ucStartAddr   --> Start address of selected device
//                usLength      --> Numbers of data we want to read
//                pReadArray    --> Result array
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
bit CI2cRead(BYTE ucDeviceAddr, BYTE ucStartAddr, WORD usLength, BYTE *pReadArray)
{
    BYTE control;

    if(usLength == 0)
        return _FAIL;

    if(CI2cWriteStart(ucDeviceAddr, ucStartAddr) == _FAIL)
        return _FAIL;

    control = ucDeviceAddr | _I2C_RD;

    if(CI2cStart(control) != _I2C_OK)
        return _FAIL;

    while(--usLength)
    {
        *pReadArray++ = CI2cGetByte();
        CI2cSendAck();
    }

    *pReadArray++ = CI2cGetByte();

    CI2cSendNoAck();
    CI2cStop();

    return _SUCCESS;
}

//--------------------------------------------------
// Description  : Write data to the selected device by I2C protocol
// Input Value  : ucDeviceAddr  --> Device address
//                ucStartAddr   --> Start address of selected device
//                usLength      --> Numbers of data we want to write
//                pWriteArray   --> Writing data array
// Output Value : Write result (Fail/Success)
//--------------------------------------------------
bit CI2cWrite(BYTE ucDeviceAddr, BYTE ucStartAddr, WORD usLength, BYTE *pWriteArray)
{
    BYTE control;

    if(usLength == 0)
        return _FAIL;
    while(usLength > 0)
    {
        if(CI2cWriteStart(ucDeviceAddr, ucStartAddr) == _FAIL)
            return _FAIL;

        control = _I2C_WRITE_SIZE - (ucStartAddr & 0x0f);

        if(usLength > control)
        {
            usLength -= control;
            if(ucStartAddr >= 0xf0)
                ucDeviceAddr += 2;
            ucStartAddr += control;
        }
        else
        {
            control = usLength;
            usLength = 0;
        }

        while(control--)
        {
            if(CI2cSendByte(*pWriteArray++) != _I2C_OK)
                return _FAIL;
        }

        CI2cStop();
    }

    return _SUCCESS;
}


//==============================================================================

