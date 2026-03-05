#include "back_obstacle.h"

// Define the pins and variables used only for this logic
#define IR_PIN A2
int back_ir_values[5];
int back_angles[5] = {0, 45, 90, 135, 180};

int back_obstacle_avoid() {
    int high_angle = -1;
    int irValue = digitalRead(IR_PIN);

    if (irValue == LOW) { // object detected
        for (int i = 0; i < 5; i++) {
            backServo.write(back_angles[i]);
            delay(200);
            back_ir_values[i] = digitalRead(IR_PIN);
        }
        for (int i = 0; i < 5; i++) {
            if (back_ir_values[i] == HIGH && high_angle == -1) {
                high_angle = back_angles[i];
            }
        }
        backServo.write(90);
        delay(500);
    }
    return high_angle;
}