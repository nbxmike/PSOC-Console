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
/** @file USBHost.c
 *  @author Mike McCormack (nbxmike)
 *  @date   8/OCT/2018
 *  @brief Support library and port of CLI task to Cypress PSOC 5LP
 *
 *  Support library for the FreeRTOS command line interpreter and port of their
 *  CLI task to Cypress PSOC 5LP.  All the CH_xxx deal with the CLI Human 
 *  interface device.  This will typically be a real or virtual UART device;
 *  here it is a USB virtual UART.
 */

#include "project.h"
#include "FRSupport.h"
#include <stdio.h>
#include <string.h>
#include "FreeRTOS.h"
#include "FreeRTOS_CLI.h"
#include "timers.h"
#include "semphr.h"
#include "USBHost.h"
#include "globals.h"


SemaphoreHandle_t xUSBHost_Semaphore = NULL;


/** @brief ISR callback for all EP0 activities
 *
 * EP0 is used when the other side of the USB needs to setup or reset stuff on
 * the whole device.  This callback will free the foreground more often than
 * it needs to so the foreground needs to check why it was released.
 */
void USBCOMP_EP_0_ISR_ExitCallback(void)
{
  static BaseType_t xHigherPriorityTaskWoken;
  xHigherPriorityTaskWoken = pdFALSE;
  if( xUSBHost_Semaphore != NULL )
  {
    xSemaphoreGiveFromISR( xUSBHost_Semaphore, &xHigherPriorityTaskWoken );
    if (xHigherPriorityTaskWoken == pdTRUE)
    {
      portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
    }
  }
}

/** @brief CH_Init starts the user's comm port
 *
 * CH_Init will start the interface and clear and data that was present
 * before it begins.  Typically there will be nothing as this should
 * start at power up, but just in case . . . 
 */
void USBHost_Init(void) 
{
  if (USBCOMP_IsConfigurationChanged())
  {
    if (USBCOMP_GetConfiguration())
    {
      USBCOMP_CDC_Init();
      while(USBCOMP_DataIsReady())
      {
        USBCOMP_GetChar();
      }
    }
  }

}

/** @brief cliTask task which invokes the FreeRTOS CLI engine
 *
 * cliTask process the user input on the command line.  At present it only
 * support character input and backspace editing; there is no support for
 * cursor movement or anything else.  To make things as platform independant
 * as possible this accepts DEL or BS as backspace, accepts CR, LF, or CR-LF
 * as input termination.
 */
void USBHostTask(void *arg) {
  (void)arg;

  xUSBHost_Semaphore = xSemaphoreCreateBinary(); //TODO: do error checking someday
  USBConfigurationCDC = 0;
  USBConfigurationHID = 0;

  

  while (1)
  {
    
  }
}
