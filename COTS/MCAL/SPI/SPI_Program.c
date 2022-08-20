/*------------------------------- INCLUDE -------------------------------*/
#include "../../Library/Macros.h"
#include "../../Library/Standard_Types.h"
#include "../../MCAL/SPI/SPI_Config.h"
#include "../../MCAL/SPI/SPI_Interface.h"
#include "../../MCAL/SPI/SPI_Private.h"
/*------------------------- OPTIONS FOR SPI -------------------------*/
void SPI_VidInitialization (u8 Copy_u8Master_Slave)
{
	switch(Copy_u8Master_Slave)	/* Master/Slave Select (0-Slave)(1-Master) */
	{
		case(Master):Set_Bit(SPCR,SPCR_MSTR);break;
		case(Slave):Clear_Bit(SPCR,SPCR_MSTR);break;
		default:Clear_Bit(SPCR,SPCR_MSTR);break;
	}

	#if SPI_Interrupt == Disable		/* SPI Interrupt Enable */
		Clear_Bit(SPCR,SPCR_SPIE);
	#elif SPI_Interrupt == Enable
		Set_Bit(SPCR,SPCR_SPIE);
	#else
				#warning (" Wrong Configuration !!")
	#endif

	#if Data_Order == Left		/* Data Order (0-Lift)(1-Right) */
		Clear_Bit(SPCR,SPCR_DORD);
	#elif Data_Order == Right
		Set_Bit(SPCR,SPCR_DORD);
	#else
				#warning (" Wrong Configuration !!")
	#endif

	#if Clock_Polarity == Rising		/* Clock Polarity (0-Rising)(1-Falling) */
		Clear_Bit(SPCR,SPCR_CPOL);
	#elif Clock_Polarity == Falling
		Set_Bit(SPCR,SPCR_CPOL);
	#else
				#warning (" Wrong Configuration !!")
	#endif

	#if Clock_Phase == Setup		/* Clock Polarity (0-Rising)(1-Falling) */
		Clear_Bit(SPCR,SPCR_CPOL);
	#elif Clock_Phase == Sample
		Set_Bit(SPCR,SPCR_CPOL);
	#else
				#warning (" Wrong Configuration !!")
	#endif

	Set_Bit(SPSR,SPSR_SPI2X); /* Double SPI Speed Bit */


	#if Clock_Rate == by_2	/* Clock Rate Select */
		Set_Bit(SPCR,SPCR_SPR0);
		Clear_Bit(SPCR,SPCR_SPR1);
	#elif	Clock_Rate == by_8
		Clear_Bit(SPCR,SPCR_SPR0);
		Clear_Bit(SPCR,SPCR_SPR1);
	#elif Clock_Rate == by_32
		Clear_Bit(SPCR,SPCR_SPR0);
		Set_Bit(SPCR,SPCR_SPR1);
	#elif Clock_Rate == by_64
		Set_Bit(SPCR,SPCR_SPR0);
		Set_Bit(SPCR,SPCR_SPR1);
	#else
			#warning (" Wrong Configuration !!")
	#endif

	Set_Bit(SPCR,SPCR_SPE);	   /* SPI Enable */
}

void SPI_VidSend_Receive(u8 Copy_u8Data,u8 *Copy_u8Reading)
{
	SPDR=Copy_u8Data;
	#if SPI_Interrupt == Disable		/* SPI Interrupt Enable */
		while(!Get_Bit(SPSR,SPSR_SPIF));
	#elif SPI_Interrupt == Enable
	#else
			#warning (" Wrong Configuration !!")
	#endif
	*Copy_u8Reading = SPDR;
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
