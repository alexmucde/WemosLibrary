#ifndef W_SERIAL
#define W_SERIAL

#include "Arduino.h"

class WSerial
{
	public:

		WSerial();
		~WSerial();

		enum SerialEvent { None, Line, Connected, Disconnected };
	
		void setup();
		void loop() { event(); }
		SerialEvent event();
		
		String line();
		
	private:
	
	    String receivedLine;
		
		bool connected;
	
};

#endif /* W_SERIAL */
