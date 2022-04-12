#include <Servo.h>

#define SUNMAX 600

Servo myservo;  // create servo object to control a servo

void servo_setup (void) {
  // put your setup code here, to run once:
  myservo.attach (9);
  Serial.begin (9600);
  Serial.println ("Init");
  myservo.write (0);
}

void servo(void) {
  // put your main code here, to run repeatedly:

  while (analogRead (A0) <= SUNMAX) {
    myservo.writeMicroseconds (1500);
    Serial.println ("Servo ON");
  }
    while (analogRead (A0) > SUNMAX) {
    myservo.writeMicroseconds (0);
    Serial.println ("Servo off");
  }
}

void stop (void) {
  Serial.println ("Stop");
}
  
