#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#include "MGPIO_interface.h"
#include "MSYSTICK_Interface.h"



#include"STP_Config.h"
#include"STP_Private.h"
#include"STP_Interface.h"


void STP_voidInit()
{
	MGPIO_voidSetPinMode(_GPIOA_PORT , _PIN_0 , _MODE_OUTPUT);
	MGPIO_voidSetPinMode(_GPIOA_PORT , _PIN_1 , _MODE_OUTPUT);
	MGPIO_voidSetPinMode(_GPIOA_PORT , _PIN_2 , _MODE_OUTPUT);
	
	
}
void STP_voidSendSynch(u8 Copy_u8Data)
{
	s8 Local_counter;
	u8 Local_Bit;
	for(Local_counter = 7 ; Local_counter >=0 ; Local_counter--)
	{
		Local_Bit = GET_BIT(Copy_u8Data , Local_counter);
		MGPIO_voidWriteData(_GPIOA_PORT , _PIN_0 , Local_Bit);
		
		/*Send Pulse to shift Clock*/
		MGPIO_voidWriteData(_GPIOA_PORT , _PIN_1 , HIGH);
		MSTK_voidStart(1);
		MGPIO_voidWriteData(_GPIOA_PORT , _PIN_1 , LOW);
		MSTK_voidStart(1);
	}
	
	MGPIO_voidWriteData(_GPIOA_PORT , _PIN_2 , HIGH);
	MSTK_voidStart(1);
	MGPIO_voidWriteData(_GPIOA_PORT , _PIN_2 , LOW);
	MSTK_voidStart(1);

	
}

	
