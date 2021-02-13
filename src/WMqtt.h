#ifndef W_MQTT
#define W_MQTT

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

class WMqtt
{
	public:
		WMqtt(const char *ssid,const char *psk,const char *mqttBroker,const char *clientId);
		~WMqtt();
	
		enum MqttEvent { None, Connected, Disconnected };
		
		void setup();
		MqttEvent event();
		
		void reconnect();
		void setupWifi();
		
		void publish(const char *topic,const char *text);
		void subscribe(const char *topic);
		void setCallback(MQTT_CALLBACK_SIGNATURE);
		
	private:
		WiFiClient espClient;
		PubSubClient  mqttClient;
		const char *ssid;
		const char *psk;
		const char *mqttBroker;
		const char *clientId;
		
		bool lastConnectedState;
};

#endif W_MQTT