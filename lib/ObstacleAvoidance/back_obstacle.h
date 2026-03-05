#ifndef BACK_OBSTACLE_H
#define BACK_OBSTACLE_H

#include <Arduino.h>
#include <Servo.h>

// 1.Function Declaration

int back_obstacle_avoid();
// 2. Share the Servo object so both files can see it
extern Servo backServo; 

#endif