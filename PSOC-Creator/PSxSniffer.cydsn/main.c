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
#include "usb_comm.h"

uint8 OutString[128];
int   MsgCount = 0;
int   i, j, temp;  // General globals that don't overlap
volatile int CounterValue;

uint16 MsgTime;
uint16 MsgLastTime = 0;
uint16 MsgElapseTime;


/*
 *  Message uses the ESC (0x1b) character to delimit fields
 *   0x1b | 0x00 is the expansion of a data byte of 0x1b into encapulated data
 *   0x1b | 0x01 is the start of a new tranmission which has a header of elapsed time & message count 
 *   0x1b | 0x02 is the start of MOSI data
 *   0x1b | 0x03 is the start of MISO data
 *   0x1b | 0x04 is the end of message
 */
int MsgFormat( void )
{
  
  j=0;
  OutString[j++] = 0x1b;
  OutString[j++] = 0x01;
  
  //Store the elapsed time, time counts down
  MsgTime = Timebase_ReadCounter();
  MsgElapseTime = MsgLastTime - MsgTime;
  MsgLastTime = MsgTime;
  
  for (i=0; i< 2;++i)
  {
    OutString[j++]= MsgElapseTime & 0xff;
    if( OutString[j-1] == 0x1b )
    {
      OutString[j++] = 0x00;
    }
    MsgElapseTime = MsgElapseTime >> 8;
  }
  
  temp = MsgCount++;
  for (i=0; i< 2;++i)
  {
    OutString[j++]= temp & 0xff;
    if( OutString[j-1] == 0x1b )
    {
      OutString[j++] = 0x00;
    }
    temp = temp >> 8;
  }
  
  OutString[j++] = (uint8)PSx_ACK_Count_ReadCounter();
  PSx_ACK_Count_WriteCounter(0);
  if( OutString[j-1] == 0x1b )
    {
      OutString[j++] = 0x00;
    }
  
  
  // Data from the PlayStation
  OutString[j++] = 0x1b;
  OutString[j++] = 0x02;
  while ( SPIS_MOSI_GetRxBufferSize() )
  {
    OutString[j++] = SPIS_MOSI_ReadRxData();
    if (OutString[j-1] == 0x1b)
    {
      OutString[j++] = 0x00;
    }
  }
  
    // Data from the Controller
  OutString[j++] = 0x1b;
  OutString[j++] = 0x03;
  while ( SPIS_MISO_GetRxBufferSize() )
  {
    OutString[j++] = SPIS_MISO_ReadRxData();
    if (OutString[j-1] == 0x1b)
    {
      OutString[j++] = 0x00;
    }
  }
  
  OutString[j++] = 0x1b;
  OutString[j++] = 0x04;
  
  return j;
}


int main(void)
{
  CyGlobalIntEnable; /* Enable global interrupts. */

  Timebase_Start();
  PSx_ACK_Count_Start();
  
  MsgLastTime = MsgTime = Timebase_ReadCounter();
  
    USBUART_Start(0u, USBUART_5V_OPERATION);
    
    SPIS_MOSI_Start();
    SPIS_MISO_Start();

    for(;;)
    {
      CounterValue = Timebase_ReadCounter();
      if (0x200 & CounterValue)
      {
        LED_Write(0);
      }
      else
      {
        LED_Write(1);
      }
      
      if( 0x01 & Status_Reg_Read() )
      {
        i = MsgFormat( );
        USB_Send(OutString, i );
      }
    }
}

/* [] END OF FILE */
