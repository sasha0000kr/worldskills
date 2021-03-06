    #include <OrbicraftBus.h> // подключаем библиотеку для работы с конструктором ОрбиКрафт
     
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
      if (millis () == 5000) {
         turnOnLed();
      }
    }
     
    void turnOnLed(void){
      digitalWrite(LED_BUILTIN, HIGH); //Включаем встроенный светодиод
      delay(3000); //Ждем 3 секунды
      digitalWrite (LED_BUILTIN, LOW); //Выключаем встроенный светодиод
    }
     
    /*
     * Следующий блок кода необходимо всегда добавлять в конец программы
     * Функция вызывается автоматически и необходима для обработки сообщения
    */ 
    void serialEvent2() {
      bus.serialEventProcess();
    }
