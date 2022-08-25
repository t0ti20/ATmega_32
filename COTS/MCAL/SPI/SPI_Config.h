/* File Guard */
#ifndef _SPI_CONFIG_H_
#define _SPI_CONFIG_H_

/************* SPI Configurations ************/
#define  Clock_Rate			Pre_Scalar_4		/* Pre_Scalar_2(4,8,16,32,64,128)*/
#define	 SPI_Speed			Normal				/* Normal - Double */
#define	 Data_Order			Right				/* Left - Right */
#define	 Clock_Polarity     Leading_Rising		/* Leading_Rising - Leading_Falling */
#define  Clock_Phase		Leading_Sample		/* Leading_Setup - Leading_Sample */
#define  MOSI_Pin			Pin_5				/* MOSI HW PIN */
#define  MISO_Pin			Pin_6 				/* MISO HW PIN */
#define	 SPI_SCK			Pin_7				/* SPI Clock Pin */
#define	 Data_Port			Port_B				/* MISO MISO Port */
#define	 Flush_Buffer		0x11				/* MISO MISO Port */
#endif
/*_SPI_CONFIG_H_*/
