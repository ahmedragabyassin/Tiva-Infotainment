/*
 * SysTick.c
 *
 *  Created on: Mar 12, 2019
 *      Author: Ahmed Hamdy
 */

#include <stdint.h>
#include "Includes/Systick.h"
#include "Includes/TM4C123GH6PM.h"
#include "inc/hw_types.h"


/************************************************************************/
/* Function: SysTick_INIT                                               */
/* @param: Tick                                                         */
/* return: void                                                         */
/* Description: function Initialize Systick                             */
/************************************************************************/
void SysTick_INIT(uint32_t Tick )
{
    /*Initialize PORTF*/

    /*Enable clock to PortF*/
    SYSCTL->RCGCGPIO|= PORTF_ENABLE ;
    /*Set LEDs PiNs as output*/
    GPIOF->DIR = PORTF_LEDS_DIR;
    /*set LEDs PINS digital function*/
    GPIOF->DEN = PORTF_LEDS_DEN;


    /*Configure SysTick*/

    /*Load Register with Tick value*/
    SysTick->LOAD = Tick;

   /* Enable interrupts to the processor.*/
   IntMasterEnable();

    /*Enable the SysTick Interrupt.*/
   SysTickIntEnable();

    /* Enable SysTick.*/
   SysTickEnable();


}




