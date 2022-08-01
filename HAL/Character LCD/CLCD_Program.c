/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/*************************************** Component: CLCD ***************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#include "STD_Types.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#include "DIO_Interface.h"
#include "CLCD_Interface.h"
#include "CLCD_Private.h"
#include "CLCD_Config.h"

u8 Counter = 0; // to Count the Number of Characters in the line

void CLCD_SendCommand (u8 Command)
{
	DIO_SetPinValue (ControlPort, CLCD_RS, PIN_LOW); // Set RS to Low for Command
	DIO_SetPinValue (ControlPort, CLCD_RW, PIN_LOW); // Set RS to Low for Write
	DIO_SetPortValue (DataPort, Command); // Set Command to Data Pins
	
	// Send Enable Pulse
	DIO_SetPinValue (ControlPort, CLCD_E, PIN_HIGH);
	_delay_ms(2);
	DIO_SetPinValue (ControlPort, CLCD_E, PIN_LOW);
}

void CLCD_SendData (u8 Data)
{
	DIO_SetPinValue (ControlPort, CLCD_RS, PIN_HIGH); // Set RS to High for Data
	DIO_SetPinValue (ControlPort, CLCD_RW, PIN_LOW); // Set RS to Low for Write
	DIO_SetPortValue (DataPort, Data); // Set Data to Data Pins
	
	// Send Enable Pulse
	DIO_SetPinValue (ControlPort, CLCD_E, PIN_HIGH);
	_delay_ms(2);
	DIO_SetPinValue (ControlPort, CLCD_E, PIN_LOW);
	
	Counter++;
	if (Counter == 16)  // Go to the Second Line
	CLCD_SetCursor(1,0);

	if (Counter == 32)  // Go Back to the First Line
	{
		CLCD_SetCursor(0,0);
		Counter = 0;
	}

}

void CLCD_SendString (const char* String)
{
	// Set The Array of String to Data Pins
	int i = 0;
	while (String[i] != '\0')
	{
		CLCD_SendData (String[i]);
		i++;
	}
}

void CLCD_SendNumber (u16 Number)
{
	
	u16 ReversedNumber = 0;
	u16 Temp = Number;
	u8 digit;

	u8 Counter1 = 0;
	u8 Counter2 = 0;
	
	while (Number > 0)
	{
		// Count the Number's Digits
		digit = Number % 10;
		Number = Number/10;
		
		Counter1++;
	}

	Counter2 = Counter1;
	
	while (Counter1 > 0)
	{
		// Reverse the Number
		ReversedNumber = ReversedNumber*10 + Temp%10;

		if (ReversedNumber == 0)
			ReversedNumber =+ 10;  // to count the Zeros (will create a little bit different number but we will solve it)

		Temp = Temp/10;

		Counter1--;
	}

	while (Counter2 > 0)
	{
		// Split the Number into its Digits
		digit = ReversedNumber % 10;
		
		// Add 48 into the digit so the LCD can read its ASCII and send it
		CLCD_SendData (digit+48);
		
		ReversedNumber = ReversedNumber/10;

		Counter2--;
	}
}

void CLCD_WriteSpecialChars (u8* Pattern, u8 OverwriteBlockNumber /*Just 8 Blocks*/, u8 XPosition, u8 YPosition)
{
	u8 Address = 0;
	Address = OverwriteBlockNumber*8; // Get CGRAM Address
	
	// Set bit 6 for CGRAM Address Command then send the Command
	CLCD_SendCommand (Address + 64);
	
	// Write the Pattern into CGRAM
	for(int i=0; i<8; i++)
	CLCD_SendData (Pattern[i]);
	
	// Go Back to DDRAM to Display the Pattern
	CLCD_SetCursor (XPosition, YPosition);
	
	// Display the Pattern written in the CGRAM
	CLCD_SendData (OverwriteBlockNumber);
}

void CLCD_Initialization (void)
{
	// Wait for more than 30ms
	_delay_ms(40);
	
	// Function Set Command: 2 Lines(bit 3), 5*7 Font Size(bit 2)
	CLCD_SendCommand (0b00111100);
	
	// Display On/Off Control: Display Enable(bit 2), Display Cursor(bit 1), Blink Cursor(bit 0)
	CLCD_SendCommand (0b00001111);
	
	// Clear Display
	CLCD_SendCommand (0b00000001);
}

void CLCD_SetCursor(u8 XPosition, u8 YPosition)
{
	u8 Address = 0;
	if (XPosition == 0)  // Location at First Line
	Address = YPosition;
	else if (XPosition == 1)  // Location at Second Line
	Address = 0x40 + YPosition;
	
	// Set bit 7 for DDRAM Address Command then send the Command
	CLCD_SendCommand(Address + 128);
}