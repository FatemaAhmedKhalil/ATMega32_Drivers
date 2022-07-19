/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: DIO *******************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#include "STD_Types.h"
#include "BitOperations.h"

#include "DIO_Config.h"
#include "DIO_Private.h"
#include "DIO_Register.h"
#include "DIO_Interface.h"

u8 DIO_SetPinValue (u8 Port, u8 Pin, u8 Value)
{
	u8 ErrorState = 0;  // to know if there is Errors or not
	
	if (Pin <= PIN_7)
	{
		if (Value == PIN_LOW) // Low Value means 0 (Clear)
		{
			switch (Port) // to switch the Port and Set the value of the defined Pin
			{
				case PORT_A: CLR_BIT(PORTA, Pin); break;
				case PORT_B: CLR_BIT(PORTB, Pin); break;
				case PORT_C: CLR_BIT(PORTC, Pin); break;
				case PORT_D: CLR_BIT(PORTD, Pin); break;
				default: ErrorState = 1; break; // error 
			}
		}
		
		else if (Value == PIN_HIGH)	// High Value means 1 (Set)
		{
			switch (Port)	// to switch the Port and Set the value of the defined Pin
			{
				case PORT_A: SET_BIT(PORTA, Pin); break;
				case PORT_B: SET_BIT(PORTB, Pin); break;
				case PORT_C: SET_BIT(PORTC, Pin); break;
				case PORT_D: SET_BIT(PORTD, Pin); break;
				default: ErrorState = 1; break;  // Error if not any of these Ports (A, B, C, D) 
			}
		}
		
		else
			ErrorState = 1;		// Error if not any of these values (High or 1, Low or 0)
	}
	
	else
		ErrorState = 1;	// Error if not any of the eight Pins
	
	return ErrorState;
}

u8 DIO_SetPortValue (u8 Port, u8 Value)
{
	u8 ErrorState = 0;	// to know if there is Errors or not
	
	switch (Port)	// to switch the Port and Set its value
	{
		case PORT_A: PORTA = Value; break;
		case PORT_B: PORTB = Value; break;
		case PORT_C: PORTC = Value; break;
		case PORT_D: PORTD = Value; break;
		default: ErrorState = 1; break;	// Error if not any of these Ports (A, B, C, D) 
	}
	
	return ErrorState;
}

u8 DIO_GetPinValue (u8 Port, u8 Pin, u8* Value)
{
	u8 ErrorState = 0;
	if (Pin <= PIN_7 && Value != 0)
	{
		switch (Port)	// to switch the Port and Get the value of the defined Pin
		{
			case PORT_A: *Value = GET_BIT(PINA, Pin); break;
			case PORT_B: *Value = GET_BIT(PINB, Pin); break;
			case PORT_C: *Value = GET_BIT(PINC, Pin); break;
			case PORT_D: *Value = GET_BIT(PIND, Pin); break;
			default: ErrorState = 1; break;	// Error if not any of these Ports (A, B, C, D) 
		}
	}
		else
			ErrorState = 1; // Error if not any of the eight Pins or the value equals 00000000
	
	return ErrorState;
}