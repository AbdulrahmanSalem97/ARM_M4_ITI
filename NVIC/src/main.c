/*
 * main.c
 *
 *  Created on: May 19, 2023
 *      Author: Abdulrahman 
 */
#include "STD_Types.h"
#include "BIT_MATH_H_.h"
#include "stm32f401xx.h"

#include "GPIO_Interface.h"
#include "GPIO_Config.h"
#include "GPIO_Private.h"
#include "RCC_Interface.h"
#include "SYS_TICK_Interface.h"
#include "NVIC_Interface.h"

void main()
{
	RCC_void_InitSysClock();//init clock system
	STK_void_Init();
	RCC_void_EnablePeripheralClock(RCC_u8_AHB1_BUS,GPIOA_);
	NVIC_voidSetPriorityConfig(GROUP2BITS_SUBGROUP2BITS);
	/*set priority for exti0 and spi*/
	/* EXTI....grp1 ..sub 3*/
	NVIC_voidSetIntPriority(6,1,3);
	/*SPI......grp2...sub 0*/
	NVIC_voidSetIntPriority(35,2,0);
	/*enable the interrupts*/
	NVIC_voidEnablePerInt(6);
	NVIC_voidEnablePerInt(35);
	/*set pending flag*/
	NVIC_voidSetPendingFlag(6);


	GPIO_void_SetPinMode(GPIOA_,PIN0,INPUT);
	GPIO_void_SetPinSpeed(GPIOA_,PIN0,LOW_SPEED);
	GPIO_void_SetPinType(GPIOA_,PIN0,PULLUP);

	while(1)
	{


	}
}

void EXTI0_IRQHandler(void)
{
	GPIO_void_SetPinValue(GPIOA_,PIN0,HIGH);
	STK_void_SetBusyWait(50000000);
	GPIO_void_SetPinValue(GPIOA_,PIN0,LOW);
	STK_void_SetBusyWait(50000000);
}
void SPI1_IRQHandler(void)
{

}
