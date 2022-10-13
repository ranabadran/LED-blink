/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <gpio.h>
 *       Module:  -
 *
 *  Description:  <GPIO Driver>     
 *  
 *********************************************************************************************************************/
#ifndef gpio_h
#define gpio_h

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include <stdint.h>

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


#define SYSCTL_RCGCGPIO 	(*((volatile uint32_t *) 0x400FE608))
	
#define GPIO_PORTF_DATA		(*((volatile uint32_t *) 0x40025038))
#define GPIO_PORTF_DIR 		(*((volatile uint32_t *) 0x40025400))
#define GPIO_PORTF_IS			(*((volatile uint32_t *) 0x40025404))
#define GPIO_PORTF_IBE		(*((volatile uint32_t *) 0x40025408))
#define GPIO_PORTF_IEV		(*((volatile uint32_t *) 0x4002540C))
#define GPIO_PORTF_IM			(*((volatile uint32_t *) 0x40025410))
#define GPIO_PORTF_RIS		(*((volatile uint32_t *) 0x40025418))
#define GPIO_PORTF_MIS		(*((volatile uint32_t *) 0x40025414))
#define GPIO_PORTF_ICR		(*((volatile uint32_t *) 0x4002541C))
#define GPIO_PORTF_AFSEL	(*((volatile uint32_t *) 0x40025420))
#define GPIO_PORTF_PUR		(*((volatile uint32_t *) 0x40025510))
#define GPIO_PORTF_DEN		(*((volatile uint32_t *) 0x4002551C))
#define GPIO_PORTF_LOCK		(*((volatile uint32_t *) 0x40025520))
#define GPIO_PORTF_CR			(*((volatile uint32_t *) 0x40025524))

	

	
#define GPIO_PORTF_CLK_EN	 (0x20)

#define PIN0	(0x01)
#define PIN1	(0x02)
#define PIN2	(0x04)
#define PIN3	(0x08)
#define PIN4	(0x10)
#define PIN5 	(0x20)
#define PIN6 	(0x40)
#define PIN7 	(0x80)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void PORTF_Init(void);
void GPIOF_Handler(void);



#endif  /* gpio_h */

/**********************************************************************************************************************
 *  END OF FILE: gpio.h
 *********************************************************************************************************************/
 