/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: ADC *******************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef ADC_Interface
#define ADC_Interface

/************************************************************************************************/
/* Define The Voltage Reference for ADC	-->		AREF or AVCC or InternalVREF					*/
/*		1) AREF -> Internal Vref turned off														*/
/*		2) AVCC -> AVCC with external capacitor at AREF pin										*/
/*		3) InternalVREF -> Internal 2.56V Voltage Reference with external capacitor at AREF pin	*/
/************************************************************************************************/
#define AREF			1
#define AVCC			2
#define InternalVREF	3

/************************************************************************************************/
/* Define The Adjust Result	-->		Left or Right												*/
/*		1) Left	  -> for 8 bits Presentation													*/
/*		2) Right  -> for 10 bits Presentation													*/
/************************************************************************************************/
#define Left	1
#define Right	2

/************************************************************************************************/
/*    Determine The division factor between the XTAL frequency and the input clock to the ADC	*/
/*		1) Division Factor by 2	  -> Div_2  (The Fastest)										*/
/*		1) Division Factor by 4	  -> Div_4														*/
/*		1) Division Factor by 8	  -> Div_8														*/
/*		1) Division Factor by 16  -> Div_16														*/
/*		1) Division Factor by 32  -> Div_32														*/
/*		1) Division Factor by 64  -> Div_64														*/
/*		1) Division Factor by 128 -> Div_128	(The Slowest)									*/
/************************************************************************************************/
#define Div_2	0  // 0 or 1
#define Div_4	2
#define Div_8	3
#define Div_16	4
#define Div_32	5
#define Div_64	6
#define Div_128	7

/************************************************************************************************/
/*    Determine The  Analog Channel and Gain Selection Bits										*/
/*		1) Single Ended	Input																	*/
/*		1) Positive and Negative Differential Input												*/
/************************************************************************************************/
#define SingleADC0		0b00000000
#define SingleADC1		0b00000001
#define SingleADC2		0b00000010
#define SingleADC3		0b00000011
#define SingleADC4		0b00000100
#define SingleADC5		0b00000101
#define SingleADC6		0b00000110
#define SingleADC7		0b00000111
#define PosADC0_NegADC0_X10		0b00001000
#define PosADC1_NegADC0_X10		0b00001001
#define PosADC0_NegADC0_X200	0b00001010
#define PosADC1_NegADC0_X200	0b00001011
#define PosADC2_NegADC2_X10		0b00001100
#define PosADC3_NegADC2_X10		0b00001101
#define PosADC2_NegADC2_X200	0b00001110
#define PosADC3_NegADC2_X200	0b00001111
#define PosADC0_NegADC1_X1		0b00010000
#define PosADC1_NegADC1_X1		0b00010001
#define PosADC2_NegADC1_X1		0b00010010
#define PosADC3_NegADC1_X1		0b00010011
#define PosADC4_NegADC1_X1		0b00010100
#define PosADC5_NegADC1_X1		0b00010101
#define PosADC6_NegADC1_X1		0b00010110
#define PosADC7_NegADC1_X1		0b00010111
#define PosADC0_NegADC2_X1		0b00011000
#define PosADC1_NegADC2_X1		0b00011001
#define PosADC2_NegADC2_X1		0b00011010
#define PosADC3_NegADC2_X1		0b00011011
#define PosADC4_NegADC2_X1		0b00011100
#define PosADC5_NegADC2_X1		0b00011101
#define SingleVGB				0b00011110   // 1.22 volt
#define SingleGND				0b00011111	 // 0 volt


#define RightADCAdjustResult *((volatile u16*) 0x24) // to Return The Value of Right Adjust 


u8 ADC_Initialliztion (u8 VREF, u8 adjust, u8 DivisionFactor);


#define BusyError 3		// // to return ERROR because ADC is Working NOW
u8 ADC_StartConversionSynch (u8 Channel, u8* SynchReading);
   /** You MUST Enable The Global Interrupt Before Calling this Function **/
u8 ADC_StartConversionAsynch (u8 Channel, u8* AsynchReading, void(*NotificationFunction)(void));

#endif