/*------------------------------- INCLUDE -------------------------------*/
#include <avr/delay.h>
#include "../../Library/Standard_Types.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Seven_Segment_Config.h"
#include "Seven_Segment_Interface.h"
#include "Seven_Segment_Private.h"
/*-------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*/
/*----------------------------- Seven_Segment_Display_One_Digit -----------------------------*/
/*-------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*/
/* Sense Control */
#if Seven_Segment_Type == Common_Anode
	u8 Local_u8Seven_Segment_Array [10] = Seven_Segment_Anode_Array ;
	u8 Local_u8State=HI;
#elif Seven_Segment_Type == Common_Cathode
	u8 Local_u8Seven_Segment_Array [10] = Seven_Segment_Cathode_Array ;
	u8 Local_u8State=LOW;
#endif

/*------------------------------ Seven_Segment_INIT ------------------------------*/
void Seven_Segment_VidInit(u8 Copy_u8Number)
{
	if (Copy_u8Number==TWO)
	{
		DIO_VidSet_Pin_Direction(Seven_Segment_Enable_Port, Seven_Segment_Enable_2_Pin, OUTPUT);
		DIO_VidSet_Pin_Value(Seven_Segment_Enable_Port,Seven_Segment_Enable_2_Pin,Local_u8State);
	}
	DIO_VidSet_Pin_Direction(Seven_Segment_Enable_Port, Seven_Segment_Enable_1_Pin, OUTPUT);
	DIO_VidSet_Pin_Value(Seven_Segment_Enable_Port,Seven_Segment_Enable_1_Pin,Local_u8State);
	DIO_VidSet_Whole_Port_Direction(Seven_Segment_Data_Port, OUTPUT);
	DIO_VidSet_Port_Value(Seven_Segment_Data_Port,Local_u8Seven_Segment_Array[ZERO]);
}
/*------------------------------ Seven_Segment_Display_One_Digit ------------------------------*/

void Seven_Segment_VidSend_One_Digit(u8 Copy_u8Number)
{
	if(Copy_u8Number<10)
	{
		DIO_VidSet_Pin_Value(Seven_Segment_Enable_Port,Seven_Segment_Enable_1_Pin,Local_u8State);
		DIO_VidSet_Port_Value(Seven_Segment_Data_Port,Local_u8Seven_Segment_Array[Copy_u8Number]);
	}
}


/*------------------------------ Seven_Segment_Count ------------------------------*/

void Seven_Segment_VidCount_One_Digit(u8 Copy_u8Max_number,u16 Copy_u8Delay_Ms)
{
	if(Copy_u8Max_number<10)
	{
		u8 Local_u8Counter  = 0;
		DIO_VidSet_Pin_Value(Seven_Segment_Enable_Port,Seven_Segment_Enable_1_Pin,Local_u8State);
		for(Local_u8Counter=0 ; Local_u8Counter<=Copy_u8Max_number ; Local_u8Counter++)
		{
		DIO_VidSet_Port_Value(Seven_Segment_Data_Port,Local_u8Seven_Segment_Array[Local_u8Counter]);
		_delay_ms(Copy_u8Delay_Ms);
		}
	}
}


/*------------------------------ Seven_Segment_INC ------------------------------*/
void Seven_Segment_VidIncrement_One_Digit()
{
	u8 Local_u8Current;
	u8 Local_u8Counter;
	DIO_VidGet_Port_Value(Seven_Segment_Data_Port,&Local_u8Current);
	for(Local_u8Counter=0;Local_u8Counter<10;Local_u8Counter++)
	{
		if(Local_u8Current==Local_u8Seven_Segment_Array[Local_u8Counter])
		{
			break;
		}
	}
	if(Local_u8Counter==9)
		Seven_Segment_VidSend_One_Digit(0);
	else
		Seven_Segment_VidSend_One_Digit(Local_u8Counter+1);
}


/*------------------------------ Seven_Segment_Dec ------------------------------*/
void Seven_Segment_VidDecrement_One_Digit()
{
	u8 Local_u8Current;
	u8 Local_u8Counter;
	DIO_VidGet_Port_Value(Seven_Segment_Data_Port,&Local_u8Current);
	for(Local_u8Counter=0;Local_u8Counter<10;Local_u8Counter++)
	{
		if(Local_u8Current==Local_u8Seven_Segment_Array[Local_u8Counter])
		{
			break;
		}
	}
	if(Local_u8Counter==0)
		Seven_Segment_VidSend_One_Digit(9);
	else
		Seven_Segment_VidSend_One_Digit(Local_u8Counter-1);
}


/*----------------------------- Seven_Segment_Special_Character -----------------------------*/

void Seven_Segment_VidSpecial_One_Digit(u8 Copy_u8Character)
{
	Seven_Segment_VidInit(ONE);
	DIO_VidSet_Pin_Value(Seven_Segment_Enable_Port,Seven_Segment_Enable_1_Pin,Local_u8State);
	DIO_VidSet_Port_Value(Seven_Segment_Data_Port,Copy_u8Character);
}


/*-------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*/
/*----------------------------- Seven_Segment_Display_Two_Digit -----------------------------*/
/*-------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*/


/*------------------------------ Send_Two_Numbers ------------------------------*/
void Seven_Segment_VidSend_Two_Digits(u8 Copy_u8Number)
{
	u8 Local_u8Number_1=Copy_u8Number/TEN;
	u8 Local_u8Number_2=Copy_u8Number%TEN;
	Seven_Segment_VidInit(TWO);
	if(Local_u8Number_1<TEN && Local_u8Number_2<TEN)
	{
		DIO_VidSet_Pin_Value(Seven_Segment_Enable_Port,Seven_Segment_Enable_2_Pin,!Local_u8State);
		DIO_VidSet_Pin_Value(Seven_Segment_Enable_Port,Seven_Segment_Enable_1_Pin,Local_u8State);
		DIO_VidSet_Port_Value(Seven_Segment_Data_Port,Local_u8Seven_Segment_Array[Local_u8Number_1]);
		 _delay_ms(4);
		DIO_VidSet_Pin_Value(Seven_Segment_Enable_Port,Seven_Segment_Enable_1_Pin,!Local_u8State);
		DIO_VidSet_Pin_Value(Seven_Segment_Enable_Port,Seven_Segment_Enable_2_Pin,Local_u8State);
		DIO_VidSet_Port_Value(Seven_Segment_Data_Port,Local_u8Seven_Segment_Array[Local_u8Number_2]);
		_delay_ms(4);
	}
}


/*------------------------------ Send_Two_Numbers ------------------------------*/
void Seven_Segment_VidCount_Two_Digits(u8 Copy_u8Min,u8 Copy_u8Max,u8 Copy_u8Delay)
{
	if(Copy_u8Min<100&&Copy_u8Max<100)
	{
		Seven_Segment_VidInit(TWO);
		for(;Copy_u8Min<=Copy_u8Max;Copy_u8Min++)
		{
			u8 Local_u8Number_1=Copy_u8Min/TEN;
			u8 Local_u8Number_2=Copy_u8Min%TEN;
			u16 Local_u16Counter;
			if(Local_u8Number_1<TEN && Local_u8Number_2<TEN)
			{
				for(Local_u16Counter=0;Local_u16Counter<(Copy_u8Delay/20);Local_u16Counter++)
				{
					DIO_VidSet_Pin_Value(Seven_Segment_Enable_Port,Seven_Segment_Enable_2_Pin,!Local_u8State);
					DIO_VidSet_Pin_Value(Seven_Segment_Enable_Port,Seven_Segment_Enable_1_Pin,Local_u8State);
					DIO_VidSet_Port_Value(Seven_Segment_Data_Port,Local_u8Seven_Segment_Array[Local_u8Number_1]);
					_delay_ms(10);
					DIO_VidSet_Pin_Value(Seven_Segment_Enable_Port,Seven_Segment_Enable_1_Pin,!Local_u8State);
					DIO_VidSet_Pin_Value(Seven_Segment_Enable_Port,Seven_Segment_Enable_2_Pin,Local_u8State);
					DIO_VidSet_Port_Value(Seven_Segment_Data_Port,Local_u8Seven_Segment_Array[Local_u8Number_2]);
					_delay_ms(10);
				}
			}
		}
	}
}


