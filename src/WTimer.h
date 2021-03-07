#ifndef W_TIMER
#define W_TIMER

#include "Arduino.h"

class WTimer
{
  public:
    WTimer();
    ~WTimer();

    enum TimerEvent { None, Expired };

    void setup();
    void loop();
    TimerEvent event();

    void start(unsigned long duration);
    void stop();

    bool running();
    bool isExpired() { return stateExpired; }

  private:

    unsigned long startTime;  // start time of timer
    unsigned long duration;   // the duration of a timer

    bool eventExpired;
    bool stateExpired;

};

#endif
