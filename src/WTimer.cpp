#include "WTimer.h"

WTimer::WTimer()
{
  startTime = 0;
  duration = 0;
  stateExpired = false;
}

WTimer::~WTimer()
{
}

void WTimer::setup()
{
}

void WTimer::loop()
{
  event();
}

WTimer::TimerEvent WTimer::event()
{
  if(!duration)
    return WTimer::None;
  
  unsigned long currentTime = millis();

  if( (startTime + duration) <= currentTime)
  {
    if(!stateExpired)
    {
      stateExpired = true;
      return WTimer::Expired;
    }
    else
    {
    }
  }  
  return WTimer::None;
}


void WTimer::start(unsigned long duration)
{
  startTime = millis();
  this->duration = duration;
  stateExpired = false;
}

void WTimer::stop()
{
  startTime = 0;
  duration = 0;
  stateExpired = false;
}

bool WTimer::running()
{
	if(duration!=0)
	{
		if(stateExpired==true)
		{
			return false;
		}
		else
		{
			return true;
		}		
	}
	else
	{
		return false;
	}
}

