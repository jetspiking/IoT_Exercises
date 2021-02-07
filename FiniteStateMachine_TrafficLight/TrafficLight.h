#pragma once
#include <memory>
#include "TrafficLightState.h"
#include "TrafficLightWriter.h"

class TrafficLightState;
class TrafficLightWriter;
class TrafficLightOutOfOrder;

class TrafficLight {

    public: 
    TrafficLight(std::shared_ptr<TrafficLightWriter> trafficLightWriter);

    inline std::shared_ptr<TrafficLightState> getTrafficLightState (void) const noexcept { return trafficLightState; }; 
    inline std::shared_ptr<TrafficLightWriter> getTrafficLightWriter (void) const noexcept { return trafficLightWriter; };
    
    void setTrafficLightState (std::shared_ptr<TrafficLightState> trafficLightState) noexcept; 
    
    void toggleState (void);


    private:
    std::shared_ptr<TrafficLightState> trafficLightState = std::dynamic_pointer_cast<TrafficLightState>(std::make_shared<TrafficLightOutOfOrder>());
    std::shared_ptr<TrafficLightWriter> trafficLightWriter;
};