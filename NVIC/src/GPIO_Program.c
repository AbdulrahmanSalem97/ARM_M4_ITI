/******************************************************************************/
/***************  Name    :   Abdulrahman Salem  ******************************/
/***************  Date    :   10/5/2023          ******************************/
/**************   Version :   1.0V               ******************************/
/**************   SWC     :   GPIO               ******************************/
/******************************************************************************/
#include "BIT_MATH_H_.h"
#include "STD_Types.h"
#include "stm32f401xx.h"

#include "RCC_Interface.h"

#include "GPIO_Config.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"


/*
 * copy_u8GPIOX Option :1-GPIOA
 *                      2-GPIOB
 *                      3-GPIOC
 *
 *
 * copy_u8PIN Option :From PIN 0 TO PIN 15
 *
 *
 * copy_Pin_Mode Option:1-INPUT
 *                      2-OUTPUT
 *                      3-ALTERNATE
 *                      4-ANALOG  */
void GPIO_void_SetPinMode(u8 copy_u8GPIOX ,u8 copy_u8PIN, u8 copy_Pin_Mode)
{
	switch(copy_u8GPIOX)
	{
	case (GPIOA_):
			switch(copy_Pin_Mode)
			{
			case (INPUT):     Clr_Bit(GPIOA_REG->MODER,(copy_u8PIN*2));
						      Clr_Bit(GPIOA_REG->MODER,(copy_u8PIN*2+1)); break;
			case (OUTPUT):    Set_Bit(GPIOA_REG->MODER,(copy_u8PIN*2));
			                  Clr_Bit(GPIOA_REG->MODER,(copy_u8PIN*2+1)); break;
			case (ALTERNATE): Clr_Bit(GPIOA_REG->MODER,(copy_u8PIN*2));
							  Set_Bit(GPIOA_REG->MODER,(copy_u8PIN*2+1)); break;
			case(ANALOG):     Set_Bit(GPIOA_REG->MODER,(copy_u8PIN*2));
			                  Set_Bit(GPIOA_REG->MODER,(copy_u8PIN*2+1)); break;
			default:break;
			}
	         break;
	case (GPIOB_):
				switch(copy_Pin_Mode)
				{
				case (INPUT):     Clr_Bit(GPIOB_REG->MODER,(copy_u8PIN*2));
								  Clr_Bit(GPIOB_REG->MODER,(copy_u8PIN*2+1)); break;
				case (OUTPUT):    Set_Bit(GPIOB_REG->MODER,(copy_u8PIN*2));
								  Clr_Bit(GPIOB_REG->MODER,(copy_u8PIN*2+1)); break;
				case (ALTERNATE): Clr_Bit(GPIOB_REG->MODER,(copy_u8PIN*2));
								  Set_Bit(GPIOB_REG->MODER,(copy_u8PIN*2+1)); break;
				case(ANALOG):     Set_Bit(GPIOB_REG->MODER,(copy_u8PIN*2));
								  Set_Bit(GPIOB_REG->MODER,(copy_u8PIN*2+1)); break;
				default:break;
				}
			break;
	case (GPIOC_):
					switch(copy_Pin_Mode)
					{
					case (INPUT):     Clr_Bit(GPIOC_REG->MODER,(copy_u8PIN*2));
									  Clr_Bit(GPIOC_REG->MODER,(copy_u8PIN*2+1)); break;
					case (OUTPUT):    Set_Bit(GPIOC_REG->MODER,(copy_u8PIN*2));
									  Clr_Bit(GPIOC_REG->MODER,(copy_u8PIN*2+1)); break;
					case (ALTERNATE): Clr_Bit(GPIOC_REG->MODER,(copy_u8PIN*2));
									  Set_Bit(GPIOC_REG->MODER,(copy_u8PIN*2+1)); break;
					case(ANALOG):     Set_Bit(GPIOC_REG->MODER,(copy_u8PIN*2));
									  Set_Bit(GPIOC_REG->MODER,(copy_u8PIN*2+1)); break;
					default:break;
					}
				break;

					default:break;

	}
}

/*
 * copy_u8GPIOX Option :1-GPIOA
 *                      2-GPIOB
 *                      3-GPIOC
 *
 *
 * copy_u8PIN Option :From PIN 0 TO PIN 15
 *
 *
 * copy_Pin_Type (OUTPUT PIN) Option:1-PUSH_PULL
 *                                   2-OPEN_DRAIN
 *                       */
void GPIO_void_SetPinType(u8 copy_u8GPIOX ,u8 copy_u8PIN,u8 copy_PinType)
{
	switch(copy_u8GPIOX)
		{
		case (GPIOA_):
					switch(copy_PinType)
					{
					case (PUSH_PULL):     Clr_Bit(GPIOA_REG->OTYPER,(copy_u8PIN)); break;
					case (OPEN_DRAIN):    Set_Bit(GPIOA_REG->OTYPER,(copy_u8PIN)); break;
					default:break;
					}
					 break;
		case (GPIOB_):
					switch(copy_PinType)
					{
					case (PUSH_PULL):     Clr_Bit(GPIOB_REG->OTYPER,(copy_u8PIN)); break;
					case (OPEN_DRAIN):    Set_Bit(GPIOB_REG->OTYPER,(copy_u8PIN)); break;
					default:break;
					}
				    break;
		case (GPIOC_):
					switch(copy_PinType)
					{
					case (PUSH_PULL):     Clr_Bit(GPIOC_REG->OTYPER,(copy_u8PIN)); break;
					case (OPEN_DRAIN):    Set_Bit(GPIOC_REG->OTYPER,(copy_u8PIN)); break;
					default:break;
					}
					break;

		default:    break;

		}

}
/*
 * copy_u8GPIOX Option :1-GPIOA
 *                      2-GPIOB
 *                      3-GPIOC
 *
 *
 * copy_u8PIN Option :From PIN 0 TO PIN 15
 *
 *
 * copy_Pin_Speed (OUTPUT PIN) Option:1-LOW_SPEED
 *                                    2-MEDIUM_SPEED
 *                                    3-HIGH_SPEED
 *                                    4-VERY_HIGH_SPEED
 *                       */
void GPIO_void_SetPinSpeed(u8 copy_u8GPIOX ,u8 copy_u8PIN,u8 copy_PinSpeed )
{
	switch(copy_u8GPIOX)
		{
		case (GPIOA_):
						switch(copy_PinSpeed)
						{
						case (LOW_SPEED):       Clr_Bit(GPIOA_REG->OSPEEDR,(copy_u8PIN*2));
												Clr_Bit(GPIOA_REG->OSPEEDR,(copy_u8PIN*2+1)); break;
						case (MEDIUM_SPEED):    Set_Bit(GPIOA_REG->OSPEEDR,(copy_u8PIN*2));
												Clr_Bit(GPIOA_REG->OSPEEDR,(copy_u8PIN*2+1)); break;
						case (HIGH_SPEED):      Clr_Bit(GPIOA_REG->OSPEEDR,(copy_u8PIN*2));
												Set_Bit(GPIOA_REG->OSPEEDR,(copy_u8PIN*2+1)); break;
						case(VERY_HIGH_SPEED):  Set_Bit(GPIOA_REG->OSPEEDR,(copy_u8PIN*2));
												Set_Bit(GPIOA_REG->OSPEEDR,(copy_u8PIN*2+1)); break;
						default:break;
						}
						 break;
		case (GPIOB_):
						switch(copy_PinSpeed)
						{
						case (LOW_SPEED):       Clr_Bit(GPIOB_REG->OSPEEDR,(copy_u8PIN*2));
												Clr_Bit(GPIOB_REG->OSPEEDR,(copy_u8PIN*2+1)); break;
						case (MEDIUM_SPEED):    Set_Bit(GPIOB_REG->OSPEEDR,(copy_u8PIN*2));
												Clr_Bit(GPIOB_REG->OSPEEDR,(copy_u8PIN*2+1)); break;
						case (HIGH_SPEED):      Clr_Bit(GPIOB_REG->OSPEEDR,(copy_u8PIN*2));
												Set_Bit(GPIOB_REG->OSPEEDR,(copy_u8PIN*2+1)); break;
						case(VERY_HIGH_SPEED):  Set_Bit(GPIOB_REG->OSPEEDR,(copy_u8PIN*2));
												Set_Bit(GPIOB_REG->OSPEEDR,(copy_u8PIN*2+1)); break;
						default:break;
						}
					break;
		case (GPIOC_):
						switch(copy_PinSpeed)
						{
						case (LOW_SPEED):       Clr_Bit(GPIOC_REG->OSPEEDR,(copy_u8PIN*2));
										  	    Clr_Bit(GPIOC_REG->OSPEEDR,(copy_u8PIN*2+1)); break;
						case (MEDIUM_SPEED):    Set_Bit(GPIOC_REG->OSPEEDR,(copy_u8PIN*2));
										  	  	Clr_Bit(GPIOC_REG->OSPEEDR,(copy_u8PIN*2+1)); break;
						case (HIGH_SPEED): 		Clr_Bit(GPIOC_REG->OSPEEDR,(copy_u8PIN*2));
										  	  	Set_Bit(GPIOC_REG->OSPEEDR,(copy_u8PIN*2+1)); break;
						case(VERY_HIGH_SPEED):  Set_Bit(GPIOC_REG->OSPEEDR,(copy_u8PIN*2));
										  	  	Set_Bit(GPIOC_REG->OSPEEDR,(copy_u8PIN*2+1)); break;
						default:break;
						}
					break;

						default:break;
		}


}

/*
 * copy_u8GPIOX Option :1-GPIOA
 *                      2-GPIOB
 *                      3-GPIOC
 *
 *
 * copy_u8PIN Option :From PIN 0 TO PIN 15
 *
 *
 * copy_Value (OUTPUT PIN) Option:    1-HIGH
 *                                    2-LOW
 *
 *                       */
void GPIO_void_SetPinValue(u8 copy_u8GPIOX ,u8 copy_u8PIN,u8 copy_Value)
{
	switch(copy_u8GPIOX)
			{
			case (GPIOA_):
						switch(copy_Value)
						{
						case (LOW):       Clr_Bit(GPIOA_REG->ODR,(copy_u8PIN)); break;
						case (HIGH):      Set_Bit(GPIOA_REG->ODR,(copy_u8PIN)); break;
						default:break;
						}
						 break;
			case (GPIOB_):
						switch(copy_Value)
						{
						case (LOW):       Clr_Bit(GPIOB_REG->ODR,(copy_u8PIN)); break;
						case (HIGH):      Set_Bit(GPIOB_REG->ODR,(copy_u8PIN)); break;
						default:break;
						}
					    break;
			case (GPIOC_):
						switch(copy_Value)
						{
						case (LOW):       Clr_Bit(GPIOC_REG->ODR,(copy_u8PIN)); break;
						case (HIGH):      Set_Bit(GPIOC_REG->ODR,(copy_u8PIN)); break;
						default:break;
						}
						break;

			default:    break;

			}
}
void GPIO_void_SetPortValue(u8 copy_u8GPIOX ,u8 copy_Value)
{
	switch(copy_u8GPIOX)
	{
	case GPIOA_:
			GPIOA_REG->ODR=copy_Value;break;
	case GPIOB_:
			GPIOB_REG->ODR=copy_Value;break;
	case GPIOC_:
			GPIOC_REG->ODR=copy_Value;break;

	}

}


