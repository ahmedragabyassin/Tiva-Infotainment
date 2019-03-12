/*
 * Tasks.c
 *
 *  Created on: Mar 12, 2019
 *      Author: Ahmed Hamdy
 */


#include "Includes/tasks.h"
#include "Includes/types.h"
#include "Includes/scheduler.h"
#include "Includes/TM4C123GH6PM.h"

/*********************** Init_Tasks() *************************
*Parameters:
*           I/P: NOTHING
*           O/P: NOTHING
*           I/O: NOTHING
*Return: Nothing
*Description: Function to Set LED0
**************************************************************/
void Init_Tasks(void)
{
    /*Initialize PORTF*/

    /*Enable clock to PortF*/
    SYSCTL->RCGCGPIO|= PORTF_ENABLE ;
    /*Set LEDs PiNs as output*/
    GPIOF->DIR = PORTF_LEDS_DIR;
    /*set LEDs PINS digital function*/
    GPIOF->DEN = PORTF_LEDS_DEN;
}


/*********************** Led0_Task() *************************
*Parameters:
*           I/P: NOTHING
*           O/P: NOTHING
*           I/O: NOTHING
*Return: Nothing
*Description: Function to Set LED0
**************************************************************/
void Led_Task(void)
{
   /*Toggle LED*/
   GPIOF->DATA^= TOGGLE_LED;
}
