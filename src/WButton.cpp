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
  longPressTimer.event();
  debounceTimer.event();

  if (reading != lastButtonState) {
    debounceTimer.start(50);
  }

  if(debounceTimer.isExpired())
  {
    if (reading != buttonState) {
        buttonState = reading;
        
		if (buttonState == LOW) 
        {
          statePressed = true;
          lastButtonState = reading;
		  longPressTimer.start(750);
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
  
  if(statePressed == false && longPressTimer.running())
  {
	  // Short Press detected
	  longPressTimer.stop();
	  return WButton::ShortPress;
  }
  
  if(statePressed == true && longPressTimer.isExpired())
  {
	  // Long Press detected
	  longPressTimer.stop();
	  return WButton::LongPress;
  }
  
  lastButtonState = reading;
  return WButton::None;
}

  
bool WButton::isDown()
{
  return statePressed;
}
  
