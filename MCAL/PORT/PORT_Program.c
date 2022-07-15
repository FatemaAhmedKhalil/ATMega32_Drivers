/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: PORT ******************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#include "STD_Types.h"
#include "BitOperations.h"

#include "PORT_Config.h"
#include "PORT_Private.h" 
#include "PORT_Register.h"
#include "PORT_Interface.h"

void PORT_Initialliztion (void)
{
	DDRA = PORTA_Direction;
	DDRB = PORTB_Direction;
	DDRC = PORTC_Direction;
	DDRD = PORTD_Direction;
	
	PORTA = PORTA_Value;
	PORTB = PORTB_Value;
	PORTC = PORTC_Value;
	PORTD = PORTD_Value;
}