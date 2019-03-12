/*
 * LCD.c
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-057
 */

#include "../Includes/LCD_cfg.h"
#include "../Includes/LCD.h"
#include "tm4c123gh6pm.h"


/************************************************************************/
/* Function: LCD Init                                                   */
/* @param: void                                                         */
/* return: void                                                         */
/* Description: function Initialize LCD                                 */
/************************************************************************/
void LCD_Init(void)
{
    /* Config Control Pins and set their direction*/

    /* Enable the GPIOA peripheral */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    /* Wait for the GPIOA module to be ready.*/
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA))
    {
    }
    /* Set pins 2 and 3 and 4 as output.*/
    GPIOPinTypeGPIOOutput(LCD_CONT_PORT_BASE, LCD_RS | LCD_E | LCD_RW);

    /*config data pins direction */
    /* Enable the GPIOA peripheral */
   SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);

  /* Wait for the GPIOA module to be ready.*/
   while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC))
   {
   }
   /* Set pins 4 and 5 and 6 and 7 as output.*/
   GPIOPinTypeGPIOOutput(LCD_DATA_PORT_BASE, LCD_D4 | LCD_D5 | LCD_D6 | LCD_D7);

    /* Initialize LCD in Four bits Mode and two lines */
    LCD_SendCommand(LCD_FOUR_BIT_TWO_LINE_MODE, CMD_MODE);
    LCD_SendCommand(LCD_FOUR_BIT_DATA_MODE, CMD_MODE);
    /* Clear LCD and set cursor at the beginning */
    LCD_SendCommand(LCD_CURSOR_ON, CMD_MODE);
    LCD_SendCommand(LCD_CLEAR, CMD_MODE);


}


/************************************************************************/
/* Function: LCD Send Command                                           */
/* @param: command, command to be sent to LCD                           */
/* @param: type, send data of command to set RS                         */
/* return: void                                                         */
/* Description: function take hexa command                              */
/************************************************************************/
void LCD_SendCommandData(uint8 Command, uint8 type)
{

    /* Switch case to check if command mode or data mode */
    switch(type)
    {
        case CMD_MODE:
            /*Config Control Reg*/
           /* RS set to low to send command*/
            GPIOPinWrite(LCD_CONT_PORT_BASE, LCD_RS, LOW);
            /* RW set to write */
            GPIOPinWrite(LCD_CONT_PORT_BASE, LCD_RW, LCD_RW);
            /* delay 1ms */
            SysCtlDelay(200);
            /* Set EN pin to high */
            GPIOPinWrite(LCD_CONT_PORT_BASE, LCD_E, LCD_E);
            /* delay 1ms */
            SysCtlDelay(200);
               /* Send Command Most significant bit first */
            GPIOPinWrite(LCD_DATA_PORT_BASE, LCD_D4, (GET_BIT(Command,LCD_BIT4)>>LCD_BIT4)<<LCD_BIT4);
            GPIOPinWrite(LCD_DATA_PORT_BASE, LCD_D5, (GET_BIT(Command,LCD_BIT5)>>LCD_BIT4)<<LCD_BIT5);
            GPIOPinWrite(LCD_DATA_PORT_BASE, LCD_D6, (GET_BIT(Command,LCD_BIT6)>>LCD_BIT4)<<LCD_BIT6);
            GPIOPinWrite(LCD_DATA_PORT_BASE, LCD_D7, (GET_BIT(Command,LCD_BIT7)>>LCD_BIT4)<<LCD_BIT7);

                /* delay 1ms */
            SysCtlDelay(2000);
               /* latch data by writing low on EN pin */
            GPIOPinWrite(LCD_CONT_PORT_BASE, LCD_E, LOW);
                /* delay 1ms */
            SysCtlDelay(2000);
               /* set EN pin */
            GPIOPinWrite(LCD_CONT_PORT_BASE, LCD_E, LCD_E);
                /* delay 1ms */
            SysCtlDelay(2000);
                /*Send Least Significant bit */
            GPIOPinWrite(LCD_DATA_PORT_BASE, LCD_D4, (GET_BIT(Command,LCD_BIT0)>>LCD_BIT0)<<LCD_BIT4);
            GPIOPinWrite(LCD_DATA_PORT_BASE, LCD_D5, (GET_BIT(Command,LCD_BIT1)>>LCD_BIT1)<<LCD_BIT5);
            GPIOPinWrite(LCD_DATA_PORT_BASE, LCD_D6, (GET_BIT(Command,LCD_BIT2)>>LCD_BIT2)<<LCD_BIT6);
            GPIOPinWrite(LCD_DATA_PORT_BASE, LCD_D7, (GET_BIT(Command,LCD_BIT3)>>LCD_BIT3)<<LCD_BIT7);

                /* delay 1ms */
             SysCtlDelay(200);
                /* latch data by writing low on EN pin */
             GPIOPinWrite(LCD_CONT_PORT_BASE, LCD_E, LOW);
                /* delay 1ms */
             SysCtlDelay(200);
                break;
        case DATA_MODE:
                    /*Config Control Reg*/
                   /* RS set to low to send command*/
              GPIOPinWrite(LCD_CONT_PORT_BASE, LCD_RS, LCD_RS);
                    /* RW set to write */
              GPIOPinWrite(LCD_CONT_PORT_BASE, LCD_RW, LCD_RW);
                    /* delay 1ms */
              SysCtlDelay(2000);
                    /* Set EN pin to high */
              GPIOPinWrite(LCD_CONT_PORT_BASE, LCD_E, LCD_E);
                    /* delay 1ms */
              SysCtlDelay(2000);
                       /* Send Command Most significant bit first */
              GPIOPinWrite(LCD_DATA_PORT_BASE, LCD_D4, (GET_BIT(Command,LCD_BIT4)>>LCD_BIT4)<<LCD_BIT4);
              GPIOPinWrite(LCD_DATA_PORT_BASE, LCD_D5, (GET_BIT(Command,LCD_BIT5)>>LCD_BIT4)<<LCD_BIT5);
              GPIOPinWrite(LCD_DATA_PORT_BASE, LCD_D6, (GET_BIT(Command,LCD_BIT6)>>LCD_BIT4)<<LCD_BIT6);
              GPIOPinWrite(LCD_DATA_PORT_BASE, LCD_D7, (GET_BIT(Command,LCD_BIT7)>>LCD_BIT4)<<LCD_BIT7);

                        /* delay 1ms */
              SysCtlDelay(2000);

                       /* latch data by writing low on EN pin */
              GPIOPinWrite(LCD_CONT_PORT_BASE, LCD_E, LOW);
                        /* delay 1ms */
              SysCtlDelay(2000);
                       /* set EN pin */
              GPIOPinWrite(LCD_CONT_PORT_BASE, LCD_E, LCD_E);
                        /* delay 1ms */
              SysCtlDelay(2000);
                        /*Send Least Significant bit */
              GPIOPinWrite(LCD_DATA_PORT_BASE, LCD_D4, (GET_BIT(Command,LCD_BIT0)>>LCD_BIT0)<<LCD_BIT4);
              GPIOPinWrite(LCD_DATA_PORT_BASE, LCD_D5, (GET_BIT(Command,LCD_BIT1)>>LCD_BIT1)<<LCD_BIT5);
              GPIOPinWrite(LCD_DATA_PORT_BASE, LCD_D6, (GET_BIT(Command,LCD_BIT2)>>LCD_BIT2)<<LCD_BIT6);
              GPIOPinWrite(LCD_DATA_PORT_BASE, LCD_D7, (GET_BIT(Command,LCD_BIT3)>>LCD_BIT3)<<LCD_BIT7);
                        /* delay 1ms */
              SysCtlDelay(2000);
                        /* latch data by writing low on EN pin */
              GPIOPinWrite(LCD_CONT_PORT_BASE, LCD_E, LOW);
                        /* delay 1ms */
              SysCtlDelay(2000);
              break;
    }
}


