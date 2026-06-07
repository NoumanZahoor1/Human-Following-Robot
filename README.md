<img width="1024" height="1536" alt="car1" src="https://github.com/user-attachments/assets/0c1fbb44-d8ce-4943-9361-ffa57147f266" />
<img width="1536" height="1024" alt="car" src="https://github.com/user-attachments/assets/e2ad9086-f536-4f81-aabf-ae6cfd367353" />

# Human-Following-Robot
This project demonstrates a human-following robot built using an Arduino UNO, ultrasonic sensor, infrared sensor, and motor driver module. The robot detects and follows a person by continuously measuring distance and direction using sensors mounted on a servo motor.
Components Used
Component	Description
Arduino UNO	Main microcontroller board controlling all operations
Ultrasonic Sensor (HC-SR04)	Detects distance to the target (human)
Infrared Sensor	Helps detect motion and proximity
Servo Motor	Rotates the ultrasonic sensor to scan surroundings
Motor Driver Module (L298N)	Controls the DC motors based on Arduino signals
DC Motors & Wheels	Provide movement and steering
Battery Pack	Powers the entire system

Refer to the circuit diagram below for wiring details between the Arduino, sensors, and motor driver.

🧠 Working Principle
Distance Measurement — The ultrasonic sensor measures distance to the nearest object (human).

Servo Scanning — The servo rotates the sensor to find the direction of the person.

Decision Logic — Arduino processes sensor data and decides whether to move forward, stop, or turn.

Motor Control — The motor driver executes movement commands based on Arduino output.

🧩 Code Overview
The Arduino sketch includes:

Initialization of sensors and motors

Continuous distance measurement loop

Conditional movement logic (follow, stop, turn)

Servo angle scanning routine

You can upload the code using the Arduino IDE after connecting all components.

📸 Demonstration

The robot autonomously follows a person walking ahead, maintaining a safe distance using ultrasonic feedback.

🚀 Future Improvements
Add camera-based tracking using OpenCV

Implement Bluetooth control for manual override

Integrate PID control for smoother motion

🧾 License
This project is open-source under the MIT License. Feel free to modify and share.
