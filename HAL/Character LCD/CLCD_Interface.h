/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/*************************************** Component: CLCD ***************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef CLCD_Interface
#define CLCD_Interface

void CLCD_SendCommand (u8 Command);

void CLCD_SendData (u8 Data);
void CLCD_SendString (const char* String);
void CLCD_SendNumber (u16 Number);

void CLCD_WriteSpecialChars (u8* Pattern, u8 OverwriteBlockNumber, u8 XPosition, u8 YPosition);

void CLCD_Initialization (void);

void CLCD_SetCursor(u8 XPosition, u8 YPosition);

#endif