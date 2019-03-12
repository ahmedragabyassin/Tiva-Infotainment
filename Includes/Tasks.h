/*
 * Tasks.h
 *
 *  Created on: Mar 12, 2019
 *      Author: Ahmed Hamdy
 */

#ifndef INCLUDES_TASKS_H_
#define INCLUDES_TASKS_H_


/*Constants*/
/*PORTF*/
#define PORTF_ENABLE         0x20
#define PORTF_LEDS_DIR       0x0E
#define PORTF_LEDS_DEN       0x0E
#define TOGGLE_LED           0x0E
void Init_Tasks(void);
void Led_Task(void);


#endif /* INCLUDES_TASKS_H_ */
