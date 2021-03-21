#include <WRgb.h>

WRgb rgb;		// single WS2812B RGB Leds
//WRgb rgb(7);	// seven WS2812B RGB Leds

void setup() {
  rgb.setup();
}

void loop() {
  rgb.loop();
  
  rgb.setColor(white);
  rgb.on();
  delay(500);

  rgb.setColor(red);
  delay(500);
  rgb.setColor(green);
  delay(500);
  rgb.setColor(blue);
  delay(500);

  rgb.off();
  delay(500);
  
}