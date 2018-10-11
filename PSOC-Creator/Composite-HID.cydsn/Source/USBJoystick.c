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
 *  Support for peripherals that are not part of a PlayStation controller that 
 *  are attached to the PSOC.  Examples could be configuration switches as inputs
 *  or LEDs as outputs.
 */


#include <project.h>
#include <stdio.h>
#include "USBJoystick.h"
#include "PSxHost.h"


static uint16 AnalogRaw[ANALOG_SIZE];                   /* Raw ADC measurements */
static int16 AnalogData[ANALOG_SIZE];                   /* Scaled ADC measurements */
static int8 USB_Input_Data[ANALOG_SIZE + BUTTON_SIZE];  /* USB data to send to the PC */
static uint8 USB_Output_Data[OUTPUT_SIZE];              /* USB data received from the PC */



void UsbJoyStartUp(void) {
  uint8 i;

  /* Intialize USB Input EP data array */
  for (i = 0; i < sizeof(USB_Input_Data); i++) {
    USB_Input_Data[i] = 0;
  }

  USBCOMP_Start(0, USBCOMP_DWR_VDDD_OPERATION);     /* Start USBFS operation/device 0 and with 5V operation */
  while (!USBCOMP_bGetConfiguration())
  {
    /* Wait for Device to enumerate */
  }

  USBCOMP_LoadInEP(JOY_IN_EP, (uint8 *)USB_Input_Data, sizeof(USB_Input_Data)); /* Loads an inital value into EP1 and sends it out to the PC */
  USBCOMP_EnableOutEP(JOY_OUT_EP);                                              /* Enable the output endpoint */
}


void UsbJoyReadAnalog(void) {
  uint8 i;

  for (i = 0; i < ANALOG_SIZE; i++) {
    AnalogRaw[i] = ADC_GetResult16(i) >> 4;         /* Get ADC reading and keep just the 8 upper bits */
    AnalogData[i] = AnalogRaw[i] - 127;             /* Adjust axis to center the reading */
    if (AnalogData[i] > 127) {
      AnalogData[i] = 127;
    }
    if (AnalogData[i] < -127) {
      AnalogData[i] = -127;
    }

    /* Move analog data to USB array to prepare for sending */
    USB_Input_Data[i] = AnalogData[i];
  }
}


void UsbJoyReadButtons(void) {
  /* Read button values from status registers into USB array to prepare for sending */
  USB_Input_Data[ANALOG_SIZE] = ButtonReg1_Read();     /* First button byte is after the last analog value */
  USB_Input_Data[ANALOG_SIZE+1] = ButtonReg2_Read();
}


void UsbJoySetOutputs(void) {
  Indicators_Write(USB_Output_Data[0]);
}

int UsbJoyTask() {
  uint16 outCount;

  UsbJoyStartUp();    /* Calls the proper start API for all the components */

  for ( ; ;) {
    while (!USBCOMP_bGetEPAckState(JOY_IN_EP))      /* Wait for ACK before loading data */

    {
    }
    UsbJoyReadAnalog();       /* Calls function to read analog inputs */
    UsbJoyReadButtons();      /* Calls function to monitor button presses */

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
