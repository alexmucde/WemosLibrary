#ifndef W_RELAIS
#define W_RELAIS

#include "Arduino.h"

#include "WTimer.h"
  
class WRelais
{
  public:

    WRelais(int pin = D1);
    ~WRelais();

    void setup();
    void loop();

    void setOn(bool state);
    void trigger(unsigned long time);

  private:

    int pin;
    WTimer timer;
  
};

#endif
  
