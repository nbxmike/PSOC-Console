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
#include "PSxHost.h"
#include "FreeRTOS.h"
#include "timers.h"

uint8 PSxOutBuffer[PSx_MAX_MESSAGE];
uint8 PSxInBuffer[PSx_MAX_MESSAGE];


void PSxInit(void) {
  int rx_stat;
  PSx_Control_Write(0x03 | PSx_Control_Read());
  PSx_SPI_Init();
  PSx_SPI_Enable();
  
  // Clear lingering data
  rx_stat = PSx_SPI_GetRxBufferSize();
  while (rx_stat == 0)
  {
    rx_stat = PSx_SPI_GetRxBufferSize();
    PSx_SPI_ReadRxData();
  }
}


uint8 PSxTrasnferByte(uint8 *Out) {
  int rx_stat;

  PSx_SPI_WriteTxData(*Out);
  rx_stat = PSx_SPI_GetRxBufferSize();
  while (rx_stat == 0)
  {
    rx_stat = PSx_SPI_GetRxBufferSize();
  }
  return (PSx_SPI_ReadRxData());
}


int PSxTrasnferString(uint8 *Out, uint8 *In, int count) {
  int rcode = 0;
  int i;
  
  rcode = PSx_ACKs_Read();
  PSx_Control_Write(0xFE & PSx_Control_Read());

  if (count > 0) {
    for (i = 0; i < count; ++i) {
      *In = PSxTrasnferByte(Out);
      ++Out;
      ++In;
    }
  }

  PSx_Control_Write(0x03 | PSx_Control_Read());
  rcode = PSx_ACKs_Read();

  return rcode;
}


int PSxEnPressure(int button) {
  int rcode;

  PSxOutBuffer[0] = 0x01;
  PSxOutBuffer[1] = 0x40;
  PSxOutBuffer[2] = 0x00;
  PSxOutBuffer[3] = (uint8)button;
  PSxOutBuffer[4] = 0x02;
  PSxOutBuffer[5] = 0x00;
  PSxOutBuffer[6] = 0x00;
  PSxOutBuffer[7] = 0x00;
  PSxOutBuffer[8] = 0x00;

  rcode = PSxTrasnferString(PSxOutBuffer, PSxInBuffer, 8);

  return (rcode);
}


int PSxMotorPoll(int Motor0, int Motor1) {
  int rcode, temp;
  
  PSxOutBuffer[0] = 0x01;
  PSxOutBuffer[1] = 0x42;
  PSxOutBuffer[3] = (uint8) Motor0;
  PSxOutBuffer[4] = (uint8) Motor1;
  PSxOutBuffer[2]  = PSxOutBuffer[5]  = PSxOutBuffer[6]  = PSxOutBuffer[7]  = PSxOutBuffer[8]  = \
  PSxOutBuffer[9]  = PSxOutBuffer[10] = PSxOutBuffer[11] = PSxOutBuffer[12] = PSxOutBuffer[13] = \
  PSxOutBuffer[14] = PSxOutBuffer[15] = PSxOutBuffer[16] = PSxOutBuffer[17] = PSxOutBuffer[18] = \
  PSxOutBuffer[19] = PSxOutBuffer[20] = PSxOutBuffer[21] = PSxOutBuffer[22] = PSxOutBuffer[23] = \
  PSxOutBuffer[24] = PSxOutBuffer[25] = PSxOutBuffer[26] = PSxOutBuffer[27] = PSxOutBuffer[28] = \
  PSxOutBuffer[29] = PSxOutBuffer[30] = PSxOutBuffer[31] = PSxOutBuffer[32] = PSxOutBuffer[33] = \
  PSxOutBuffer[34] = PSxOutBuffer[35] = PSxOutBuffer[36] = 0x00;

  rcode = PSxTrasnferString(PSxOutBuffer, PSxInBuffer, 5);
  temp = 2 * ((PSxInBuffer[1] & 0x0f) - 1);
  
  if ( temp > 1 )
  {
    rcode = rcode | PSxTrasnferString(&PSxOutBuffer[5], &PSxInBuffer[5], temp);
  }

  return (rcode);
}


int PSxConfigPoll(int CfgByte) {
  int rcode, temp;
  PSxOutBuffer[0] = 0x01;
  PSxOutBuffer[1] = 0x43;
  PSxOutBuffer[2] = 0x00;
  PSxOutBuffer[3] = (uint8) CfgByte;
  PSxOutBuffer[4]  = PSxOutBuffer[5]  = PSxOutBuffer[6]  = PSxOutBuffer[7]  = PSxOutBuffer[8]  = \
  PSxOutBuffer[9]  = PSxOutBuffer[10] = PSxOutBuffer[11] = PSxOutBuffer[12] = PSxOutBuffer[13] = \
  PSxOutBuffer[14] = PSxOutBuffer[15] = PSxOutBuffer[16] = PSxOutBuffer[17] = PSxOutBuffer[18] = \
  PSxOutBuffer[19] = PSxOutBuffer[20] = PSxOutBuffer[21] = PSxOutBuffer[22] = PSxOutBuffer[23] = \
  PSxOutBuffer[24] = PSxOutBuffer[25] = PSxOutBuffer[26] = PSxOutBuffer[27] = PSxOutBuffer[28] = \
  PSxOutBuffer[29] = PSxOutBuffer[30] = PSxOutBuffer[31] = PSxOutBuffer[32] = PSxOutBuffer[33] = \
  PSxOutBuffer[34] = PSxOutBuffer[35] = PSxOutBuffer[36] = 0x00;

  rcode = PSxTrasnferString(PSxOutBuffer, PSxInBuffer, 5);
  temp = 2 * ((PSxInBuffer[1] & 0x0f) - 1);
  if ( temp > 1 )
  {
    rcode = rcode | PSxTrasnferString(&PSxOutBuffer[5], &PSxInBuffer[5], temp );
  }

  return (rcode);
}


/* PlayStation controller task, getting bigger . . . */
void PSx_Host_Task(void *arg) {
  (void)arg;  // Just to get rid of compiler warning . . .
  TickType_t xLastWakeTime;
  xLastWakeTime = xTaskGetTickCount();

  while (1)
  {
    Indicators_Write(0x01 ^ Indicators_Read());
    vTaskDelayUntil(&xLastWakeTime, 25);
  }
}


/* End of File */
