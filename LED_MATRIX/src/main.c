/*
 * main.c
 *
 *  Created on: May 28, 2023
 *      Author: Abdulrahman
 */


#include "STD_TYPES.h"
#include "BIT_MATH_H_.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "SYS_TICK_Interface.h"
#include "LEDMXD_Interface.h"
#include "string.h"


u8 GLOB_u8DataArr[] = {0, 0, 0, 0, 0, 0, 0, 0,255, 2, 4, 8, 8, 4, 2, 255,0, 56, 68, 68, 68, 56, 0, 0,0, 255, 8, 8, 8, 248, 0, 0,0, 0, 60, 36, 36, 36, 120, 64};//{0, 127, 73, 73, 65, 0, 0, 0} ;
u8* ptr=GLOB_u8DataArr;

void main(void)
{
	/*Step 1 : System Clock is 16 MHz From HSI*/
	RCC_void_InitSysClock();

	/*Step 2 : Enable GPIO Peripheral Clock For Port A*/
	RCC_void_EnablePeripheralClock(RCC_u8_AHB1_BUS,GPIOA_);

	/*Step 3 : Enable GPIO Peripheral Clock For Port B*/
	RCC_void_EnablePeripheralClock(RCC_u8_AHB1_BUS,GPIOB_);

	/*STK init*/
	STK_void_Init();
	/*Step 4 : Initialize For LED Matrix*/

    LEDMXD_voidInit();

	/* Loop forever */
    u32 x;
    x=strlen(GLOB_u8DataArr);

	while(1)
	{

		for ( u8 i=0 ; i<x-1 ; i++ )
				{
					for(u8 s=0;s<=50;s++)
					{
						LEDMXD_u8Display(ptr);
					}
					ptr++;

				}

	}

}


