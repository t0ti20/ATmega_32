/*------------------------------- INCLUDE -------------------------------*/
#include "../../Library/Standard_Types.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Stepper_Motor_Interface.h"
#include "Stepper_Motor_Config.h"
#include <avr/delay.h>
/*------------------------- Drive Forward -------------------------*/
/*
void Stepper_VidGo_Forward()
{
	u8 Pin_Array[4]={Stepper_S1_PIN,Stepper_S2_PIN,Stepper_S3_PIN,Stepper_S4_PIN};
	for(s8 i=0;i<4;i++)
	{
		_delay_ms(100);
		DIO_VidSet_Pin_Value(Stepper_CTRL_PORT,Pin_Array[i],HI);
		_delay_ms(100);
		DIO_VidSet_Pin_Value(Stepper_CTRL_PORT,Pin_Array[i],LOW);
	}
}
*/

/*------------------------- Drive Backward -------------------------*/

void Stepper_VidGo_Backward()
{
	u8 Pin_Array[4]={Stepper_S1_PIN,Stepper_S2_PIN,Stepper_S3_PIN,Stepper_S4_PIN};
	for(s8 i=4;i>-1;i--)
	{
		_delay_ms(100);
		DIO_VidSet_Pin_Value(Stepper_CTRL_PORT,Pin_Array[i],HI);
		_delay_ms(100);
		DIO_VidSet_Pin_Value(Stepper_CTRL_PORT,Pin_Array[i],LOW);
	}
}


/*------------------------- Motor Stop -------------------------*/

void Stepper_VidGo_Forward_Micro()
{
	u8 flag=TRUE;
	u8 Pin_Array[4]={Stepper_S1_PIN,Stepper_S2_PIN,Stepper_S3_PIN,Stepper_S4_PIN};
	for(s8 i=0;i<4;i++)
	{
		if(flag)
		{
			_delay_ms(100);
			DIO_VidSet_Pin_Value(Stepper_CTRL_PORT,Pin_Array[i],HI);
			_delay_ms(100);
			flag=flag^1;
		}
		else if(flag)
		{
			DIO_VidSet_Pin_Value(Stepper_CTRL_PORT,Pin_Array[i-1],LOW);
			_delay_ms(100);
			DIO_VidSet_Pin_Value(Stepper_CTRL_PORT,Pin_Array[i],HI);
			_delay_ms(100);
			flag=flag^1;
		}
	}
}

