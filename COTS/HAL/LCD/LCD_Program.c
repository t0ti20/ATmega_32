/*------------------------------- INCLUDE -------------------------------*/
#include "../../HAL/LCD/LCD_Interface.h"
/*------------------------- Initialization -------------------------*/
void LCD_VidInitialization(void)
{
	DIO_VidSet_Pin_Direction(LCD_CTRL_PORT,LCD_RS_PIN,OUTPUT);
	DIO_VidSet_Pin_Direction(LCD_CTRL_PORT,LCD_RW_PIN,OUTPUT);
	DIO_VidSet_Pin_Direction(LCD_CTRL_PORT,LCD_E_PIN,OUTPUT);
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,LOW);
	/* Mode Control */
#if LCD_Mode == Mode_8
	DIO_VidSet_Whole_Port_Direction(LCD_DATA_PORT,OUTPUT);			/* Port Direction Select */
	_delay_ms(40);													/*DELAY*/
	LCD_VidSend_Command(0x3C);										/*1ST FROM DATA SHEET(Function Set)*/
	LCD_VidSend_Command(0x0C);										/*2ND FROM DATA SHEET(Display On-Off)*/
	LCD_VidSend_Command(HI);
#elif LCD_Mode == Mode_4
	DIO_VidSet_Pin_Direction(LCD_DATA_PORT,Pin_4,OUTPUT);
	DIO_VidSet_Pin_Direction(LCD_DATA_PORT,Pin_5,OUTPUT);
	DIO_VidSet_Pin_Direction(LCD_DATA_PORT,Pin_6,OUTPUT);
	DIO_VidSet_Pin_Direction(LCD_DATA_PORT,Pin_7,OUTPUT);
	_delay_ms(40);
	LCD_VidSend_Command(0X02);
	LCD_VidSend_Command(0X28);
	LCD_VidSend_Command(0X0E);
	LCD_VidSend_Command(0X06);
#else
#warning (" Wrong Configuration !!")
#endif
}

/*------------------------- Send_Command -------------------------*/
void LCD_VidSend_Command(u8 Copy_u8Command)
{
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_RS_PIN,LOW);					/*SET RS PIN AS LOW*/
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_RW_PIN,LOW);					/*SET RW PIN AS LOW TO WRITE*/
#if LCD_Mode == Mode_8
	DIO_VidSet_Port_Value(LCD_DATA_PORT,Copy_u8Command);				/*SEND COMMAND*/
#elif LCD_Mode == Mode_4
	DIO_VidEdit_Port_Value(LCD_DATA_PORT,HI,Copy_u8Command);			/*Send Most 4-Bits*/
	/*Enable*/
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,HI);					/*SET ENABLE PIN*/
	_delay_ms(5);														/*DELAY*/
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,LOW);					/*CLR ENABLE PIN*/
	_delay_ms(50);
	/*Enable*/
	DIO_VidEdit_Port_Value(LCD_DATA_PORT,HI,(Copy_u8Command<<4));			/*Send Least 4-Bits*/
#else
#warning (" Wrong Configuration !!")
#endif
	/*Enable*/
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,HI);					/*SET ENABLE PIN*/
	_delay_ms(5);														/*DELAY*/
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,LOW);					/*CLR ENABLE PIN*/
	_delay_ms(2);
	/*Enable*/
}

/*------------------------- Send_Data -------------------------*/
void LCD_VidSend_Data(u8 Copy_u8Data)
{
	_delay_ms(50);
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_RS_PIN,HI);					/*SET RS PIN AS HI*/
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_RW_PIN,LOW);					/*SET RW PIN AS LOW TO WRITE*/
#if LCD_Mode == Mode_8
	DIO_VidSet_Port_Value(LCD_DATA_PORT,Copy_u8Data);					/*SEND Data*/
#elif LCD_Mode == Mode_4
	DIO_VidEdit_Port_Value(LCD_DATA_PORT,HI,Copy_u8Data);				/*Send Most 4-Bits*/
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,HI);					/*SET ENABLE PIN*/
	_delay_ms(5);
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,LOW);
	_delay_ms(50);
	DIO_VidEdit_Port_Value(LCD_DATA_PORT,HI,(Copy_u8Data<<4));			/*Send Least 4-Bits*/
#else
#warning (" Wrong Configuration !!")
#endif
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,HI);					/*SET ENABLE PIN*/
	_delay_ms(5);
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,LOW);
	_delay_ms(2);
}

/*------------------------- Set_Position -------------------------*/
void LCD_VidSet_Position(u8 Copy_u8x_location,u8 Copy_u8y_location)
{
	LCD_VidSend_Command((128|(((Copy_u8y_location)*0x40)+Copy_u8x_location)));
}

/*------------------------- Special_Character -------------------------*/
void LCD_VidSend_Special_Character(u8 *Copy_u8Pattern,u8 Copy_u8Pattern_Location,u8 Copy_u8x_location,u8 Copy_u8y_location)
{
	LCD_VidSend_Command(64+(8*Copy_u8Pattern_Location));
	for(u8 i=0;i<8;i++)
	{
		LCD_VidSend_Data(Copy_u8Pattern[i]);
	}
	LCD_VidSet_Position(Copy_u8x_location,Copy_u8y_location);
	LCD_VidSend_Data(Copy_u8Pattern_Location);
}

/*------------------------- Send_String -------------------------*/
void LCD_VidSend_String(u8 *Copy_u8String)
{
	u8 Local_u8Counter=0;
	while(((Copy_u8String[Local_u8Counter])!=0)&&Local_u8Counter<16)
	{
		LCD_VidSend_Data(Copy_u8String[Local_u8Counter]);
		Local_u8Counter++;
	}
}

/*------------------------- LCD Clear -------------------------*/
void LCD_VidClear(void)
{
	u8 Local_u8String[16]="                ";
	LCD_VidSet_Position(0,0);
	LCD_VidSend_String(Local_u8String);
	LCD_VidSet_Position(0,1);
	LCD_VidSend_String(Local_u8String);
	LCD_VidSet_Position(0,0);
}


