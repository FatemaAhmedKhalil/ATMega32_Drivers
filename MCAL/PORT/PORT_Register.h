/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: PORT ******************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef PORT_Register
#define PORT_Register

#define DDRA  *((volatile u8*) 0x3a)	//Port A Data Direction Register
#define DDRB  *((volatile u8*) 0x37)	//Port B Data Direction Register
#define DDRC  *((volatile u8*) 0x34)	//Port C Data Direction Register
#define DDRD  *((volatile u8*) 0x31)	//Port D Data Direction Register

#define PORTA *((volatile u8*) 0X3b)	//Port A Data Register
#define PORTB *((volatile u8*) 0x38)	//Port B Data Register
#define PORTC *((volatile u8*) 0x35)	//Port C Data Register
#define PORTD *((volatile u8*) 0x32)	//Port D Data Register

#endif