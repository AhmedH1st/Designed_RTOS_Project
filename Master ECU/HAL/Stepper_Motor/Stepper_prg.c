#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include <avr/delay.h>
#include "Stepper_interface.h"
#include "Stepper_private.h"





void Stepper_UniPoler_Step_CW (void)
{
	M_DIO_void_setPinValue(COIL_1A, DIO_HIGH);
	M_DIO_void_setPinValue(COIL_1B, DIO_LOW);
	M_DIO_void_setPinValue(COIL_2A, DIO_LOW);
	M_DIO_void_setPinValue(COIL_2B, DIO_LOW);
	_delay_ms(2);
	M_DIO_void_setPinValue(COIL_1A, DIO_LOW);
	M_DIO_void_setPinValue(COIL_1B, DIO_HIGH);
	M_DIO_void_setPinValue(COIL_2A, DIO_LOW);
	M_DIO_void_setPinValue(COIL_2B, DIO_LOW);
	_delay_ms(2);

	M_DIO_void_setPinValue(COIL_1A, DIO_LOW);
	M_DIO_void_setPinValue(COIL_1B, DIO_LOW);
	M_DIO_void_setPinValue(COIL_2A, DIO_HIGH);
	M_DIO_void_setPinValue(COIL_2B, DIO_LOW);
	_delay_ms(2);

	M_DIO_void_setPinValue(COIL_1A, DIO_LOW);
	M_DIO_void_setPinValue(COIL_1B, DIO_LOW);
	M_DIO_void_setPinValue(COIL_2A, DIO_LOW);
	M_DIO_void_setPinValue(COIL_2B, DIO_HIGH);
	_delay_ms(1);
}

void Stepper_Step1(void)
{
	M_DIO_void_setPinValue(COIL_1A, DIO_HIGH);
	M_DIO_void_setPinValue(COIL_1B, DIO_LOW);
	M_DIO_void_setPinValue(COIL_2A, DIO_LOW);
	M_DIO_void_setPinValue(COIL_2B, DIO_LOW);
}
void Stepper_Step2(void)
{
	M_DIO_void_setPinValue(COIL_1A, DIO_LOW);
	M_DIO_void_setPinValue(COIL_1B, DIO_HIGH);
	M_DIO_void_setPinValue(COIL_2A, DIO_LOW);
	M_DIO_void_setPinValue(COIL_2B, DIO_LOW);
}
void Stepper_Step3(void)
{
	M_DIO_void_setPinValue(COIL_1A, DIO_LOW);
	M_DIO_void_setPinValue(COIL_1B, DIO_LOW);
	M_DIO_void_setPinValue(COIL_2A, DIO_HIGH);
	M_DIO_void_setPinValue(COIL_2B, DIO_LOW);
}
void Stepper_Step4(void)
{
	M_DIO_void_setPinValue(COIL_1A, DIO_LOW);
	M_DIO_void_setPinValue(COIL_1B, DIO_LOW);
	M_DIO_void_setPinValue(COIL_2A, DIO_LOW);
	M_DIO_void_setPinValue(COIL_2B, DIO_HIGH);
}



