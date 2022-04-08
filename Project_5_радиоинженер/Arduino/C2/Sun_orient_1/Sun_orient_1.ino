#include <Servo.h>

Servo servo1;
Servo servo2;
#define SERVOTIME 500
#define SERVOSTEP 1

#define SUN1 A0
#define SUN2 A1
#define SUNMAX 650

int grad = 0;



void setup() {
  // put your setup code here, to run once:
  servo1.attach (4);
  servo2.attach (5);
  servo1.write (0);
  Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    servo1.write (0);
      while (analogRead (SUN1) > SUNMAX) {

  }
    delay (SERVOTIME);
    servo1.write (45);
      while (analogRead (SUN1) > SUNMAX) {

  }
    delay (SERVOTIME);
    servo1.write (90);
      while (analogRead (SUN1) > SUNMAX) {

  }
    delay (SERVOTIME);
    servo1.write (135);
      while (analogRead (SUN1) > SUNMAX) {

  }
    delay (SERVOTIME);
    servo1.write (180);
      while (analogRead (SUN1) > SUNMAX) {

  }
    delay (SERVOTIME);
    servo1.write (135);
      while (analogRead (SUN1) > SUNMAX) {

  }
    delay (SERVOTIME);
    servo1.write (90);
      while (analogRead (SUN1) > SUNMAX) {

  }
    delay (SERVOTIME);
    servo1.write (45);
      while (analogRead (SUN1) > SUNMAX) {

  }
    delay (SERVOTIME);
    servo1.write (0);
  while (analogRead (SUN1) > SUNMAX) {

  }
}
