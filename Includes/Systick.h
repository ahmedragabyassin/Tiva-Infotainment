/*
 * Systick.h
 *
 *  Created on: Mar 12, 2019
 *      Author: Ahmed Hamdy
 */

#ifndef SYSTICK_SYSTICK_H_
#define SYSTICK_SYSTICK_H_

/************************************************************************/
/* Function: SysTick_INIT                                               */
/* @param: Tick                                                         */
/* return: void                                                         */
/* Description: function Initialize Systick                             */
/************************************************************************/
void SysTick_INIT(uint32_t Tick);

/************************************************************************/
/* Function: IntMasterEnable                                            */
/* @param: void                                                         */
/* return: void                                                         */
/* Description: function Enable Master Interrupt                        */
/************************************************************************/
void IntMasterEnable(void);

/************************************************************************/
/* Function: SysTickIntEnable                                           */
/* @param: void                                                         */
/* return: void                                                         */
/* Description: function Enable SysTick Interrupt                       */
/************************************************************************/
void SysTickIntEnable(void);

/************************************************************************/
/* Function: SysTickEnable                                              */
/* @param: void                                                         */
/* return: void                                                         */
/* Description: function Enable SysTick                                 */
/************************************************************************/
void SysTickEnable(void);


/*Constants*/
/*PORTF*/
#define PORTF_ENABLE         0x20
#define PORTF_LEDS_DIR       0x0E
#define PORTF_LEDS_DEN       0x0E
#define TOGGLE_LED           0x0E

#endif /* SYSTICK_SYSTICK_H_ */
