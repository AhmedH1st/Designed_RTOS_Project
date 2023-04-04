#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "SSD_private.h"
#include "SSD_types.h"
#include "SSD_cfg.h"
#include "SSD_interface.h"
#include "Bit_Math.h"
#include "util/delay.h"

void H_SSD_void_displayInNumber (u16 copy_Number)
{
	u8 arr[4]={0};
	u8 i=0,j;

	while ((copy_Number > 0)  &&   ( i < MAX_ARRAY_CAPACITY))
	{
		arr[i++]=copy_Number%10;
		copy_Number/=10;
	}
	//Prepare first number to be displayd

	for (j=0; j<SSD_DISPLAY_TIME; j++)
	{
		for (i=0; i<MAX_ARRAY_CAPACITY; i++)
			{
				M_DIO_void_setPinValue(SSD_A_PIN1,GET_BIT(arr[i],0));
				M_DIO_void_setPinValue(SSD_A_PIN2,GET_BIT(arr[i],1));
				M_DIO_void_setPinValue(SSD_A_PIN3,GET_BIT(arr[i],2));
				M_DIO_void_setPinValue(SSD_A_PIN4,GET_BIT(arr[i],3));

				if(i % 4 == 0)
				{
					M_DIO_void_setPinValue(SSD_DIG1_E,DIO_LOW);
					_delay_ms(1);
					M_DIO_void_setPinValue(SSD_DIG1_E,DIO_HIGH);
				}
				else if(i % 4 == 1)
				{
					M_DIO_void_setPinValue(SSD_DIG2_E,DIO_LOW);
					_delay_ms(1);
					M_DIO_void_setPinValue(SSD_DIG2_E,DIO_HIGH);
				}
				else if(i % 4 == 2)
				{
					M_DIO_void_setPinValue(SSD_DIG3_E,DIO_LOW);
					_delay_ms(1);
					M_DIO_void_setPinValue(SSD_DIG3_E,DIO_HIGH);
				}
				else if(i % 4==3)
				{
					M_DIO_void_setPinValue(SSD_DIG4_E,DIO_LOW);
					_delay_ms(1);
					M_DIO_void_setPinValue(SSD_DIG4_E,DIO_HIGH);
				}
			}
	}
}
