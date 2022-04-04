#define clock 7

#include <Servo.h>
int suniter = 0;


Servo sun1;



void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  sun1.attach(4);
  sun1.write (0);
}

void loop() {

  
  // put your main code here, to run repeatedly:
while (suniter < 90) {
  sun1.write (suniter);
  suniter = suniter + 1;
  Serial.println (suniter);
}
while (suniter > 90) {
  sun1.write (suniter);
  suniter = suniter - 1;
  Serial.println (suniter);
}
if (suniter == 90) {
suniter = 0;
sun1.write (suniter);
  
}
delay (clock);
}
