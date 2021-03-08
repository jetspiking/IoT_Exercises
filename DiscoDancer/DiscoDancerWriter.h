#pragma once
#include "Arduino.h"
#include "IDiscoDancerNotifier.h"

constexpr byte WRITER_LED_ON = 0;
constexpr byte WRITER_LED_OFF = 1;

class DiscoDancerWriter : public IDiscoDancerNotifier
{

public:
    static byte pins[8];

    byte singlePin = 15;

    void enterOff(DiscoDancer *) override;
    void toggleOff(DiscoDancer *) override;
    void exitOff(DiscoDancer *) override;

    void enterOn(DiscoDancer *) override;
    void toggleOn(DiscoDancer *) override;
    void exitOn(DiscoDancer *) override;

    void enterBlinking(DiscoDancer *) override;
    void toggleBlinking(DiscoDancer *) override;
    void exitBlinking(DiscoDancer *) override;
    void actingSwapBlinking(DiscoDancer *) override;

    void enterPin(DiscoDancer *) override;
    void togglePin(DiscoDancer *) override;
    void exitPin(DiscoDancer *) override;

    void enterWave(DiscoDancer *) override;
    void toggleWave(DiscoDancer *) override;
    void exitWave(DiscoDancer *) override;
    void actingSwapWave(DiscoDancer *) override;

    void enterConverge(DiscoDancer *) override;
    void toggleConverge(DiscoDancer *) override;
    void exitConverge(DiscoDancer *) override;
    void actingSwapConverge(DiscoDancer *) override;

    void enterDiverge(DiscoDancer *) override;
    void toggleDiverge(DiscoDancer *) override;
    void exitDiverge(DiscoDancer *) override;
    void actingSwapDiverge(DiscoDancer *) override;

private:
};