#!/usr/bin/env python
# * coding: latin-1
#
# Copyright 2018 Michael McCormack
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included
# in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
# CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
# OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
#  The PSx sniffer will send and entire transaction at once across the USB UART
#   it does not send byte by byte data.  This is a design feature of the sniffer
#   which is not true of generic UART interfaces.
#
#  Messages from the PSx Sniffer uses the ESC (0x1b) character to delimit fields
#   0x1b | 0x00 is the expansion of a data byte of 0x1b into encapsulated data
#   0x1b | 0x01 is the start of a new transmission which has a header of elapsed time & message count
#   0x1b | 0x02 is the start of MOSI data
#   0x1b | 0x03 is the start of MISO data
#   0x1b | 0x04 is the end of message
#  Otherwise, a byte is just a data byte

import serial
import sys
import select
import tty
import termios


# import time


def is_data():
    return select.select([sys.stdin], [], [], 0) == ([sys.stdin], [], [])


def validate_escape(number, uart, log):
    if number == 0x1b:
        if uart.inWaiting() > 0:
            if 0 != ord(uart.read()):
                log.write("\n\r** Garbage Encountered\n\r")
                return 0x0fff
            else:
                return 0
        else:
            log.write("\n\r** Garbage Encountered\n\r")
            return 0x0fff
    return number


def psx_header(uart, log):
    if uart.inWaiting() > 4:
        low_byte = validate_escape(ord(uart.read()), uart, log)
        if low_byte > 0xff:
            return False
        high_byte = validate_escape(ord(uart.read()), uart, log)
        if high_byte > 0xff:
            return False
        w = low_byte + (high_byte << 8)
        log.write("\n\r++ et %d" % w)

        if uart.inWaiting() > 1:
            low_byte = validate_escape(ord(uart.read()), uart, log)
            if low_byte > 0xff:
                return False
            high_byte = validate_escape(ord(uart.read()), uart, log)
            if high_byte > 0xff:
                return False
            w = low_byte + (high_byte << 8)
            log.write(", msg %d" % w)

        else:
            log.write("\n\r** Garbage Encountered\n\r")
            return False
    else:
        log.write("\n\r** Garbage Encountered\n\r")
        return False
    return True


if len(sys.argv) < 3:
    print("Usage: python PSxReceiver.py <Controller-String> <virtualUART>")
    sys.exit(0)

ControllerModel = "Unknown Controller "
SerialUART = "/dev/ttyUSB1"
if len(sys.argv) >= 2:
    ControllerModel = sys.argv[2]
if len(sys.argv) >= 3:
    SerialUART = sys.argv[3]

old_settings = termios.tcgetattr(sys.stdin)
try:
    tty.setcbreak(sys.stdin.fileno())
    with serial.Serial(SerialUART) as PSxAnalyzer:
        with open(ControllerModel + "_PSx_Log.txt", "w") as PSxLog:
            PSxLog.write(ControllerModel + " PSx Controller Capture\n\r")

            c = 'A'
            while c != '\x1b':
                if is_data():
                    c = sys.stdin.read(1)
                if PSxAnalyzer.inWaiting() > 0:
                    x = ord(PSxAnalyzer.read())
                    if x == 0x1b:
                        if PSxAnalyzer.inWaiting() > 0:
                            x = ord(PSxAnalyzer.read())
                            if x == 0:  # Encapsulated data
                                PSxLog.write(" 0x1B")
                            elif x == 1:  # Start of new message
                                psx_header(PSxAnalyzer, PSxLog)
                            elif x == 2:  # Start of PlayStation message
                                PSxLog.write(" PSx>> ")
                            elif x == 3:  # Start of controller message
                                PSxLog.write(" Ctl>> ")
                            elif x == 4:  # End of message
                                PSxLog.write("\n\r")
                            else:
                                PSxLog.write("\n\r** Garbage Encountered\n\r")
                                continue
                        else:
                            PSxLog.write("0x%2X" % x)
                    else:
                        PSxLog.write("0x%2X " % x)
            PSxLog.close()
            sys.exit(0)

finally:
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, old_settings)
