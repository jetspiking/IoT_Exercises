#include <Arduino.h>
#include <memory>
#include "DiscoDancer.h"
#include "DiscoDancerWriter.h"
#include "WiFiSetup.h"
#include "MQTTClient.h"

std::shared_ptr<DiscoDancer> discoDancer;
std::shared_ptr<DiscoDancerWriter> discoDancerWriter;
std::shared_ptr<MQTTClient> mqttClient;

void setup()
{
	Serial.begin(9600);
	Serial.println("Starting");

	discoDancerWriter = std::make_shared<DiscoDancerWriter>();
	discoDancer = std::make_shared<DiscoDancer>(discoDancerWriter);

	for (byte b = 0; b < sizeof(DiscoDancerWriter::pins); b++)
		pinMode(DiscoDancerWriter::pins[b], OUTPUT);

	discoDancer->setDiscoDancerState(std::make_shared<DiscoDancerWave>());

	std::shared_ptr<WiFiSetup> wifiSetup = std::make_shared<WiFiSetup>();
	mqttClient = std::make_shared<MQTTClient>(wifiSetup->getWiFiClient());

	std::shared_ptr<IMQTTCallback> iCallback = std::dynamic_pointer_cast<IMQTTCallback>(discoDancer);
	mqttClient->setMQTTCallback(iCallback);

	mqttClient->connectToServer("test.mosquitto.org", 1883);
	mqttClient->connectToTopic("DiscoDancer");

}

uint64_t delayCounter = 0;


void loop()
{
	if (delayCounter % 50 == 0)
	{
		std::shared_ptr<DiscoDancerInteractiveState> interactiveState = std::dynamic_pointer_cast<DiscoDancerInteractiveState>(discoDancer->getDiscoDancerState());
		mqttClient->getPubSubClient()->loop();
		if (interactiveState)
			interactiveState->actingSwap(discoDancer.get());

	}

	delay(10);
	if (++delayCounter > UINT_FAST64_MAX)
		delayCounter = 0;
}