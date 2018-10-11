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
/** @file   LocalPeripherals.c
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
#include "LocalPeripherals.h"
#include "FreeRTOS.h"
#include "timers.h"
#include "semphr.h"


int16 AnalogWorking[ANALOG_SIZE];                /* ADC measurements in process       */
int16 AnalogScaled[ANALOG_SIZE];                 /* Scaled, centered ADC measurements */
uint8 ButtonBuffer[BUTTON_SIZE];
uint8 IndicatorBuffer;
SemaphoreHandle_t xAnalog_Semaphore = NULL;

void ADC_IRQ_Interrupt_InterruptCallback(void)
{
  static BaseType_t xHigherPriorityTaskWoken;
  xHigherPriorityTaskWoken = pdFALSE;
    
  if( xAnalog_Semaphore != NULL )
  {
    xSemaphoreGiveFromISR( xAnalog_Semaphore, &xHigherPriorityTaskWoken );
    if (xHigherPriorityTaskWoken == pdTRUE)
    {
      portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
    }
  }  
  
}

void LocalAnalogStartUp(void) {
  uint8 i;

  ADC_Start();                                      /* Initialize ADC */
  ADC_StartConvert();                               /* End ADC conversion */

}


void LocalAnalogRead(void) {
  int i;

  for (i = 0; i < ANALOG_SIZE; i++)             // Adjust the data in one array
  {                                             // then copy the final result to the buffer
    AnalogWorking[i] = ADC_GetResult16(i) >> 4;
    AnalogWorking[i] = AnalogWorking[i] - 127;  /* Center the reading about zero            */
    if (AnalogWorking[i] > 127) {
      AnalogWorking[i] = 127;
    }
    else if (AnalogWorking[i] < -127) {
      AnalogWorking[i] = -127;
    }
  }
  LocalAnalogCopy();
}

void LocalAnalogCopy(void) 
{
  int i;

  for (i = 0; i < ANALOG_SIZE; i++)  {
    AnalogScaled[i] = AnalogWorking[i];
  }
}

void LocalButtonsRead(void) {    // Move from I/O registers to memory
  ButtonBuffer[0] = ButtonReg1_Read();     /* First button byte is after the last analog value */
  ButtonBuffer[1] = ButtonReg2_Read();
}


void LocalOutputsSet(void) {
  Indicators_Write(IndicatorBuffer);
}

int LocalPeripheralsTask() {
  uint16 outCount;
  TickType_t xPeripheralWakeTime;
  
  LocalAnalogStartUp();    /* Calls the proper start API for all the components */
  xAnalog_Semaphore = xSemaphoreCreateBinary();
  xSemaphoreGive(xAnalog_Semaphore);             // Not sure this is necessary, doc say yes
  xSemaphoreTake(xAnalog_Semaphore, 1 );

  xPeripheralWakeTime = xTaskGetTickCount();
  while (1)
  {
    vTaskDelayUntil( &xPeripheralWakeTime, SAMPLE_PERIOD );  
    LocalAnalogRead();
    LocalButtonsRead();
    LocalOutputsSet();
  }
}

/* End of File */
