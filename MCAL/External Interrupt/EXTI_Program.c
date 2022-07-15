/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/*********************************** SWC: External Interrupt ***********************************/
/***********************************************************************************************/
/***********************************************************************************************/

#include "STD_Types.h"
#include "BitOperations.h"

#include "EXTI_Config.h"
#include "EXTI_Private.h"
#include "EXTI_Register.h"
#include "EXTI_Interface.h"

void EXTI_INT1 (u8 Change)
{
	if (Change == FallingEdge)
	{
		// Set Interrupt Sense Control of INT1 to Falling Edge
		SET_BIT(MCUCR, MCUCR_ISC11);
		CLR_BIT(MCUCR, MCUCR_ISC10);
	}
	
	else if (Change == RisingEdge)
	{
		// Set Interrupt Sense Control of INT1 to Rising Edge
		SET_BIT(MCUCR, MCUCR_ISC11);
		SET_BIT(MCUCR, MCUCR_ISC10);
	}
	
	else if (Change == LowLevel)
	{
		// Set Interrupt Sense Control of INT1 to Low Level
		CLR_BIT(MCUCR, MCUCR_ISC11);
		CLR_BIT(MCUCR, MCUCR_ISC10);
	}
	
	else if (Change == AnyChange)
	{
		// Set Interrupt Sense Control of INT1 for any Logical Change
		CLR_BIT(MCUCR, MCUCR_ISC11);
		SET_BIT(MCUCR, MCUCR_ISC10);
	}
	
	// Set External Interrupt Request Peripheral of INT1 to Enable
	SET_BIT(GICR, GICR_INT1);
}

void EXTI_INT0 (u8 Change)
{
	if (Change == FallingEdge)
	{
		// Set Interrupt Sense Control of INT0 to Falling Edge
		SET_BIT(MCUCR, MCUCR_ISC01);
		CLR_BIT(MCUCR, MCUCR_ISC00);
	}
	else if (Change == RisingEdge)
	{
		// Set Interrupt Sense Control of INT0 to Rising Edge
		SET_BIT(MCUCR, MCUCR_ISC01);
		SET_BIT(MCUCR, MCUCR_ISC00);
	}

	else if (Change == LowLevel)
	{
		// Set Interrupt Sense Control of INT0 to Low Level
		CLR_BIT(MCUCR, MCUCR_ISC01);
		CLR_BIT(MCUCR, MCUCR_ISC00);
	}
					
	else if (Change == AnyChange)
	{
		// Set Interrupt Sense Control of INT0 for any Logical Change
		CLR_BIT(MCUCR, MCUCR_ISC01);
		SET_BIT(MCUCR, MCUCR_ISC00);
	}
	
	// Set External Interrupt Request Peripheral of INT0 to Enable
	SET_BIT(GICR, GICR_INT0);
}

void EXTI_INT2 (u8 Change)
{
	if (Change == FallingEdge)
	{
		// Set Interrupt Sense Control of INT2 to Falling Edge
		SET_BIT(MCUCSR, MCUCSR_ISC2);
	}
	
	else if (Change == RisingEdge)
	{
		// Set Interrupt Sense Control of INT2 to Rising Edge
		CLR_BIT(MCUCSR, MCUCSR_ISC2);
	}
	
	// Set External Interrupt Request Peripheral of INT1 to Enable
	SET_BIT(GICR, GICR_INT2);
}
