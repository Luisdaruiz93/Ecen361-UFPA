/***************************************************************************
 * Library for Thermal Sensor of the Adafruit AMG88xx.
 *
 *  Library is based on the a github library.
 *
 **************************************************************************/
#include <AMG88xx.h>
#include <i2c.h>
#include <eusci.h>

// Constants
#define     thermalAddress      0x69
#define     thermal_PixelSize   64

// Register Addresses
#define     Reg_PowerControl    0x00        // R/W, 8 bits, initial value is normal mode
#define     Reg_Reset           0x01        // W, 8 bits, initial value is nothing
#define     Reg_FrameRate       0x02        // R/W. LSB 1 bit, initial value is 10FPS
#define     Reg_InterruptState  0x03        // R/W, LSB 2 bits, initial value is ???
#define     Reg_Average         0x07        // R/W, @ bit 5 position, ???



/*         Register Values          */
#define PowerControl_NormalMode 0x00
#define PowerControl_SleepMode  0x10

#define Reset_InitialReset      0x3F
#define InterruptIntModeAbs     0x02
#define InterruptIntModeDiff    0x00
#define InterruptIntEnableAct   0x01
#define InterruptIntEnableReAct 0x00
#define FrameRate1FPS           0x01
#define FrameRate10FPS          0x00

// Structs
eUSCI_I2C_MasterConfig i2cConfig =
{
    EUSCI_B_I2C_CLOCKSOURCE_SMCLK,          // Clock that we will source from
    3000000,                                // Desired System Clock Rate 3MHz
    EUSCI_B_I2C_SET_DATA_RATE_400KBPS,      // Desired I2C Clock Rate
    0,                                      // No byte counter threshold
    EUSCI_B_I2C_NO_AUTO_STOP                // No Autostop
}

/**************************************************************************
 *  Description: Setups the I2C interface and hardware
 *
 *   @returns True if device is set up, false on any failure
 *
 *************************************************************************/
void AMG88xxInit(uint8_t addr)
{
    // Step 1: Initialize & enable I2C settings
    I2C_initMaster(EUSCI_B0_BASE, &i2cConfig);
    I2C_setSlaveAddress(EUSCI_B0_BASE, thermalAddress);
    I2C_setMode(EUSCI_B0_BASE, EUSCI_B_I2C_TRANSMIT_MODE);      // Master in transmit mode
    I2C_enableModule(EUSCI_B0_BASE);


     // Step 2: Initialize Thermal Sensor registers

    /*
     * Communication Process:
     *      Send a start sequence
     *      Send the I2C address of the slave with the R/W bit low (even address)
     *      Send the internal register number you want to write to
     *      Send the data byte
     *      [Optionally, send any further data bytes]
     *      Send the stop sequence.
     */

    // Enter Normal Mode
    I2C_masterSendMultiByteStart(EUSCI_B0_BASE, Reg_PowerControl);
    I2C_masterSendMultiByteFinish(EUSCI_B0_BASE, PowerControl_NormalMode);
    // Software Reset
    I2C_masterSendMultiByteStart(EUSCI_B0_BASE, Reg_Reset);
    I2C_masterSendMultiByteFinish(EUSCI_B0_BASE, Reset_InitialReset);
    // Disable interrupts
    I2C_masterSendMultiByteStart(EUSCI_B0_BASE, Reg_InterruptState);
    I2C_masterSendMultiByteFinish(EUSCI_B0_BASE, InterruptIntModeDiff | InterruptIntEnableReAct);
    // Set to 10 Frames a second
    I2C_masterSendMultiByteStart(EUSCI_B0_BASE, Reg_FrameRate);
    I2C_masterSendMultiByteFinish(EUSCI_B0_BASE, FrameRate10FPS);
}


/**************************************************************************
 *  Description: Reads Infrared sensor values
 *
 *  Parameters:
 *      *buf - pointer to store pixels/data
 *      size - number of bytes that we want to read. Max 64 bytes.
 *
 *  Note: Even though 64 is the max number of bytes it is not the actual
 *      amount of data we get back. There is a High and Low pair for every
 *      pixel.
 *
 *  Returned: Nothing
 *
 *************************************************************************/
void readThermalPixels(float *buf, uint8_t size)
{
    uint16_t recast;
    float converted;
    uint8_t bytesToRead = (size << 1);          // Double the Max # of Bytes
    uint8_t rawArray[bytesToRead];

    uint16_t pixelValue = 0;
    uint8_t i = 0;
    // Read from the sensor HELP See if I can move this and capsulate
    //I2C_setMode(EUSCI_B0_BASE, EUSCI_B_I2C_RECEIVE_MODE);
    while (i < size)
    {   /*
         * Communication Process:
         *      Send a start sequence
         *      Send the I2C address of the slave with the R/W bit low (even address)
         *      Send the internal register number you want to read from
         *      Send a start sequence again
         *      Send I2C address of the slave with a R/W bit high (odd address)
         *      Read data byte from slave
         *      Send the stop sequence.
         */
        I2C_masterSendSingleByte(EUSCI_B0_BASE, (0x80 + count));
        //I2C_masterReceiveStart(EUSCI_B0_BASE);
        //I2C_masterSendSingleByte(EUSCI_B0_BASE, );
        I2C_masterReceiveSingleByte(EUSCI_B0_BASE);
        //pixelValue = I2C_slaveGetData(EUSCI_B0_BASE);
    }


}



