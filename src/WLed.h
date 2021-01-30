#ifndef W_LED
#define W_LED

#include "Arduino.h"

#include "WTimer.h"
  
class WLed
{
  public:

    WLed(int pin = BUILTIN_LED);
    ~WLed();

    enum LedEvent { None };

    void setup();
    void loop();
    
    void setOn(bool state);
	void on() { setOn(true); }
	void off() { setOn(false); }
	bool isOn() { return state; }
    
	void setBlink(unsigned long blinkTime);

  private:

    int pin;
    bool state;
    bool lastState;
    unsigned long blinkTime;
    WTimer timer;
  
};

#endif
