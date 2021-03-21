#include <WRgb.h>

WRgb rgb;		// single WS2812B RGB Leds
//WRgb rgb(7);	// seven WS2812B RGB Leds

void setup() {
  rgb.setup();
  rgb.setBlink(200);
  rgb.setColor(red);
  rgb.on();
}

void loop() {
  rgb.loop();
}
