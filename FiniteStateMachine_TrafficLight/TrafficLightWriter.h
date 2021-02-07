#pragma once
#include <Arduino.h>
#include <memory>
#include <iostream>
#include "TrafficLightPinSetup.h"
#include "ITrafficLightNotifier.h"
#include "TrafficLight.h"


constexpr int WRITER_LED_ON = 0;
constexpr int WRITER_LED_OFF = 1; 

class TrafficLight;

class TrafficLightWriter : public ITrafficLightNotifier {

public: 

    TrafficLightWriter(std::shared_ptr<TrafficLightPinSetup> trafficLightPinSetup);    

    void enterOutOfOrder(TrafficLight* trafficLight) override;
    void toggleOutOfOrder(TrafficLight* trafficLight) override;
    void exitOutOfOrder(TrafficLight* trafficLight) override; 

    void enterRed(TrafficLight* trafficLight) override;
    void toggleRed(TrafficLight* trafficLight) override;
    void exitRed(TrafficLight* trafficLight) override;

    void enterOrange(TrafficLight* trafficLight) override;
    void toggleOrange(TrafficLight* trafficLight) override;
    void exitOrange(TrafficLight* trafficLight) override;

    void enterGreen(TrafficLight* trafficLight) override;
    void toggleGreen(TrafficLight* trafficLight) override;
    void exitGreen(TrafficLight* trafficLight) override;

    std::shared_ptr<TrafficLightPinSetup> trafficLightPinSetup;
};