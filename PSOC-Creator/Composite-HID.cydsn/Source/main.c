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

volatile int USBConfigurationHost = 0;
volatile int USBConfigurationCDC  = 0;
volatile int USBConfigurationHID  = 0;

/**
 * @brief Sets up things that are not specific to just one library.
 *
 * This is intended to set up thing that must be configured early and which
 * are note associated with any one function.  Examples are the USB interface
 * which must be started before the USB HID and USB UART which are set up 
 * elsewhere (as they are specific to one function / library).
 * @param None
 * @return None
 * @note - we might want to make this return even if USB doesn't quite start
 */
void Setup_System(void)
{
  USBCOMP_Start(0u, USBCOMP_5V_OPERATION);
  USBConfigurationHost = 1;
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

  USBConfigurationHost = 0;
  USBConfigurationCDC  = 0;
  USBConfigurationHID  = 0;

  Setup_System();
  FRsetup();

  xTaskCreate(cliTask, "CLI Task", configMINIMAL_STACK_SIZE*3, 0, 1, 0);
  vTaskStartScheduler();    // Had best never return

  while (1)
  {
  }
}

/* [] END OF FILE */
