#include "WButton.h"
  
WButton::WButton(int pin)
{
  this->pin = pin;
  lastButtonState = 1;
  lastDebounceTime = 0;
  debounceDelay = 50;
  statePressed = false;
}

WButton::~WButton()
{
  
}

void WButton::setup()
{
  pinMode(pin,INPUT);    
}

WButton::ButtonEvent WButton::event()
{
  int reading = digitalRead(pin);

  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
  
    // if the button state has changed:
    if (reading != buttonState) {
        buttonState = reading;
  
        // only toggle the LED if the new button state is HIGH
        if (buttonState == LOW) 
        {
          statePressed = true;
          lastButtonState = reading;
          return WButton::Pressed;
        }
        else
        {
          statePressed = false;
          lastButtonState = reading;
          return WButton::Released;
        }
      }
  }
  
  lastButtonState = reading;
  return WButton::None;
}

  
bool WButton::isDown()
{
  return statePressed;
}
  
