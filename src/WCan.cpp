#include "WCan.h"

WCan::WCan(byte baudrate, byte clock, int pinCs,int pinInt)
  : can(pinCs) 
{
	this->pinCs = pinCs;
	this->pinInt = pinInt;
	this->baudrate = baudrate;
	this->clock = clock;
	
	length = 0;
	id = 0;
}

WCan::~WCan()
{
}

bool WCan::setup()
{
	if(can.begin(MCP_ANY, baudrate, clock) != CAN_OK)
		return false;
		
	can.setMode(MCP_NORMAL);
	
	pinMode(pinInt, INPUT);
	
	return true;
}

WCan::CanEvent WCan::event()
{
	if(!digitalRead(pinInt))                         // If CAN0_INT pin is low, read receive buffer
	{
		can.readMsgBuf(&id, &length, data);
		
		return WCan::Received;
	}
	
    return WCan::None;
}

bool WCan::send(INT32U id, byte *data,byte size)
{
	byte sndStat = can.sendMsgBuf(id, 0, size, data);	
	
    if(sndStat == CAN_OK)
		return true;
	else
		return false;
	
}
