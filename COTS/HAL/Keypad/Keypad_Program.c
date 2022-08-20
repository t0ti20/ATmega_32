/*------------------------------- INCLUDE -------------------------------*/
#include "../../HAL/Keypad/Keypad_Interface.h"
/*----------------------------- Get_The_Key -----------------------------*/
u8 Keypad_u8Get_Pressed_Key()
{
/*******Initialization Of Some Local Important Variables*******/
	u8 Local_u8Key_Pressd = Not_Pressed ;				                                                                   /*Initial Value For The Key*/
	u8 Local_u8Keypad_Array [4][4] =  Keypad_Array ;	                                                                   /*Set Keypad Array*/
	u8 Local_u8Column = ZERO ;							                                                                   /*Counter For Columns*/
	u8 Local_u8Row = ZERO ;								                                                                   /*Counter For ROWs*/
	u8 Local_u8Key_State = HI ;							  															   	   /*Key State Variable*/
	u8 Local_u8Column_Array [] = {KeyPad_u8Column_0_PIN,KeyPad_u8Column_1_PIN,KeyPad_u8Column_2_PIN,KeyPad_u8Column_3_PIN};/* Rows Array For Ease Access*/
	u8 Local_u8Row_Array [] = {KeyPad_u8Row_0_PIN,KeyPad_u8Row_1_PIN,KeyPad_u8Row_2_PIN,KeyPad_u8Row_3_PIN};			   /* Column Array For Ease Access*/
/*******The Main Code*******/
	for(Local_u8Column = ZERO;Local_u8Column<4;Local_u8Column++)
	{
		DIO_VidSet_Pin_Value(Keypad_Port,Local_u8Column_Array[Local_u8Column],LOW);
		for(Local_u8Row = ZERO;Local_u8Row<4;Local_u8Row++)
		{
			DIO_VidGet_Pin_Value(Keypad_Port,Local_u8Row_Array [Local_u8Row],&Local_u8Key_State);
			if(Local_u8Key_State==LOW)
			{
				Local_u8Key_Pressd=Local_u8Keypad_Array[Local_u8Row][Local_u8Column];
				while (Local_u8Key_State == LOW )
				{
					DIO_VidGet_Pin_Value(Keypad_Port,Local_u8Row_Array [Local_u8Row],&Local_u8Key_State);
				}
				DIO_VidSet_Pin_Value(Keypad_Port,Local_u8Column_Array[Local_u8Column],HI);
				return Local_u8Key_Pressd;
			}
		}
		DIO_VidSet_Pin_Value(Keypad_Port,Local_u8Column_Array[Local_u8Column],HI);
	}
	return Local_u8Key_Pressd;
}
/*----------------------------- Get And Wait -----------------------------*/
u8 Keypad_u8Get_Pressed_Key_Wait()
{
/*******Initialization Of Some Local Important Variables*******/
	u8 Local_u8Key_Pressd = Not_Pressed ;				                                                                   /*Initial Value For The Key*/
	u8 Local_u8Keypad_Array [4][4] =  Keypad_Array ;	                                                                   /*Set Keypad Array*/
	u8 Local_u8Column = ZERO ;							                                                                   /*Counter For Columns*/
	u8 Local_u8Row = ZERO ;								                                                                   /*Counter For ROWs*/
	u8 Local_u8Key_State = HI ;							  															   	   /*Key State Variable*/
	u8 Local_u8Column_Array [] = {KeyPad_u8Column_0_PIN,KeyPad_u8Column_1_PIN,KeyPad_u8Column_2_PIN,KeyPad_u8Column_3_PIN};/* Rows Array For Ease Access*/
	u8 Local_u8Row_Array [] = {KeyPad_u8Row_0_PIN,KeyPad_u8Row_1_PIN,KeyPad_u8Row_2_PIN,KeyPad_u8Row_3_PIN};			   /* Column Array For Ease Access*/
/*******The Main Code*******/
	do
	{
		for(Local_u8Column = ZERO;Local_u8Column<4;Local_u8Column++)
		{
			DIO_VidSet_Pin_Value(Keypad_Port,Local_u8Column_Array[Local_u8Column],LOW);
			for(Local_u8Row = ZERO;Local_u8Row<4;Local_u8Row++)
			{
				DIO_VidGet_Pin_Value(Keypad_Port,Local_u8Row_Array [Local_u8Row],&Local_u8Key_State);
				if(Local_u8Key_State==LOW)
				{
					Local_u8Key_Pressd=Local_u8Keypad_Array[Local_u8Row][Local_u8Column];
					while (Local_u8Key_State == LOW )
					{
						DIO_VidGet_Pin_Value(Keypad_Port,Local_u8Row_Array [Local_u8Row],&Local_u8Key_State);
					}
					DIO_VidSet_Pin_Value(Keypad_Port,Local_u8Column_Array[Local_u8Column],HI);
					return Local_u8Key_Pressd;
				}
			}
			DIO_VidSet_Pin_Value(Keypad_Port,Local_u8Column_Array[Local_u8Column],HI);
		}
	}while(TRUE);
}
/*----------------------------- Port Initialization  -----------------------------*/
void Keypad_VidInitialization(void)
{
	DIO_VidSet_Port_Direction(Keypad_Port,0X0F);
	DIO_VidInternal_Pin_Bull_Up(Keypad_Port,Pin_4);
	DIO_VidInternal_Pin_Bull_Up(Keypad_Port,Pin_5);
	DIO_VidInternal_Pin_Bull_Up(Keypad_Port,Pin_6);
	DIO_VidInternal_Pin_Bull_Up(Keypad_Port,Pin_7);
}
