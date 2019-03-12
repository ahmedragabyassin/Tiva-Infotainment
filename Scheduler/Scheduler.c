/*
 * Scheduler.c
 *
 *  Created on: Mar 12, 2019
 *      Author: Ahmed Hamdy
 */



#include "Includes/types.h"
#include "Includes/Systick.h"
//#include "tasks.h"
#include "Includes/scheduler.h"
#include <stdio.h>


static void sorting ();

/*global variable changed by more than function (program scope)*/
volatile uint8 flag = INITIAL;

volatile uint32 index = ZERO;


volatile uint32 task_num;

/****************** scheduler_Add_Task() *********************
*Parameters:
*           I/P: Pointer to function
*           O/P: NOTHING
*           I/O: NOTHING
*Return: Nothing
*Description: This Function extend the array with the new task
**************************************************************/

uint8 scheduler_Add_Task(Tasks *S_ptr)
{
    uint8 ret = TRUE;
    if (index < MAX_TASK_NUMBER)
    {
        Tasks_Arr[index].ptr_func = S_ptr->ptr_func;
        Tasks_Arr[index].Task_Periodicity = S_ptr->Task_Periodicity;
        Tasks_Arr[index].Remaining_Ticks = S_ptr->Remaining_Ticks;
        Tasks_Arr[index].Piriority = S_ptr->Piriority;

        index++;

        /*Sort the array*/
        ret = TRUE;
    }
    else
    {
        ret = FALSE;
    }
    return ret;
}

/********************** schedulerInitt() *********************
*Parameters:
*           I/P: Tasks Number, Array of Periodicities
*           O/P: NOTHING
*           I/O: NOTHING
*Return: Nothing
*Description: This Function set the periodicity of each task
              and calculate the remaining ticks
**************************************************************/

void schedulerInit(uint32 Task_Num)
{
    task_num = Task_Num;
    uint32 index_1 = INITIAL;
    for (index_1=INITIAL;index_1<Task_Num;index_1++)
    {
        Tasks_Arr[index_1].ptr_func = NULL;
        Tasks_Arr[index_1].Task_Periodicity = 0;
        Tasks_Arr[index_1].Remaining_Ticks = 0;
        Tasks_Arr[index_1].Piriority=0;
    }
}

/******************** schedulerStart() ***********************
*Parameters:
*           I/P: NOTHING
*           O/P: NOTHING
*           I/O: NOTHING
*Return: Nothing
*Description: This Function Starts the OS scheduler
**************************************************************/

void schedulerStart()
{
    /*Sort the array of task based on priorities*/
    sorting ();
    /*initialize the systick timer*/
    SysTick_INIT(15999);
    /*call the set flag function based on ISR using call back mechanism*/
    set_call_back(set_flag);
    while(TRUE)
    {
        if(flag==ONE)
        {
            flag=ZERO;
            /*Call the TCC Scheduler*/
            TTC_Scheduler();
        }
    }
}

/********************* TTC_Scheduler() ************************
*Parameters:
*           I/P: NOTHING
*           O/P: NOTHING
*           I/O: NOTHING
*Return: Nothing
*Description: This Function has the Algorithm that choose which
              task to be executed
**************************************************************/
void TTC_Scheduler(void)
{
    uint8 i = ZERO;
    for (i = ZERO; i<index;i++)
    {
        Tasks_Arr[i].Remaining_Ticks--;
        if(Tasks_Arr[i].Remaining_Ticks==ZERO)
        {
            Tasks_Arr[i].ptr_func();
            Tasks_Arr[i].Remaining_Ticks = Tasks_Arr[i].Task_Periodicity;

        }
    }
}

/*********************** set_flag () **************************
*Parameters:
*           I/P: NOTHING
*           O/P: NOTHING
*           I/O: NOTHING
*Return: Nothing
*Description: This Function Set flag to High When After
              ISR execution
**************************************************************/
void set_flag(void)
{
    flag = ONE;
}


/*********************** Sorting () **************************
*Parameters:
*           I/P: NOTHING
*           O/P: NOTHING
*           I/O: NOTHING
*Return: Nothing
*Description: This Function sort an array of structs
**************************************************************/
static void sorting ()
{
    uint32 counter1 = INITIAL, counter2 = INITIAL;
    Tasks temp;
    for(counter1 = INITIAL; counter1 < task_num; counter1++)
    {
        for (counter2 = ONE; counter2 < task_num; counter2++)
        {
            if (Tasks_Arr[counter2].Piriority < Tasks_Arr[counter2-1].Piriority)
            {
                temp = Tasks_Arr[counter2];
                Tasks_Arr[counter2] = Tasks_Arr[counter2-ONE];
                Tasks_Arr[counter2-1] = temp;
            }
            else
            {
                /*Nothing to do*/
            }
        }
    }

}
