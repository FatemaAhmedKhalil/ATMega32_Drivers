/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: DIO *******************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef DIO_Register
#define DIO_Register

#define PORTA *((volatile u8*) 0X3b)	// Port A Data Register
#define DDRA  *((volatile u8*) 0x3a)	// Port A Data Direction Register
#define PINA  *((volatile u8*) 0x39)	// Port A Input Pins Address

#define PORTB *((volatile u8*) 0x38)	// Port B Data Register
#define DDRB  *((volatile u8*) 0x37)	// Port B Data Direction Register
#define PINB  *((volatile u8*) 0x36)	// Port B Input Pins Address

#define PORTC *((volatile u8*) 0x35)	// Port C Data Register
#define DDRC  *((volatile u8*) 0x34)	// Port C Data Direction Register
#define PINC  *((volatile u8*) 0x33)	// Port C Input Pins Address

#define PORTD *((volatile u8*) 0x32)	// Port D Data Register
#define DDRD  *((volatile u8*) 0x31)	// Port D Data Direction Register
#define PIND  *((volatile u8*) 0x30)	// Port D Input Pins Address

#endif