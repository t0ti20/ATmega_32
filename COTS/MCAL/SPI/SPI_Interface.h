/* File Guard */
#ifndef _SPI_INTERFACE_H_
#define _SPI_INTERFACE_H_
/* SPI Include */
#include "../../Library/Macros.h"
#include "../../Library/Standard_Types.h"
#include "../DIO/DIO_Interface.h"
#include "SPI_Config.h"
#include "SPI_Private.h"
/* SPI Functions */
void SPI_VidInitialization (u8 Copy_u8Master_Slave,u8 Copy_u8Interrupt);
void SPI_VidSend_Receive(u8 Copy_u8Data,u8 *Copy_u8Reading);
void SPI_VidInturrept(void(*Copy_VidInturrept)(void));
#endif
/* _SPI_INTERFACE_H_*/
