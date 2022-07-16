/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/*********************************** SWC: External Interrupt ***********************************/
/***********************************************************************************************/
/***********************************************************************************************/


/**																							   **/
/** Define The Interrupt Change		-->		FallingEdge or RisingEdge or LowLevel or AnyChange **/
/** Define The Interrupt State		-->		Enabled or Disabled								   **/
/**																							   **/


#ifndef EXTI_Config
#define EXTI_Config

#define INT0_Sense		FallingEdge 
#define INT0_State		Enabled

#define INT1_Sense		FallingEdge
#define INT1_State		Enabled 

#define INT2_Sense		FallingEdge
#define INT2_State		Enabled

#endif