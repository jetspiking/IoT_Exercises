#include "MQTTClient.h"

MQTTClient::MQTTClient(std::shared_ptr<WiFiClient> wifiClient)
{
    this->wifiClient = wifiClient;
    this->pubSubClient = std::make_shared<PubSubClient>(*wifiClient);
}

void MQTTClient::setMQTTCallback(std::shared_ptr<IMQTTCallback> iMQTTCallback) 
{
    this->iMQTTCallback = iMQTTCallback;
}

void MQTTClient::initMQTTClient(void)
{
}

void MQTTClient::connectToServer(const char* server, int port) {
    this->pubSubClient->setServer(server, port);
    using std::placeholders::_1;
    using std::placeholders::_2;
    using std::placeholders::_3;
    this->pubSubClient->setCallback(std::bind( &MQTTClient::callback, this, _1,_2,_3));
}

void MQTTClient::connectToTopic(const char *topic)
{
    this->pubSubClient->connect(topic);
    if (this->pubSubClient->connected() ) {
        Serial.println("Success: Connected to topic.");
    } else {
        Serial.println("Error: Can not connect to topic.");
    }
    this->pubSubClient->subscribe(topic);
}

void MQTTClient::callback(char* topic, byte* payload, unsigned int length) {
    Serial.println("Received message.");
    String messageString;
    for (int i = 0; i < length; i++)
        messageString+=(char)payload[i];
    if (this->iMQTTCallback!=nullptr)    
        this->iMQTTCallback->newMQTTMessage(topic, messageString.c_str());    
}