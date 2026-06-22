# Arduino Sun-Tracking Solar Panel ☀️
This repository contains the C++ control logic for an automated, dual-LDR solar tracking system built on the Arduino Uno platform.

### Hardware Architecture
* **Microcontroller:** Arduino Uno
* **Actuator:** SG90 Micro Servo (PWM driven)
* **Sensors:** 2x Light Dependent Resistors (LDRs) configured as voltage dividers

### System Logic
The code reads analog voltages from the LDRs to determine the direction of the strongest light source. It utilizes a configurable "deadband" (error tolerance) to prevent the servo from constantly twitching due to minor ambient light changes or electrical noise. Software-level bounds checking is implemented to protect the mechanical limits of the servo gears.

*This project was built as part of a hardware comparison experiment, comparing this microcontroller-driven approach against a purely analog (BC547 transistor-based) control loop.*
