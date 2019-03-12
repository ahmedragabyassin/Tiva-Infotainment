/*
 * Scheduler.h
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-039
 */

#ifndef INCLUDES_SCHEDULER_H_
#define INCLUDES_SCHEDULER_H_

/*Prototype of array of structure*/

#define MAX_TASK_NUMBER 4
typedef struct
{
    void(*ptr_func)(void); /*Pointer to function*/
    uint32 Task_Periodicity;    /*Task periodicity*/
    uint32 Remaining_Ticks;     /*Remaining Ticks*/
    uint8 Piriority;
}Tasks;

/*array of structures*/
Tasks Tasks_Arr[MAX_TASK_NUMBER];

/*Scheduler APIs*/
extern void schedulerInit(uint32 Task_Num);
extern void schedulerStart();
extern uint8 scheduler_Add_Task(Tasks *S_ptr);
extern void TTC_Scheduler(void);
extern void set_flag(void);


/*Constants*/
#define INITIAL 0
#define ZERO    0
#define ONE     1

/*States*/
#define TRUE  1
#define FALSE 0
#define HIGH  1
#define LOW   0



#endif /* INCLUDES_SCHEDULER_H_ */
