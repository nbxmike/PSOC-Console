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
/**
 * @file   FRSupport.c
 * @author Mike McCormack (nbxmike)
 * @date   8/OCT/2018
 * @brief  Attempt to prepackage FreeRTOS support for Cypress PSOC 5LP usage.
 */

#include "project.h"
#include "FreeRTOS.h"
#include "FRSupport.h"
#include "timers.h"
#include "semphr.h"

volatile SemaphoreHandle_t xPSx_ACK_Semaphore = NULL;
volatile SemaphoreHandle_t xPSx_SPI_Semaphore = NULL;
volatile SemaphoreHandle_t xPSx_XFR_Semaphore = NULL;
volatile SemaphoreHandle_t xCH_Semaphore = NULL;
volatile SemaphoreHandle_t xAnalog_Semaphore = NULL;
volatile SemaphoreHandle_t xUSBHost_Semaphore = NULL;
volatile SemaphoreHandle_t xUSBConfig_Semaphore = NULL;
volatile SemaphoreHandle_t xUSBJoystick_Semaphore = NULL;


TickType_t BlinkyWakeTime;

/** @brief FRInit initializes stuff needed for FreeRTOS
 *
 * FRInit initializes the interrupt hooks needed by FreeRTOS and also
 * creates the LED heartbeat task just so there is always some task
 * for FreeRTOS.  The heartbeat can be deleted, I just like to see
 * something happen when I start a project.
 */
void FRInit() {
  /* Handler for Cortex calls - part of Cortex-M3 port */
  CyIntSetSysVector(CORTEX_INTERRUPT_BASE + SVCall_IRQn, (cyisraddress)vPortSVCHandler);
  CyIntSetSysVector(CORTEX_INTERRUPT_BASE + PendSV_IRQn, (cyisraddress)xPortPendSVHandler);
  CyIntSetSysVector(CORTEX_INTERRUPT_BASE + SysTick_IRQn, (cyisraddress)xPortSysTickHandler);

  /* Create all semaphores used in the application, initialize them to taken */
  xPSx_ACK_Semaphore = xSemaphoreCreateBinary();
  xSemaphoreGive(xPSx_ACK_Semaphore);             // Not sure this is necessary, doc 
  xSemaphoreTake( xPSx_ACK_Semaphore, 1 );        //   implies it is, or at least clouded
  
  xPSx_SPI_Semaphore = xSemaphoreCreateBinary();
  xSemaphoreGive(xPSx_SPI_Semaphore);
  xSemaphoreTake( xPSx_SPI_Semaphore, 1 );

  xPSx_XFR_Semaphore = xSemaphoreCreateBinary();
  xSemaphoreGive(xPSx_XFR_Semaphore);
  xSemaphoreTake( xPSx_XFR_Semaphore, 1 );
  
  xCH_Semaphore = xSemaphoreCreateBinary();
  xSemaphoreGive(xCH_Semaphore);
  xSemaphoreTake( xCH_Semaphore, 1 );
  
  xAnalog_Semaphore = xSemaphoreCreateBinary();
  xSemaphoreGive(xAnalog_Semaphore);
  xSemaphoreTake( xAnalog_Semaphore, 1 );

  xUSBHost_Semaphore = xSemaphoreCreateBinary();
  xSemaphoreGive(xUSBHost_Semaphore);
  xSemaphoreTake( xUSBHost_Semaphore, 1 );

  xUSBConfig_Semaphore = xSemaphoreCreateBinary();
  xSemaphoreGive(xUSBConfig_Semaphore);

  xUSBJoystick_Semaphore = xSemaphoreCreateBinary();
  xSemaphoreGive(xUSBJoystick_Semaphore);
  xSemaphoreTake( xUSBJoystick_Semaphore, 1 );

/* Create a default task so something always is there */ 
  xTaskCreate(                  /* Create LED task, which will blink the '059 LED */
    Blinky_Task,                /* Function implementing the task loop            */
    "LED Blink",                /* String to locate the task in debugger          */
    configMINIMAL_STACK_SIZE,   /* Task's stack size (FreeTROS allocates)         */
    0,                          /* Number of parameters to pass to task  (none)   */
    1,                          /* Task's priority (low)                          */
    0);                         /* Task handle (not used)                         */
}


/** @brief Blinky_Task blinks the local heartbeat LED, defined here so there is always a starting task
 *
 * This task needs to be modified for each board that it is run on, for Cypress
 * PSOC boards the following are the LED locations (incomplete I am aware):
 *  CY8KIT-059 - P2.1
 *  CY8KIT-029 - P1.6
 *  CY8KIT-040 - P3.1
 * and of course you need to map these pins to your TopDesign.cysch register
 * names.  Blink rate is presently hard coded for 1Hz.
 */
void Blinky_Task(void *arg) 
{
  (void)arg;
  TickType_t xBlinkyWakeTime;
  
  xBlinkyWakeTime = xTaskGetTickCount();
  while (1)
  {
    Indicators_Write(0x80^Indicators_Read());
    vTaskDelayUntil( &xBlinkyWakeTime, 500 );  
  }
}


/* [] END OF FILE */
