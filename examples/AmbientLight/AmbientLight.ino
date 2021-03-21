#include <WAmbientLight.h>

WAmbientLight ambientLight;

void setup() {
	Serial.begin(115200);
	
	ambientLight.setup();
}

void loop() {
	uint16_t value = ambientLight.getValue();

	Serial.print("Light: ");
	Serial.print(value);
	Serial.println(" lx");
	delay(1000);
  
}
