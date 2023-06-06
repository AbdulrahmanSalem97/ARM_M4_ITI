/******************************************************************************/
/***************  Name    :   Abdulrahman Salem  ******************************/
/***************  Date    :   10/5/2023          ******************************/
/**************   Version :   1.0V               ******************************/
/**************   SWC     :   RCC                ******************************/
/******************************************************************************/


#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H
/*Macros For Buses*/
#define RCC_u8_AHB1_BUS    1
#define RCC_u8_AHB2_BUS    2
#define RCC_u8_APB1_BUS    3
#define RCC_u8_APB2_BUS    4
/******************/
/*Macros For Peripheral connected to AHB1*/
#define GPIOA   0
#define GPIOB   1
#define GPIOC   2
#define GPIOD   3
#define GPIOE   4
#define GPIOH   7
#define CRC     12
#define DMA1    21
#define DMA2    22
/*****************************************/
/*Macros For Peripheral connected to APB1*/
#define TIM2    0
#define TIM3    1
#define TIM4    2
#define TIM5    3
#define WWDG    11
#define SPI2    14
#define SPI3    15
#define USART2  17
#define I2C1    21
#define I2C2    22
#define I2C3    23
#define PWR     28
/*****************************************/
/*Macros For Peripheral connected to APB2*/
#define TIM1    0
#define USART1  4
#define USART6  5
#define ADC1    8
#define SDIO    11
#define SPI1    12
#define SPI4LP  13
#define SYSCFG  14
#define TIM9    16
#define TIM10   17
#define TIM11   18
/*****************************************/
/*Macros For Peripheral connected to AHB2*/
#define OTGFSEN 7
/*****************************************/


u8 RCC_void_EnablePeripheralClock(u8 copy_u8Bus, u8 copy_u8_Peripheral_ID);
u8 RCC_void_DisablePeripheralClock(u8 copy_u8Bus, u8 copy_u8_Peripheral_ID);
void RCC_void_InitSysClock(void);



#endif
