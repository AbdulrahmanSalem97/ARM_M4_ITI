/*
 * LEDMXD_Program.c
 *
 *  Created on: May 17, 2023
 *      Author: Abdulrahman
 */
#include "STD_Types.h"
#include "BIT_MATH_H_.h"

#include "GPIO_Interface.h"
#include "GPIO_Config.h"
#include "GPIO_Private.h"
#include "SYS_TICK_Interface.h"

#include "LEDMXD_Config.h"
#include "LEDMXD_Interface.h"
#include "LEDMXD_Private.h"

void LEDMXD_voidInit(void)
{
	/*set mode for rows and cols pins*/
	GPIO_void_SetPinMode(LEDMXD_ROW0_PIN);
	GPIO_void_SetPinMode(LEDMXD_ROW1_PIN);
	GPIO_void_SetPinMode(LEDMXD_ROW2_PIN);
	GPIO_void_SetPinMode(LEDMXD_ROW3_PIN);
	GPIO_void_SetPinMode(LEDMXD_ROW4_PIN);
	GPIO_void_SetPinMode(LEDMXD_ROW5_PIN);
	GPIO_void_SetPinMode(LEDMXD_ROW6_PIN);
	GPIO_void_SetPinMode(LEDMXD_ROW7_PIN);

	GPIO_void_SetPinMode(LEDMXD_COL0_PIN);
	GPIO_void_SetPinMode(LEDMXD_COL1_PIN);
	GPIO_void_SetPinMode(LEDMXD_COL2_PIN);
	GPIO_void_SetPinMode(LEDMXD_COL3_PIN);
	GPIO_void_SetPinMode(LEDMXD_COL4_PIN);
	GPIO_void_SetPinMode(LEDMXD_COL5_PIN);
	GPIO_void_SetPinMode(LEDMXD_COL6_PIN);
	GPIO_void_SetPinMode(LEDMXD_COL7_PIN);


}

u8 LEDMXD_u8Display(u8* Copy_u8Frame)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	if (Copy_u8Frame!=NULL)
	{
		 	/*Column 0*/
			/*Disable All Columns*/
			LEDMXD_voidDisableCols() ;
			/*Set Row Value*/
			LEDMXD_voidSetRowVlaues(Copy_u8Frame[0]) ;
			/*Enable Column0 */
			GPIO_void_SetPinValue(LEDMXD_COL0,LOW) ;
			//Delay 1042 us
			STK_void_SetBusyWait(2500) ; //2.5ms

			/*Column 1*/
			/*Disable All Columns*/
			LEDMXD_voidDisableCols() ;
			/*Set Row Value*/
			LEDMXD_voidSetRowVlaues(Copy_u8Frame[1]) ;
			/*Enable Column0 */
			GPIO_void_SetPinValue(LEDMXD_COL1,LOW) ;
			//Delay 1042 us
			STK_void_SetBusyWait(2500) ; //2.5ms

			/*Column 2*/
			/*Disable All Columns*/
			LEDMXD_voidDisableCols() ;
			/*Set Row Value*/
			LEDMXD_voidSetRowVlaues(Copy_u8Frame[2]) ;
			/*Enable Column0 */
			GPIO_void_SetPinValue(LEDMXD_COL2,LOW) ;
			//Delay 1042 us
			STK_void_SetBusyWait(2500) ; //2.5ms

			/*Column 3*/
			/*Disable All Columns*/
			LEDMXD_voidDisableCols() ;
			/*Set Row Value*/
			LEDMXD_voidSetRowVlaues(Copy_u8Frame[3]) ;
			/*Enable Column0 */
			GPIO_void_SetPinValue(LEDMXD_COL3,LOW) ;
			//Delay 1042 us
			STK_void_SetBusyWait(2500) ; //2.5ms

			/*Column 4*/
			/*Disable All Columns*/
			LEDMXD_voidDisableCols() ;
			/*Set Row Value*/
			LEDMXD_voidSetRowVlaues(Copy_u8Frame[4]) ;
			/*Enable Column0 */
			GPIO_void_SetPinValue(LEDMXD_COL4,LOW) ;
			//Delay 1042 us
			STK_void_SetBusyWait(2500) ; //2.5ms

			/*Column 5*/
			/*Disable All Columns*/
			LEDMXD_voidDisableCols() ;
			/*Set Row Value*/
			LEDMXD_voidSetRowVlaues(Copy_u8Frame[5]) ;
			/*Enable Column0 */
			GPIO_void_SetPinValue(LEDMXD_COL5,LOW) ;
			//Delay 1042 us
			STK_void_SetBusyWait(2500) ; //2.5ms


			/*Column 6*/
			/*Disable All Columns*/
			LEDMXD_voidDisableCols() ;
			/*Set Row Value*/
			LEDMXD_voidSetRowVlaues(Copy_u8Frame[6]) ;
			/*Enable Column0 */
			GPIO_void_SetPinValue(LEDMXD_COL6,LOW) ;
			//Delay 1042 us
			STK_void_SetBusyWait(2500) ; //2.5ms

			/*Column 7*/
			/*Disable All Columns*/
			LEDMXD_voidDisableCols() ;
			/*Set Row Value*/
			LEDMXD_voidSetRowVlaues(Copy_u8Frame[7]) ;
			/*Enable Column0 */
			GPIO_void_SetPinValue(LEDMXD_COL7,LOW) ;
			//Delay 1042 us
			STK_void_SetBusyWait(2500) ; //2.5ms

	}
	else
	{
		Local_u8ErrorState=STD_TYPES_NOT_OK;
	}




	return Local_u8ErrorState;
}
 void LEDMXD_voidDisableCols(void)
{
	GPIO_void_SetPinValue(LEDMXD_COL0,HIGH) ;
	GPIO_void_SetPinValue(LEDMXD_COL1,HIGH) ;
	GPIO_void_SetPinValue(LEDMXD_COL2,HIGH) ;
	GPIO_void_SetPinValue(LEDMXD_COL3,HIGH) ;
	GPIO_void_SetPinValue(LEDMXD_COL4,HIGH) ;
	GPIO_void_SetPinValue(LEDMXD_COL5,HIGH) ;
	GPIO_void_SetPinValue(LEDMXD_COL6,HIGH) ;
	GPIO_void_SetPinValue(LEDMXD_COL7,HIGH) ;
}

void LEDMXD_voidSetRowVlaues(u8 Copy_u8Frame)
{
	GPIO_void_SetPinValue(LEDMXD_ROW0,Get_Bit(Copy_u8Frame,0)) ;
	GPIO_void_SetPinValue(LEDMXD_ROW1,Get_Bit(Copy_u8Frame,1)) ;
	GPIO_void_SetPinValue(LEDMXD_ROW2,Get_Bit(Copy_u8Frame,2)) ;
	GPIO_void_SetPinValue(LEDMXD_ROW3,Get_Bit(Copy_u8Frame,3)) ;
	GPIO_void_SetPinValue(LEDMXD_ROW4,Get_Bit(Copy_u8Frame,4)) ;
	GPIO_void_SetPinValue(LEDMXD_ROW5,Get_Bit(Copy_u8Frame,5)) ;
	GPIO_void_SetPinValue(LEDMXD_ROW6,Get_Bit(Copy_u8Frame,6)) ;
	GPIO_void_SetPinValue(LEDMXD_ROW7,Get_Bit(Copy_u8Frame,7)) ;
}
void LEDMXD_u8ShiftingDisplay(u8* Copy_u8Frame)
{
	 u8 *ptr=Copy_u8Frame;


	 for(s8 i=0;i<=60;i++)
	 {
	LEDMXD_u8Display( ptr);
	 }
	ptr++;


}

