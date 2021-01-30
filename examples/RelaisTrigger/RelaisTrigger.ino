#include <WRelais.h>

WRelais relais;

void setup() {
  relais.setup();
  relais.trigger(500);
}

void loop() {
  relais.loop();
}
