/* File Guard */
#ifndef _EXTERNAL_INTERRUPT_INTERFACE_H_
#define _EXTERNAL_INTERRUPT_INTERFACE_H_
/*Include*/
#include  "../../Library/Macros.h"
#include  "../../Library/Standard_Types.h"
#include "External_Interrupt_Private.h"
#include "External_Interrupt_Interface.h"
/*External Interrupt Enable */
void External_Interrupt_VidInitialization (u8 Copy_u8Interrupt,u8 Copy_u8Mode);
void External_Interrupt_0(void(*Copy_VidInturrept)(void));
void External_Interrupt_1(void(*Copy_VidInturrept)(void));
void External_Interrupt_2(void(*Copy_VidInturrept)(void));
#endif
/* _EXTERNAL_INTERRUPT_INTERFACE_H_*/
