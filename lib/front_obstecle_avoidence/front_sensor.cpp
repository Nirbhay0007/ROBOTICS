#include "front_sensor.h"
#include "run_motor.h"

// Shield-compatible pins for the ultrasonic sensor
const int trigPin = A5; 
const int echoPin = A4;

int scan_angles[5] = {0, 45, 90, 135, 180};
int best_front = -1;

void check_front_obstacle() {

    int current_dist = Ultrsonic_trigger();


    if (current_dist < 30) {
        stop();
        moveBackward(250);
        delay(2000);
        front_servo_scan();
        delay(200);


        switch(best_front)
        
            {
        case 0: turn0();   break; // 90 Left
        case 45: turn45();  break; // 45 Left
        case 90: turn90();  break; // Straight (or skip)
        case 135: turn135(); break; // 45 Right
        case 180: turn180(); break; // 90 Right
    
        }

    }

}

void front_servo_scan() {

    for (int i = 0; i < 5; i++) {

        frontServo.write(scan_angles[i]);

        delay(200); // Allow time for servo to reach position

        int measured_dist = Ultrsonic_trigger();

        // If distance is greater than 50cm, mark this as a clear path

        if (measured_dist > 80) {

            best_front = scan_angles[i];

        }

        delay(200);

    }

    // Return to center

    frontServo.write(90);

    delay(200);

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