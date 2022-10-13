    // Troyka-Stepper подключён к следующим пинам:
    const byte stepPin = 9;
    const byte directionPin = 8;
    const byte enablePin = 7;
     
    // Выдержка для регулировки скорости вращения
    int delayTime = 5;
     
    void setup() {
      // Настраиваем нужные контакты на выход
      pinMode(stepPin, OUTPUT);
      pinMode(directionPin, OUTPUT);
      pinMode(enablePin, OUTPUT);
     
    }
     
    void loop() {
     
      // Подаём питание на двигатель
      digitalWrite(enablePin, HIGH);
     
      // Задаём направление вращения по часовой стрелке
      digitalWrite(directionPin, HIGH);
     
      // Делаем 50 шагов
      for (int i = 0; i < 150; ++i) {
        // Делаем шаг
        digitalWrite(stepPin, HIGH);
        delay(delayTime);
     
        digitalWrite(stepPin, LOW);
        delay(delayTime);
      }
     
      // Переходим в режим экономичного удержания двигателя...
      analogWrite(enablePin, 100);
      //... на три секунды
      delay(3000);
     
      // Меняем направление вращения
      digitalWrite(directionPin, LOW);
     
      // Включаем двигатель на полную мощность
      digitalWrite(enablePin, HIGH);
     
      // Делаем 50 шагов
      for (int i = 0; i < 50; ++i) {
        digitalWrite(stepPin, HIGH);
        delay(delayTime);
     
        digitalWrite(stepPin, LOW);
        delay(delayTime);
      }
     
      // Ничего не делаем без отключения двигателя
      delay(3000);
     
      // Отключаем двигатель
      digitalWrite(enablePin, LOW);
     
      // Ничего не делаем до перезагрузки
     
      while (true) {
        ;
      }
     
    }
