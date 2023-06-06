/*
 * RTO_Program.c
 *
 *  Created on: May 24, 2023
 *      Author: Abdulrahman
 */


#define No_Of_Tasks 3

typedef struct
{
	void (*pf)(void);
	u32 First_Delay;
	u32 Periodicity;

}TCB_t;

TCB_t Task_Arr[No_Of_Tasks]={NULL};

static void RTO_Scheduler (void)
{
	u8 Local_u8Count=0;
	for (Local_u8Count=0;Local_u8Count<No_Of_Tasks;Local_u8Count++)
	{
		if(Task_Arr[Local_u8Count].First_Delay==0&&Task_Arr[Local_u8Count].pf!=NULL)
		{
			Task_Arr[Local_u8Count].pf();
			Task_Arr[Local_u8Count].First_Delay=Task_Arr[Local_u8Count].Periodicity -1;
		}
		else
		{
			Task_Arr[Local_u8Count].First_Delay--;
		}
	}
}
void RTO_voidStartOs(void)
{
}
void RTO_voidCreateTask(u8 copy_u8TaskId,u32 copy_u32priodicity ,u32 copy_u32FirstDelay, void (*pf)(void))
{
	if(copy_u8TaskId<No_Of_Tasks)
	{
		Task_Arr[copy_u8TaskId].Periodicity=copy_u32priodicity;
		Task_Arr[copy_u8TaskId].First_Delay=copy_u32FirstDelay;

	}

}
