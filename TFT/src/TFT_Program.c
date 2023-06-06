#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#include "SPI_Interface.h"
#include "MSYSTICK_Interface.h"
#include "MGPIO_interface.h"
#include"TFT_config.h"
#include"TFT_private.h"
#include"TFT_interface.h"


void TFT_voidInit()
{
	/*Reset pulse*/
	MGPIO_voidWriteData(TFT_RST_PIN,HIGH);
	MSTK_voidStart(10);
	MGPIO_voidWriteData(TFT_RST_PIN,LOW);
	MSTK_voidStart(1);
	MGPIO_voidWriteData(TFT_RST_PIN,HIGH);
	MSTK_voidStart(10);
	MGPIO_voidWriteData(TFT_RST_PIN,LOW);
	MSTK_voidStart(10);
	MGPIO_voidWriteData(TFT_RST_PIN,HIGH);
	MSTK_voidStart(12);
	
	/*Sleep out Command*/
	TFT_voidWriteCommand(0x11);

	MSTK_voidStart(150);

	/*Color Mode command*/
	TFT_voidWriteCommand(0x3A);

	/*RGB565*/
	TFT_voidWriteCommand(0x05);

	/*Display Command*/
	TFT_voidWriteCommand(0x29);

}
void TFT_voidDisplayImage(const u16* Copy_ptrImage)
{
	u8 Data = 0;

	/*Set X Address*/
	TFT_voidWriteCommand(0x2A);

	/*Start*/
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);

	/*Stop*/
	TFT_voidWriteData(0);
	TFT_voidWriteData(127);

	/*Set Y Address*/
	TFT_voidWriteCommand(0x2B);

	/*Start */
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);

	/*Stop*/
	TFT_voidWriteData(0);
	TFT_voidWriteData(159);


	/*RAM write command*/
	TFT_voidWriteCommand(0x2C);

	/*Display Image*/
	for(u16 i=0;i<20480;i++)
	{
		Data = Copy_ptrImage[i] >> 8;
		TFT_voidWriteData(Data);
		Data = (u8)Copy_ptrImage[i] & 0x00FF;
		TFT_voidWriteData(Data);
	}

}
static void TFT_voidWriteCommand(u8 Copy_u8Command)
{
	 /*Set pin A0 in TFT to low*/
	MGPIO_voidWriteData(TFT_A0_PIN,LOW);
	/*Send Data over Spi*/
	(void)SPI_u8TrancieveData(Copy_u8Command);
}
static void TFT_voidWriteData(u8 Copy_u8Data)
{
	/*Set pin A0 in TFT to low*/
		MGPIO_voidWriteData(TFT_A0_PIN,HIGH);
		/*Send Data over Spi*/
		(void)SPI_u8TrancieveData(Copy_u8Data);
}
