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
#include "project.h"
#include "FreeRTOS.h"
#include "FRSupport.h"
#include "timers.h"

TickType_t BlinkyWakeTime;


void FRsetup() {
  /* Handler for Cortex Supervisor Call - address 11 */
  CyIntSetSysVector(CORTEX_INTERRUPT_BASE + SVCall_IRQn, (cyisraddress)vPortSVCHandler);

  /* Handler for Cortex PendSV Call - address 14 */
  CyIntSetSysVector(CORTEX_INTERRUPT_BASE + PendSV_IRQn, (cyisraddress)xPortPendSVHandler);

  /* Handler for Cortex SYSTICK - address 15 */
  CyIntSetSysVector(CORTEX_INTERRUPT_BASE + SysTick_IRQn, (cyisraddress)xPortSysTickHandler);

  xTaskCreate(                  /* Create LED task, which will blink the '059 LED */
    Blinky_Task,                /* Task function */
    "LED Blink",                /* Task name (string) */
    configMINIMAL_STACK_SIZE,   /* Task stack, allocated from heap */
    0,                          /* No param passed to task function */
    1,                          /* Low priority */
    0);                         /* Not using the task handle */
}


/* Very simple task to blink and LED, defined here so there is always a starting task */
void Blinky_Task(void *arg) {
  (void)arg;  // Just to get rid of compiler warning . . .
  BlinkyWakeTime = xTaskGetTickCount();

  while (1)
  {
    Indicators_Write(0x01 ^ Indicators_Read());
    vTaskDelayUntil(&BlinkyWakeTime, 500);
  }
}


/* [] END OF FILE */
