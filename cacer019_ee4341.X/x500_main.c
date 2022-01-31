/* ************************************************************************** */
/** x500_main.c

  @Description
    Main file.
 
 */
/* ************************************************************************** */

#include "io_setup.h"


void setup(void)
{
    io_setup();
    // include any other setup functions here
}

void uart1_setup(void)
{   
    // BRGH OFF; UEN TX_RX; 
    U1MODEbits.BRGH = 0;
    U1MODEbits.UEN = 0b11;
    //BaudRate = 9600; Frequency = 40000000 Hz; BRG 259; 
    U1BRG = 259;
    U1STAbits.UTXEN = 1; // Enable the TX pin
    U1STAbits.URXEN = 1; // Enable the RX pin
    
    // Enable transmit
    // Enable receive
    
    // Enable UART (ON bit)
    U1MODEbits.ON = 1; 
    
    __XC_UART = 1;              // Code is configured to use UART1 for printf()
}


int main(void)
{
    setup();
    uart1_setup();
    delay(1);                  // 100 ms delay as precaution
    
    while(1)
    { 
        delay(1);
        buttons();
    }

    return 0;
}


/* *****************************************************************************
 End of File
 */
