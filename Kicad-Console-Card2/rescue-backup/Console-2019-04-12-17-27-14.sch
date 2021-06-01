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
LIBS:Console-cache
EELAYER 25 0
EELAYER END
$Descr B 17000 11000
encoding utf-8
Sheet 1 1
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
L CONN_PS1 PS1
U 1 1 5A9FE242
P 15525 1550
F 0 "PS1" H 15525 2050 60  0000 C CNN
F 1 "CONN_PS1" V 15825 1550 60  0000 C CNN
F 2 "Aglet_Footprints:PS1-Ctrlr" H 15525 1650 60  0001 C CNN
F 3 "" H 15525 1650 60  0001 C CNN
	1    15525 1550
	1    0    0    -1  
$EndComp
$Comp
L CONN_PS1 PS2
U 1 1 5A9FE285
P 15525 2600
F 0 "PS2" H 15525 3100 60  0000 C CNN
F 1 "CONN_PS1" V 15825 2600 60  0000 C CNN
F 2 "Aglet_Footprints:PS1-Ctrlr" H 15525 2700 60  0001 C CNN
F 3 "" H 15525 2700 60  0001 C CNN
	1    15525 2600
	1    0    0    -1  
$EndComp
$Comp
L USB-MICROB J1
U 1 1 5AA0047C
P 12150 6850
F 0 "J1" H 12550 7050 60  0000 C CNN
F 1 "USB-MICROB" V 12750 6650 60  0000 C CNN
F 2 "Aglet_Footprints:Micro_usb_b" H 11600 6450 60  0001 C CNN
F 3 "" H 11600 6450 60  0000 C CNN
	1    12150 6850
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 5AA00483
P 10975 6950
F 0 "R7" H 10825 6990 50  0000 C CNN
F 1 "22" H 10925 6890 50  0000 C CNN
F 2 "Aglet_Footprints:r_0603" H 10975 6950 60  0001 C CNN
F 3 "" H 10975 6950 60  0000 C CNN
	1    10975 6950
	-1   0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 5AA0048A
P 11150 7050
F 0 "R6" H 11000 7090 50  0000 C CNN
F 1 "22" H 11100 6990 50  0000 C CNN
F 2 "Aglet_Footprints:r_0603" H 11150 7050 60  0001 C CNN
F 3 "" H 11150 7050 60  0000 C CNN
	1    11150 7050
	-1   0    0    -1  
$EndComp
Text Label 2775 8475 2    60   ~ 0
VTARG
Text Label 5600 3750 0    60   ~ 0
SWDCK
Text Label 5600 3650 0    60   ~ 0
SWDIO
Text Label 2750 8925 2    60   ~ 0
VDDIO_3
$Comp
L C C2
U 1 1 5AA004A8
P 1300 9350
F 0 "C2" H 1350 9450 50  0000 L CNN
F 1 "0.1uF" H 1350 9250 50  0000 L CNN
F 2 "Aglet_Footprints:c_0603" H 1300 9350 60  0001 C CNN
F 3 "" H 1300 9350 60  0000 C CNN
	1    1300 9350
	-1   0    0    -1  
$EndComp
$Comp
L C C18
U 1 1 5AA004AF
P 900 9350
F 0 "C18" H 950 9450 50  0000 L CNN
F 1 "0.1uF" H 950 9250 50  0000 L CNN
F 2 "Aglet_Footprints:c_0603" H 900 9350 60  0001 C CNN
F 3 "" H 900 9350 60  0000 C CNN
	1    900  9350
	-1   0    0    -1  
$EndComp
$Comp
L C C15
U 1 1 5AA004B6
P 2100 9350
F 0 "C15" H 2150 9450 50  0000 L CNN
F 1 "0.1uF" H 2150 9250 50  0000 L CNN
F 2 "Aglet_Footprints:c_0603" H 2100 9350 60  0001 C CNN
F 3 "" H 2100 9350 60  0000 C CNN
	1    2100 9350
	-1   0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 5AA004BD
P 1700 9350
F 0 "C3" H 1750 9450 50  0000 L CNN
F 1 "0.1uF" H 1750 9250 50  0000 L CNN
F 2 "Aglet_Footprints:c_0603" H 1700 9350 60  0001 C CNN
F 3 "" H 1700 9350 60  0000 C CNN
	1    1700 9350
	-1   0    0    -1  
$EndComp
Text Label 2750 8825 2    60   ~ 0
VDDIO_2
Text Label 2750 8725 2    60   ~ 0
VDDIO_1
Text Label 2750 8625 2    60   ~ 0
VDDIO_0
$Comp
L C C6
U 1 1 5AA004C7
P 11825 7375
F 0 "C6" H 11875 7475 50  0000 L CNN
F 1 "0.1uF" H 11875 7275 50  0000 L CNN
F 2 "Aglet_Footprints:c_0603" H 11825 7375 60  0001 C CNN
F 3 "" H 11825 7375 60  0000 C CNN
	1    11825 7375
	-1   0    0    -1  
$EndComp
Text Label 5775 3850 0    60   ~ 0
KP_Rev_0
Text Label 5775 3950 0    60   ~ 0
KP_Rev_1
Text Label 5775 4050 0    60   ~ 0
KP_Rev_2
Text Label 5775 4150 0    60   ~ 0
KP_Rev_3
Text Label 7275 8750 2    60   ~ 0
KP_Rev_0
Text Label 7275 8850 2    60   ~ 0
KP_Rev_1
Text Label 7275 8950 2    60   ~ 0
KP_Rev_2
Text Label 7275 9050 2    60   ~ 0
KP_Rev_3
$Comp
L R R5
U 1 1 5AA004D6
P 6575 9425
F 0 "R5" V 6625 9350 50  0000 C CNN
F 1 "NP" V 6450 9375 50  0000 C CNN
F 2 "Aglet_Footprints:JUMPER-OPEN" H 6575 9425 60  0001 C CNN
F 3 "" H 6575 9425 60  0000 C CNN
	1    6575 9425
	0    1    -1   0   
$EndComp
$Comp
L R R3
U 1 1 5AA004DD
P 6375 9425
F 0 "R3" V 6425 9350 50  0000 C CNN
F 1 "NP" V 6250 9375 50  0000 C CNN
F 2 "Aglet_Footprints:JUMPER-OPEN" H 6375 9425 60  0001 C CNN
F 3 "" H 6375 9425 60  0000 C CNN
	1    6375 9425
	0    1    -1   0   
$EndComp
$Comp
L R R2
U 1 1 5AA004E4
P 6175 9425
F 0 "R2" V 6225 9350 50  0000 C CNN
F 1 "NP" V 6050 9375 50  0000 C CNN
F 2 "Aglet_Footprints:JUMPER-OPEN" H 6175 9425 60  0001 C CNN
F 3 "" H 6175 9425 60  0000 C CNN
	1    6175 9425
	0    1    -1   0   
$EndComp
$Comp
L R R1
U 1 1 5AA004EB
P 5975 9425
F 0 "R1" V 6025 9350 50  0000 C CNN
F 1 "0" V 5850 9375 50  0000 C CNN
F 2 "Aglet_Footprints:JUMPER-SHORT" H 5975 9425 60  0001 C CNN
F 3 "" H 5975 9425 60  0000 C CNN
	1    5975 9425
	0    1    -1   0   
$EndComp
$Comp
L GND1 #PWR01
U 1 1 5AA004F2
P 6500 9900
F 0 "#PWR01" H 6500 9650 50  0001 C CNN
F 1 "GND1" H 6500 9750 50  0000 C CNN
F 2 "" H 6500 9900 50  0001 C CNN
F 3 "" H 6500 9900 50  0001 C CNN
	1    6500 9900
	-1   0    0    -1  
$EndComp
$Comp
L GND1 #PWR02
U 1 1 5AA004F8
P 1525 9850
F 0 "#PWR02" H 1525 9600 50  0001 C CNN
F 1 "GND1" H 1525 9700 50  0000 C CNN
F 2 "" H 1525 9850 50  0001 C CNN
F 3 "" H 1525 9850 50  0001 C CNN
	1    1525 9850
	-1   0    0    -1  
$EndComp
$Comp
L GND1 #PWR03
U 1 1 5AA004FE
P 12300 7800
F 0 "#PWR03" H 12300 7550 50  0001 C CNN
F 1 "GND1" H 12300 7650 50  0000 C CNN
F 2 "" H 12300 7800 50  0001 C CNN
F 3 "" H 12300 7800 50  0001 C CNN
	1    12300 7800
	-1   0    0    -1  
$EndComp
$Comp
L C C11
U 1 1 5AA00518
P 4925 1500
F 0 "C11" H 4975 1600 50  0000 L CNN
F 1 "1.0uF" H 4975 1400 50  0000 L CNN
F 2 "Aglet_Footprints:c_0603" H 4925 1500 60  0001 C CNN
F 3 "" H 4925 1500 60  0000 C CNN
	1    4925 1500
	1    0    0    -1  
$EndComp
$Comp
L C C10
U 1 1 5AA0051F
P 5325 1500
F 0 "C10" H 5375 1600 50  0000 L CNN
F 1 "0.1uF" H 5375 1400 50  0000 L CNN
F 2 "Aglet_Footprints:c_0603" H 5325 1500 60  0001 C CNN
F 3 "" H 5325 1500 60  0000 C CNN
	1    5325 1500
	1    0    0    -1  
$EndComp
$Comp
L C C20
U 1 1 5AA00526
P 4125 1500
F 0 "C20" H 4175 1600 50  0000 L CNN
F 1 "1.0uF" H 4175 1400 50  0000 L CNN
F 2 "Aglet_Footprints:c_0603" H 4125 1500 60  0001 C CNN
F 3 "" H 4125 1500 60  0000 C CNN
	1    4125 1500
	1    0    0    -1  
$EndComp
$Comp
L C C17
U 1 1 5AA0052D
P 4525 1500
F 0 "C17" H 4575 1600 50  0000 L CNN
F 1 "0.1uF" H 4575 1400 50  0000 L CNN
F 2 "Aglet_Footprints:c_0603" H 4525 1500 60  0001 C CNN
F 3 "" H 4525 1500 60  0000 C CNN
	1    4525 1500
	1    0    0    -1  
$EndComp
$Comp
L C C12
U 1 1 5AA00534
P 2925 1500
F 0 "C12" H 2975 1600 50  0000 L CNN
F 1 "0.1uF" H 2975 1400 50  0000 L CNN
F 2 "Aglet_Footprints:c_0603" H 2925 1500 60  0001 C CNN
F 3 "" H 2925 1500 60  0000 C CNN
	1    2925 1500
	1    0    0    -1  
$EndComp
$Comp
L C C16
U 1 1 5AA0053B
P 3325 1500
F 0 "C16" H 3375 1600 50  0000 L CNN
F 1 "0.1uF" H 3375 1400 50  0000 L CNN
F 2 "Aglet_Footprints:c_0603" H 3325 1500 60  0001 C CNN
F 3 "" H 3325 1500 60  0000 C CNN
	1    3325 1500
	1    0    0    -1  
$EndComp
$Comp
L C C13
U 1 1 5AA00542
P 2125 1500
F 0 "C13" H 2175 1600 50  0000 L CNN
F 1 "1.0uF" H 2175 1400 50  0000 L CNN
F 2 "Aglet_Footprints:c_0603" H 2125 1500 60  0001 C CNN
F 3 "" H 2125 1500 60  0000 C CNN
	1    2125 1500
	1    0    0    -1  
$EndComp
$Comp
L C C14
U 1 1 5AA00549
P 2525 1500
F 0 "C14" H 2575 1600 50  0000 L CNN
F 1 "0.1uF" H 2575 1400 50  0000 L CNN
F 2 "Aglet_Footprints:c_0603" H 2525 1500 60  0001 C CNN
F 3 "" H 2525 1500 60  0000 C CNN
	1    2525 1500
	1    0    0    -1  
$EndComp
Text Label 6200 1050 0    60   ~ 0
VCCA
Text Label 6200 950  0    60   ~ 0
VCCD
Text Label 6200 1150 0    60   ~ 0
VDDA
Text Label 6200 1250 0    60   ~ 0
VDDD
Text Label 2325 4250 0    60   ~ 0
XRES
$Comp
L C C1
U 1 1 5AA0055D
P 3125 4525
F 0 "C1" H 3175 4625 50  0000 L CNN
F 1 "0.1uF" H 3175 4425 50  0000 L CNN
F 2 "Aglet_Footprints:c_0603" H 3125 4525 60  0001 C CNN
F 3 "" H 3125 4525 60  0000 C CNN
	1    3125 4525
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 5AA00564
P 3125 3975
F 0 "R4" V 2975 4050 50  0000 C CNN
F 1 "4.7K" V 3175 4075 50  0000 C CNN
F 2 "Aglet_Footprints:r_0603" H 3125 3975 60  0001 C CNN
F 3 "" H 3125 3975 60  0000 C CNN
	1    3125 3975
	0    1    1    0   
$EndComp
Text Label 11225 6675 0    60   ~ 0
VUSB
Text Label 3500 8625 0    60   ~ 0
VSSA
$Comp
L GND1 #PWR04
U 1 1 5AA0056D
P 3825 8725
F 0 "#PWR04" H 3825 8475 50  0001 C CNN
F 1 "GND1" H 3825 8575 50  0000 C CNN
F 2 "" H 3825 8725 50  0001 C CNN
F 3 "" H 3825 8725 50  0001 C CNN
	1    3825 8725
	1    0    0    -1  
$EndComp
Text Label 4375 8750 0    60   ~ 0
VDDA
Text Label 4375 8625 0    60   ~ 0
VDDD
Text Notes 2800 8300 0    75   ~ 0
Seperate net while PCB is placed
Text Label 2300 4050 0    60   ~ 0
VDDD
$Comp
L C C8
U 1 1 5AA00577
P 11475 7375
F 0 "C8" H 11525 7475 50  0000 L CNN
F 1 "1.0uF" H 11525 7275 50  0000 L CNN
F 2 "Aglet_Footprints:c_0603" H 11475 7375 60  0001 C CNN
F 3 "" H 11475 7375 60  0000 C CNN
	1    11475 7375
	-1   0    0    -1  
$EndComp
$Comp
L C C7
U 1 1 5AA0057E
P 10825 7375
F 0 "C7" H 10875 7475 50  0000 L CNN
F 1 "0.1uF" H 10875 7275 50  0000 L CNN
F 2 "Aglet_Footprints:c_0603" H 10825 7375 60  0001 C CNN
F 3 "" H 10825 7375 60  0000 C CNN
	1    10825 7375
	-1   0    0    -1  
$EndComp
$Comp
L C C19
U 1 1 5AA00585
P 3725 1500
F 0 "C19" H 3775 1600 50  0000 L CNN
F 1 "1.0uF" H 3775 1400 50  0000 L CNN
F 2 "Aglet_Footprints:c_0603" H 3725 1500 60  0001 C CNN
F 3 "" H 3725 1500 60  0000 C CNN
	1    3725 1500
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR05
U 1 1 5AA0058C
P 4850 8475
F 0 "#PWR05" H 4850 8575 30  0001 C CNN
F 1 "VCC" H 4850 8575 30  0000 C CNN
F 2 "" H 4850 8475 60  0000 C CNN
F 3 "" H 4850 8475 60  0000 C CNN
	1    4850 8475
	1    0    0    -1  
$EndComp
Text Notes 2400 10175 0    60   ~ 0
                    Routing of power\n\nVTARG and VDDIO - the I/O voltage \n    input to PSOC and souced at SWD target connector,\n    decouple each input, route together\nVDDA and VDDD are the analog and digital inputs\n    decouple seperately, route together\nVCCA and VCCD outputs of analog and digital regulators\n    decouple and route seperately, do not connect to \n    other power pins\nVSSA and VSSD are analog and digital returns \n    join, single point VSSA to other returns
$Comp
L CY8C54LP U2
U 1 1 5AA00619
P 7725 6250
F 0 "U2" H 6525 10350 60  0000 C CNN
F 1 "CY8C54LP" H 8575 10350 60  0000 C CNN
F 2 "Aglet_Footprints:QFP_100" H 9625 5800 60  0001 C CNN
F 3 "" H 9625 5800 60  0001 C CNN
	1    7725 6250
	1    0    0    -1  
$EndComp
Text Label 7225 1925 1    60   ~ 0
VDDIO_0
Text Label 7325 1925 1    60   ~ 0
VDDIO_1
Text Label 7425 1925 1    60   ~ 0
VDDIO_2
Text Label 7525 1925 1    60   ~ 0
VDDIO_3
Text Label 2300 4350 0    60   ~ 0
SWDCK
Text Label 2300 4450 0    60   ~ 0
SWDIO
Text Label 9150 3250 0    60   ~ 0
XRES
$Comp
L CONN_5 KP1
U 1 1 5AA0063E
P 1850 4250
F 0 "KP1" V 1800 4250 60  0000 C CNN
F 1 "CONN_5" V 1900 4250 60  0000 C CNN
F 2 "Aglet_Footprints:HEADER_1x05" H 1850 4200 60  0001 C CNN
F 3 "" H 1850 4200 60  0000 C CNN
	1    1850 4250
	-1   0    0    -1  
$EndComp
$Comp
L GND1 #PWR06
U 1 1 5AA0064B
P 3000 4950
F 0 "#PWR06" H 3000 4700 50  0001 C CNN
F 1 "GND1" H 3000 4800 50  0000 C CNN
F 2 "" H 3000 4950 50  0001 C CNN
F 3 "" H 3000 4950 50  0001 C CNN
	1    3000 4950
	1    0    0    -1  
$EndComp
Text Label 6925 8000 1    60   ~ 0
VSSA
$Comp
L GND1 #PWR07
U 1 1 5AA00654
P 7150 7950
F 0 "#PWR07" H 7150 7700 50  0001 C CNN
F 1 "GND1" H 7150 7800 50  0000 C CNN
F 2 "" H 7150 7950 50  0001 C CNN
F 3 "" H 7150 7950 50  0001 C CNN
	1    7150 7950
	1    0    0    -1  
$EndComp
$Comp
L C C9
U 1 1 5AA00662
P 5725 1500
F 0 "C9" H 5775 1600 50  0000 L CNN
F 1 "0.1uF" H 5775 1400 50  0000 L CNN
F 2 "Aglet_Footprints:c_0603" H 5725 1500 60  0001 C CNN
F 3 "" H 5725 1500 60  0000 C CNN
	1    5725 1500
	1    0    0    -1  
$EndComp
Text Label 5750 3450 0    60   ~ 0
P0_7
Text Label 5750 3350 0    60   ~ 0
P0_6
Text Label 5750 3250 0    60   ~ 0
P0_5
Text Label 5750 3150 0    60   ~ 0
P0_4
$Comp
L GND1 #PWR08
U 1 1 5AA006D9
P 3475 1950
F 0 "#PWR08" H 3475 1700 50  0001 C CNN
F 1 "GND1" H 3475 1800 50  0000 C CNN
F 2 "" H 3475 1950 50  0001 C CNN
F 3 "" H 3475 1950 50  0001 C CNN
	1    3475 1950
	1    0    0    -1  
$EndComp
Text Label 5750 5550 0    60   ~ 0
P3_1
Text Label 5750 5650 0    60   ~ 0
P3_2
Text Label 5750 5450 0    60   ~ 0
P3_0
Text Label 5750 5750 0    60   ~ 0
P3_3
Text Label 4200 7975 0    60   ~ 0
VTARG
Text Label 3250 7975 0    60   ~ 0
VDDD
Text Notes 2700 7800 0    75   ~ 0
No need for seperate VIO in this design
$Comp
L DIODESCH D1
U 1 1 5AA00758
P 2225 6425
F 0 "D1" H 2225 6525 40  0000 C CNN
F 1 "MBR0520L" H 2225 6325 40  0000 C CNN
F 2 "Aglet_Footprints:D_SOD-123" H 2225 6425 60  0001 C CNN
F 3 "" H 2225 6425 60  0000 C CNN
	1    2225 6425
	1    0    0    1   
$EndComp
$Comp
L 78xDC-DC U1
U 1 1 5AA0075F
P 2925 6050
F 0 "U1" H 2925 6500 60  0000 C CNN
F 1 "78xDC-DC" H 3325 5975 60  0000 C CNN
F 2 "Aglet_Footprints:3-OSTTA" H 2925 6050 60  0001 C CNN
F 3 "" H 2925 6050 60  0001 C CNN
	1    2925 6050
	1    0    0    -1  
$EndComp
Text Label 1600 6425 0    60   ~ 0
VUSB
$Comp
L GND1 #PWR09
U 1 1 5AA0076D
P 2925 7325
F 0 "#PWR09" H 2925 7075 50  0001 C CNN
F 1 "GND1" H 2925 7175 50  0000 C CNN
F 2 "" H 2925 7325 50  0001 C CNN
F 3 "" H 2925 7325 50  0001 C CNN
	1    2925 7325
	1    0    0    -1  
$EndComp
Text Label 3375 6425 0    60   ~ 0
VDDD
$Comp
L C C4
U 1 1 5AA0077E
P 2525 6950
F 0 "C4" H 2575 7050 50  0000 L CNN
F 1 "C" H 2575 6850 50  0000 L CNN
F 2 "Aglet_Footprints:c_1210" H 2525 6950 60  0001 C CNN
F 3 "" H 2525 6950 60  0000 C CNN
	1    2525 6950
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 5AA02EA0
P 3275 6925
F 0 "C5" H 3325 7025 50  0000 L CNN
F 1 "C" H 3325 6825 50  0000 L CNN
F 2 "Aglet_Footprints:c_1210" H 3275 6925 60  0001 C CNN
F 3 "" H 3275 6925 60  0000 C CNN
	1    3275 6925
	1    0    0    -1  
$EndComp
Text Label 9175 4850 0    60   ~ 0
SPI_MISO
Text Label 9175 5950 0    60   ~ 0
SPI_CLK
Text Label 9175 4750 0    60   ~ 0
SPI_MOSI
Text Label 9175 5050 0    60   ~ 0
SPI_CS0
Text Label 9175 5850 0    60   ~ 0
SPI_CS1
Text Label 9175 4950 0    60   ~ 0
PS1_ACK
Text Label 14600 1150 0    60   ~ 0
SPI_MISO
Text Label 14600 1750 0    60   ~ 0
SPI_CLK
Text Label 14600 1250 0    60   ~ 0
SPI_MOSI
Text Label 14600 1650 0    60   ~ 0
SPI_CS0
Text Label 14600 1950 0    60   ~ 0
PS1_ACK
Text Label 14600 2200 0    60   ~ 0
SPI_MISO
Text Label 14600 2800 0    60   ~ 0
SPI_CLK
Text Label 14600 2300 0    60   ~ 0
SPI_MOSI
Text Label 14600 2700 0    60   ~ 0
SPI_CS1
Text Label 14600 3000 0    60   ~ 0
PS1_ACK
$Comp
L CONN_2x10 P3
U 1 1 5AA08071
P 4675 5750
F 0 "P3" H 4675 6300 60  0000 C CNN
F 1 "CONN_2x10" V 4675 5650 60  0000 C CNN
F 2 "Aglet_Footprints:CONN_2_10" H 4675 5900 60  0001 C CNN
F 3 "" H 4675 5900 60  0000 C CNN
	1    4675 5750
	1    0    0    -1  
$EndComp
Text Label 5750 5950 0    60   ~ 0
P3_5
Text Label 5750 6050 0    60   ~ 0
P3_6
Text Label 5750 5850 0    60   ~ 0
P3_4
Text Label 5750 6150 0    60   ~ 0
P3_7
$Comp
L GND1 #PWR010
U 1 1 5AA08AC0
P 4175 6600
F 0 "#PWR010" H 4175 6350 50  0001 C CNN
F 1 "GND1" H 4175 6450 50  0000 C CNN
F 2 "" H 4175 6600 50  0001 C CNN
F 3 "" H 4175 6600 50  0001 C CNN
	1    4175 6600
	1    0    0    -1  
$EndComp
Text Label 5125 5350 0    60   ~ 0
VDDD
Text Label 5125 6250 0    60   ~ 0
VDDD
Text Label 5750 3050 0    60   ~ 0
P0_3
Text Label 5750 2950 0    60   ~ 0
P0_2
Text Label 5750 2850 0    60   ~ 0
P0_1
Text Label 5750 2750 0    60   ~ 0
P0_0
$Comp
L CONN_2x10 P4
U 1 1 5AA0C77C
P 11275 1725
F 0 "P4" H 11275 2275 60  0000 C CNN
F 1 "CONN_2x10" V 11275 1625 60  0000 C CNN
F 2 "Aglet_Footprints:CONN_2_10" H 11275 1875 60  0001 C CNN
F 3 "" H 11275 1875 60  0000 C CNN
	1    11275 1725
	-1   0    0    -1  
$EndComp
$Comp
L GND1 #PWR011
U 1 1 5AA0C786
P 11775 2575
F 0 "#PWR011" H 11775 2325 50  0001 C CNN
F 1 "GND1" H 11775 2425 50  0000 C CNN
F 2 "" H 11775 2575 50  0001 C CNN
F 3 "" H 11775 2575 50  0001 C CNN
	1    11775 2575
	1    0    0    -1  
$EndComp
Text Label 10825 1325 2    60   ~ 0
VDDD
Text Label 10825 2225 2    60   ~ 0
VDDD
$Comp
L CONN_2x10 P5
U 1 1 5AA0D89D
P 13250 1725
F 0 "P5" H 13250 2275 60  0000 C CNN
F 1 "CONN_2x10" V 13250 1625 60  0000 C CNN
F 2 "Aglet_Footprints:CONN_2_10" H 13250 1875 60  0001 C CNN
F 3 "" H 13250 1875 60  0000 C CNN
	1    13250 1725
	-1   0    0    -1  
$EndComp
$Comp
L GND1 #PWR012
U 1 1 5AA0D8A3
P 13750 2575
F 0 "#PWR012" H 13750 2325 50  0001 C CNN
F 1 "GND1" H 13750 2425 50  0000 C CNN
F 2 "" H 13750 2575 50  0001 C CNN
F 3 "" H 13750 2575 50  0001 C CNN
	1    13750 2575
	-1   0    0    -1  
$EndComp
Text Label 12800 1325 2    60   ~ 0
VDDD
Text Label 12800 2225 2    60   ~ 0
VDDD
Text Label 9225 4450 0    60   ~ 0
P6_1
Text Label 9225 4550 0    60   ~ 0
P6_2
Text Label 9225 4350 0    60   ~ 0
P6_0
Text Label 9225 4650 0    60   ~ 0
P6_3
Text Label 13650 4900 0    60   ~ 0
P6_1
Text Label 11225 4400 0    60   ~ 0
P6_2
Text Label 11225 4300 0    60   ~ 0
P6_0
Text Label 13650 5000 0    60   ~ 0
P6_3
Text Label 5750 4650 0    60   ~ 0
P2_1
Text Label 5750 4750 0    60   ~ 0
P2_2
Text Label 5750 4550 0    60   ~ 0
P2_0
Text Label 5750 4850 0    60   ~ 0
P2_3
Text Label 11225 4600 0    60   ~ 0
P2_2
Text Label 13650 5200 0    60   ~ 0
P2_3
Text Label 2625 6425 0    60   ~ 0
VIN
Wire Wire Line
	11350 7050 12150 7050
Wire Wire Line
	12150 6950 11175 6950
Wire Wire Line
	10875 6950 10200 6950
Wire Wire Line
	10200 7050 11050 7050
Wire Wire Line
	2400 8475 2900 8475
Wire Wire Line
	5500 3750 6275 3750
Wire Wire Line
	5500 3650 6275 3650
Wire Wire Line
	2900 8925 2100 8925
Wire Wire Line
	2900 8825 1700 8825
Wire Wire Line
	2900 8725 1300 8725
Wire Wire Line
	2900 8625 900  8625
Wire Wire Line
	2100 8925 2100 9150
Wire Wire Line
	1700 8825 1700 9150
Wire Wire Line
	1300 8725 1300 9150
Wire Wire Line
	900  8625 900  9150
Wire Wire Line
	12150 7250 12075 7250
Wire Wire Line
	12075 7250 12075 7725
Wire Wire Line
	10825 7725 12600 7725
Wire Wire Line
	11825 7725 11825 7575
Wire Wire Line
	12600 7725 12600 7650
Connection ~ 12075 7725
Wire Wire Line
	12500 7650 12500 7725
Connection ~ 12500 7725
Wire Wire Line
	5675 3850 6275 3850
Wire Wire Line
	5675 3950 6275 3950
Wire Wire Line
	5675 4050 6275 4050
Wire Wire Line
	5675 4150 6275 4150
Wire Wire Line
	7375 8750 5975 8750
Wire Wire Line
	7375 8850 6175 8850
Wire Wire Line
	7375 8950 6375 8950
Wire Wire Line
	7375 9050 6575 9050
Wire Wire Line
	6575 9050 6575 9325
Wire Wire Line
	6375 8950 6375 9325
Wire Wire Line
	6175 8850 6175 9325
Wire Wire Line
	5975 8750 5975 9325
Wire Wire Line
	5975 9775 5975 9625
Wire Wire Line
	5975 9775 6575 9775
Wire Wire Line
	6575 9775 6575 9625
Wire Wire Line
	6375 9625 6375 9775
Wire Wire Line
	6175 9775 6175 9625
Wire Wire Line
	6500 9900 6500 9775
Wire Wire Line
	1525 9725 1525 9850
Wire Wire Line
	900  9725 2100 9725
Wire Wire Line
	2100 9725 2100 9550
Wire Wire Line
	1700 9550 1700 9725
Connection ~ 1700 9725
Wire Wire Line
	1300 9725 1300 9550
Connection ~ 1525 9725
Wire Wire Line
	900  9725 900  9550
Connection ~ 1300 9725
Wire Wire Line
	12300 7800 12300 7725
Connection ~ 12300 7725
Wire Wire Line
	4925 1250 7025 1250
Wire Wire Line
	4925 1250 4925 1300
Wire Wire Line
	5325 1300 5325 1250
Connection ~ 5325 1250
Wire Wire Line
	4125 1150 7625 1150
Wire Wire Line
	4125 1150 4125 1300
Wire Wire Line
	4525 1300 4525 1150
Connection ~ 4525 1150
Wire Wire Line
	2925 950  2925 1300
Wire Wire Line
	3325 1300 3325 1050
Wire Wire Line
	2125 950  2125 1300
Wire Wire Line
	2525 950  2525 1300
Wire Wire Line
	2125 1800 5725 1800
Wire Wire Line
	2125 1800 2125 1700
Wire Wire Line
	2525 1700 2525 1800
Connection ~ 2525 1800
Wire Wire Line
	2925 1700 2925 1800
Connection ~ 2925 1800
Wire Wire Line
	3325 1700 3325 1800
Connection ~ 3325 1800
Wire Wire Line
	4125 1700 4125 1800
Connection ~ 4125 1800
Wire Wire Line
	4525 1700 4525 1800
Connection ~ 4525 1800
Wire Wire Line
	4925 1700 4925 1800
Connection ~ 4925 1800
Wire Wire Line
	5325 1800 5325 1700
Wire Wire Line
	2200 4250 3125 4250
Wire Wire Line
	3125 4075 3125 4325
Wire Wire Line
	12150 6850 11825 6850
Wire Wire Line
	11825 6675 11825 7175
Wire Wire Line
	10825 6675 11825 6675
Connection ~ 11825 6850
Wire Wire Line
	3450 8625 3825 8625
Wire Wire Line
	4275 8625 4850 8625
Wire Wire Line
	4850 8750 4275 8750
Wire Notes Line
	2325 8075 5200 8075
Wire Notes Line
	5200 7675 5200 10275
Wire Notes Line
	5200 10275 2325 10275
Wire Notes Line
	2325 10275 2325 7675
Wire Wire Line
	3125 3700 2800 3700
Wire Wire Line
	3125 3775 3125 3700
Wire Wire Line
	11475 7725 11475 7575
Connection ~ 11825 7725
Wire Wire Line
	11475 7175 11475 6675
Connection ~ 11475 6675
Wire Wire Line
	10825 7725 10825 7575
Connection ~ 11475 7725
Wire Wire Line
	3725 1050 3725 1300
Wire Wire Line
	3725 1700 3725 1800
Connection ~ 3725 1800
Wire Wire Line
	2125 950  8125 950 
Connection ~ 2525 950 
Wire Wire Line
	3325 1050 7925 1050
Connection ~ 3725 1050
Wire Wire Line
	7225 1475 7225 2000
Wire Wire Line
	7325 1475 7325 2000
Wire Wire Line
	7425 1475 7425 2000
Wire Wire Line
	7525 1475 7525 2000
Wire Wire Line
	9025 6950 9700 6950
Wire Wire Line
	9025 7050 9700 7050
Wire Wire Line
	9700 7050 10200 6950
Wire Wire Line
	9700 6950 10200 7050
Connection ~ 3125 4250
Connection ~ 2925 950 
Wire Wire Line
	7025 1250 7025 2000
Wire Wire Line
	7625 1150 7625 2000
Wire Wire Line
	7925 1050 7925 2000
Wire Wire Line
	8025 2000 8025 1850
Wire Wire Line
	8025 1850 8125 1850
Wire Wire Line
	8125 950  8125 2000
Connection ~ 8125 1850
Wire Wire Line
	7125 1875 7125 2000
Wire Wire Line
	7125 1875 7025 1875
Connection ~ 7025 1875
Wire Wire Line
	2200 4350 2700 4350
Wire Wire Line
	2200 4450 2700 4450
Wire Wire Line
	9025 3250 9450 3250
Wire Wire Line
	2200 4150 2875 4150
Wire Wire Line
	2875 4150 2875 4850
Wire Wire Line
	2875 4850 3125 4850
Wire Wire Line
	3125 4850 3125 4725
Wire Wire Line
	2800 3700 2800 4050
Wire Wire Line
	2800 4050 2200 4050
Wire Wire Line
	3000 4950 3000 4850
Connection ~ 3000 4850
Wire Wire Line
	6925 8050 6925 7700
Wire Wire Line
	7025 7700 7025 7825
Wire Wire Line
	7025 7825 7225 7825
Wire Wire Line
	7225 7825 7225 7700
Wire Wire Line
	7125 7700 7125 7825
Connection ~ 7125 7825
Wire Wire Line
	7150 7950 7150 7825
Connection ~ 7150 7825
Wire Wire Line
	5725 1800 5725 1700
Wire Wire Line
	5725 1300 5725 1250
Connection ~ 5725 1250
Connection ~ 5325 1800
Connection ~ 6175 9775
Connection ~ 6375 9775
Connection ~ 6500 9775
Wire Wire Line
	5675 3450 6275 3450
Wire Wire Line
	5675 3350 6275 3350
Wire Wire Line
	5675 3250 6275 3250
Wire Wire Line
	5675 3150 6275 3150
Wire Wire Line
	3475 1950 3475 1800
Connection ~ 3475 1800
Wire Wire Line
	5025 5550 6275 5550
Wire Wire Line
	5025 5650 6275 5650
Wire Wire Line
	5025 5450 6275 5450
Wire Wire Line
	5025 5750 6275 5750
Wire Wire Line
	2825 7975 3675 7975
Wire Wire Line
	3875 7975 4650 7975
Wire Notes Line
	2325 7675 5200 7675
Wire Wire Line
	1500 6425 2025 6425
Wire Wire Line
	2425 6425 2825 6425
Wire Wire Line
	2925 6250 2925 7325
Wire Wire Line
	3025 6250 3025 6425
Wire Wire Line
	3025 6425 3675 6425
Wire Wire Line
	2525 7150 2525 7225
Wire Wire Line
	2525 7225 2925 7225
Connection ~ 2925 7225
Wire Wire Line
	2925 7150 3275 7150
Wire Wire Line
	3275 7150 3275 7125
Connection ~ 2925 7150
Wire Wire Line
	3275 6725 3275 6425
Connection ~ 3275 6425
Wire Wire Line
	2825 6425 2825 6250
Wire Wire Line
	2525 6425 2525 6750
Connection ~ 2525 6425
Wire Wire Line
	9625 5050 9025 5050
Wire Wire Line
	9025 4750 9625 4750
Wire Wire Line
	9025 5850 9625 5850
Wire Wire Line
	9025 4950 9625 4950
Wire Wire Line
	9025 5950 9575 5950
Wire Wire Line
	9025 4850 9575 4850
Wire Wire Line
	14575 1650 15225 1650
Wire Wire Line
	14575 1250 15225 1250
Wire Wire Line
	14575 1950 15225 1950
Wire Wire Line
	14575 1750 15225 1750
Wire Wire Line
	14575 1150 15225 1150
Wire Wire Line
	14575 2700 15225 2700
Wire Wire Line
	14575 2300 15225 2300
Wire Wire Line
	14575 3000 15225 3000
Wire Wire Line
	14575 2800 15225 2800
Wire Wire Line
	14575 2200 15225 2200
Wire Wire Line
	5025 5950 6275 5950
Wire Wire Line
	5025 6050 6275 6050
Wire Wire Line
	5025 5850 6275 5850
Wire Wire Line
	5025 6150 6275 6150
Wire Wire Line
	5025 5350 5425 5350
Wire Wire Line
	5025 6250 5425 6250
Wire Wire Line
	4325 6250 4275 6250
Wire Wire Line
	4275 6250 4275 6450
Wire Wire Line
	4275 6450 5075 6450
Wire Wire Line
	5075 6450 5075 6250
Connection ~ 5075 6250
Wire Wire Line
	5075 5350 5075 5100
Wire Wire Line
	5075 5100 4275 5100
Wire Wire Line
	4275 5100 4275 5350
Wire Wire Line
	4275 5350 4325 5350
Connection ~ 5075 5350
Wire Wire Line
	4325 5450 4175 5450
Wire Wire Line
	4175 5450 4175 6600
Wire Wire Line
	4325 6150 4175 6150
Connection ~ 4175 6150
Wire Wire Line
	4325 6050 4175 6050
Connection ~ 4175 6050
Wire Wire Line
	4325 5950 4175 5950
Connection ~ 4175 5950
Wire Wire Line
	4325 5850 4175 5850
Connection ~ 4175 5850
Wire Wire Line
	4325 5750 4175 5750
Connection ~ 4175 5750
Wire Wire Line
	4325 5650 4175 5650
Connection ~ 4175 5650
Wire Wire Line
	4325 5550 4175 5550
Connection ~ 4175 5550
Wire Wire Line
	5675 3050 6275 3050
Wire Wire Line
	5675 2950 6275 2950
Wire Wire Line
	5675 2850 6275 2850
Wire Wire Line
	5675 2750 6275 2750
Wire Wire Line
	10525 1325 10925 1325
Wire Wire Line
	10525 2225 10925 2225
Wire Wire Line
	11625 2225 11675 2225
Wire Wire Line
	11675 2225 11675 2425
Wire Wire Line
	11675 2425 10875 2425
Wire Wire Line
	10875 2425 10875 2225
Connection ~ 10875 2225
Wire Wire Line
	10875 1325 10875 1075
Wire Wire Line
	10875 1075 11675 1075
Wire Wire Line
	11675 1075 11675 1325
Wire Wire Line
	11675 1325 11625 1325
Connection ~ 10875 1325
Wire Wire Line
	11625 1425 11775 1425
Wire Wire Line
	11775 1425 11775 2575
Wire Wire Line
	11625 2125 11775 2125
Connection ~ 11775 2125
Wire Wire Line
	11625 2025 11775 2025
Connection ~ 11775 2025
Wire Wire Line
	11625 1925 11775 1925
Connection ~ 11775 1925
Wire Wire Line
	11625 1825 11775 1825
Connection ~ 11775 1825
Wire Wire Line
	11625 1725 11775 1725
Connection ~ 11775 1725
Wire Wire Line
	11625 1625 11775 1625
Connection ~ 11775 1625
Wire Wire Line
	11625 1525 11775 1525
Connection ~ 11775 1525
Wire Wire Line
	12500 1325 12900 1325
Wire Wire Line
	12500 2225 12900 2225
Wire Wire Line
	13600 2225 13650 2225
Wire Wire Line
	13650 2225 13650 2425
Wire Wire Line
	13650 2425 12850 2425
Wire Wire Line
	12850 2425 12850 2225
Connection ~ 12850 2225
Wire Wire Line
	12850 1325 12850 1075
Wire Wire Line
	12850 1075 13650 1075
Wire Wire Line
	13650 1075 13650 1325
Wire Wire Line
	13650 1325 13600 1325
Connection ~ 12850 1325
Wire Wire Line
	13600 1425 13750 1425
Wire Wire Line
	13750 1425 13750 2575
Wire Wire Line
	13600 2125 13750 2125
Connection ~ 13750 2125
Wire Wire Line
	13600 2025 13750 2025
Connection ~ 13750 2025
Wire Wire Line
	13600 1925 13750 1925
Connection ~ 13750 1925
Wire Wire Line
	13600 1825 13750 1825
Connection ~ 13750 1825
Wire Wire Line
	13600 1725 13750 1725
Connection ~ 13750 1725
Wire Wire Line
	13600 1625 13750 1625
Connection ~ 13750 1625
Wire Wire Line
	13600 1525 13750 1525
Connection ~ 13750 1525
Wire Wire Line
	9025 4450 9750 4450
Wire Wire Line
	9025 4550 9750 4550
Wire Wire Line
	9025 4350 9750 4350
Wire Wire Line
	9025 4650 9750 4650
Wire Wire Line
	13450 4800 14175 4800
Wire Wire Line
	11025 4400 11750 4400
Wire Wire Line
	11025 4300 11750 4300
Wire Wire Line
	13450 4900 14175 4900
Wire Wire Line
	5550 4650 6275 4650
Wire Wire Line
	5550 4750 6275 4750
Wire Wire Line
	5550 4550 6275 4550
Wire Wire Line
	5550 4850 6275 4850
Wire Wire Line
	13450 5000 14175 5000
Wire Wire Line
	11025 4600 11750 4600
Wire Wire Line
	11025 4500 11750 4500
Wire Wire Line
	13450 5100 14175 5100
Wire Wire Line
	10825 6675 10825 7175
Wire Wire Line
	3675 7975 3675 7925
Wire Wire Line
	3875 7925 3875 7975
Wire Wire Line
	2900 8475 2900 8925
Connection ~ 2900 8625
Connection ~ 2900 8725
Connection ~ 2900 8825
Wire Wire Line
	3825 8625 3825 8725
Wire Wire Line
	4850 8475 4850 8750
Connection ~ 4850 8625
$Comp
L GND1 #PWR013
U 1 1 5AA28E04
P 15100 3200
F 0 "#PWR013" H 15100 2950 50  0001 C CNN
F 1 "GND1" H 15100 3050 50  0000 C CNN
F 2 "" H 15100 3200 50  0001 C CNN
F 3 "" H 15100 3200 50  0001 C CNN
	1    15100 3200
	-1   0    0    -1  
$EndComp
Wire Wire Line
	15100 1450 15100 3200
Wire Wire Line
	15100 2500 15225 2500
Wire Wire Line
	15100 1450 15225 1450
Connection ~ 15100 2500
$Comp
L VCC #PWR014
U 1 1 5AA29711
P 15200 900
F 0 "#PWR014" H 15200 1000 30  0001 C CNN
F 1 "VCC" H 15200 1000 30  0000 C CNN
F 2 "" H 15200 900 60  0000 C CNN
F 3 "" H 15200 900 60  0000 C CNN
	1    15200 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	15200 900  15200 2600
Wire Wire Line
	15200 1550 15225 1550
Wire Wire Line
	15200 2600 15225 2600
Connection ~ 15200 1550
Wire Wire Line
	3675 7925 3875 7925
Text Label 5750 5050 0    60   ~ 0
P2_5
Text Label 5750 5150 0    60   ~ 0
P2_6
Text Label 5750 4950 0    60   ~ 0
P2_4
Text Label 5750 5250 0    60   ~ 0
P2_7
Wire Wire Line
	5550 5050 6275 5050
Wire Wire Line
	5550 5150 6275 5150
Wire Wire Line
	5550 4950 6275 4950
Wire Wire Line
	5550 5250 6275 5250
Text Label 5750 6450 0    60   ~ 0
P4_1
Text Label 5750 6550 0    60   ~ 0
P4_2
Text Label 5750 6350 0    60   ~ 0
P4_0
Text Label 5750 6650 0    60   ~ 0
P4_3
Wire Wire Line
	5550 6450 6275 6450
Wire Wire Line
	5550 6550 6275 6550
Wire Wire Line
	5550 6350 6275 6350
Wire Wire Line
	5550 6650 6275 6650
Text Label 5750 6850 0    60   ~ 0
P4_5
Text Label 5750 6950 0    60   ~ 0
P4_6
Text Label 5750 6750 0    60   ~ 0
P4_4
Text Label 5750 7050 0    60   ~ 0
P4_7
Wire Wire Line
	5550 6850 6275 6850
Wire Wire Line
	5550 6950 6275 6950
Wire Wire Line
	5550 6750 6275 6750
Wire Wire Line
	5550 7050 6275 7050
$Comp
L CONN_2x10 P1
U 1 1 5AB698DC
P 14525 5000
F 0 "P1" H 14525 5550 60  0000 C CNN
F 1 "CONN_2x10" V 14525 4900 60  0000 C CNN
F 2 "Aglet_Footprints:CONN_2_10" H 14525 5150 60  0001 C CNN
F 3 "" H 14525 5150 60  0000 C CNN
	1    14525 5000
	-1   0    0    -1  
$EndComp
$Comp
L GND1 #PWR015
U 1 1 5AB698E2
P 15025 5850
F 0 "#PWR015" H 15025 5600 50  0001 C CNN
F 1 "GND1" H 15025 5700 50  0000 C CNN
F 2 "" H 15025 5850 50  0001 C CNN
F 3 "" H 15025 5850 50  0001 C CNN
	1    15025 5850
	-1   0    0    -1  
$EndComp
Text Label 14075 4600 2    60   ~ 0
VDDD
Text Label 14075 5500 2    60   ~ 0
VDDD
Text Label 13650 5300 0    60   ~ 0
P2_5
Text Label 11225 4800 0    60   ~ 0
P2_6
Text Label 11225 4700 0    60   ~ 0
P2_4
Text Label 13650 5400 0    60   ~ 0
P2_7
Wire Wire Line
	13775 4600 14175 4600
Wire Wire Line
	13775 5500 14175 5500
Wire Wire Line
	14875 5500 14925 5500
Wire Wire Line
	14925 5500 14925 5700
Wire Wire Line
	14925 5700 14125 5700
Wire Wire Line
	14125 5700 14125 5500
Connection ~ 14125 5500
Wire Wire Line
	14125 4600 14125 4350
Wire Wire Line
	14125 4350 14925 4350
Wire Wire Line
	14925 4350 14925 4600
Wire Wire Line
	14925 4600 14875 4600
Connection ~ 14125 4600
Wire Wire Line
	14875 4700 15025 4700
Wire Wire Line
	15025 4700 15025 5850
Wire Wire Line
	14875 5400 15025 5400
Connection ~ 15025 5400
Wire Wire Line
	14875 5300 15025 5300
Connection ~ 15025 5300
Wire Wire Line
	14875 5200 15025 5200
Connection ~ 15025 5200
Wire Wire Line
	14875 5100 15025 5100
Connection ~ 15025 5100
Wire Wire Line
	14875 5000 15025 5000
Connection ~ 15025 5000
Wire Wire Line
	14875 4900 15025 4900
Connection ~ 15025 4900
Wire Wire Line
	14875 4800 15025 4800
Connection ~ 15025 4800
Wire Wire Line
	13450 5200 14175 5200
Wire Wire Line
	11025 4800 11750 4800
Wire Wire Line
	11025 4700 11750 4700
Wire Wire Line
	13450 5300 14175 5300
Wire Wire Line
	10200 1825 10925 1825
Wire Wire Line
	12175 2025 12900 2025
Wire Wire Line
	10200 1925 10925 1925
Wire Wire Line
	12175 2125 12900 2125
$Comp
L CONN_2x10 P2
U 1 1 5AB69AEB
P 12100 4400
F 0 "P2" H 12100 4950 60  0000 C CNN
F 1 "CONN_2x10" V 12100 4300 60  0000 C CNN
F 2 "Aglet_Footprints:CONN_2_10" H 12100 4550 60  0001 C CNN
F 3 "" H 12100 4550 60  0000 C CNN
	1    12100 4400
	-1   0    0    -1  
$EndComp
$Comp
L GND1 #PWR016
U 1 1 5AB69AF1
P 12600 5250
F 0 "#PWR016" H 12600 5000 50  0001 C CNN
F 1 "GND1" H 12600 5100 50  0000 C CNN
F 2 "" H 12600 5250 50  0001 C CNN
F 3 "" H 12600 5250 50  0001 C CNN
	1    12600 5250
	-1   0    0    -1  
$EndComp
Text Label 11650 4000 2    60   ~ 0
VDDD
Text Label 11650 4900 2    60   ~ 0
VDDD
Wire Wire Line
	11350 4000 11750 4000
Wire Wire Line
	11350 4900 11750 4900
Wire Wire Line
	12450 4900 12500 4900
Wire Wire Line
	12500 4900 12500 5100
Wire Wire Line
	12500 5100 11700 5100
Wire Wire Line
	11700 5100 11700 4900
Connection ~ 11700 4900
Wire Wire Line
	11700 4000 11700 3750
Wire Wire Line
	11700 3750 12500 3750
Wire Wire Line
	12500 3750 12500 4000
Wire Wire Line
	12500 4000 12450 4000
Connection ~ 11700 4000
Wire Wire Line
	12450 4100 12600 4100
Wire Wire Line
	12600 4100 12600 5250
Wire Wire Line
	12450 4800 12600 4800
Connection ~ 12600 4800
Wire Wire Line
	12450 4700 12600 4700
Connection ~ 12600 4700
Wire Wire Line
	12450 4600 12600 4600
Connection ~ 12600 4600
Wire Wire Line
	12450 4500 12600 4500
Connection ~ 12600 4500
Wire Wire Line
	12450 4400 12600 4400
Connection ~ 12600 4400
Wire Wire Line
	12450 4300 12600 4300
Connection ~ 12600 4300
Wire Wire Line
	12450 4200 12600 4200
Connection ~ 12600 4200
Wire Wire Line
	13450 5400 14175 5400
Wire Wire Line
	11025 4200 11750 4200
Wire Wire Line
	11025 4100 11750 4100
Wire Wire Line
	13450 4700 14175 4700
Wire Wire Line
	10200 1525 10925 1525
Wire Wire Line
	10200 1625 10925 1625
Wire Wire Line
	10200 1425 10925 1425
Wire Wire Line
	10200 1725 10925 1725
Text Label 10400 1925 0    60   ~ 0
P4_1
Text Label 12375 2025 0    60   ~ 0
P4_2
Text Label 10400 1825 0    60   ~ 0
P4_0
Text Label 12375 2125 0    60   ~ 0
P4_3
Text Label 13650 4700 0    60   ~ 0
P4_5
Text Label 11225 4200 0    60   ~ 0
P4_6
Text Label 11225 4100 0    60   ~ 0
P4_4
Text Label 13650 4800 0    60   ~ 0
P4_7
Text Label 13650 5100 0    60   ~ 0
P2_1
Text Label 11225 4500 0    60   ~ 0
P2_0
Text Label 9225 5550 0    60   ~ 0
P12_1
Text Label 9225 5650 0    60   ~ 0
P12_2
Text Label 9225 5450 0    60   ~ 0
P12_0
Text Label 9225 5750 0    60   ~ 0
P12_3
Wire Wire Line
	9025 5550 9750 5550
Wire Wire Line
	9025 5650 9750 5650
Wire Wire Line
	9025 5450 9750 5450
Wire Wire Line
	9025 5750 9750 5750
Text Label 10550 5200 0    60   ~ 0
P12_1
Text Label 10550 5300 0    60   ~ 0
P12_2
Text Label 10550 5100 0    60   ~ 0
P12_0
Text Label 10550 5400 0    60   ~ 0
P12_3
Text Label 10450 1525 0    60   ~ 0
P12_1
Text Label 10450 1625 0    60   ~ 0
P12_2
Text Label 10450 1425 0    60   ~ 0
P12_0
Text Label 10450 1725 0    60   ~ 0
P12_3
Text Label 12375 1925 0    60   ~ 0
P0_7
Text Label 12375 1825 0    60   ~ 0
P0_6
Text Label 12375 1725 0    60   ~ 0
P0_5
Text Label 12375 1625 0    60   ~ 0
P0_4
Text Label 12375 1525 0    60   ~ 0
P0_3
Text Label 12375 1425 0    60   ~ 0
P0_2
Text Label 10400 2125 0    60   ~ 0
P0_1
Text Label 10400 2025 0    60   ~ 0
P0_0
Wire Wire Line
	12900 1925 12175 1925
Wire Wire Line
	12900 1825 12175 1825
Wire Wire Line
	12900 1725 12175 1725
Wire Wire Line
	12900 1625 12175 1625
Wire Wire Line
	12900 1525 12175 1525
Wire Wire Line
	12900 1425 12175 1425
Wire Wire Line
	10925 2125 10225 2125
Wire Wire Line
	10925 2025 10200 2025
$EndSCHEMATC