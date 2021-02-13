#include "WBuzzer.h"

WBuzzer::WBuzzer(int pin)
{
	this->pin = pin;
	pos = -1;
}

WBuzzer::~WBuzzer()
{
	
}

void WBuzzer::setup()
{
	pinMode(pin, OUTPUT);
}

void WBuzzer::loop()
{
	if(pos!=-1)
	{
		timer.loop();
		if(timer.isExpired())
		{
			playTone();
		}
	}
}

void WBuzzer::tone(unsigned int frequency,unsigned long duration)
{
	::tone(pin, frequency, duration);
}

void WBuzzer::play(const char *notes,const int *beats)
{
	this->notes = notes;
	this->beats = beats;
	
	pos = -1;
	playTone();
}

void WBuzzer::playTone()
{
	pos++;

    unsigned long duration = beats[pos] * 150;
 
    if (notes[pos] == 0) 
	{
		pos = -1;
	}
    else if (notes[pos] == ' ') 
    {
      timer.start(duration);  
    }
    else                 
    {
      tone(frequency(notes[pos]), duration);
	  timer.start(duration);
    }
	
}

int WBuzzer::frequency(char note) 
{
 
  int i;
  const int numNotes = 8;
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};
 
 
  for (i = 0; i < numNotes; i++) 
  {
    if (names[i] == note)
    {
      return(frequencies[i]);  
    }
  }
  return(0); 
}