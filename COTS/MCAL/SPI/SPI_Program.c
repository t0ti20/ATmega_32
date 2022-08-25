/*------------------------------- INCLUDE -------------------------------*/
#include "SPI_Interface.h"
/*------------------------- OPTIONS FOR SPI -------------------------*/
void SPI_VidInitialization (u8 Copy_u8Master_Slave,u8 Copy_u8Interrupt)
{
	/* Master Slave Select*/
	switch(Copy_u8Master_Slave)
	{
		case(Master):DIO_VidSet_Pin_Direction(Data_Port, MOSI_Pin, OUTPUT);DIO_VidSet_Pin_Direction(Data_Port, MISO_Pin,INPUT);DIO_VidSet_Pin_Direction(Data_Port,SPI_SCK,OUTPUT);Set_Bit(SPCR,SPCR_MSTR);break;
		case(Slave):DIO_VidSet_Pin_Direction(Data_Port, MOSI_Pin, INPUT);DIO_VidSet_Pin_Direction(Data_Port, MISO_Pin,OUTPUT);Clear_Bit(SPCR,SPCR_MSTR);break;
		default:Clear_Bit(SPCR,SPCR_MSTR);break;
	}
	/* Interrupt Setup */
	if(Copy_u8Interrupt==SPI_Interrupt_Enable)Set_Bit(SPCR,SPCR_SPIE);
	else Clear_Bit(SPCR,SPCR_SPIE);
	/* Data Order */
	#if Data_Order == Left
		Clear_Bit(SPCR,SPCR_DORD);
	#elif Data_Order == Right
		Set_Bit(SPCR,SPCR_DORD);
	#else
				#warning (" Wrong Configuration !!")
	#endif
	/* Clock Polarity*/
	#if Clock_Polarity == Leading_Rising
		Clear_Bit(SPCR,SPCR_CPOL);
	#elif Clock_Polarity == Leading_Falling
		Set_Bit(SPCR,SPCR_CPOL);
	#else
				#warning (" Wrong Configuration !!")
	#endif
		/* Clock Phase*/
	#if Clock_Phase == Leading_Sample
		Clear_Bit(SPCR,SPCR_CPOL);
	#elif Clock_Phase == Leading_Setup
		Set_Bit(SPCR,SPCR_CPOL);
	#else
				#warning (" Wrong Configuration !!")
	#endif
	/* Double SPI Speed Bit & Clock Rate Select*/
#if (SPI_Speed == Normal) && (Clock_Rate == Pre_Scalar_4)
	Clear_Bit(SPSR,SPSR_SPI2X);
	Clear_Bit(SPCR,SPCR_SPR0);
	Clear_Bit(SPCR,SPCR_SPR1);
#elif (SPI_Speed == Normal) && (Clock_Rate == Pre_Scalar_16)
	Clear_Bit(SPSR,SPSR_SPI2X);
	Clear_Bit(SPCR,SPCR_SPR1);
	Set_Bit(SPCR,SPCR_SPR0);
#elif (SPI_Speed == Normal) && (Clock_Rate == Pre_Scalar_64)
	Clear_Bit(SPSR,SPSR_SPI2X);
	Set_Bit(SPCR,SPCR_SPR1);
	Clear_Bit(SPCR,SPCR_SPR0);
#elif (SPI_Speed == Normal) && (Clock_Rate == Pre_Scalar_128)
	Clear_Bit(SPSR,SPSR_SPI2X);
	Set_Bit(SPCR,SPCR_SPR1);
	Set_Bit(SPCR,SPCR_SPR0);
#elif (SPI_Speed == Double) && (Clock_Rate == Pre_Scalar_2)
	Set_Bit(SPSR,SPSR_SPI2X);
	Set_Bit(SPCR,SPCR_SPR0);
	Clear_Bit(SPCR,SPCR_SPR1);
#elif (SPI_Speed == Double) && (Clock_Rate == Pre_Scalar_8)
	Set_Bit(SPSR,SPSR_SPI2X);
	Clear_Bit(SPCR,SPCR_SPR0);
	Clear_Bit(SPCR,SPCR_SPR1);
#elif (SPI_Speed == Double) && (Clock_Rate == Pre_Scalar_32)
	Set_Bit(SPSR,SPSR_SPI2X);
	Clear_Bit(SPCR,SPCR_SPR0);
	Set_Bit(SPCR,SPCR_SPR1);
#elif (SPI_Speed == Double) && (Clock_Rate == Pre_Scalar_64)
	Set_Bit(SPSR,SPSR_SPI2X);
	Set_Bit(SPCR,SPCR_SPR0);
	Set_Bit(SPCR,SPCR_SPR1);
#else
			#warning (" Wrong Configuration !!")
#endif
	/* SPI Enable */
	Set_Bit(SPCR,SPCR_SPE);
}

void SPI_VidSend_Receive(u8 Copy_u8Mode,u8 *Copy_u8Data)
{
	u8 Local_u8Flush_Buffer=Flush_Buffer;
	if(Copy_u8Mode==SPI_Send)
	{
		SPDR=*Copy_u8Data;
		while(!Get_Bit(SPSR,SPSR_SPIF));
		Local_u8Flush_Buffer = SPDR;
	}
	else if (Copy_u8Mode==SPI_Receive)
	{
		SPDR=Local_u8Flush_Buffer;
		while(!Get_Bit(SPSR,SPSR_SPIF));
		*Copy_u8Data = SPDR;
	}
}


/*------------------------- ISR -------------------------*/

static void (*SPI_Inturrept_Function)(void)=NULL;
void SPI_VidInturrept(void(*Copy_VidInturrept)(void))
{
	if(Copy_VidInturrept!=NULL)
	{
		SPI_Inturrept_Function = Copy_VidInturrept;
	}
}
void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
	if(SPI_Inturrept_Function!=NULL)
	{
		SPI_Inturrept_Function();
	}
}
