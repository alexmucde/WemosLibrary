#include "WAmbientLight.h"
  
WAmbientLight::WAmbientLight(int address)
   : lightMeter(address)
{
  this->address = address;
}

WAmbientLight::~WAmbientLight()
{
  
}

void WAmbientLight::setup()
{
	Wire.begin();
	
	if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println(F("BH1750 Advanced begin"));
  }
  else {
    Serial.println(F("Error initialising BH1750"));
  }
}

void WAmbientLight::loop()
{
	
}

uint16_t WAmbientLight::getValue()
{
	return lightMeter.readLightLevel();
}
	
