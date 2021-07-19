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
/** @file   USBJoystick.c
 *  @author Mike McCormack (nbxmike)
 *  @date   8/OCT/2018
 *  @brief  Local inputs added to or outputs derived from the USB HID information.
 *
 *  Creates the data transfered to the USB or extracts data from the USB host
 *  side.  It will replace the PSx controller input into HID data.  Also 
 *  supports peripherals that are not part of a PlayStation controller that 
 *  are attached to the PSOC.  Examples could be configuration switches as 
 *  inputs or LEDs as outputs.
 */


#include <project.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include <stdio.h>
#include "globals.h"
#include "USBJoystick.h"
#include "PSxHost.h"
#include "FRSupport.h"
#include "USBHost.h"
#include "LocalPeripherals.h"



static int8 USB_Input_Data[ANALOG_SIZE + BUTTON_SIZE];  /* USB data to send to the PC */
static uint8 USB_Output_Data[OUTPUT_SIZE];              /* USB data received from the PC */
static int sJoy_Startup = USB_UNSET;


/** @brief USBFS_EP_4_ISR_EntryCallback ISR hook for Joystick.
 *
 * USBFS_EP_4_ISR_EntryCallback and USBFS_EP_5_ISR_EntryCallback are the
 * joystick endpoint ISRs for this implementation.  Whenever either are
 * called the foreground task is freed to run, it must decide if the right
 * stuff occured or not.  If the endpoints are remapped, this routine will
 * need to be ported even if the processor remains a PSOC-5LP.
 */
void USBCOMP_EP_4_ISR_ExitCallback(void)
{
  static BaseType_t xHigherPriorityTaskWoken;
  xHigherPriorityTaskWoken = pdFALSE;
  if( xUSBJoystick_Semaphore != NULL )
  {
    xSemaphoreGiveFromISR( xUSBJoystick_Semaphore, &xHigherPriorityTaskWoken );
    if (xHigherPriorityTaskWoken == pdTRUE)
    {
      portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
    }
  }
}
void USBCOMP_EP_5_ISR_ExitCallback(void)
{
  static BaseType_t xHigherPriorityTaskWoken;
  xHigherPriorityTaskWoken = pdFALSE;
  if( xUSBJoystick_Semaphore != NULL )
  {
    xSemaphoreGiveFromISR( xUSBJoystick_Semaphore, &xHigherPriorityTaskWoken );
    if (xHigherPriorityTaskWoken == pdTRUE)
    {
      portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
    }
  }
}

/**
 * @brief Initializes USB HID buffers and create FreeRTOS task.
 *
 * Clears any garbage in buffers and will check to see that we've been
 * configured.  It also creates the FreeRTOS task which runs to implement
 * the USB HID function.
 *
 * @param  None
 * @return Nothing
 */
void USBJoyClearBuffers(void) {
  uint8 i;

  /* Intialize USB Input EP data array */
  for (i = 0; i < sizeof(USB_Input_Data); i++) {
    USB_Input_Data[i] = 0;
  }

  /* Intialize USB Output EP data array */
  for (i = 0; i < sizeof(USB_Output_Data); i++) {
    USB_Output_Data[i] = 0xff;
  }

}

/**
 * @brief Initializes USB HID buffers and create FreeRTOS task.
 *
 * Clears any garbage in buffers and will check to see that we've been
 * configured.  It also creates the FreeRTOS task which runs to implement
 * the USB HID function.
 *
 * @param  None
 * @return Nothing
 */
void USBJoyInit(void) {

  sJoy_Startup = USB_UNSET;

  USBJoyClearBuffers();
  UsbJoyCheck();
  
  xTaskCreate(                  /* Create Playstation Interface task              */
    UsbJoyTask,                 /* Function implementing the task loop            */
    "PSx_Host",                 /* String to locate the task in debugger          */
    configMINIMAL_STACK_SIZE,   /* Task's stack size (FreeTROS allocates)         */
    0,                          /* Number of parameters to pass to task  (none)   */
    2,                          /* Task's priority (medium)                       */
    0);                         /* Task handle (not used)                         */
}

/**
 * @brief Initializes USB HID buffers and interface.
 *
 * Clears any garbage in buffers and will check to see that we've been
 * configured.
 *
 * @param  None
 * @return Nothing
 */
int UsbJoyCheck(void) {

  if (USBConfigurationHID & USB_INITIALIZED)
  {
    if(sJoy_Startup == USB_UNSET)
    {
      sJoy_Startup = USB_INITIALIZED + USB_RECONFIGURED;
    }
    if(USBConfigurationHID & USB_RECONFIGURED)
    {
      sJoy_Startup = USB_INITIALIZED + USB_RECONFIGURED;
      xSemaphoreTake( xUSBConfig_Semaphore, USBHOST_CONFIG_WAIT );
      USBConfigurationHID = USB_INITIALIZED;
      xSemaphoreGive(xUSBConfig_Semaphore);
    }
  }
  else
  {
    sJoy_Startup = USB_UNSET;
  }

  if(sJoy_Startup & USB_RECONFIGURED)
  {
    USBJoyClearBuffers();
    USBCOMP_LoadInEP(JOY_IN_EP, (uint8 *)USB_Input_Data, sizeof(USB_Input_Data)); /* Loads an inital value into EP1 and sends it out to the PC */
    USBCOMP_EnableOutEP(JOY_OUT_EP);                                              /* Enable the output endpoint */
    sJoy_Startup = USB_INITIALIZED;
  }
  return sJoy_Startup;
}


void UsbJoySetOutputs(void) {
  Indicators_Write(USB_Output_Data[0]);
}

void UsbJoyTask(void *arg) {
  (void)arg;  // Just to get rid of compiler warning . . .
  uint16 outCount;

  for ( ; ;) {
    while (!USBCOMP_GetEPAckState(JOY_IN_EP))      /* Wait for ACK before loading data */
    {
    }
    LocalAnalogRead();       /* Calls function to read analog inputs */
    LocalButtonsRead();      /* Calls function to monitor button presses */

    /*Check to see if the IN Endpoint is empty. If so, load it with Input data to be tranfered */
    if (USBCOMP_GetEPState(JOY_IN_EP) == USBCOMP_IN_BUFFER_EMPTY) {
      /* Load latest analog and button data into the IN EP and send */
      USBCOMP_LoadInEP(JOY_IN_EP, (uint8 *)USB_Input_Data, sizeof(USB_Input_Data));
    }

    /* Check to see if the OUT Endpoint is full from a recieved transaction. */
    if (USBCOMP_GetEPState(JOY_OUT_EP) == USBCOMP_OUT_BUFFER_FULL) {
      /* Get the number of bytes recieved */
      outCount = USBCOMP_GetEPCount(JOY_OUT_EP);
      /* Read the OUT endpoint and store data in OUT_Data_Buffer */
      USBCOMP_ReadOutEP(JOY_OUT_EP, USB_Output_Data, outCount);
      /* Re-enable OUT endpoint */
      USBCOMP_EnableOutEP(JOY_OUT_EP);
    }

    UsbJoySetOutputs();       /* Set output values based on the data received from the out EP */
  }
}

/* End of File */
