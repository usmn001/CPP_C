
// Includes
#include "7_I2C2_OV7670.h"
#include "SCCB.h"
#include "delay.h"

#include "I2C_Error_Handler.h"

// External Private VARIABLE
extern I2C_HandleTypeDef hi2c2;
//extern DCMI_HandleTypeDef hdcmi;

static uint8_t  tb_8[1];                    // A 8 Byte TX Buffer Of 1 Memory Locations
static uint8_t  rb_8[4];                    // A 8 Byte RX Buffer Of 1 Memory Locations
static uint16_t tb_16[1];                   // A 16 Byte TX Buffer Of 1 Memory Locations
static uint16_t rb_16[1];                   // A 16 Byte RX Buffer Of 1 Memory Locations


/************ Camera IO Functions ***********/

void Cam_Pwdn(void)                                                     // Power Down Camera
{
HAL_GPIO_WritePin(GPIOD,PD_11_GPIO_Pin,GPIO_PIN_SET);			
}

void Cam_Pwup(void)
{
HAL_GPIO_WritePin(GPIOD,PD_11_GPIO_Pin,GPIO_PIN_RESET);			             // Power Up Camera
}


void Cam_Set(void)                                                       // Set Camera
{
HAL_GPIO_WritePin(CAM_RST_GPIO_Port,CAM_RST_Pin,GPIO_PIN_RESET);
}	

void Cam_Rst(void)
{
HAL_GPIO_WritePin(CAM_RST_GPIO_Port,CAM_RST_Pin,GPIO_PIN_SET);           // Reset Camera	
}




// READ OV7670 PID MSB  
/*
uint8_t r_Cam_Pid(void)
{	
unsigned char regID = 0x7A;	
uint8_t cam_pid =rdOV7670Reg(regID);
return cam_pid;                                 
}
void set_OV7670reg(void)
{
	wrOV7670Reg(0x8c, 0x00);
	wrOV7670Reg(0x3a, 0x04);
	wrOV7670Reg(0x40, 0xd0);
	wrOV7670Reg(0x8c, 0x00);
	wrOV7670Reg(0x12, 0x14);
	wrOV7670Reg(0x32, 0x80);
	wrOV7670Reg(0x17, 0x16);
	wrOV7670Reg(0x18, 0x04);
	wrOV7670Reg(0x19, 0x02);
	wrOV7670Reg(0x1a, 0x7b);
	wrOV7670Reg(0x03, 0x06);
	wrOV7670Reg(0x0c, 0x04);
	wrOV7670Reg(0x3e, 0x00);
	wrOV7670Reg(0x70, 0x3a);
	wrOV7670Reg(0x71, 0x35); 
	wrOV7670Reg(0x72, 0x11); 
	wrOV7670Reg(0x73, 0x00);
	wrOV7670Reg(0xa2, 0x00);
	wrOV7670Reg(0x11, 0xff); 
	//wrOV7670Reg(0x15 , 0x31);
	wrOV7670Reg(0x7a, 0x20); 
	wrOV7670Reg(0x7b, 0x1c); 
	wrOV7670Reg(0x7c, 0x28); 
	wrOV7670Reg(0x7d, 0x3c);
	wrOV7670Reg(0x7e, 0x55); 
	wrOV7670Reg(0x7f, 0x68); 
	wrOV7670Reg(0x80, 0x76);
	wrOV7670Reg(0x81, 0x80); 
	wrOV7670Reg(0x82, 0x88);
	wrOV7670Reg(0x83, 0x8f);
	wrOV7670Reg(0x84, 0x96); 
	wrOV7670Reg(0x85, 0xa3);
	wrOV7670Reg(0x86, 0xaf);
	wrOV7670Reg(0x87, 0xc4); 
	wrOV7670Reg(0x88, 0xd7);
	wrOV7670Reg(0x89, 0xe8);
	 
	wrOV7670Reg(0x32,0xb6);
	
	wrOV7670Reg(0x13, 0xff); 
	wrOV7670Reg(0x00, 0x00);
	wrOV7670Reg(0x10, 0x00);
	wrOV7670Reg(0x0d, 0x00);
	wrOV7670Reg(0x14, 0x4e);
	wrOV7670Reg(0xa5, 0x05);
	wrOV7670Reg(0xab, 0x07); 
	wrOV7670Reg(0x24, 0x75);
	wrOV7670Reg(0x25, 0x63);
	wrOV7670Reg(0x26, 0xA5);
	wrOV7670Reg(0x9f, 0x78);
	wrOV7670Reg(0xa0, 0x68);
//	wrOV7670Reg(0xa1, 0x03);//0x0b,
	wrOV7670Reg(0xa6, 0xdf);
	wrOV7670Reg(0xa7, 0xdf);
	wrOV7670Reg(0xa8, 0xf0); 
	wrOV7670Reg(0xa9, 0x90); 
	wrOV7670Reg(0xaa, 0x94); 
	//wrOV7670Reg(0x13, 0xe5); 
	wrOV7670Reg(0x0e, 0x61);
	wrOV7670Reg(0x0f, 0x43);
	wrOV7670Reg(0x16, 0x02); 
	wrOV7670Reg(0x1e, 0x37);
	wrOV7670Reg(0x21, 0x02);
	wrOV7670Reg(0x22, 0x91);
	wrOV7670Reg(0x29, 0x07);
	wrOV7670Reg(0x33, 0x0b);
	wrOV7670Reg(0x35, 0x0b);
	wrOV7670Reg(0x37, 0x3f);
	wrOV7670Reg(0x38, 0x01);
	wrOV7670Reg(0x39, 0x00);
	wrOV7670Reg(0x3c, 0x78);
	wrOV7670Reg(0x4d, 0x40);
	wrOV7670Reg(0x4e, 0x20);
	wrOV7670Reg(0x69, 0x00);
	wrOV7670Reg(0x6b, 0x4a);
	wrOV7670Reg(0x74, 0x19);
	wrOV7670Reg(0x8d, 0x4f);
	wrOV7670Reg(0x8e, 0x00);
	wrOV7670Reg(0x8f, 0x00);
	wrOV7670Reg(0x90, 0x00);
	wrOV7670Reg(0x91, 0x00);
	wrOV7670Reg(0x92, 0x00);
	wrOV7670Reg(0x96, 0x00);
	wrOV7670Reg(0x9a, 0x80);
	wrOV7670Reg(0xb0, 0x84);
	wrOV7670Reg(0xb1, 0x0c);
	wrOV7670Reg(0xb2, 0x0e);
	wrOV7670Reg(0xb3, 0x82);
	wrOV7670Reg(0xb8, 0x0a);
	wrOV7670Reg(0x43, 0x14);
	wrOV7670Reg(0x44, 0xf0);
	wrOV7670Reg(0x45, 0x34);
	wrOV7670Reg(0x46, 0x58);
	wrOV7670Reg(0x47, 0x28);
	wrOV7670Reg(0x48, 0x3a);
	
	wrOV7670Reg(0x59, 0x88);
	wrOV7670Reg(0x5a, 0x88);
	wrOV7670Reg(0x5b, 0x44);
	wrOV7670Reg(0x5c, 0x67);
	wrOV7670Reg(0x5d, 0x49);
	wrOV7670Reg(0x5e, 0x0e);
	
	wrOV7670Reg(0x64, 0x04);
	wrOV7670Reg(0x65, 0x20);
	wrOV7670Reg(0x66, 0x05);

	wrOV7670Reg(0x94, 0x04);
	wrOV7670Reg(0x95, 0x08);	 

	wrOV7670Reg(0x6c, 0x0a);
	wrOV7670Reg(0x6d, 0x55);
	wrOV7670Reg(0x6e, 0x11);
	wrOV7670Reg(0x6f, 0x9f); 

	wrOV7670Reg(0x6a, 0x40);
	wrOV7670Reg(0x01, 0x40);
	wrOV7670Reg(0x02, 0x40);
	
	//wrOV7670Reg(0x13, 0xe7);
	wrOV7670Reg(0x15, 0x00);
	wrOV7670Reg(0x4f, 0x80);
	wrOV7670Reg(0x50, 0x80);
	wrOV7670Reg(0x51, 0x00);
	wrOV7670Reg(0x52, 0x22);
	wrOV7670Reg(0x53, 0x5e);
	wrOV7670Reg(0x54, 0x80);
	wrOV7670Reg(0x58, 0x9e);

	wrOV7670Reg(0x41, 0x08);
	wrOV7670Reg(0x3f, 0x00);
	wrOV7670Reg(0x75, 0x05);
	wrOV7670Reg(0x76, 0xe1);

	wrOV7670Reg(0x4c, 0x00);
	wrOV7670Reg(0x77, 0x01);
	
	wrOV7670Reg(0x3d, 0xc1);
	wrOV7670Reg(0x4b, 0x09);
	wrOV7670Reg(0xc9, 0x60);
	//wrOV7670Reg(0x41, 0x38);	
	wrOV7670Reg(0x56, 0x40);
	wrOV7670Reg(0x34, 0x11);
	wrOV7670Reg(0x3b, 0x02);
	wrOV7670Reg(0xa4, 0x89);
	
	wrOV7670Reg(0x96, 0x00);
	wrOV7670Reg(0x97, 0x30);
	wrOV7670Reg(0x98, 0x20);
	wrOV7670Reg(0x99, 0x30);
	wrOV7670Reg(0x9a, 0x84);
	wrOV7670Reg(0x9b, 0x29);
	wrOV7670Reg(0x9c, 0x03);
	wrOV7670Reg(0x9d, 0x4c);
	wrOV7670Reg(0x9e, 0x3f);	

	wrOV7670Reg(0x09, 0x00);
	wrOV7670Reg(0x3b, 0xc2);

}


void w_pid_msb(uint8_t data)
{
uint8_t tb_8[] = {PID,data};  
if(HAL_SCCB_Mem_Write(&hi2c2,cam_dev_w,PID,mem_size,(uint8_t*)tb_8,s_16,timeout)!=HAL_OK)
{
i2c2_error_handler();
}	
}

// READ OV7670 PID LSB  

uint8_t Cam_Ver(void)
{	
uint8_t cam_ver = 0;                                // Variable For Storing PID MSB	
if( HAL_SCCB_Mem_Read(&hi2c2,cam_dev_r,VER,mem_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)	
{	
cam_ver = rb_8[0];
return cam_ver;	
}		
else
i2c2_error_handler();
return 0;	
}*/


void Cam_Stat(void)
{
if(HAL_I2C_IsDeviceReady(&hi2c2,cam_dev_r,1,1000)!=HAL_OK)	
{
i2c2_error_handler();
}	
}
// READ OV7670 PID REGISTER  

uint8_t R_Cam_PID(void)
{	

uint8_t cam_pid = 0;                         // Variable For Storing PID MSB	
if( HAL_I2C_Mem_Read(&hi2c2,cam_dev_r,PID,add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)	
{
cam_pid = rb_8[0];
}		
return cam_pid;	
}
/*
// READ OV7670 GAIN REGISTER  

uint8_t r_cam_gain(void)
{	

uint8_t cam_gain = 0;                         // Variable For Storing PID MSB	
if( HAL_I2C_Mem_Read(&hi2c2,cam_dev_r,OV7660_CTL_GAIN,add_size,(uint8_t*)Rxbuff2,size,timeout)==HAL_OK)	
{
cam_gain = Rxbuff2[0];
}		
return cam_gain;	
}

// READ OV7670 BLUE REGISTER  

uint8_t r_cam_blue(void)
{
uint8_t cam_blue = 0; 
if( HAL_I2C_Mem_Read(&hi2c2,cam_dev_r,OV7660_CTL_BLUE,add_size,(uint8_t*)Rxbuff2,size,timeout)==HAL_OK)	
{	
cam_blue = Rxbuff2[0];
}		
return cam_blue;	
}
	
// READ OV7670 RED REGISTER  

uint8_t r_cam_red(void)
{
uint8_t cam_red =0; 
if( HAL_I2C_Mem_Read(&hi2c2,cam_dev_r,OV7660_CTL_RED,add_size,(uint8_t*)Rxbuff2,size,timeout)==HAL_OK)	
{
cam_red = Rxbuff2[0];
}		
return cam_red;	
}	*/



// Writing PID MSB OF OV7670




// DCMI FUNCTIONS


/*
void start_capture(void)
{
uint32_t buff[50][50];
if( ( HAL_DCMI_Start_DMA(&hdcmi, DCMI_MODE_CONTINUOUS,(uint32_t)buff,10) )==HAL_OK )
{	
	
}
}

void stop_capture(void)
{
HAL_DCMI_Stop(&hdcmi);		
}*/





