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
void Func(void);
void main()
{
	EXTI_PinConfig_t o={EXTI_u8_GPIOA,EXTI_u8_PIN9,EXTI_u8_RISING_EDGE,&Func};

	    RCC_void_InitSysClock();//init clock system
		STK_void_Init();
		RCC_void_EnablePeripheralClock(RCC_u8_AHB1_BUS,GPIOA_);
		RCC_void_EnablePeripheralClock(RCC_u8_APB2_BUS,SYSCFG_);
		//RCC_void_EnablePeripheralClock(RCC_u8_APB2_BUS,EXTI);
		NVIC_voidSetPriorityConfig(GROUP2BITS_SUBGROUP2BITS);
		/* EXTI....grp1 ..sub 3*/
		NVIC_voidSetIntPriority(6,1,3);
		/*SPI......grp2...sub 0*/
		NVIC_voidSetIntPriority(35,2,0);
		/*enable the interrupts*/
		NVIC_voidEnablePerInt(23);
		//NVIC_voidEnablePerInt(35);


		GPIO_void_SetPinMode(GPIOA_,PIN9,INPUT);
		GPIO_void_SetPinSpeed(GPIOA_,PIN9,LOW_SPEED);
		GPIO_void_SetPinType(GPIOA_,PIN9,PULL_DOWN);

		EXTI_voidPinIniit(&o);
		EXTI_voidIntEnable(9);




	while(1)
	{


	}
}
void Func(void)
{
	/*GPIO_void_SetPinMode(GPIOA_,PIN1,OUTPUT);
	GPIO_void_SetPinSpeed(GPIOA_,PIN1,LOW_SPEED);
	GPIO_void_SetPinType(GPIOA_,PIN1,PUSH_PULL);
	GPIO_void_SetPinValue(GPIOA_,PIN1,HIGH);
	STK_void_SetBusyWait(100000000);
	GPIO_void_SetPinValue(GPIOA_,PIN1,LOW);
	STK_void_SetBusyWait(100000000);*/
	for (u8 j=2;j<=7;j++)
		 {
			GPIO_void_SetPinMode(GPIOA_,j,OUTPUT);
			GPIO_void_SetPinSpeed(GPIOA_,j,LOW_SPEED);
			GPIO_void_SetPinType(GPIOA_,j,PUSH_PULL);
		 }


			 for (u8 j=2;j<=7;j++)
			 {
				 GPIO_void_SetPinValue(GPIOA_,j,HIGH);
				 STK_void_SetBusyWait(1000000);
				 GPIO_void_SetPinValue(GPIOA_,j,LOW);
				 STK_void_SetBusyWait(1000000);
			 }

}

