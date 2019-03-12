/*
 * Debouncing.c
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-071
 */
#include "../Includes/Debouncing.h"

/* Global Debouncing Flag */
uint8 Deb_Flag = ZERO;
uint8 Deb  = ZERO;


/************************************************************************/
/* Function: Debouncing_Task                                             */
/* @param: void                                                         */
/* return: void                                                         */
/* Description: check for Debouncing                      */
/************************************************************************/
void Debouncing_Task(void)
{

    /* Check for value input read from the rows*/
    if(!GPIOPinRead(ROW_BASE_PORT, ROW1_PIN | ROW2_PIN | ROW3_PIN ))
    {

        Deb++;

        if(Deb>=NUM_5)
        {
            Deb_Flag=NUM_1;        /* Set the debouncing flag */
        }

    }
    else
    {
        Deb = ZERO;
        Deb_Flag= ZERO;     /* reset the debouncing flag */
    }





}




