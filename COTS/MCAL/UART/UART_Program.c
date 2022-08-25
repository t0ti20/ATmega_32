/*------------------------------- INCLUDE -------------------------------*/
#include "UART_Interface.h"
/*------------------------- UART Initialization -------------------------*/
void UART_VidInitialization (u8 Copy_u8Mode,u8 Copy_u8Rx_Interrupt,u8 Copy_u8Tx_Interrupt)
{
	/*----------------------- Select Baud Rate & Speed -----------------------*/
#if	(Baud_Rate == S_9600) && (Speed == Normal_Speed)
	UBRRL= 51;
	Clear_Bit(UCSRA,UCSRA_U2X);
#else
#warning (" Wrong Configuration !!")
#endif
	/*----------------------- Trans-Rec -----------------------*/
	switch(Copy_u8Mode)
	{
		case(Transmit_Recive):Set_Bit(UCSRB,UCSRB_RXEN);Set_Bit(UCSRB,UCSRB_TXEN);break;
		case(Transmit):Clear_Bit(UCSRB,UCSRB_RXEN);Set_Bit(UCSRB,UCSRB_TXEN);break;
		case(Recive):Set_Bit(UCSRB,UCSRB_RXEN);Clear_Bit(UCSRB,UCSRB_TXEN);break;
		default:Clear_Bit(UCSRB,UCSRB_RXEN);Clear_Bit(UCSRB,UCSRB_TXEN);break;
	}
	/*----------------------- Enable Interrupts -----------------------*/
	switch(Copy_u8Rx_Interrupt)							/*(Rx)Interrupt*/
	{
		case (Rx_Enable):Set_Bit(UCSRB,UCSRB_RXCIE);break;
		case (Rx_Disable):Clear_Bit(UCSRB,UCSRB_RXCIE);break;
		default:Clear_Bit(UCSRB,UCSRB_RXCIE);break;
	}
	switch(Copy_u8Tx_Interrupt)							/*(Tx)Interrupt*/
	{
		case (Tx_Enable):Set_Bit(UCSRB,UCSRB_TXCIE);break;
		case (Tx_Disable):Clear_Bit(UCSRB,UCSRB_TXCIE);break;
		default:Clear_Bit(UCSRB,UCSRB_TXCIE);break;
	}
	/*----------------------- Frame Formate -----------------------*/
	/*Parity Mode*/
	Set_Bit(UBRRH,UBRRH_URSEL);
#if	Parity_Mode == Even
	Set_Bit(UCSRC,UCSRC_UPM1);
	Clear_Bit(UCSRC,UCSRC_UPM0);
#elif Parity_Mode == Odd
	Set_Bit(UCSRC,UCSRC_UPM1);
	Set_Bit(UCSRC,UCSRC_UPM0);
#elif Parity_Mode == Disabled
	Clear_Bit(UCSRC,UCSRC_UPM1);
	Clear_Bit(UCSRC,UCSRC_UPM0);
#else
#warning (" Wrong Configuration !!")
#endif
	/*Character Size*/
#if	Character_Size == _8_Bits
	Clear_Bit(UCSRB,UCSRB_UCSZ2);
	Set_Bit(UCSRC,UCSRC_UCSZ1);
	Set_Bit(UCSRC,UCSRC_UCSZ0);
#else
#warning (" Wrong Configuration !!")
#endif
	/*Stop Bits*/
#if	Stop_Bits == Two_StopBits
	Set_Bit(UCSRC,UCSRC_USBS);
#elif Stop_Bits == One_StopBit
	Clear_Bit(UCSRC,UCSRC_USBS);
#else
#warning (" Wrong Configuration !!")
#endif
	/*Clock Polarity*/
#if	Clock_Polarity == Tx_Rising
	Clear_Bit(UCSRC,UCSRC_UCPOL);
#elif Clock_Polarity == Tx_Falling
	Set_Bit(UCSRC,UCSRC_UCPOL);
#else
#warning (" Wrong Configuration !!")
#endif
}
/*------------------------- UART Send -------------------------*/
void UART_VidSend_Receive (u8 Copy_u8Mode,u8 *Copy_u8Data)
{
	if(Copy_u8Mode==Receive)
	{
		/* Wait for empty transmit buffer */
		while(!Get_Bit(UCSRA,UCSRA_RXC));
		/*Write Data Into Data Register*/
		*Copy_u8Data=UDR;
	}
	else if(Copy_u8Mode==Send)
	{
		/* Wait for empty transmit buffer */
		while(!Get_Bit(UCSRA,UCSRA_UDRE));
		/*Write Data Into Data Register*/
		UDR=*Copy_u8Data;
	}
}

