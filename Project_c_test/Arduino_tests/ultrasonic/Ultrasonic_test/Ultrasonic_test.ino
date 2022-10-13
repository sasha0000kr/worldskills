#include <OrbicraftBus.h>
#include <Ultrasonic.h>
 
 * Module HR-SC04 (four pins)
 * ---------------------
 * | HC-SC04 | Arduino |
 * ---------------------
 * |   Vcc   |   5V    |
 * |   Trig  |   6     |
 * |   Echo  |   7     |
 * |   Gnd   |   GND   |
 * ---------------------
 
Message msg;
OrbicraftBus bus;
Ultrasonic ultrasonic(6, 7);  // подключаем  HC-SR04 к пинам 6 (Trig) и 7 (Echo)
int distance;
int16_t msgSize = 0;
 
void setup() {
  Serial1.begin(9600); // задаем скорость обмена информацией по Serial1   !!!
}
 
void loop() {
  distance = ultrasonic.read();  // считываем расстояние
  msgSize = bus.takeMessage(msg); // пробуем прочитать сообщение с помощью метода takeMessage
 
  if (msgSize > 0){ //если сообщение есть
    switch (msg.id){//в зависимости от идентификатора сообщения выполняем те или иные действия
 
      // Рассмотрим случай с идентификатором 2
        case 0x02:{
        String data = String(distance); // записываем показания датчика расстояния в переменную data
        bus.sendMessage(bus.obcAddress, 0, data); // передаем содержимое переменной data на БКУ
        break;
      }
    }
  }
}
// Следующий блок кода необходимо всегда добавлять в конец программы
// Функция вызывается автоматически и необходима для обработки сообщения
void serialEvent2() {
  bus.serialEventProcess();
}
