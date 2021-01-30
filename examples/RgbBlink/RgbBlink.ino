#include <WRgb.h>

WRgb rgb;

void setup() {
  rgb.setup();
  rgb.setBlink(200);
  rgb.setColor(0xff,0,0);
  rgb.on();
}

void loop() {
  rgb.loop();
}
