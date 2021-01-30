#include <WButton.h>
#include <WLed.h>

WButton button;
WLed led;

void setup() {
  button.setup();
  led.setup();
}

void loop() {
  switch(button.event())
  {
    case WButton::Pressed:
      led.on();
      break;
    case WButton::Released:
      led.off();
      break;
  }
}
