#include <Arduino.h>
#include <Servo.h>
#include "obstacle.h" // Include your new library

Servo myservo; // Define the servo here

void setup() {
    myservo.attach(7);
    pinMode(8, INPUT); // Ensure IR pin is set to input
    myservo.write(90);
    Serial.begin(9600);
}

void loop() {
    int anglefollow = back_obstacle_avoid();
    
    if (anglefollow != -1) {
        Serial.print("Clear Path Found at: ");
        Serial.println(anglefollow);
    }
    delay(500);
}