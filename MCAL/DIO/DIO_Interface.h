/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: DIO *******************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef DIO_Interface
#define DIO_Interface

#define PIN_OUTPUT 1
#define PIN_INPUT  0

#define PIN_HIGH  1
#define PIN_LOW   0

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7

u8 DIO_SetPinValue (u8 Port, u8 Pin, u8 Value);  // to Set a Value to a Pin by define its Port and Number

u8 DIO_SetPortValue (u8 Port, u8 Value);	// to Set a Value to a full Port 

u8 DIO_GetPinValue (u8 Port, u8 Pin, u8* Value);	// to Get the Value of a certain Pin by define its Port and Number

#endif