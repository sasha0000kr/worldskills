#define E 7
#define D 8
#define S 9

#define STEPS 200

#define STEPTIME 1
#define SLEEP 3000

#define SERVO1 4

#include <Servo.h>

Servo sun1;
Servo sun2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode (E, OUTPUT);
  pinMode (D, OUTPUT);
  pinMode (S, OUTPUT);

  sun1.attach (4);
  sun1.write (0);

  // Подаём питание на двигатель
  digitalWrite(E, 1);
}

void loop() {
  // put your main code here, to run repeatedly:


  // Задаём направление вращения по часовой стрелке
  digitalWrite(D, 0);

  // Делаем 50 шагов
  for (int i = 0; i < STEPS; ++i) {
    // Делаем шаг
    digitalWrite(S, HIGH);
    delay(STEPTIME);

    digitalWrite(S, LOW);
    delay(STEPTIME);

    sun1.write (i);
  }
}
