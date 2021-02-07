#include "TrafficLightWriter.h"

TrafficLightWriter::TrafficLightWriter(std::shared_ptr<TrafficLightPinSetup> trafficLightPinSetup) {
    this->trafficLightPinSetup = trafficLightPinSetup;
}

void TrafficLightWriter::enterOutOfOrder(TrafficLight* trafficLight) {
    std::cout << "Stoplicht buiten dienst - start" << std::endl;
    digitalWrite(trafficLight->getTrafficLightWriter()->trafficLightPinSetup->trafficLightPinRed, WRITER_LED_OFF);
    digitalWrite(trafficLight->getTrafficLightWriter()->trafficLightPinSetup->trafficLightPinOrange, WRITER_LED_OFF);
    digitalWrite(trafficLight->getTrafficLightWriter()->trafficLightPinSetup->trafficLightPinGreen, WRITER_LED_OFF);
}

void TrafficLightWriter::toggleOutOfOrder(TrafficLight* trafficLight) {
    std::cout << "Stoplicht buiten dienst - toggle" << std::endl;
}

void TrafficLightWriter::exitOutOfOrder(TrafficLight* trafficLight) {
    std::cout << "Stoplicht buiten dienst - exit" << std::endl;
}

void TrafficLightWriter::enterRed(TrafficLight* trafficLight) {
    std::cout << "Stoplicht rood - start" << std::endl;
    digitalWrite(trafficLight->getTrafficLightWriter()->trafficLightPinSetup->trafficLightPinRed, WRITER_LED_ON);
}

void TrafficLightWriter::toggleRed(TrafficLight* trafficLight) {
    std::cout << "Stoplicht rood - toggle" << std::endl;
}

void TrafficLightWriter::exitRed(TrafficLight* trafficLight) {
    std::cout << "Stoplicht rood - exit" << std::endl;
    digitalWrite(trafficLight->getTrafficLightWriter()->trafficLightPinSetup->trafficLightPinRed, WRITER_LED_OFF);
}

void TrafficLightWriter::enterOrange(TrafficLight* trafficLight) {
    std::cout << "Stoplicht oranje - start" << std::endl;
    digitalWrite(trafficLight->getTrafficLightWriter()->trafficLightPinSetup->trafficLightPinOrange, WRITER_LED_ON);
}

void TrafficLightWriter::toggleOrange(TrafficLight* trafficLight) {
    std::cout << "Stoplicht oranje - toggle" << std::endl;
}

void TrafficLightWriter::exitOrange(TrafficLight* trafficLight) {
    std::cout << "Stoplicht oranje - exit" << std::endl;
    digitalWrite(trafficLight->getTrafficLightWriter()->trafficLightPinSetup->trafficLightPinOrange, WRITER_LED_OFF);
}

void TrafficLightWriter::enterGreen(TrafficLight* trafficLight) {
    std::cout << "Stoplicht groen - start" << std::endl;
    digitalWrite(trafficLight->getTrafficLightWriter()->trafficLightPinSetup->trafficLightPinGreen, WRITER_LED_ON);
}

void TrafficLightWriter::toggleGreen(TrafficLight* trafficLight) {
    std::cout << "Stoplicht groen - toggle" << std::endl;
}

void TrafficLightWriter::exitGreen(TrafficLight* trafficLight) { 
    std::cout << "Stoplicht groen - exit" << std::endl;
    digitalWrite(trafficLight->getTrafficLightWriter()->trafficLightPinSetup->trafficLightPinGreen, WRITER_LED_OFF);
}

