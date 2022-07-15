/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/************************************** Component: 7Segment ************************************/
/***********************************************************************************************/
/***********************************************************************************************/
#include "STD_Types.h"
#include "BitOperations.h"

#include "DIO_Interface.h"
#include "Seg_Config.h"
#include "Seg_Private.h"
#include "Seg_Interface.h"

void DisplaySevenSegment (SEG Segment, u8 Number)
{
	static u8 Seg[SegmentNumbers] = Seg_Array;
	
	if (Segment.COM_Connection == COMAnode)
	{
		DIO_SetPinValue(Segment.COM_PORT, Segment.COM_PIN, PIN_HIGH); 
		DIO_SetPortValue (Segment.PORT, ~Seg[Number]);	// Common Anode
	}
	
	else if (Segment.COM_Connection == COMCathod)
	{
		DIO_SetPinValue(Segment.COM_PORT, Segment.COM_PIN, PIN_LOW); 
		DIO_SetPortValue (Segment.PORT, Seg[Number]);	// Common Cathode
	}
}