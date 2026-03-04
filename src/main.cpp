#include <Servo.h>
#include <Arduino.h>

Servo myservo;

bool done = false;
int angles[5]={0,45,90,135,180};
int ir_values[5];
int high[1] ;


int irPin = 8;      // IR sensor OUT connected to pin 8
int irValue = 0;    // variable to store IR value

void setup()
{
  myservo.attach(7);      // Servo signal connected to pin 7
  pinMode(irPin, INPUT);  
  myservo.write(90);    // Start at center
  Serial.begin(9600);
}

void loop()
{
  irValue = digitalRead(irPin);

  if(irValue == LOW)   // object detected
  {
    Serial.println("Object detected! Scanning...");

    for(int i = 0; i < 5; i++)
    {
      myservo.write(angles[i]);
      delay(500);

      ir_values[i] = digitalRead(irPin);

      Serial.print("Angle: ");
      Serial.print(angles[i]);
      Serial.print("  IR: ");
      Serial.println(ir_values[i]);
    }

    Serial.println("Angles with NO object detected:");

    for(int i = 0; i < 5; i++)
    {
      if(ir_values[i] == HIGH)
      { 
        high[0]=angles[i];
        Serial.print("no Object at angle: ");
        Serial.println(angles[i]);
      }
    }

    myservo.write(90);
    Serial.println("---------------------------");
    Serial.println("conclusion of search : ");
    Serial.print(high[0]);

  }
  delay(4000);

}

