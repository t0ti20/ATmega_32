/*File Guard*/
#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_
/*Constant Values*/
#define Keypad_Port		Port_B			  /*KeyPad Used Port*/
#define Not_Pressed		'x' 		      /*In Case There Is No Button Pressed*/
#define Keypad_Array {{'7','8','9','/'},\
					  {'4','5','6','*'},\
					  {'1','2','3','-'},\
					  {'O','0','=','+'}}\
/* The COLUMN Pins Output */
#define KeyPad_u8Column_0_PIN		Pin_0
#define KeyPad_u8Column_1_PIN       Pin_1
#define KeyPad_u8Column_2_PIN       Pin_2
#define KeyPad_u8Column_3_PIN       Pin_3
/* The ROW Pins Input */
#define KeyPad_u8Row_0_PIN          Pin_4
#define KeyPad_u8Row_1_PIN          Pin_5
#define KeyPad_u8Row_2_PIN          Pin_6
#define KeyPad_u8Row_3_PIN          Pin_7
#endif
/* KEYPAD_CONFIGH_H_*/
