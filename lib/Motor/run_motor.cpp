#include "run_motor.h"

// define the motor pots
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int speed = 100;
int turnspeed = 150;
const int TURN_90 = 800;
const int TURN_45 = 400;

void  moveForward()
{
          motor1.setSpeed(speed);
          motor2.setSpeed(speed);
          motor3.setSpeed(speed);
          motor4.setSpeed(speed);

          motor1.run(FORWARD);
          motor2.run(FORWARD);
          motor3.run(FORWARD);
          motor4.run(FORWARD);
}


void       moveBackward(int speedb)
{

          motor1.setSpeed(speedb);
          motor2.setSpeed(speedb);
          motor3.setSpeed(speedb);
          motor4.setSpeed(speedb);


          motor1.run(BACKWARD);
          motor2.run(BACKWARD);
          motor3.run(BACKWARD);
          motor4.run(BACKWARD);
}

// TURN SPEED
void turnSpeed()
{
          motor1.setSpeed(turnspeed);
          motor2.setSpeed(turnspeed);
          motor3.setSpeed(turnspeed);
          motor4.setSpeed(turnspeed);
}
// Turn functions

void turn0()   // 90 degrees Left
{
          turnSpeed();

          motor1.run(BACKWARD);
          motor2.run(BACKWARD);
          motor3.run(FORWARD);
          motor4.run(FORWARD);
          delay(TURN_90);
          stop();
}


void turn45()  // 45 degrees Left
{
          turnSpeed();

          motor1.run(BACKWARD);
          motor2.run(BACKWARD);
          motor3.run(FORWARD);
          motor4.run(FORWARD);
          delay(TURN_45);
          stop();
}


void turn90()  // Forward/Center (Special case)
{
          stop();
}
void turn135() // 45 degrees Right
{
          turnSpeed();

          motor1.run(FORWARD);
          motor2.run(FORWARD);
          motor3.run(BACKWARD);
          motor4.run(BACKWARD);
          delay(TURN_45);
          stop();
}
void turn180() // 90 degrees Right
{
          turnSpeed();

          motor1.run(FORWARD);
          motor2.run(FORWARD);
          motor3.run(BACKWARD);
          motor4.run(BACKWARD);
          delay(TURN_90);
          stop();
}
void     stop()
{                  
          motor1.run(RELEASE);
          motor2.run(RELEASE);
          motor3.run(RELEASE);
          motor4.run(RELEASE);
}