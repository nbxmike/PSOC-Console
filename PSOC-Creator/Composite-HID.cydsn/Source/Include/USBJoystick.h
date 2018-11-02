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
/** @file   USBJoystick.h
 *  @author Mike McCormack (nbxmike)
 *  @date   8/OCT/2018
 *  @brief  Constants and prototypes for the local i/o devices.
 */


#include <project.h>
#include <stdio.h>

#ifndef USBJOYSTICK_H
#define USBJOYSTICK_H

/* USB buffer sizes */
#define ANALOG_SIZE		8
#define BUTTON_SIZE		3 /* Mix of buttons from PSx and local inputs  */
#define OUTPUT_SIZE		1

/* In USB vernacular, IN and OUT are always from the persepective of the host */
/* controller and not the peripheral, unfortunately Cypress documentation     */
/* looks at things from the point of view of thier parts . .                  */
#define JOY_IN_EP		  4           /* Endpoint 1 is IN (analog and buttons) */
#define JOY_OUT_EP		5           /* Endpiont 2 is OUT (indicators) */

extern void USBJoyInit(void);
extern void USBJoyClearBuffers(void);
extern int  UsbJoyCheck(void);
extern void UsbJoySetOutputs(void);
extern void UsbJoyTask(void*);

#endif
/* End of File */
