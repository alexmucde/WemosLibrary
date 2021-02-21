#include "WDlt.h"

WDlt::WDlt(unsigned int baudrate)
{
	this->baudrate = baudrate;
}

WDlt::~WDlt()
{
	
}

void WDlt::setup()
{
	Serial.begin(baudrate);
}

void WDlt::loop()
{
}

void WDlt::send(char *text)
{
	int length = strlen(text);
	
	// Serial Header
	Serial.write("DLS");
	Serial.write(0x01);

	// Standard Header (4 Byte)
	Serial.write(0x21); // htyp: Use extended header, version 0x1
	Serial.write(0x00); // message counter
	Serial.write(0x00); // length high byte
	Serial.write(4+10+4+2+length); // length low byte
	
	// Extended Header (10 Byte)
	Serial.write(0x41); // MSIN: Verbose,NW_TRACE, CAN 0x25
	Serial.write(0x01); // NOAR 
	Serial.write('C'); // APID
	Serial.write('A'); // APID
	Serial.write('N'); // APID
	Serial.write(0); // APID
	Serial.write('C'); // CTID
	Serial.write('A'); // CTID
	Serial.write('N'); // CTID
	Serial.write(0); // CTID
	
	// Payload Type Info (4 Byte)
	Serial.write(0x00); 
	Serial.write(0x02); // String
	Serial.write(0x00); 
	Serial.write(0x00); 
	
	// Payload Type Data Length
	Serial.write(length); // length low byte
	Serial.write(0x00); // length high byte 

	// Payload Type Data
	Serial.write(text,length);
}

void WDlt::send(byte *data, int length)
{
	// Serial Header
	Serial.write("DLS");
	Serial.write(0x01);

	// Standard Header (4 Byte)
	Serial.write(0x21); // htyp: Use extended header, version 0x1
	Serial.write(0x00); // message counter
	Serial.write(0x00); // length high byte
	Serial.write(4+10+4+2+length); // length low byte
	
	// Extended Header (10 Byte)
	Serial.write(0x25); // MSIN: Verbose,NW_TRACE, CAN 0x25
	Serial.write(0x01); // NOAR 
	Serial.write('C'); // APID
	Serial.write('A'); // APID
	Serial.write('N'); // APID
	Serial.write(0); // APID
	Serial.write('C'); // CTID
	Serial.write('A'); // CTID
	Serial.write('N'); // CTID
	Serial.write(0); // CTID
	
	// Payload Type Info (4 Byte)
	Serial.write(0x00); 
	Serial.write(0x04); // Raw Data
	Serial.write(0x00); 
	Serial.write(0x00); 
	
	// Payload Type Data Length
	Serial.write(length); // length low byte
	Serial.write(0x00); // length high byte 

	// Payload Type Data
	Serial.write(data,length);
		
}

void WDlt::send(byte *data1, int length1,byte *data2, int length2)
{
	// Serial Header
	Serial.write("DLS");
	Serial.write(0x01);

	// Standard Header (4 Byte)
	Serial.write(0x21); // htyp: Use extended header, version 0x1
	Serial.write(0x00); // message counter
	Serial.write(0x00); // length high byte
	Serial.write(4+10+4+2+length1+4+2+length2); // length low byte
	
	// Extended Header (10 Byte)
	Serial.write(0x25); // MSIN: Verbose,NW_TRACE, CAN
	Serial.write(0x02); // NOAR 
	Serial.write('C'); // APID
	Serial.write('A'); // APID
	Serial.write('N'); // APID
	Serial.write(0); // APID
	Serial.write('C'); // CTID
	Serial.write('A'); // CTID
	Serial.write('N'); // CTID
	Serial.write(0); // CTID
	
	// Payload Type Info (4 Byte)
	Serial.write(0x00); 
	Serial.write(0x04); 
	Serial.write(0x00); 
	Serial.write(0x00); 
	
	// Payload Type Data Length
	Serial.write(length1); // length low byte
	Serial.write(0x00); // length high byte 

	// Payload Type Data
	Serial.write(data1,length1);

	// Payload Type Info (4 Byte)
	Serial.write(0x00); 
	Serial.write(0x04); 
	Serial.write(0x00); 
	Serial.write(0x00); 
	
	// Payload Type Data Length
	Serial.write(length2); // length low byte
	Serial.write(0x00); // length high byte 

	// Payload Type Data
	Serial.write(data2,length2);
}

