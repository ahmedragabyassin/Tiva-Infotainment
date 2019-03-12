/*
 * Keypad.c
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-071
 */

#include "Keypad.h"


/************************************************************************/
/* Function: Keypad_Init                                                */
/* @param: void                                                         */
/* return: void                                                         */
/* Description: Initialize keypad pins directions                       */
/************************************************************************/

void Keypad_Init(void)
{

    /* Enable the GPIO port for keypad rows.                                */
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

    /* Check if the peripheral access is enabled.                           */
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB));

    /* Enable the GPIO port for keypad Columns.                             */
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD));
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    /* Check if the peripheral access is enabled.                           */

       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));



    /* SET Rows Direction Input                                               */
    GPIOPinTypeGPIOInput(ROW_BASE_PORT, ROW1_PIN);
    GPIOPinTypeGPIOInput(ROW_BASE_PORT, ROW2_PIN);
    GPIOPinTypeGPIOInput(ROW_BASE_PORT, ROW3_PIN);

    /* Activate Pull-up resistor on Rows                                    */
    GPIOPadConfigSet(ROW_BASE_PORT, ROW1_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
    GPIOPadConfigSet(ROW_BASE_PORT, ROW2_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
    GPIOPadConfigSet(ROW_BASE_PORT, ROW3_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    /* Set Columns Direction Output                                               */
    GPIOPinTypeGPIOOutput(COL_BASE_PORT, COL1_PIN);
    GPIOPinTypeGPIOOutput(COL_BASE_PORT, COL2_PIN);
    GPIOPinTypeGPIOOutput(COL3_BASE_PORT, COL3_PIN);


}


uint8 key=0;

/************************************************************************/
/* Function: Keypad_Task                                                */
/* @param: void                                                         */
/* return: uint8                                                         */
/* Description: Task to return the key pressed                           */
/************************************************************************/
uint8 Keypad_Task(void)
{

            /* Set Column1 to Low and others to High                                             */
            GPIOPinWrite(COL_BASE_PORT, COL1_PIN, LOW);
            GPIOPinWrite(COL_BASE_PORT, COL2_PIN, COL2_PIN);
            GPIOPinWrite(COL3_BASE_PORT, COL3_PIN, COL3_PIN);
            /* Check if Row1 reads a value                                             */
            if(!GPIOPinRead(ROW_BASE_PORT,ROW1_PIN))
            {
                key='1';
                return key;
            }
            /* Check if Row2 reads a value                                             */
            if(!GPIOPinRead(ROW_BASE_PORT,ROW2_PIN))
            {
                key='4';
                return key;
            }
            /* Check if Row3 reads a value                                             */
            if(!GPIOPinRead(ROW_BASE_PORT,ROW3_PIN))
            {
                key='7';
                return key;
            }
            /* Set Column2 to Low and others to High                                             */
            GPIOPinWrite(COL_BASE_PORT, COL1_PIN, COL1_PIN);
            GPIOPinWrite(COL_BASE_PORT, COL2_PIN, LOW);
            GPIOPinWrite(COL3_BASE_PORT, COL3_PIN, COL3_PIN);
            /* Check if Row1 reads a value                                             */
            if(!GPIOPinRead(ROW_BASE_PORT,ROW1_PIN))
            {
                key='2';
                return key;
            }
            /* Check if Row2 reads a value                                             */
            if(!GPIOPinRead(ROW_BASE_PORT,ROW2_PIN))
            {
                key='5';
                return key;
            }
            /* Check if Row3 reads a value                                             */
            if(!GPIOPinRead(ROW_BASE_PORT,ROW3_PIN))
            {
                key='8';
                return key;
            }

            /* Set Column3 to Low and others to High                                             */
            GPIOPinWrite(COL_BASE_PORT, COL1_PIN, COL1_PIN);
            GPIOPinWrite(COL_BASE_PORT, COL2_PIN, COL2_PIN);
            GPIOPinWrite(COL3_BASE_PORT, COL3_PIN, LOW);
            /* Check if Row1 reads a value                                             */
            if(!GPIOPinRead(ROW_BASE_PORT,ROW1_PIN))
            {
                key='3';
                return key;
            }
            /* Check if Row2 reads a value                                             */
            if(!GPIOPinRead(ROW_BASE_PORT,ROW2_PIN))
            {
                key='6';
                return key;
            }
            /* Check if Row3 reads a value                                             */
            if(!GPIOPinRead(ROW_BASE_PORT,ROW3_PIN))
            {
                key='9';
                return key;
            }

}





