#include "back_obstacle.h"
#include "run_motor.h"
// Define the pins and variables used only for this logic
#define IR_PIN A2
int back_ir_values[5];
int back_angles[5] = {0, 45, 90, 135, 180};


void backCheck()
{
int irValue = digitalRead(IR_PIN);

if (irValue == LOW)

{  
    
    stop();
    delay(500);
    moveForward();
    delay(4000);
    int turn = back_obstacle_avoid();
    // Serial.println(turn);
    switch (turn) {
        case 0: turn0();   break; // 90 Left
        case 45: turn45();  break; // 45 Left
        case 90: turn90();  break; // Straight (or skip)
        case 135: turn135(); break; // 45 Right
        case 180: turn180(); break; // 90 Right
    }

}
}

int back_obstacle_avoid() {
    int high_angle = -1;
    

    

     // object detected
        for (int i = 0; i < 5; i++) {
            backServo.write(back_angles[i]);
            delay(200);
            back_ir_values[i] = digitalRead(IR_PIN);
        }
        for (int i = 0; i < 5; i++) {
            if (back_ir_values[i] == HIGH && high_angle == -1) {
                high_angle = back_angles[i];
                

            }
        
        backServo.write(90);
        delay(200);
    }
    
    return high_angle;

    
}