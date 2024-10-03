#include <18F46K22.h>
#device ADC=10      /*ADC resulution in bits*/
#device ANSI        /*ANSI C*/

/*Chip configuration*/
#FUSES NOWDT                   //No Watch Dog Timer
#FUSES PUT                     //Power Up Timer
#FUSES NOBROWNOUT              //No brownout reset
#FUSES BORV29                  //Brownout reset at 2.85V
#FUSES TIMER3B5                //Timer3 Clock In is on pin B5
#FUSES LVP                  //Low Voltage Programming

#use delay(internal=64000000)

#use fast_io(ALL)
