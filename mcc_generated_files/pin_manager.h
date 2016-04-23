/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - v3.00
        Device            :  PIC12F1822
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20

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


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set PI_RUNNING aliases
#define PI_RUNNING_TRIS               TRISA0
#define PI_RUNNING_LAT                LATA0
#define PI_RUNNING_PORT               RA0
#define PI_RUNNING_WPU                WPUA0
#define PI_RUNNING_ANS                ANSA0
#define PI_RUNNING_SetHigh()    do { LATA0 = 1; } while(0)
#define PI_RUNNING_SetLow()   do { LATA0 = 0; } while(0)
#define PI_RUNNING_Toggle()   do { LATA0 = ~LATA0; } while(0)
#define PI_RUNNING_GetValue()         RA0
#define PI_RUNNING_SetDigitalInput()    do { TRISA0 = 1; } while(0)
#define PI_RUNNING_SetDigitalOutput()   do { TRISA0 = 0; } while(0)

#define PI_RUNNING_SetPullup()    do { WPUA0 = 1; } while(0)
#define PI_RUNNING_ResetPullup()   do { WPUA0 = 0; } while(0)
#define PI_RUNNING_SetAnalogMode()   do { ANSA0 = 1; } while(0)
#define PI_RUNNING_SetDigitalMode()   do { ANSA0 = 0; } while(0)


// get/set HOLD_PI aliases
#define HOLD_PI_TRIS               TRISA1
#define HOLD_PI_LAT                LATA1
#define HOLD_PI_PORT               RA1
#define HOLD_PI_WPU                WPUA1
#define HOLD_PI_ANS                ANSA1
#define HOLD_PI_SetHigh()    do { LATA1 = 1; } while(0)
#define HOLD_PI_SetLow()   do { LATA1 = 0; } while(0)
#define HOLD_PI_Toggle()   do { LATA1 = ~LATA1; } while(0)
#define HOLD_PI_GetValue()         RA1
#define HOLD_PI_SetDigitalInput()    do { TRISA1 = 1; } while(0)
#define HOLD_PI_SetDigitalOutput()   do { TRISA1 = 0; } while(0)

#define HOLD_PI_SetPullup()    do { WPUA1 = 1; } while(0)
#define HOLD_PI_ResetPullup()   do { WPUA1 = 0; } while(0)
#define HOLD_PI_SetAnalogMode()   do { ANSA1 = 1; } while(0)
#define HOLD_PI_SetDigitalMode()   do { ANSA1 = 0; } while(0)


// get/set BUTTON aliases
#define BUTTON_TRIS               TRISA2
#define BUTTON_LAT                LATA2
#define BUTTON_PORT               RA2
#define BUTTON_WPU                WPUA2
#define BUTTON_ANS                ANSA2
#define BUTTON_SetHigh()    do { LATA2 = 1; } while(0)
#define BUTTON_SetLow()   do { LATA2 = 0; } while(0)
#define BUTTON_Toggle()   do { LATA2 = ~LATA2; } while(0)
#define BUTTON_GetValue()         RA2
#define BUTTON_SetDigitalInput()    do { TRISA2 = 1; } while(0)
#define BUTTON_SetDigitalOutput()   do { TRISA2 = 0; } while(0)

#define BUTTON_SetPullup()    do { WPUA2 = 1; } while(0)
#define BUTTON_ResetPullup()   do { WPUA2 = 0; } while(0)
#define BUTTON_SetAnalogMode()   do { ANSA2 = 1; } while(0)
#define BUTTON_SetDigitalMode()   do { ANSA2 = 0; } while(0)


// get/set SPARE aliases
#define SPARE_TRIS               TRISA3
#define SPARE_PORT               RA3
#define SPARE_WPU                WPUA3
#define SPARE_GetValue()         RA3
#define SPARE_SetDigitalInput()    do { TRISA3 = 1; } while(0)
#define SPARE_SetDigitalOutput()   do { TRISA3 = 0; } while(0)

#define SPARE_SetPullup()    do { WPUA3 = 1; } while(0)
#define SPARE_ResetPullup()   do { WPUA3 = 0; } while(0)


// get/set LED aliases
#define LED_TRIS               TRISA4
#define LED_LAT                LATA4
#define LED_PORT               RA4
#define LED_WPU                WPUA4
#define LED_ANS                ANSA4
#define LED_SetHigh()    do { LATA4 = 1; } while(0)
#define LED_SetLow()   do { LATA4 = 0; } while(0)
#define LED_Toggle()   do { LATA4 = ~LATA4; } while(0)
#define LED_GetValue()         RA4
#define LED_SetDigitalInput()    do { TRISA4 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISA4 = 0; } while(0)

#define LED_SetPullup()    do { WPUA4 = 1; } while(0)
#define LED_ResetPullup()   do { WPUA4 = 0; } while(0)
#define LED_SetAnalogMode()   do { ANSA4 = 1; } while(0)
#define LED_SetDigitalMode()   do { ANSA4 = 0; } while(0)


// get/set RELAY aliases
#define RELAY_TRIS               TRISA5
#define RELAY_LAT                LATA5
#define RELAY_PORT               RA5
#define RELAY_WPU                WPUA5
#define RELAY_SetHigh()    do { LATA5 = 1; } while(0)
#define RELAY_SetLow()   do { LATA5 = 0; } while(0)
#define RELAY_Toggle()   do { LATA5 = ~LATA5; } while(0)
#define RELAY_GetValue()         RA5
#define RELAY_SetDigitalInput()    do { TRISA5 = 1; } while(0)
#define RELAY_SetDigitalOutput()   do { TRISA5 = 0; } while(0)

#define RELAY_SetPullup()    do { WPUA5 = 1; } while(0)
#define RELAY_ResetPullup()   do { WPUA5 = 0; } while(0)



/**
 * @Param
    none
 * @Returns
    none
 * @Description
    GPIO and peripheral I/O initialization
 * @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);

#endif // PIN_MANAGER_H