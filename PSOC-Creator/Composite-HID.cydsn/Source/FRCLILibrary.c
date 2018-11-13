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
/** @file FRCLILibrary.c
 *  @author Mike McCormack (nbxmike)
 *  @date   8/OCT/2018
 *  @brief Support library and port of CLI task to Cypress PSOC 5LP
 *
 *  Support library for the FreeRTOS command line interpreter and port of their
 *  CLI task to Cypress PSOC 5LP.  All the CH_xxx deal with the CLI Human 
 *  interface device.  This will typically be a real or virtual UART device;
 *  for the present build it is a USB virtual UART (CDC device).
 */

#include "project.h"
#include "FreeRTOS.h"
#include "FRSupport.h"
#include <stdio.h>
#include <string.h>
#include "FreeRTOS_CLI.h"
#include "timers.h"
#include "semphr.h"
#include "FRCLILibrary.h"
#include "USBHost.h"
#include "globals.h"

static int sCH_Startup = USB_UNSET;


/** @brief CH_Init starts the user's comm port
 *
 * CH_Init will start the interface and clear and data that was present
 * before it begins.  Typically there will be nothing as this should
 * start at power up, but just in case . . . 
 */
void CH_Init(void) 
{
  sCH_Startup = USB_UNSET;
  CH_StartUp();
  xTaskCreate(cliTask, "CLI Task", configMINIMAL_STACK_SIZE*3, 0, 2, 0);
}

/** @brief CH_StartUp cleans up the USB if it is configured/recofigured 
 *
 * CH_StartUp will see to it that data in the buffer is cleared if the USB
 * changes configuration either intially or after the systems has started.
 */
int CH_StartUp(void)
{
  xSemaphoreTake( xUSBConfig_Semaphore, USBHOST_CONFIG_WAIT );
  if (USBConfigurationCDC == USB_UNSET)
  {
    sCH_Startup = USB_UNSET;
  }
  else if ((sCH_Startup == USB_UNSET) && (USBConfigurationCDC & USB_INITIALIZED))
  {
    sCH_Startup = USB_RECONFIGURED + USB_INITIALIZED;
    USBConfigurationCDC = USB_INITIALIZED;
  }
  else if ((sCH_Startup == USB_INITIALIZED) && (USBConfigurationCDC & USB_RECONFIGURED))
  {
    sCH_Startup |= USB_RECONFIGURED;
    USBConfigurationCDC = USB_INITIALIZED;
  }
  xSemaphoreGive(xUSBConfig_Semaphore);
  
  if (sCH_Startup & USB_RECONFIGURED)
  {
    sCH_Startup = USB_INITIALIZED;    
    
    USBCOMP_CDC_Init();
    while(USBCOMP_DataIsReady())
    {
      USBCOMP_GetChar();
    }  
  }
  return sCH_Startup;
}

/** @brief CH_DeviceReady checks for console input
 *
 * CH_DeviceReady returns zero unless the system has completed initialization
 * of the CLI Human interface device.  This does not configure the device, it
 * merely checks status.  It is needed to ensure that virtual UARTs are started
 * on the host side of a USB CDC device, if a harware UART is used then this
 * could be replaced with a macro which always returns 1 (unless there is some
 * error checking or protocol handshake that needs to get done.)
 */
uint8  CH_DeviceReady(void)
{
  return (USBConfigurationCDC & USB_INITIALIZED);
}

/** @brief CH_DataIsReady checks for console input
 *
 * CH_DataIsReady looks to see if there is user input in the device buffer.
 * In this implementation, it also checks if the USB has be reset by the host
 * and if so will run the init routine.
 */
uint8  CH_DataIsReady(void)
{
  if (USBConfigurationCDC & USB_RECONFIGURED)
  {
    CH_StartUp();
  }

  if (USBConfigurationCDC & USB_INITIALIZED)
  {
    return USBCOMP_DataIsReady();
  }
  return 0;
}

/** @brief CH_GetChar returns the next user input byte
 *
 * CH_GetChar will return the next byte form the user input in the device 
 * buffer.  This routine does not check if there is data to be obtained, it
 * should only be called if the CH_DataIsReady function indicates there is
 * data to be had.  In this implementation, it also checks if the USB has 
 * been reset by the host and if so will run the init routine; in this case
 * the CH_GetChar routine returns a newline to terminate any input that was
 * in process when the USB was reset/restarted.
 */
uint8  CH_GetChar(void)
{
  if (USBConfigurationCDC & USB_RECONFIGURED)
  {
    CH_StartUp();
    return '\n';   // Only reasonable thing to do is end any pending command.
  }

  if (USBConfigurationCDC & USB_INITIALIZED)
  {
    return USBCOMP_GetChar();
  }
  return 0;
}

/** @brief CH_GetCharWait return the next user byte and will wait if it is not avialible
 *
 * CH_GetCharWait will return the next byte form the user input in the device 
 * buffer.  This routine checks if data is avialable and if not will wait; the
 * wait is for 10mS or until data is sent by the host, which ever comes first.
 * If 10ms has expired and there is still no data the fnction waits another 
 * 10ms. In this implementation, it also checks if the USB has been reset by 
 * the host and if so will run the init routine; in this case the 
 * CH_GetCharWait routine returns a newline to terminate any input that was
 * in process when the USB was reset/restarted.
 */
uint8  CH_GetCharWait(void)
{
  while(1)
  {
    if (USBConfigurationCDC & USB_RECONFIGURED)
    {
      CH_StartUp();
      return '\n';   // Only reasonable thing to do is end any pending command.
    }

    if (USBConfigurationCDC & USB_INITIALIZED)
    {
      if(CH_DataIsReady() != 0 )
      {
        return USBCOMP_GetChar();
      }
    }
    xSemaphoreTake( xCH_Semaphore, ( TickType_t ) 10 );
  }
}


/** @brief CH_PutData puts arbitrary data in the send buffer
 *
 * CH_PutData will put any bytes in the output buffer of the user interface
 * device.  The number of bytes to send must be specified.  For null terminated
 * strings CH_PutString is a more friendly call.  In this implementation, it 
 * also checks if the USB has been reset by the host and if so will run the 
 * USB init routine.
 */
void CH_PutData(const uint8* pData, uint16 length)
{
  if (USBConfigurationCDC & USB_RECONFIGURED)
  {
    CH_StartUp();
  }

  if (USBConfigurationCDC & USB_INITIALIZED)
  {
    USBCOMP_PutData(pData, length) ;
  }
}

/** @brief CH_PutString puts a character string in the send buffer
 *
 * CH_PutString will put a null terminated string into the output buffer of 
 * the user interface device.  For arbitrary byte which may include zeros, 
 * CH_PutData is the proper interface call.  In this implementation, it 
 * also checks if the USB has been reset by the host and if so will run the 
 * USB init routine.
 */
void CH_PutString(const char *string)
{
  if (USBConfigurationCDC & USB_RECONFIGURED)
  {
    CH_StartUp();
  }

  if (USBConfigurationCDC & USB_INITIALIZED)
  {
    USBCOMP_PutString(string);
  }
}

/** @brief CH_PutChar puts a single character in the send buffer
 *
 * CH_PutChar will put a single character into the output buffer of the user
 * interface device.  Since this will copy any value, it is suitable for
 * arbitrary byte which may include zeros or printable characters equally well.
 * In this implementation, it also checks if the USB has been reset by the host
 * and if so will run the USB init routine.
 */
void CH_PutChar(char txDataByte)
{
  if (USBConfigurationCDC & USB_RECONFIGURED)
  {
    CH_StartUp();
  }

  if (USBConfigurationCDC & USB_INITIALIZED)
  {
    USBCOMP_PutChar(txDataByte);
  }
}


/** @brief echoCommand process an echo command at the CLI
 *
 * echoCommand is called by the FreeRTOS CLI tool when the user input starts
 * with echo.  This is a demonstration command to provide a platform
 * independant command that can always be present.  Delete from your port of
 * the FreeRTOS CLI if you need the space.
 */
BaseType_t echoCommand(char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString) {
  (void)xWriteBufferLen;
  strcpy(pcCommandString, pcWriteBuffer);
  return (pdFALSE);
}

/** @brief USBFS_EP_3_ISR_EntryCallback ISR hook to tell foeground data may be ready.
 *
 * USBFS_EP_3_ISR_EntryCallback is called by the USB IRQ handler when there is
 * a data transfer from the host.  It is unclear if this is called when the 
 * data field is zero lenght or if the tranfer was found to be corrupt so the
 * foreground must still check if data is available.
 * This hook can change even for the PSOC parts if the USB endpoints for the 
 * virtual UART change.  That means it may be necessary to port this when the
 * configuration changes, not just when the processor does.
 */
void USBCOMP_EP_3_ISR_ExitCallback(void)
{
  static BaseType_t xHigherPriorityTaskWoken;
  xHigherPriorityTaskWoken = pdFALSE;
  if( xCH_Semaphore != NULL )
  {
    xSemaphoreGiveFromISR( xCH_Semaphore, &xHigherPriorityTaskWoken );
    if (xHigherPriorityTaskWoken == pdTRUE)
    {
      portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
    }
  }
}

static const CLI_Command_Definition_t echoCommandStruct =
{
  "echo",
  "echo: Prints the command line as entered, no processing\n",
  echoCommand,
  0
};

/** @brief cliTask task which invokes the FreeRTOS CLI engine
 *
 * cliTask process the user input on the command line.  At present it only
 * support character input and backspace editing; there is no support for
 * cursor movement or anything else.  To make things as platform independant
 * as possible this accepts DEL or BS as backspace, accepts CR, LF, or CR-LF
 * as input termination.
 */
void cliTask(void *arg) {
  (void)arg;

  char OutBuffer[CLI_MAX_OUTPUT], InBuffer[CLI_MAX_INPUT];
  uint8_t cli_c, cli_lastc;
  int cli_index;
  BaseType_t cli_more;

  cli_c = cli_lastc = 0;
  cli_index = 0;
  
  // Register commands with the CLI processor
  FreeRTOS_CLIRegisterCommand(&echoCommandStruct);
  
  // Wait for the UART to at least start
  while( CH_DeviceReady() == 0 )
  {
    xSemaphoreTake( xCH_Semaphore, ( TickType_t ) 10 );
  }  
  CH_PutString(START_MESSAGE);  // Welcome message (probably unseen)


  while (1)
  {
    cli_lastc = cli_c;
    
    cli_c = CH_GetCharWait();
    CH_PutData( &cli_c, 1);

    if ((cli_c == '\x0A' &&  cli_lastc == '\x0D') || (cli_c == '\x0D' &&  cli_lastc == '\x0A'))
    {
      continue;
    }
      
    if( cli_c == '\x0A' || cli_c == '\x0D' )  // CR and LF treated the same
    {
      InBuffer[cli_index] = '\0';
      do
      {
        cli_more = FreeRTOS_CLIProcessCommand( InBuffer, OutBuffer, CLI_MAX_OUTPUT );
        CH_PutString(OutBuffer);
      } while (cli_more != pdFALSE);
      cli_index = 0;
    }
    else if ( cli_c == '\x08' || cli_c == '\x7F' )  // BS and DEL treated the same
    {
      if (cli_index > 0)
      {
        cli_index--;
      }
    }
    else
    {
      InBuffer[cli_index++] = cli_c;
    }
  }    
}
