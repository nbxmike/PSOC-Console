
/* ========================================
 *
 * Copyright 2018 Michael McCormack
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * ========================================
 */
/** @file   main.c
 *  @author Mike McCormack (nbxmike)
 *  @date   8/OCT/2018
 *  @brief  The startup of the PSOC.
 */

#include "project.h"
#include "FreeRTOS.h"
#include "task.h"
#include "FRSupport.h"
#include "FRCLILibrary.h"
#include "globals.h"
#include "USBHost.h"
#include "LocalPeripherals.h"
#include "PSxHost.h"

/* Flags to indicate the state of USB host and sub functions */
volatile int USBConfigurationHost = USB_UNSET;
volatile int USBConfigurationCDC  = USB_UNSET;
volatile int USBConfigurationHID  = USB_UNSET;


/**
 * @brief Sets up things by calling all init functions.
 *
 * This just provides one place for all of the initialization routines
 * to be placed for easy long term care.  
 * @param None
 * @return None
 * @note - we might want to make this return even if USB doesn't quite start
 */
void Setup_System(void)
{
  Indicators_Write(0xff);    // Turn off all LEDs
}


/**
 * @brief Very little happens in main, .
 *
 * Call a few setups and start the task scheduler that runs the real show.
 * @param None
 * @return None
 */
int main(void) {
  CyGlobalIntEnable;   /* Enable global interrupts. */

  Setup_System();
  FRInit();
  
  USBHostInit();
  CH_Init();
  PSxInit();
  USBJoyInit();
  LocalAnalogInit();



  vTaskStartScheduler();    // Had best never return

  while (1)
  {
  }
}

/* [] END OF FILE */
