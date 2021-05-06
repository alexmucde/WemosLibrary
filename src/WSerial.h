#ifndef W_SERIAL
#define W_SERIAL

#include "Arduino.h"

#define SERIAL_MAX_LENGTH 256

class WSerial
{
	public:

		enum SerialEvent { None, Line, Data, Connected, Disconnected };
		enum Mode { Ascii, Binary };

		WSerial(Mode mode = Ascii);
		~WSerial();

		void setup();
		void loop() { event(); }
		SerialEvent event();
		
		String line();
		
		unsigned char* getData(int &length);
		void clearData(int length = -1); // remove data from beginning, length=-1 remove all data
		
	private:
	
	    String receivedLine;
		
		bool connected;
		
		Mode mode;
		
		unsigned char data[SERIAL_MAX_LENGTH];
		int length;
	
};

#endif /* W_SERIAL */
