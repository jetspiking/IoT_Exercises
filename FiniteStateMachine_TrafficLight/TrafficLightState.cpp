#include "trafficLightState.h"

void TrafficLightOutOfOrder::enter(TrafficLight* trafficLight) {
    trafficLight->getTrafficLightWriter()->enterOutOfOrder(trafficLight);
}

void TrafficLightOutOfOrder::toggle(TrafficLight* trafficLight) {
    trafficLight->getTrafficLightWriter()->toggleOutOfOrder(trafficLight);
    trafficLight->setTrafficLightState(std::make_shared<TrafficLightRed>());
}

void TrafficLightOutOfOrder::exit(TrafficLight* trafficLight) {
    trafficLight->getTrafficLightWriter()->exitOutOfOrder(trafficLight);
}

void TrafficLightRed::enter(TrafficLight* trafficLight) {
    trafficLight->getTrafficLightWriter()->enterRed(trafficLight);
}

void TrafficLightRed::toggle(TrafficLight* trafficLight) {
    trafficLight->getTrafficLightWriter()->toggleRed(trafficLight);
    trafficLight->setTrafficLightState(std::make_shared<TrafficLightGreen>());
}

void TrafficLightRed::exit(TrafficLight* trafficLight) {
    trafficLight->getTrafficLightWriter()->exitRed(trafficLight);
}

void TrafficLightOrange::enter(TrafficLight* trafficLight) {
    trafficLight->getTrafficLightWriter()->enterOrange(trafficLight);
    sleep(5);
    trafficLight->toggleState();
}

void TrafficLightOrange::toggle(TrafficLight* trafficLight) {
    trafficLight->getTrafficLightWriter()->toggleOrange(trafficLight);
    trafficLight->setTrafficLightState(std::make_shared<TrafficLightRed>());
}

void TrafficLightOrange::exit(TrafficLight* trafficLight) {
    trafficLight->getTrafficLightWriter()->exitOrange(trafficLight);
}

void TrafficLightGreen::enter(TrafficLight* trafficLight) {
    trafficLight->getTrafficLightWriter()->enterGreen(trafficLight);
}

void TrafficLightGreen::toggle(TrafficLight* trafficLight) {
    trafficLight->getTrafficLightWriter()->toggleGreen(trafficLight);
    trafficLight->setTrafficLightState(std::make_shared<TrafficLightOrange>());
}

void TrafficLightGreen::exit(TrafficLight* trafficLight) { 
    trafficLight->getTrafficLightWriter()->exitGreen(trafficLight);
}