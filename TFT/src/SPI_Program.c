/*******************************************************************/
/****************** Author    : Abdulrahman Salem  *****************/
/****************** Date      : 2/6/2023          ******************/
/****************** Version   : 1.0v               *****************/
/****************** SWC       : SPI                *****************/
/*******************************************************************/
#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"

#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"

/*void (*SPI1_CallBack)(void);*/

void SPI_voiInit()
{
    /*2 Line unidirectional data mode selection */
	CLR_BIT(SPI1->CR1,15);
	CLR_BIT(SPI1->CR1,14);

	/*Disable CRC*/
	CLR_BIT(SPI1->CR1,13);
	CLR_BIT(SPI1->CR1,12);

	/*Data Frame Format ->8-bit*/
	CLR_BIT(SPI1->CR1,11);

	/*Full Duplex*/
	CLR_BIT(SPI1->CR1,10);

	/*SW Slave Management Enable */
	SET_BIT(SPI1->CR1,9);
    
	/*Internal Slave Select->Master*/
	SET_BIT(SPI1->CR1,8);

	/*MSB Mode*/
	CLR_BIT(SPI1->CR1,7);

	/*BaudRate Prescaler ->clk/2 */
	CLR_BIT(SPI1->CR1,5);
	CLR_BIT(SPI1->CR1,4);
	CLR_BIT(SPI1->CR1,3);

	/*Master Select*/
	SET_BIT(SPI1->CR1,2);

	/*CLK Polarity -> Idle High-> Falling Edge*/
	SET_BIT(SPI1->CR1,1);

	/*CLK Phase ->Write then Read->Second clk transition*/
	SET_BIT(SPI1->CR1,0);

	/*SPI Enable*/
	SET_BIT(SPI1->CR1,6);

}
u8 SPI_u8TrancieveData(u8 Copy_u8Data)
{
	/*Put Data in Data Register*/
	SPI1->DR = Copy_u8Data;

	/*Polling on Busy Flag... 1-> Busy*/
	while(GET_BIT(SPI1->SR,7) ==1);

	/*For recieving Data*/
	return (u8)SPI1->DR;

}


/*void SPI_voidSetCallBack(void (*ptr)(void))
{


    
}*/
