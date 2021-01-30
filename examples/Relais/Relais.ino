#include <WRelais.h>

WRelais relais;

void setup() {
  relais.setup();
}

void loop() {
  relais.on();
  delay(500);
  relais.off();
  delay(500);
  
}
