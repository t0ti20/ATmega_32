/*File Guard*/
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
/*Include*/
#include "../../Library/Standard_Types.h"
#include "../../HAL/LCD/LCD_Config.h"
#include "../../HAL/LCD/LCD_Private.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "avr/delay.h"
/*OPTIONS FOR ACCESS LCD*/
void LCD_VidInitialization(void);																										/*Initialize LCD Basic Setting*/
void LCD_VidSend_Command(u8 Copy_u8Command);																							/*SEND COMMAND FOR LCD*/
void LCD_VidSend_Data(u8 Copy_u8Data);																									/*SEND DATA FOR LCD*/
void LCD_VidSet_Position(u8 Copy_u8x_location,u8 Copy_u8y_location);																	/*GO TO EXACT POSITION*/
void LCD_VidSend_String(u8 *Copy_u8String); 																							/*String Display*/
void LCD_VidSend_Special_Character(u8 *Copy_u8Pattern,u8 Copy_u8Pattern_Location,u8 Copy_u8x_location,u8 Copy_u8y_location); 			/*Configure Special Character*/
void LCD_VidClear(void);

/*Some SPECIAL Characters*/

#endif
/* LCD_INTERFACE_H_ */
