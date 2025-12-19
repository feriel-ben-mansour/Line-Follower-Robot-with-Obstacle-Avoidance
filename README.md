# Line-Following Robot with Obstacle Avoidance

**Hackathon Project**

##  Project Overview
This project presents an Arduino-based autonomous robot developed during a hackathon. The robot is capable of tracking a predefined path and navigating through environments with obstacles by combining infrared-based line detection and distance sensing.

The solution combines mechanical design, embedded firmware development, and system simulation under tight time constraints (24 hours challenge).

---

##  Key Features
- Autonomous line-following using infrared sensors
- Obstacle detection and avoidance logic
- Real-time control using Arduino
- Fast prototyping and iterative testing

---

## Tools & Technologies
- **Microcontroller:** Arduino
- **Mechanical Design:** SolidWorks
- **Simulation:** Proteus, TinkerCad
- **Programming:** Embedded C / Arduino
- **Hardware:** Hardware: Arduino board, IR sensors, ultrasonic sensor, DC motors with motor driver, LED, chassis, power supply, jumper wires, breadboard.

Main Control Logic:
---

## My Role
- Mechanical design of the robot chassis
- Firmware implementation for navigation and obstacle avoidance
- System integration and testing during the hackathon

---

## System Operation

### Initialization & Calibration
At startup, the robot calibrates its IR sensors to determine appropriate threshold values. A status LED provides visual feedback during this phase.

### Autonomous Navigation
Motor speeds are dynamically adjusted based on sensor input to ensure smooth line tracking and accurate turns.

### Decision Making
Intersections and obstacles are handled in real time, enabling the robot to continue its path without manual intervention.

---

## Possible Enhancements
- Adaptive speed control based on path complexity
- Integration of additional sensors for better accuracy
