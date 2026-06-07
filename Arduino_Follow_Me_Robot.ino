/* * Arduino Human Following Robot
 * Modified & Fixed Code
 * Author: Nouman Zahoor
 * Base code structure by DIY Builder (v1.1)
 */

#include <NewPing.h>           
#include <Servo.h>             
#include <AFMotor.h>           

// Pin Configurations
#define RIGHT A2              // Right IR sensor 
#define LEFT A3               // Left IR sensor  
#define TRIGGER_PIN A1        // Ultrasonic Trigger Pin
#define ECHO_PIN A0           // Ultrasonic Echo Pin
#define MAX_DISTANCE 200      // Maximum ping distance (cm)

// Variables
unsigned int distance = 0;    
unsigned int Right_Value = 0; 
unsigned int Left_Value = 0;  

// Component Initialization
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

AF_DCMotor Motor1(1, MOTOR12_1KHZ);
AF_DCMotor Motor2(2, MOTOR12_1KHZ);
AF_DCMotor Motor3(3, MOTOR34_1KHZ);
AF_DCMotor Motor4(4, MOTOR34_1KHZ);

Servo myservo; 
int pos = 0;     

void setup() { 
  Serial.begin(9600); 
  
  myservo.attach(10); // Servo attached to pin 10 of Adafruit Motor Shield
  
  // Startup Diagnostic Servo Sweep
  for(pos = 90; pos <= 180; pos += 1) { 
    myservo.write(pos);                 
    delay(15);                          
  } 
  for(pos = 180; pos >= 0; pos -= 1) {     
    myservo.write(pos);                 
    delay(15);                          
  }
  for(pos = 0; pos <= 90; pos += 1) {       
    myservo.write(pos);                 
    delay(15);                          
  }

  pinMode(RIGHT, INPUT); 
  pinMode(LEFT, INPUT);  
  
  // Set default initial operational speeds 
  Motor1.setSpeed(130);
  Motor2.setSpeed(130);
  Motor3.setSpeed(130);
  Motor4.setSpeed(130);
}

void loop() {     
  delay(50); // Small delay between pings for sensor stability
  
  unsigned int raw_distance = sonar.ping_cm();
  
  // Catch NewPing out-of-range/error value (0) and set to max distance
  if (raw_distance == 0) {
    distance = MAX_DISTANCE;
  } else {
    distance = raw_distance;
  }
  
  // Read IR Sensors
  Right_Value = digitalRead(RIGHT);             
  Left_Value = digitalRead(LEFT);                

  // Debugging outputs to Serial Monitor
  Serial.print("Distance: "); Serial.print(distance); Serial.print("cm | ");
  Serial.print("RIGHT IR: "); Serial.print(Right_Value); Serial.print(" | ");
  Serial.print("LEFT IR: "); Serial.println(Left_Value);

  // Target Tracking Logic
  if ((distance > 1) && (distance < 15)) {  
    // Target is directly in front and close -> Move Forward
    Motor1.setSpeed(130);  
    Motor1.run(FORWARD);   
    Motor2.setSpeed(130);  
    Motor2.run(FORWARD);   
    Motor3.setSpeed(130);  
    Motor3.run(FORWARD);   
    Motor4.setSpeed(130);  
    Motor4.run(FORWARD);   
    
  } else if ((Right_Value == 0) && (Left_Value == 1)) {
    // Target lost on right, found on left -> Turn Left
    Motor1.setSpeed(150);  
    Motor1.run(FORWARD);   
    Motor2.setSpeed(150);  
    Motor2.run(FORWARD);   
    Motor3.setSpeed(150);  
    Motor3.run(BACKWARD);  
    Motor4.setSpeed(150);  
    Motor4.run(BACKWARD);  
    delay(150);
    
  } else if ((Right_Value == 1) && (Left_Value == 0)) {
    // Target lost on left, found on right -> Turn Right
    Motor1.setSpeed(150);  
    Motor1.run(BACKWARD);  
    Motor2.setSpeed(150);  
    Motor2.run(BACKWARD);  
    Motor3.setSpeed(150);  
    Motor3.run(FORWARD);   
    Motor4.setSpeed(150);  
    Motor4.run(FORWARD);   
    delay(150);
    
  } else if (distance > 15) {
    // Target out of range -> Stop safely
    Motor1.run(RELEASE);   
    Motor2.run(RELEASE);   
    Motor3.run(RELEASE);   
    Motor4.run(RELEASE);   
  }
}