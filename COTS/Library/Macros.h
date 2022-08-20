/*MACROS*/
#ifndef _MACROS_H_
#define _MACROS_H_
/*-------------- File Guard ------------------*/
/* Magic_Numbers */
typedef enum{FALSE,TRUE,ZERO=0,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHTH,NINE,TEN}Magic_Numbers;
/* Bit Math */
#define Set_Bit(Reg,Bit_Num)  Reg|=1<<Bit_Num			/* Set Bit */
#define Clear_Bit(Reg,Bit_Num)  Reg&=~(1<<Bit_Num)		/* Clear Bit */
#define Toggle_Bit(Reg,Bit_Num)  Reg^=(1<<Bit_Num)		/* Toggle Bit */
#define Get_Bit(Reg,Bit_Num)   ((Reg>>Bit_Num)&1)		/* Get_Bit */
/* Max-Min */
#define Max(x,y)    (x>y)?(x):(y)                      /* Max Of Two Digits */
#define Min(x,y)    (x>y)?(y):(x)                      /* Min Of Two Digits */
/*-------------- File Guard ------------------*/
#endif
_MACROS_H_
