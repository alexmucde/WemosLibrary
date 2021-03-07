#ifndef W_BUTTON
#define W_BUTTON

#include "Arduino.h"
#include <WTimer.h>

class WButton
{
  public:

    WButton(int pin = D3);
    ~WButton();

    enum ButtonEvent { None, Pressed, Released, ShortPress, LongPress };

    void setup();
    ButtonEvent event();

    bool isDown();


  private:

    int pin;
    byte buttonState;      // the current reading from the input pin
    byte lastButtonState;  // the previous reading from the input pin

    unsigned long lastDebounceTime;  // the last time the output pin was toggled
    unsigned long debounceDelay;     // the debounce time; increase if the output flickers

    bool statePressed;     // set when button pressed
	
	WTimer longPressTimer;
	WTimer debounceTimer;

};

#endif
