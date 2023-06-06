/*****************************************************************************/
/***************  Name    :   Abdulrahman Salem ******************************/
/***************  Date    :   10/5/2023         ******************************/
/**************   Version :   1.0V              ******************************/
/**************   SWC     :   stm32f401xx.h     ******************************/
/*****************************************************************************/

#ifndef STM32F401xx_H
#define STM32F401xx_H

/********************************** RCC Registers ************************/
#define RCC_u32_BASE_ADDRESS  0x40023800

typedef struct
{
	volatile u32 CR;
	volatile u32 PLLCFGR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 AHB1RSTR;
	volatile u32 AHB2RSTR;
	volatile u32 Res1;
	volatile u32 Res2;
	volatile u32 APB1RSTR;
	volatile u32 APB2RSTR;
	volatile u32 Res3;
	volatile u32 Res4;
	volatile u32 AHB1ENR;
	volatile u32 AHB2ENR;
	volatile u32 Res5;
	volatile u32 Res6;
	volatile u32 APB1ENR;
	volatile u32 APB2ENR;
	volatile u32 Res7;
	volatile u32 Res8;
	volatile u32 AHB1LPENR;
	volatile u32 AHB2LPENR;
	volatile u32 Res9;
	volatile u32 Res10;
	volatile u32 APB1LPENR;
	volatile u32 APB2LPENR;
	volatile u32 Res11;
	volatile u32 Res12;
	volatile u32 BDCR;
	volatile u32 CSR;
	volatile u32 Res13;
	volatile u32 Res14;
	volatile u32 SSCGR;
	volatile u32 PLLI2SCFGR;
	volatile u32 Res15;
	volatile u32 DCKCFGR;
	
}RCC_REG_DEF_T;
#define RCC ((RCC_REG_DEF_T*)RCC_u32_BASE_ADDRESS)
/*************************************************************************/
/***********************GPIO_REGISTER*************************************/
#define GPIOA_u32_BASE_ADDRESS  0x40020000
#define GPIOB_u32_BASE_ADDRESS  0x40020400
#define GPIOC_u32_BASE_ADDRESS  0x40023800
typedef struct
{
	volatile u32 MODER;
	volatile u32 OTYPER;
	volatile u32 OSPEEDR;
	volatile u32 PUPDR;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 LCKR;
	volatile u32 AFRL;
	volatile u32 AFRH;


}GPIO;
#define GPIOA_REG ((GPIO*)GPIOA_u32_BASE_ADDRESS)
#define GPIOB_REG ((GPIO*)GPIOB_u32_BASE_ADDRESS)
#define GPIOC_REG ((GPIO*)GPIOC_u32_BASE_ADDRESS)

/**********************************************************************************/




#endif
