/*File Guard*/
#ifndef _SPI_PRIVATE_H_
#define _SPI_PRIVATE_H_

/******** Registers ********/
#define   SPCR      *((volatile u8*)0x2D)	/* Control Register */
#define   SPSR      *((volatile u8*)0x2E)	/* Status Register */
#define   SPDR      *((volatile u8*)0x2F) 	/* SPI Data */

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
#define   SPSR_WCOL               6		/* Write Collision Flag */
#define   SPSR_SPI2X              0		/* Double SPI Speed Bit */

/************* Macros for Configure ************/
typedef enum {Master,Slave,SPI_Interrupt_Enable,SPI_Interrupt_Disable} SPIMode;
#define   Pre_Scalar_2				2
#define   Pre_Scalar_4				4
#define   Pre_Scalar_8				8
#define   Pre_Scalar_16				16
#define   Pre_Scalar_32				32
#define   Pre_Scalar_64				64
#define   NULL				0
#define   Left				10
#define   SPI_Send			10
#define   SPI_Receive		10
#define   Right				9
#define   Normal			12
#define   Double			13
#define   Leading_Rising	8
#define   Leading_Falling	7
#define   Leading_Setup		6
#define   Leading_Sample	5
#endif 
/*_SPI_PRIVATE_H_*/
