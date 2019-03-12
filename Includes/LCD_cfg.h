/*
 * LCD_cfg.h
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-057
 */

#ifndef INCLUDES_LCD_CFG_H_
#define INCLUDES_LCD_CFG_H_




#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"


/**********************************************************************/
/* define mode in send data to operate in command mode or data mode   */
/**********************************************************************/

#define CMD_MODE            0
#define DATA_MODE           1


/************************************************************************/
/* LCD Commands                                                         */
/************************************************************************/
#define LCD_FOUR_BIT_TWO_LINE_MODE  0x02 /* initialize LCD in Four bits two lines mode*/
#define LCD_FOUR_BIT_DATA_MODE      0x28 /* Four Bit mode */
#define LCD_EIGHT_BIT_MODE          0x38 /* Eight Bit mode */
#define LCD_CLEAR                   0x01 /* clear screen */
#define LCD_SET_CURSOR_LOCATION     0x80 /* Set cursor at the first line */
#define LCD_CURSOR_ON               0x0E /* display cursor */
#define LCD_CURSOR_OFF              0x0C /* turn cursor off*/
#define LCD_SHIFT_CURSOR_RIGHT      0x14 /* shift cursor right */
#define LCD_CURSOR_LINE_ONE         0x80 /* set cursor at the first line*/
#define LCD_CURSOR_LINE_TWO         0xC0 /* set cursor to the second line*/
#define LCD_MASK_HIGH_NIBBLES       0x0F /* mask higher nibbles */
#define LCD_MASK_LOW_NIBBLES        0xF0 /* mask lower nibbles */


/************************************************************************/
/* LCD Config Pin                                                       */
/************************************************************************/
/**********************************************************************/
/* define LCD PORTs BASE                                              */
/**********************************************************************/

#define LCD_CONT_PORT_BASE            GPIO_PORTA_BASE
#define LCD_DATA_PORT_BASE            GPIO_PORTC_BASE
/************************************************************************/
/* LCD control pins                                                     */
/************************************************************************/
#define LCD_RS                  GPIO_PIN_2
#define LCD_RW                  GPIO_PIN_3
#define LCD_E                   GPIO_PIN_3
/************************************************************************/
/* LCD Data pins                                                        */
/************************************************************************/
#define LCD_D0
#define LCD_D1
#define LCD_D2
#define LCD_D3
#define LCD_D4                  GPIO_PIN_4
#define LCD_D5                  GPIO_PIN_5
#define LCD_D6                  GPIO_PIN_6
#define LCD_D7                  GPIO_PIN_7

/************************************************************************/
/* To set cursor location                                               */
/************************************************************************/
/************************************************************************/
/* define number of rows in LCD                                         */
/************************************************************************/
#define LCD_ROW1                0
#define LCD_ROW2                1
#define LCD_ROW3                2
/************************************************************************/
/* define number of columns                                             */
/************************************************************************/
#define LCD_COL1                0
#define LCD_COL2                1
#define LCD_COL3                2
#define LCD_COL4                3
#define LCD_COL5                4
#define LCD_COL6                5
#define LCD_COL7                6
#define LCD_COL8                7
#define LCD_COL9                8
#define LCD_COL10               9
#define LCD_COL11               10
#define LCD_COL12               11
#define LCD_COL13               12
#define LCD_COL14               13
#define LCD_COL15               14
#define LCD_COL16               16


/************************************************************************/
/* DEFINATIONS FOR BITS USED TO GET COMMAND AND DATA                    */
/* used to hold the value of bits in command or data                    */
/************************************************************************/
#define LCD_BIT0                0
#define LCD_BIT1                1
#define LCD_BIT2                2
#define LCD_BIT3                3
#define LCD_BIT4                4
#define LCD_BIT5                5
#define LCD_BIT6                6
#define LCD_BIT7                7





#endif /* INCLUDES_LCD_CFG_H_ */
