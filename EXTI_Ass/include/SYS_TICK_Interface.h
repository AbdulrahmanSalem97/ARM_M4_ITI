/*****************************************************************************/
/***************  Name    :   Abdulrahman Salem ******************************/
/***************  Date    :   10/5/2023         ******************************/
/**************   Version :   1.0V              ******************************/
/**************   SWC     :   SYSTICK           ******************************/
/*****************************************************************************/



#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

void STK_void_Init(void);
void STK_void_SetBusyWait(u32 copy_u8Ticks);
u8 STK_u8_SetIntervalSingle(u32 copy_u8Ticks,void(*copy_pf)(void));
u8 STK_u8_SetIntervalPeriodic(u32 copy_u8Ticks,void(*copy_pf)(void));
void STK_void_StopTimer(void);
u8 STK_u8_GetElapsedTime(u32 *copy_u32ElapsedTime);
u8 STK_u8_GetRemainingTime(u32 *copy_u32RemainingTime);



#endif
