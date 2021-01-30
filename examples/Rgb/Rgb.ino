#include <WRgb.h>

WRgb rgb;

void setup() {
  rgb.setup();
}

void loop() {
  rgb.loop();
  
  rgb.setColor(0xff,0xff,0xfff);
  rgb.on();
  delay(500);

  rgb.setColor(0xff,0,0);
  delay(500);
  rgb.setColor(0,0xff,0);
  delay(500);
  rgb.setColor(0,0,0xff);
  delay(500);

  rgb.off();
  delay(500);
  
}
