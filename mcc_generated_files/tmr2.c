/**
  TMR2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr2.c

  @Summary
    This is the generated driver implementation file for the TMR2 driver using MPLAB(c) Code Configurator

  @Description
    This source file provides APIs for TMR2.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - v3.00
        Device            :  PIC12F1822
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20
 */

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

/**
  Section: Included Files
 */

#include <xc.h>
#include "tmr2.h"
#include "pin_manager.h"
#include "../main.h"

/**
  Section: TMR2 APIs
 */

void TMR2_Initialize(void) {
  // Set TMR2 to the options selected in the User Interface

  // T2CKPS 1:16; T2OUTPS 1:1; TMR2ON off; 
  T2CON = 0x02;

  // PR2 255; 
  PR2 = 0xFF;

  // TMR2 0; 
  TMR2 = 0x00;

  // Clearing IF flag before enabling the interrupt.
  PIR1bits.TMR2IF = 0;

  // Enabling TMR2 interrupt.
  PIE1bits.TMR2IE = 1;

  // Set Default Interrupt Handler
  TMR2_SetInterruptHandler(TMR2_DefaultInterruptHandler);

  // Start TMR2
  TMR2_StartTimer();
}

void TMR2_StartTimer(void) {
  // Start the Timer by writing to TMRxON bit
  T2CONbits.TMR2ON = 1;
}

void TMR2_LoadPeriodRegister(uint8_t periodVal) {
  PR2 = periodVal;
}

void TMR2_ISR(void) {
  static volatile unsigned int CountCallBack = 0;

  // clear the TMR2 interrupt flag
  PIR1bits.TMR2IF = 0;
  TMR2_LoadPeriodRegister(222);

  // callback function - called every 25th pass
  if (++CountCallBack >= TMR2_INTERRUPT_TICKER_FACTOR) {
    // ticker function call
    TMR2_CallBack();

    // reset ticker counter
    CountCallBack = 0;
  }
}

void TMR2_CallBack(void) {
  // Add your custom callback code here
  // this code executes every TMR2_INTERRUPT_TICKER_FACTOR periods of TMR2
  if (TMR2_InterruptHandler) {
    TMR2_InterruptHandler();
  }
}

void TMR2_SetInterruptHandler(void* InterruptHandler) {
  TMR2_InterruptHandler = InterruptHandler;
}

void TMR2_DefaultInterruptHandler(void) {
  static volatile unsigned int CountPiHalted = POWER_DOWN_TICKER_FACTOR;
  static volatile unsigned int CountButtonPressed = BUTTON_TICKER_FACTOR;
  static volatile unsigned int CountBlink = LED_BLINK_PERIOD;

  if ((HOLD_PI_PORT && !PI_RUNNING_PORT) || (!HOLD_PI_PORT && PI_RUNNING_PORT)) {
    CountBlink--;
    if (CountBlink == LED_BLINK_DURATION) {
      LED_SetHigh();
    } else if (CountBlink == 0) {
      LED_SetLow();
      CountBlink = LED_BLINK_PERIOD;
    }
  } else if (!PiHalted) {
    LED_SetHigh();
  }

  if (PiHalted) {
    if (!PI_RUNNING_PORT) {
      CountPiHalted--;
      if (CountPiHalted == 0) {
        PowerDown = true;
      }
    } else {
      PiHalted = false;
      CountPiHalted = POWER_DOWN_TICKER_FACTOR;
    }
  }

  if (ButtonPushed) {
    if (BUTTON_PORT) {
      CountButtonPressed--;
      if (CountButtonPressed == 0) {
        HOLD_PI_SetLow(); // request Pi to shutdown
        ButtonPushed = false;
        CountButtonPressed = BUTTON_TICKER_FACTOR;
      }
    } else {
      ButtonPushed = false;
      CountButtonPressed = BUTTON_TICKER_FACTOR;
    }
  }
}