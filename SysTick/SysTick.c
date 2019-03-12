/*
 * SysTick.c
 *
 *  Created on: Mar 12, 2019
 *      Author: Ahmed Hamdy
 */

#include <Includes/types.h>
#include <stdint.h>
#include "Includes/Systick.h"
#include "Includes/TM4C123GH6PM.h"
#include "inc/hw_types.h"
#include "Includes/Scheduler.h"

/*Array of pointer to functions which containes Tasks*/
extern void(*ptr[MAX_TASK_NUMBER])(void);

/*Pointer to function which we use in call back function principle*/
void(*call_back)(void);

/************************************************************************/
/* Function: SysTick_INIT                                               */
/* @param: Tick                                                         */
/* return: void                                                         */
/* Description: function Initialize Systick                             */
/************************************************************************/
void SysTick_INIT(uint32_t Tick )
{

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


/******************** set_call_back() ************************
*Parameters:
*           I/P: Pointer To Function
*           O/P: NOTHING
*           I/O: NOTHING
*Return: Nothing
*Description: This function sets call back pointer to function
              to equal the input pointer to function
**************************************************************/
void set_call_back(void(*ptr)(void))
{
    call_back=ptr;
}



/************************************************************************/
/* Function: SysTickIntHandler                                          */
/* @param: void                                                         */
/* return: void                                                         */
/* Description: Interrupt handler for the for Systick interrupt.                             */
/************************************************************************/
void
SysTickIntHandler(void)
{
    call_back();
}


