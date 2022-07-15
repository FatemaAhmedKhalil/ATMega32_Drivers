/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: HAL ******************************************/
/************************************** Component: 7Segment ************************************/
/***********************************************************************************************/
/***********************************************************************************************/


/*************************************************************************************************************************************************/
/** Define The Port used in the Hardware  -->  PORTA or PORTB or PORTC or PORTD									**/
/**																		**/
/**	Define The COM Port and Pin used in the Hardware   -->  PIN0 or PIN1 or PIN2 or PIN3 or PIN4 or PIN5 or PIN6 or PIN7		        **/
/**																		**/
/**	Define The Connection Type            -->  COMAnode  or COMCathod									**/
/**																		**/
/**	1) Common Cathod Connection  --> Connect the COM of the 7 Segment with the Ground	( Signal to Light the LEDs is HIGH )		**/
/**																		**/
/**	2) Common Anode Connection   --> Connect the COM of the 7 Segment with the 5 volt		( Signal to Light the LEDs is LOW )	**/
/**																		**/
/*************************************************************************************************************************************************/


#ifndef Seg_Interface
#define Seg_Interface

typedef struct _7Segment_ SEG;
struct _7Segment_
{
	u8 PORT:2;
	u8 COM_PORT:2;
	u8 COM_PIN:3;
	u8 COM_Connection:1;
};

#define COMAnode	1
#define COMCathod	0

void DisplaySevenSegment (SEG Segment, u8 Number);

#endif
