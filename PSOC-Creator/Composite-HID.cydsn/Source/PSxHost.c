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
 * @file   PSxHost.c
 * @author Mike McCormack (nbxmike)
 * @date   8/OCT/2018
 * @brief  The host side interface of a PlayStation 1/2 controller.
 */

#include <project.h>
#include "FreeRTOS.h"
#include "PSxHost.h"
#include "timers.h"
#include "semphr.h"
#include "FRSupport.h"
#include "globals.h"

uint8 PSxOutBuffer[PSx_MAX_MESSAGE];
uint8 PSxInBuffer[PSx_MAX_MESSAGE];
uint8 PSxXfrBuffer[PSx_MAX_MESSAGE];
int   Feedback0, Feedback1;

static volatile uint8 ACK_Reg_Save;           //!< flag from ISR indicating ACK was received
static ControllerInstance PSxControllerType;  //!< Keeps controller information after i is found
static TickType_t xLastTransactionTime;       //!< Used to pace the PSx transacions


/**
 * @brief The ISR handler for the ACK signal from the PSx game controller.
 *
 * Will give the semaphore to the foreground related to waiting for an
 * ACK from the PSx game controller.  Since the ACK timeout function releases
 * the same semaphore, the foreground must check that ACK was actaully sent to 
 * the host by the game controller.  This checks to ensure the semaphore has
 * been created but really should not be called until the semaphore does
 * exist.
 * @param None, ISR
 * @return None, ISR.  It does release the foreground semaphore.
 */
void PSx_ACK_isr_Interrupt_InterruptCallback(void)
{
  static BaseType_t xHigherPriorityTaskWoken;
  xHigherPriorityTaskWoken = pdFALSE;
  
  ACK_Reg_Save |= PSx_ACKs_Read();
  
  if( xPSx_ACK_Semaphore != NULL )
  {
    xSemaphoreGiveFromISR( xPSx_ACK_Semaphore, &xHigherPriorityTaskWoken );
    if (xHigherPriorityTaskWoken == pdTRUE)
    {
      portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
    }
  }  
}

/**
 * @brief The ISR handler for the timeout of the ACK signal.
 *
 * Will give the semaphore to the foreground related to waiting for an
 * ACK from the PSx game controller if the timeout period has expired.
 * The foreground must check what caused the ACK wait to release,
 * this timeout or an actual ACK.  Checks to ensure the semaphore has
 * been created but really should not be called until the semaphore does
 * exist.
 * @param None, ISR
 * @return None, ISR.  It does release the foreground semaphore.
 */
void Delay_10uS_isr_Interrupt_InterruptCallback(void)
{
  static BaseType_t xHigherPriorityTaskWoken;
  xHigherPriorityTaskWoken = pdFALSE;
  
  Delay_10uS_Stop();
  Delay_10uS_WritePeriod(ACK_DELAY);
  
  if( xPSx_ACK_Semaphore != NULL )
  {
    xSemaphoreGiveFromISR( xPSx_ACK_Semaphore, &xHigherPriorityTaskWoken );
    if (xHigherPriorityTaskWoken == pdTRUE)
    {
      portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
    }
  }  
}

/**
 * @brief The ISR handler for the receive from the PSx game controller.
 *
 * Will give the semaphore to the foreground related to waiting for an
 * data from the PSx game controller.  Checks to ensure the semaphore has
 * been created but really should not be called until the semaphore does
 * exist.
 * @param None, ISR
 * @return None, ISR.  It does release the foreground semaphore.
 */
void PSx_SPI_RX_ISR_ExitCallback(void)
{  
  static BaseType_t xHigherPriorityTaskWoken;
  xHigherPriorityTaskWoken = pdFALSE;
  
  if( xPSx_SPI_Semaphore != NULL )
  {
    xSemaphoreGiveFromISR( xPSx_SPI_Semaphore, &xHigherPriorityTaskWoken );
    if (xHigherPriorityTaskWoken == pdTRUE)
    {
      portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
    }
  }
}

/**
 * @brief Sends and receives a single byte to/from the PSx controller.
 *
 * PSxTrasnferByte will send a byte, and since the interface is forced to be
 * full duplex, it will receive a byte.  If told to wait for and ACK, it will
 * return a non-zero value if an ACK was received, otherwise it will return
 * zero.  Generally speaking, this procedure could use better error handling
 * especially when the dongle handles multiple interfaces errors on one will 
 * seriously impact others if nothing is done to clean up error handling.
 * Recommend using the NOWAIT / YESWAIT defined values as the wait parameter.
 *
 * @param  Out The byte to be sent to the PSx game controller
 * @param  In Pointer to where received data from the PSx game controller is stored
 * @param  Wait If non-zero, the function waits for an ACK
 * @return If zero then no ACK or did not wait, nonzero only if ACK received
 */
int PSxTrasnferByte(uint8 Out, uint8 *In, int Wait) 
{
  int rx_stat;
  int wait_loops = 0;

  rx_stat = PSx_SPI_GetRxBufferSize();
  while (rx_stat == 0)
  {
    PSx_SPI_ReadRxData();
    rx_stat = PSx_SPI_GetRxBufferSize();
    Err_Rpt("PSx SPI input buffer contained data before transfer started\r\n");
  }

  ACK_Reg_Save = 0;
  PSx_SPI_WriteTxData(Out);
  
  rx_stat = PSx_SPI_GetRxBufferSize();
  while (rx_stat == 0)
  {
    xSemaphoreTake( xPSx_SPI_Semaphore, 1 );
    rx_stat = PSx_SPI_GetRxBufferSize();
    if (wait_loops++ >= 5)                   // TODO - do something better
    {
      return 0;
    }
  }
  if  (rx_stat != 0)
  {
    *In = PSx_SPI_ReadRxData();
  }
  else
  {
    *In = 0xff;
    Err_Rpt("PSx SPI never completed\r\n");
  }

  if ( Wait !=0 )
  {
    xSemaphoreTake( xPSx_ACK_Semaphore, 0 );
    if (ACK_Reg_Save == 0)
    {
      Delay_10uS_WritePeriod(ACK_DELAY);
      Delay_10uS_Start();
      xSemaphoreTake( xPSx_ACK_Semaphore, 2 );
      if (ACK_Reg_Save == 0)
      {
        PSx_Control_Write(0x03 | PSx_Control_Read());
        return 0;
      }
    }
    return 1;
  }
  return (0);
}

/**
 * @brief Sends and receives a string of bytes to/from the PSx controller.
 *
 * PSxTrasnferString will send a packet of binary data to the PSx game 
 * controller.  Since the interface is forced to be full duplex, it will 
 * the same number of bytes.  If the wait parameter is non-zero, the 
 * function will wait until there is an AKC for every byte sent.  If the
 * wait parameter is zero, the function will not wait for the final ACK
 * though it will wait for intrabyte ACK.  Should ACKs stop at some point,
 * the procedure stops sending.
 * Recommend using YESWAIT and NOWAIT as the wait parameter.
 *
 * @param  Out The byte to be sent to the PSx game controller
 * @param  In Pointer to where received data from the PSx game controller is stored
 * @param  Wait If zero, the function does not wait for the final ACK
 * @return The number of ACKs received
 * @note If wait is requested, the SS line remains asserted after return
 * @note If wait is not requested the packed is ended (i.e. SS is deasserted)
 */
int PSxTrasnferString(uint8 *Out, uint8 *In, int count, int Wait) 
{
  int rcode = 0;
  int i;
  
  PSx_Control_Write(0xFE & PSx_Control_Read());

  if (count > 0) {
    for (i = 0; i < count-1; ++i) {
      if (PSxTrasnferByte(*Out, In, 1) !=0 )
      {
        ++rcode;
        ++Out;
        ++In;
      }
      else
      {
        return rcode;
      }
    }
  }
  if (Wait != 0)
  {
    rcode += PSxTrasnferByte(*Out, In, 1);
  }
  else
  {
    PSxTrasnferByte(*Out, In, 0);
    PSx_Control_Write(0x03 | PSx_Control_Read());
  }
  return rcode;
}


/**
 * @brief Sends a packet to enable pressure reporting for a button.
 *
 * Some buttons on some PSx controllers can report a value proportional to the
 * amount of pressure that is used to depress the button.  This command creates
 * the necessary packet for the button number provided and sends it to the PSx
 * game controller
 * @param  button The button number to enable pressure sensing
 * @return Non-zero if the complete packet was ACKed, zero if not.
 */
int PSxEnPressure(int button) 
{
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

  rcode = PSxTrasnferString(PSxOutBuffer, PSxInBuffer, 9, NOWAIT);

  return (rcode == 8 );
}


/**
 * @brief Gets the analog and button data and sends the vibration motor levels.
 *
 * This sends the universally accepted poll command to the game controller if
 * one is attached.  For game controllers with "force feedback" the same 
 * message also sets the motor speed.  At present only two motors are supported
 * might need to expand that at some point.  The physical motors are mapped to 
 * these logical control bytes by other commands.
 * @param  Motor0 Speed parameter for first logical motor.
 * @param  Motor1 Speed parameter for second logical motor.
 * @return Number of bytes ACKed by the controller (i.e. transfer - 1).
 * @note Not all motors support speed control, some are on/off only.
 */
int PSxMotorPoll(int Motor0, int Motor1) 
{
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

  rcode = PSxTrasnferString(PSxOutBuffer, PSxInBuffer, 5, YESWAIT);
  if( rcode == 5 )
  {
    temp = 2 * ((PSxInBuffer[1] & 0x0f) - 1);
  
    if ( temp > 1 )
    {
      rcode = rcode + PSxTrasnferString(&PSxOutBuffer[5], &PSxInBuffer[5], temp, NOWAIT);
    }
    else
    {
      PSx_Control_Write(0x03 | PSx_Control_Read());
    }
  }
  return (rcode);
}


/**
 * @brief Gets the analog and button data and enter or exits configuration.
 *
 * This sends the configuration/poll command to the game controller if one is
 * attached.  Not all controllers support this message so the ACKs from a
 * controller may stop at the second byte of the transfer.  Calling routines
 * must check that sufficent bytes were transfered to have entered config
 * mode.
 * Recommend using ENTERCONFIG/EXITCONFIG as the parameter value
 * @param  CfgByte if zero exits configuration, otherwise enters config.
 * @return The number of bytes ACKed is returned.
 */
int PSxConfigPoll(int CfgByte) 
{
  int rcode, temp;
  PSxOutBuffer[0] = 0x01;
  PSxOutBuffer[1] = 0x43;
  PSxOutBuffer[2] = 0x00;
  PSxOutBuffer[3] = ( CfgByte == EXITCONFIG) ? EXITCONFIG : ENTERCONFIG;
  PSxOutBuffer[4]  = PSxOutBuffer[5]  = PSxOutBuffer[6]  = PSxOutBuffer[7]  = PSxOutBuffer[8]  = \
  PSxOutBuffer[9]  = PSxOutBuffer[10] = PSxOutBuffer[11] = PSxOutBuffer[12] = PSxOutBuffer[13] = \
  PSxOutBuffer[14] = PSxOutBuffer[15] = PSxOutBuffer[16] = PSxOutBuffer[17] = PSxOutBuffer[18] = \
  PSxOutBuffer[19] = PSxOutBuffer[20] = PSxOutBuffer[21] = PSxOutBuffer[22] = PSxOutBuffer[23] = \
  PSxOutBuffer[24] = PSxOutBuffer[25] = PSxOutBuffer[26] = PSxOutBuffer[27] = PSxOutBuffer[28] = \
  PSxOutBuffer[29] = PSxOutBuffer[30] = PSxOutBuffer[31] = PSxOutBuffer[32] = PSxOutBuffer[33] = \
  PSxOutBuffer[34] = PSxOutBuffer[35] = PSxOutBuffer[36] = 0x00;

  rcode = PSxTrasnferString(PSxOutBuffer, PSxInBuffer, 5, YESWAIT);
  if( rcode == 5 )
  {
    temp = 2 * ((PSxInBuffer[1] & 0x0f) - 1);
  
    if ( temp > 1 )
    {
      rcode = rcode + PSxTrasnferString(&PSxOutBuffer[5], &PSxInBuffer[5], temp, NOWAIT);
    }
    else
    {
      PSx_Control_Write(0x03 | PSx_Control_Read());
    }
  }
  return rcode;
}


/**
 * @brief Reads the controller type and actuator data.
 *
 * This sends a get model message and if it is successfully received it will
 * fill in elements of the PSxControllerType data structure according to what
 * is received.
 * @param  None
 * @return The number of bytes ACKed is returned.
 * @note Presently this also set the global PSxControllerType elements 
 */
int PSxGetModel(void) 
{
  int rcode;
  PSxOutBuffer[0] = 0x01;
  PSxOutBuffer[1] = 0x45;
  PSxOutBuffer[2]  = PSxOutBuffer[3]  = PSxOutBuffer[4]  = PSxOutBuffer[5]  = \
  PSxOutBuffer[6]  = PSxOutBuffer[7]  = PSxOutBuffer[8]  = PSxOutBuffer[9]  = \
  PSxOutBuffer[10] = PSxOutBuffer[11] = PSxOutBuffer[12] = PSxOutBuffer[13] = \
  PSxOutBuffer[14] = PSxOutBuffer[15] = PSxOutBuffer[16] = PSxOutBuffer[17] = \
  PSxOutBuffer[18] = PSxOutBuffer[19] = PSxOutBuffer[20] = PSxOutBuffer[21] = \
  PSxOutBuffer[22] = PSxOutBuffer[23] = PSxOutBuffer[24] = PSxOutBuffer[25] = \
  PSxOutBuffer[26] = PSxOutBuffer[27] = PSxOutBuffer[28] = PSxOutBuffer[29] = \
  PSxOutBuffer[30] = PSxOutBuffer[31] = PSxOutBuffer[32] = PSxOutBuffer[33] = \
  PSxOutBuffer[34] = PSxOutBuffer[35] = PSxOutBuffer[36] = 0x00;

  rcode = PSxTrasnferString(PSxOutBuffer, PSxInBuffer, 9, NOWAIT);
  if( rcode == 8 )
  {
    PSxControllerType.Model       = PSxInBuffer[3];
    PSxControllerType.Modes       = PSxInBuffer[4];
    PSxControllerType.CurrentMode = PSxInBuffer[5];
    PSxControllerType.Actuators   = PSxInBuffer[6];
  }
  return rcode;
}


/**
 * @brief Sends a messages to the game controller to reset it.
 *
 * This will send the 0x01 first byte only message that a real PlayStation
 * sends when it dislikes the game controller it is talking to such as at
 * power up or when one is plugged in later.
 * @param lenght If length is zero, a 100mS reset is performed, otherwise 1S
 * @return None
 */
void PSxReset(int length) 
{
  int i;
  uint8 temp;
  
  i = ( length == SHORTRESET ) ? 6 : 60;

  for(;i != 0; --i)
  {
    vTaskDelayUntil( &xLastTransactionTime, PSx_XFR_PAUSE );
    PSxTrasnferByte(0x01, &temp, YESWAIT);
    PSx_Control_Write(0x03 | PSx_Control_Read());

  }
}


/**
 * @brief PSxGetCtlrType determine what type of controller is present, if any.
 *
 * First, we just poll the controller and use the reply type to set an inital
 * value for the controller type.  Then we try to enter config mode, and if 
 * that works we try to read the model number.  If the game controller answered
 * the initial poll but not the config, we leave the inital guess as the final
 * answer.  If we never completed any message, we return NOTPRESENT as the
 * answer.
 * @param none
 * @return Controller type
 * @note Presently this also set the global PSxControllerType elements
 */
int PSxGetCtlrType(void) 
{
  int i;
  int tempCtrlr;
  
  vTaskDelayUntil( &xLastTransactionTime, PSx_XFR_PAUSE );
  i = PSxMotorPoll(0,0);
  if ( i >= 5 )
  {
    tempCtrlr = (PSxInBuffer[1] & 0xf0) >> 4 ; 
    if (tempCtrlr == 0x0f)
    {
      tempCtrlr = (PSxInBuffer[1] == 0xf3)? DUALSHOCK2 : 0;
    }
    vTaskDelayUntil( &xLastTransactionTime, PSx_XFR_PAUSE );
    i = PSxConfigPoll(ENTERCONFIG);
    if ( i >= 5 )
    {
      vTaskDelayUntil( &xLastTransactionTime, PSx_XFR_PAUSE );
      i = PSxConfigPoll(ENTERCONFIG);
      if( i == 8 )
      {
        vTaskDelayUntil( &xLastTransactionTime, PSx_XFR_PAUSE );
        i = PSxGetModel();
        if( i == 8 )
        {
          vTaskDelayUntil( &xLastTransactionTime, PSx_XFR_PAUSE );
          PSxGetModel();
          i = PSxConfigPoll(EXITCONFIG);
          if(PSxControllerType.Model == 2 || PSxControllerType.Model == 3)
          {
            tempCtrlr = DUALSHOCK2;
          }
        }
        else 
        {
          tempCtrlr = NOTPRESENT;
        }
      }
      else 
      {
        tempCtrlr = NOTPRESENT;
      }
    }
    else 
    {
      tempCtrlr = NOTPRESENT;
    }
  } 
  else
  {
    tempCtrlr = NOTPRESENT;
  }
  PSxControllerType.Type = tempCtrlr;
  return tempCtrlr;
}

/**
 * @brief Sets up the system to talk to the PSx game controller.
 *
 * Sets up the software mainly, the hardware is largely configured in the
 * PSOC TopDesign.cysch file.  This does nothing to create/setup the FreeRTOS 
 * elements needed to sync physical events to software, it can be called after
 * it has already been called once without problems.
 * @param None
 * @return None
 */
void PSxSetup(void) 
{
  int rx_stat;
  
  Feedback0 = Feedback1 = ACK_Reg_Save = 0;
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

/**
 * @brief Intialization of the PSx game controller - one time only.
 *
 * Sets up the software mainly, the hardware is largely configured in the
 * PSOC TopDesign.cysch file.  This is intended to only be called one time
 * and repeat calls could be problematic.
 * @param None
 * @return None
 */
void PSxInit(void) 
{

  PSxSetup();
  
  xTaskCreate(                  /* Create Playstation Interface task              */
    PSx_Host_Task,              /* Function implementing the task loop            */
    "PSx_Host",                 /* String to locate the task in debugger          */
    configMINIMAL_STACK_SIZE,   /* Task's stack size (FreeTROS allocates)         */
    0,                          /* Number of parameters to pass to task  (none)   */
    3,                          /* Task's priority (medium)                       */
    0);                         /* Task handle (not used)                         */
}

/* PlayStation controller task, getting bigger . . . */
void PSx_Host_Task(void *arg) {
  (void)arg;  // Just to get rid of compiler warning . . .

  xLastTransactionTime = xTaskGetTickCount();
  
  PSxReset(0);
  PSxGetModel();
  while (1)
  {
    Indicators_Write(0x01 ^ Indicators_Read());   // So we can check we're running
    PSxMotorPoll(Feedback0, Feedback1);
    vTaskDelayUntil( &xLastTransactionTime, PSx_XFR_PAUSE );
  }
}


/* End of File */
