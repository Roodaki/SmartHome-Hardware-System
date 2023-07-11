<div align="center">
  <h1><strong>SmartHome Temperature & Lightning Monitoring/Controlling Hardware-System</strong></h1>
  <p><strong>A comprehensive solution designed to manage temperature and lighting in a smart home environment. It incorporates advanced features such as temperature sensors, LCD displays, LEDs, and motors to provide real-time temperature monitoring, visual and auditory indicators for critical conditions, and dynamic control of lighting intensity. With its user-friendly interface and robust security mechanisms, the system ensures optimal comfort, energy efficiency, and security in the smart home.</strong></p>
</div>

![Screenshot (142)](https://github.com/Roodaki/SmartHome-Hardware-System/assets/89901590/b48b946a-ebb5-434a-ae8b-e9bf9be552ea)

## Table of Contents
- [Features](#features)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
  - [Requirements](#requirements)
  - [Installation](#installation)

## Features
- ***Security Module***
  - **Keypad**: The system incorporates a secure keypad for users to enter their password. The intuitive keypad interface allows for convenient and secure password input. The '*' symbol is used to submit the password, while the '#' symbol is used to delete the last entered character, ensuring accurate password entry.
  - **Toggle-Switch**: A toggle-switch functionality enhances password confidentiality by providing control over password visibility. Users can easily switch between displaying asterisks (*) or the actual characters on the LCD screen, adding an extra layer of security to the system.
  - **Access Control**: A robust access control mechanism restricts access to other system functionalities, such as temperature control and lighting control, until the correct password is entered. This ensures that only authorized individuals can interact with the system, safeguarding the smart home environment.

- ***Temperature Monitoring and Controlling Module***
  - **LM35 Sensor and LCD Display**: The integration of the LM35 temperature sensor enables accurate temperature measurement. Real-time temperature readings are displayed on the LCD screen, providing users with up-to-date information about the ambient temperature within the smart home.
  - **Blinking-LEDs and Alarming-Buzzers**: To ensure user safety and comfort, the system employs visual and auditory indicators to convey critical temperature conditions. When the temperature exceeds the predefined upper threshold (55 degrees), a blinking red LED and an alarming buzzer alert users to take prompt cooling measures. Similarly, for extremely low temperatures (below 3 degrees), a blinking blue LED and a distinct buzzer signal prompt users to address heating requirements.
  - **Cooler and Heater Motors**: The temperature control module features dedicated cooler and heater motors. The cooler motor operates within the temperature range of 25 to 55 degrees, dynamically adjusting its duty cycle to maintain optimal cooling. The duty cycle increases by 10% for every additional 5 degrees. Likewise, the heater motor activates when the temperature falls between 0 and 20 degrees, with the duty cycle decreasing by 25% for every subsequent 5 degrees. This precise motor control ensures efficient temperature regulation and user comfort.

-  ***Light Monitoring and Controlling Module***
    - **LDR Sensor and LCD Display**: The system utilizes a Light Dependent Resistor (LDR) to accurately measure ambient light intensity. The LDR captures real-time light level variations, which are displayed on the LCD screen, allowing users to observe and adjust the lighting conditions as needed.
    - **Motorized Light Control with Dynamic Duty Cycle**: A dedicated motor controls the lighting intensity based on the LDR readings. The motor's duty cycle dynamically adapts to the light intensity levels, providing optimal illumination for the smart home environment. The duty cycle is adjusted based on the light intensity levels: for light intensity between 0 and 25, the motor operates at 100% duty cycle, and as the light intensity increases by 25% increments, the duty cycle decreases by a factor of 25% at each step, allowing precise and efficient control over the lighting intensity.

## Project Structure
The project has the following structure:
```
├── Codes/
│   ├── MASTER/
│   │   ├── src/
│   │   │   ├── INT1.h
│   │   │   ├── keypad.h
│   │   │   ├── LDR.h
│   │   │   ├── main.c
│   │   │   ├── SPI.h
│   │   │   └── temperature.h
│   │   ├── .gitignore
│   │   └── platformio.ini
│   └── SLAVE/
│       ├── src/
│       │   ├── LCD.h
│       │   ├── LED.h
│       │   ├── main.c
│       │   ├── motor.h
│       │   ├── password.h
│       │   └── SPI.h
│       ├── .gitignore
│       └── platformio.ini
├── Simulation/
│   └── Schematic.pdsprj
└── README.md
```

## Getting Started
### Requirements
To set up and run the project, you will need the following:
  * **VS-Code and PlatformIO Extension**: Install VS Code, and then add the PlatformIO extension to your VS Code installation. PlatformIO provides a powerful integrated development environment (IDE) for embedded systems development.
  * **Proteus Design Suite**: Install Proteus Design Suite, a simulation software used to simulate and test the project.
  * **Git Command Line Tool (or Git GUI Client)**: Install Git command line tool or a Git GUI client to clone the project repository.
### Installation
Follow these steps to set up and run the project:
  1. Open a terminal or command prompt and clone the project repository by running the following command: `git clone https://github.com/Roodaki/SmartHome-Hardware-System.git`
  2. Open the cloned project in VS Code and use the PlatformIO extension to build the project codes.
  3. Open Proteus Design Suite and import the simulation file (Schematic.pdsprj) provided in the repository.
  4. Load the hex files generated by PlatformIO into the corresponding microcontroller components in the Proteus simulation.
  5. Run the simulation to test and validate the project functionality.
