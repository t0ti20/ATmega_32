/*File Guard*/
#ifndef SEVEN_SEGMENT_CONFIG_H_
#define SEVEN_SEGMENT_CONFIG_H_

/*Constant Values*/
#define Seven_Segment_Type	Common_Cathode  							          /* Common_Anode - Common_Cathode */
#define Seven_Segment_Data_Port	Port_C      					  		          /* 7_Segment Used Port */
#define Seven_Segment_Enable_Port Port_D									      /* 7_Segment Enable Port */
#define Seven_Segment_Enable_1_Pin Pin_0									   	  /* First Segment Enable Port */
#define Seven_Segment_Enable_2_Pin Pin_1										  /* Second Segment Enable Port */

/*Common Anode 7-Segment*/
#define Seven_Segment_Anode_Array {0xC0,0xf9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90}

/*Common Cathode 7-Segment*/
#define Seven_Segment_Cathode_Array {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}

#endif
/* SEVEN_SEGMENT_CONFIG_H_ */
