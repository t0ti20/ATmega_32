/* File Guard */
#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_
/* Include */
#include  "../../Library/Macros.h"
#include  "../../Library/Standard_Types.h"
#include "../../MCAL/ADC/ADC_Config.h"
#include "../../MCAL/ADC/ADC_Private.h"
/*ADC Functions*/
void ADC_VidInitialization (void);
void ADC_VidAsync_Reading (u8 Copy_u8Channel,u16 *Copy_u16Reading);
void ADC_VidSync_Reading (u8 Copy_u8Channel,u8 *Copy_u8Reading);
void ADC_VidAsync_Mapped_Reading (u8 Copy_u8Channel,u32 Copy_u32Min,u32 Copy_u32Max,u32 *Copy_u32Reading);
#endif
/* _EXTERNAL_INTERFACE_H_*/
