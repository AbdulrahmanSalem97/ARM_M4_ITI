#include "STD_Types.h"
#include "BIT_MATH_H_.h"
#include "stm32f401xx.h"

#include "GPIO_Interface.h"
#include "GPIO_Config.h"
#include "GPIO_Private.h"
#include "RCC_Interface.h"
#include "SYS_TICK_Interface.h"
#include "NVIC_Interface.h"
#include "EXTI_Interface.h"
#include "SEVENSEGEMENTS_Interface.h"
void Func(void);
void func1(void);
void main()
{


	EXTI_PinConfig_t o={EXTI_u8_GPIOA,EXTI_u8_PIN9,EXTI_u8_RISING_EDGE,&Func};
	EXTI_PinConfig_t o1={EXTI_u8_GPIOA,EXTI_u8_PIN11,EXTI_u8_RISING_EDGE,&func1};

	    RCC_void_InitSysClock();//init clock system
		STK_void_Init();
		RCC_void_EnablePeripheralClock(RCC_u8_AHB1_BUS,GPIOA_);
		RCC_void_EnablePeripheralClock(RCC_u8_APB2_BUS,SYSCFG_);

		NVIC_voidSetPriorityConfig(GROUP2BITS_SUBGROUP2BITS);//GROUP2BITS_SUBGROUP2BITS
		/* EXTI9....grp2 ..sub 3*/
		NVIC_voidSetIntPriority(23,2,0);
		/*EXTI11......grp1...sub 0*/
		NVIC_voidSetIntPriority(40,1,0);
		/*enable the interrupts*/
		NVIC_voidEnablePerInt(23);
		NVIC_voidEnablePerInt(40);


		GPIO_void_SetPinMode(GPIOA_,PIN9,INPUT);
		GPIO_void_SetPinSpeed(GPIOA_,PIN9,LOW_SPEED);
		GPIO_void_SetPinType(GPIOA_,PIN9,PULL_DOWN);
		GPIO_void_SetPinMode(GPIOA_,PIN11,INPUT);
		GPIO_void_SetPinSpeed(GPIOA_,PIN11,LOW_SPEED);
		GPIO_void_SetPinType(GPIOA_,PIN11,PULL_DOWN);

		EXTI_voidPinIniit(&o);
		EXTI_voidIntEnable(9);
		EXTI_voidPinIniit(&o1);
		EXTI_voidIntEnable(11);
		GPIO_void_SetPinMode(GPIOA_,PIN10,OUTPUT);
		GPIO_void_SetPinSpeed(GPIOA_,PIN10,LOW_SPEED);
		GPIO_void_SetPinType(GPIOA_,PIN10,PUSH_PULL);




	while(1)
	{


	}
}
void Func(void)
{
	SEVENSEGMENTS_voidInit(GPIOA_);




	for(u8 i=0;i<=9;i++)
	{
		SEVENSEGMENTS_voidGet(GPIOA_,i);
		if (i==5)
		{

			//NVIC_voidSetPendingFlag(23);

		}
		STK_void_SetBusyWait(10000000);


	}


	/*for (u8 j=2;j<=7;j++)
		 {
			GPIO_void_SetPinMode(GPIOA_,j,OUTPUT);
			GPIO_void_SetPinSpeed(GPIOA_,j,LOW_SPEED);
			GPIO_void_SetPinType(GPIOA_,j,PUSH_PULL);
		 }


			 for (u8 j=2;j<=7;j++)
			 {
				 GPIO_void_SetPinValue(GPIOA_,j,HIGH);
				 STK_void_SetBusyWait(10000000);
				 GPIO_void_SetPinValue(GPIOA_,j,LOW);
				 STK_void_SetBusyWait(10000000);
			 }*/

}
void func1(void)
{

	GPIO_void_SetPinValue(GPIOA_,10,HIGH);
	 STK_void_SetBusyWait(10000000);
	 GPIO_void_SetPinValue(GPIOA_,10,LOW);
	 STK_void_SetBusyWait(10000000);

}

