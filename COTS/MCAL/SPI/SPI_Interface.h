/* File Guard */
#ifndef _SPI_INTERFACE_H_
#define _SPI_INTERFACE_H_
/* SPI Functions */
void SPI_VidInitialization (u8 Copy_u8Master_Slave);
void SPI_VidSend_Receive(u8 Copy_u8Data,u8 *Copy_u8Reading);
void SPI_VidInturrept(void(*Copy_VidInturrept)(void));
#endif
/* _SPI_INTERFACE_H_*/
