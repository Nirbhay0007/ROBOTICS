#include "emergency_stop.h"
#include "run_motor.h"
#include "back_obstacle.h"

#define   EM_PIN  A0

void emergency_break()
{         
          

          int em_ir_value = digitalRead(EM_PIN);
          if(em_ir_value == LOW )
          {
                    
                    stop();
                    delay(500);
                    moveBackward(250);
                    delay(4000);

                    int choice_turn = random(0,5);
                    Serial.println(choice_turn);
                    switch (choice_turn) {
        case 1: turn0();   break; // 90 Left
        case 2: turn45();  break; // 45 Left
        case 3: turn90();  break; // Straight (or skip)
        case 4: turn135(); break; // 45 Right
        case 5: turn180(); break; // 90 Right

        delay(2000);
        }                    
          }


}