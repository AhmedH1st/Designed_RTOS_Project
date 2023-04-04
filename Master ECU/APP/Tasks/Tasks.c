#include "STD_TYPES.h"
#include <avr/delay.h>
#include "Mcu_HW.h"
#include "PORT_Interface.h"
#include "ADC_interface.h"
#include "GI.h"
#include "DIO_Interface.h"
#include "UART_interface.h"
#include "Timer0_interface.h"
#include "LCD_interface.h"
#include "LED_interface.h"
#include "Stepper_interface.h"
#include "Servo_interface.h"
#include "DC_Motor.h"
#include "Lm35_interface.h"
#include "Buzzer_interface.h"
#include "SSD1.h"

void LED_Toggle_Task (void)
{
	H_LED_Toggle(LED_RED);
}

void Stepper_Task (void)
{
	static u8 Step_counter;

	if (Step_counter == 0)
	{
		Step_counter++;
		Stepper_Step1();
	}
	else if (Step_counter == 1)
	{
		Step_counter++;
		Stepper_Step2();
	}
	else if (Step_counter == 2)
	{
		Step_counter++;
		Stepper_Step3();
	}
	else if (Step_counter == 3)
	{
		Step_counter=0;
		Stepper_Step4();

	}
}

void Buzzer_Task (void)
{
	Buzzer_Toggle();
}

void Servo_Task (void)
{
	static u16 Angle=0;

	Servo_SetAngle(Angle);
	Angle+=10;
	if (Angle > 360)
	{
		Angle=0;
	}
}

void DC_Task (void)
{
	static u8 Rotation_Flag;
	if (Rotation_Flag == NULL)
	{
		Rotation_Flag=1;
		H_void_Motor_Start_Cw();
	}
	else
	{
		Rotation_Flag=NULL;
		H_void_Motor_Start_CCw();
	}
}

void LCD_Task (void)
{
	static u8 cursor;
	H_LCD_ClearDisplay();
	_delay_ms(1);
	H_LCD_GoTOAddress_UsingLine_Col(LINE_1,cursor);
	H_LCD_Writestr("Ahmed H");
	cursor++;
	if (cursor == 14)
	{
		cursor=NULL;
	}
}

void Temp_Task (void)
{
	static u16 Temp_reading;
	Temp_reading=LM35_GetRead();
	/*H_LCD_ClearDisplay();
	_delay_ms(1);
	H_LCD_GoTOAddress_UsingLine_Col(LINE_2, DIgit_1);
	H_LCD_WriteNum(Temp_reading);*/
}

void SSD_Task (void)
{
	static u8 c;
	SSD1_Disblay(c);
	c++;
	if (c>9)
	{
		c=0;
	}
}


void UART_Task (void)
{
	static s8 c=99;
	M_void_UART__SendWord_Synch((u8)c);
	c--;
	if (c<0)
	{
		c=99;
	}
}




