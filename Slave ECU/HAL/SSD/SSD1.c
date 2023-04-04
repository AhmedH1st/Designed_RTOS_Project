#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "Bit_Math.h"
#include "Mcu_HW.h"
#include "util/delay.h"


unsigned char leds[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0xff,0x6f};


void SSD1_Disblay (u8 num)
{
	u8 right,left;

	right=num%10;
	left=num/10;


	u8 local_num=leds[num%10];

	/*M_DIO_void_setPinValue(DIO_PC6,DIO_HIGH);

	M_DIO_void_setPinValue(DIO_PA1,GET_BIT(local_num,0));
	M_DIO_void_setPinValue(DIO_PA2,GET_BIT(local_num,1));
	M_DIO_void_setPinValue(DIO_PC3,GET_BIT(local_num,2));
	M_DIO_void_setPinValue(DIO_PC4,GET_BIT(local_num,3));
	M_DIO_void_setPinValue(DIO_PA5,GET_BIT(local_num,4));
	M_DIO_void_setPinValue(DIO_PA6,GET_BIT(local_num,5));
	M_DIO_void_setPinValue(DIO_PA7,GET_BIT(local_num,6));*/
	M_DIO_void_setPinValue(DIO_PC7,DIO_LOW);
	M_DIO_void_setPinValue(DIO_PC6,DIO_HIGH);
	M_Dio_void_setPortValue(DIO_PORTA,((leds[num%10])<<1));

	_delay_ms(10);

	M_DIO_void_setPinValue(DIO_PC6,DIO_LOW);
	M_DIO_void_setPinValue(DIO_PC7,DIO_HIGH);
	M_Dio_void_setPortValue(DIO_PORTA,((leds[num/10])<<1));
	_delay_ms(10);



}
