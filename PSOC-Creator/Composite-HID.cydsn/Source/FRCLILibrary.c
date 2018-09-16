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
#include "FRSupport.h"
#include <stdio.h>
#include <string.h>
#include "FreeRTOS.h"
#include "FreeRTOS_CLI.h"
#include "timers.h"


#define MAX_INPUT_LENGTH		50
//#define MAX_OUTPUT_LENGTH   configCOMMAND_INT_MAX_OUTPUT_SIZE
#define MAX_OUTPUT_LENGTH		128



/*****************************************************************************\
*
\*****************************************************************************/
BaseType_t echoCommand(char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString) {
  (void)xWriteBufferLen;
  strcpy(pcCommandString, pcWriteBuffer);
  return (pdFALSE);
}


static const CLI_Command_Definition_t echoCommandStruct =
{
  "echo",
  "echo: Prints the command line as entered, no processing\n",
  echoCommand,
  0   // No arguments
};

/*****************************************************************************\
* Function:    cliTask
* Input:       void *arg  ... unused
* Returns:     void
* Description:
*     This function is the inifite loop for the command line intepreter.. it
*     reads characters using the FreeRTOS_read function then sends them to the
*     cli when there is a \r
\*****************************************************************************/
void cliTask(void *arg) {
  (void)arg;

  char pcOutputString[MAX_OUTPUT_LENGTH], pcInputString[MAX_INPUT_LENGTH];
  int8_t cRxedChar, cInputIndex = 0;
  BaseType_t xMoreDataToFollow;

  FreeRTOS_open((const int8_t *)"/uart", 0);
#define INTRO_STRING    "Command Line & RTC Demo\n"
  FreeRTOS_write(0, INTRO_STRING, strlen(INTRO_STRING));

  RTC_Start();

  FreeRTOS_CLIRegisterCommand(&echoCommandStruct);
  while (1)
  {
    FreeRTOS_read(0, &cRxedChar, sizeof(cRxedChar));
    if (cRxedChar == '\r') {
      /* A newline character was received, so the input command string is
       * complete and can be processed.  Transmit a line separator, just to
       * make the output easier to read. */

      FreeRTOS_write(0, &cRxedChar, 1);

      /* The command interpreter is called repeatedly until it returns
       * pdFALSE.  See the "Implementing a command" documentation for an
       * exaplanation of why this is. */
      do
      {
        /* Send the command string to the command interpreter.  Any
         * output generated by the command interpreter will be placed in the
         * pcOutputString buffer. */

        xMoreDataToFollow = FreeRTOS_CLIProcessCommand
            (
          pcInputString,                            /* The command string.*/
          pcOutputString,                           /* The output buffer. */
          MAX_OUTPUT_LENGTH                         /* The size of the output buffer. */
            );

        /* Write the output generated by the command interpreter to the
         * console. */

        FreeRTOS_write(0, pcOutputString, strlen(pcOutputString));
      } while (xMoreDataToFollow != pdFALSE);

      /* All the strings generated by the input command have been sent.
       * Processing of the command is complete.  Clear the input string ready
       * to receive the next command. */
      cInputIndex = 0;
      memset(pcInputString, 0x00, MAX_INPUT_LENGTH);
    }
    else{
      /* The if() clause performs the processing after a newline character
       * is received.  This else clause performs the processing if any other
       * character is received. */

      if (cRxedChar == 127) {      // delete character
        FreeRTOS_write(0, &cRxedChar, 1);

        /* Backspace was pressed.  Erase the last character in the input
         * buffer - if there are any. */
        if (cInputIndex > 0) {
          cInputIndex--;
          pcInputString[cInputIndex] = '\0';
        }
      }
      else{
        /* A character was entered.  It was not a new line, backspace
         * or carriage return, so it is accepted as part of the input and
         * placed into the input buffer.  When a \n is entered the complete
         * string will be passed to the command interpreter. */
        if (cInputIndex < MAX_INPUT_LENGTH) {
          FreeRTOS_write(0, &cRxedChar, 1);
          pcInputString[cInputIndex] = cRxedChar;
          cInputIndex++;
        }
      }
    }
  }
}


// An example Task
void ledTask(void *arg) {
  (void)arg;
  while (1)
  {
    Indicators_Write(0x02^Indicators_Read());
    vTaskDelay(500);
  }
}
