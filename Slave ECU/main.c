#include "STD_TYPES.h"
#include "Mcu_HW.h"
#include "PORT_Interface.h"
#include "DIO_Interface.h"
#include "GI.h"
#include "UART_interface.h"
#include "SSD1.h"

u8 num;

void SSD_Func (void)
{
	num=UDR;
}




void main (void){

	Port_Init(PORT_Config_Arr);
	M_void_UART_Init();
	GI_Enable();
	M_void_UART_Receive_Complete_INT_Enable();
	M_void_UART_Receive_INT_SetCallBack(SSD_Func);



	while(1)
	{
		SSD1_Disblay(num);
	}

}
