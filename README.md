# WemosLibrary
Easy to use C++ Library for the WEMOS/LOLIN D1 mini CPU boards and shields for the Arduino platform.

The following Wemos D1 Mini CPU Boards are supprted:

![Image of Wemos D1 Mini](https://github.com/alexmucde/WemosLibrary/blob/main/doc/images/WemosD1Mini.jpg) [AliExpress](https://s.click.aliexpress.com/e/_AXoYOK)

![Image of Wemos D1 Mini v3](https://github.com/alexmucde/WemosLibrary/blob/main/doc/images/WemosD1MiniV3.jpg) [Amazon Germany](https://amzn.to/3thvzYd) [AliExpress](https://s.click.aliexpress.com/e/_AsJ7pg)

![Image of Wemos D1 Mini Pro](https://github.com/alexmucde/WemosLibrary/blob/main/doc/images/WemosD1MiniPro.jpg) [AliExpress](https://s.click.aliexpress.com/e/_Ag4g4w)


The following base boards can be used to use several Wemos Shields in parallel:

![Image of Dual Base](https://github.com/alexmucde/WemosLibrary/blob/main/doc/images/DualBase.jpg) [Amazon Germany](https://amzn.to/3eyI9Ov) [AliExpress Dual Base](https://s.click.aliexpress.com/e/_9In2Z0)

![Image of Triple Base](https://github.com/alexmucde/WemosLibrary/blob/main/doc/images/TripleBase.jpg) [AliExpress Triple Base](https://s.click.aliexpress.com/e/_AXI4VC)


# Implemented classes

## WLed

### Supported Boards

Supports WEMOS Builtin LED

![Image of Wemos D1 Mini](https://github.com/alexmucde/WemosLibrary/blob/main/doc/images/WemosD1Mini.jpg) [Amazon Germany](https://amzn.to/3thvzYd) [AliExpress](https://s.click.aliexpress.com/e/_AXoYOK)

### Default Settings

Pin: GPIO02/D4

### Dependent Library

None

### Examples

```
#include <WLed.h>

WLed led;

void setup() {
  led.setup();
}

void loop() {
  led.loop();
  
  led.on();
  delay(500);
  led.off();
  delay(500);
  
}
```

## WRgb

### Supported Boards

WEMOS WS2812B RGB Shield

![Image of RGB Shield](https://github.com/alexmucde/WemosLibrary/blob/main/doc/images/RgbShield.jpg) [AliExpress](https://s.click.aliexpress.com/e/_A9uePs)

![Image of RGB 7 Shield](https://github.com/alexmucde/WemosLibrary/blob/main/doc/images/Rgb7Shield.jpg)

### Default Settings

Pin: GPIO04/D2

### Dependent Library

Adafruit NeoPixel

### Examples

```
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
```

## WButton

### Supported Boards

Supports WEMOS Button Shield

![Image of RGB Shield](https://github.com/alexmucde/WemosLibrary/blob/main/doc/images/ButtonShield.jpg) [AliExpress](https://s.click.aliexpress.com/e/_9INwTG)

### Default Settings

Pin: GPIO00/D3

### Dependent Library

None

### Examples

```
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
```

## WRelais

### Supported Boards

Supports WEMOS Relais Shield

![Image of RGB Shield](https://github.com/alexmucde/WemosLibrary/blob/main/doc/images/RelaisShield.jpg) [Amazon Germany](https://amzn.to/3csEJdE) [AliExpress](https://s.click.aliexpress.com/e/_9JeBua)

### Default Settings

Pin: GPIO14/D5

### Dependent Library

None

### Examples

```
#include <WRelais.h>

WRelais relais;

void setup() {
  relais.setup();
}

void loop() {
  relais.on();
  delay(500);
  relais.off();
  delay(500);
  
}
```

## WBuzzer

### Supported Boards

Supports WEMOS Buzzer Shield

![Image of RGB Shield](https://github.com/alexmucde/WemosLibrary/blob/main/doc/images/BuzzerShield.jpg) [AliExpress](https://s.click.aliexpress.com/e/_A7sRs2)

### Default Settings

Pin: GPIO05/D1

### Dependent Library

None

### Examples

```
#include <WBuzzer.h>

WBuzzer buzzer;

void setup() {
  buzzer.setup();
}

void loop() {
  buzzer.tone(262,150); // c
  delay(500);
  buzzer.tone(294,150); // d
  delay(500);
  buzzer.tone(230,150); // e
  delay(500);
}
```

## WAmbientLight

### Supported Boards

Supports WEMOS Ambient Light

![Image of Ambient Light Shield](https://github.com/alexmucde/WemosLibrary/blob/main/doc/images/AmbientLightShield.jpg)

### Default Settings

Pin:

* GPIO05/D1
* GPIO04/D2

Default I²C Address: 0x23

### Dependent Library

BH1750

### Examples

```
#include <WAmbientLight.h>

WAmbientLight ambientLight;

void setup() {
	Serial.begin(115200);
	
	ambientLight.setup();
}

void loop() {
	uint16_t value = ambientLight.getValue();

	Serial.print("Light: ");
	Serial.print(value);
	Serial.println(" lx");
	delay(1000);
  
}
```

## WCan

### Supported Boards

Supports a custom build CAN Shield with MCP2515

### Default Settings

D5 SCK
D6 MISO
D7 MOSI
D8 GPIO015 CS
D4 GPIO02 INT

### Dependent Library

MCP CAN lib

## WMqtt

### Dependent Library

PubSubClient

## WTimer

Helper class

## WColour

Helper class

## WColourArray

Helper class

## WDlt

Logging in the Automotive DLT protocol

## Serial

Helper class for serial port communication

## Contributing

Contibutions are always welcome! Please provide a Pull Request on Github.

https://github.com/alexmucde/DLTRelais

## Donation

If you find this SW useful and you want to donate my work please select one of the following donations:

Paypal Donation:

[![Donations](https://www.paypalobjects.com/en_US/DK/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/donate?hosted_button_id=YBWSNXYWJJP2Q)

Github Sponsors:

[:heart: Sponsor](https://github.com/sponsors/alexmucde)

## Copyright

Alexander Wenzel <alex@eli2.de>

This code is licensed under LGPLv3.

# Links

https://github.com/alexmucde/WemosLibrary
