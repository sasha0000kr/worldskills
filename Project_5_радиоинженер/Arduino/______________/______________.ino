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

#define E1 7
#define D1 8
#define S1 9

#define E2 10
#define D2 11
#define S2 12

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
  Serial2.begin(9600); // задаем скорость обмена информацией по Serial2 (протестируйте скорость 115200 для новых конструкторов 2020г.в.)
  mySwitch.enableTransmit(2); //Передатчик

  pinMode (E1, OUTPUT);
  pinMode (D1, OUTPUT);
  pinMode (S1, OUTPUT);
  pinMode (E2, OUTPUT);
  pinMode (D2, OUTPUT);
  pinMode (S2, OUTPUT);

  servo1.attach (4);
  servo2.attach (5);
  servo1.write (0);
  servo2.write (0);

  //расчиковка спутника
  digitalWrite (E1, 1);
  digitalWrite (E2, 1);
  digitalWrite (D1, 0);
  digitalWrite (D2, 0);

  for (int i = 0; i < STEPS; i++) {
    digitalWrite (S1, 1);
    digitalWrite (S2, 1);
    delay (STEPTIME);
    digitalWrite (S1, 0);
    digitalWrite (S2, 0);
  }
  analogWrite (E1, 100);
  analogWrite (E2, 100);



}

void loop() {
  msgSize = bus.takeMessage(msg); // пробуем прочитать сообщение с помощью метода takeMessage
  if (msgSize > 0) { //если сообщение есть
    switch (msg.id) { //в зависимости от идентификатора сообщения выполняем те или иные действия

      // Рассмотрим случай с идентификатором 1
      case 0x01:
        main(); // Вызов функции для включения и выключения светодиода
        break;
    }
  }
}

void main(void) {
  do {
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
  } while (analogRead (SUN1) > SUNMAX);

    do {
    servo2.write (0);
    while (analogRead (SUN2) > SUNMAX) {
      mySwitch.send(analogRead (SUN1), 24);
    }
    delay (SERVOTIME);
    servo2.write (45);
    while (analogRead (SUN2) > SUNMAX) {
      mySwitch.send(analogRead (SUN1), 24);
    }
    delay (SERVOTIME);
    servo2.write (90);
    while (analogRead (SUN2) > SUNMAX) {
      mySwitch.send(analogRead (SUN1), 24);
    }
    delay (SERVOTIME);
    servo2.write (135);
    while (analogRead (SUN2) > SUNMAX) {
      mySwitch.send(analogRead (SUN1), 24);
    }
    delay (SERVOTIME);
    servo2.write (180);
    while (analogRead (SUN2) > SUNMAX) {
      mySwitch.send(analogRead (SUN1), 24);
    }
    delay (SERVOTIME);
    servo2.write (135);
    while (analogRead (SUN2) > SUNMAX) {
      mySwitch.send(analogRead (SUN1), 24);
    }
    delay (SERVOTIME);
    servo2.write (90);
    while (analogRead (SUN2) > SUNMAX) {
      mySwitch.send(analogRead (SUN1), 24);
    }
    delay (SERVOTIME);
    servo2.write (45);
    while (analogRead (SUN2) > SUNMAX) {
      mySwitch.send(analogRead (SUN1), 24);
    }
    delay (SERVOTIME);
    servo2.write (0);
    while (analogRead (SUN2) > SUNMAX) {
      mySwitch.send(analogRead (SUN1), 24);
    }
  } while (analogRead (SUN2) > SUNMAX);
}

/*
   Следующий блок кода необходимо всегда добавлять в конец программы
   Функция вызывается автоматически и необходима для обработки сообщения
*/
void serialEvent2() {
  bus.serialEventProcess();
}
