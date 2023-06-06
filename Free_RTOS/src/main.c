#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"

#include "MGPIO_Interface.h"
#include "MRCC_Interface.h"
#include "MGPIO_Private.h"
#include "FreeRTOS.h"
#include "task.h"

#include "semphr.h"

SemaphoreHandle_t Test_Semaphore;

BaseType_t Semaphore_State;

void Task_1(void)
{
	static u8 flag = 0;
	while(1)
	{
		Semaphore_State=xSemaphoreTake(Test_Semaphore,60);
		if(Semaphore_State == pdTRUE)
		{
			if(flag == 0)
			{
				MGPIO_voidSetPinValue(MGPIOA_PORT,MGPIO_PIN0,1);
				flag = 1;
			}
			else
			{
				MGPIO_voidSetPinValue(MGPIOA_PORT,MGPIO_PIN0,0);
				flag = 0;
			}
			xSemaphoreGive(Test_Semaphore);
			vTaskDelay(50);
		}
	}

}
void Task_2(void)
{
	static u8 flag = 0;
	while(1)
	{
		Semaphore_State=xSemaphoreTake(Test_Semaphore,110);
		if(Semaphore_State == pdTRUE)
		{
			if(flag == 0)
			{
				MGPIO_voidSetPinValue(MGPIOA_PORT,MGPIO_PIN1,1);
				flag = 1;
			}
			else
			{
				MGPIO_voidSetPinValue(MGPIOA_PORT,MGPIO_PIN1,0);
				flag = 0;
			}
		}
		xSemaphoreGive(Test_Semaphore);
		vTaskDelay(100);
	}

}
void Task_3(void)
{
	static u8 flag = 0;
	while(1)
	{
		Semaphore_State=xSemaphoreTake(Test_Semaphore,160);
		if(Semaphore_State == pdTRUE)
		{
			if(flag == 0)
			{
				MGPIO_voidSetPinValue(MGPIOA_PORT,MGPIO_PIN2,1);
				flag = 1;
			}
			else
			{
				MGPIO_voidSetPinValue(MGPIOA_PORT,MGPIO_PIN2,0);
				flag = 0;
			}
		}
		xSemaphoreGive(Test_Semaphore);
		vTaskDelay(150);
	}

}
int main()
{

	MRCC_voidInitSystemClk();

	MRCC_voidEnablePeripheralClock(AHB1,0);

	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN0,1);
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN1,1);
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN2,1);

	MGPIO_voidSetOutputType(MGPIOA_PORT,MGPIO_PIN0,MGPIO_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetOutputType(MGPIOA_PORT,MGPIO_PIN1,MGPIO_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetOutputType(MGPIOA_PORT,MGPIO_PIN2,MGPIO_OUTPUT_TYPE_PUSH_PULL);

	vSemaphoreCreateBinary(Test_Semaphore);

	xTaskCreate(Task_1,NULL,50,NULL,1,NULL);
	xTaskCreate(Task_2,NULL,50,NULL,1,NULL);
	xTaskCreate(Task_3,NULL,50,NULL,1,NULL);

	/*Start OS*/
	vTaskStartScheduler();


	while(1)
	{


	}


	return 0;
}
