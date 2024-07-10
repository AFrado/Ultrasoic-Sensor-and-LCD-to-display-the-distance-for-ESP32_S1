# Ultrasoic Sensor and LCD to display the distance for ESP32_S1
This project demonstrates how to use an ESP32 microcontroller to measure the distance to an object using an ultrasonic sensor and display the measured distance on a 16x2 LCD. The project is designed to showcase how microcontrollers can interface with sensors and output devices to provide real-time data visualization.

Components:
ESP32 Microcontroller: Acts as the brain of the project, handling the input from the ultrasonic sensor and controlling the output to the LCD.
Ultrasonic Sensor (HC-SR04): Used to measure the distance to an object by emitting ultrasonic waves and measuring the time it takes for the echo to return.
TRIG Pin: GPIO 12
ECHO Pin: GPIO 14
16x2 LCD with Parallel Interface: Displays the measured distance.
RS Pin: GPIO 23
EN Pin: GPIO 22
D4 Pin: GPIO 21
D5 Pin: GPIO 19
D6 Pin: GPIO 18
D7 Pin: GPIO 5
Functionality:
Distance Measurement:

The ultrasonic sensor is triggered by sending a short pulse on the TRIG pin.
The sensor then sends out an ultrasonic burst and waits for the echo to return.
The time taken for the echo to return is measured and converted to distance in centimeters.
Distance Display:

The measured distance is sent to the LCD, which displays the distance in centimeters.
The display updates approximately every 500 milliseconds to provide real-time distance readings.
Technical Details:
Ultrasonic Sensor Initialization:

The NewPing library is used to simplify the process of interacting with the ultrasonic sensor.
LCD Control Without Libraries:

The project manually controls the LCD without relying on the LiquidCrystal library. This involves directly manipulating the GPIO pins to send the necessary commands and data to the LCD.
Project Code:

The code includes functions to send commands and data to the LCD, initialize the LCD, and print strings to the LCD.
The main loop continuously measures the distance and updates the LCD with the latest reading.
Benefits and Applications:
Educational Value:

This project serves as an educational tool for understanding how microcontrollers can interface with sensors and display devices.
It provides insight into manually controlling hardware components without relying on high-level libraries.
Practical Applications:

Distance measurement is a fundamental aspect of many applications, including robotics, security systems, and industrial automation.
The techniques demonstrated in this project can be extended to more complex systems requiring distance measurement and display.
Real-Time Feedback:

The project provides immediate visual feedback on the distance to an object, which can be useful for debugging and testing in various applications.
By completing this project, users will gain hands-on experience in interfacing an ESP32 with an ultrasonic sensor and an LCD, enhancing their understanding of embedded systems and real-time data display.



![image](https://github.com/AFrado/Ultrasoic-Sensor-and-LCD-to-display-the-distance-for-ESP32_S1/assets/174622127/8f089abd-d46f-4061-a40a-660c9d85d57e)
