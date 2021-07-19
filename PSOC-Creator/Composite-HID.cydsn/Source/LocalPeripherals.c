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
 *  @brief  Local inputs added to, or outputs derived from, the USB HID information.
 *
 *  Support for peripherals that are not part of a PlayStation controller that 
 *  are attached to the PSOC.  Examples could be configuration switches as inputs
 *  or LEDs as outputs.
 */


#include <project.h>
#include "FreeRTOS.h"
#include <stdio.h>
#include "LocalPeripherals.h"
#include "timers.h"
#include "semphr.h"
#include "FRSupport.h"


int16 AnalogWorking[ANALOG_SIZE];                /* ADC measurements in process       */
volatile int16 AnalogScaled[ANALOG_SIZE];        /* Scaled, centered ADC measurements */
volatile uint8 ButtonBuffer[BUTTON_SIZE];
volatile uint8 IndicatorBuffer;


/**
 * @brief Releases the foreground waiting on ADC to end.
 *
 * Hopefully, this is called when one complete ADC cycle, that is all 
 * ADCs inputs are sampled, is completed.
 * @param  None, IRQ
 * @return Nothing, IRQ
 */
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

/**
 * @brief Pulls samples from the ADC and puts them a buffer.
 *
 * This will pull data from the ADC, scales it and centers it about zero
 * in an integer array.  To ensure that another task cannot get half converted
 * data, the shared buffer is not updated here but in another procedure and
 * and that is not called until the data is has been processed.   Yes, some
 * other task could get data from two sample periods, but as we are talking
 * with human interoperations, it really does not matter.
 *
 * @param  None
 * @return Nothing
 */
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


/**
 * @brief Copies data from the working to the shared array.
 *
 * This is a very specific copy routine moved from its previous function
 * to a seperate function to force the compiler to not optimize it in a
 * way that would be problematic.
 *
 * @param  None
 * @return Nothing
 */
void LocalAnalogCopy(void) 
{
  int i;

  for (i = 0; i < ANALOG_SIZE; i++)  {
    AnalogScaled[i] = AnalogWorking[i];
  }
}


/**
 * @brief Pulls from the digital input register.
 *
 * This will pull data from the the digital registers that are connected to 
 * buttons and switches.  Yes, some other task could get data from two 
 * sample periods, but as we are talking with human interoperations, it really
 * does not matter.
 *
 * @param  None
 * @return Nothing
 */
void LocalButtonsRead(void) {    // Move from I/O registers to memory
  ButtonBuffer[0] = ButtonReg1_Read();     /* First button byte is after the last analog value */
  ButtonBuffer[1] = ButtonReg2_Read();
}



/**
 * @brief Programs the local indicators with USB host data.
 *
 * The USB host sends the data that will get copied to local indicators register.
 *
 * @param  None
 * @return Nothing
 */
void LocalOutputsSet(void) {
  Indicators_Write(IndicatorBuffer);
}

/**
 * @brief Initializes and starts the analog sampling.
 *
 * Will setup the ADC, though it is already set in the schematic, an then
 * starts the converter on a continous loog of samples
 *
 * @param  None
 * @return Nothing
 */
void LocalAnalogStartUp(void) {
  
  ADC_Start();                                      /* Initialize ADC */
  ADC_StartConvert();                               /* End ADC conversion */

}

/**
 * @brief Intialization of the local inputs/outputs - one time only.
 *
 * Sets up the software mainly, the hardware is largely configured in the
 * PSOC TopDesign.cysch file.  This is intended to only be called one time
 * and repeat calls could be problematic.
 * @param None
 * @return None
 */
void LocalAnalogInit(void) 
{

  LocalAnalogStartUp();
  
  xTaskCreate(                  /* Create Playstation Interface task              */
    LocalPeripheralsTask,       /* Function implementing the task loop            */
    "LocalPeripherals",         /* String to locate the task in debugger          */
    configMINIMAL_STACK_SIZE,   /* Task's stack size (FreeTROS allocates)         */
    0,                          /* Number of parameters to pass to task  (none)   */
    3,                          /* Task's priority (medium)                       */
    0);                         /* Task handle (not used)                         */
}



/**
 * @brief FreeRTOS task to handle peripherals on the PSOC.
 *
 * The standard FreeRTOS task, set things up then loop forever.
 *
 * @param  None
 * @return Nothing
 */
void LocalPeripheralsTask(void *arg) {
  (void)arg;
  TickType_t xPeripheralWakeTime;
  
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
