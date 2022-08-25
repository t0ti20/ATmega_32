/* File Guard */
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
/*------------------------------- INCLUDE -------------------------------*/
#include "../../Library/Macros.h"
#include "../../Library/Standard_Types.h"
#include "UART_Config.h"
#include "UART_Private.h"
/*---------------------------- UART Functions ----------------------------*/
void UART_VidInitialization (u8 Copy_u8Mode,u8 Copy_u8Rx_Interrupt,u8 Copy_u8Tx_Interrupt);
void UART_VidSend_Receive (u8 Copy_u8Mode,u8 *Copy_u8Data);
#endif
/* UART_INTERFACE_H_ */
