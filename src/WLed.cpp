#include "WLed.h"
  
WLed::WLed(int pin)
{
  this->pin = pin;
  state = false;
  lastState = false;
  blinkTime = 0;
}

WLed::~WLed()
{
  
}

void WLed::setup()
{
  pinMode(pin,OUTPUT);  
  digitalWrite(pin,HIGH);    
}

void WLed::loop()
{
  switch(timer.event())
  {
    case WTimer::Expired:
      if(state == true)
      {
        if(lastState== false)
        {
          digitalWrite(pin,LOW);
          lastState = true;
        }
        else
        {
          digitalWrite(pin,HIGH);    
          lastState = false;
        }
      }
      timer.start(blinkTime);
      break;      
  }
}

void WLed::setOn(bool state)
{
  if(state == true)
  {
    digitalWrite(pin,LOW);
    this->state = true;
    lastState = true;
  }
  else
  {
    digitalWrite(pin,HIGH);    
    this->state = false;
    lastState = false;
  }
}

void WLed::setBlink(unsigned long blinkTime)
{
  this->blinkTime = blinkTime;
  timer.start(blinkTime);
}
