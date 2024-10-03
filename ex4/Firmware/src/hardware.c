#include "main.h"
#include "hardware.h"

/**
 * 
 */
void init_io_ports(void)
{
    set_tris_a(0x00);    /*A: all ouputs*/
    output_a(0x00);      /*all ZEROs*/

    set_tris_b(0x03);    /*B: B0, B1: inputs only*/
    output_b(0x00);      /*all ZEROs*/

    set_tris_c(0x00);    /*C: all ouputs*/
    output_c(0x00);      /*all ZEROs*/

    set_tris_d(0x00);    /*D: all ouputs*/
    output_d(0x00);      /*all ZEROs*/

    set_tris_e(0x08);    /*E*/
    output_e(0x00);      /*all ZEROs*/
}
///////////////////////////////////////////////////////////////////////////////
/**
 * 
 * @return 
 */
bool init_hw(void)
{
    init_io_ports();

    /*list other things (if any):*/
    
    return true;
}
