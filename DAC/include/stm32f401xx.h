/*******************************************************************************/
/***************  Name    :   Abdulrahman Salem ********************************/
/***************  Date    :   10/5/2023         ********************************/
/**************   Version :   1.0V              ********************************/
/**************   SWC     :   stm32f401xx.h     ********************************/
/*******************************************************************************/

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
/****************************************************************/
#define SYS_TICK_BASE_ADDRESS  0xE000E010

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL ;
	volatile u32 CALIB;



}STK_t;
#define STK ((STK_t*)SYS_TICK_BASE_ADDRESS)


/**********************************************************************************/
/**************************NVIC_REGISTERS******************************************/
#define NVIC_BASE_ADDRESS 0xE000E100
typedef struct
{
	volatile u32 ISER[32];
	volatile u32 ICER[32];
	volatile u32 ISPR[32];
	volatile u32 ICPR[32];
	volatile u32 IABR[32];
	volatile u32 RES[32];
	volatile u8  IPR[240];
}NVIC_t;
#define NVIC ((NVIC_t*)NVIC_BASE_ADDRESS)
//#define AIRCR_ ((volatile u32*)0xE000ED0C)

/**********************************************************************************/
/**************************SCB_REGISTERS*******************************************/
#define SCB_BASE_ADDRESS 0xE000E008
typedef struct
{
	volatile u32 CPUID;
	volatile u32 ICSR;
	volatile u32 VTOR;
	volatile u32 AIRCR;
	volatile u32 SCR;
	volatile u32 SHPR[3];
	volatile u32 SHCSR;
	volatile u32 CFSR;
	volatile u32 HFSR;
	volatile u32 MMAR;
	volatile u32 BFAR;
	volatile u32 AFSR;

}SCB_t;
#define SCB ((SCB_t*)SCB_BASE_ADDRESS)
/************************************************************************************/
/******************************EXTI_REGISTERS****************************************/
#define EXTI_BASE_ADDRESS 0x40013C00
typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;


}EXTI_t;
#define EXTI ((EXTI_t*)EXTI_BASE_ADDRESS)
/**************************************************************************************/
/**********************************SYSCFG_REGISTERS************************************/
//AFIO
#define SYSCFG_BASE_ADDRESS 0x40013800
typedef struct
{
	volatile u32 MEMRMP;
	volatile u32 PMC;
	volatile u32 EXTICR[4];
	volatile u32 RES[2];
	volatile u32 CMPCR;

}SYSCFG_t;
#define SYSCFG ((SYSCFG_t*)SYSCFG_BASE_ADDRESS)
/**************************************************************************************/
#endif
