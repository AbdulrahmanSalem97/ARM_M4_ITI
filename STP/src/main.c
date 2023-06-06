#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSYSTICK_Interface.h"
#include "STP_Interface.h"

int main()
{
	MRCC_voidInitSystemClk();
	MRCC_voidEnablePeripheralClock(AHB1_BUS,0);
	MSTK_voidInit();

	STP_voidInit();

	while(1)
	{
		for(u8 i=0;i<8;i++)
		{
			STP_voidSendSynch(1<<i);
			MSTK_voidStart(30000);
		}

	}


	return 0;
}
