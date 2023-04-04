#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "Buzzer_interface.h"








void Buzzer_On (void)
{
	M_DIO_void_setPinValue(BUZZER_PIN,DIO_LOW);
}

void Buzzer_Off (void)
{
	M_DIO_void_setPinValue(BUZZER_PIN,DIO_LOW);
}

void Buzzer_Toggle (void)
{
	M_DIO_TogglePin(BUZZER_PIN);
}


