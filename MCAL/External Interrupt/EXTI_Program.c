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

// Global Pointer to Function to Hold INT_ ISR Address
void (*EXTI_INT0Function)(void) = NULL;
void (*EXTI_INT1Function)(void) = NULL;
void (*EXTI_INT2Function)(void) = NULL;


/** Pre-build Configuration **/
void EXTI_INT1 (void)
{
	// Check Interrupt Sense Control of INT1
	#if INT0_Sense == FallingEdge
	SET_BIT(MCUCR, MCUCR_ISC11);
	CLR_BIT(MCUCR, MCUCR_ISC10);
	
	#elif INT0_Sense == RisingEdge
	SET_BIT(MCUCR, MCUCR_ISC11);
	SET_BIT(MCUCR, MCUCR_ISC10);

	#elif INT0_Sense == LowLevel
	CLR_BIT(MCUCR, MCUCR_ISC11);
	CLR_BIT(MCUCR, MCUCR_ISC10);
	
	#elif INT0_Sense == AnyChange
	CLR_BIT(MCUCR, MCUCR_ISC11);
	SET_BIT(MCUCR, MCUCR_ISC10);
	
	#else
	#error "Wrong INT1 Configuration"
	#endif
	
	// Check External Interrupt Request Peripheral of INT1
	#if INT1_State ==  Enabled
	SET_BIT(GICR, GICR_INT1);
	
	#elif INT1_State ==  Disabled
	CLR_BIT(GICR, GICR_INT1);
	
	#else
	#error "Wrong INT1 State Configuration"
	#endif
}

/** Post-build Configuration **/
u8 EXTI_INT1_Sense (u8 Sense, u8 State)
{
	u8 ErrorState = 0;
	switch(Sense)
	{
		case FallingEdge:	// Set Interrupt Sense Control of INT0 to Falling Edge
			SET_BIT(MCUCR, MCUCR_ISC11);
			CLR_BIT(MCUCR, MCUCR_ISC10);
			break;
		
		case RisingEdge:	// Set Interrupt Sense Control of INT0 to Rising Edge
			SET_BIT(MCUCR, MCUCR_ISC11);
			SET_BIT(MCUCR, MCUCR_ISC10);
			break;
		
		case LowLevel:	// Set Interrupt Sense Control of INT0 to Low Level
			CLR_BIT(MCUCR, MCUCR_ISC11);
			CLR_BIT(MCUCR, MCUCR_ISC10);
			break;
		
		case AnyChange:	// Set Interrupt Sense Control of INT0 for any Logical Change
			CLR_BIT(MCUCR, MCUCR_ISC11);
			SET_BIT(MCUCR, MCUCR_ISC10);
			break;
		
		default: ErrorState = 1;
	}
	
	// Check External Interrupt Request Peripheral of INT1 to Enable
	switch(State)
	{
		case Enabled:
		SET_BIT(GICR, GICR_INT1);
		break;
		
		case Disabled:
		CLR_BIT(GICR, GICR_INT1);
		break;
		
		default: ErrorState = 1;
	}
	return ErrorState;
}

/** ************************************************************************************************ **/

/** Pre-build Configuration **/
void EXTI_INT0 (void)
{
	// Check Interrupt Sense Control of INT0
	#if INT0_Sense == FallingEdge
	SET_BIT(MCUCR, MCUCR_ISC01);
	CLR_BIT(MCUCR, MCUCR_ISC00);
	
	#elif INT0_Sense == RisingEdge
	SET_BIT(MCUCR, MCUCR_ISC01);
	SET_BIT(MCUCR, MCUCR_ISC00);

	#elif INT0_Sense == LowLevel
	CLR_BIT(MCUCR, MCUCR_ISC01);
	CLR_BIT(MCUCR, MCUCR_ISC00);
	
	#elif INT0_Sense == AnyChange
	CLR_BIT(MCUCR, MCUCR_ISC01);
	SET_BIT(MCUCR, MCUCR_ISC00);
	
	#else
	#error "Wrong INT0 Configuration"
	#endif
	
	// Check External Interrupt Request Peripheral of INT0
	#if INT0_State ==  Enabled
	SET_BIT(GICR, GICR_INT0);
	
	#elif INT0_State ==  Disabled
	CLR_BIT(GICR, GICR_INT0);
	
	#else
	#error "Wrong INT0 State Configuration"
	#endif
}
 
/** Post-build Configuration **/
u8 EXTI_INT0_Sense (u8 Sense, u8 State)
{
	u8 ErrorState = 0;
	switch(Sense)
	{
		case FallingEdge:	// Set Interrupt Sense Control of INT0 to Falling Edge
			SET_BIT(MCUCR, MCUCR_ISC01);
			CLR_BIT(MCUCR, MCUCR_ISC00);
			break;
			
		case RisingEdge:	// Set Interrupt Sense Control of INT0 to Rising Edge
			SET_BIT(MCUCR, MCUCR_ISC01);
			SET_BIT(MCUCR, MCUCR_ISC00);
			break;
			
		case LowLevel:	// Set Interrupt Sense Control of INT0 to Low Level
			CLR_BIT(MCUCR, MCUCR_ISC01);
			CLR_BIT(MCUCR, MCUCR_ISC00);
			break;
		
		case AnyChange:	// Set Interrupt Sense Control of INT0 for any Logical Change
			CLR_BIT(MCUCR, MCUCR_ISC01);
			SET_BIT(MCUCR, MCUCR_ISC00);
			break;
			
		default: ErrorState = 1;
	}
	
	// Set External Interrupt Request Peripheral of INT0 to Enable
	switch(State)
	{
		case Enabled:
		SET_BIT(GICR, GICR_INT0);
		break;
		
		case Disabled:
		CLR_BIT(GICR, GICR_INT0);
		break;
		
		default: ErrorState = 1;
	}
	return ErrorState;
}

/** ************************************************************************************************ **/ 

/** Pre-build Configuration **/
void EXTI_INT2 (void)
{
		// Check Interrupt Sense Control of INT2
		#if INT2_Sense == FallingEdge
		SET_BIT(MCUCSR, MCUCSR_ISC2);
		
		#elif INT2_Sense == RisingEdge
		CLR_BIT(MCUCSR, MCUCSR_ISC2);
		
		#else
		#error "Wrong INT2 Configuration"
		#endif
		
		// Check External Interrupt Request Peripheral of INT2
		#if INT2_State ==  Enabled
		SET_BIT(GICR, GICR_INT2);
		
		#elif INT2_State ==  Disabled
		CLR_BIT(GICR, GICR_INT2);
		
		#else
		#error "Wrong INT2 State Configuration"
		#endif
}
/** Post-build Configuration **/
u8 EXTI_INT2_Sense (u8 Sense , u8 State)
{
	u8 ErrorState = 0;
	switch(Sense)
	{
		case FallingEdge:	// Set Interrupt Sense Control of INT2 to Falling Edge
			SET_BIT(MCUCSR, MCUCSR_ISC2);
			break;
	
		case RisingEdge:	// Set Interrupt Sense Control of INT2 to Rising Edge
			CLR_BIT(MCUCSR, MCUCSR_ISC2);
			break;
		
		default: ErrorState = 1;
	}
	
	// Check External Interrupt Request Peripheral of INT2
	switch(State)
	{
		case Enabled:
			SET_BIT(GICR, GICR_INT2);
			break;
			
		case Disabled:
			CLR_BIT(GICR, GICR_INT2);
			break;
			
		default: ErrorState = 1;
	}
	return ErrorState;
}

/** ************************************************************************************************ **/

/** Call Back **/
u8 EXTI_INTn_CallBack (u8 INT_n, void (*INTnFunction)(void))
{
	u8 ErrorSate = 0;
	
	if (INTnFunction != NULL)
	{
		if (INT_n == INT_0)  // Call Back for INT0
			EXTI_INT0Function = INTnFunction;
		
		else if (INT_n == INT_1)  // Call Back for INT1
			EXTI_INT1Function = INTnFunction;
			
		else if (INT_n == INT_2)	// Call Back for INT2
			EXTI_INT2Function = INTnFunction;
		
		else
			ErrorSate = 1;
	}
	else
		ErrorSate = 1;
	
	return ErrorSate;
}

/** ISR of INT0 **/
void __vector_1 (void) __attribute__((signal));
void __vector_1(void)
{
	if (EXTI_INT0Function != NULL)
		EXTI_INT0Function();
	
	else 
	{
		/* Do Nothing */
	}
}

/** ISR of INT1 **/
void __vector_2 (void) __attribute__((signal));
void __vector_2(void)
{
	if (EXTI_INT1Function != NULL)
		EXTI_INT1Function();
	
	else
	{
		/* Do Nothing */
	}
}

/** ISR of INT2 **/
void __vector_3 (void) __attribute__((signal));
void __vector_3(void)
{
	if (EXTI_INT2Function != NULL)
		EXTI_INT2Function();
	
	else
	{
		/* Do Nothing */
	}
}
