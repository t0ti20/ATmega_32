/*------------------------------- INCLUDE -------------------------------*/
#include "../../Library/Macros.h"
#include "../../Library/Standard_Types.h"
#include "../../MCAL/TWI/TWI_Interface.h"
#include "../../MCAL/TWI/TWI_Private.h"
/*------------------------- GIE Enable -------------------------*/
void TWI_VidInitialization(u8 Copy_u8Master_Slave,u8 Copy_u8Adress)
{
	if( Copy_u8Master_Slave == Slave)	/*SCL frequency*/
	{
		TWBR= TWBR_Value;
		Clear_Bit(TWSR,TWSR_TWPS1);
		Clear_Bit(TWSR,TWSR_TWPS0);
	}
	if(Copy_u8Adress>0)		/* Adress Set + BroadCast */
	{
		TWAR=(Copy_u8Adress<<1);
	}
	Set_Bit(TWCR,TWCR_TWEN);		/*Enable TWI*/
}

void TWI_VidStart(u8 Copy_u8Adress,u8 Copy_u8Read_Write)
{
	/*Set Start Condition*/
	Set_Bit(TWCR,TWCR_TWSTA);

	/*Clear Flag*/
	Set_Bit(TWCR,TWCR_TWINT);

	/*Wait Untill Flag*/
	while(!Get_Bit(TWCR,TWCR_TWINT));

	/*Check*/
	/*if(!=START_ACK)
	{

	}*/

	/*Select Adress And Operation*/
	TWDR=((Copy_u8Adress<<1)|Copy_u8Read_Write);

	/*Clear*/
	Clear_Bit(TWCR,TWCR_TWSTA);

	/*Clear Flag (Start Job)*/
	Set_Bit(TWCR,TWCR_TWINT);

	/*Wait Untill Flag*/
	while(!Get_Bit(TWCR,TWCR_TWINT));

	/*Check*/
	/*if(!=REP_START_ACK)
	{

	}*/
}

void TWI_VidSend_Data(u8 Copy_u8Data)
{
	/*Write Data*/
	TWDR = Copy_u8Data;

	/*Clear Flag (Start Job)*/
	Set_Bit(TWCR,TWCR_TWINT);

	/*Wait Untill Flag*/
	while(!Get_Bit(TWCR,TWCR_TWINT));

	/*Check*/
	/*if(!=SLAVE_W_ACK)
	{

	}*/
}

void TWI_VidRead_Data(u8 *Copy_u8Data)
{
	/*Clear Flag (Start Job)*/
	Set_Bit(TWCR,TWCR_TWINT);

	/*Wait Untill Flag*/
	while(!Get_Bit(TWCR,TWCR_TWINT));

	/*Read Data*/
	*Copy_u8Data=TWDR;

	/*Check*/
	/*if(!=SLAVE_R_ACK)
	{

	}*/
}

void TWI_VidStop(void)
{
	/*Stop Indicate*/
	Set_Bit(TWCR,TWCR_TWSTO);

	/*Clear Flag (Start Job)*/
	Set_Bit(TWCR,TWCR_TWINT);

}


/*------------------------- GIE Disable -------------------------*/


