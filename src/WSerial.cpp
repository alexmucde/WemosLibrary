#include "WSerial.h"

WSerial::WSerial()
{
	connected = false;
}

WSerial::~WSerial()
{
	
}

	
void WSerial::setup()
{
	Serial.begin(115200);
}

WSerial::SerialEvent WSerial::event()
{
	if(connected == false && Serial)
	{
		connected = true;
		return WSerial::Connected;
	}
	else if(connected == true && !Serial)
	{
		connected = false;
		return WSerial::Disconnected;
	}
			
	if (Serial.available() > 0)
	{
		char data = Serial.read();
		
		if(data == '\r') 
		{
			return WSerial::None;
		}
		if(data == '\n') 
		{
			return WSerial::Line;
		}
		
		receivedLine += data;
	}
	
	return WSerial::None;
}

String WSerial::line()
{
	String back;
	
	back = receivedLine;
	
	receivedLine = "";
	
	return back;
}
