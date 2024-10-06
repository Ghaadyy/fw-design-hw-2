#include "main.h"
#include "hardware.h"
#include "system.h"
#include <stdint.h>

bool toggle = false;      // Toggle delay from 1s to 2s (and vice-versa)
uint16_t B0_DELAY = 500;  // Delay for PIN_B0
uint16_t b1_delay = 1000; // Delay for PIN_B1

void toggle_delay()
{
    if (toggle)
    {
        b1_delay = 1000;
    }
    else
    {
        b1_delay = 2000;
    }
    toggle = !toggle;
}

void main()
{
    init_hw();     // Initialize HW (IO ports)
    delay_ms(100); // Power up delay, wait for 100ms

    while (1) // Infinite loop
    {
        if (!input(PIN_B0)) // Handle case when D1 and D2 are flashing
        {
            while (!input(PIN_B0))
            {
                /*
                    Distribute output in 500ms periods to
                    incrementally light D1 depending on D2's delay
                 */
                for (uint8_t i = 0; i < b1_delay / B0_DELAY; i++)
                {
                    output_toggle(PIN_C0);
                    delay_ms(500);
                }

                output_toggle(PIN_C1);
            }
        }
        else // D2 is only flashing
        {
            output_low(PIN_C0);
            if (input(PIN_B1))
            {
                while (input(PIN_B1))
                {
                    output_toggle(PIN_C1);
                    delay_ms(b1_delay);
                }

                toggle_delay();
            }
            else
            {
                output_toggle(PIN_C1);
                delay_ms(b1_delay);
            }
        }
    }
}