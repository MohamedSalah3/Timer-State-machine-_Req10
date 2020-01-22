/*
 * Interrupts.c
 *
 * Created: 21/01/2020 01:18:13 م
 *  Author: mo
 */ 

#include "Interrupts.h"

void G_interrupt_Enable(void)
{
//SET_BIT(SREG,7);	
SREG |=(1<<7);
}

void G_interrupt_Disable(void)
{

SREG &=(~(SREG,7));
}
/*
void __vector_16(void) __attribute__((signal,__INTR_ATTRS));
void __vector_16(void)
{
u32_ovf_counter++;
}
*/



