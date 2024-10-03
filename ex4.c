#include "main.h"
#include "hardware.h"
#include "system.h"

void main()
{
    init_hw();                          /*Initialize HW (IOs ports)*/

    bool toggleInterval = false;        /*Variable used to control the interval time*/
    int16 interval = 1000;              /*Interval in ms*/

    delay_ms(100);                      /*power up delay, wait a 100ms*/

    while(1)                            /*main infinite loop*/
    {
        if (!input(PIN_B0)) {           
            while(!input(PIN_B0)) {     /*While PB1 pressed...*/
                output_toggle(PIN_C0);
                delay_ms(500);
            }
        } else {
            output_low(PIN_C0);
        }

        if(input(PIN_B1)) {
            while(input(PIN_B1))    {}  /*while still pressed, just wait...*/
            if(toggleInterval) {
                interval = 2000;
            } else {
                interval = 1000;
            }
        }

        output_toggle(PIN_C1);
        delay_ms(interval);

        // else {
        //     output_low(PIN_C0);
        // }

        // if (!input(PIN_B0))             /*PB1 pressed?*/
        // {
        //     output_high(PIN_C0);
        // }
        // else                            /*PB1 released?*/
        // {
        //     output_low(PIN_C0);
        // }

        // if (input(PIN_B1))              /*PB2 pressed?*/
        // {
        //     while(input(PIN_B1))    {}  /*while still pressed, just wait...*/
        //     output_toggle(PIN_C1);      /*Do it!*/
        // }
    }
}
