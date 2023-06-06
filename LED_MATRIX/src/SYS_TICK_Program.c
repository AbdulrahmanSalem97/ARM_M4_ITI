/******************************************************************************/
/***************  Name    :   Abdulrahman Salem  ******************************/
/***************  Date    :   10/5/2023          ******************************/
/**************   Version :   1.0V               ******************************/
/**************   SWC     :   SYSTICK            ******************************/
/******************************************************************************/

/*lib layer*/
#include "BIT_MATH_H_.h"
#include "STD_Types.h"
#include "stm32f401xx.h"

#include "SYS_TICK_Interface.h"
#include "SYSTICK_Private.h"
#include "SYS_TICK_Config.h"

void STK_void_Init(void)
{
	/*Set clk for systick =SYS_TICK_SRC_AHB or SYS_TICK_SRC_AHB_8 and disable timer  */
#if (SYS_CLK_SOURC==SYS_TICK_SRC_AHB)
	{
		STK->CTRL=0x04;
	}
#elif (SYS_CLK_SOURC==SYS_TICK_SRC_AHB_8)
	{
		STK->CTRL=0x00;
	}
#else
    #warning "wrong sys_tick clk souce input"
#endif
}
void STK_void_SetBusyWait(u32 copy_u8Ticks)
{
	/*load Ticks to LOAD REG*/
	STK->LOAD=copy_u8Ticks;
	/*enable timer */
	Set_Bit(STK->CTRL,0);
	/*wait for flag */
	while(!(Get_Bit(STK->CTRL,16)));
	/*Stop timer */
	Clr_Bit(STK->CTRL,0);
	Clr_Bit(STK->CTRL,1);
	/*load =0 ,val =0*/
	STK->LOAD=0;
	STK->VAL=0;


}

