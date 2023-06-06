/*
 * main.c
 *
 *  Created on: May 12, 2023
 *      Author: Abdulrahman
 */
#include "BIT_MATH_H_.h"
#include "STD_Types.h"



#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"

void APP_void_DelayMS(u32 copy_u32Delay);




void main(void)
{
	/*set system clock*/
	RCC_void_InitSysClock();
	/*enable GPIOA clock*/
	RCC_void_EnablePeripheralClock(RCC_u8_AHB1_BUS,GPIOA_);
	RCC_void_EnablePeripheralClock(RCC_u8_AHB1_BUS,GPIOB_);
	/*configure pin 5 as  output*/
	GPIO_void_SetPinMode(GPIOA,PIN5,OUTPUT);
	GPIO_void_SetPinMode(GPIOB,PIN5,OUTPUT);
	/**/
	GPIO_void_SetPinType(GPIOA,PIN5,PUSH_PULL);
	GPIO_void_SetPinType(GPIOB,PIN5,PUSH_PULL);


	while(1)
	{
		/*Tog led*/
		GPIO_void_SetPinValue(GPIOA,PIN5,HIGH);
		GPIO_void_SetPinValue(GPIOB,PIN5,HIGH);
		APP_void_DelayMS(10000);
		GPIO_void_SetPinValue(GPIOA,PIN5,LOW);
		GPIO_void_SetPinValue(GPIOB,PIN5,LOW);
		APP_void_DelayMS(10000);


	}



}
void APP_void_DelayMS(u32 copy_u32Delay)
{
	for(u32 i=0;i<copy_u32Delay*300;i++)
	{
		asm("NOP");
	}
}

