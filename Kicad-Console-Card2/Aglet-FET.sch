EESchema Schematic File Version 2
LIBS:aglet
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
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
LIBS:valves
LIBS:Smart-H-cache
EELAYER 25 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 2 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L R R21
U 1 1 59DA970D
P 5075 1875
F 0 "R21" H 4925 1975 50  0000 C CNN
F 1 "R" H 5025 1815 50  0000 C CNN
F 2 "Aglet_Footprints:r_0805" H 5075 1875 60  0001 C CNN
F 3 "" H 5075 1875 60  0000 C CNN
	1    5075 1875
	1    0    0    -1  
$EndComp
$Comp
L R R22
U 1 1 59DA9713
P 5075 2475
F 0 "R22" H 4925 2575 50  0000 C CNN
F 1 "R" H 5025 2415 50  0000 C CNN
F 2 "Aglet_Footprints:r_0805" H 5075 2475 60  0001 C CNN
F 3 "" H 5075 2475 60  0000 C CNN
	1    5075 2475
	1    0    0    -1  
$EndComp
$Comp
L MOSFET_N Q21
U 1 1 59DA9719
P 5625 1875
F 0 "Q21" H 5925 1825 60  0000 R CNN
F 1 "MOSFET_N" H 5635 1725 60  0000 R CNN
F 2 "Aglet_Footprints:sot223-gds" H 5625 1875 60  0001 C CNN
F 3 "" H 5625 1875 60  0000 C CNN
	1    5625 1875
	1    0    0    -1  
$EndComp
$Comp
L MOSFET_N Q22
U 1 1 59DA971F
P 5625 2475
F 0 "Q22" H 5925 2625 60  0000 R CNN
F 1 "MOSFET_N" H 5635 2325 60  0000 R CNN
F 2 "Aglet_Footprints:sot223-gds" H 5625 2475 60  0001 C CNN
F 3 "" H 5625 2475 60  0000 C CNN
	1    5625 2475
	1    0    0    -1  
$EndComp
Wire Wire Line
	5175 1875 5425 1875
Wire Wire Line
	5175 2475 5425 2475
Wire Wire Line
	4875 2475 4675 2475
Wire Wire Line
	4675 2475 4675 2275
Wire Wire Line
	4675 2275 3575 2275
Wire Wire Line
	5725 2175 3575 2175
Wire Wire Line
	5725 2075 5725 2275
Connection ~ 5725 2175
Wire Wire Line
	3575 2075 4675 2075
Wire Wire Line
	4675 2075 4675 1875
Wire Wire Line
	4675 1875 4875 1875
Wire Wire Line
	3875 1975 3575 1975
Wire Wire Line
	5725 1025 5725 1675
$Comp
L CONN_1 Out2
U 1 1 59DA9739
P 6525 2125
F 0 "Out2" H 6605 2125 40  0000 L CNN
F 1 "CONN_1" H 6525 2180 30  0001 C CNN
F 2 "Aglet_Footprints:SCREW-TERM-6-C" H 6525 2125 60  0001 C CNN
F 3 "" H 6525 2125 60  0000 C CNN
	1    6525 2125
	1    0    0    -1  
$EndComp
Wire Wire Line
	5725 2675 5725 2925
$Comp
L C C21
U 1 1 59DA9742
P 2425 2575
F 0 "C21" H 2275 2675 50  0000 L CNN
F 1 "C" H 2475 2475 50  0000 L CNN
F 2 "Aglet_Footprints:c_0805" H 2425 2575 60  0001 C CNN
F 3 "" H 2425 2575 60  0000 C CNN
	1    2425 2575
	1    0    0    -1  
$EndComp
$Comp
L C C22
U 1 1 59DA9748
P 8425 1400
F 0 "C22" H 8475 1475 50  0000 L CNN
F 1 "C" H 8475 1300 50  0000 L CNN
F 2 "Aglet_Footprints:c_1210" H 8425 1400 60  0001 C CNN
F 3 "" H 8425 1400 60  0000 C CNN
	1    8425 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2425 2775 2425 2825
Wire Wire Line
	2425 2825 2625 2825
Wire Wire Line
	5725 2125 6375 2125
Connection ~ 5725 2125
$Comp
L CONN_1 Pow2
U 1 1 59DA9753
P 5725 875
F 0 "Pow2" V 5825 825 40  0000 L CNN
F 1 "CONN_1" H 5725 930 30  0001 C CNN
F 2 "Aglet_Footprints:SCREW-TERM-6-C" H 5725 875 60  0001 C CNN
F 3 "" H 5725 875 60  0000 C CNN
	1    5725 875 
	0    -1   -1   0   
$EndComp
$Comp
L CONN_1 GND2
U 1 1 59DA9759
P 9425 875
F 0 "GND2" V 9525 825 40  0000 L CNN
F 1 "CONN_1" H 9425 930 30  0001 C CNN
F 2 "Aglet_Footprints:SCREW-TERM-6-C" H 9425 875 60  0001 C CNN
F 3 "" H 9425 875 60  0000 C CNN
	1    9425 875 
	0    -1   -1   0   
$EndComp
Text Notes 3075 1575 0    60   ~ 0
D2PAK
$Comp
L C C23
U 1 1 59DA9760
P 4075 1775
F 0 "C23" H 3925 1875 50  0000 L CNN
F 1 "C" H 4125 1675 50  0000 L CNN
F 2 "Aglet_Footprints:c_0805" H 4075 1775 60  0001 C CNN
F 3 "" H 4075 1775 60  0000 C CNN
	1    4075 1775
	1    0    0    -1  
$EndComp
Wire Wire Line
	4075 1975 4075 2175
Connection ~ 4075 2175
Wire Wire Line
	5725 1125 8425 1125
Connection ~ 5725 1125
Wire Wire Line
	1550 2075 2775 2075
Wire Wire Line
	1550 2175 2775 2175
$Comp
L DIODE D21
U 1 1 59DA9796
P 6075 1775
F 0 "D21" V 5975 1675 40  0000 C CNN
F 1 "DIODE" H 6025 1925 40  0001 C CNN
F 2 "Diodes_SMD:D_SMB" H 6075 1775 60  0001 C CNN
F 3 "" H 6075 1775 60  0000 C CNN
	1    6075 1775
	0    -1   -1   0   
$EndComp
$Comp
L DIODE D22
U 1 1 59DA979C
P 6075 2475
F 0 "D22" V 6175 2375 40  0000 C CNN
F 1 "DIODE" H 6025 2625 40  0001 C CNN
F 2 "Diodes_SMD:D_SMB" H 6075 2475 60  0001 C CNN
F 3 "" H 6075 2475 60  0000 C CNN
	1    6075 2475
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5725 2775 6075 2775
Wire Wire Line
	6075 2775 6075 2675
Connection ~ 5725 2775
Wire Wire Line
	6075 1975 6075 2275
Connection ~ 6075 2125
Wire Wire Line
	6075 1575 6075 1475
Wire Wire Line
	6075 1475 5725 1475
Connection ~ 5725 1475
Text Label 2675 1175 0    60   Italic 0
VCC2
Text Label 5825 1475 0    60   Italic 0
Vdrv
Text Label 4925 2175 0    60   Italic 0
Vout2
Text Label 3625 1975 0    60   Italic 0
Vb2
Wire Wire Line
	2425 1175 2425 2375
Wire Wire Line
	2625 2275 2775 2275
Wire Wire Line
	2775 1975 2725 1975
Wire Wire Line
	2725 1975 2725 1825
Wire Wire Line
	2725 1825 2425 1825
Connection ~ 2425 1825
$Comp
L GND1 #PWR5
U 1 1 59DA97EE
P 8850 1775
F 0 "#PWR5" H 8850 1525 50  0001 C CNN
F 1 "GND1" H 8850 1625 50  0000 C CNN
F 2 "" H 8850 1775 50  0001 C CNN
F 3 "" H 8850 1775 50  0001 C CNN
	1    8850 1775
	1    0    0    -1  
$EndComp
$Comp
L GND1 #PWR3
U 1 1 59DA9846
P 5725 2925
F 0 "#PWR3" H 5725 2675 50  0001 C CNN
F 1 "GND1" H 5725 2775 50  0000 C CNN
F 2 "" H 5725 2925 50  0001 C CNN
F 3 "" H 5725 2925 50  0001 C CNN
	1    5725 2925
	1    0    0    -1  
$EndComp
$Comp
L GND1 #PWR1
U 1 1 59DA989E
P 2625 2975
F 0 "#PWR1" H 2625 2725 50  0001 C CNN
F 1 "GND1" H 2625 2825 50  0000 C CNN
F 2 "" H 2625 2975 50  0001 C CNN
F 3 "" H 2625 2975 50  0001 C CNN
	1    2625 2975
	1    0    0    -1  
$EndComp
$Comp
L R R41
U 1 1 59DAE3DD
P 5075 4450
F 0 "R41" H 4925 4550 50  0000 C CNN
F 1 "R" H 5025 4390 50  0000 C CNN
F 2 "Aglet_Footprints:r_0805" H 5075 4450 60  0001 C CNN
F 3 "" H 5075 4450 60  0000 C CNN
	1    5075 4450
	1    0    0    -1  
$EndComp
$Comp
L R R42
U 1 1 59DAE3E3
P 5075 5050
F 0 "R42" H 4925 5150 50  0000 C CNN
F 1 "R" H 5025 4990 50  0000 C CNN
F 2 "Aglet_Footprints:r_0805" H 5075 5050 60  0001 C CNN
F 3 "" H 5075 5050 60  0000 C CNN
	1    5075 5050
	1    0    0    -1  
$EndComp
$Comp
L MOSFET_N Q41
U 1 1 59DAE3E9
P 5625 4450
F 0 "Q41" H 5925 4400 60  0000 R CNN
F 1 "MOSFET_N" H 5635 4300 60  0000 R CNN
F 2 "Aglet_Footprints:sot223-gds" H 5625 4450 60  0001 C CNN
F 3 "" H 5625 4450 60  0000 C CNN
	1    5625 4450
	1    0    0    -1  
$EndComp
$Comp
L MOSFET_N Q42
U 1 1 59DAE3EF
P 5625 5050
F 0 "Q42" H 5925 5150 60  0000 R CNN
F 1 "MOSFET_N" H 5635 4900 60  0000 R CNN
F 2 "Aglet_Footprints:sot223-gds" H 5625 5050 60  0001 C CNN
F 3 "" H 5625 5050 60  0000 C CNN
	1    5625 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5175 4450 5425 4450
Wire Wire Line
	5175 5050 5425 5050
Wire Wire Line
	4875 5050 4675 5050
Wire Wire Line
	4675 5050 4675 4850
Wire Wire Line
	4675 4850 3575 4850
Wire Wire Line
	5725 4750 3575 4750
Wire Wire Line
	5725 4650 5725 4850
Connection ~ 5725 4750
Wire Wire Line
	3575 4650 4675 4650
Wire Wire Line
	4675 4650 4675 4450
Wire Wire Line
	4675 4450 4875 4450
Wire Wire Line
	3875 4550 3575 4550
$Comp
L CONN_1 Out4
U 1 1 59DAE410
P 6525 4700
F 0 "Out4" H 6605 4700 40  0000 L CNN
F 1 "CONN_1" H 6525 4755 30  0001 C CNN
F 2 "Aglet_Footprints:SCREW-TERM-6-C" H 6525 4700 60  0001 C CNN
F 3 "" H 6525 4700 60  0000 C CNN
	1    6525 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5725 5250 5725 5500
$Comp
L C C41
U 1 1 59DAE41D
P 2425 5150
F 0 "C41" H 2275 5250 50  0000 L CNN
F 1 "C" H 2475 5050 50  0000 L CNN
F 2 "Aglet_Footprints:c_0805" H 2425 5150 60  0001 C CNN
F 3 "" H 2425 5150 60  0000 C CNN
	1    2425 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2425 5350 2425 5400
Wire Wire Line
	2425 5400 2625 5400
Wire Wire Line
	5725 4700 6375 4700
Connection ~ 5725 4700
Text Notes 3075 4150 0    60   ~ 0
D2PAK
$Comp
L C C43
U 1 1 59DAE43C
P 4075 4350
F 0 "C43" H 3925 4450 50  0000 L CNN
F 1 "C" H 4125 4250 50  0000 L CNN
F 2 "Aglet_Footprints:c_0805" H 4075 4350 60  0001 C CNN
F 3 "" H 4075 4350 60  0000 C CNN
	1    4075 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4075 4550 4075 4750
Connection ~ 4075 4750
Wire Wire Line
	2175 4650 2775 4650
Wire Wire Line
	2075 4750 2775 4750
$Comp
L DIODE D41
U 1 1 59DAE475
P 6075 4350
F 0 "D41" V 5975 4250 40  0000 C CNN
F 1 "DIODE" H 6025 4500 40  0001 C CNN
F 2 "Diodes_SMD:D_SMB" H 6075 4350 60  0001 C CNN
F 3 "" H 6075 4350 60  0000 C CNN
	1    6075 4350
	0    -1   -1   0   
$EndComp
$Comp
L DIODE D42
U 1 1 59DAE47B
P 6075 5050
F 0 "D42" V 6175 4950 40  0000 C CNN
F 1 "DIODE" H 6025 5200 40  0001 C CNN
F 2 "Diodes_SMD:D_SMB" H 6075 5050 60  0001 C CNN
F 3 "" H 6075 5050 60  0000 C CNN
	1    6075 5050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5725 5350 6075 5350
Wire Wire Line
	6075 5350 6075 5250
Connection ~ 5725 5350
Wire Wire Line
	6075 4550 6075 4850
Connection ~ 6075 4700
Wire Wire Line
	6075 4150 6075 4050
Wire Wire Line
	5725 4050 7200 4050
Text Label 2675 3750 0    60   Italic 0
VCC2
Text Label 5825 4050 0    60   Italic 0
Vdrv
Text Label 4925 4750 0    60   Italic 0
Vout4
Text Label 3625 4550 0    60   Italic 0
Vb4
Wire Wire Line
	2425 3750 2425 4950
Wire Wire Line
	2625 4850 2775 4850
Wire Wire Line
	2775 4550 2725 4550
Wire Wire Line
	2725 4550 2725 4400
Wire Wire Line
	2725 4400 2425 4400
Connection ~ 2425 4400
$Comp
L GND1 #PWR2
U 1 1 59DAE74E
P 2625 5550
F 0 "#PWR2" H 2625 5300 50  0001 C CNN
F 1 "GND1" H 2625 5400 50  0000 C CNN
F 2 "" H 2625 5550 50  0001 C CNN
F 3 "" H 2625 5550 50  0001 C CNN
	1    2625 5550
	1    0    0    -1  
$EndComp
$Comp
L GND1 #PWR4
U 1 1 59DAE7EA
P 5725 5500
F 0 "#PWR4" H 5725 5250 50  0001 C CNN
F 1 "GND1" H 5725 5350 50  0000 C CNN
F 2 "" H 5725 5500 50  0001 C CNN
F 3 "" H 5725 5500 50  0001 C CNN
	1    5725 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3875 1175 3875 1975
Wire Wire Line
	4075 1175 4075 1575
$Comp
L DIODE D23
U 1 1 59DC2EA1
P 3575 1175
F 0 "D23" H 3675 1075 40  0000 C CNN
F 1 "DIODE" H 3525 1325 40  0001 C CNN
F 2 "Diodes_SMD:D_SMA" H 3575 1175 60  0001 C CNN
F 3 "" H 3575 1175 60  0000 C CNN
	1    3575 1175
	1    0    0    -1  
$EndComp
$Comp
L R R23
U 1 1 59DC2EA7
P 3225 1175
F 0 "R23" H 3075 1275 50  0000 C CNN
F 1 "R" H 3175 1115 50  0000 C CNN
F 2 "Aglet_Footprints:r_0805" H 3225 1175 60  0001 C CNN
F 3 "" H 3225 1175 60  0000 C CNN
	1    3225 1175
	1    0    0    -1  
$EndComp
Wire Wire Line
	3775 1175 4075 1175
Connection ~ 3875 1175
Wire Wire Line
	3375 1175 3325 1175
Wire Wire Line
	2425 1175 3025 1175
Wire Wire Line
	3875 3750 3875 4550
Wire Wire Line
	4075 3750 4075 4150
$Comp
L DIODE D43
U 1 1 59DC396E
P 3575 3750
F 0 "D43" H 3675 3650 40  0000 C CNN
F 1 "DIODE" H 3525 3900 40  0001 C CNN
F 2 "Diodes_SMD:D_SMA" H 3575 3750 60  0001 C CNN
F 3 "" H 3575 3750 60  0000 C CNN
	1    3575 3750
	1    0    0    -1  
$EndComp
$Comp
L R R43
U 1 1 59DC3974
P 3225 3750
F 0 "R43" H 3075 3850 50  0000 C CNN
F 1 "R" H 3175 3690 50  0000 C CNN
F 2 "Aglet_Footprints:r_0805" H 3225 3750 60  0001 C CNN
F 3 "" H 3225 3750 60  0000 C CNN
	1    3225 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3775 3750 4075 3750
Connection ~ 3875 3750
Wire Wire Line
	3375 3750 3325 3750
Wire Wire Line
	2425 3750 3025 3750
$Comp
L LOGO Logo1
U 1 1 59DD8437
P 1200 1150
F 0 "Logo1" H 1200 1150 60  0000 C CNN
F 1 "LOGO" H 1200 900 60  0001 C CNN
F 2 "Aglet_Footprints:HexenLogoSm" H 1200 1150 60  0001 C CNN
F 3 "" H 1200 1150 60  0000 C CNN
	1    1200 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5725 4050 5725 4250
Wire Wire Line
	2625 4850 2625 5550
Connection ~ 2625 5400
Wire Wire Line
	2175 4650 2175 2275
Wire Wire Line
	2175 2275 1550 2275
Wire Wire Line
	1550 2375 2075 2375
Wire Wire Line
	2075 2375 2075 4750
Text Label 1675 2075 0    60   ~ 0
Hin0
Text Label 1675 2175 0    60   ~ 0
Lin0
Text Label 1675 2275 0    60   ~ 0
Hin1
Text Label 1675 2375 0    60   ~ 0
Lin1
Wire Wire Line
	2625 2275 2625 2975
Connection ~ 2625 2825
Text HLabel 1550 2075 0    60   Input ~ 0
Hin0
Text HLabel 1550 2175 0    60   Input ~ 0
Lin0
Text HLabel 1550 2275 0    60   Input ~ 0
Hin1
Text HLabel 1550 2375 0    60   Input ~ 0
Lin1
$Comp
L GenericLM5107 U2
U 1 1 5A92EE34
P 3175 2125
F 0 "U2" H 3025 2375 60  0000 C CNN
F 1 "GenericLM5107" H 3175 1875 60  0000 C CNN
F 2 "Aglet_Footprints:SO8" H 3025 2025 60  0001 C CNN
F 3 "" H 3025 2025 60  0001 C CNN
	1    3175 2125
	1    0    0    -1  
$EndComp
$Comp
L GenericLM5107 U4
U 1 1 5A92F177
P 3175 4700
F 0 "U4" H 3025 4950 60  0000 C CNN
F 1 "GenericLM5107" H 3175 4450 60  0000 C CNN
F 2 "Aglet_Footprints:SO8" H 3025 4600 60  0001 C CNN
F 3 "" H 3025 4600 60  0001 C CNN
	1    3175 4700
	1    0    0    -1  
$EndComp
$Comp
L C C25
U 1 1 5A9544F9
P 8000 1400
F 0 "C25" H 8075 1500 50  0000 L CNN
F 1 "470uF" H 8025 1300 50  0000 L CNN
F 2 "Aglet_Footprints:CP_Radial_D18.0mm_P7.50mm" H 8000 1400 60  0001 C CNN
F 3 "" H 8000 1400 60  0000 C CNN
	1    8000 1400
	1    0    0    -1  
$EndComp
$Comp
L C C24
U 1 1 5A954585
P 7625 1400
F 0 "C24" H 7675 1500 50  0000 L CNN
F 1 "470uF" H 7650 1300 50  0000 L CNN
F 2 "Aglet_Footprints:CP_Radial_D18.0mm_P7.50mm" H 7625 1400 60  0001 C CNN
F 3 "" H 7625 1400 60  0000 C CNN
	1    7625 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 1775 8850 1675
Wire Wire Line
	7625 1675 9425 1675
Wire Wire Line
	7625 1675 7625 1600
Wire Wire Line
	8000 1600 8000 1675
Connection ~ 8000 1675
Wire Wire Line
	8425 1600 8425 1675
Connection ~ 8425 1675
Wire Wire Line
	9425 1675 9425 1025
Connection ~ 8850 1675
Wire Wire Line
	8425 1125 8425 1200
Wire Wire Line
	7625 1200 7625 1125
Connection ~ 7625 1125
Wire Wire Line
	8000 1200 8000 1125
Connection ~ 8000 1125
Wire Wire Line
	7200 4050 7200 1125
Connection ~ 6075 4050
Connection ~ 7200 1125
Text HLabel 6375 2250 2    60   Output ~ 0
Mtr_A
Text HLabel 6500 4575 2    60   Output ~ 0
Mtr_B
Text HLabel 7375 2775 2    60   Output ~ 0
Mtr_V
Wire Wire Line
	6375 2250 6300 2250
Wire Wire Line
	6300 2250 6300 2125
Connection ~ 6300 2125
Wire Wire Line
	6500 4575 6300 4575
Wire Wire Line
	6300 4575 6300 4700
Connection ~ 6300 4700
Wire Wire Line
	7375 2775 7200 2775
Connection ~ 7200 2775
Text HLabel 1550 1525 0    60   Input ~ 0
VCC2
Wire Wire Line
	1550 1525 2425 1525
Connection ~ 2425 1525
$EndSCHEMATC