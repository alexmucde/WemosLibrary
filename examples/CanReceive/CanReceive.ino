#include <WCan.h>

WCan can;

char msgString[128];                        

void setup() {
  Serial.begin(115200);
  
  if(can.setup()==true)
     Serial.println("Initializing MCP2515 ok");  
  else
     Serial.println("Error Initializing MCP2515 failed");
}

void loop() 
{ 
  switch(can.event())
  {
    case WCan::Received:
           
      if((can.getId() & 0x80000000) == 0x80000000)     // Determine if ID is standard (11 bits) or extended (29 bits)
        sprintf(msgString, "Extended ID: 0x%.8lX  DLC: %1d  Data:", (can.getId() & 0x1FFFFFFF), can.getLength());
      else
        sprintf(msgString, "Standard ID: 0x%.3lX       DLC: %1d  Data:", can.getId(), can.getLength());
    
      Serial.print(msgString);
    
      if((can.getId() & 0x40000000) == 0x40000000){    // Determine if message is a remote request frame.
        sprintf(msgString, " REMOTE REQUEST FRAME");
        Serial.print(msgString);
      } else {
        for(byte i = 0; i<can.getLength(); i++){
          sprintf(msgString, " 0x%.2X", can.getData()[i]);
          Serial.print(msgString);
        }
      }
          
      Serial.println();

      break;
  }
}