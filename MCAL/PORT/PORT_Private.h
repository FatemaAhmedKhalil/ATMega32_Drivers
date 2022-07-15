/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Duthor: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: PORT ******************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef PORT_Private
#define PORT_Private

#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)				CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)		0b##b7##b6##b5##b4##b3##b2##b1##b0

#define PORTA_Direction		CONC(PORTA_PIN7_Direction,PORTA_PIN6_Direction,PORTA_PIN5_Direction,PORTA_PIN4_Direction,PORTA_PIN3_Direction,PORTA_PIN2_Direction,PORTA_PIN1_Direction,PORTA_PIN0_Direction)
#define PORTB_Direction		CONC(PORTB_PIN7_Direction,PORTB_PIN6_Direction,PORTB_PIN5_Direction,PORTB_PIN4_Direction,PORTB_PIN3_Direction,PORTB_PIN2_Direction,PORTB_PIN1_Direction,PORTB_PIN0_Direction)
#define PORTC_Direction		CONC(PORTC_PIN7_Direction,PORTC_PIN6_Direction,PORTC_PIN5_Direction,PORTC_PIN4_Direction,PORTC_PIN3_Direction,PORTC_PIN2_Direction,PORTC_PIN1_Direction,PORTC_PIN0_Direction)
#define PORTD_Direction		CONC(PORTD_PIN7_Direction,PORTD_PIN6_Direction,PORTD_PIN5_Direction,PORTD_PIN4_Direction,PORTD_PIN3_Direction,PORTD_PIN2_Direction,PORTD_PIN1_Direction,PORTD_PIN0_Direction)

#define PORTA_Value		    CONC(PORTA_PIN7_Value,PORTA_PIN6_Value,PORTA_PIN5_Value,PORTA_PIN4_Value,PORTA_PIN3_Value,PORTA_PIN2_Value,PORTA_PIN1_Value,PORTA_PIN0_Value)
#define PORTB_Value			CONC(PORTB_PIN7_Value,PORTB_PIN6_Value,PORTB_PIN5_Value,PORTB_PIN4_Value,PORTB_PIN3_Value,PORTB_PIN2_Value,PORTB_PIN1_Value,PORTB_PIN0_Value)
#define PORTC_Value			CONC(PORTC_PIN7_Value,PORTC_PIN6_Value,PORTC_PIN5_Value,PORTC_PIN4_Value,PORTC_PIN3_Value,PORTC_PIN2_Value,PORTC_PIN1_Value,PORTC_PIN0_Value)
#define PORTD_Value			CONC(PORTD_PIN7_Value,PORTD_PIN6_Value,PORTD_PIN5_Value,PORTD_PIN4_Value,PORTD_PIN3_Value,PORTD_PIN2_Value,PORTD_PIN1_Value,PORTD_PIN0_Value)

#endif