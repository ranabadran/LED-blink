/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <IntCtrl.h>
 *       Module:  -
 *
 *  Description:  <Header file for NVIC and SCB>     
 *  
 *********************************************************************************************************************/
#ifndef IntCtrl_h
#define IntCtrl_h


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "stdint.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define NVIC_EN0_R	 		(*((volatile uint32_t *) 0xE000E100))
#define NVIC_PRI7_R 		(*((volatile uint32_t *) 0xE000E41C))
#define SCB_APINT_R			(*((volatile uint32_t *) 0xE000ED0C))
	
#define SCB_groupPri_8_subPri_1		(0x05FA0400)  //3 bits for group priority and 0 bit  for sub priority
#define SCB_groupPri_4_subPri_2		(0x05FA0500)  //2 bits for group priority and 1 bit  for sub priority
#define SCB_groupPri_2_subPri_4		(0x05FA0600)  //1 bit  for group priority and 2 bits for sub priority
#define SCB_groupPri_1_subPri_8		(0x05FA0700)  //0 bit  for group priority and 3 bits for sub priority

#define PRIORITY_LEVEL_0 0
#define PRIORITY_LEVEL_1 1
#define PRIORITY_LEVEL_2 2
#define PRIORITY_LEVEL_3 3
#define PRIORITY_LEVEL_4 4
#define PRIORITY_LEVEL_5 5
#define PRIORITY_LEVEL_6 6
#define PRIORITY_LEVEL_7 7

#define IRQ_GPIOF 30

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void IntCtrl_Init (void);

#endif  /* IntCtrl_h */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.h
 *********************************************************************************************************************/




