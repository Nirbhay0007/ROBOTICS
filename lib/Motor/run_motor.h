#ifndef RUN_MOTOR_H
#define RUN_MOTOR_H


#include <AFMotor.h>
#include <Arduino.h>

// "extern" tells the compiler these are defined in another file
extern AF_DCMotor motor1;
extern AF_DCMotor motor2;
extern AF_DCMotor motor3;
extern AF_DCMotor motor4;


// Function declarations
void   moveForward();

void       moveBackward(int speedb);
void turn0();   // 90 degrees Left
void turn45();  // 45 degrees Left
void turn90();  // Forward/Center (Special case)
void turn135(); // 45 degrees Right
void turn180(); // 90 degrees Right
void     stop();
#endif

