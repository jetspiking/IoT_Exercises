#include "DiscoDancer.h"

DiscoDancer::DiscoDancer(std::shared_ptr<DiscoDancerWriter> discoDancerWriter) {
    this->discoDancerWriter = discoDancerWriter; 
}

void DiscoDancer::newMQTTMessage(const char* topic, const char* message) {
    if (strcmp(message, "")==0) this->toggleState();
    if (strcmp(message, "off")==0) this->setDiscoDancerState(std::make_shared<DiscoDancerOff>());
    if (strcmp(message, "on")==0) this->setDiscoDancerState(std::make_shared<DiscoDancerOn>());
    if (strcmp(message, "converge")==0) this->setDiscoDancerState(std::make_shared<DiscoDancerConverge>());
    if (strcmp(message, "diverge")==0) this->setDiscoDancerState(std::make_shared<DiscoDancerDiverge>());
    if (strcmp(message, "blinking")==0) this->setDiscoDancerState(std::make_shared<DiscoDancerBlinking>());
    if (strcmp(message, "wave")==0) this->setDiscoDancerState(std::make_shared<DiscoDancerWave>());
}

void DiscoDancer::setDiscoDancerState(std::shared_ptr<DiscoDancerState> discoDancerState) noexcept { 
    this->discoDancerState->exit(this);
    this->discoDancerState = discoDancerState;
    this->discoDancerState->enter(this);
}

void DiscoDancer::toggleState(void) {
    this->discoDancerState->toggle(this);
}