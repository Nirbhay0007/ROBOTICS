#ifndef FRONT_SENSOR_H
#define FRONT_SENSOR_H

#include <Arduino.h>
#include <Servo.h>

// Share the servo and best angle variable across files
extern Servo frontServo;
extern int best_front;
          
// Function declarations
int Ultrsonic_trigger();
void front_servo_scan();
void check_front_obstacle();

#endif