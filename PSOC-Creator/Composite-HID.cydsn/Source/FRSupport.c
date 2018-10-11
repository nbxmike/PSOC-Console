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

TickType_t BlinkyWakeTime;

/** @brief FRsetup initializes stuff needed for FreeRTOS
 *
 * FRsetup initializes the interrupt hooks needed by FreeRTOS and also
 * creates the LED heartbeat task just so there is always some task
 * for FreeRTOS.  The heartbeat can be deleted, I just like to see
 * something happen when I start a project.
 */
void FRsetup() {
  /* Handler for Cortex calls - part of Cortex-M3 port */
  CyIntSetSysVector(CORTEX_INTERRUPT_BASE + SVCall_IRQn, (cyisraddress)vPortSVCHandler);
  CyIntSetSysVector(CORTEX_INTERRUPT_BASE + PendSV_IRQn, (cyisraddress)xPortPendSVHandler);
  CyIntSetSysVector(CORTEX_INTERRUPT_BASE + SysTick_IRQn, (cyisraddress)xPortSysTickHandler);

  xTaskCreate(                  /* Create LED task, which will blink the '059 LED */
    Blinky_Task,                /* Task function */
    "LED Blink",                /* Task name (string) */
    configMINIMAL_STACK_SIZE,   /* Task stack, allocated from heap */
    0,                          /* No param passed to task function */
    1,                          /* Low priority */
    0);                         /* Not using the task handle */
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
