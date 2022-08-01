/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: ADC *******************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef ADC_Register
#define ADC_Register

#define ADMUX		*((volatile u8*) 0x27)	// ADC Multiplexer Selection Register
#define ADMUX_REFS1		7					// Reference Selection Bit 1
#define ADMUX_REFS0		6					// Reference Selection Bit 0
#define ADMUX_ADLAR		5					//ADC Left adjust Result

#define ADCSRA		*((volatile u8*) 0x26)	// ADC Control and Status Register A
#define ADCSRA_ADEN		7					// ADC Enable
#define ADCSRA_ADSC		6					// ADC Start Conversion
#define ADCSRA_ADATE	5					// ADC Auto Trigger Enable
#define ADCSRA_ADIF		4					// ADC Interrupt Flag
#define ADCSRA_ADIE		3					// ADC Interrupt Enable
#define ADCSRA_ADPS2	2					// PreScaler Bit 2
#define ADCSRA_ADPS1	1					// PreScaler Bit 1
#define ADCSRA_ADPS0	0					// PreScaler Bit 0

#define ADCH		*((volatile u8*) 0x25)	// ADC High Register
#define ADCL		*((volatile u8*) 0x24)	// ADC Low Register

#endif