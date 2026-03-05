#include "front_sensor.h"

// Shield-compatible pins for the ultrasonic sensor
const int trigPin = A5; 
const int echoPin = A4;

int scan_angles[5] = {0, 45, 90, 135, 180};
int best_front = -1;

void check_front_obstacle() {

    int current_dist = Ultrsonic_trigger();


    if (current_dist < 30) {

        Serial.println("--- Front Obstacle Detected! Scanning... ---");

        front_servo_scan();

        Serial.print("Clear path found at angle: ");

        Serial.println(best_front);

    }

}

void front_servo_scan() {

    for (int i = 0; i < 5; i++) {

        frontServo.write(scan_angles[i]);

        delay(200); // Allow time for servo to reach position

        int measured_dist = Ultrsonic_trigger();

        // If distance is greater than 50cm, mark this as a clear path

        if (measured_dist > 50) {

            best_front = scan_angles[i];

        }

        delay(200);

    }

    // Return to center

    frontServo.write(90);

    delay(2000);

}

int Ultrsonic_trigger() {

    digitalWrite(trigPin, LOW);

    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);

    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

   

    long duration = pulseIn(echoPin, HIGH);

    // Speed of sound: 0.034 cm/us. Divide by 2 for round trip.

    int distance = duration * 0.034 / 2;

    return distance;

}