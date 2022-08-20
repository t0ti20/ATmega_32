/*File Guard*/
#ifndef SEVEN_SEGMENT_INTERFACE_H_
#define SEVEN_SEGMENT_INTERFACE_H_

/*Special Character*/
#define Left_Arrow  0x06
#define Right_Arrow 0x30

/*Seven Segment Basic Options*/
void Seven_Segment_VidInit(u8 Copy_u8Number);									   /*7-Segment Initialization*/
void Seven_Segment_VidSend_One_Digit(u8 Copy_u8Number);	  					   /*Use Only One 7-Segment*/
void Seven_Segment_VidCount_One_Digit(u8 Copy_u8Max_number,u16 Copy_u8Delay_Ms);      	   /*Count With 7-Segment*/
void Seven_Segment_VidSpecial_One_Digit(u8 Copy_u8Character);			 		   /*Special Character With 7-Segment*/
void Seven_Segment_VidIncrement_One_Digit();												   /*7-Segment Increment*/
void Seven_Segment_VidDecrement_One_Digit();
void Seven_Segment_VidSend_Two_Digits(u8 Copy_u8Number);      /*Use TWO 7-Segments*/
void Seven_Segment_VidCount_Two_Digits(u8 Copy_u8Min,u8 Copy_u8Max,u8 Copy_u8Delay);
#endif
/* SEVEN_SEGMENT_INTERFACE_H_ */
