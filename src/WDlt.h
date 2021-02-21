#ifndef W_DLT
#define W_DLT

#include "Arduino.h"

class WDlt
{
	public:
		WDlt(unsigned int baudrate = 115200);
		~WDlt();
	
		void setup();
		void loop();
		
		void send(char *text);
		void send(byte *data, int length);
		void send(byte *data1, int length1,byte *data2, int length2);
		
	private:
		unsigned int baudrate;

};

#endif W_DLT