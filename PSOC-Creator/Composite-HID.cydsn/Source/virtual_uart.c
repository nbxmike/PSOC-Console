/* ========================================
 *
 * Copyright Michael McCormack, 2018
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
/** @file   virtual_uart.c
 *  @author Mike McCormack (nbxmike)
 *  @date   8/OCT/2018
 *  @brief  Configuration of the UART used by the CLI.
 *
 *  At present, this is a placeholder to change the CLI task into a task which
 *  uses a set of functions to hide the physical implementation of the human
 *  interface to the CLI.  At present, the CLI has been hooked directly to the
 *  PSOC USB CDC library which would make moving the CLI to another platform a
 *  little more difficult than it needs to be.
 */

#include "project.h"
#include "FreeRTOS.h"
#include "virtual_uart.h"

void vuInit(void)
{

    USBCOMP_CDC_Init();
    while (USBCOMP_DataIsReady())
    {
        USBCOMP_GetChar();
    }
}

/* [] END OF FILE */
