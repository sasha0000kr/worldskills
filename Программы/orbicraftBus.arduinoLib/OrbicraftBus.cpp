#include "OrbicraftBus.h"

OrbicraftBus::OrbicraftBus(const uint8_t arduinoNum){
  uartBufferIndex = 0;
  Serial2.begin(uartBaudRate);
  pinMode(directionPin, OUTPUT);
  digitalWrite(directionPin, LOW);
  if (arduinoNum < 16){
    ownAddress = baseArduinoAddress + arduinoNum;
  }
  
   newMsgGet = false;
}


uint8_t OrbicraftBus::getArduinoNum(void){
  return ownAddress - baseArduinoAddress;
}

void OrbicraftBus::setArduinoNum(const uint8_t arduinoNum){
  ownAddress = baseArduinoAddress + arduinoNum;
}
  
/**
 * \brief Функция обработки 
 * \return Ничего
 */
void OrbicraftBus::serialEventProcess() {
	while (Serial2.available() && !newMsgGet){
	  uint8_t newData = Serial2.read();
	  if (newData == 0){
		newMsgGet = true;
	  }
	  else{
		uartBuffer[uartBufferIndex++] = newData;
	  }
	}
}

/**
 * \brief Функция приёма сообщения
 * \param msg: буфер, для записи сообщения
 * \return Размер сообщения
 */
int16_t OrbicraftBus::takeMessage(Message &msg){
  cobs_decode_result res;
  uint16_t addressTo;

  uint16_t msgBufSize = 255;
  uint8_t msgBuf[msgBufSize];
  
  if (newMsgGet){
    res = cobs_decode(msgBuf, msgBufSize, uartBuffer, uartBufferIndex);
    uartBufferIndex = 0;
    newMsgGet = false;

    if ((res.status != COBS_DECODE_OK) || ((res.out_len + 1) < 8)){
      return -1;
    }
	
    addressTo = *(uint16_t*)(msgBuf + 2);

    if ((addressTo != ownAddress) && (addressTo != broadCastAddress)){
      return 0;
    }
    else{
		msgBuf[res.out_len] = 0;
		
		msg.from = *(uint16_t*)(msgBuf + 4);
		msg.to = addressTo;
		msg.id = *(uint16_t*)(msgBuf + 6);
		msg.data.remove(0);
		msg.data = String((char*)(msgBuf + 8));
		
		return res.out_len;
    }
  }
  else{
    return 0;
  }
}

/**
 * \brief Функция отправки сообщения
 * \param address: адрес получателя
 * \param msgId: идентификатор сообщения
 * \param args: строка аргументов
 * \return Размер переданного сообщения
 */
int16_t OrbicraftBus::sendMessage(const uint16_t address, const uint16_t msgId, const String args){
  uint8_t outMsgBuffer[255];
  uint8_t outCobsMsgBuffer[255];
  cobs_encode_result res;
  uint16_t args_len = 0;

  outMsgBuffer[0] = msgId & 0xFF;
  outMsgBuffer[1] = (msgId >> 8) & 0xFF;
  outMsgBuffer[2] = address & 0xFF;
  outMsgBuffer[3] = (address >> 8) & 0xFF;
  outMsgBuffer[4] = ownAddress & 0xFF;
  outMsgBuffer[5] = (ownAddress >> 8) & 0xFF;
  outMsgBuffer[6] = msgId & 0xFF;
  outMsgBuffer[7] = (msgId >> 8) & 0xFF;
  
  args_len = args.length();
  if (args_len > 0){
    strcpy(&outMsgBuffer[8], args.c_str());
  }

  res = cobs_encode(outCobsMsgBuffer, 255, outMsgBuffer, args_len + 8 + 1);
  if (res.status == COBS_ENCODE_OK){
    outCobsMsgBuffer[res.out_len++] = '\0';
    digitalWrite(directionPin, HIGH);
    delay(1);
    Serial2.write(outCobsMsgBuffer, res.out_len);
    Serial2.flush();
    digitalWrite(directionPin, LOW);
	return res.out_len;
  }
  else{
    return -1;
  }
}
