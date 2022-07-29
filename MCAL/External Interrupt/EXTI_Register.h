/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/*********************************** SWC: External Interrupt ***********************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef EXTI_Register
#define EXTI_Register

#define GICR	*((volatile u8*) 0x5B)		// General Interrupt Control Register
#define GICR_INT1 7		// GICR External Interrupt Request 1 Enable
#define GICR_INT0 6		// GICR External Interrupt Request 0 Enable
#define GICR_INT2 5		// GICR External Interrupt Request 2 Enable

#define GIFR	*((volatile u8*) 0x5A)		// General Interrupt Flag Register

#define MCUCR	*((volatile u8*) 0x55)		// MCU Control Register
#define MCUCR_ISC11 3		// Interrupt Sense Control 1
#define MCUCR_ISC10 2		// Interrupt Sense Control 1
#define MCUCR_ISC01 1		// Interrupt Sense Control 0
#define MCUCR_ISC00 0		// Interrupt Sense Control 0

#define MCUCSR	*((volatile u8*) 0x54)		// MCU Control and Status Register
#define MCUCSR_ISC2 6		//  Interrupt Sense Control 2

#endif
