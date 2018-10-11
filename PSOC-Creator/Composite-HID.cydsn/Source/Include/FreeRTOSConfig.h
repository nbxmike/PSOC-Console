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
/** @file   FreeRTOSConfig.h
 *  @author Mike McCormack (nbxmike)
 *  @date   8/OCT/2018
 *  @brief  Configuration requirements and options for FreeRTOS.
 *
 *  Largely collected from FreeRTOS docs/webpages and other peoples examples, 
 *  I beleive it is not up to the point of an independant work and applying
 *  my copyright and license terms.
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H
#include <project.h>

#define configUSE_PREEMPTION						1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION		0
#define configUSE_TICKLESS_IDLE						0
#define configCPU_CLOCK_HZ							(( unsigned long )BCLK__BUS_CLK__HZ)
#define configTICK_RATE_HZ							1000
#define configMAX_PRIORITIES						5
#define configMINIMAL_STACK_SIZE					(( unsigned short )128)
#define configMAX_TASK_NAME_LEN						16
#define configUSE_16_BIT_TICKS						0
#define configIDLE_SHOULD_YIELD						1
#define configUSE_TASK_NOTIFICATIONS				1
#define configUSE_MUTEXES							0
#define configUSE_RECURSIVE_MUTEXES					0
#define configUSE_COUNTING_SEMAPHORES				0
#define configUSE_ALTERNATIVE_API					0 /* Deprecated! */
#define configQUEUE_REGISTRY_SIZE					10
#define configUSE_QUEUE_SETS						0
#define configUSE_TIME_SLICING						0
#define configUSE_NEWLIB_REENTRANT					0
#define configENABLE_BACKWARD_COMPATIBILITY			0
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS		5

/* Memory allocation related definitions. */
#define configSUPPORT_STATIC_ALLOCATION				0
#define configSUPPORT_DYNAMIC_ALLOCATION			1
#define configTOTAL_HEAP_SIZE						10240
#define configAPPLICATION_ALLOCATED_HEAP			0

/* Hook function related definitions. */
#define configUSE_IDLE_HOOK							0
#define configUSE_TICK_HOOK							0
#define configCHECK_FOR_STACK_OVERFLOW				0
#define configUSE_MALLOC_FAILED_HOOK				0
#define configUSE_DAEMON_TASK_STARTUP_HOOK			0

/* Run time and task stats gathering related definitions. */
#define configGENERATE_RUN_TIME_STATS				0
#define configUSE_TRACE_FACILITY					0
#define configUSE_STATS_FORMATTING_FUNCTIONS		1

/* Co-routine related definitions. */
#define configUSE_CO_ROUTINES						0
#define configMAX_CO_ROUTINE_PRIORITIES				1

/* Software timer related definitions. */
#define configUSE_TIMERS							1
#define configTIMER_TASK_PRIORITY					3
#define configTIMER_QUEUE_LENGTH					10
#define configTIMER_TASK_STACK_DEPTH				configMINIMAL_STACK_SIZE

/* Interrupt nesting behaviour configuration. */

/**
 * Configure the number of priority bits. This is normally
 * __NVIC_PRIO_BITS but PSoC Creator beta 5 contained a larger
 * value for the priority than is implemented in the hardware so
 * set it here to what the data sheet describes.
 */
#define configPRIO_BITS						3 /* 8 priority levels */

/* The lowest priority. */
#define configKERNEL_INTERRUPT_PRIORITY		(7 << (8 - configPRIO_BITS))

/* Priority 5, or 160 as only the top three bits are implemented. */

/* !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
 * See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY    (5 << (8 - configPRIO_BITS))

/*  A very, very bad trap for development, MUST REPLACE  */
/* TODO - don't let good code die                        */
  
#define configASSERT(x)                                     \
  if ((x) == 0) { taskDISABLE_INTERRUPTS(); for ( ; ;) {; } \
  }


/* Optional functions  */
#define INCLUDE_vTaskPrioritySet				1
#define INCLUDE_uxTaskPriorityGet				1
#define INCLUDE_vTaskDelete						1
#define INCLUDE_vTaskSuspend					1
#define INCLUDE_xResumeFromISR					1
#define INCLUDE_vTaskDelayUntil					1
#define INCLUDE_vTaskDelay						1
#define INCLUDE_xTaskGetSchedulerState			1
#define INCLUDE_xTaskGetCurrentTaskHandle		1
#define INCLUDE_uxTaskGetStackHighWaterMark		0
#define INCLUDE_xTaskGetIdleTaskHandle			0
#define INCLUDE_eTaskGetState					0
#define INCLUDE_xEventGroupSetBitFromISR		1
#define INCLUDE_xTimerPendFunctionCall			0
#define INCLUDE_xTaskAbortDelay					0
#define INCLUDE_xTaskGetHandle					0
#define INCLUDE_xTaskResumeFromISR				1

/* CLI related configs                                                */
#define configCOMMAND_INT_MAX_OUTPUT_SIZE		128

#endif /* FREERTOS_CONFIG_H */
