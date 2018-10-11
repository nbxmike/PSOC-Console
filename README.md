# PSOC-Console

This is an expansion of the operator console for FIRST Robotic Competitions
originally published on the Cypress Semiconductor website:
  https://community.cypress.com/thread/30090
based on the CY8CKIT-059 development board.  I had previously released hardware
to ease the creation of the console, publised on the Cypress website:
  https://community.cypress.com/thread/30074
  
With this project, the Cypress GPL code is being replaced with MIT licensed 
firmware which runs as a task under FreeRTOS 10 (which is licensed under MIT
terms and hence the new firmware being released under the same license.)  The
firmware is not a port, it is new code which has at best been inspired by the
Cypress code meantioned above

The hardware is at the moment (11/OCT/2018) the same as was previously released
hardware.  A new revision of the hardware has been designed to incorporate a
3.3V regulator to make interfacing to PS/2, GameCube and other game console 
devices much easier.  It is entirely possible to interface the existing board
to 3.3V devices, and it has been done, it has been a painful kludge of wires
and ICs glued in place.  Expect updated hardware in the August 2018 timeframe
(boards are out for fab as I write.)

The project has been assigned the USB ID of 0x1d50 | 0x6131 by the 
openmoko USB OUI program.  Anticipating the hardware revision to 3.3V and its
associated updated firmware, a second ID is reserved.  Obtaining unique USB
IDs makes custom host support much easier should something other than stock
HID drivers be desired at some future point.

The project is broken down into three directories:
  Kicad - this folder includes the Kicad source files, gerbers, BOMs, etc.
    Kicad is a free schematic capture package the equal of many commercial
	packages but as FOSS it places no restrictions on use of its outputs.
  PSOC-Creator - This is the source for the firware and PLD of the CPU core
    used for this project.  PSOC Creator is a free integrated development
	enviroment which is not open source nor available for a package other than
	Windows.  It sucks that to use Cypress hardware you are forced into such
	a crap desktop but Cypress does not seem to care too much.
  Documents - I have collected a number for reference documents that I have
    included in this folder.  Should a copyright holder ask that I not provide
	people this information source I will attempt to find open documents to 
	replace them.
	
Licensing:
  Hardware - CERN
  Firmware - MIT
  Documents - individual terms are in each document
  
Enjoy

Mike
