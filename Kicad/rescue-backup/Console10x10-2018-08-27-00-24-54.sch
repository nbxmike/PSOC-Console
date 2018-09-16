EESchema Schematic File Version 2
LIBS:Console-10x10
LIBS:valves
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:Console10x10-cache
EELAYER 25 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 1 1
Title "FRC Console"
Date ""
Rev ""
Comp ""
Comment1 "Copyright Mike McCormack 2018"
Comment2 "Licensed under CERN OHL v.1.2"
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_26 J1
U 1 1 560FE8CA
P 2700 4550
F 0 "J1" H 2975 1850 50  0000 C CNN
F 1 "CONN_26" V 2800 4550 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x26" H 2700 4550 60  0001 C CNN
F 3 "" H 2700 4550 60  0000 C CNN
	1    2700 4550
	-1   0    0    1   
$EndComp
$Comp
L CONN_26 J2
U 1 1 560FE924
P 1250 4550
F 0 "J2" H 1500 1825 50  0000 C CNN
F 1 "CONN_26" V 1350 4550 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x26" H 1250 4550 60  0001 C CNN
F 3 "" H 1250 4550 60  0000 C CNN
	1    1250 4550
	1    0    0    1   
$EndComp
Wire Wire Line
	800  4550 1250 4550
Wire Wire Line
	1250 4450 800  4450
Wire Wire Line
	800  4350 1250 4350
Wire Wire Line
	800  4250 1250 4250
Wire Wire Line
	800  4150 1250 4150
Wire Wire Line
	1250 4050 800  4050
Wire Wire Line
	800  3950 1250 3950
Wire Wire Line
	800  3850 1250 3850
Wire Wire Line
	800  3750 1250 3750
Wire Wire Line
	1250 3650 800  3650
Wire Wire Line
	800  3550 1250 3550
Wire Wire Line
	800  3450 1250 3450
Wire Wire Line
	800  3350 1250 3350
Wire Wire Line
	1250 3250 800  3250
Wire Wire Line
	800  3150 1250 3150
Wire Wire Line
	800  3050 1250 3050
Wire Wire Line
	1250 2950 800  2950
Wire Wire Line
	800  2850 1250 2850
Wire Wire Line
	800  2750 1250 2750
Wire Wire Line
	800  2650 1250 2650
Wire Wire Line
	1250 2550 800  2550
Wire Wire Line
	800  2450 1250 2450
Wire Wire Line
	1250 2350 800  2350
Wire Wire Line
	800  2250 1250 2250
Wire Wire Line
	800  2150 1250 2150
Wire Wire Line
	3150 4550 2700 4550
Wire Wire Line
	2700 4450 3150 4450
Wire Wire Line
	3150 4350 2700 4350
Wire Wire Line
	3150 4250 2700 4250
Wire Wire Line
	3150 4150 2700 4150
Wire Wire Line
	2700 4050 3150 4050
Wire Wire Line
	3150 3950 2700 3950
Wire Wire Line
	3150 3850 2700 3850
Wire Wire Line
	3150 3750 2700 3750
Wire Wire Line
	2700 3650 3150 3650
Wire Wire Line
	3150 3550 2700 3550
Wire Wire Line
	3150 3450 2700 3450
Wire Wire Line
	3150 3350 2700 3350
Wire Wire Line
	2700 3250 3150 3250
Wire Wire Line
	3150 3150 2700 3150
Wire Wire Line
	3150 3050 2700 3050
Wire Wire Line
	2700 2950 3150 2950
Wire Wire Line
	3150 2850 2700 2850
Wire Wire Line
	3150 2750 2700 2750
Wire Wire Line
	3150 2650 2700 2650
Wire Wire Line
	2700 2550 3150 2550
Wire Wire Line
	3150 2450 2700 2450
Wire Wire Line
	3150 2350 2700 2350
Wire Wire Line
	2700 2250 3150 2250
Wire Wire Line
	3150 2150 2700 2150
Wire Wire Line
	3150 2050 2700 2050
Text Label 3100 4550 2    60   ~ 0
P2.0
Text Label 3100 4450 2    60   ~ 0
P2.1
Text Label 3100 4350 2    60   ~ 0
P2.2
Text Label 3100 4250 2    60   ~ 0
P2.3
Text Label 3100 4150 2    60   ~ 0
P2.4
Text Label 3100 4050 2    60   ~ 0
P2.5
Text Label 3100 3950 2    60   ~ 0
P2.6
Text Label 3100 3850 2    60   ~ 0
P2.7
Text Label 3100 3750 2    60   ~ 0
TXD
Text Label 3100 3650 2    60   ~ 0
RCV
Text Label 3100 3550 2    60   ~ 0
P12.5
Text Label 3100 3450 2    60   ~ 0
P12.4
Text Label 3100 3350 2    60   ~ 0
P12.3
Text Label 3100 3250 2    60   ~ 0
P12.2
Text Label 3100 3150 2    60   ~ 0
SDA
Text Label 3100 3050 2    60   ~ 0
SCL
Text Label 3100 2950 2    60   ~ 0
SWDIO
Text Label 3100 2850 2    60   ~ 0
SWDCLK
Text Label 3100 2750 2    60   ~ 0
P1.2
Text Label 3100 2650 2    60   ~ 0
P1.3
Text Label 3100 2550 2    60   ~ 0
P1.4
Text Label 3100 2450 2    60   ~ 0
P1.5
Text Label 3100 2350 2    60   ~ 0
P1.6
Text Label 3100 2250 2    60   ~ 0
P1.7
Text Label 3100 2150 2    60   ~ 0
GND
Text Label 3100 2050 2    60   ~ 0
VIO
Text Label 900  4550 0    60   ~ 0
VDD
Text Label 900  4450 0    60   ~ 0
GND
Text Label 900  4350 0    60   ~ 0
RESET
Text Label 900  4250 0    60   ~ 0
P0.7
Text Label 900  4150 0    60   ~ 0
P0.6
Text Label 900  4050 0    60   ~ 0
P0.5
Text Label 900  3950 0    60   ~ 0
P0.4
Text Label 900  3850 0    60   ~ 0
P0.3
Text Label 900  3750 0    60   ~ 0
P0.2
Text Label 900  3650 0    60   ~ 0
P0.1
Text Label 900  3550 0    60   ~ 0
P0.0
Text Label 900  3450 0    60   ~ 0
P15.5
Text Label 900  3350 0    60   ~ 0
P15.4
Text Label 900  3250 0    60   ~ 0
XTALi
Text Label 900  3150 0    60   ~ 0
XTALo
Text Label 900  3050 0    60   ~ 0
P15.1
Text Label 900  2950 0    60   ~ 0
P15.0
Text Label 900  2850 0    60   ~ 0
P3.7
Text Label 900  2750 0    60   ~ 0
P3.6
Text Label 900  2650 0    60   ~ 0
P3.5
Text Label 900  2550 0    60   ~ 0
P3.4
Text Label 900  2450 0    60   ~ 0
P3.3
Text Label 900  2350 0    60   ~ 0
P3.2
Text Label 900  2250 0    60   ~ 0
P3.1
Text Label 900  2150 0    60   ~ 0
P3.0
Wire Wire Line
	800  2050 1250 2050
Text Label 900  2050 0    60   ~ 0
GND
Wire Notes Line
	1500 4800 2450 4800
Wire Notes Line
	2450 4800 2450 1900
Wire Notes Line
	2450 1900 1500 1900
Wire Notes Line
	1500 1900 1500 4800
Text Notes 1700 2100 0    60   ~ 0
CY8CKIT-059
Wire Wire Line
	9050 4900 9500 4900
Wire Wire Line
	7650 6200 8100 6200
Wire Wire Line
	7650 6100 8100 6100
Wire Wire Line
	9500 6300 9050 6300
Wire Wire Line
	9050 6200 9500 6200
Wire Wire Line
	9050 6100 9500 6100
Wire Wire Line
	9050 5200 9500 5200
Wire Wire Line
	9500 5100 9050 5100
Wire Wire Line
	9050 5000 9500 5000
Wire Wire Line
	1350 5950 1800 5950
Wire Wire Line
	1350 6050 1800 6050
Wire Wire Line
	1350 6150 1800 6150
Wire Wire Line
	1800 6250 1350 6250
Wire Wire Line
	4500 4000 5500 4000
Wire Wire Line
	4500 3900 5500 3900
Wire Wire Line
	4500 2900 5500 2900
Wire Wire Line
	4500 2800 5500 2800
Wire Wire Line
	4500 2700 5500 2700
Wire Wire Line
	4500 1700 5500 1700
Wire Wire Line
	4500 1600 5500 1600
Wire Wire Line
	4500 1500 5500 1500
Text Label 9150 4900 0    60   ~ 0
VDD
Text Label 7750 6200 0    60   ~ 0
P0.7
Text Label 7750 6100 0    60   ~ 0
P0.6
Text Label 9150 6300 0    60   ~ 0
P0.5
Text Label 9150 6200 0    60   ~ 0
P0.4
Text Label 9150 6100 0    60   ~ 0
P0.3
Text Label 9150 5200 0    60   ~ 0
P0.2
Text Label 9150 5100 0    60   ~ 0
P0.1
Text Label 9150 5000 0    60   ~ 0
P0.0
Text Label 1450 5950 0    60   ~ 0
P15.5
Text Label 1450 6050 0    60   ~ 0
P15.4
Text Label 1450 6150 0    60   ~ 0
P15.1
Text Label 1450 6250 0    60   ~ 0
P15.0
Text Label 4600 4000 0    60   ~ 0
P3.7
Text Label 4600 3900 0    60   ~ 0
P3.6
Text Label 4600 2900 0    60   ~ 0
P3.5
Text Label 4600 2800 0    60   ~ 0
P3.4
Text Label 4600 2700 0    60   ~ 0
P3.3
Text Label 4600 1700 0    60   ~ 0
P3.2
Text Label 4600 1600 0    60   ~ 0
P3.1
Text Label 4600 1500 0    60   ~ 0
P3.0
Wire Wire Line
	9050 5300 9500 5300
Text Label 9150 5300 0    60   ~ 0
GND
Wire Wire Line
	6600 2900 7600 2900
Wire Wire Line
	6600 2800 7600 2800
Wire Wire Line
	6600 2700 7600 2700
Wire Wire Line
	6600 4100 7600 4100
Wire Wire Line
	6600 4000 7600 4000
Wire Wire Line
	6600 3900 7600 3900
Wire Wire Line
	4500 4100 5500 4100
Wire Wire Line
	4150 7400 3700 7400
Wire Wire Line
	3700 7500 4150 7500
Wire Wire Line
	1800 7000 1350 7000
Wire Wire Line
	1800 6900 1350 6900
Wire Wire Line
	1800 6800 1350 6800
Wire Wire Line
	1350 6700 1800 6700
Wire Wire Line
	4150 6600 3700 6600
Wire Wire Line
	4150 6700 3700 6700
Wire Wire Line
	6600 1700 7600 1700
Wire Wire Line
	6600 1600 7600 1600
Wire Wire Line
	6600 1500 7600 1500
Wire Wire Line
	4500 5300 5500 5300
Wire Wire Line
	4500 5200 5500 5200
Wire Wire Line
	4500 5100 5500 5100
Wire Wire Line
	1800 1450 1550 1450
Text Label 7000 2900 2    60   ~ 0
P2.0
Text Label 7000 2800 2    60   ~ 0
P2.2
Text Label 7000 2700 2    60   ~ 0
P2.3
Text Label 7000 4100 2    60   ~ 0
P2.5
Text Label 7000 4000 2    60   ~ 0
P2.6
Text Label 7000 3900 2    60   ~ 0
P2.7
Text Label 4800 4100 2    60   ~ 0
P2.4
Text Label 4100 7400 2    60   ~ 0
TXD
Text Label 4100 7500 2    60   ~ 0
RCV
Text Label 1750 7000 2    60   ~ 0
P12.5
Text Label 1750 6900 2    60   ~ 0
P12.4
Text Label 1750 6800 2    60   ~ 0
P12.3
Text Label 1750 6700 2    60   ~ 0
P12.2
Text Label 4100 6600 2    60   ~ 0
SDA
Text Label 4100 6700 2    60   ~ 0
SCL
Text Label 7000 1700 2    60   ~ 0
P1.2
Text Label 7000 1600 2    60   ~ 0
P1.3
Text Label 7000 1500 2    60   ~ 0
P1.4
Text Label 4900 5300 2    60   ~ 0
P1.5
Text Label 4900 5200 2    60   ~ 0
P1.6
Text Label 4900 5100 2    60   ~ 0
P1.7
Text Label 1750 1450 2    60   ~ 0
VIO
$Comp
L CONN_4 Button1
U 1 1 56100597
P 5850 1650
F 0 "Button1" H 5850 1900 50  0000 C CNN
F 1 "CONN_4" V 5950 1650 50  0001 C CNN
F 2 "Aglets:PTSA-4" H 5850 1650 60  0001 C CNN
F 3 "" H 5850 1650 60  0000 C CNN
	1    5850 1650
	1    0    0    1   
$EndComp
Wire Wire Line
	5050 1800 5500 1800
Text Label 5150 1800 0    60   ~ 0
GND
Wire Wire Line
	9050 6000 9500 6000
Text Label 9150 6000 0    60   ~ 0
VDD
Wire Wire Line
	9050 6400 9500 6400
Text Label 9150 6400 0    60   ~ 0
GND
$Comp
L CONN_5 JS1
U 1 1 561006CA
P 9850 5100
F 0 "JS1" H 9850 5400 50  0000 C CNN
F 1 "CONN_5" V 9950 5100 50  0001 C CNN
F 2 "Aglets:PTSA-5" H 9850 5100 60  0001 C CNN
F 3 "" H 9850 5100 60  0000 C CNN
	1    9850 5100
	1    0    0    -1  
$EndComp
$Comp
L CONN_5 JS2
U 1 1 5610071F
P 9850 6200
F 0 "JS2" H 9850 6500 50  0000 C CNN
F 1 "CONN_5" V 9950 6200 50  0001 C CNN
F 2 "Aglets:PTSA-5" H 9850 6200 60  0001 C CNN
F 3 "" H 9850 6200 60  0000 C CNN
	1    9850 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 6000 8100 6000
Text Label 7750 6000 0    60   ~ 0
VDD
Wire Wire Line
	7650 6400 8100 6400
Text Label 7750 6400 0    60   ~ 0
GND
Wire Wire Line
	2100 5850 2550 5850
Text Label 2200 5850 0    60   ~ 0
VDD
Wire Wire Line
	2100 6600 2550 6600
Text Label 2200 6600 0    60   ~ 0
VDD
$Comp
L CONN_4 UART1
U 1 1 561014BD
P 4500 7450
F 0 "UART1" H 4500 7700 50  0000 C CNN
F 1 "CONN_4" V 4600 7450 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04" H 4500 7450 60  0001 C CNN
F 3 "" H 4500 7450 60  0000 C CNN
	1    4500 7450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 7300 4150 7300
Text Label 3800 7300 0    60   ~ 0
VDD
Wire Wire Line
	3700 7600 4150 7600
Text Label 3800 7600 0    60   ~ 0
GND
$Comp
L CONN_4 I2C1
U 1 1 5610152C
P 4500 6650
F 0 "I2C1" H 4500 6900 50  0000 C CNN
F 1 "CONN_4" V 4600 6650 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04" H 4500 6650 60  0001 C CNN
F 3 "" H 4500 6650 60  0000 C CNN
	1    4500 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 6500 4150 6500
Text Label 3800 6500 0    60   ~ 0
VDD
Wire Wire Line
	3700 6800 4150 6800
Text Label 3800 6800 0    60   ~ 0
GND
$Comp
L R R4
U 1 1 56101B67
P 2000 6250
F 0 "R4" H 1850 6290 50  0000 C CNN
F 1 "330" H 2050 6200 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 2000 6250 60  0001 C CNN
F 3 "" H 2000 6250 60  0000 C CNN
	1    2000 6250
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 56101C87
P 2000 6700
F 0 "R5" H 1850 6740 50  0000 C CNN
F 1 "330" H 2050 6650 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 2000 6700 60  0001 C CNN
F 3 "" H 2000 6700 60  0000 C CNN
	1    2000 6700
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 56101D51
P 2000 6800
F 0 "R6" H 1850 6840 50  0000 C CNN
F 1 "330" H 2050 6750 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 2000 6800 60  0001 C CNN
F 3 "" H 2000 6800 60  0000 C CNN
	1    2000 6800
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 56101E3D
P 2000 5950
F 0 "R1" H 1850 5990 50  0000 C CNN
F 1 "330" H 2050 5900 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 2000 5950 60  0001 C CNN
F 3 "" H 2000 5950 60  0000 C CNN
	1    2000 5950
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 56101E43
P 2000 6050
F 0 "R2" H 1850 6090 50  0000 C CNN
F 1 "330" H 2050 6000 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 2000 6050 60  0001 C CNN
F 3 "" H 2000 6050 60  0000 C CNN
	1    2000 6050
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 56101E49
P 2000 6150
F 0 "R3" H 1850 6190 50  0000 C CNN
F 1 "330" H 2050 6100 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 2000 6150 60  0001 C CNN
F 3 "" H 2000 6150 60  0000 C CNN
	1    2000 6150
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 56101F3B
P 2000 6900
F 0 "R7" H 1850 6940 50  0000 C CNN
F 1 "330" H 2050 6850 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 2000 6900 60  0001 C CNN
F 3 "" H 2000 6900 60  0000 C CNN
	1    2000 6900
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 56101F41
P 2000 7000
F 0 "R8" H 1850 7040 50  0000 C CNN
F 1 "330" H 2050 6950 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 2000 7000 60  0001 C CNN
F 3 "" H 2000 7000 60  0000 C CNN
	1    2000 7000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 6900 2550 6900
Wire Wire Line
	2550 7000 2100 7000
Wire Wire Line
	2100 5950 2550 5950
Wire Wire Line
	2550 6050 2100 6050
Wire Wire Line
	2100 6150 2550 6150
Wire Wire Line
	2100 6250 2550 6250
Wire Wire Line
	2550 6700 2100 6700
Wire Wire Line
	2100 6800 2550 6800
Wire Wire Line
	4800 950  5250 950 
Text Label 4850 950  0    60   ~ 0
VDD
$Comp
L R R17
U 1 1 56103E75
P 5250 1300
F 0 "R17" H 5100 1250 50  0000 C CNN
F 1 "4.7K" H 5300 1350 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 5250 1300 60  0001 C CNN
F 3 "" H 5250 1300 60  0000 C CNN
	1    5250 1300
	0    1    1    0   
$EndComp
$Comp
L R R13
U 1 1 56103E7B
P 5150 1300
F 0 "R13" H 5000 1250 50  0000 C CNN
F 1 "4.7K" H 5200 1350 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 5150 1300 60  0001 C CNN
F 3 "" H 5150 1300 60  0000 C CNN
	1    5150 1300
	0    1    1    0   
$EndComp
$Comp
L R R9
U 1 1 56103E81
P 5050 1300
F 0 "R9" H 4900 1250 50  0000 C CNN
F 1 "4.7K" H 5100 1350 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 5050 1300 60  0001 C CNN
F 3 "" H 5050 1300 60  0000 C CNN
	1    5050 1300
	0    1    1    0   
$EndComp
Wire Wire Line
	5050 1100 5050 950 
Connection ~ 5050 950 
Wire Wire Line
	5150 1100 5150 950 
Connection ~ 5150 950 
Wire Wire Line
	5250 950  5250 1100
Wire Wire Line
	5050 1400 5050 1700
Connection ~ 5050 1700
Wire Wire Line
	5150 1400 5150 1600
Connection ~ 5150 1600
Wire Wire Line
	5250 1400 5250 1500
Connection ~ 5250 1500
$Comp
L CONN_4 Button2
U 1 1 561031B5
P 5850 2850
F 0 "Button2" H 5850 3100 50  0000 C CNN
F 1 "CONN_4" V 5950 2850 50  0001 C CNN
F 2 "Aglets:PTSA-4" H 5850 2850 60  0001 C CNN
F 3 "" H 5850 2850 60  0000 C CNN
	1    5850 2850
	1    0    0    1   
$EndComp
Wire Wire Line
	5050 3000 5500 3000
Text Label 5150 3000 0    60   ~ 0
GND
Wire Wire Line
	4800 2150 5250 2150
Text Label 4850 2150 0    60   ~ 0
VDD
$Comp
L R R18
U 1 1 561031BF
P 5250 2500
F 0 "R18" H 5100 2450 50  0000 C CNN
F 1 "4.7K" H 5300 2550 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 5250 2500 60  0001 C CNN
F 3 "" H 5250 2500 60  0000 C CNN
	1    5250 2500
	0    1    1    0   
$EndComp
$Comp
L R R14
U 1 1 561031C5
P 5150 2500
F 0 "R14" H 5000 2450 50  0000 C CNN
F 1 "4.7K" H 5200 2550 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 5150 2500 60  0001 C CNN
F 3 "" H 5150 2500 60  0000 C CNN
	1    5150 2500
	0    1    1    0   
$EndComp
$Comp
L R R10
U 1 1 561031CB
P 5050 2500
F 0 "R10" H 4900 2450 50  0000 C CNN
F 1 "4.7K" H 5100 2550 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 5050 2500 60  0001 C CNN
F 3 "" H 5050 2500 60  0000 C CNN
	1    5050 2500
	0    1    1    0   
$EndComp
Wire Wire Line
	5050 2300 5050 2150
Connection ~ 5050 2150
Wire Wire Line
	5150 2300 5150 2150
Connection ~ 5150 2150
Wire Wire Line
	5250 2150 5250 2300
Wire Wire Line
	5050 2600 5050 2900
Connection ~ 5050 2900
Wire Wire Line
	5150 2600 5150 2800
Connection ~ 5150 2800
Wire Wire Line
	5250 2600 5250 2700
Connection ~ 5250 2700
$Comp
L CONN_4 Button3
U 1 1 561032B8
P 5850 4050
F 0 "Button3" H 5850 4300 50  0000 C CNN
F 1 "CONN_4" V 5950 4050 50  0001 C CNN
F 2 "Aglets:PTSA-4" H 5850 4050 60  0001 C CNN
F 3 "" H 5850 4050 60  0000 C CNN
	1    5850 4050
	1    0    0    1   
$EndComp
Wire Wire Line
	5050 4200 5500 4200
Text Label 5150 4200 0    60   ~ 0
GND
Wire Wire Line
	4800 3350 5250 3350
Text Label 4850 3350 0    60   ~ 0
VDD
$Comp
L R R19
U 1 1 561032C2
P 5250 3700
F 0 "R19" H 5100 3650 50  0000 C CNN
F 1 "4.7K" H 5300 3750 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 5250 3700 60  0001 C CNN
F 3 "" H 5250 3700 60  0000 C CNN
	1    5250 3700
	0    1    1    0   
$EndComp
$Comp
L R R15
U 1 1 561032C8
P 5150 3700
F 0 "R15" H 5000 3650 50  0000 C CNN
F 1 "4.7K" H 5200 3750 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 5150 3700 60  0001 C CNN
F 3 "" H 5150 3700 60  0000 C CNN
	1    5150 3700
	0    1    1    0   
$EndComp
$Comp
L R R11
U 1 1 561032CE
P 5050 3700
F 0 "R11" H 4900 3650 50  0000 C CNN
F 1 "4.7K" H 5100 3750 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 5050 3700 60  0001 C CNN
F 3 "" H 5050 3700 60  0000 C CNN
	1    5050 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	5050 3500 5050 3350
Connection ~ 5050 3350
Wire Wire Line
	5150 3500 5150 3350
Connection ~ 5150 3350
Wire Wire Line
	5250 3350 5250 3500
Wire Wire Line
	5050 3800 5050 4100
Connection ~ 5050 4100
Wire Wire Line
	5150 3800 5150 4000
Connection ~ 5150 4000
Wire Wire Line
	5250 3800 5250 3900
Connection ~ 5250 3900
$Comp
L CONN_4 Button7
U 1 1 56103437
P 7950 2850
F 0 "Button7" H 7950 3100 50  0000 C CNN
F 1 "CONN_4" V 8050 2850 50  0001 C CNN
F 2 "Aglets:PTSA-4" H 7950 2850 60  0001 C CNN
F 3 "" H 7950 2850 60  0000 C CNN
	1    7950 2850
	1    0    0    1   
$EndComp
Wire Wire Line
	7150 4200 7600 4200
Text Label 7250 4200 0    60   ~ 0
GND
Wire Wire Line
	6900 3350 7350 3350
Text Label 6950 3350 0    60   ~ 0
VDD
$Comp
L R R29
U 1 1 56103441
P 7350 3700
F 0 "R29" H 7200 3650 50  0000 C CNN
F 1 "4.7K" H 7400 3750 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 7350 3700 60  0001 C CNN
F 3 "" H 7350 3700 60  0000 C CNN
	1    7350 3700
	0    1    1    0   
$EndComp
$Comp
L R R26
U 1 1 56103447
P 7250 3700
F 0 "R26" H 7100 3650 50  0000 C CNN
F 1 "4.7K" H 7300 3750 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 7250 3700 60  0001 C CNN
F 3 "" H 7250 3700 60  0000 C CNN
	1    7250 3700
	0    1    1    0   
$EndComp
$Comp
L R R23
U 1 1 5610344D
P 7150 3700
F 0 "R23" H 7000 3650 50  0000 C CNN
F 1 "4.7K" H 7200 3750 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 7150 3700 60  0001 C CNN
F 3 "" H 7150 3700 60  0000 C CNN
	1    7150 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	7150 3500 7150 3350
Connection ~ 7150 3350
Wire Wire Line
	7250 3500 7250 3350
Connection ~ 7250 3350
Wire Wire Line
	7350 3350 7350 3500
Wire Wire Line
	7150 3800 7150 4100
Connection ~ 7150 4100
Wire Wire Line
	7250 3800 7250 4000
Connection ~ 7250 4000
Wire Wire Line
	7350 3800 7350 3900
Connection ~ 7350 3900
$Comp
L CONN_4 Button4
U 1 1 56103A2C
P 5850 5250
F 0 "Button4" H 5850 5500 50  0000 C CNN
F 1 "CONN_4" V 5950 5250 50  0001 C CNN
F 2 "Aglets:PTSA-4" H 5850 5250 60  0001 C CNN
F 3 "" H 5850 5250 60  0000 C CNN
	1    5850 5250
	1    0    0    1   
$EndComp
Wire Wire Line
	5050 5400 5500 5400
Text Label 5150 5400 0    60   ~ 0
GND
Wire Wire Line
	4800 4550 5250 4550
Text Label 4850 4550 0    60   ~ 0
VDD
$Comp
L R R20
U 1 1 56103A36
P 5250 4900
F 0 "R20" H 5100 4850 50  0000 C CNN
F 1 "4.7K" H 5300 4950 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 5250 4900 60  0001 C CNN
F 3 "" H 5250 4900 60  0000 C CNN
	1    5250 4900
	0    1    1    0   
$EndComp
$Comp
L R R16
U 1 1 56103A3C
P 5150 4900
F 0 "R16" H 5000 4850 50  0000 C CNN
F 1 "4.7K" H 5200 4950 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 5150 4900 60  0001 C CNN
F 3 "" H 5150 4900 60  0000 C CNN
	1    5150 4900
	0    1    1    0   
$EndComp
$Comp
L R R12
U 1 1 56103A42
P 5050 4900
F 0 "R12" H 4900 4850 50  0000 C CNN
F 1 "4.7K" H 5100 4950 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 5050 4900 60  0001 C CNN
F 3 "" H 5050 4900 60  0000 C CNN
	1    5050 4900
	0    1    1    0   
$EndComp
Wire Wire Line
	5050 4700 5050 4550
Connection ~ 5050 4550
Wire Wire Line
	5150 4700 5150 4550
Connection ~ 5150 4550
Wire Wire Line
	5250 4550 5250 4700
Wire Wire Line
	5050 5000 5050 5300
Connection ~ 5050 5300
Wire Wire Line
	5150 5000 5150 5200
Connection ~ 5150 5200
Wire Wire Line
	5250 5000 5250 5100
Connection ~ 5250 5100
$Comp
L CONN_4 Button5
U 1 1 56104428
P 7950 1650
F 0 "Button5" H 7950 1900 50  0000 C CNN
F 1 "CONN_4" V 8050 1650 50  0001 C CNN
F 2 "Aglets:PTSA-4" H 7950 1650 60  0001 C CNN
F 3 "" H 7950 1650 60  0000 C CNN
	1    7950 1650
	1    0    0    1   
$EndComp
Wire Wire Line
	7150 1800 7600 1800
Text Label 7250 1800 0    60   ~ 0
GND
Wire Wire Line
	6900 950  7350 950 
Text Label 6950 950  0    60   ~ 0
VDD
$Comp
L R R27
U 1 1 56104432
P 7350 1300
F 0 "R27" H 7200 1250 50  0000 C CNN
F 1 "4.7K" H 7400 1350 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 7350 1300 60  0001 C CNN
F 3 "" H 7350 1300 60  0000 C CNN
	1    7350 1300
	0    1    1    0   
$EndComp
$Comp
L R R24
U 1 1 56104438
P 7250 1300
F 0 "R24" H 7100 1250 50  0000 C CNN
F 1 "4.7K" H 7300 1350 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 7250 1300 60  0001 C CNN
F 3 "" H 7250 1300 60  0000 C CNN
	1    7250 1300
	0    1    1    0   
$EndComp
$Comp
L R R21
U 1 1 5610443E
P 7150 1300
F 0 "R21" H 7000 1250 50  0000 C CNN
F 1 "4.7K" H 7200 1350 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 7150 1300 60  0001 C CNN
F 3 "" H 7150 1300 60  0000 C CNN
	1    7150 1300
	0    1    1    0   
$EndComp
Wire Wire Line
	7150 1100 7150 950 
Connection ~ 7150 950 
Wire Wire Line
	7250 1100 7250 950 
Connection ~ 7250 950 
Wire Wire Line
	7350 950  7350 1100
Wire Wire Line
	7150 1400 7150 1700
Connection ~ 7150 1700
Wire Wire Line
	7250 1400 7250 1600
Connection ~ 7250 1600
Wire Wire Line
	7350 1400 7350 1500
Connection ~ 7350 1500
$Comp
L CONN_4 Button6
U 1 1 561049DE
P 7950 4050
F 0 "Button6" H 7950 4300 50  0000 C CNN
F 1 "CONN_4" V 8050 4050 50  0001 C CNN
F 2 "Aglets:PTSA-4" H 7950 4050 60  0001 C CNN
F 3 "" H 7950 4050 60  0000 C CNN
	1    7950 4050
	1    0    0    1   
$EndComp
Wire Wire Line
	7150 3000 7600 3000
Text Label 7250 3000 0    60   ~ 0
GND
Wire Wire Line
	6900 2150 7350 2150
Text Label 6950 2150 0    60   ~ 0
VDD
$Comp
L R R28
U 1 1 561049E8
P 7350 2500
F 0 "R28" H 7200 2450 50  0000 C CNN
F 1 "4.7K" H 7400 2550 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 7350 2500 60  0001 C CNN
F 3 "" H 7350 2500 60  0000 C CNN
	1    7350 2500
	0    1    1    0   
$EndComp
$Comp
L R R25
U 1 1 561049EE
P 7250 2500
F 0 "R25" H 7100 2450 50  0000 C CNN
F 1 "4.7K" H 7300 2550 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 7250 2500 60  0001 C CNN
F 3 "" H 7250 2500 60  0000 C CNN
	1    7250 2500
	0    1    1    0   
$EndComp
$Comp
L R R22
U 1 1 561049F4
P 7150 2500
F 0 "R22" H 7000 2450 50  0000 C CNN
F 1 "4.7K" H 7200 2550 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" H 7150 2500 60  0001 C CNN
F 3 "" H 7150 2500 60  0000 C CNN
	1    7150 2500
	0    1    1    0   
$EndComp
Wire Wire Line
	7150 2300 7150 2150
Connection ~ 7150 2150
Wire Wire Line
	7250 2300 7250 2150
Connection ~ 7250 2150
Wire Wire Line
	7350 2150 7350 2300
Wire Wire Line
	7150 2600 7150 2900
Connection ~ 7150 2900
Wire Wire Line
	7250 2600 7250 2800
Connection ~ 7250 2800
Wire Wire Line
	7350 2600 7350 2700
Connection ~ 7350 2700
Wire Wire Line
	2200 1450 2500 1450
Text Label 2300 1450 0    60   ~ 0
VDD
Wire Wire Line
	1800 1450 1800 1600
Wire Wire Line
	1800 1600 2200 1600
Wire Wire Line
	2200 1600 2200 1450
$Comp
L LOGO Logo1
U 1 1 56116FAC
P 9825 900
F 0 "Logo1" H 9825 900 60  0000 C CNN
F 1 "LOGO" H 9825 650 60  0001 C CNN
F 2 "Aglets:StMarySmall" H 9825 900 60  0001 C CNN
F 3 "" H 9825 900 60  0000 C CNN
	1    9825 900 
	1    0    0    -1  
$EndComp
$Comp
L HOLE B1
U 1 1 56168795
P 9550 1975
F 0 "B1" H 9550 2125 60  0000 C CNN
F 1 "HOLE" H 9550 1875 60  0000 C CNN
F 2 "Aglets:MH-No6-3p5" H 9550 1675 60  0001 C CNN
F 3 "" H 9550 1675 60  0000 C CNN
	1    9550 1975
	-1   0    0    1   
$EndComp
$Comp
L HOLE B3
U 1 1 56168858
P 10150 1975
F 0 "B3" H 10150 2125 60  0000 C CNN
F 1 "HOLE" H 10150 1875 60  0000 C CNN
F 2 "Aglets:MH-No6-3p5" H 10150 1675 60  0001 C CNN
F 3 "" H 10150 1675 60  0000 C CNN
	1    10150 1975
	1    0    0    -1  
$EndComp
$Comp
L HOLE B4
U 1 1 561688D3
P 10175 2450
F 0 "B4" H 10175 2600 60  0000 C CNN
F 1 "HOLE" H 10175 2350 60  0000 C CNN
F 2 "Aglets:MH-No6-3p5" H 10175 2150 60  0001 C CNN
F 3 "" H 10175 2150 60  0000 C CNN
	1    10175 2450
	1    0    0    -1  
$EndComp
$Comp
L HOLE B2
U 1 1 561689B4
P 9550 2450
F 0 "B2" H 9550 2600 60  0000 C CNN
F 1 "HOLE" H 9550 2350 60  0000 C CNN
F 2 "Aglets:MH-No6-3p5" H 9550 2150 60  0001 C CNN
F 3 "" H 9550 2150 60  0000 C CNN
	1    9550 2450
	-1   0    0    1   
$EndComp
$Comp
L CONN_5 AnalogIO1
U 1 1 56169B27
P 8450 6200
F 0 "AnalogIO1" H 8450 6500 50  0000 C CNN
F 1 "CONN_5" V 8550 6200 50  0001 C CNN
F 2 "Aglets:PTSA-5" H 8450 6200 60  0001 C CNN
F 3 "" H 8450 6200 60  0000 C CNN
	1    8450 6200
	1    0    0    -1  
$EndComp
$Comp
L CONN_6 LED0
U 1 1 5616A181
P 2900 6100
F 0 "LED0" H 2900 6450 50  0000 C CNN
F 1 "CONN_6" V 3000 6100 50  0001 C CNN
F 2 "Aglets:PTSA-6" H 2900 6100 60  0001 C CNN
F 3 "" H 2900 6100 60  0000 C CNN
	1    2900 6100
	1    0    0    -1  
$EndComp
$Comp
L CONN_6 LED1
U 1 1 5616A630
P 2900 6850
F 0 "LED1" H 2900 7200 50  0000 C CNN
F 1 "CONN_6" V 3000 6850 50  0001 C CNN
F 2 "Aglets:PTSA-6" H 2900 6850 60  0001 C CNN
F 3 "" H 2900 6850 60  0000 C CNN
	1    2900 6850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 6350 2550 6350
Text Label 2200 6350 0    60   ~ 0
GND
Wire Wire Line
	2100 7100 2550 7100
Text Label 2200 7100 0    60   ~ 0
GND
$Comp
L LOGO Logo2
U 1 1 5616AC45
P 9825 1400
F 0 "Logo2" H 9825 1400 60  0000 C CNN
F 1 "LOGO" H 9825 1150 60  0001 C CNN
F 2 "Aglets:StMaryLarge" H 9825 1400 60  0001 C CNN
F 3 "" H 9825 1400 60  0000 C CNN
	1    9825 1400
	1    0    0    -1  
$EndComp
$Comp
L TP T1
U 1 1 562BC6A8
P 9575 3350
F 0 "T1" H 9585 3530 60  0000 C CNN
F 1 "TP" H 9655 3370 60  0001 C CNN
F 2 "Aglets:TP-TH" H 9575 3150 60  0001 C CNN
F 3 "" H 9575 3150 60  0000 C CNN
	1    9575 3350
	1    0    0    -1  
$EndComp
$Comp
L TP T2
U 1 1 562BC75D
P 9775 3350
F 0 "T2" H 9785 3530 60  0000 C CNN
F 1 "TP" H 9855 3370 60  0001 C CNN
F 2 "Aglets:TP-TH" H 9775 3150 60  0001 C CNN
F 3 "" H 9775 3150 60  0000 C CNN
	1    9775 3350
	1    0    0    -1  
$EndComp
$Comp
L TP T3
U 1 1 562BCDB6
P 9950 3350
F 0 "T3" H 9960 3530 60  0000 C CNN
F 1 "TP" H 10030 3370 60  0001 C CNN
F 2 "Aglets:TP-TH" H 9950 3150 60  0001 C CNN
F 3 "" H 9950 3150 60  0000 C CNN
	1    9950 3350
	1    0    0    -1  
$EndComp
$Comp
L TP T4
U 1 1 562BCDBC
P 10150 3350
F 0 "T4" H 10160 3530 60  0000 C CNN
F 1 "TP" H 10230 3370 60  0001 C CNN
F 2 "Aglets:TP-TH" H 10150 3150 60  0001 C CNN
F 3 "" H 10150 3150 60  0000 C CNN
	1    10150 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8950 3450 10150 3450
Text Label 9050 3450 0    60   ~ 0
GND
Wire Wire Line
	10150 3450 10150 3350
Wire Wire Line
	9950 3350 9950 3450
Connection ~ 9950 3450
Wire Wire Line
	9775 3350 9775 3450
Connection ~ 9775 3450
Wire Wire Line
	9575 3350 9575 3450
Connection ~ 9575 3450
$EndSCHEMATC
