/*File Guard*/
#ifndef _ADC_CONFIG_H_
#define _ADC_CONFIG_H_

/************* ADC Configurations ************/
/* AVCC -- AREF -- Internal */
#define  Voltage_Referace	AVCC  		 				/*Voltage_Referace*/

/* LOW -- HIGH */
#define  ADC_Data_Mode	HIGH  		 					/*ADC Store Data Mode*/

/* Prescaler_4 -- 2-4-8-16-32-64-128 */
#define  ADC_Prescaler	Prescaler_128  					/*ADC PreScaler*/

/* Free - Comparator - External - Timer_0_Overflow */
#define  ADC_Trigger_Mode        Comparator  			/*Trigger Mode*/

#endif
/*_ADC_INTERRUPT_CONFIG_H_*/
