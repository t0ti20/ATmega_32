/* File Guard */
#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_
/* TWI Functions */
void TWI_VidInitialization (u8 Copy_u8Master_Slave,u8 Copy_u8Adress);
void TWI_VidStart (u8 Copy_u8Adress,u8 Copy_u8Read_Write);
void TWI_VidSend_Data (u8 Copy_u8Data);
void TWI_VidRead_Data (u8 *Copy_u8Data);
void TWI_VidStop (void);
//void TWI_VidRepeated_Start(void);

#endif
/* TWI_INTERFACE_H_ */
