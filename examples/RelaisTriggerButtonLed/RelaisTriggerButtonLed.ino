#include <WButton.h>
#include <WLed.h>
#include <WRelais.h>

WButton button;
WLed led;
WRelais relais;

void setup()
{
  button.setup();
  led.setup();
  relais.setup();
}

void loop()
{
  relais.loop();
  
  switch(button.event())
  {
    case WButton::Pressed:
      relais.trigger(500);
      led.on();
      break;
    case WButton::Released:
      led.off();
      break;
  }
}