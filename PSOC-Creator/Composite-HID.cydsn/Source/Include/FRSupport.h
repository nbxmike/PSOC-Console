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
 * @file   FRSupport.h
 * @author Mike McCormack (nbxmike)
 * @date   8/OCT/2018
 * @brief  Prototypes and constants for FreeRTOS support on a Cypress PSOC 5LP.
 */

#ifndef FRSUPPORT
#define FRSUPPORT
  
#include "semphr.h"


#define CORTEX_INTERRUPT_BASE    (16)

/* all semaphores are initialized in FRSupport */
extern volatile SemaphoreHandle_t xPSx_ACK_Semaphore;
extern volatile SemaphoreHandle_t xPSx_SPI_Semaphore;
extern volatile SemaphoreHandle_t xPSx_XFR_Semaphore;
extern volatile SemaphoreHandle_t xCH_Semaphore;
extern volatile SemaphoreHandle_t xAnalog_Semaphore;
extern volatile SemaphoreHandle_t xUSBHost_Semaphore;
extern volatile SemaphoreHandle_t xUSBConfig_Semaphore;
extern volatile SemaphoreHandle_t xUSBJoystick_Semaphore;

  
/* Defined in FreeRTOS's port.c but not provided in any include file ???  */
extern void xPortPendSVHandler(void);
extern void xPortSysTickHandler(void);
extern void vPortSVCHandler(void);

extern void FRInit();
extern void Blinky_Task(void *arg);


#endif
/* [] END OF FILE */
