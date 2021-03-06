

  /******************** Si7020-A20 I2C1 DEVICE DRIVER FUNCTION PROTOTYPES  **********************/ 
                     /************* Si7020-A20 IS INTERFACED WITH STM32F429ZIT6 **********/
#ifndef _I2C1_Si7020_H
#define _I2C1_Si7020_H

// Version : 2

// Includes
#include "stm32f4xx_hal.h"
#include "I2C_Error_Handler.h"
#include "math.h"


// TEMPERATURE & HUMIDITY SENSOR Si7020-A20 Device Driver Definitions

#define dev_addr3       0x80                  // Si7020-A20 Device Address

#define cmd_rhm1        0xE5                  // Command To Measure Relative Humidity ,Hold Master Mode  
#define cmd_rhm2        0xF5                  // Command To Measure Relative Humidity ,No Hold Master Mode

#define cmd_temp1       0xE3                  // Command To Measure Temperature  , Hold Master Mode
#define cmd_temp2       0xF3                  // Command For Reading Temperature , No Hold Master Mode 
#define cmd_temp3       0xE0                  // Command For Reading Temperature , From Previous RH Measurement 

#define cmd_rheat       0x11                  // Command To Read Heater Control Register
#define cmd_wheat       0x51                  // Command To Write Heater Control Register
#define cmd_rst         0xFE                  // Command For Resetting Device

#define cmd_eid1       0xFA0F                 // Command For Reading Electronic ID First Byte
#define cmd_eid2       0xFCC9                 // Command For Reading Electronic ID Second Byte

#define cmd_rev        0x84B8                 // Command For Reading Firmware                

#define add_size     I2C_MEMADD_SIZE_8BIT     // POINTER REGISTER ADDRESS SIZE IS OF 8-BITS
#define add_size3    I2C_MEMADD_SIZE_16BIT    // POINTER REGISTER ADDRESS SIZE IS OF 16-BITS


/**** Si7020 : I/O Function Prototypes *****/

void    rst_si7020(void);    // RESET Si7020



// Function Prototypes

uint8_t  r_firm_v(void);    // Command For Reading  Firmware Version
uint16_t r_eid1(void);      // Command For Reading 1st Electronic ID Second Byte
uint8_t  r_eid2(void);      // Command For Reading 2nd Electronic ID Second Byte
uint8_t  r_heat(void);      // Command For Reading Heater Register

void       si_stat(void);       // Command For Checking Sensor Status
float   r_hum1(void);        // Command To Measure Relative Humidity ,Hold Master Mode
float   r_temp11(void);      // Command To Measure Temperature  , Hold Master Mode
float   r_temp33(void);      // Command For Reading Temperature , From Previous RH Measurement 


// MEMORY READ FUNCTION PARAMETERS

#define t1 1000              // TimeOut Duration = 1 second		


#endif /* _I2C1_Si7020_H */
                        
  												/*********End Of File**********/
