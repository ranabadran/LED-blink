/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  gpio.c
 *        \brief  gpio initialization of PORTF
 *
 *      \details  Enable clock to portF. Initialize pin 1 (RED LED) and pin 4 (Switch 1).
 *								Configure interrupts for GPIO portF
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "stdint.h"
#include "gpio.h"


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
void PORTF_Init(void)
{
	SYSCTL_RCGCGPIO |= GPIO_PORTF_CLK_EN; // Enable clock to portF
	GPIO_PORTF_LOCK = 0x4C4F434B;					// Unlock GPIOCR
	GPIO_PORTF_CR = 0x01;
	GPIO_PORTF_LOCK = 0;
	GPIO_PORTF_DIR |= PIN1;								// Initialize Red LED pin (Pin1) as output
	GPIO_PORTF_DEN |= PIN1;
	GPIO_PORTF_DIR &=~ PIN4 | PIN0 ;			// Initialize Switch 1 & 2 (pin 0 & 4) as input
	GPIO_PORTF_DEN |= PIN4 | PIN0;
	GPIO_PORTF_PUR |= PIN4 | PIN0;				// Enable pullup resistor for Switch 1&2
	GPIO_PORTF_IS &=~ PIN4 | PIN0;				// Make Switch 1&2 Edge sensitive
	GPIO_PORTF_IBE &=~ PIN4 | PIN0;
	GPIO_PORTF_IEV &=~ PIN4 | PIN0;				// Negative edge trigger
	GPIO_PORTF_ICR |= PIN4 | PIN0;				// Clear any prior interrupt
	GPIO_PORTF_IM  |= PIN4 | PIN0;				// Unmask Interrupt
}

/*uint8_t get_On_Switch_State ()
{
return (GPIO_PORTF_DATA & PIN4);
}
uint8_t get_Off_Switch_State ()
{
return (GPIO_PORTF_DATA & PIN0);
}*/

/**********************************************************************************************************************
 *  END OF FILE: gpio.c
 *********************************************************************************************************************/



