/*
 * TimersAndInterrupts.c
 *
 * Created: 20/01/2020 04:51:00 م
 *  Author: mo
 */ 

#include "avr/interrupt.h"
#include "led.h"
#include "ledConfig.h"
#include "Interrupts.h"
uint8_t Prescaler_Value=0;
volatile uint32_t u32_ovf_counter=0; 
int main(void)
{	
timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_8 ,0,0,T0_INTERRUPT_NORMAL);
Led_Init(LED_1);
Led_Init(LED_2);
Led_Init(LED_3);	
    while(1)
    {
Led_On(LED_1);
timer0Start();
timer0DelayMs(1000);
Led_Off(LED_1);	
Led_On(LED_3);
timer0Start();
timer0DelayMs(1000);
Led_Off(LED_3);
Led_On(LED_2);
timer0Start();
timer0DelayMs(1000);
Led_Off(LED_2);
}
}
void __vector_11(void) __attribute__((signal,__INTR_ATTRS));
void __vector_11(void)
{
	u32_ovf_counter++;
}/*
ISR(TIMER0_OVF_vect)
{
	u32_ovf_counter++;
}*/