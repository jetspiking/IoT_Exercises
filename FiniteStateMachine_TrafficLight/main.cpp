#include <Arduino.h>
#include <memory>
#include "TrafficLightPinSetup.h"
#include "TrafficLightWriter.h"
#include "TrafficLight.h"
#include "TrafficLightState.h"

constexpr uint8_t light1PinRed = 18;
constexpr uint8_t light1PinOrange = 19;
constexpr uint8_t light1PinGreen = 21;
constexpr uint8_t light1PinButton = 22;

constexpr uint8_t light2PinRed = 33;
constexpr uint8_t light2PinOrange = 32;
constexpr uint8_t light2PinGreen = 25;
constexpr uint8_t light2PinButton = 23;

std::shared_ptr<TrafficLightPinSetup> trafficLight1PinSetup;
std::shared_ptr<TrafficLightWriter> trafficLight1Writer;
std::shared_ptr<TrafficLight> trafficLight1;

std::shared_ptr<TrafficLightPinSetup> trafficLight2PinSetup;
std::shared_ptr<TrafficLightWriter> trafficLight2Writer;
std::shared_ptr<TrafficLight> trafficLight2;

void setup() {
  pinMode(light1PinRed, OUTPUT);
  pinMode (light2PinRed, OUTPUT);

  digitalWrite(light1PinRed, WRITER_LED_ON);
  digitalWrite(light2PinRed, WRITER_LED_ON);

  pinMode(light1PinOrange, OUTPUT);
  pinMode(light2PinOrange, OUTPUT);

  digitalWrite(light1PinOrange, WRITER_LED_ON);
  digitalWrite(light2PinOrange, WRITER_LED_ON);

  pinMode(light1PinGreen, OUTPUT);
  pinMode(light2PinGreen, OUTPUT);

  digitalWrite(light1PinGreen, WRITER_LED_ON);
  digitalWrite(light2PinGreen, WRITER_LED_ON);

  pinMode(light1PinButton, INPUT);
  pinMode(light2PinButton, INPUT);

  trafficLight1PinSetup = std::make_shared<TrafficLightPinSetup>(light1PinRed,light1PinOrange,light1PinGreen,light1PinButton);
  trafficLight1Writer = std::make_shared<TrafficLightWriter>(trafficLight1PinSetup);
  trafficLight1 = std::make_shared<TrafficLight>(trafficLight1Writer);

  trafficLight2PinSetup = std::make_shared<TrafficLightPinSetup>(light2PinRed,light2PinOrange,light2PinGreen,light2PinButton);
  trafficLight2Writer = std::make_shared<TrafficLightWriter>(trafficLight2PinSetup);
  trafficLight2 = std::make_shared<TrafficLight>(trafficLight2Writer);

  sleep(1);
  trafficLight1->setTrafficLightState(std::make_shared<TrafficLightOutOfOrder>());
  trafficLight2->setTrafficLightState(std::make_shared<TrafficLightOutOfOrder>()); 
  trafficLight1->setTrafficLightState(std::make_shared<TrafficLightGreen>());
  trafficLight2->setTrafficLightState(std::make_shared<TrafficLightRed>());
}

void loop() {
  if (digitalRead(light1PinButton)==1) { 
    trafficLight2->setTrafficLightState(std::make_shared<TrafficLightOrange>());
    trafficLight1->setTrafficLightState(std::make_shared<TrafficLightGreen>());
  } 
  if (digitalRead(light2PinButton)==1) {
    trafficLight1->setTrafficLightState(std::make_shared<TrafficLightOrange>());
    trafficLight2->setTrafficLightState(std::make_shared<TrafficLightGreen>());
  }
  sleep(1);
}
