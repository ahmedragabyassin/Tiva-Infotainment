/*
 * Keypad.h
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-071
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_



#include "Keypad_cfg.h"
#include "Includes/BitwiseOperations.h"
#include "Includes/ChallengeCommonDef.h"
#include "Includes/CommonDelays.h"
#include "Includes/CommonDefinations.h"
#include "Includes/CommonNumbers.h"
#include "Includes/types.h"

/************************************************************************/
/* Function: KeyPad Init                                                */
/* @param: void                                                         */
/* return: void                                                         */
/* Description: Initialize keypad pins directions                      */
/************************************************************************/

void Keypad_Init(void);


/************************************************************************/
/* Function: Keypad_Task                                                */
/* @param: void                                                         */
/* return: uint8                                                         */
/* Description: Task to return the key pressed                           */
/************************************************************************/
uint8 Keypad_Task(void);

#endif /* KEYPAD_H_ */
