

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "../Includes/types.h"


/***********************************************************************/
/* Function name :- UART_init
 * Function job :- initialize uart
 * Function inputs :- N/A
 * Function outputs :- N/A
/**********************************************************************/
void UART0_init(void);

/**************************************************************************************************/
/*Function Name :- UART_Transmit                                                                  */
/*Function job   :- sending byte bu uart                                                          */
/*Function inputs :- sending character                                                            */
/*Function outputs :- N/A                                                                         */
/**************************************************************************************************/
void UART0_Transmit(uint8 data);

/**************************************************************************************************/
/*Function Name :- UART_receive                                                               */
/*Function job   :-receiving byte by uart                                                         */
/*Function inputs :- N/A                                                                          */
/*Function outputs :-byte received                                                               */
/**************************************************************************************************/

uint8 UART0_receive(void);
