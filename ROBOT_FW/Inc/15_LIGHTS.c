
#include "15_LIGHTS.h"

void led_green_off(void)
{
HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_SET); // GREEN LED OFF ---> LED-B
}

void led_green_on(void)
{
HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_RESET); // GREEN LED ON---> LED-B
}

void toggle_green(void)
{
HAL_GPIO_TogglePin (GPIOD,GPIO_PIN_4);	
}

void led_red_off(void)
{
HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_SET); // RED LED OFF ---> LED-R
}

void led_red_on(void)
{
HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_RESET); // RED LED ON ---> LED-R
}

void toggle_red()
{
HAL_GPIO_TogglePin (GPIOD,GPIO_PIN_5);	
}



void led_fcam_off(void)
{
HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_SET); // FCAM LED OFF ---> LED-FCAM
}

void led_fcam_on(void)
{
HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_RESET); // FCAM LED ON ---> LED-FCAM
}

void led_x_on(void)
{
HAL_GPIO_WritePin(GPIOA,X_GPIO_1_Pin,GPIO_PIN_RESET); // X-GPIO-1 LED ON ---->X-GPIO-1-SEC	
}

void led_x_off(void)
{
HAL_GPIO_WritePin(GPIOA,X_GPIO_1_Pin,GPIO_PIN_SET);   // X-GPIO-1 LED OFF ---->X-GPIO-1-SEC	
}



void all_lights_off(void)
{
led_fcam_off();	
led_red_off();
led_green_off();
led_x_off();	
}

                            /*********End Of File**********/

