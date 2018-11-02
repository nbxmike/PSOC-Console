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
#include "FreeRTOS.h"
#include <stdio.h>
#include <string.h>
#include "timers.h"
#include "semphr.h"
#include "FRSupport.h"
#include "FreeRTOS_CLI.h"
#include "USBHost.h"
#include "globals.h"



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

/** @brief USBHost_Init sets up USB interface used by the HID and Serial port
 *
 * Actually, very little done here other than starting the hardware and
 * creating the FreeRTOS task.
 */
void USBHostInit(void) 
{
  USBCOMP_Start(0u, USBCOMP_5V_OPERATION);
  USBConfigurationHost = USB_UNSET;
  USBConfigurationCDC  = USB_UNSET;
  USBConfigurationHID  = USB_UNSET;

  xTaskCreate(                  /* Create Playstation Interface task              */
    USBHostTask,              /* Function implementing the task loop            */
    "USB_Host",                 /* String to locate the task in debugger          */
    configMINIMAL_STACK_SIZE,   /* Task's stack size (FreeTROS allocates)         */
    0,                          /* Number of parameters to pass to task  (none)   */
    4,                          /* Task's priority (high)                       */
    0);                         /* Task handle (not used)                         */
}

/** @brief cliTask task which invokes the FreeRTOS CLI engine
 *
 * USBHostTask jsut checks to see if the interface has been configured and/or if
 * the host has reconfigured the interface.
 */
void USBHostTask(void *arg) {
  (void)arg;
  
  while (1)
  {
    if (USBCOMP_GetConfiguration() != 0)
    {  
      xSemaphoreTake( xUSBConfig_Semaphore, USBHOST_CONFIG_WAIT );
      USBConfigurationHost |= USB_INITIALIZED;
      USBConfigurationCDC  |= USB_INITIALIZED;
      USBConfigurationHID  |= USB_INITIALIZED;

      if (USBCOMP_IsConfigurationChanged())
      {
        USBConfigurationCDC  |= USB_RECONFIGURED;
        USBConfigurationHID  |= USB_RECONFIGURED;
      }
    }
    else
    {
      xSemaphoreTake( xUSBConfig_Semaphore, USBHOST_CONFIG_WAIT );
      USBConfigurationHost = USB_UNSET;
      USBConfigurationCDC  = USB_UNSET;
      USBConfigurationHID  = USB_UNSET;
    }
    xSemaphoreGive(xUSBConfig_Semaphore);
    xSemaphoreTake(xUSBHost_Semaphore, USBHOST_TRANSACTION_WAIT );
    
  }
}
