/*File Guard*/
#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

/******** Registers ********/
#define    TWBR	        *((volatile u8 *)0x20)		/* SCL frequency */
#define    TWCR	        *((volatile u8 *)0x56)		/* Control Register */
#define    TWSR	        *((volatile u8 *)0x21)		/* El3asfora */
#define    TWDR	        *((volatile u8 *)0x23)		/* Data Register */
#define    TWAR	        *((volatile u8 *)0x22)		/* Address Register + BroadCast */

/******** TWCR_Bits ********/
#define		TWCR_TWINT		7		/* Interrupt Flag (Clear - 1) */
#define		TWCR_TWEA		6		/* Enable Acknowledge Bit (Enable - 1) */
#define		TWCR_TWSTA		5		/* START Condition Bit (HI) */
#define		TWCR_TWSTO		4		/* STOP Condition Bit (HI) */
#define		TWCR_TWWC		3		/* Write Collision Flag (Stop - 1) */
#define		TWCR_TWEN		2		/* Enable Bit (Hi)*/
#define		TWCR_TWIE		0		/* Interrupt Enable(Hi) */

/******** TWSR_Bits ********/
#define		TWSR_TWS7		7		/* TWS: TWI Status */
#define		TWSR_TWS6		6		
#define		TWSR_TWS5		5		
#define		TWSR_TWS4		4		
#define		TWSR_TWS3		3		
#define		TWSR_TWPS1		1		/* Prescaler Bits*/
#define		TWSR_TWPS0		0		

/******** TWAR_Bits ********/
#define TWAR_TWA0 1
#define TWAR_TWGCE 0

/******** Macro ********/
#define		TWBR_Value	        2  		/*SCL frequency*/
#define		TWPS	     		0  		/* 1 - 2 - 3 - 4 */
#define		Write				0
#define		Read				1
#define		Slave				0
#define		Master				1
#define		TWSR_MASK			0xF8

/******** TWI_states ********/
#define START_ACK 0x08			/* For Master mode */
#define REP_START_ACK 0x10
#define SLAVE_W_ACK 0x18
#define SLAVE_W_NACK 0x20
#define SLAVE_DATA_ACK 0x28
#define SLAVE_DATA_NACK 0x30
#define SLAVE_R_ACK 0x40
#define SLAVE_R_NACK 0x48
#define MASTER_R_DATA_ACK 0x50
#define MASTER_R_DATA_NACK 0x58
#define SLAVE_ADDRESS_W_ACK 0x60		/* For_Slave_mode */
#define SLAVE_GEN_CALL_ACK 0x70
#define SLAVE_DATA_REC_ACK 0x80
#define SLAVE_DATA_REC_NACK 0x88

#endif
/* TWI_PRIVATE_H_ */
