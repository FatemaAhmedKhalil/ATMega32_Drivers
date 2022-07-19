/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: DIO *******************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef DIO_Register
#define DIO_Register

#define PORTA *((volatile u8*) 0X3b)	// Port A
#define DDRA  *((volatile u8*) 0x3a)	// Port A Direction
#define PINA  *((volatile u8*) 0x39)	// Pins of Port A

#define PORTB *((volatile u8*) 0x38)	// Port B
#define DDRB  *((volatile u8*) 0x37)	// Port B Direction
#define PINB  *((volatile u8*) 0x36)	// Pins of Port B

#define PORTC *((volatile u8*) 0x35)	// Port C
#define DDRC  *((volatile u8*) 0x34)	// Port C Direction
#define PINC  *((volatile u8*) 0x33)	// Pins of Port C

#define PORTD *((volatile u8*) 0x32)	// Port D
#define DDRD  *((volatile u8*) 0x31)	// Port D Direction
#define PIND  *((volatile u8*) 0x30)	// Pins of Port D

#endif