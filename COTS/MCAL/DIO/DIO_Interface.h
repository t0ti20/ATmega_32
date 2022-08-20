/*File Guard*/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
/*Include*/
#include "../../Library/Macros.h"
#include "../../Library/Standard_Types.h"
#include "../../MCAL/DIO/DIO_Private.h"
/*OPTIONS FOR SINGLE BIN*/
void DIO_VidInternal_Pin_Bull_Up(u8 Copy_u8Port,u8 Copy_u8Pin);							/*INTERNAL PIN PULL UP (Port,Pin) */
void DIO_VidSet_Pin_Direction(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction);		/*SET PIN Direction (Port,Pin,Direction) */
void DIO_VidSet_Pin_Value(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);				/*SET PIN Value (Port,Pin,Value) */
void DIO_VidToggle_Pin_Value(u8 Copy_u8Port,u8 Copy_u8Pin);								/*TOGGLE PIN Value (Port,Pin) */
void DIO_VidGet_Pin_Value(u8 Copy_u8Port,u8 Copy_u8Pin,u8 *Copy_Pu8Pin_Value);			/*Get PIN Value (Port,Pin,Poiner) */
/*OPTIONS FOR SINGLE PORT*/
void DIO_VidInternal_Port_Bull_Up(u8 Copy_u8Port);										/*INTERNAL PORT PULL UP (Port) */
void DIO_VidSet_Whole_Port_Direction(u8 Copy_u8Port,u8 Copy_u8Direction);				/*SET Whole PORT Direction (Port,Direction) */
void DIO_VidSet_Port_Direction(u8 Copy_u8Port,u8 Copy_u8Direction);						/*SET PORT Direction (Port,Value) */
void DIO_VidSet_Port_Value(u8 Copy_u8Port,u8 Copy_u8Value);								/*SET PORT Value (Port,Value) */
void DIO_VidToggle_Port_Value(u8 Copy_u8Port);											/*TOGGLE PORT Value (Port) */
void DIO_VidGet_Port_Value(u8 Copy_u8Port,u8 *Copy_Pu8Port_Value);						/*Get PORT Value (Port,Poiner) */
void DIO_VidEdit_Port_Value(u8 Copy_u8Port,u8 Copy_u8Pins,u8 Copy_u8Value);				/*Edit Port (HI-LOW) Bits */
/*Global Interrupt*/
void DIO_VidGlobal_Interrupt_Enable(void);
#endif
/* DIO_INTERFACE_H_ */
