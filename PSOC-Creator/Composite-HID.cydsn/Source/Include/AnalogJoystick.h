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

#include <project.h>
#include <stdio.h>

#ifndef ANALOGJOYSTICK_H
#define ANALOGJOYSTICK_H

/* USB buffer sizes */
#define ANALOG_SIZE		8
#define BUTTON_SIZE		3 /* Mix of buttons from PSx and local inputs  */
#define OUTPUT_SIZE		1

/* In USB vernacular, IN and OUT are always from the persepective of the host */
/* controller and not the peripheral, unfortunately Cypress documentation     */
/* looks at things from the point of view of thier parts . .                  */
#define IN_EP		1           /* Endpoint 1 is IN (analog and buttons) */
#define OUT_EP		2           /* Endpiont 2 is OUT (indicators) */

void AnaJoyStartUp(void);       /* Setup for the local joystick and buttons   */
void AnaJoyReadAnalog(void);    /* Read and pack up the joysticks and sliders */
void AnaJoyReadButtons(void);   /* Read and pack up digital inputs            */
void AnaJoySetOutputs(void);    /* Put the PCs data in tha digital outputs    */
int AnaJoyTask(void);           /* */


#endif
/* End of File */
