/****************************************************************************/
/***************  Name    :   Abdulrahman Salem *****************************/
/***************  Date    :   10/5/2023         *****************************/
/**************   Version :   1.0V              *****************************/
/**************   SWC     :   GPIO              *****************************/
/****************************************************************************/


#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


void GPIO_void_SetPinMode(u8 copy_u8GPIOX ,u8 copy_u8PIN, u8 copy_Pin_Mode);
void GPIO_void_SetPinType(u8 copy_u8GPIOX ,u8 copy_u8PIN,u8 copy_PinType);
void GPIO_void_SetPinSpeed(u8 copy_u8GPIOX ,u8 copy_u8PIN,u8 copy_PinSpeed );
void GPIO_void_SetPinValue(u8 copy_u8GPIOX ,u8 copy_u8PIN,u8 copy_Value);
void GPIO_void_SetPortValue(u8 copy_u8GPIOX ,u8 copy_Value);




#endif
