// Used Classes from Wemos Library
#include <WMqtt.h>
#include <WBuzzer.h>
#include <WLed.h>
#include <WRgb.h>

// Configuration
const char *ssid = "WLAN_SSID";
const char *psk = "WLAN_PASSWORD";
const char *mqqtClientIp = "MQTT_BROKER_IP";
const char *mqttClientId = "MqttBuzzer";
const char notes[] = "cdfda ag cdfdg gf ";
const int beats[] = {1,1,1,1,1,1,4,4,2,1,1,1,1,1,1,4,4,2};
const unsigned long rgbBlinkSpeed = 200; // 200ms
const unsigned long rgbBlinkTime = 60 * 1000; // 60s
const unsigned long ledBlinkSpeedOk = 2000; // 2s
const unsigned long ledBlinkSpeedError = 200; // 200ms

// Instances
WLed led;
WBuzzer buzzer;
WRgb rgb;
WMqtt mqtt(ssid,psk,mqqtClientIp,mqttClientId);

// Mqtt Callback
void callback(char* topic, byte* payload, unsigned int length)
{
    // Mqtt message received
    char msg[length+1];
    for (int i = 0; i < length; i++) {
        msg[i] = (char)payload[i];
    }
    msg[length] = 0;  
    if(strcmp(msg,"ON")==0)
    {
        // ON received
        buzzer.play(notes,beats);
        rgb.on(rgbBlinkTime);
    }
    else if(strcmp(msg,"OFF")==0)
    {
        // OFF received
    }  
}

// Setup
void setup()
{
  // Setup LED
  led.setup();
  led.on();
  led.setBlink(ledBlinkSpeedError);

  // Setup Rgb
  rgb.setup();
  rgb.setBlink(rgbBlinkSpeed);
  rgb.setColor(white);
  rgb.on(rgbBlinkSpeed); // test blink
  
  // Setup Mqtt
  mqtt.setup();
  mqtt.setCallback(callback);

  // Setup Buzzer
  buzzer.setup();
  buzzer.tone(262,150); // test tome
}

// Loop
void loop()
{
  // Loop LED
  led.loop();

  // Loop RGB
  rgb.loop();
  
  // Loop Buzzer
  buzzer.loop();
  
  // Event Mqtt
  switch(mqtt.event())
  {
    case WMqtt::Connected:
      // Mqtt connected
      led.setBlink(ledBlinkSpeedOk);
      mqtt.subscribe("Wemos/MqttButton");
      break;
    case WMqtt::Disconnected:
      // Mqtt disconnected
      led.setBlink(ledBlinkSpeedError);
      break;
  }
    
}
