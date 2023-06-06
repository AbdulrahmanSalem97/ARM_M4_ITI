/******************************************************************************/
/***************  Name    :   Abdulrahman Salem  ******************************/
/***************  Date    :   10/5/2023          ******************************/
/**************   Version :   1.0V               ******************************/
/**************   SWC     :   RCC                ******************************/
/******************************************************************************/

/*lib layer*/
#include "BIT_MATH_H_.h"
#include "STD_Types.h"
#include "stm32f401xx.h"

#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"
u8 RCC_void_EnablePeripheralClock(u8 copy_u8Bus, u8 copy_u8_Peripheral_ID)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	if (copy_u8_Peripheral_ID<32)
	{
		switch (copy_u8Bus)
			{
				case RCC_u8_AHB1_BUS:
					Set_Bit(RCC->AHB1ENR,copy_u8_Peripheral_ID);
					break;
				case RCC_u8_AHB2_BUS:
					Set_Bit(RCC->AHB2ENR,copy_u8_Peripheral_ID);
					break;
				case RCC_u8_APB1_BUS:
					Set_Bit(RCC->APB1ENR,copy_u8_Peripheral_ID);
					break;
				case RCC_u8_APB2_BUS:
					Set_Bit(RCC->APB2ENR,copy_u8_Peripheral_ID);
					break;
				default:
					Local_u8ErrorState=STD_TYPES_NOT_OK;
					break;


			}

	}
	else
	{
		Local_u8ErrorState=STD_TYPES_NOT_OK;

	}



	return Local_u8ErrorState;

}
u8 RCC_void_DisablePeripheralClock(u8 copy_u8Bus, u8 copy_u8_Peripheral_ID)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
		if (copy_u8_Peripheral_ID<32)
		{
			switch (copy_u8Bus)
				{
					case RCC_u8_AHB1_BUS:
						Clr_Bit(RCC->AHB1ENR,copy_u8_Peripheral_ID);
						break;
					case RCC_u8_AHB2_BUS:
						Clr_Bit(RCC->AHB2ENR,copy_u8_Peripheral_ID);
						break;
					case RCC_u8_APB1_BUS:
						Clr_Bit(RCC->APB1ENR,copy_u8_Peripheral_ID);
						break;
					case RCC_u8_APB2_BUS:
						Clr_Bit(RCC->APB2ENR,copy_u8_Peripheral_ID);
						break;
					default:
						Local_u8ErrorState=STD_TYPES_NOT_OK;
						break;
				}

		}
		else
		{
			Local_u8ErrorState=STD_TYPES_NOT_OK;

		}



		return Local_u8ErrorState;


}
void RCC_void_InitSysClock(void)
{
#if RCC_u8_CLC_TYPE==RCC_u8_HSI
    /*enable HSI*/
	Set_Bit(RCC->CR,0);
	/*select HSI*/
	Clr_Bit(RCC->CFGR,0);
	Clr_Bit(RCC->CFGR,1);

#elif RCC_u8_CLC_TYPE==RCC_u8_HSE_OSC
	/*enable HSE*/
	Set_Bit(RCC->CR,16);
	/*select HSE*/
	Set_Bit(RCC->CFGR,0);
	Clr_Bit(RCC->CFGR,1);
#elif RCC_u8_CLC_TYPE==RCC_u8_HSE_BYBASS
	/* enable BYBASS*/
	Set_Bit(RCC->CR,18);
	/*enable HSE*/
	Set_Bit(RCC->CR,16);
	/*select HSE*/
	Set_Bit(RCC->CFGR,0);
	Clr_Bit(RCC->CFGR,1);

#elif RCC_u8_CLC_TYPE==RCC_u8_PLL
	/*enable PLL*/
	Set_Bit(RCC->CR,24);
	/*select PLL*/
	Clr_Bit(RCC->CFGR,0);
	Set_Bit(RCC->CFGR,1);

#else
     #warning "Wrong Choice"

#endif

}
