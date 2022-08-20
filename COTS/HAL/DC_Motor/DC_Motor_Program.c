/*------------------------------- INCLUDE -------------------------------*/
#include "../../Library/Standard_Types.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "DC_Motor_Interface.h"
#include "DC_Motor_Config.h"


/*------------------------- Drive Forward -------------------------*/

void Motor_VidGo_Forward(u8 Copy_u8Motor_Number)
{
	switch(Copy_u8Motor_Number)
	{
		case(Motor_One) : DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_One_D1_PIN,HI);
						  DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_One_D2_PIN,LOW);
						  DIO_VidSet_Pin_Value(Motor_Enable_PORT,Motor_One_E_PIN,HI);break;

		case(Motor_Two) : DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_Two_D1_PIN,HI);
						  DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_Two_D2_PIN,LOW);
						  DIO_VidSet_Pin_Value(Motor_Enable_PORT,Motor_Two_E_PIN,HI);break;

		default			: DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_One_D1_PIN,HI);
						  DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_One_D2_PIN,LOW);
						  DIO_VidSet_Pin_Value(Motor_Enable_PORT,Motor_One_E_PIN,HI);
						  DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_Two_D1_PIN,HI);
						  DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_Two_D2_PIN,LOW);
						  DIO_VidSet_Pin_Value(Motor_Enable_PORT,Motor_Two_E_PIN,HI);break;
	}
}


/*------------------------- Drive Backward -------------------------*/

void Motor_VidGo_Backward(u8 Copy_u8Motor_Number)
{
	switch(Copy_u8Motor_Number)
	{
		case(Motor_One) : DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_One_D1_PIN,LOW);
						  DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_One_D2_PIN,HI);
						  DIO_VidSet_Pin_Value(Motor_Enable_PORT,Motor_One_E_PIN,HI);break;

		case(Motor_Two) : DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_Two_D1_PIN,LOW);
						  DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_Two_D2_PIN,HI);
						  DIO_VidSet_Pin_Value(Motor_Enable_PORT,Motor_Two_E_PIN,HI);break;

		default			: DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_One_D1_PIN,LOW);
						  DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_One_D2_PIN,HI);
						  DIO_VidSet_Pin_Value(Motor_Enable_PORT,Motor_One_E_PIN,HI);
						  DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_Two_D1_PIN,LOW);
						  DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_Two_D2_PIN,HI);
						  DIO_VidSet_Pin_Value(Motor_Enable_PORT,Motor_Two_E_PIN,HI);
	}
}


/*------------------------- Motor Stop -------------------------*/

void Motor_VidStop(u8 Copy_u8Motor_Number)
{
	switch(Copy_u8Motor_Number)
	{
		case(Motor_One) : DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_One_D1_PIN,LOW);
						  DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_One_D2_PIN,LOW);
						  DIO_VidSet_Pin_Value(Motor_Enable_PORT,Motor_One_E_PIN,HI);break;

		case(Motor_Two) : DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_Two_D1_PIN,LOW);
						  DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_Two_D2_PIN,LOW);
						  DIO_VidSet_Pin_Value(Motor_Enable_PORT,Motor_Two_E_PIN,HI);break;

		default			: DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_One_D1_PIN,LOW);
						  DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_One_D2_PIN,LOW);
						  DIO_VidSet_Pin_Value(Motor_Enable_PORT,Motor_One_E_PIN,HI);
						  DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_Two_D1_PIN,LOW);
						  DIO_VidSet_Pin_Value(Motor_CTRL_PORT,Motor_Two_D2_PIN,LOW);
						  DIO_VidSet_Pin_Value(Motor_Enable_PORT,Motor_Two_E_PIN,HI);
	}
}



