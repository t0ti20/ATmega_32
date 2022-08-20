/*File Guard*/
#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_
/*Include*/
#include "../../Library/Standard_Types.h"
#include "../../HAL/Keypad/Keypad_Config.h"
#include "../../HAL/Keypad/Keypad_Private.h"
#include "../../MCAL/DIO/DIO_Interface.h"
/*OPTIONS Getting Character*/
void Keypad_VidInitialization(void);					 /*Port Initializaiion*/
u8 Keypad_u8Get_Pressed_Key();		   					 /*Check And Get Character (Without Waiting)*/
u8 Keypad_u8Get_Pressed_Key_Wait();     				 /*Check And Get Character (With Waiting)*/
#endif
/* KEYPAD_PRIVATE_H_ */
