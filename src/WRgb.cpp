#include "WRgb.h"

WRgb::WRgb(int pixel,int pin)
 : leds(pixel, pin, NEO_GRB + NEO_KHZ800)
{
  this->pin = pin;
  this->pixel = pixel;
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

  for(int i = 0;i<pixel;i++)
	leds.setPixelColor(i, leds.Color(0, 0, 0));
  leds.show();    
}

void WRgb::loop()
{
  switch(blinkTimer.event())
  {
    case WTimer::Expired:
      if(state == true)
      {
        if(lastState== false)
        {
		  for(int i = 0;i<pixel;i++)
		    leds.setPixelColor(i, leds.Color(r, g, b));
          leds.show();    
          lastState = true;
        }
        else
        {
		  for(int i = 0;i<pixel;i++)
		    leds.setPixelColor(i, leds.Color(0, 0, 0));    
          leds.show();    
          lastState = false;
        }
      }
      blinkTimer.start(blinkTime);
      break;      
  }  
  switch(offTimer.event())
  {
    case WTimer::Expired:
      off();
      break;      
  }  
}

void WRgb::setOn(bool state)
{
  if(state == true)
  {
	for(int i = 0;i<pixel;i++)
	  leds.setPixelColor(i, leds.Color(r, g, b));
    this->state = true;
    lastState = true;
  }
  else
  {
	for(int i = 0;i<pixel;i++)
	  leds.setPixelColor(i, leds.Color(0, 0, 0));
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
	for(int i = 0;i<pixel;i++)
		leds.setPixelColor(i, leds.Color(r, g, b));
    leds.show();      
  }
}

void WRgb::setColor(const WColor &color)
{
  this->r = color.r;
  this->g = color.g;
  this->b = color.b;

  if(state)
  {
	for(int i = 0;i<pixel;i++)
		leds.setPixelColor(i, leds.Color(r, g, b));
    leds.show();      
  }	
}


void WRgb::setBlink(unsigned long blinkTime)
{
  this->blinkTime = blinkTime;
  blinkTimer.start(blinkTime);
}
