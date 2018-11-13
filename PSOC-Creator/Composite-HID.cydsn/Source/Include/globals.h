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
 * @file   globals.h
 * @author Mike McCormack (nbxmike)
 * @date   8/OCT/2018
 * @brief  Universally used prototypes and constants.
 */

#ifndef PSX_GLOBALS_H
#define PSX_GLOBALS_H

/* Flags to indicate the state of USB host and sub functions */
#define USB_UNSET        0                //!< USB is starting or reset
#define USB_INITIALIZED  1                //!< Host has initialized the USB
#define USB_RECONFIGURED 2                //!< There was an intial or re configuration
extern volatile int USBConfigurationCDC;  //!< Virtual UART USB configuration status
extern volatile int USBConfigurationHID;  //!< USB game controller configuration status
extern volatile int USBConfigurationHost; //!< USB EP0 configuration status

extern void Err_Rpt( const char* );

#endif
/* End of File */
