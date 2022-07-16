/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/*********************************** SWC: External Interrupt ***********************************/
/***********************************************************************************************/
/***********************************************************************************************/


/**																							                                               **/
/** Define The Interrupt Change		-->		FallingEdge or RisingEdge or LowLevel or AnyChange     **/
/** Define The Interrupt PIN		-->		INT0 e or INT1 or INT2			                  				   **/
/**																							                                               **/


#ifndef EXTI_Interface
#define EXTI_Interface

#define FallingEdge	1
#define RisingEdge	2
#define LowLevel	3
#define AnyChange	4

#define INT_0	1
#define INT_1	2
#define INT_2	3

#define Enabled		1
#define Disabled	2

/** Pre-build Configuration **/
void EXTI_INT1 (void);

void EXTI_INT0 (void);

void EXTI_INT2 (void);

/** Post-build Configuration **/
u8 EXTI_INT1_Sense (u8 Sense, u8 State);

u8 EXTI_INT0_Sense (u8 Sense, u8 State);

u8 EXTI_INT2_Sense (u8 Sense, u8 State);

/** Call Back Function **/
u8 EXTI_INTn_CallBack (u8 INT_n, void (*INT0Function)(void));

#endif
