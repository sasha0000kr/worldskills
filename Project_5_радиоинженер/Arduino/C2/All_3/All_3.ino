#include <OrbicraftBus.h> // подключаем библиотеку для работы с конструктором ОрбиКрафт
//Иниициализация доп систем
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

#define E1 5
#define D1 6
#define S1 7

#define E2 8
#define D2 9
#define S2 10

#define STEPTIME 10
#define STEPS 100

/*
    Объявим переменную msg как тип данных Message
    Message - представляет собой структуру, содержащую идентификаторы и данные передаваемого сообщения
*/
Message msg;

/*
    Объявим переменную bus как тип данных OrbicraftBus
    OrbicraftBus - представляет собой класс, описывающий взаимодействие Arduino и шины конструктора Orbicraft
*/
OrbicraftBus bus;

// Объявим переменную msgSize, в которую будет записываться размер принятого сообщения
uint16_t msgSize = 0;


void setup() {
  Serial2.begin(9600);
  mySwitch.enableTransmit(2);

  pinMode (E1, OUTPUT);
  pinMode (D1, OUTPUT);
  pinMode (S1, OUTPUT);
  pinMode (E2, OUTPUT);
  pinMode (D2, OUTPUT);
  pinMode (S2, OUTPUT);

  servo1.attach (4);
  servo1.write (0);

}


  void loop() {
    msgSize = bus.takeMessage(msg); // пробуем прочитать сообщение с помощью метода takeMessage
    if (msgSize > 0) { //если сообщение есть
      switch (msg.id) { //в зависимости от идентификатора сообщения выполняем те или иные действия

        // Рассмотрим случай с идентификатором 1
        case 0x01:
          code(); // Вызов функции для включения и выключения светодиода
          break;
      }
    }
  }

  void code (void) {

    digitalWrite (E1, 1);

    digitalWrite (D1, 0);

    for (int i = 0; i < STEPS; i++) {
      digitalWrite (S1, 1);
      delay (STEPTIME);
      digitalWrite (S1, 0);
    }
    digitalWrite (E1, 0);

    while (analogRead (SUN1) > SUNMAX) {
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
  }

  void serialEvent2() {
  bus.serialEventProcess();
}
