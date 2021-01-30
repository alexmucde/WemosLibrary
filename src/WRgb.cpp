#include "WRgb.h"

WRgb::WRgb(int pin)
 : leds(1, pin, NEO_GRB + NEO_KHZ800)
{
  this->pin = pin;
  state = false;
  r = 0xff;
  g = 0xff;
  b = 0xff;
  lastState = false;
  blinkTime = 0;
}

WRgb::~WRgb()
{
  
}

void WRgb::setup()
{
  leds.begin();  

  leds.setPixelColor(0, leds.Color(0, 0, 0));
  leds.show();    
}

void WRgb::loop()
{
  switch(timer.event())
  {
    case WTimer::Expired:
      if(state == true)
      {
        if(lastState== false)
        {
          leds.setPixelColor(0, leds.Color(r, g, b));
          leds.show();    
          lastState = true;
        }
        else
        {
          leds.setPixelColor(0, leds.Color(0, 0, 0));    
          leds.show();    
          lastState = false;
        }
      }
      timer.start(blinkTime);
      break;      
  }  
}

void WRgb::setOn(bool state)
{
  if(state == true)
  {
    leds.setPixelColor(0, leds.Color(r, g, b));
    this->state = true;
    lastState = true;
  }
  else
  {
    leds.setPixelColor(0, leds.Color(0, 0, 0));
    this->state = false;
    lastState = false;
  }
  leds.show();    
}

void WRgb::setColor(unsigned char r, unsigned char g, unsigned char b)
{
  this->r = r;
  this->g = g;
  this->b = b;

  if(state)
  {
    leds.setPixelColor(0, leds.Color(r, g, b));
    leds.show();      
  }
}


void WRgb::setBlink(unsigned long blinkTime)
{
  this->blinkTime = blinkTime;
  timer.start(blinkTime);
}
