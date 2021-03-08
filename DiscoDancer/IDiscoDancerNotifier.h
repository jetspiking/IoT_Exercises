#pragma once

#include "DiscoDancer.h"

class DiscoDancer;

class IDiscoDancerNotifier
{
public:
    virtual void enterOff(DiscoDancer *) = 0;
    virtual void toggleOff(DiscoDancer *) = 0;
    virtual void exitOff(DiscoDancer *) = 0;

    virtual void enterOn(DiscoDancer *) = 0;
    virtual void toggleOn(DiscoDancer *) = 0;
    virtual void exitOn(DiscoDancer *) = 0;

    virtual void enterBlinking(DiscoDancer *) = 0;
    virtual void toggleBlinking(DiscoDancer *) = 0;
    virtual void exitBlinking(DiscoDancer *) = 0;
    virtual void actingSwapBlinking(DiscoDancer *) = 0;

    virtual void enterPin(DiscoDancer *) = 0;
    virtual void togglePin(DiscoDancer *) = 0;
    virtual void exitPin(DiscoDancer *) = 0;

    virtual void enterWave(DiscoDancer *) = 0;
    virtual void toggleWave(DiscoDancer *) = 0;
    virtual void exitWave(DiscoDancer *) = 0;
    virtual void actingSwapWave(DiscoDancer *) = 0;

    virtual void enterConverge(DiscoDancer *) = 0;
    virtual void toggleConverge(DiscoDancer *) = 0;
    virtual void exitConverge(DiscoDancer *) = 0;
    virtual void actingSwapConverge(DiscoDancer *) = 0;

    virtual void enterDiverge(DiscoDancer *) = 0;
    virtual void toggleDiverge(DiscoDancer *) = 0;
    virtual void exitDiverge(DiscoDancer *) = 0;
    virtual void actingSwapDiverge(DiscoDancer *) = 0;
};