

/**
 * main.c
 */
#include "Includes/TM4C123GH6PM.h"
#include "Includes/types.h"
#include "Includes/Tasks.h"
#include "Includes/Scheduler.h"
#include "Includes/Systick.h"
#include <stdint.h>
#include <stdbool.h>


void main(void)
{
    /*Interrupt comes every one second*/
    Init_Tasks ();


    /*Initialize The scheduler only one task*/
    schedulerInit(1);

    /*Initialize task0*/
    Tasks Task0;
    Task0.ptr_func = Led_Task;
    Task0.Task_Periodicity = 1000;
    Task0.Remaining_Ticks  = 1000;
    Task0.Piriority = 1;

    /*Adding Our Tasks*/
    if (scheduler_Add_Task(&Task0))
    {
        /*Task is added*/
    }
    else
    {
        /*No place to add Task*/
    }

    /*Start the OS scheduler*/
    schedulerStart();

}
