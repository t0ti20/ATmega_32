/*File Guard*/
#ifndef _SPI_PRIVATE_H_
#define _SPI_PRIVATE_H_

/******** Registers ********/
#define   SPCR      *((volatile u8*)0x2D)
#define   SPSR      *((volatile u8*)0x2E)
#define   SPDR      *((volatile u8*)0x2F) /* SPI Data */

/******** SPCR_Bits ********/       
#define   SPCR_SPIE               7		/* SPI Interrupt Enable */
#define   SPCR_SPE                6		/* SPI Enable */
#define   SPCR_DORD               5		/* Data Order (0-Lift)(1-Right) */
#define   SPCR_MSTR               4		/* Master/Slave Select (0-Slave)(1-Master) */
#define   SPCR_CPOL               3		/* Clock Polarity (0-Rising)(1-Falling) */
#define   SPCR_CPHA               2		/* Clock Phase (Sample-0)(Setup-1)*/
#define   SPCR_SPR1               1		/* Clock Rate Select */
#define   SPCR_SPR0               0		/* Clock Rate Select */

/******** SPSR_Bits ********/
#define   SPSR_SPIF               7		/* SPI Interrupt Flag */
#define   SPSR_WCOL               6		/* Write COLlision Flag */
#define   SPSR_SPI2X              0		/* Double SPI Speed Bit */

/************* Macros for Configure ************/
typedef enum {Master,Slave} SPIMode;
#define   NULL		0
#define   Enable	12
#define   Disable	11
#define   Left		10
#define   Right		9
#define   Rising	8
#define   Falling	7
#define   Setup		6
#define   Sample	5
#define   by_2		4
#define   by_8		3
#define   by_32		2
#define   by_64		1

#endif 
/*_SPI_PRIVATE_H_*/
