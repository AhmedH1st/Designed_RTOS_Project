#include "STD_TYPES.h"
#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "GI.h"
#include "Timer0_interface.h"
#include "Tasks.h"

Task_t Task_Handler_Arr[NO_TASKS];

delay_t Delay_arr[NO_TASKS]={{0}};


void RTOS_Init (void)
{
	M_void_Timer0_Init();
	M_void_Timer0_Start(PRESCALER_256);
}

void RTOS_Start(void)
{
	//GI_Enable();
	//M_void_Timer_EnableInt(OV);      //Func Set delay enables them
	//M_void_Timer_EnableInt(OCM);
	M_void_Timer_SetCallBack(Set_OS_Timer,OCM);
	M_void_Timer_setDelayTimeMilliSec(SYSTIK_MS,NORMAL);

}




void RTOS_void_CreateTask (u8 local_priority,u8 local_periodicity, void (local_PtoFunc)(void),u8 local_first_delay,Task_Status_t local_status)
{
	if (local_PtoFunc != NULL)
	{
		if (Task_Handler_Arr[local_priority].TaskHandler == NULL)
		{
			Task_Handler_Arr[local_priority].Periodicity=local_periodicity;
			Task_Handler_Arr[local_priority].TaskHandler=local_PtoFunc;
			Task_Handler_Arr[local_priority].First_Delay=local_first_delay;
			Task_Handler_Arr[local_priority].status=local_status;
		}
	}
}

void RTOS_void_SusbendTask (u8 local_priority)
{
	Task_Handler_Arr[local_priority].status=TASK_SUSPEND;
}

void RTOS_void_SusbendTask_Delay (u8 local_priority, u8 local_desired_delay)
{
	Delay_arr[local_priority].delay = local_desired_delay;
}

void RTOS_void_ResumeTask (u8 local_priority)
{
	Task_Handler_Arr[local_priority].status=TASK_RESUMED;
}

void RTOS_void_DeleteTask (u8 local_priority)
{
	Task_Handler_Arr[local_priority].TaskHandler=NULLPTR;
}


void RTOS_void_Schedular (void)
{
	u8 Task_Num;

	for (Task_Num=0; Task_Num<NO_TASKS; Task_Num++)
	{
		if (Task_Handler_Arr[Task_Num].TaskHandler != NULLPTR)
		{
			if (Task_Handler_Arr[Task_Num].status == TASK_RESUMED)
			{
				if (Task_Handler_Arr[Task_Num].First_Delay != NULL)
				{
					Task_Handler_Arr[Task_Num].First_Delay--;
				}
				/*****So if first delay reaches zero it invokes the task*****/
				if (Task_Handler_Arr[Task_Num].First_Delay == NULL)
				{
					Task_Handler_Arr[Task_Num].First_Delay = Task_Handler_Arr[Task_Num].Periodicity;
					Task_Handler_Arr[Task_Num].TaskHandler();
				}
			}
		}
	}
}



void Delay_Task_Checker (void)
{
	for (u8 i=0; i<NO_TASKS; i++)
	{
		if (Delay_arr[i].delay != NULL)
		{
			Task_Handler_Arr[i].status=TASK_SUSPEND;
			Delay_arr[i].delay--;
		}
		else
		{
			Task_Handler_Arr[i].status=TASK_RESUMED;
		}
	}
}


void Set_OS_Timer (void)
{
	if (delay_func_flag)              //delay function works
	{
		if (count == desired_count)
			{
				delay_func_flag=0;
				M_void_Timer_setDelayTimeMilliSec(SYSTIK_MS,NORMAL);  //set timer again to give give a periodic interrupt after system tick desired
				RTOS_void_Schedular();
			}
	}
}
