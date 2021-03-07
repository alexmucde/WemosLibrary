#include <WButton.h>
#include <WLed.h>
#include <WRelais.h>

WButton button;
WLed led;
WRelais relais1(D1);
WRelais relais2(D2);

void setup()
{
  button.setup();
  led.setup();
  relais1.setup();
  relais2.setup();
}

void loop()
{
  relais1.loop();
  relais2.loop();
  
  switch(button.event())
  {
    case WButton::Pressed:
      led.on();
      break;
    case WButton::ShortPress:
      relais1.trigger(500);
      break;
    case WButton::LongPress:
      relais2.toggle();
      break;
    case WButton::Released:
      led.off();
      break;
  }
}