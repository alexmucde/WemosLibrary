#ifndef W_RELAIS
#define W_RELAIS

#include "Arduino.h"

#include "WTimer.h"
  
class WRelais
{
  public:

    WRelais(int pin = D1);
    ~WRelais();

    void setup();
    void loop();

    void setOn(bool state);
    void trigger(unsigned long time);

	void on() { setOn(true); }
	void off() { setOn(false); }
	bool isOn() { return state; }    

  private:

    int pin;
    WTimer timer;
	int state;
  
};

#endif
  
