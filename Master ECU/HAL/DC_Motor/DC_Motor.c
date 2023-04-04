#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "DC_Motor.h"







void H_void_Motor_Start_Cw (void)
{
	M_DIO_void_setPinValue(inc1,DIO_LOW);
	//M_DIO_void_setPinValue(inc2,DIO_HIGH);
}


void H_void_Motor_Stop (void)
{
	M_DIO_void_setPinValue(inc1,DIO_LOW);
	M_DIO_void_setPinValue(inc2,DIO_LOW);
}

void H_void_Motor_Start_CCw (void)
{
	M_DIO_void_setPinValue(inc1,DIO_HIGH);
	//M_DIO_void_setPinValue(inc2,DIO_LOW);
}
