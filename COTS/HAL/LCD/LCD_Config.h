/*File Guard*/
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
/*LCD Mode Select*/
#define LCD_Mode		Mode_4                         /* Mode_8 - Mode_4 */
/*CONTROL PORT And Pins*/
#define LCD_CTRL_PORT 	Port_D					 /* Port_A-Port_B-Port_C-Port_D */
#define LCD_RS_PIN		Pin_0					 /* Pin_0-Pin_1-Pin_2-......... */
#define LCD_RW_PIN		Pin_1
#define LCD_E_PIN		Pin_2
/*Data PORT*/
/*In 4-Bit Mode You Have To Connect Pins From LCD 4-5-6-7 To Pins From 4-5-6-7*/
#define LCD_DATA_PORT	Port_C				  	 /* Port_A-Port_B-Port_C-Port_D */
#endif
/* LCD_CONFIGH_ */
