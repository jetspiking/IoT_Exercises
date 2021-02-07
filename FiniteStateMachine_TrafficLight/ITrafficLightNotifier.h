#pragma once

#include "TrafficLight.h"

class TrafficLight;

class ITrafficLightNotifier { 
    public: 

    virtual void enterOutOfOrder(TrafficLight*) = 0;
    virtual void toggleOutOfOrder(TrafficLight*) = 0;
    virtual void exitOutOfOrder(TrafficLight*) = 0;

    virtual void enterRed(TrafficLight*) = 0;
    virtual void toggleRed(TrafficLight*) = 0;
    virtual void exitRed(TrafficLight*) = 0;

    virtual void enterOrange(TrafficLight*) = 0;
    virtual void toggleOrange(TrafficLight*) = 0;
    virtual void exitOrange(TrafficLight*) = 0;

    virtual void enterGreen(TrafficLight*) = 0;
    virtual void toggleGreen(TrafficLight*) = 0;
    virtual void exitGreen(TrafficLight*) = 0;
};