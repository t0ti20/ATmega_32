/*File Guard*/
#ifndef _ADC_PRIVATE_H_
#define _ADC_PRIVATE_H_
/************* Macros for Configure ************/
#define     LOW               0      /*ADC Store Data Mode */
#define     HIGH              1      /*ADC Store Data Mode */
#define     AVCC              0      /*AREF, Internal VREF turned off*/
#define     AREF              1      /*AVCC with external capacitor at AREF pin*/
#define 	Internal		  3      /*Internal 2.56V Voltage Reference with external capacitor at AREF pin*/
#define     Prescaler_2		  0      /*PreScaler (2)*/
#define     Prescaler_4		  1	  	 /*PreScaler (4)*/
#define     Prescaler_8		  2	  	 /*PreScaler (8)*/
#define     Prescaler_16	  3	  	 /*PreScaler (16)*/
#define     Prescaler_32	  4	     /*PreScaler (32)*/
#define     Prescaler_64	  5	  	 /*PreScaler (64)*/
#define     Prescaler_128	  6	  	 /*PreScaler (128)*/

/******** Registers ********/
#define   ADMUX     *((volatile u8*)0x27)
#define   ADCSRA    *((volatile u8*)0x26)
#define   ADCH      *((volatile u8*)0x25)
#define   ADCL      *((volatile u8*)0x24)
#define   SFIOR     *((volatile u8*)0x50)
#define   ADCSR     *((volatile u8*)0x5B)

/******** ADMUX_Bits ********/       
#define   ADMUX_REFS1		7		/*Voltage Reference Selection*/
#define   ADMUX_REFS0		6
#define   ADMUX_ADLAR		5		/*ADC Adjust Result*/
#define   ADMUX_MUX_0		0		/*Analog Channel*/
#define   ADMUX_MUX_1		1
#define   ADMUX_MUX_2		2
#define   ADMUX_MUX_3		3
#define   ADMUX_MUX_4		4

/******** ADCSRA_Bits ********/
#define   ADCSRA_ADEN       7		/* ADC Enable */
#define   ADCSRA_ADSC       6		/* Start Conversion */
#define   ADCSRA_ADATE      5		/* Auto Trigger */
#define   ADCSRA_ADIF       4		/* Interrupt Flag (1 when finish Conversion)*/
#define   ADCSRA_ADIE       3		/* Interrupt Enable */
#define   ADCSRA_ADPS2      2		/* PreScalar Selection */
#define   ADCSRA_ADPS1      1
#define   ADCSRA_ADPS0      0

/******** SFIOR_Bits ********/
#define   SFIOR_ADTS2       7		/*Auto Trigger Source*/
#define   SFIOR_ADTS1       6
#define   SFIOR_ADTS0       5

/******** GIFR_Bits ********/
#define   GIFR_Interrupt_F_0       6
#define   GIFR_Interrupt_F_1       7
#define   GIFR_Interrupt_F_2       5

/******** enum ********/
typedef enum {Free,External,Timer_0_Overflow} ADC_Trigger;
typedef enum {ADC_0,ADC_1,ADC_2,ADC_3,ADC_4,ADC_5,ADC_6,ADC_7} ADC_Channels;
#endif 
/*_ADC_PRIVATE_H_*/
