/*-----------------------------------------------------------------------*/
/*------------------------------- INCLUDE -------------------------------*/
/*-----------------------------------------------------------------------*/
#include "Timer_Interface.h"
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------- Main Functions --------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/************************************************/
/*					Timer 0 					*/
/************************************************/
void Timer_0_VidBusy_Wait_ms(u32 Copy_u32Delay)
{
	f32 Local_f32Tic_Time=(1024.0/CPU_Freq)*1000;
	u32 Local_u32Total_Tics=Copy_u32Delay/Local_f32Tic_Time;
	if (Local_u32Total_Tics<=255)
	{
		Timer_0_VidInitialization(CTC,Local_u32Total_Tics,Disable_CM,Disable_OF,Pre_Scalar_1024);
		while(!Get_Bit(TIFR,TIFR_OCF0));
		Set_Bit(TIFR,TIFR_OCF0);
	}
	else
	{
		Global_Timer_0_u16Flag=(Local_u32Total_Tics/255)+1;
		Timer_0_VidInitialization(Normal,255-((Local_u32Total_Tics%255)*255),Disable_CM,Disable_OF,Pre_Scalar_1024);
		while(Global_Timer_0_u16Flag)
		{
			if(Get_Bit(TIFR,TIFR_TOV0))
			{
				Global_Timer_0_u16Flag--;
				Set_Bit(TIFR,TIFR_TOV0);
			}
		}
	}
}
void Timer_0_VidDelay_ms(u32 Copy_u32Delay,void (*Copy_VidDelay_Func)(void))
{
	f32 Local_f32Tic_Time=(1024.0/CPU_Freq)*1000;
	u32 Local_u32Total_Tics=Copy_u32Delay/Local_f32Tic_Time;
	if (Local_u32Total_Tics<=255)
	{
		Timer_0_VidInitialization(CTC,Local_u32Total_Tics,Enable_CM,Disable_OF,Pre_Scalar_1024);
		Timer_0_VidCompare_Match_Inturrept(Copy_VidDelay_Func);
	}
	else
	{
		Global_Timer_0_u16Flag=(Local_u32Total_Tics/255)+1;
		Timer_0_VidInitialization(Normal,255-((Local_u32Total_Tics%255)*255),Disable_CM,Enable_OF,Pre_Scalar_1024);
		Timer_0_VidOverflow_Inturrept(Copy_VidDelay_Func);
	}
}

void Timer_0_VidInitialization (u8 Copy_u8Mode,u8 Copy_u8OCR_Value,u8 Copy_u8Compare_Match_Interrupt,u8 Copy_u8Over_Flow_Interrupt,u8 Copy_u8Pre_Scalar)
{
	switch(Copy_u8Mode)
	{
		case(Normal):Clear_Bit(TCCR0,TCCR0_WGM00);Clear_Bit(TCCR0,TCCR0_WGM01);OCR0=Copy_u8OCR_Value;break;
		case(CTC):Clear_Bit(TCCR0,TCCR0_WGM00);Set_Bit(TCCR0,TCCR0_WGM01);OCR0=Copy_u8OCR_Value;break;
		case(PWM_Phase_Correct):Set_Bit(TCCR0,TCCR0_WGM00);Clear_Bit(TCCR0,TCCR0_WGM01);break;
		case(Fast_PWM):Set_Bit(TCCR0,TCCR0_WGM00);Set_Bit(TCCR0,TCCR0_WGM01);break;
		default:Clear_Bit(TCCR0,TCCR0_WGM00);Clear_Bit(TCCR0,TCCR0_WGM01);
	}
	switch(Copy_u8Compare_Match_Interrupt)
	{
		case(Enable_CM):Set_Bit(TIMSK,TIMSK_OCIE0);break;
		case(Disable_CM):Clear_Bit(TIMSK,TIMSK_OCIE0);break;
		default:Set_Bit(TIMSK,TIMSK_OCIE0);
	}
	switch(Copy_u8Over_Flow_Interrupt)
	{
		case(Enable_OF):Set_Bit(TIMSK,TIMSK_TOIE0);break;
		case(Disable_OF):Clear_Bit(TIMSK,TIMSK_TOIE0);break;
		default:Set_Bit(TIMSK,TIMSK_TOIE0);
	}

	if((Copy_u8Mode==PWM_Phase_Correct)||(Copy_u8Mode==Fast_PWM))
	{
		#if	PWM_Mode == COCSOB
			Clear_Bit(TCCR0,TCCR0_COM00);
			Set_Bit(TCCR0,TCCR0_COM01);
		#elif PWM_Mode == COBSOC
			Set_Bit(TCCR0,TCCR0_COM00);
			Set_Bit(TCCR0,TCCR0_COM01);
		#else
					#warning (" Wrong Configuration !!")
		#endif
	}
	switch(Copy_u8Pre_Scalar)
	{
		case(Pre_Scalar_0):Set_Bit(TCCR0 , TCCR0_CS00);Clear_Bit(TCCR0 , TCCR0_CS01);Clear_Bit(TCCR0 , TCCR0_CS02);break;
		case(Pre_Scalar_8):Clear_Bit(TCCR0 , TCCR0_CS00);Set_Bit(TCCR0 , TCCR0_CS01);Clear_Bit(TCCR0 , TCCR0_CS02);break;
		case(Pre_Scalar_64):Set_Bit(TCCR0 , TCCR0_CS00);Set_Bit(TCCR0 , TCCR0_CS01);Clear_Bit(TCCR0 , TCCR0_CS02);break;
		case(Pre_Scalar_256):Clear_Bit(TCCR0 , TCCR0_CS00);Clear_Bit(TCCR0 , TCCR0_CS01);Set_Bit(TCCR0 , TCCR0_CS02);break;
		case(Pre_Scalar_1024):Set_Bit(TCCR0 , TCCR0_CS00);Clear_Bit(TCCR0 , TCCR0_CS01);Set_Bit(TCCR0 , TCCR0_CS02);break;
		default:Clear_Bit(TCCR0 , TCCR0_CS00);Clear_Bit(TCCR0 , TCCR0_CS01);Clear_Bit(TCCR0 , TCCR0_CS02);
	}
}
/************************************************/
/*					Timer 1 					*/
/************************************************/


/************************************************/
/*					Timer 2 					*/
/************************************************/
void Timer_2_VidDelay_ms(u32 Copy_u32Delay,void (*Copy_VidDelay_Func)(void))
{
	f32 Local_f32Tic_Time=(1024.0/CPU_Freq)*1000;
	u32 Local_u32Total_Tics=Copy_u32Delay/Local_f32Tic_Time;
	if (Local_u32Total_Tics<=255)
	{
		Timer_2_VidInitialization(CTC,Local_u32Total_Tics,Enable_CM,Disable_OF,Pre_Scalar_1024);
		Timer_2_VidCompare_Match_Inturrept(Copy_VidDelay_Func);
	}
	else
	{
		Global_Timer_2_u16Flag=(Local_u32Total_Tics/255)+1;
		Timer_2_VidInitialization(Normal,255-((Local_u32Total_Tics%255)*255),Disable_CM,Enable_OF,Pre_Scalar_1024);
		Timer_2_VidOverflow_Inturrept(Copy_VidDelay_Func);
	}
}
void Timer_2_VidBusy_Wait_ms(u32 Copy_u32Delay)
{
	f32 Local_f32Tic_Time=(1024.0/CPU_Freq)*1000;
	u32 Local_u32Total_Tics=Copy_u32Delay/Local_f32Tic_Time;
	if (Local_u32Total_Tics<=255)
	{
		Timer_2_VidInitialization(CTC,Local_u32Total_Tics,Disable_CM,Disable_OF,Pre_Scalar_1024);
		while(!Get_Bit(TIFR,TIFR_OCF2));
		Set_Bit(TIFR,TIFR_OCF2);
	}
	else
	{
		Global_Timer_2_u16Flag=(Local_u32Total_Tics/255)+1;
		Timer_2_VidInitialization(Normal,255-((Local_u32Total_Tics%255)*255),Disable_CM,Disable_OF,Pre_Scalar_1024);
		while(Global_Timer_2_u16Flag)
		{
			if(Get_Bit(TIFR,TIFR_TOV2))
			{
				Global_Timer_2_u16Flag--;
				Set_Bit(TIFR,TIFR_TOV2);
			}
		}
	}

}

void Timer_2_VidInitialization (u8 Copy_u8Mode,u8 Copy_u8OCR_Value,u8 Copy_u8Compare_Match_Interrupt,u8 Copy_u8Over_Flow_Interrupt,u8 Copy_u8Pre_Scalar)
{
	switch(Copy_u8Mode)
	{
		case(Normal):Clear_Bit(TCCR2,TCCR2_WGM21);Clear_Bit(TCCR2,TCCR2_WGM20);OCR2=Copy_u8OCR_Value;break;
		case(CTC):Clear_Bit(TCCR2,TCCR2_WGM21);Set_Bit(TCCR2,TCCR2_WGM20);OCR2=Copy_u8OCR_Value;break;
		case(PWM_Phase_Correct):Set_Bit(TCCR2,TCCR2_WGM21);Clear_Bit(TCCR2,TCCR2_WGM20);break;
		case(Fast_PWM):Set_Bit(TCCR2,TCCR2_WGM21);Set_Bit(TCCR2,TCCR2_WGM20);break;
		default:Clear_Bit(TCCR2,TCCR2_WGM21);Clear_Bit(TCCR2,TCCR2_WGM20);
	}
	switch(Copy_u8Compare_Match_Interrupt)
	{
		case(Enable_CM):Set_Bit(TIMSK,TIMSK_OCIE2);break;
		case(Disable_CM):Clear_Bit(TIMSK,TIMSK_OCIE2);break;
		default:Clear_Bit(TIMSK,TIMSK_OCIE2);
	}
	switch(Copy_u8Over_Flow_Interrupt)
	{
		case(Enable_OF):Set_Bit(TIMSK,TIMSK_TOIE2);break;
		case(Disable_OF):Clear_Bit(TIMSK,TIMSK_TOIE2);break;
		default:Clear_Bit(TIMSK,TIMSK_TOIE2);
	}
	if((Copy_u8Mode==PWM_Phase_Correct)||(Copy_u8Mode==Fast_PWM))
	{
		#if	PWM_Mode == COCSOB
			Clear_Bit(TCCR0,TCCR0_COM00);
			Set_Bit(TCCR0,TCCR0_COM01);
		#elif PWM_Mode == COBSOC
			Set_Bit(TCCR0,TCCR0_COM00);
			Set_Bit(TCCR0,TCCR0_COM01);
		#else
					#warning (" Wrong Configuration !!")
		#endif
	}
	switch(Copy_u8Pre_Scalar)
	{
		case(Pre_Scalar_0):Clear_Bit(TCCR2 , TCCR2_CS22);Clear_Bit(TCCR2 , TCCR2_CS21);Set_Bit(TCCR2 , TCCR2_CS20);break;
		case(Pre_Scalar_8):Clear_Bit(TCCR2 , TCCR2_CS22);Set_Bit(TCCR2 , TCCR2_CS21);Clear_Bit(TCCR2 , TCCR2_CS20);break;
		case(Pre_Scalar_32):Clear_Bit(TCCR2 , TCCR2_CS22);Set_Bit(TCCR2 , TCCR2_CS21);Set_Bit(TCCR2 , TCCR2_CS20);break;
		case(Pre_Scalar_64):Set_Bit(TCCR2 , TCCR2_CS22);Clear_Bit(TCCR2 , TCCR2_CS21);Clear_Bit(TCCR2 , TCCR2_CS20);break;
		case(Pre_Scalar_256):Set_Bit(TCCR2 , TCCR2_CS22);Set_Bit(TCCR2 , TCCR2_CS21);Clear_Bit(TCCR2 , TCCR2_CS20);break;
		case(Pre_Scalar_1024):Set_Bit(TCCR2 , TCCR2_CS22);Set_Bit(TCCR2 , TCCR2_CS21);Set_Bit(TCCR2 , TCCR2_CS20);break;
		default:Clear_Bit(TCCR2 , TCCR2_CS22);Clear_Bit(TCCR2 , TCCR2_CS21);Clear_Bit(TCCR2 , TCCR2_CS20);
	}
}

/************************************************/
/*					General 					*/
/************************************************/
void Timer_VidPwm_Duty_Cycle(u8 Copy_u8Timer,u8 Copy_u8Duty_Cycle)
{
u8 Local_u8Variable=((Copy_u8Duty_Cycle*255ul)/100ul);
	switch(Copy_u8Timer)
	{
		case(Timer_0):OCR0=Local_u8Variable;break;
		case(Timer_1):OCR1AL=Local_u8Variable;OCR1BL=Local_u8Variable;break;
		case(Timer_2):OCR2=Local_u8Variable;break;
	}
}
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------- ISR -------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------------------------------------------------*/

/****************************************************************/
/*							Timer 0 							*/
/****************************************************************/
/*------------------ Over_flow_ISR --------------------*/
static void (*Timer_0_Overflow_Inturrept_Function)(void)=0;
void Timer_0_VidOverflow_Inturrept(void(*Copy_VidInturrept)(void))
{
	if(Copy_VidInturrept!=0)
	{
		Timer_0_Overflow_Inturrept_Function = Copy_VidInturrept;
	}
}
void __vector_11(void) __attribute__((signal,used));
void __vector_11(void)
{
	Global_Timer_0_u16Flag--;
	if(Timer_0_Overflow_Inturrept_Function!=0 && !Global_Timer_0_u16Flag)
	{
		Timer_0_VidInitialization(Normal,0,Disable_CM,Disable_OF,0);
		Timer_0_Overflow_Inturrept_Function();
	}
}
/*-------------------- Compare_Match_ISR ------------------*/
static void (*Timer_0_Compare_Match_Inturrept_Function)(void)=0;
void Timer_0_VidCompare_Match_Inturrept(void(*Copy_VidInturrept)(void))
{
	if(Copy_VidInturrept!=0)
	{
		Timer_0_Compare_Match_Inturrept_Function = Copy_VidInturrept;
	}
}
void __vector_10(void) __attribute__((signal,used));
void __vector_10(void)
{
	if(Timer_0_Compare_Match_Inturrept_Function!=0)
	{
		Timer_0_VidInitialization(Normal,0,Disable_CM,Disable_OF,0);
		Timer_0_Compare_Match_Inturrept_Function();
	}
}

/****************************************************************/
/*							Timer 1 							*/
/****************************************************************/


/****************************************************************/
/*							Timer 2 							*/
/****************************************************************/

/*------------------ Over_flow_ISR --------------------*/
static void (*Timer_2_Overflow_Inturrept_Function)(void)=0;
void Timer_2_VidOverflow_Inturrept(void(*Copy_VidInturrept)(void))
{
	if(Copy_VidInturrept!=0)
	{
		Timer_2_Overflow_Inturrept_Function = Copy_VidInturrept;
	}
}
void __vector_5(void) __attribute__((signal,used));
void __vector_5(void)
{
	Global_Timer_2_u16Flag--;
	if(Timer_2_Overflow_Inturrept_Function!=0 && !Global_Timer_2_u16Flag)
	{
		Timer_2_VidInitialization(Normal,0,Disable_CM,Disable_OF,0);
	}
}
/*-------------------- Compare_Match_ISR ------------------*/
static void (*Timer_2_Compare_Match_Inturrept_Function)(void)=0;
void Timer_2_VidCompare_Match_Inturrept(void(*Copy_VidInturrept)(void))
{
	if(Copy_VidInturrept!=0)
	{
		Timer_2_Compare_Match_Inturrept_Function = Copy_VidInturrept;
	}
}
void __vector_4(void) __attribute__((signal,used));
void __vector_4(void)
{
	if(Timer_2_Compare_Match_Inturrept_Function!=0)
	{
		Timer_2_Compare_Match_Inturrept_Function();
		Timer_2_VidInitialization(Normal,0,Disable_CM,Disable_OF,0);
	}
}
