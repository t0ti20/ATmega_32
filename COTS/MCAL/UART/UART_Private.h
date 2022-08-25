/*File Guard*/
#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/******** Registers ********/
#define    UDR			*((volatile u8 *)0x2C)		/* Data (Send-Recieve) Register */
#define    UCSRA		*((volatile u8 *)0x2B)		/* Control and Status Register */
#define    UCSRB		*((volatile u8 *)0x2A)		/* Control and Status Register */
#define    UBRRL		*((volatile u8 *)0x29)		/* Baud Rate Registers */
#define    UCSRC		*((volatile u8 *)0x40)		/* Control and Status Register */
#define    UBRRH		*((volatile u8 *)0x40)		/* Baud Rate Registers */

/******** UCSRA_Bits ********/
#define		UCSRA_RXC		7		/* Flag Receive Complete */
#define		UCSRA_TXC		6		/* Flag Transmit Complete */
#define		UCSRA_UDRE		5		/* Flag Data Register Empty */
#define		UCSRA_FE		4		/* Flag Frame Error */
#define		UCSRA_DOR		3		/* Flag Data OverRun */
#define		UCSRA_PE		2		/* Flag Parity Error */
#define		UCSRA_U2X		1		/* Double Speed*/
#define		UCSRA_MPCM		0		/* Multi-processor Communication  */

/******** UCSRB_Bits ********/
#define		UCSRB_RXCIE		7		/* RX Complete Interrupt Enable */
#define		UCSRB_TXCIE		6		/* TX Complete Interrupt Enable */
#define		UCSRB_UDRIE		5		/* Data Register Empty Interrupt Enable */
#define		UCSRB_RXEN		4		/* Receiver Enable */
#define		UCSRB_TXEN		3		/* Transmitter Enable */
#define		UCSRB_UCSZ2		2		/* Character Size */
#define		UCSRB_RXB8		1		/* Receive Data Bit 8 */
#define		UCSRB_TXB8		0		/* Transmit Data Bit 8 */

/******** UCSRC_Bits ********/
#define		UCSRC_URSEL		7		/* Register Select */
#define		UCSRC_UMSEL		6		/* Mode Select */
#define		UCSRC_UPM1		5		/* Parity Mode */
#define		UCSRC_UPM0		4		/* Parity Mode */
#define		UCSRC_USBS		3		/* Stop Bit Select */
#define		UCSRC_UCSZ1		2		/* Character Size */
#define		UCSRC_UCSZ0		1		/* Character Size*/
#define		UCSRC_UCPOL		0		/* Clock Polarity */

/******** UBRRH_Bits ********/
#define		UBRRH_URSEL		7		/* Register Select (UCSRC-UBRRH) */

/******** Macros for Configure ********/
typedef enum {Transmit_Recive,Transmit,Recive,Stop,Tx_Enable,Tx_Disable,Rx_Enable,Rx_Disable}UART_Mode;
typedef enum {S_9600}UART_BaudRate;
typedef enum {Normal_Speed,Double_Speed,Send,Receive}UART_Configure;

/******** Macro ********/
#define		S_9600UBRR			0x33
#define		Even				0
#define		Odd					1
#define		Disabled			2
#define		_8_Bits				8
#define		One_StopBit			1
#define		Two_StopBits		1
#define		Tx_Rising			1
#define		Tx_Falling			1
#endif
/* UART_PRIVATE_H_ */
