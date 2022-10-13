#include <Servo.h>
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

Servo servo1;
Servo servo2;
#define SERVOTIME 500
#define SERVOSTEP 1

#define SUN1 A0
#define SUN2 A1
#define SUNMAX 650

int grad = 0;

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
  mySwitch.enableTransmit(2);

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
  digitalWrite (E1, 0);

}

void loop() {
  // put your main code here, to run repeatedly:
  servo1.write (0);
  while (analogRead (SUN1) > SUNMAX) {
    mySwitch.send(analogRead (SUN1), 24);
  }
  delay (SERVOTIME);
  servo1.write (45);
  while (analogRead (SUN1) > SUNMAX) {
    mySwitch.send(analogRead (SUN1), 24);
  }
  delay (SERVOTIME);
  servo1.write (90);
  while (analogRead (SUN1) > SUNMAX) {
    mySwitch.send(analogRead (SUN1), 24);
  }
  delay (SERVOTIME);
  servo1.write (135);
  while (analogRead (SUN1) > SUNMAX) {
    mySwitch.send(analogRead (SUN1), 24);
  }
  delay (SERVOTIME);
  servo1.write (180);
  while (analogRead (SUN1) > SUNMAX) {
    mySwitch.send(analogRead (SUN1), 24);
  }
  delay (SERVOTIME);
  servo1.write (135);
  while (analogRead (SUN1) > SUNMAX) {
    mySwitch.send(analogRead (SUN1), 24);
  }
  delay (SERVOTIME);
  servo1.write (90);
  while (analogRead (SUN1) > SUNMAX) {
    mySwitch.send(analogRead (SUN1), 24);
  }
  delay (SERVOTIME);
  servo1.write (45);
  while (analogRead (SUN1) > SUNMAX) {
    mySwitch.send(analogRead (SUN1), 24);
  }
  delay (SERVOTIME);
  servo1.write (0);
  while (analogRead (SUN1) > SUNMAX) {
    mySwitch.send(analogRead (SUN1), 24);
  }
}
