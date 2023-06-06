/*
 * main.c
 *
 *  Created on: May 29, 2023
 *      Author: Abdulrahman
 */


#include "STD_Types.h"
#include "BIT_MATH_H_.h"
#include "stm32f401xx.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "SYS_TICK_Interface.h"
#include "song.h"
 volatile u32 Local_u8Counter;
void Func()
{

	GPIOA_REG->ODR=song_raw[Local_u8Counter];
	Local_u8Counter++;
	if(Local_u8Counter==25635)
	{
		Local_u8Counter=0;
	}

}

int main()
{
	RCC_void_InitSysClock();
	RCC_void_EnablePeripheralClock(RCC_u8_AHB1_BUS,GPIOA_);
	//RCC_void_EnablePeripheralClock(RCC_u8_AHB1_BUS,GPIOB_);
	GPIO_void_SetPinMode(GPIOA_,PIN0,OUTPUT);
	GPIO_void_SetPinMode(GPIOA_,PIN1,OUTPUT);
	GPIO_void_SetPinMode(GPIOA_,PIN2,OUTPUT);
	GPIO_void_SetPinMode(GPIOA_,PIN3,OUTPUT);
	GPIO_void_SetPinMode(GPIOA_,PIN4,OUTPUT);
	GPIO_void_SetPinMode(GPIOA_,PIN5,OUTPUT);
	GPIO_void_SetPinMode(GPIOA_,PIN6,OUTPUT);
	GPIO_void_SetPinMode(GPIOA_,PIN7,OUTPUT);
	GPIO_void_SetPinType(GPIOA_,PIN0,PUSH_PULL);
	GPIO_void_SetPinType(GPIOA_,PIN1,PUSH_PULL);
	GPIO_void_SetPinType(GPIOA_,PIN2,PUSH_PULL);
	GPIO_void_SetPinType(GPIOA_,PIN3,PUSH_PULL);
	GPIO_void_SetPinType(GPIOA_,PIN4,PUSH_PULL);
	GPIO_void_SetPinType(GPIOA_,PIN5,PUSH_PULL);
	GPIO_void_SetPinType(GPIOA_,PIN6,PUSH_PULL);
	GPIO_void_SetPinType(GPIOA_,PIN7,PUSH_PULL);

	STK_void_Init();

	STK_voidSetInternalPeriodic(125,Func);
	while(1)
	{

	}



	return 0;
}
