#include "WButton.h"
  
WButton::WButton(int pin)
{
  this->pin = pin;
  lastButtonState = 0;
  lastDebounceTime = 0;
  debounceDelay = 50;
  statePressed = false;
  buttonState = true;
  lastButtonState = false;
}

WButton::~WButton()
{
  
}

void WButton::setup()
{
  pinMode(pin,INPUT);
  digitalWrite(pin, LOW);  
}

WButton::ButtonEvent WButton::event()
{
  pinMode(pin,INPUT);    
  digitalWrite(pin, LOW);  
  byte reading = digitalRead(pin);
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
  
