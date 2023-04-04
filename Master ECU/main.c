#include "STD_TYPES.h"
#include <avr/delay.h>
#include "Mcu_HW.h"
#include "PORT_Interface.h"
#include "ADC_interface.h"
#include "GI.h"
#include "DIO_Interface.h"
#include "Timer0_interface.h"
#include "UART_interface.h"
#include "LCD_interface.h"
#include "LED_interface.h"
#include "Stepper_interface.h"
#include "Servo_interface.h"
#include "DC_Motor.h"
#include "Lm35_interface.h"
#include "Buzzer_interface.h"
#include "SSD1.h"
#include "RTOS_interface.h"
#include "Tasks.h"


void main (void){

	u16 t1,t2,c;

	Port_Init(PORT_Config_Arr);
	H_LCD_Init();
	Servo_Init();
	GI_Enable();
	M_ADC_void_Init();
	M_void_UART_Init();

	M_void_Timer0_Init();
//	M_void_Timer0_Start(PRESCALER_64);



	RTOS_Init();

	RTOS_void_CreateTask(0,13,LCD_Task,13,TASK_RESUMED);
	RTOS_void_CreateTask(1,1,Stepper_Task,1,TASK_RESUMED);
	RTOS_void_CreateTask(2,20,Servo_Task,20,TASK_RESUMED);
	RTOS_void_CreateTask(3,50,Buzzer_Task,50,TASK_RESUMED);
	RTOS_void_CreateTask(4,30,LED_Toggle_Task,30,TASK_RESUMED);
	RTOS_void_CreateTask(5,45,DC_Task,45,TASK_RESUMED);
	RTOS_void_CreateTask(6,100,Temp_Task,100,TASK_RESUMED);
	RTOS_void_CreateTask(7,5,SSD_Task,1,TASK_RESUMED);
	RTOS_void_CreateTask(8,6,UART_Task,6,TASK_RESUMED);

	RTOS_Start();





	/*M_void_Timer0_Start(PRESCALER_64);

	t1=TCNT0;
	UART_Task();
	c=count;
	t2=TCNT0;
H_LCD_GoTOAddress_UsingLine_Col(LINE_2, DIgit_1);
	//H_LCD_ClearDisplay();
	H_LCD_Writestr("t1=");
	H_LCD_WriteNum(t1);
	H_LCD_Writestr(" t2=");
	H_LCD_WriteNum(t2);
	H_LCD_Writestr(" c=");
	H_LCD_WriteNum(c);*/

	while(1)
	{
	}
}

