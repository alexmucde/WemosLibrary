#include <WButton.h>
#include <WLed.h>
#include <WRelais.h>
#include <WSerial.h>

WButton button;
WLed led;
WRelais relais1(D1);
WRelais relais2(D2);
WRelais relais3(D6);
WSerial serial;

void setup()
{
  serial.setup();
  button.setup();
  led.setup();
  relais1.setup();
  relais2.setup();
  relais3.setup();
}

void loop()
{
  relais1.loop();
  relais2.loop();
  relais3.loop();
  
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

  switch(serial.event())
  {
    case WSerial::Line:
      String text = serial.line();
      if(text[0]=='D')
      {
        if(text[1]=='1')
        {
          if(text[2]=='0')
          {
            relais1.off();
          }      
          else if(text[2]=='1')
          {
            relais1.on();            
          }      
          else if(text[2]=='T')
          {
            relais1.trigger(500);
          }      
        }
        if(text[1]=='2')
        {
          if(text[2]=='0')
          {
            relais2.off();
          }      
          else if(text[2]=='1')
          {
            relais2.on();            
          }      
          else if(text[2]=='T')
          {
            relais2.trigger(500);
          }      
        }     
        if(text[1]=='6')
        {
          if(text[2]=='0')
          {
            relais3.off();
          }      
          else if(text[2]=='1')
          {
            relais3.on();            
          }      
          else if(text[2]=='T')
          {
            relais3.trigger(500);
          }      
        }     
      }
      break;
  }
  
}