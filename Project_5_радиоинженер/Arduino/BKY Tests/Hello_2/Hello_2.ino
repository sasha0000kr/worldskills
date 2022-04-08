    #include <OrbicraftBus.h> // подключаем библиотеку для работы с конструктором ОрбиКрафт
     #include <Servo.h>

Servo servo1;
Servo servo2;
#define SERVOTIME 500
#define SERVOSTEP 1

#define SUN1 A0
#define SUN2 A1
#define SUNMAX 650

int grad = 0;
    /*
      * Объявим переменную msg как тип данных Message
      * Message - представляет собой структуру, содержащую идентификаторы и данные передаваемого сообщения
    */
    Message msg;
     
    /*
      * Объявим переменную bus как тип данных OrbicraftBus 
      * OrbicraftBus - представляет собой класс, описывающий взаимодействие Arduino и шины конструктора Orbicraft
    */
    OrbicraftBus bus;
     
    // Объявим переменную msgSize, в которую будет записываться размер принятого сообщения
    uint16_t msgSize = 0;
     
    void setup() {
      Serial2.begin(9600); // задаем скорость обмена информацией по Serial2 (протестируйте скорость 115200 для новых конструкторов 2020г.в.)
    servo1.attach (4);
    }
     
    void loop() {
      msgSize = bus.takeMessage(msg); // пробуем прочитать сообщение с помощью метода takeMessage
      if (msgSize > 0){ //если сообщение есть
        switch (msg.id){//в зависимости от идентификатора сообщения выполняем те или иные действия
     
          // Рассмотрим случай с идентификатором 1
            case 0x01:
              turnOnLed(); // Вызов функции для включения и выключения светодиода
              break;
        }         
      }
    }
     
    void turnOnLed(void){
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
     
    /*
     * Следующий блок кода необходимо всегда добавлять в конец программы
     * Функция вызывается автоматически и необходима для обработки сообщения
    */ 
    void serialEvent2() {
      bus.serialEventProcess();
    }
