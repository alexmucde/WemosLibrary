#ifndef W_RGB
#define W_RGB
  

#include <Adafruit_NeoPixel.h>
#include "Arduino.h"

#include "WTimer.h"
  
class WRgb
{
  public:

    WRgb(int pin = D2);
    ~WRgb();

    void setup();
    void loop();    

    void setOn(bool state);
    void setColor(unsigned char r, unsigned char g, unsigned char b);
    void setBlink(unsigned long blinkTime);

	void on() { setOn(true); }
	void off() { setOn(false); }
	bool isOn() { return state; }   
	
  private:

    Adafruit_NeoPixel leds;
    int pin;
    bool state;
    unsigned char r,g,b;
    bool lastState;
    unsigned long blinkTime;
    WTimer timer;
  
};

#endif
