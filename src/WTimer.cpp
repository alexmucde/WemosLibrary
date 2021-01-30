#include "WTimer.h"

WTimer::WTimer()
{
  startTime = 0;
  duration = 0;
  eventExpired = false;
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
      eventExpired = true;
      stateExpired = true;
      return WTimer::Expired;
    }
    else
    {
      eventExpired = false;
    }
  }  
  return WTimer::None;
}


void WTimer::start(unsigned long duration)
{
  startTime = millis();
  this->duration = duration;
  eventExpired = false;
  stateExpired = false;
}

void WTimer::stop()
{
  startTime = 0;
  duration = 0;
  eventExpired = false;
  stateExpired = false;
}
