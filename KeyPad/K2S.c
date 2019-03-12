/*
 * K2S.c
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-071
 */

#include "../Includes/K2S.h"

extern uint8 Deb_Flag;

uint8 Data=ZERO;

void  K2S_Transmit()
{

    if (Deb_Flag==HIGH)
    {

        Data=Keypad_Task();
        UART0_Transmit(Data);

    }

}
