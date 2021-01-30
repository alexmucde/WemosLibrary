#include <WLed.h>

WLed led;

void setup() {
  led.setup();
}

void loop() {
  led.loop();
  
  led.on();
  delay(500);
  led.off();
  delay(500);
  
}