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
/** @file   LocalPeripherals.h
 *  @author Mike McCormack (nbxmike)
 *  @date   8/OCT/2018
 *  @brief  Constants and prototypes for the local i/o devices.
 */


#include <project.h>

#ifndef LOCALPERIPHERALS_H
#define LOCALPERIPHERALS_H

#define ANALOG_SIZE   8
#define BUTTON_SIZE   2
#define SAMPLE_PERIOD 5
  
extern int16 AnalogWorking[ANALOG_SIZE];      /* ADC measurements in process       */
extern int16 AnalogScaled[ANALOG_SIZE];       /* Scaled, centered ADC measurements */

void LocalAnalogStartUp(void);     /* Setup for the local analog and digital IO  */
void LocalAnalogRead(void);        /* Read analog joysticks and sliders          */
void LocalButtonsRead(void);       /* Read digital inputs                        */
void LocalOutputsSet(void);        /* Put the PCs data in tha digital outputs    */
int  LocalPeripheralsTask(void);   /* */
void LocalAnalogCopy(void);        /* Create to force the compiler's hand        */



#endif
/* End of File */
