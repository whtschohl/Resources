//#############################################################################
//
// FILE:   empty_sysconfig_main.c
//
// TITLE:  Empty Pinmux Example
//
//! \addtogroup driver_example_list
//! <h1> Empty SysCfg & Driverlib Example </h1>
//!
//! This example is an empty project setup for SysConfig and Driverlib 
//! development.
//
//#############################################################################
//
//
// $Copyright:
// Copyright (C) 2025 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################


//
// Included Files
//
#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"


//
// Defines
//
#define RESULTS_BUFFER_SIZE     256 

//
// Globals
//
uint16_t myADC0Results[RESULTS_BUFFER_SIZE];   // Buffer for results
uint16_t index;                              // Index into result buffer
volatile uint16_t bufferFull;                // Flag to indicate buffer is full


//
// Main
//
void main(void)
{
	
    //
    // Initialize device clock and peripherals
    //
    Device_init();

    //
    // Disable pin locks and enable internal pull-ups.
    //
    Device_initGPIO();

    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();

    //
    // Disable sync(Freeze clock to PWM as well). GTBCLKSYNC is applicable
    // only for multiple core devices. Uncomment the below statement if
    // applicable.
    //
    // SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_GTBCLKSYNC);
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);


    //
    // Configure ePWM1, ePWM2, and TZ GPIOs/Modules
    //
    Board_init();

    //
    // Enable sync and clock to PWM
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);


    //
    // C2000Ware Library initialization
    //
    C2000Ware_libraries_init();

    //
    // Initialize results buffer
    //
    for(index = 0; index < RESULTS_BUFFER_SIZE; index++)
    {
        myADC0Results[index] = 0;
    }

    index = 0;
    bufferFull = 0;

    //
    // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
    //
    EINT;
    ERTM;

    // Enter code here

    //
    // IDLE loop. Just sit and loop forever (optional):
    //
    for(;;)
    {
    //     if (myADC0Results[index] > 2048)   // halfway of 12-bit range
    //         GPIO_writePin(myGPIO0, 1);  // Set GPIO0 HIGH
    //     else
    //         GPIO_writePin(myGPIO0, 0);  // Set GPIO0 LOW

    //     if(bufferFull)
    //     {
    //         bufferFull = 0;
    //     }
     }
}

__interrupt void INT_myADC0_1_ISR(void)
{
    static bool value = 0;
    //myADC0Results[index++] = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER0);

    // if(index >= RESULTS_BUFFER_SIZE)
    // {
    //     index = 0;
    //     bufferFull = 1;   // mark buffer ready (optional)
    // }

    value ^= 1;
    GPIO_writePin(myGPIO0, value);

    ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);

    if(ADC_getInterruptOverflowStatus(myADC0_BASE, ADC_INT_NUMBER1))
    {
        ADC_clearInterruptOverflowStatus(myADC0_BASE, ADC_INT_NUMBER1);
        ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);
    }

    Interrupt_clearACKGroup(INT_myADC0_1_INTERRUPT_ACK_GROUP);
}


//
// End of File
//
