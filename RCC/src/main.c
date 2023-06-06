/*
 * main.c
 *
 *  Created on: May 10, 2023
 *      Author: Abdulrahman
 */


#include "BIT_MATH_H_.h"
#include "STD_Types.h"


#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"

void APP_void_DelayMS(u32 copy_u32Delay);


#define GPIOA_MODER   (*((volatile u32*)(0x40020000)))   //ddr
#define GPIOA_ODR     (*((volatile u32*)(0x40020014)))   // port

void main(void)
{
	/*set system clock*/
	RCC_void_InitSysClock();
	/*enable GPIOA clock*/
	RCC_void_EnablePeripheralClock(RCC_u8_AHB1_BUS,GPIOA);
	/*configure pin 0 as  output*/
	Set_Bit(GPIOA_MODER,0);

	/*make bit 0 High*/
	Set_Bit(GPIOA_ODR,0);
	while(1)
	{
		/*Tog led*/
		Tog_Bit(GPIOA_ODR,0);
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
