/*File Guard*/
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_
/*FOR PORT A*/
#define PORTA *((volatile u8*)0X3B)
#define DDRA  *((volatile u8*)0X3A)
#define PINA  *((volatile u8*)0X39)
/*FOR PORT B*/
#define PORTB *((volatile u8*)0X38)
#define DDRB  *((volatile u8*)0X37)
#define PINB  *((volatile u8*)0X36)
/*FOR PORT C*/
#define PORTC *((volatile u8*)0X35)
#define DDRC  *((volatile u8*)0X34)
#define PINC  *((volatile u8*)0X33)
/*FOR PORT D*/
#define PORTD *((volatile u8*)0X32)
#define DDRD  *((volatile u8*)0X31)
#define PIND  *((volatile u8*)0X30)
/*Global*/
#define SREG  *((volatile u8*)0x5F)
#define SREG_I 7
/*CONSTANTS_DIO*/
typedef enum{INPUT,OUTPUT,Port_A=0,Port_B,Port_C,Port_D,LOW=0,HI,Pin_0=0,Pin_1,Pin_2,Pin_3,Pin_4,Pin_5,Pin_6,Pin_7}Constants_DIO_Variables;
#endif
/* DIO_PRIVATE_H_ */
