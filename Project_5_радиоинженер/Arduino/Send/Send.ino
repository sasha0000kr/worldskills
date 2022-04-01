#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int i = 0;
int val1 = 0;
int val2 = 0;

void setup() {

  Serial.begin(9600);
  mySwitch.enableTransmit(2);
  Serial.begin (9600);
  
}

void loop() {

  /* Same switch as above, but using decimal code */
  val1 = analogRead (A0);
  val2 = analogRead (A1);
  Serial.print ("Send data panel 1: ");
  mySwitch.setProtocol (1);
  mySwitch.send(val1, 24);
  Serial.print (val1);
  Serial.println(" OK");
  delay(250);  
  Serial.print ("Send data panel 2: ");
  mySwitch.setProtocol (2);
  mySwitch.send(val2, 24);
  Serial.print (val2);
  Serial.println(" OK");
  delay(500);  
}
