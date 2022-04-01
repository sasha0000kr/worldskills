#ifndef _ORBICRAFT_BUS_H
#define _ORBICRAFT_BUS_H

#include "Arduino.h"
#include "cobs.h"

typedef struct{
  uint16_t from;
  uint16_t to;
  uint16_t id;
  String data;
}Message;

class OrbicraftBus{

public:
  
  OrbicraftBus(const uint8_t arduinoNum = 0);
  int16_t takeMessage(Message &msg);
  int16_t sendMessage(const uint16_t address, const uint16_t id, const String data  = "");
  uint8_t getArduinoNum(void);
  void setArduinoNum(const uint8_t arduinoNum);
  
  void serialEventProcess(void);

  const uint16_t obcAddress = 0x0001;

  
private:

  boolean newMsgGet = false;
  uint8_t uartBuffer[255];
  uint8_t uartBufferIndex;

  uint8_t directionPin = 13;
  uint16_t ownAddress;
  
  const uint16_t baseArduinoAddress = 0x280;
  const uint16_t broadCastAddress = 0xffff;
  const uint32_t uartBaudRate = 115200;
  
};
#endif
