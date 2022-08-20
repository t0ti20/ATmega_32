/*------------------------------- INCLUDE -------------------------------*/
#include "../../MCAL/ADC/ADC_Interface.h"
/*-------------------------------------------------------------------*/
/*------------------------- OPTIONS FOR ADC -------------------------*/
/*-------------------------------------------------------------------*/
void ADC_VidInitialization (void)
{
/*--------------------SELECT REFERANCE--------------------*/
#if Voltage_Referace == AVCC
	Set_Bit(ADMUX, ADMUX_REFS0);
	Clear_Bit(ADMUX, ADMUX_REFS1);
#elif Voltage_Referace == AREF
	Clear_Bit(ADMUX, ADMUX_REFS0);
	Clear_Bit(ADMUX, ADMUX_REFS1);
#elif Voltage_Referace == Internal
	Set_Bit(ADMUX, ADMUX_REFS0);
	Set_Bit(ADMUX, ADMUX_REFS1);
#else
		#warning (" Wrong Configuration !!")
#endif
/*--------------------ACTIVE ADJUST--------------------*/
#if ADC_Data_Mode == LOW
	Clear_Bit(ADMUX, ADMUX_ADLAR);
#elif ADC_Data_Mode == HIGH
	Set_Bit(ADMUX, ADMUX_ADLAR);
#else
		#warning (" Wrong Configuration !!")
#endif
/*--------------------SELECT PRESCALAR--------------------*/
#if ADC_Prescaler == Prescaler_2
	Clear_Bit(ADCSRA,ADCSRA_ADPS0);
	Clear_Bit(ADCSRA,ADCSRA_ADPS1);
	Clear_Bit(ADCSRA,ADCSRA_ADPS2);
#elif ADC_Prescaler == Prescaler_4
	Clear_Bit(ADCSRA,ADCSRA_ADPS0);
	Set_Bit(ADCSRA,ADCSRA_ADPS1);
	Clear_Bit(ADCSRA,ADCSRA_ADPS2);
#elif ADC_Prescaler == Prescaler_8
	Set_Bit(ADCSRA,ADCSRA_ADPS0);
	Set_Bit(ADCSRA,ADCSRA_ADPS1);
	Clear_Bit(ADCSRA,ADCSRA_ADPS2);
#elif ADC_Prescaler == Prescaler_16
	Clear_Bit(ADCSRA,ADCSRA_ADPS0);
	Clear_Bit(ADCSRA,ADCSRA_ADPS1);
	Set_Bit(ADCSRA,ADCSRA_ADPS2);
#elif ADC_Prescaler == Prescaler_32
	Set_Bit(ADCSRA,ADCSRA_ADPS0);
	Clear_Bit(ADCSRA,ADCSRA_ADPS1);
	Set_Bit(ADCSRA,ADCSRA_ADPS2);
#elif ADC_Prescaler == Prescaler_128
	Set_Bit(ADCSRA,ADCSRA_ADPS0);
	Set_Bit(ADCSRA,ADCSRA_ADPS1);
	Set_Bit(ADCSRA,ADCSRA_ADPS2);
#else
	#warning (" Wrong Configuration !! ")
#endif
	/*ENABLE*/
	Set_Bit(ADCSRA,ADCSRA_ADEN);
}
/*-------------------------------------------------------------------*/
/*-------------------------- Sync_Reading ---------------------------*/
/*-------------------------------------------------------------------*/
/*void ADC_VidSync_Reading (u8 Copy_u8Channel,u8 *Copy_u8Reading)
{

}*/
/*-------------------------------------------------------------------*/
/*-------------------------- ASync Reading --------------------------*/
/*-------------------------------------------------------------------*/
void ADC_VidAsync_Reading (u8 Copy_u8Channel,u16 *Copy_u16Reading)
{
	ADMUX &= 0xE0;
	ADMUX = ADMUX | Copy_u8Channel;
	Set_Bit(ADCSRA,ADCSRA_ADSC);			/* Start Conversion */
	while(!Get_Bit(ADCSRA,ADCSRA_ADIF));
	Set_Bit(ADCSRA,ADCSRA_ADIF);
#if ADC_Data_Mode == LOW
	*Copy_u16Reading=ADCH;
#elif ADC_Data_Mode == HIGH
	*Copy_u16Reading=ADCH;
#else
		#warning (" Wrong Configuration !!")
#endif
}
/*-------------------------------------------------------------------*/
/*------------------------- Mapped Reading -------------------------*/
/*-------------------------------------------------------------------*/
void ADC_VidAsync_Mapped_Reading (u8 Copy_u8Channel,u32 Copy_u32Min,u32 Copy_u32Max,u32 * Copy_u32Reading)
{
	u8 Local_u16Value;
	ADC_VidAsync_Reading (Copy_u8Channel,&Local_u16Value);
	*Copy_u32Reading=((((Local_u16Value)*(Copy_u32Max-Copy_u32Min))/(255UL))+Copy_u32Min);
}
