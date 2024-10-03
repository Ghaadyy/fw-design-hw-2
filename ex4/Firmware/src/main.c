#include "main.h"
#include "hardware.h"
#include "system.h"

void main()
{
    init_hw();                          /*Initialize HW (IOs ports)*/

    delay_ms(100);                      /*power up delay, wait a 100ms*/

	while(1)                            /*main infinite loop*/
    {
        if (!input(PIN_B0))             /*PB1 pressed?*/
        {
            output_high(PIN_C0);
        }
        else                            /*PB1 released?*/
        {
            output_low(PIN_C0);
        }

        if (input(PIN_B1))              /*PB2 pressed?*/
        {
            while(input(PIN_B1))    {}  /*while still pressed, just wait...*/
            output_toggle(PIN_C1);      /*Do it!*/
        }
        
    }
}
