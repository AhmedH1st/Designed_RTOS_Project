#include "STD_TYPES.h";
#include "Timer1_interface.h"
#include "Servo_interface.h"









void Servo_Init (void)
{
	M_void_Timer1_Init();
}


void Servo_SetAngle (u16 angle)
{
	u32 local_val;

	local_val=(((u32)angle * 1000)/180)+499;
	local_val*=2;

	M_void_Timer1_FastPWM_OCR_Direct_input(OCR_1A,(u16)local_val);
}
