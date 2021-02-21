#include <WCan.h>

WCan can;

byte data[8] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};

void setup() {
  Serial.begin(115200);
  
  if(can.setup()==true)
     Serial.println("Initializing MCP2515 ok");  
  else
     Serial.println("Error Initializing MCP2515 failed");
}

void loop() {
  if(can.send(0x100,data)==true)
     Serial.println("Send succesful");  
  else
     Serial.println("Error sending message");

  delay(500);
}