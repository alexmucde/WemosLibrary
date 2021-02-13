#include "WMqtt.h"

WMqtt::WMqtt(const char *ssid,const char *psk,const char *mqttBroker,const char *clientId)
  : mqttClient(espClient)
{
	this->ssid = ssid;
	this->psk = psk;
	this->mqttBroker = mqttBroker;
	this->clientId = clientId;
}

WMqtt::~WMqtt()
{
}

void WMqtt::setup()
{
	setupWifi();
    mqttClient.setServer(mqttBroker, 1883);
}

WMqtt::MqttEvent WMqtt::event()
{
    mqttClient.loop();
	if (!mqttClient.connected())
	{
		if(lastConnectedState==true)
		{
			lastConnectedState = false;
			return WMqtt::Disconnected;
		}
		reconnect();
    }
	else
	{
		if(lastConnectedState==false)
		{
			lastConnectedState = true;
			return WMqtt::Connected;
		}
	}	
	
	return WMqtt::None;
}

void WMqtt::setupWifi()
{
    delay(10);
    //Serial.println();
    //Serial.print("Connecting to ");
    //Serial.println(SSID);
 
    WiFi.begin(ssid, psk);
 
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        //Serial.print(".");
    }
 
    //Serial.println("");
    //Serial.println("WiFi connected");
    //Serial.println("IP address: ");
    //Serial.println(WiFi.localIP());
}

void WMqtt::reconnect()
{
    if(!mqttClient.connected())
	{
        //Serial.print("Reconnecting...");
        if (!mqttClient.connect(clientId))
		{
            //Serial.print("failed, rc=");
            //Serial.print(client.state());
            //Serial.println(" retrying in 5 seconds");
            delay(500);
        }
    }

}

void WMqtt::publish(const char *topic,const char *text)
{
    //Serial.print("Publish message: ");
    //Serial.println(msg);
    mqttClient.publish(topic, text);	
}

void WMqtt::subscribe(const char *topic)
{
    //Serial.print("Publish message: ");
	mqttClient.subscribe(topic);
}

void WMqtt::setCallback(MQTT_CALLBACK_SIGNATURE)
{
	mqttClient.setCallback(callback);
}

