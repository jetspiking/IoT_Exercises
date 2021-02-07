#pragma once
#include <map>
#include <memory>
#include "TrafficLight.h"
#include "TrafficLightWriter.h"

class TrafficLight;

class TrafficLightState { 
    public:
    virtual void enter(TrafficLight* trafficLight) = 0;
    virtual void toggle(TrafficLight* trafficLight) = 0;
    virtual void exit(TrafficLight* trafficLight) = 0;
}; 

class TrafficLightOutOfOrder : public TrafficLightState {
public:
    void enter(TrafficLight* trafficLight) override;
    void toggle(TrafficLight* trafficLight) override;
    void exit(TrafficLight* trafficLight) override;
};

class TrafficLightRed : public TrafficLightState {
public:
    void enter(TrafficLight* trafficLight) override;
    void toggle(TrafficLight* trafficLight) override;
    void exit(TrafficLight* trafficLight) override;
};

class TrafficLightOrange : public TrafficLightState {
public:
    void enter(TrafficLight* trafficLight) override;
    void toggle(TrafficLight* trafficLight) override;
    void exit(TrafficLight* trafficLight) override;
};

class TrafficLightGreen : public TrafficLightState {
public:
    void enter(TrafficLight* trafficLight) override;
    void toggle(TrafficLight* trafficLight) override;
    void exit(TrafficLight* trafficLight) override;
};