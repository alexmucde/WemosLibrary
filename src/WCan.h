#ifndef W_CAN
#define W_CAN

#include <Arduino.h>
#include <mcp_can.h>
#include <SPI.h>

class WCan
{
	public:
		WCan(byte baudrate = CAN_500KBPS,byte clock = MCP_8MHZ, int pinCs = D8,int pinInt = D2);
		~WCan();
	
        enum CanEvent { None, Received };
	
		bool setup();
		CanEvent event();
		
		bool send(INT32U id, byte *data,const byte size = 8);
		
		INT32U getId() { return id; }
		byte* getData() { return data; }
		byte getLength() { return length; }
		
	private:
		int pinCs;
		int pinInt;
		byte baudrate;
		byte clock;
		
		MCP_CAN can;

		byte data[8];		
		INT32U id;
		byte length;
};

#endif W_CAN