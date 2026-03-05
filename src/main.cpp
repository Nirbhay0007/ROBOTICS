#include <Arduino.h>
#include <Servo.h>
#include <run_motor.h>


#include "front_sensor.h"
#include "back_obstacle.h"
#include "emergency_stop.h"

Servo frontServo;
Servo backServo;


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

    
}

void loop() {
emergency_break();
backCheck();
check_front_obstacle();
moveForward();
delay(200);
}
