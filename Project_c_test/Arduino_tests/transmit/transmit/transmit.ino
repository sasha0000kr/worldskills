#include <OrbicraftBus.h>
 
/*
  * Объявим переменную msg как тип данных Message
  * Message - представляет собой структуру, описывающую идентификаторы передаваемого сообщения
*/
Message msg;
 
/*
  * Объявим переменную bus как тип данных OrbicraftBus 
  * OrbicraftBus - представляет собой класс, описывающий взаимодействие Arduino и шины конструктора Orbicraft
*/
OrbicraftBus bus;
 
// Объявим переменную msgSize, в которую будет записываться передаваемое сообщение
int16_t msgSize = 0;
// Объявим номер пина для считывания показаний
int data_pin = A0; // Указываем пин, с которого будем считывать показания датчика
 
void setup() {
  Serial1.begin(9600); // задаем скорость обмена информацией по Serial2 (протестируйте скорость 115200 для новых конструкторов 2020г.в.)
}
 
void loop() {
 
  msgSize = bus.takeMessage(msg); // пробуем прочитать сообщение с помощью метода takeMessage
 
  if (msgSize > 0){ //если сообщение есть
    switch (msg.id){//в зависимости от идентификатора сообщения выполняем те или иные действия
 
      // Рассмотрим случай с идентификатором 2
        case 0x02:{
        String data = String(Sensor_data()); // записываем показания, полученные от функции Sensor_data() в переменную data
        bus.sendMessage(bus.obcAddress, 0, data); // передаем содержимое переменной data на БКУ
        break;
      }
    }
  }
}
 
uint16_t Sensor_data(void){
  uint16_t data = analogRead(data_pin); //Считываем показания освещенности с датчика
  return data;
}
 
/*
 * Следующий блок кода необходимо всегда добавлять в конец программы
 * Функция вызывается автоматически и необходима для обработки сообщения
*/ 
void serialEvent2() {
  bus.serialEventProcess();
}
