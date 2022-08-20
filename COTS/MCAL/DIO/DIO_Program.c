/*------------------------------- INCLUDE -------------------------------*/
#include "DIO_Interface.h"
/*------------------------- OPTIONS FOR SINGLE BIN -------------------------*/
void DIO_VidSet_Pin_Direction(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction)		/*SET PIN Direction*/
{
	if(Copy_u8Direction==INPUT)
	{
		switch(Copy_u8Port)
		{
			case(Port_A):Clear_Bit(DDRA,Copy_u8Pin);break;
			case(Port_B):Clear_Bit(DDRB,Copy_u8Pin);break;
			case(Port_C):Clear_Bit(DDRC,Copy_u8Pin);break;
			case(Port_D):Clear_Bit(DDRD,Copy_u8Pin);break;
		}
	}
	else if(Copy_u8Direction==OUTPUT)
	{
		switch(Copy_u8Port)
		{
			case(Port_A):Set_Bit(DDRA,Copy_u8Pin);break;
			case(Port_B):Set_Bit(DDRB,Copy_u8Pin);break;
			case(Port_C):Set_Bit(DDRC,Copy_u8Pin);break;
			case(Port_D):Set_Bit(DDRD,Copy_u8Pin);break;
		}
	}
}
/*---------------------------------------------------------------------------*/
void DIO_VidInternal_Pin_Bull_Up(u8 Copy_u8Port,u8 Copy_u8Pin)						/*INTERNAL PIN PULL UP*/
{
	switch(Copy_u8Port)//Set As Output
	{
		case(Port_A):Set_Bit(DDRA,Copy_u8Pin);break;
		case(Port_B):Set_Bit(DDRB,Copy_u8Pin);break;
		case(Port_C):Set_Bit(DDRC,Copy_u8Pin);break;
		case(Port_D):Set_Bit(DDRD,Copy_u8Pin);break;
	}
	switch(Copy_u8Port)//Activate Internal Bull Up
	{
		case(Port_A):Set_Bit(PORTA,Copy_u8Pin);break;
		case(Port_B):Set_Bit(PORTB,Copy_u8Pin);break;
		case(Port_C):Set_Bit(PORTC,Copy_u8Pin);break;
		case(Port_D):Set_Bit(PORTD,Copy_u8Pin);break;
	}
}
/*---------------------------------------------------------------------------*/
void DIO_VidSet_Pin_Value(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value)				/*SET PIN Value*/
{
	if(Copy_u8Value==HI)
	{
		switch(Copy_u8Port)
		{
			case(Port_A):Set_Bit(PORTA,Copy_u8Pin);break;
			case(Port_B):Set_Bit(PORTB,Copy_u8Pin);break;
			case(Port_C):Set_Bit(PORTC,Copy_u8Pin);break;
			case(Port_D):Set_Bit(PORTD,Copy_u8Pin);break;
		}
	}
	else if(Copy_u8Value==LOW)
	{
		switch(Copy_u8Port)
		{
			case(Port_A):Clear_Bit(PORTA,Copy_u8Pin);break;
			case(Port_B):Clear_Bit(PORTB,Copy_u8Pin);break;
			case(Port_C):Clear_Bit(PORTC,Copy_u8Pin);break;
			case(Port_D):Clear_Bit(PORTD,Copy_u8Pin);break;
		}
	}
}
/*---------------------------------------------------------------------------*/
void DIO_VidToggle_Pin_Value(u8 Copy_u8Port,u8 Copy_u8Pin)								/*TOGGLE PIN Value*/
{
	switch(Copy_u8Port)
	{
		case(Port_A):Toggle_Bit(PORTA,Copy_u8Pin);break;
		case(Port_B):Toggle_Bit(PORTB,Copy_u8Pin);break;
		case(Port_C):Toggle_Bit(PORTC,Copy_u8Pin);break;
		case(Port_D):Toggle_Bit(PORTD,Copy_u8Pin);break;
	}
}
/*---------------------------------------------------------------------------*/
void DIO_VidGet_Pin_Value(u8 Copy_u8Port,u8 Copy_u8Pin,u8 *Copy_Pu8Pin_Value)			/*Get PIN Value*/
{
	switch(Copy_u8Port)
	{
		case(Port_A):*Copy_Pu8Pin_Value = Get_Bit(PINA,Copy_u8Pin);break;
		case(Port_B):*Copy_Pu8Pin_Value = Get_Bit(PINB,Copy_u8Pin);break;
		case(Port_C):*Copy_Pu8Pin_Value = Get_Bit(PINC,Copy_u8Pin);break;
		case(Port_D):*Copy_Pu8Pin_Value = Get_Bit(PIND,Copy_u8Pin);break;
	}
}
/*---------------------------------------------------------------------------*/
/*------------------------- OPTIONS FOR SINGLE PORT -------------------------*/
/*---------------------------------------------------------------------------*/
void DIO_VidSet_Whole_Port_Direction(u8 Copy_u8Port,u8 Copy_u8Direction)						/*SET PORT Direction*/
{
	if(Copy_u8Direction==INPUT)
	{
		switch(Copy_u8Port)
				{
					case(Port_A):DDRA&=0x00;break;
					case(Port_B):DDRB&=0x00;break;
					case(Port_C):DDRC&=0x00;break;
					case(Port_D):DDRD&=0x00;break;
				}
	}
	else if(Copy_u8Direction==OUTPUT)
	{
		switch(Copy_u8Port)
				{
					case(Port_A):DDRA|=0xff;break;
					case(Port_B):DDRB|=0xff;break;
					case(Port_C):DDRC|=0xff;break;
					case(Port_D):DDRD|=0xff;break;
				}
	}
}
/*---------------------------------------------------------------------------*/
void DIO_VidSet_Port_Direction(u8 Copy_u8Port,u8 Copy_u8Value)
{
	switch(Copy_u8Port)
			{
				case(Port_A):DDRA=Copy_u8Value;break;
				case(Port_B):DDRB=Copy_u8Value;break;
				case(Port_C):DDRC=Copy_u8Value;break;
				case(Port_D):DDRD=Copy_u8Value;break;
			}
}
/*---------------------------------------------------------------------------*/
void DIO_VidInternal_Port_Bull_Up(u8 Copy_u8Port)										/*INTERNAL PORT PULL UP*/
{
	switch(Copy_u8Port)
	{
		case(Port_A):DDRA|=0xff;break;
		case(Port_B):DDRB|=0xff;break;
		case(Port_C):DDRC|=0xff;break;
		case(Port_D):DDRD|=0xff;break;
	}
	switch(Copy_u8Port)
	{
		case(Port_A):PORTA=0xff;break;
		case(Port_B):PORTB=0xff;break;
		case(Port_C):PORTC=0xff;break;
		case(Port_D):PORTD=0xff;break;
	}
}
/*---------------------------------------------------------------------------*/
void DIO_VidSet_Port_Value(u8 Copy_u8Port,u8 Copy_u8Value)								/*SET PORT Value*/
{
		switch(Copy_u8Port)
		{
			case(Port_A):PORTA=Copy_u8Value;break;
			case(Port_B):PORTB=Copy_u8Value;break;
			case(Port_C):PORTC=Copy_u8Value;break;
			case(Port_D):PORTD=Copy_u8Value;break;
		}
}
/*---------------------------------------------------------------------------*/
void DIO_VidEdit_Port_Value(u8 Copy_u8Port,u8 Copy_u8Pins,u8 Copy_u8Value)								/*SET PORT Value*/
{
	if(Copy_u8Pins==HI)
	{
		switch(Copy_u8Port)
		{
			case(Port_A):PORTA&=0x0F;PORTA|=(Copy_u8Value&0xF0);break;
			case(Port_B):PORTB&=0x0F;PORTB|=(Copy_u8Value&0xF0);break;
			case(Port_C):PORTC&=0x0F;PORTC|=(Copy_u8Value&0xF0);break;
			case(Port_D):PORTD&=0x0F;PORTD|=(Copy_u8Value&0xF0);break;
		}
	}
	else if (Copy_u8Pins==LOW)
	{
		switch(Copy_u8Port)
		{
			case(Port_A):PORTA&=0xF0;PORTA|=Copy_u8Value&0X0F;break;
			case(Port_B):PORTB&=0xF0;PORTB|=Copy_u8Value&0X0F;break;
			case(Port_C):PORTC&=0xF0;PORTC|=Copy_u8Value&0X0F;break;
			case(Port_D):PORTD&=0xF0;PORTD|=Copy_u8Value&0X0F;break;
		}
	}
}
/*---------------------------------------------------------------------------*/
void DIO_VidToggle_Port_Value(u8 Copy_u8Port)											/*Toggle PORT Value*/
{
	switch(Copy_u8Port)
	{
		case(Port_A):PORTA^=0xff;break;
		case(Port_B):PORTB^=0xff;break;
		case(Port_C):PORTC^=0xff;break;
		case(Port_D):PORTD^=0xff;break;
	}
}
/*---------------------------------------------------------------------------*/
void DIO_VidGet_Port_Value(u8 Copy_u8Port,u8 *Copy_u8Port_Value)						/*Get PORT Value*/
{
	switch(Copy_u8Port)
	{
		case(Port_A):*Copy_u8Port_Value = PINA;break;
		case(Port_B):*Copy_u8Port_Value = PINB;break;
		case(Port_C):*Copy_u8Port_Value = PINC;break;
		case(Port_D):*Copy_u8Port_Value = PIND;break;
	}
}
void DIO_VidGlobal_Interrupt_Enable(void)
{
	Set_Bit(SREG,SREG_I);
}
