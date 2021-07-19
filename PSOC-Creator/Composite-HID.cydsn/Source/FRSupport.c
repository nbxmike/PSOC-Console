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

/** @brief FRInit initializes stuff needed for FreeRTOS
 *
 * FRInit initializes the interrupt hooks needed by FreeRTOS and creates
 * semephores passed around by the rest of the system. 
 *
 */
void FRInit() {
  /* Handler for Cortex calls - part of Cortex-M3 port */
  CyIntSetSysVector(CORTEX_INTERRUPT_BASE + SVCall_IRQn, (cyisraddress)vPortSVCHandler);
  CyIntSetSysVector(CORTEX_INTERRUPT_BASE + PendSV_IRQn, (cyisraddress)xPortPendSVHandler);
  CyIntSetSysVector(CORTEX_INTERRUPT_BASE + SysTick_IRQn, (cyisraddress)xPortSysTickHandler);

  /* Create all semaphores used in the application, initialize them to taken */
  xPSx_ACK_Semaphore = xSemaphoreCreateBinary();  // Not sure this is necessary, doc 
  xSemaphoreGive(xPSx_ACK_Semaphore);             //   implies it is, or at least clouded,
  xSemaphoreTake( xPSx_ACK_Semaphore, 1 );        //   so I give then take
  
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
}
/* [] END OF FILE */
