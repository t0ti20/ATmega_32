/* File Guard */
#ifndef _TIMER_INTERFACE_H_
#define _TIMER_INTERFACE_H_
/* Include */
#include "../../Library/Macros.h"
#include "../../Library/Standard_Types.h"
#include "../../MCAL/Timer/Timer_Config.h"
#include "../../MCAL/Timer/Timer_Private.h"
/* Global Variables */
u32 Global_Timer_0_u16Flag;
u32 Global_Timer_2_u16Flag;
/************************************************/
/*					Timer 0 					*/
/************************************************/
void Timer_0_VidInitialization(u8 Copy_u8Mode,u8 Copy_u8OCR_Value,u8 Copy_u8Compare_Match_Interrupt,u8 Copy_u8Over_Flow_Interrupt,u8 Copy_u8Pre_Scalar);
void Timer_0_VidBusy_Wait_ms(u32 Copy_u32Delay);
void Timer_0_VidDelay_ms(u32 Copy_u32Delay,void (*Copy_VidDelay_Func)(void));
void Timer_0_VidCompare_Match_Inturrept(void(*Copy_VidInturrept)(void));
void Timer_0_VidOverflow_Inturrept(void(*Copy_VidInturrept)(void));
/************************************************/
/*					Timer 2 					*/
/************************************************/
void Timer_2_VidInitialization(u8 Copy_u8Mode,u8 Copy_u8OCR_Value,u8 Copy_u8Compare_Match_Interrupt,u8 Copy_u8Over_Flow_Interrupt,u8 Copy_u8Pre_Scalar);
void Timer_2_VidBusy_Wait_ms(u32 Copy_u32Delay);
void Timer_2_VidDelay_ms(u32 Copy_u32Delay,void (*Copy_VidDelay_Func)(void));
void Timer_2_VidCompare_Match_Inturrept(void(*Copy_VidInturrept)(void));
void Timer_2_VidOverflow_Inturrept(void(*Copy_VidInturrept)(void));
/************************************************/
/*					General 					*/
/************************************************/
void Timer_VidPwm_Duty_Cycle(u8 Copy_u8Timer,u8 Copy_u8Duty_Cycle);
#endif
/*_TIMER_INTERFACE_H_*/
