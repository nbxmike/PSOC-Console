/* ========================================
 *
 * Copyright 2018 Michael McCormack
 * All Rights Reserved
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
 * @file   cyapicallbacks.h
 * @author Mike McCormack (nbxmike)
 * @date   8/OCT/2018
 * @brief  Cypress PSOC 5LP hooks for interrupt code snippets.
 */

#ifndef CYAPICALLBACKS_H
#define CYAPICALLBACKS_H

  #define USBCOMP_EP_0_ISR_EXIT_CALLBACK
  void    USBCOMP_EP_0_ISR_ExitCallback(void);
  
  #define USBCOMP_EP_3_ISR_EXIT_CALLBACK
  void    USBCOMP_EP_3_ISR_ExitCallback(void);
  
  #define USBCOMP_EP_4_ISR_EXIT_CALLBACK
  void    USBCOMP_EP_4_ISR_ExitCallback(void);

  #define USBCOMP_EP_5_ISR_EXIT_CALLBACK
  void    USBCOMP_EP_5_ISR_ExitCallback(void);

  
  #define PSx_ACK_isr_INTERRUPT_INTERRUPT_CALLBACK
  void    PSx_ACK_isr_Interrupt_InterruptCallback(void);
  
  #define PSx_SPI_RX_ISR_EXIT_CALLBACK
  void    PSx_SPI_RX_ISR_ExitCallback(void);
  
  #define Delay_10uS_isr_INTERRUPT_INTERRUPT_CALLBACK
  void Delay_10uS_isr_Interrupt_InterruptCallback(void);

  #define ADC_IRQ_INTERRUPT_INTERRUPT_CALLBACK
  void ADC_IRQ_Interrupt_InterruptCallback(void);

#endif   
