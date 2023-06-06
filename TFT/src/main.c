#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#include "SPI_Interface.h"
#include "MSYSTICK_Interface.h"
#include "MGPIO_interface.h"
#include "TFT_Interface.h"
#include "MRCC_interface.h"
#include "Image.h"
int main()
{
	MRCC_voidInitSystemClk();

	MRCC_voidEnablePeripheralClock(AHB1,0);

	MRCC_voidEnablePeripheralClock(APB2,12U);

	for(u8 i=0;i<3;i++)
	{
		MGPIO_voidSetPinMode(_GPIOA_PORT,i,_MODE_OUTPUT);
		MGPIO_voidSetPinOutSpeed(_GPIOA_PORT,i,_OUTPUT_SPEED_MEDUIM);
		MGPIO_voidSetPinOutPutType(_GPIOA_PORT,i,_OUTPUT_TYPE_PUSH_PULL);
	}

	MGPIO_voidSetPinMode(_GPIOA_PORT,_PIN_5,_MODE_ALTF);
	MGPIO_voidSetPinMode(_GPIOA_PORT,_PIN_7,_MODE_ALTF);

	MGPIO_voidSetPinAltFn(_GPIOA_PORT,_PIN_5,_ALTFN_5);
	MGPIO_voidSetPinAltFn(_GPIOA_PORT,_PIN_7,_ALTFN_5);

	SPI_voiInit();

	TFT_voidInit();

	TFT_voidDisplayImage(image_arr);

	while(1)
	{

	}

	return 0;
}
