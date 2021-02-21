#ifndef W_RGB
#define W_RGB
  

#include <Adafruit_NeoPixel.h>
#include "Arduino.h"

#include "WTimer.h"
#include "WColor.h"
#include "WColorArray.h"
  
class WRgb
{
  public:

    WRgb(int pixel = 1,int pin = D2);
    ~WRgb();

    void setup();
    void loop();    

    void setOn(bool state);
    void setColor(unsigned char r, unsigned char g, unsigned char b);
    void setColor(const WColor &color);
    void setColorArray(const WColorArray &colors);
    void setBlink(unsigned long blinkTime);

	void on() { setOn(true); }
	void on(unsigned long offTime) { offTimer.start(offTime);setOn(true); }
	void off() { setOn(false); }
	bool isOn() { return state; }   
	
  private:

    Adafruit_NeoPixel leds;
    int pin;
	int pixel;
    bool state;
    unsigned char r,g,b;
    bool lastState;
    unsigned long blinkTime;
    WTimer blinkTimer;
	WTimer offTimer;
  
};

#endif
