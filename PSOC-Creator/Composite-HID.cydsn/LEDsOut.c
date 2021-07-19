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

#include <project.h>
#include "FreeRTOS.h"
#include "timers.h"
#include "LEDsOut.h"


#define LEDSOUT_SLOW_ON           (0)
#define LEDSOUT_SLOW_OFF          (1)

#define LEDSOUT_FAST_ON           (0)
#define LEDSOUT_FAST_OFF          (1)
#define LEDSOUT_DOUBLE_ONE_ON     (0)
#define LEDSOUT_DOUBLE_ONE_OFF    (1)
#define LEDSOUT_DOUBLE_TWO_ON     (2)
#define LEDSOUT_DOUBLE_TWO_OFF    (3)
#define LEDSOUT_DOUBLE_PAUSE      (4)
#define LEDSOUT_TRIPLE_ONE_ON     (0)
#define LEDSOUT_TRIPLE_ONE_OFF    (1)
#define LEDSOUT_TRIPLE_TWO_ON     (2)
#define LEDSOUT_TRIPLE_TWO_OFF    (3)
#define LEDSOUT_TRIPLE_THREE_ON   (4)
#define LEDSOUT_TRIPLE_THREE_OFF  (5)
#define LEDSOUT_TRIPLE_PAUSE      (6)
#define LEDSOUT_DASH_ON           (0)
#define LEDSOUT_DASH_OFF          (1)
#define LEDSOUT_DOT_ON            (2)
#define LEDSOUT_DOT_OFF           (3)

static LED_Output_t Leds[LEDSOUT_COUNT];
static TickType_t xLastTransactionTime;
static const uint8_t AndMasks[8] =  {0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F};
static const uint8_t OrMasks[8] =  {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

void LEDSOut_Task(void *arg);

/**
 * @brief Intialization of the LED outputs.
 *
 * Creates the blinking task and set the outputs to defaults / known states
 *
 * @param None
 * @return None
 */
void LEDSOut_Init(void) 
{

  for (int i = 0; i < LEDSOUT_COUNT; ++i)
    {
        Leds[i].mode = LEDSOUT_OFF;
        Leds[i].count = 0;        
    }
  
  xTaskCreate(                  /* Create Playstation Interface task              */
    LEDSOut_Task,               /* Function implementing the task loop            */
    "LED_Out_Task",             /* String to locate the task in debugger          */
    configMINIMAL_STACK_SIZE,   /* Task's stack size (FreeTROS allocates)         */
    0,                          /* Number of parameters to pass to task  (none)   */
    3,                          /* Task's priority (medium)                       */
    0);                         /* Task handle (not used)                         */
}


/**
 * @brief Set the LED outputs mode.
 *
 * Will set an LED output to the intial state of the mode requested
 *
 * @param LEDNumber - which LED is being addressed
 * @param mode - one of the modes defined in the LEDsOut.h file
 * @return error code, 0 no error, -1 mode not defined, -2 if LEDNumber out of range.
 */
int LEDSOut_Set(unsigned int LEDNumber, unsigned int mode) 
{
  int retCode = 0;
    
  if (mode >= LEDSOUT_MODE_INVALID)
  {
    retCode = -1;
  }
  else if (LEDNumber >= LEDSOUT_COUNT)
  {
    retCode = -2;
  }
  else
  {
    Leds[LEDNumber].mode = mode;
    Leds[LEDNumber].count = 0;    
    Leds[LEDNumber].state = 0;    
    retCode = 0;
  }

  return retCode;
}



/* State machine that blinks the LEDs */
void LEDSOut_Task(void *arg) {
  int i;
  uint8_t tempOutput;
    
  (void)arg;  // Just to get rid of compiler warning . . .

  xLastTransactionTime = xTaskGetTickCount();
  
  while (1)
  {
    for (i = 0; i < LEDSOUT_COUNT; ++i)
    {
        switch (Leds[i].mode)
        {
        case LEDSOUT_OFF:
            tempOutput = Indicators_Read();
            tempOutput &= AndMasks[i];
            Indicators_Write(tempOutput);
          
          break;
        case LEDSOUT_STEADY_ON:
            tempOutput = Indicators_Read();
            tempOutput |= OrMasks[i];
            Indicators_Write(tempOutput);
          
          break;
        case LEDSOUT_SLOW:
            switch (Leds[i].state)
            {
                case LEDSOUT_SLOW_ON:
                    tempOutput = Indicators_Read();
                    tempOutput |= OrMasks[i];
                    Indicators_Write(tempOutput);
                    Leds[i].count = Leds[i].count + LEDSOUT_RATE_TICK;
                    if (Leds[i].count >= LEDSOUT_RATE_SLOW)
                    {
                        Leds[i].state = LEDSOUT_SLOW_OFF;
                        Leds[i].count = 0;
                    }
                                    
                break;
                case LEDSOUT_SLOW_OFF:
                    tempOutput = Indicators_Read();
                    tempOutput &= AndMasks[i];
                    Indicators_Write(tempOutput);
                    Leds[i].count = Leds[i].count + LEDSOUT_RATE_TICK;
                    if (Leds[i].count >= LEDSOUT_RATE_SLOW)
                    {
                        Leds[i].state = LEDSOUT_SLOW_ON;
                        Leds[i].count = 0;
                    }
                
                break;
                default:
                    Leds[i].state = LEDSOUT_SLOW_ON;
                    break;
            }
          
          break;
        case LEDSOUT_FAST:
            switch (Leds[i].state)
            {
                case LEDSOUT_FAST_ON:
                    tempOutput = Indicators_Read();
                    tempOutput |= OrMasks[i];
                    Indicators_Write(tempOutput);
                    Leds[i].count = Leds[i].count + LEDSOUT_RATE_TICK;
                    if (Leds[i].count >= LEDSOUT_RATE_FAST)
                    {
                        Leds[i].state = LEDSOUT_FAST_OFF;
                        Leds[i].count = 0;
                    }
                                    
                break;
                
                break;
                case LEDSOUT_FAST_OFF:
                    tempOutput = Indicators_Read();
                    tempOutput &= AndMasks[i];
                    Indicators_Write(tempOutput);
                    Leds[i].count = Leds[i].count + LEDSOUT_RATE_TICK;
                    if (Leds[i].count >= LEDSOUT_RATE_FAST)
                    {
                        Leds[i].state = LEDSOUT_FAST_ON;
                        Leds[i].count = 0;
                    }
                
                break;
                default:
                    Leds[i].state = LEDSOUT_FAST_ON;
                
                break;
            }
          
          break;
        case LEDSOUT_DOUBLE:
            switch (Leds[i].state)
            {
                case LEDSOUT_DOUBLE_ONE_ON:
                    tempOutput = Indicators_Read();
                    tempOutput |= OrMasks[i];
                    Indicators_Write(tempOutput);
                    Leds[i].count = Leds[i].count + LEDSOUT_RATE_TICK;
                    if (Leds[i].count >= LEDSOUT_RATE_FAST)
                    {
                        Leds[i].state = LEDSOUT_DOUBLE_ONE_OFF;
                        Leds[i].count = 0;
                    }
                
                break;
                case LEDSOUT_DOUBLE_ONE_OFF:
                    tempOutput = Indicators_Read();
                    tempOutput &= AndMasks[i];
                    Indicators_Write(tempOutput);
                    Leds[i].count = Leds[i].count + LEDSOUT_RATE_TICK;
                    if (Leds[i].count >= LEDSOUT_RATE_FAST)
                    {
                        Leds[i].state = LEDSOUT_DOUBLE_TWO_ON;
                        Leds[i].count = 0;
                    }
                
                break;
                case LEDSOUT_DOUBLE_TWO_ON:
                    tempOutput = Indicators_Read();
                    tempOutput |= OrMasks[i];
                    Indicators_Write(tempOutput);
                    Leds[i].count = Leds[i].count + LEDSOUT_RATE_TICK;
                    if (Leds[i].count >= LEDSOUT_RATE_FAST)
                    {
                        Leds[i].state = LEDSOUT_DOUBLE_TWO_OFF;
                        Leds[i].count = 0;
                    }
                
                break;
                case LEDSOUT_DOUBLE_TWO_OFF:
                    tempOutput = Indicators_Read();
                    tempOutput &= AndMasks[i];
                    Indicators_Write(tempOutput);
                    Leds[i].count = Leds[i].count + LEDSOUT_RATE_TICK;
                    if (Leds[i].count >= LEDSOUT_RATE_FAST)
                    {
                        Leds[i].state = LEDSOUT_DOUBLE_PAUSE;
                        Leds[i].count = 0;
                    }
                
                break;
                case LEDSOUT_DOUBLE_PAUSE:
                    tempOutput = Indicators_Read();
                    tempOutput &= AndMasks[i];
                    Indicators_Write(tempOutput);
                    Leds[i].count = Leds[i].count + LEDSOUT_RATE_TICK;
                    if (Leds[i].count >= LEDSOUT_RATE_SLOW)
                    {
                        Leds[i].state = LEDSOUT_DOUBLE_ONE_ON;
                        Leds[i].count = 0;
                    }
                
                break;
                default:
                    Leds[i].state = LEDSOUT_DOUBLE_ONE_ON;
                
                break;
            }
          
          break;
        case LEDSOUT_TRIPLE:
            switch (Leds[i].state)
            {
                case LEDSOUT_TRIPLE_ONE_ON:
                    tempOutput = Indicators_Read();
                    tempOutput |= OrMasks[i];
                    Indicators_Write(tempOutput);
                    Leds[i].count = Leds[i].count + LEDSOUT_RATE_TICK;
                    if (Leds[i].count >= LEDSOUT_RATE_FAST)
                    {
                        Leds[i].state = LEDSOUT_TRIPLE_ONE_OFF;
                        Leds[i].count = 0;
                    }
                
                
                break;
                case LEDSOUT_TRIPLE_ONE_OFF:
                    tempOutput = Indicators_Read();
                    tempOutput &= AndMasks[i];
                    Indicators_Write(tempOutput);
                    Leds[i].count = Leds[i].count + LEDSOUT_RATE_TICK;
                    if (Leds[i].count >= LEDSOUT_RATE_FAST)
                    {
                        Leds[i].state = LEDSOUT_TRIPLE_TWO_ON;
                        Leds[i].count = 0;
                    }
                
                break;
                case LEDSOUT_TRIPLE_TWO_ON:
                    tempOutput = Indicators_Read();
                    tempOutput |= OrMasks[i];
                    Indicators_Write(tempOutput);
                    Leds[i].count = Leds[i].count + LEDSOUT_RATE_TICK;
                    if (Leds[i].count >= LEDSOUT_RATE_FAST)
                    {
                        Leds[i].state = LEDSOUT_TRIPLE_TWO_OFF;
                        Leds[i].count = 0;
                    }
                
                
                break;
                case LEDSOUT_TRIPLE_TWO_OFF:
                    tempOutput = Indicators_Read();
                    tempOutput &= AndMasks[i];
                    Indicators_Write(tempOutput);
                    Leds[i].count = Leds[i].count + LEDSOUT_RATE_TICK;
                    if (Leds[i].count >= LEDSOUT_RATE_FAST)
                    {
                        Leds[i].state = LEDSOUT_TRIPLE_THREE_ON;
                        Leds[i].count = 0;
                    }
                
                break;
                case LEDSOUT_TRIPLE_THREE_ON:
                    tempOutput = Indicators_Read();
                    tempOutput |= OrMasks[i];
                    Indicators_Write(tempOutput);
                    Leds[i].count = Leds[i].count + LEDSOUT_RATE_TICK;
                    if (Leds[i].count >= LEDSOUT_RATE_FAST)
                    {
                        Leds[i].state = LEDSOUT_TRIPLE_THREE_OFF;
                        Leds[i].count = 0;
                    }
                
                
                break;
                case LEDSOUT_TRIPLE_THREE_OFF:
                    tempOutput = Indicators_Read();
                    tempOutput &= AndMasks[i];
                    Indicators_Write(tempOutput);
                    Leds[i].count = Leds[i].count + LEDSOUT_RATE_TICK;
                    if (Leds[i].count >= LEDSOUT_RATE_FAST)
                    {
                        Leds[i].state = LEDSOUT_TRIPLE_PAUSE;
                        Leds[i].count = 0;
                    }
          
                break;
                case LEDSOUT_TRIPLE_PAUSE:
                    tempOutput = Indicators_Read();
                    tempOutput &= AndMasks[i];
                    Indicators_Write(tempOutput);
                    Leds[i].count = Leds[i].count + LEDSOUT_RATE_TICK;
                    if (Leds[i].count >= LEDSOUT_RATE_FAST)
                    {
                        Leds[i].state = LEDSOUT_TRIPLE_ONE_ON;
                        Leds[i].count = 0;
                    }
                
                break;
                default:
                    Leds[i].state = LEDSOUT_TRIPLE_ONE_ON;
                
                break;
            }
          
          break;
        case LEDSOUT_DASH_DOT:
            switch (Leds[i].state)
            {
                case LEDSOUT_DASH_ON:
                    tempOutput = Indicators_Read();
                    tempOutput |= OrMasks[i];
                    Indicators_Write(tempOutput);
                    Leds[i].count = Leds[i].count + LEDSOUT_RATE_TICK;
                    if (Leds[i].count >= LEDSOUT_RATE_SLOW)
                    {
                        Leds[i].state = LEDSOUT_DASH_OFF;
                        Leds[i].count = 0;
                    }
          
                break;
                case LEDSOUT_DASH_OFF:
                    tempOutput = Indicators_Read();
                    tempOutput &= AndMasks[i];
                    Indicators_Write(tempOutput);
                    Leds[i].count = Leds[i].count + LEDSOUT_RATE_TICK;
                    if (Leds[i].count >= LEDSOUT_RATE_FAST)
                    {
                        Leds[i].state = LEDSOUT_DOT_ON;
                        Leds[i].count = 0;
                    }
          
                break;
                case LEDSOUT_DOT_ON:
                    tempOutput = Indicators_Read();
                    tempOutput |= OrMasks[i];
                    Indicators_Write(tempOutput);
                    Leds[i].count = Leds[i].count + LEDSOUT_RATE_TICK;
                    if (Leds[i].count >= LEDSOUT_RATE_FAST)
                    {
                        Leds[i].state = LEDSOUT_DOT_OFF;
                        Leds[i].count = 0;
                    }
          
                break;
                case LEDSOUT_DOT_OFF:
                    tempOutput = Indicators_Read();
                    tempOutput &= AndMasks[i];
                    Indicators_Write(tempOutput);
                    Leds[i].count = Leds[i].count + LEDSOUT_RATE_TICK;
                    if (Leds[i].count >= LEDSOUT_RATE_SLOW)
                    {
                        Leds[i].state = LEDSOUT_DASH_ON;
                        Leds[i].count = 0;
                    }
                
                break;
                default:
                    Leds[i].state = LEDSOUT_DASH_ON;
                
                break;
          
                break;
            }
          break;
            default:
            Leds[i].mode = LEDSOUT_FAST;
            break;
        }     
    }
          
    vTaskDelayUntil( &xLastTransactionTime, pdMS_TO_TICKS(LEDSOUT_RATE_TICK) );
  }
}





/* [] END OF FILE */
