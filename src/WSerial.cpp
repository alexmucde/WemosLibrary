#include "WSerial.h"

WSerial::WSerial()
{
	
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
