/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  main.c
 *        \brief  Toggle the onboard red LED, whenever switch 1 is pressed. On and off times
 *								are user defined.
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "stdint.h"
#include "TM4C123GH6PM.h"
#include "gpio.h"
#include "SysTick.h"
#include "IntCtrl.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define FALSE 0
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static volatile uint32_t time = 0; 
static volatile uint32_t flag = 0;
static volatile uint32_t onTime = 0;		//ontime in seconds
static volatile uint32_t offTime = 0;	//offtime in secnds


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void blink_control (volatile uint32_t on, volatile uint32_t off);
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
int main()
{
	PORTF_Init();
	IntCtrl_Init();
	GPIO_PORTF_DATA = 0x0;		
	SysTick_1s();
	while(1)
	{
		if(flag == 1)
		{
			blink_control(onTime, offTime);
			
		}
		
	}	
}

void SysTick_Handler(void)
{
	time--;
}

void GPIOF_Handler(void)
{
	GPIO_PORTF_ICR |= PIN4 ;			//clear interrupt flag
	flag = 1;
	onTime = onTime + 2;
	offTime = offTime + 2;
	time = offTime;
}

/******************************************************************************
* \Syntax          : Std_ReturnType blink_control(volatile uint32_t on, volatile uint32_t off)        
* \Description     : Checks if the number of SysTick interrupts is equal to the                                     
*                    number of seconds for the LED ontime and offtime                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : on   Ontime in seconds as defined by the user
*									 : off	Offtime in seconds as defined by the user
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void blink_control (volatile uint32_t on, volatile uint32_t off)
{
	if(time == FALSE) {
		GPIO_PORTF_DATA ^= PIN1;								//toggle red LED
		if((GPIO_PORTF_DATA & PIN1) == 0x00){ 
			time = off;
		} else {
			time = on;
		}
	}				
}
/**********************************************************************************************************************
 *  END OF FILE: main.c
 *********************************************************************************************************************/
