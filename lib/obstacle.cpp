#include "obstacle.h"

// Define the pins and variables used only for this logic
const int irPin = 8;
int ir_values[5];
int angles[5] = {0, 45, 90, 135, 180};

int back_obstacle_avoid() {
    int high_angle = -1;
    int irValue = digitalRead(irPin);

    if (irValue == LOW) { // object detected
        for (int i = 0; i < 5; i++) {
            myservo.write(angles[i]);
            delay(500);
            ir_values[i] = digitalRead(irPin);
        }
        for (int i = 0; i < 5; i++) {
            if (ir_values[i] == HIGH && high_angle == -1) {
                high_angle = angles[i];
            }
        }
        myservo.write(90);
        delay(4000);
    }
    return high_angle;
}