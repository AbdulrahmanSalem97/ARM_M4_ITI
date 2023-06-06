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
#include "GPIO_Config.h"
#include "GPIO_Private.h"
#include "GPIO_Interface.h"
#include "SYS_TICK_Interface.h"
#include "SYS_TICK_Config.h"
#include "SYSTICK_Private.h"
#include "SEVENSEGEMENTS_Interface.h"






void main(void)
{
	STK_void_Init();
	/*set system clock*/
	RCC_void_InitSysClock();
	/*enable GPIOA clock*/
	RCC_void_EnablePeripheralClock(RCC_u8_AHB1_BUS,GPIOA_);
	//RCC_void_EnablePeripheralClock(RCC_u8_AHB1_BUS,GPIOB_);
	//SEVENSEGMENTS_voidInit(GPIOA);

	GPIO_void_SetPinMode(GPIOA,PIN0,OUTPUT);
	GPIO_void_SetPinType(GPIOA,PIN0,PUSH_PULL);






	while(1)
	{
		GPIO_void_SetPinValue(GPIOA,PIN0,LOW);
		STK_void_SetBusyWait((1000000));

		/*Tog led*/
		GPIO_void_SetPinValue(GPIOA,PIN0,HIGH);
		STK_void_SetBusyWait((1000000));
		//GPIO_void_SetPinValue(GPIOB,PIN5,HIGH);
		//APP_void_DelayMS(10000);

		//GPIO_void_SetPinValue(GPIOB,PIN5,LOW);
		//APP_void_DelayMS(10000);
		//SEVENSEGMENTS_voidGet(GPIOA,7);


		/*for(int i=0;i<10;i++)
				{
					SEVENSEGMENTS_voidGet(GPIOA,i);
					STK_void_SetBusyWait(1000000UL);
				}*/




	}



}


