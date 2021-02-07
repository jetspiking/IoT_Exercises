#include "TrafficLight.h"

TrafficLight::TrafficLight(std::shared_ptr<TrafficLightWriter> trafficLightWriter) {
    this->trafficLightWriter = trafficLightWriter;
}

void TrafficLight::toggleState(void) {
    this->trafficLightState->toggle(this);
}

void TrafficLight::setTrafficLightState(std::shared_ptr<TrafficLightState> trafficLightState) noexcept {
    this->trafficLightState->exit(this);
    this->trafficLightState = trafficLightState; 
    this->trafficLightState->enter(this);
}