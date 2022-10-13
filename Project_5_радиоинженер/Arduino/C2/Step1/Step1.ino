#include <Servo.h>

Servo servo1;
Servo servo2;
#define SERVOTIME 100

#define E1 7
#define D1 8
#define S1 9

#define E2 10
#define D2 11
#define S2 12

#define STEPTIME 10
#define STEPS 100

void setup() {
  // put your setup code here, to run once:
  pinMode (E1, OUTPUT);
  pinMode (D1, OUTPUT);
  pinMode (S1, OUTPUT);
  pinMode (E2, OUTPUT);
  pinMode (D2, OUTPUT);
  pinMode (S2, OUTPUT);
  
  servo1.attach (4);
  servo2.attach (5);
  servo1.write (0);
  

  digitalWrite (E1, 1);

  digitalWrite (D1, 0);

  for (int i = 0; i < STEPS; i++) {
    digitalWrite (S1, 1);
    delay (STEPTIME);
    digitalWrite (S1, 0);
  }
analogWrite (E1, 200);

}

void loop() {
  // put your main code here, to run repeatedly:



}
