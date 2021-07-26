/* ========================================
 *
 * Copyright 2021 Michael McCormack
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
#ifndef LEDSOUT_H
#define LEDSOUT_H

#include <stdint.h>

#define LEDSOUT_COUNT    8
    
    
#define LEDSOUT_OFF           (0)
#define LEDSOUT_STEADY_ON     (1)
#define LEDSOUT_SLOW          (2)
#define LEDSOUT_FAST          (3)
#define LEDSOUT_DOUBLE        (4)
#define LEDSOUT_TRIPLE        (5)
#define LEDSOUT_DASH_DOT      (6)
#define LEDSOUT_MODE_INVALID  (7)      // Alsways the last mode
    
#define LEDSOUT_RATE_TICK     (50)
#define LEDSOUT_RATE_SLOW     (500)
#define LEDSOUT_RATE_FAST     (250)
#define LEDSOUT_RATE_PAUSE    (1000)

typedef struct 
{
    uint16_t count;
    uint8_t mode;
    uint8_t onOff;
    uint8_t state;
} LED_Output_t ;


void LEDSOut_Init(void);
int LEDSOut_Set(unsigned int LEDNumber, unsigned int mode);

#endif
/* [] END OF FILE */
