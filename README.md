# ESP32-Activity-Progress
🚀 A collection of my ESP32 projects and lab activities, showcasing experiments with 🛠️ sensors, ⚙️ actuators, 🌐 web servers, 📊 data logging, and 💡 IoT applications. Built for learning and documenting my progress in embedded systems and programming.

👋 I am Cel Rick Almario

This repository is a personal collection of my ESP32 projects and lab activities.
It showcases my experiments with sensors, actuators, web servers, data logging, and IoT applications.
All built for learning and documenting my journey in embedded systems and programming.

🚀 My ESP32 Progress & Activities
✅ LED Blink Test
• Used onboard LED (GPIO 2) and external LED on G15 with resistor
• Verified that my ESP32 board works perfectly

✅ Touch Sensor Read & Debug
• Used touchRead() on G4 (T0) to get raw touch values
• Printed them on Serial Monitor for calibration

✅ Touch Sensor → LED Control
• Made LED on G15 light up when touching G4
• Practiced simple digital logic with if conditions

✅ Pin Mapping & Analysis
• Listed ESP32 pin labels (V5, GND, G4, G13, G15, etc)
• Identified safe GPIOs for inputs, outputs, I2C, PWM, and touch

✅ Servo Motor Control
• Installed and used ESP32Servo library
• Controlled servo on G13, sweeping 0° → 90° → 180°

✅ Servo via Web Server
• Created simple HTTP server to adjust servo angle from phone browser

✅ LCD I2C Display
• Wired 16x2 LCD via I2C to G21 (SDA) and G22 (SCL)
• Displayed static and dynamic messages

✅ Ultrasonic Distance + LCD
• Connected HC-SR04 Trig to G13 and Echo to G12
• Displayed live distance readings on LCD in cm

✅ DHT11 Temp & Humidity + LCD
• Connected DHT11 to G23 with optional pull-up
• Displayed temperature & humidity on LCD and Serial Monitor

✅ ESP32 to ESP32 Communication
• Used one ESP32 as transmitter with web server & LCD to send data
• Used another ESP32 as receiver with web server & LCD to show received data

✅ Sensor Data Logging to MySQL
• Sent DHT11 temperature & humidity data from ESP32 to PHP script
• Saved readings into MySQL database every 30 seconds

🛠️ Tools & Tech Used
ESP32 (DOIT DevKit V1)

Arduino IDE & PlatformIO

RemoteXY for quick interfaces

HTTP client/server libraries

PHP & MySQL for database logging

VS Code for code management

💡 Purpose
This repository is mainly for practice and documentation, to build my skills in:

Embedded C++ programming

IoT data handling

Electronics hardware interfacing

Web & database integration with microcontrollers
