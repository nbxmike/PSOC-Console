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
 * @file   PSxHost.h
 * @author Mike McCormack (nbxmike)
 * @date   8/OCT/2018
 * @brief  The host interface to PlayStation 1/2 controllers prototypes and constants.
 */

#ifndef PSXHOST_H
#define PSXHOST_H

#include <project.h>

extern int   Feedback0, Feedback1;  
  
#define PSx_MAX_MESSAGE    37
#define NOWAIT             0
#define YESWAIT            1
#define ACK_DELAY          16 // 10uS counts, so 160uS
#define ENTERCONFIG        1
#define EXITCONFIG         0
#define LONGRESET          1
#define SHORTRESET         0
#define PSx_XFR_PAUSE      16

/*
 *   Game controllers sending back different messages
 */
#define NOTPRESENT 0     //
#define MOUSE      1     // SCPH-1030
#define NEGCON     2     // Namco SLPH-00001
#define GUNK       3     // Konami SLPH-00014 
#define DIGITAL16  4     // SCPH-1080, 1150, 1180, 1200, 10100, 10520
#define ANALOGJOY  5     // SCPH-1110, 1150, 1180
#define GUNN       6     // Namco SLPH-00034 
#define DUALANALOG 7     // SCPH-1150, 1180, 1200, 10100, 10520
#define MULTITAP0  8     // SCPH-1070
#define DUALSHOCK2 0x17  // SCPH-10100

typedef struct controllerinstance
  {
    uint8 Type;
    uint8 Model;
    uint8 Actuators;
    uint8 Modes;
    uint8 CurrentMode;
    uint8 SupportsConfig;
  } ControllerInstance;
  
typedef struct mousedata
  {
    uint8 TypeCount;
    uint8 Buttons0;
    uint8 Buttons1;
    uint8 Xaxis;
    uint8 Yaxis;
  } MouseData;
  
typedef struct negcon
  {
    uint8 TypeCount;
    uint8 Buttons0;
    uint8 Buttons1;
    uint8 Rotation;
    uint8 I_Button;
    uint8 II_Button;
    uint8 L_Button;
  } NegCon;

typedef struct gunk
  {
    uint8 TypeCount;
    uint8 Buttons0;
    uint8 Buttons1;
  } GunK;
  
typedef struct digital16
  {
    uint8 TypeCount;
    uint8 Buttons0;
    uint8 Buttons1;
  } Digital16;

typedef struct analogjoy
  {
    uint8 TypeCount;
    uint8 Buttons0;
    uint8 Buttons1;
    uint8 RightX;
    uint8 RightY;
    uint8 LeftX;
    uint8 LeftY;
  } AnalogJoy;
  
typedef struct gunn
  {
    uint8 TypeCount;
    uint8 Buttons0;
    uint8 Buttons1;
    uint8 XLow;
    uint8 XHigh;
    uint8 YLow;
    uint8 YHigh;
  } GunN;
  
typedef struct dualanalog
  {
    uint8 TypeCount;
    uint8 Buttons0;
    uint8 Buttons1;
    uint8 RightX;
    uint8 RightY;
    uint8 LeftX;
    uint8 LeftY;
  } DualAnalog;
  
void PSxInit(void);
int  PSxEnPressure(int);
int  PSxMotorPoll(int, int);
int  PSxConfigPoll(int);
int  PSxGetModel(void);
void PSxReset(int);
int  PSxGetCtlrType(void);
int  PSxTrasnferString(uint8* , uint8* , int, int );
int  PSxTrasnferByte(uint8, uint8*, int);
void PSx_Host_Task( void* );


#endif
/* End of File */
