/*
 * main.c
 *  Created on: July 26, 2022
 *  Author: Khaled_El-Sayed
 */

#define blue	Pin_2
#define F_CPU 16000000L
#include "COTS/Library/Standard_Types.h"
#include "COTS/Library/Macros.h"
#include "COTS/MCAL/DIO/DIO_Interface.h"
#include "COTS/HAL/LCD/LCD_Interface.h"
#include "COTS/HAL/Keypad/Keypad_Interface.h"

void temp (void);
int main(void)
{
	LCD_VidInitialization();
	Keypad_VidInitialization();
	u8 i='0';
	while(TRUE)
	{
		while(1)
		{
			LCD_VidSend_Data(i);
			i=Keypad_u8Get_Pressed_Key_Wait();
		}
	}
}

void temp (void)
{
	DIO_VidToggle_Pin_Value(Port_C, blue);
}
