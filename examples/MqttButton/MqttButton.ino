// Used CLasses from Wemos Library
#include <WMqtt.h>
#include <WButton.h>
#include <WLed.h>

// Configuration
const char *ssid = "WLAN_SSID";
const char *psk = "WLAN_PASSWORD";
const char *mqqtClientIp = "MQTT_BROKER_IP";
const char *mqttClientId = "MqttButton";
const unsigned long ledBlinkSpeedOk = 2000; // 2s
const unsigned long ledBlinkSpeedError = 200; // 200ms

// Instances
WLed led;
WButton button;
WMqtt mqtt(ssid,psk,mqqtClientIp,mqttClientId);

// Setup
void setup()
{
  // Setup LED
  led.setup();
  led.on();
  led.setBlink(ledBlinkSpeedError);

  // Setup Button
  button.setup();
  
  // Setup Mqtt
  mqtt.setup(); 
}

// Loop
void loop()
{
  // Loop LED
  led.loop();

  // Event Mqtt
  switch(mqtt.event())
  {
    case WMqtt::Connected:
      // Mqtt connected
      led.setBlink(ledBlinkSpeedOk);
      break;
    case WMqtt::Disconnected:
      // Mqtt disconnected
      led.setBlink(ledBlinkSpeedError);
      break;
  }  

  // Event Button
  switch(button.event())
  {
    case WButton::Pressed:
      // Button Pressed
      mqtt.publish("Wemos/MqttButton","ON");
      break;
    case WButton::Released:
      // Button Released
      mqtt.publish("Wemos/MqttButton","OFF");
      break;
  }  
}
