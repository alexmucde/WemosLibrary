#include <WCan.h>
#include <WDlt.h>

WCan can;
WDlt dlt;

char msgString[128];                        

void setup() {
  dlt.setup();
  
  if(can.setup()==true)
     dlt.send("Initializing MCP2515 ok");  
  else
     dlt.send("Error Initializing MCP2515 failed");
}

void loop() 
{ 
  switch(can.event())
  {
    case WCan::Received:
           
      if((can.getId() & 0x40000000) == 0x40000000){    // Determine if message is a remote request frame.
        dlt.send("REMOTE REQUEST FRAME");
      } else {
        INT32U id = can.getId();
        dlt.send((byte*)&id,4,can.getData(),can.getLength());
      }

      break;
  }
}