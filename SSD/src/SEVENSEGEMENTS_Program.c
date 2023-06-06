#include "../LIB/STD_Types.h"
#include "../LIB/BIT_MATH_H_.h"
#include"../MCAL/DIO_Interface.h"
#include"../HAL/SEVENSEGEMENTS_Interface.h"

void SEVENSEGMENTS_voidInit(u8 copy_u8PortId)
{
	DIO_voidSetPortDirection(copy_u8PortId,0xff);
}
void SEVENSEGMENTS_voidGet(u8 copy_u8PortId,u8 copy_u8Number)
{
	u8 arr[]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
	DIO_voidSetPortValue(copy_u8PortId,arr[copy_u8Number]);
}

