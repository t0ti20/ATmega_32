/*
 * main.c
 *  Created on: July 26, 2022
 *  Author: Khaled_El-Sayed
*/
#include "COTS/Library/Standard_Types.h"
#include "COTS/Library/Macros.h"
#include "COTS/MCAL/DIO/DIO_Interface.h"
#include "COTS/HAL/LCD/LCD_Interface.h"
#include "COTS/MCAL/UART/UART_Interface.h"

int main(void)
{
	u8 num=0;
	DIO_VidSet_Whole_Port_Direction(Port_C, OUTPUT);
	UART_VidInitialization(Transmit_Recive,Rx_Disable,Tx_Disable);
	while(TRUE)
	{
		num=0;
		UART_VidRead_Data(&num);
		UART_VidSend_Data(num);
		if (num=='1')DIO_VidSet_Port_Value(Port_C, 0xff);
		else if (num=='0')DIO_VidSet_Port_Value(Port_C, 0);
		else if (num)DIO_VidToggle_Port_Value(Port_C);
	}
}
