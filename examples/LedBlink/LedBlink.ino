#include <WLed.h>

WLed led;

void setup() {
  led.setup();
  led.on();
  led.setBlink(500);
}

void loop() {
  led.loop();
}
