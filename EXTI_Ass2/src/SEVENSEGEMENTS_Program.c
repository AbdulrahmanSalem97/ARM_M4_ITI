#include "BIT_MATH_H_.h"
#include "STD_Types.h"
#include "GPIO_Config.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "SEVENSEGEMENTS_Interface.h"

void SEVENSEGMENTS_voidInit(u8 copy_u8PortId)
{
	GPIO_void_SetPinMode(copy_u8PortId,PIN0,OUTPUT);
	GPIO_void_SetPinMode(copy_u8PortId,PIN1,OUTPUT);
	GPIO_void_SetPinMode(copy_u8PortId,PIN2,OUTPUT);
	GPIO_void_SetPinMode(copy_u8PortId,PIN3,OUTPUT);
	GPIO_void_SetPinMode(copy_u8PortId,PIN4,OUTPUT);
	GPIO_void_SetPinMode(copy_u8PortId,PIN5,OUTPUT);
	GPIO_void_SetPinMode(copy_u8PortId,PIN6,OUTPUT);
	GPIO_void_SetPinType(copy_u8PortId,PIN0,PUSH_PULL);
	GPIO_void_SetPinType(copy_u8PortId,PIN1,PUSH_PULL);
	GPIO_void_SetPinType(copy_u8PortId,PIN2,PUSH_PULL);
	GPIO_void_SetPinType(copy_u8PortId,PIN3,PUSH_PULL);
	GPIO_void_SetPinType(copy_u8PortId,PIN4,PUSH_PULL);
	GPIO_void_SetPinType(copy_u8PortId,PIN5,PUSH_PULL);
	GPIO_void_SetPinType(copy_u8PortId,PIN6,PUSH_PULL);
}
void SEVENSEGMENTS_voidGet(u8 copy_u8PortId,u8 copy_u8Number)
{
	u8 arr[]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

	GPIO_void_SetPortValue(copy_u8PortId ,arr[copy_u8Number]);
}

