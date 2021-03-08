#pragma once
#include <memory>
#include "DiscoDancerState.h"
#include "DiscoDancerWriter.h"
#include "IMQTTCallback.h"

class DiscoDancerState;
class DiscoDancerWriter;

class DiscoDancerOff;
class DiscoDancerOn;
class DiscoDancerWave;
class DiscoDancerBlinking;
class DiscoDancerPin;

class DiscoDancer : public IMQTTCallback
{

public:
    DiscoDancer(std::shared_ptr<DiscoDancerWriter> discoDancerWriter);

    inline std::shared_ptr<DiscoDancerState> getDiscoDancerState(void) const noexcept { return discoDancerState; };
    inline std::shared_ptr<DiscoDancerWriter> getDiscoDancerWriter(void) const noexcept { return discoDancerWriter; };

    void setDiscoDancerState(std::shared_ptr<DiscoDancerState> discoDancerState) noexcept;
    void newMQTTMessage(const char* topic, const char* message) override;
    void toggleState(void);

private:
    std::shared_ptr<DiscoDancerState> discoDancerState = std::dynamic_pointer_cast<DiscoDancerState>(std::make_shared<DiscoDancerOff>());
    std::shared_ptr<DiscoDancerWriter> discoDancerWriter;
};