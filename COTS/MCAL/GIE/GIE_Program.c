/*------------------------------- INCLUDE -------------------------------*/
#include  "../../Library/Macros.h"
#include "../../Library/Standard_Types.h"
#include "../../MCAL/GIE/GIE_Interface.h"
#include "../../MCAL/GIE/GIE_Private.h"


/*------------------------- GIE Enable -------------------------*/
void GIE_VidEnable ()
{
	Set_Bit(SREG,SREG_I_Bit);
}


/*------------------------- GIE Disable -------------------------*/
void GIE_VidDisable (void)
{
	Clear_Bit(SREG,SREG_I_Bit);
}

