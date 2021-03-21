#ifndef W_AMBIENT_LIGHT
#define W_AMBIENT_LIGHT

#include "Arduino.h"

#include <Wire.h>
#include <BH1750.h>

class WAmbientLight
{
  public:

    WAmbientLight(int address = 0x23);
    ~WAmbientLight();

    void setup();
    void loop();
	
	uint16_t getValue();

  private:

    int address;
	
	BH1750 lightMeter;
  
};

#endif // W_AMBIENT_LIGHT
  
