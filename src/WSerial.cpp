#include "WSerial.h"

WSerial::WSerial(Mode mode)
{
	connected = false;
	this->mode = mode;
	length = 0;
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
		if(mode == Ascii)
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
		else
		{
			unsigned char data = Serial.read();
			if(length<SERIAL_MAX_LENGTH)
			{
				this->data[length]=data;
				length++;
			}
     		return WSerial::Data;
		}
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

unsigned char* WSerial::getData(int &length)
{
	length = this->length;
	return data;
}

void WSerial::clearData(int length)
{
	if(length==-1)
	{
		this->length = 0;
	}
	else
	{
		if(length>this->length)
		{
			this->length = 0;
		}
		else
		{
			memcpy(data,data+length,this->length-length);
			this->length=this->length-length;
		}
	}	
}