#ifndef W_SERIAL
#define W_SERIAL

#include "Arduino.h"

class WSerial
{
	public:

		WSerial();
		~WSerial();

		enum SerialEvent { None, Line };
	
		void setup();
		void loop() { event(); }
		SerialEvent event();
		
		String line();
		
	private:
	
	    String receivedLine;
	
};

#endif /* W_SERIAL */
