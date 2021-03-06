

           /******************** TMP006 I2C1 DEVICE DRIVER FUNCTION PROTOTYPES  **********************/ 
                     /************* TMP006 IS INTERFACED WITH STM32F429ZIT6 **********/
#ifndef _I2C1_TMP006_H
#define _I2C1_TMP006_H

// Version : 2


// Includes
#include "stm32f4xx_hal.h"
#include "I2C_Error_Handler.h"

 // TEMPERATURE SENSOR TMP006 I2C1 Device Driver	Definitions

#define sens_reg        0x00                  // POINTER REGISTER ADDRESS FOR SENSOR VOLTAGE RESULT
#define temp_reg        0x01                  // POINTER REGISTER ADDRESS FOR TEMPERATURE REGISTER
#define config_reg      0x02                  // POINTER REGISTER ADDRESS FOR CONFIGURATION REGISTER
#define man_id_reg      0xFE                  // POINTER REGISTER ADDRESS FOR MANUFACTURER ID = 5449h
#define dev_id_reg      0xFF                  // POINTER REGISTER ADDRESS FOR DEVICE ID = 0067h
#define add_size    I2C_MEMADD_SIZE_8BIT      // POINTER REGISTER ADDRESS SIZE IS OF 8-BITS
#define dev_addr        0x82                  /* TMP006_I2C1 Device Address = 0x82 = 1000 0010 (7-bit Address 1000 001) 
                                                 &  8th Bit = 0 its Value Is Controlled By Processor 
                                                 Depending Upon Read Or Write Operation  */                      
#define dev_addr2       0x80
                
              
// HAL_I2C_Mem_Read(),HAL_I2C_Mem_Write () Parameter Values For Temperature Sensor TMP006

#define size1           0x02                  // Size Of Data To Be Sent & Received = 2 Bytes 
#define timeout         1000                  // TimeOut Duration = 1 second    
#define rb1_size         2                    // Rx Buffer Size = 2 Bytes Or Array Size = 2
#define tb1_size         2                    // Tx Buffer Size = 2 Bytes Or Array Size = 2 

/************* TMP006 Registers Read Functions Polling Based For TMP With Address = 0x82  *****************/

uint16_t r_dev_id1(void);    // device register read function
uint16_t r_man_id1(void);	   // manufacturer id register read function 
uint16_t r_config1(void);    // configuration register read function 
uint16_t r_temp1(void);      // temperature register read function
uint16_t r_sens1(void);      // sensor register read function



        /****** TMP006 CONFIGURATION REGISTER WRITE FUNCTIONS For TMP With Address = 0x82 ******/
	
void p_up_tmp1(void);       // POWER UP TMP006 
void p_down_tmp1(void);     // POWER DOWN TMP006
void rst_tmp1(void);				// RESET TMP006		 		 
void tmp1_1_samp(void);	    // Power Up TMP006 , Conversion Rate = 1 Samples Per Second , EN =1 (DRDY Bit Enabled) 
void tmp1_2_samp(void);	    // Power Up TMP006 , Conversion Rate = 2 Samples Per Second , EN =1 (DRDY Bit Enabled)                      
void tmp1_4_samp(void);	    // Power Up TMP006 , Conversion Rate = 4 Samples Per Second , EN =1 (DRDY Bit Enabled)                      
void tmp1_8_samp(void);		  // Power Up TMP006 , Conversion Rate = 8 Samples Per Second , EN =1 (DRDY Bit Enabled 								 						 
void tmp1_16_samp(void); 	  // Power Up TMP006 , Conversion Rate = 16 Samples Per Second , EN =1 (DRDY Bit Enabled)		



       /************* TMP006 Registers Read Functions Polling Based For TMP With Address = 0x80  *****************/

uint16_t r_dev_id2(void);   // device register read function
uint16_t r_man_id2(void);	  // manufacturer id register read function 
uint16_t r_config2(void);   // configuration register read function 
uint16_t r_temp2(void);     // temperature register read function
uint16_t r_sens2(void);     // sensor register read function	


        /****** TMP006 CONFIGURATION REGISTER WRITE FUNCTIONS For TMP With Address = 0x80 ******/
		 
void p_up_tmp2(void);       // POWER UP TMP006 
void p_down_tmp2(void);     // POWER DOWN TMP006
void rst_tmp2(void);				// RESET TMP006		 		 
void tmp2_1_samp(void);	    // Power Up TMP006 , Conversion Rate = 1 Samples Per Second , EN =1 (DRDY Bit Enabled) 
void tmp2_2_samp(void);	    // Power Up TMP006 , Conversion Rate = 2 Samples Per Second , EN =1 (DRDY Bit Enabled)                      
void tmp2_4_samp(void);	    // Power Up TMP006 , Conversion Rate = 4 Samples Per Second , EN =1 (DRDY Bit Enabled)                      
void tmp2_8_samp(void);		  // Power Up TMP006 , Conversion Rate = 8 Samples Per Second , EN =1 (DRDY Bit Enabled 								 						 
void tmp2_16_samp(void); 	  // Power Up TMP006 , Conversion Rate = 16 Samples Per Second , EN =1 (DRDY Bit Enabled)		

void tmp2_stat(void);       // TMP2 STATUS



 /*********Buffer Arrays For TMP006*************/


	
static uint8_t  rb1[rb1_size];                 // 2-Byte Buffer For Receiving Data
static uint8_t  tb1[tb1_size];                 // 2-Byte Buffer For Transmitting Dat



#endif /* _I2C1_TMP006_H */
                        
  												/*********End Of File**********/

