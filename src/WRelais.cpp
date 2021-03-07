#include "WRelais.h"
  
WRelais::WRelais(int pin)
{
  this->pin = pin;
  this->state = false;
}

WRelais::~WRelais()
{
  
}

void WRelais::setup()
{
  pinMode(pin,OUTPUT);  
  digitalWrite(pin,LOW);
}

void WRelais::loop()
{
  switch(timer.event())
  {
    case WTimer::Expired:
      digitalWrite(pin,LOW);
      break;      
  }

}

void WRelais::setOn(bool state)
{
  if(state == true)
  {
    digitalWrite(pin,HIGH);
	this->state = true;
  }
  else
  {
    digitalWrite(pin,LOW);    
	this->state = false;
  }
}

void WRelais::trigger(unsigned long time)
{
  digitalWrite(pin,HIGH);
  timer.start(time);
}

void WRelais::toggle()
{
	if(state == true)
	{
		setOn(false);
	}
	else 
	{
		setOn(true);
	}
}


  
