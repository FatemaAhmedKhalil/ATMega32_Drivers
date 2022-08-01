/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: ADC *******************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#include "STD_Types.h"
#include "BitOperations.h"

#include "ADC_Config.h"
#include "ADC_Private.h"
#include "ADC_Register.h"
#include "ADC_Interface.h"

static u8* ADC_Reading = NULL;
static void (*ADC_CallBackNotificationFunction)(void) = NULL;

static u8 AdjustResult;
u8 BusyState = Free;

u8 ADC_Initialliztion (u8 VREF, u8 adjust, u8 DivisionFactor)
{
	u8 ErrorState = 0;
	AdjustResult = adjust;
	// Initialize the Reference Voltage
	switch(VREF)
	{
		case AREF: CLR_BIT(ADMUX, ADMUX_REFS1); CLR_BIT(ADMUX, ADMUX_REFS0); break;
		case AVCC: CLR_BIT(ADMUX, ADMUX_REFS1); SET_BIT(ADMUX, ADMUX_REFS0); break;
		case InternalVREF: SET_BIT(ADMUX, ADMUX_REFS1); SET_BIT(ADMUX, ADMUX_REFS0); break;
		default: ErrorState = 1; break;
	}
	
	// Activate the Adjust Result
	switch(adjust)
	{
		case Left: SET_BIT(ADMUX, ADMUX_ADLAR); break;
		case Right: CLR_BIT(ADMUX, ADMUX_ADLAR); break;
		default: ErrorState = 1; break;
	}
	
	// Set PreScaler
	ADCSRA &= 0b11111000;  // Bit Masking
	ADCSRA |= DivisionFactor;
	
	// Enable Peripheral
	SET_BIT(ADCSRA, ADCSRA_ADEN);
		
	return ErrorState;
}

u8 ADC_StartConversionSynch (u8 Channel, u8* SynchReading)
{
	u32 Counter = 0;
	u8 ErrorState = 0;
	
	if (BusyState == Free)
	{
		// ADC Now is Busy
		BusyState == Busy;
		
		// Use Bit Masking to Set the Channel
		ADMUX &= 0b11100000;
		ADMUX |= Channel;
	
		// Start Conversion
		SET_BIT(ADCSRA, ADCSRA_ADSC);
	
		// Polling (Busy Waiting) Until The Conversion Complete Flag is Set or Counter Reaches Time Out
		while ( (GET_BIT(ADCSRA, ADCSRA_ADIF) == 0) && (Counter != ADC_TimeOut) )
		{
			Counter++;
		}
	
		if (Counter == ADC_TimeOut)
			ErrorState = 1;		// Loop is broken because Time Out is reached
		
		else 
		{	// Loop is broken because Flag is raised
		
			// Clear the Conversion Complete Flag
			CLR_BIT(ADCSRA, ADCSRA_ADIF);
		
			// Return the Reading
			if (AdjustResult == Left)
				*SynchReading = ADCH;
			else if (AdjustResult == Right)
				*SynchReading = RightADCAdjustResult;
				
			// Make ADC Free
			BusyState == Free;
		}
	}
	else
		ErrorState = BusyError;
		
	return ErrorState;
}

u8 ADC_StartConversionAsynch (u8 Channel, u8* AsynchReading, void(*NotificationFunction)(void))
{
	u8 ErrorState = 0;
	if (BusyState == Free)
	{
		if ( AsynchReading == NULL || NotificationFunction == NULL)
			ErrorState = 1;
		else
		{
			// Make ADC Busy in order not to work till being Free 
			BusyState == Busy;
	
			// Initialize the Reading value Globally
			ADC_Reading = AsynchReading;
			
			// Initialize the Call Back Function Globally
			ADC_CallBackNotificationFunction = NotificationFunction;
			
			ADMUX &= 0b11100000;
			ADMUX |= Channel;
			
			// Start Conversion
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			// ADC Interrupt Enable
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
	}
	else
		ErrorState = BusyError;
		
	return ErrorState;
}

void __vector_16 (void) __attribute__((signal));
void __vector_16(void)
{
	// Read ADC Result
	if (AdjustResult == Left)
		*ADC_Reading = ADCH;
	else if (AdjustResult == Right)
		*ADC_Reading = RightADCAdjustResult;
	
	// Make ADC Free
	BusyState == Free;
	
	// Invoke the Call Back Notification Function
	ADC_CallBackNotificationFunction();
	
	// Disable ADC Conversion Complete Interrupt 
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
}