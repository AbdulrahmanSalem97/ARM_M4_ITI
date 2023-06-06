#include "STD_Types.h"
#include "BIT_MATH_H_.h"
#include "stm32f401xc.h"

#include "EXTI_Config.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"

static void(*EXTI_APF[22])(void)={0};
void EXTI_voidPinIniit(const EXTI_PinConfig_t*copy_pstrPinInit)
{
	u8 Local_u8RegIndex,Local_u8ShiftValue;
	if (copy_pstrPinInit!=NULL)
	{
		Local_u8RegIndex=((copy_pstrPinInit->PinId)/4);
		Local_u8ShiftValue=(((copy_pstrPinInit->PinId)%4)*4);
		/*set AFIO REGS to select the port*/
		/*first clear the 4 bits  */
		SYSCFG->EXTICR[Local_u8RegIndex]&=~(0b1111<<Local_u8ShiftValue);
		SYSCFG->EXTICR[Local_u8RegIndex]|=((copy_pstrPinInit->PortId)<<Local_u8ShiftValue);
		/*select trigger source Falling,Rising,any Logical Change*/
		switch(copy_pstrPinInit->TriggerLevel)
		{
		case EXTI_u8_RISING_EDGE:
			Clr_Bit(EXTI->FTSR,copy_pstrPinInit->PinId);
			Set_Bit(EXTI->RTSR,copy_pstrPinInit->PinId);
			break;
		case EXTI_u8_FALLING_EDGE:
			Set_Bit(EXTI->FTSR,copy_pstrPinInit->PinId);
			Clr_Bit(EXTI->RTSR,copy_pstrPinInit->PinId);
			break;
		case EXTI_u8_ANY_LOGOCAL_CHANGE:
			Set_Bit(EXTI->FTSR,copy_pstrPinInit->PinId);
			Set_Bit(EXTI->RTSR,copy_pstrPinInit->PinId);
			break;


		}
		/*set global pointer to func*/
		EXTI_APF[copy_pstrPinInit->PinId]=copy_pstrPinInit->Pf;

	}
	else
	{

	}

}
void EXTI_voidIntEnable           (u8 copy_u8EXTI_ID)
{
	Set_Bit(EXTI->IMR,copy_u8EXTI_ID);
}
void EXTI_voidIntdisable          (u8 copy_u8EXTI_ID)
{
	Clr_Bit(EXTI->IMR,copy_u8EXTI_ID);
}
void EXTI_voidClearPendingFlag    (u8 copy_u8EXTI_ID)
{
	Set_Bit(EXTI->PR,copy_u8EXTI_ID);
}
void EXTI0_IRQHandler(void)
{
	if (EXTI_APF[0] != NULL)
		{
			EXTI_APF[0]();
			/*flag is not cleard by isr automaticly*/
			Set_Bit(EXTI->PR,0);

		}

}
void EXTI9_5_IRQHandler(void)
{
	 if (EXTI_APF[7] != NULL)
				{
					EXTI_APF[7]();
					/*flag is not cleard by isr automaticly*/
					Set_Bit(EXTI->PR,7);

				}
	if (EXTI_APF[9] != NULL)
		{
			EXTI_APF[9]();
			/*flag is not cleard by isr automaticly*/
			Set_Bit(EXTI->PR,9);

		}


}
void EXTI1_IRQHandler(void)
{
	if (EXTI_APF[1] != NULL)
		{
			EXTI_APF[1]();
			/*flag is not cleard by isr automaticly*/
			Set_Bit(EXTI->PR,0);

		}

}
void EXTI15_10_IRQHandler(void)
{
	 if (EXTI_APF[11] != NULL)
				{
					EXTI_APF[11]();
					/*flag is not cleard by isr automaticly*/
					Set_Bit(EXTI->PR,11);

				}



}

