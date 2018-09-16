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

#include <project.h>
#include <stdio.h>
#include "AnalogJoystick.h"


static uint16 AnalogRaw[ANALOG_SIZE];                   /* Raw ADC measurements */
static int16 AnalogData[ANALOG_SIZE];                   /* Scaled ADC measurements */
static int8 USB_Input_Data[ANALOG_SIZE + BUTTON_SIZE];  /* USB data to send to the PC */
static uint8 USB_Output_Data[OUTPUT_SIZE];              /* USB data received from the PC */

int AnaJoyTask() {
  uint16 outCount;

  StartUp();    /* Calls the proper start API for all the components */

  for ( ; ;) {
    while (!USBFS_1_bGetEPAckState(IN_EP))      /* Wait for ACK before loading data */

    {
    }
    ReadAnalog();       /* Calls function to read analog inputs */
    ReadButtons();      /* Calls function to monitor button presses */

    /*Check to see if the IN Endpoint is empty. If so, load it with Input data to be tranfered */
    if (USBFS_1_GetEPState(IN_EP) == USBFS_1_IN_BUFFER_EMPTY) {
      /* Load latest analog and button data into the IN EP and send */
      USBFS_1_LoadInEP(IN_EP, (uint8 *)USB_Input_Data, sizeof(USB_Input_Data));
    }

    /* Check to see if the OUT Endpoint is full from a recieved transaction. */
    if (USBFS_1_GetEPState(OUT_EP) == USBFS_1_OUT_BUFFER_FULL) {
      /* Get the number of bytes recieved */
      outCount = USBFS_1_GetEPCount(OUT_EP);
      /* Read the OUT endpoint and store data in OUT_Data_Buffer */
      USBFS_1_ReadOutEP(OUT_EP, USB_Output_Data, outCount);
      /* Re-enable OUT endpoint */
      USBFS_1_EnableOutEP(OUT_EP);
    }

    SetOutputs();       /* Set output values based on the data received from the out EP */
  }
}


void AnaJoyStartUp(void) {
  uint8 i;

  /* Intialize USB Input EP data array */
  for (i = 0; i < sizeof(USB_Input_Data); i++) {
    USB_Input_Data[i] = 0;
  }
  /* Intialize USB Output EP data array */
  for (i = 0; i < sizeof(USB_Output_Data); i++) {
    USB_Output_Data[i] = 0;
  }

  CYGlobalIntEnable;                                /* Enable Global interrupts */
  ADC_Start();                                      /* Initialize ADC */
  ADC_StartConvert();                               /* End ADC conversion */
  USBFS_1_Start(0, USBFS_1_DWR_VDDD_OPERATION);     /* Start USBFS operation/device 0 and with 5V operation */
  while (!USBFS_1_bGetConfiguration())
  {
    /* Wait for Device to enumerate */
  }

  USBFS_1_LoadInEP(IN_EP, (uint8 *)USB_Input_Data, sizeof(USB_Input_Data)); /* Loads an inital value into EP1 and sends it out to the PC */
  USBFS_1_EnableOutEP(OUT_EP);                                              /* Enable the output endpoint */
}


void AnaJoyReadAnalog(void) {
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


void AnaJoyReadButtons(void) {
  /* Read button values from status registers into USB array to prepare for sending */
  USB_Input_Data[ANALOG_SIZE] = ButtonReg1_Read();     /* First button byte is after the last analog value */
  USB_Input_Data[ANALOG_SIZE+1] = ButtonReg2_Read();
  USB_Input_Data[ANALOG_SIZE+2] = ButtonReg3_Read();
}


void AnaJoySetOutputs(void) {
  Indicators_Write(USB_Output_Data[0]);
}


/* End of File */
