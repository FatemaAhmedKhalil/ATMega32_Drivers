/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/************************************** Component: Kaypad **************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#include "STD_Types.h"
#include "BitOperations.h"

#include "DIO_Interface.h"
#include "KPD_Config.h"
#include "KPD_Private.h"
#include "KPD_Interface.h"

u8 GetPressedKey (void)
{
	u8 PressedKey = NoPressedKeys;
	u8 PinState;
	u8 ColumnIndex;
	u8 RowIndex;
	
	static u8 KPD[ColumnsNumber][RowsNumber] = KPD_Array;
	
	for (ColumnIndex = 0; ColumnIndex < ColumnsNumber; ColumnIndex++)
	{
		// Activate Current Column
		DIO_SetPinValue (KPD_PORT, KPD_ColumnArray[ColumnIndex], PIN_LOW);
		
		for (RowIndex = 0; RowIndex < RowsNumber; RowIndex++)
		{
			// Read the Current Row
			DIO_GetPinValue (KPD_PORT, KPD_RowArray[RowIndex], &PinState);
			
			// Check if the Key is Pressed
			if (PinState == PIN_LOW)
			{
				PressedKey = KPD[ColumnIndex][RowIndex];
				
				// Polling (Busy Waiting) until the key is released
				while(PinState == PIN_LOW)
						DIO_GetPinValue (KPD_PORT, KPD_RowArray[RowIndex], &PinState);
						
					return PressedKey;
			}
		}
		
		// Deactivate Current Column
		DIO_SetPinValue (KPD_PORT, KPD_ColumnArray[ColumnIndex], PIN_HIGH);
	}
	return PressedKey;
}