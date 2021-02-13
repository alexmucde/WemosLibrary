#ifndef W_BUZZER
#define W_BUZZER

#include "Arduino.h"

#include "WTimer.h"

class WBuzzer
{
	public:
		WBuzzer(int pin = D5);
		~WBuzzer();
	
		void setup();
		void loop();
		
		void tone(unsigned int frequency,unsigned long duration);
		void play(const char *notes,const int *beats);
				
	private:
		int pin;
		WTimer timer;
		const char *notes;
		const int *beats;
		int pos;
		
		void playTone();
		int frequency(char note);

};

#endif W_BUZZER