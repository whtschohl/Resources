#include "driverlib.h"
#include "device.h"
#include "board.h"
//
// Main
//
void main(void)
{
   // Device Initialization
   Device_init();
   //
   // Initializes Peripheral Interrupt Expansion module (PIE) and clears PIE registers. Disables CPU interrupts.
   //
   Interrupt_initModule();
   //
   // Initializes the PIE vector table with pointers to the shell Interrupt
   // Service Routines (ISR).
   //
   Interrupt_initVectorTable();
   Board_init();
   //
   // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
   //
   EINT;
   ERTM;
   while(1)
   {
   }	
}

__interrupt void INT_Led_Toggle_Timer_ISR(void)
{
    GPIO_togglePin(myBoardLED0_GPIO);
    GPIO_togglePin(myBoardLED1_GPIO);
    Interrupt_clearACKGroup(INT_Led_Toggle_Timer_INTERRUPT_ACK_GROUP);
}
