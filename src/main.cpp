#include <Arduino.h>
#include <Servo.h>
// #include "front_sensor.h"
// #include "back_obstacle.h"
// #include "emergency_stop.h"

Servo frontServo;
Servo backServo;
// Servo backServo; // Uncomment if needed

void setup() {
    Serial.begin(9600);
    
    // Attach servo to SER1 (Pin 9)
    frontServo.attach(10); 
    frontServo.write(90);

    backServo.attach(9);
    backServo.write(90);

    // Initialize Sensor Pins
    pinMode(A5, OUTPUT); // Trig
    pinMode(A4, INPUT);  // Echo

    
    Serial.println("Robot Ready: Obstacle Avoidance Active");
}

void loop() {
    // Continuously check for obstacles
    // Serial.println(emergency_break());
    
    // Serial.println(back_obstacle_avoid());
    // check_front_obstacle();
    // // Optional: Print live distance every 500ms
    // // Serial.print("Current: ");
    // // Serial.println(Ultrsonic_trigger());
    
    
    delay(200);
}