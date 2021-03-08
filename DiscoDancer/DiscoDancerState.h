#pragma once
#include "DiscoDancer.h"
#include "DiscoDancerWriter.h"

class DiscoDancer;

class DiscoDancerState
{
public:
    virtual void enter(DiscoDancer *discoDancer) = 0;
    virtual void toggle(DiscoDancer *discoDancer) = 0;
    virtual void exit(DiscoDancer *discoDancer) = 0;
};

class DiscoDancerInteractiveState
{
public:
    virtual void actingSwap(DiscoDancer *discoDancer) = 0;
};

class DiscoDancerOff : public DiscoDancerState
{
public:
    void enter(DiscoDancer *discoDancer) override;
    void toggle(DiscoDancer *discoDancer) override;
    void exit(DiscoDancer *discoDancer) override;
};

class DiscoDancerOn : public DiscoDancerState
{
public:
    void enter(DiscoDancer *discoDancer) override;
    void toggle(DiscoDancer *discoDancer) override;
    void exit(DiscoDancer *discoDancer) override;
};

class DiscoDancerBlinking : public DiscoDancerState, public DiscoDancerInteractiveState
{
public:
    void enter(DiscoDancer *discoDancer) override;
    void toggle(DiscoDancer *discoDancer) override;
    void exit(DiscoDancer *discoDancer) override;
    void actingSwap(DiscoDancer *discoDancer) override;
};

class DiscoDancerWave : public DiscoDancerState, public DiscoDancerInteractiveState
{
public:
    void enter(DiscoDancer *discoDancer) override;
    void toggle(DiscoDancer *discoDancer) override;
    void exit(DiscoDancer *discoDancer) override;
    void actingSwap(DiscoDancer *discoDancer) override;
};

class DiscoDancerPin : public DiscoDancerState
{
public:
    void enter(DiscoDancer *discoDancer) override;
    void toggle(DiscoDancer *discoDancer) override;
    void exit(DiscoDancer *discoDancer) override;
};

class DiscoDancerConverge : public DiscoDancerState, public DiscoDancerInteractiveState {
    public:
    void enter(DiscoDancer *discoDancer) override;
    void toggle(DiscoDancer *discoDancer) override;
    void exit(DiscoDancer *discoDancer) override;
    void actingSwap(DiscoDancer *discoDancer) override;
};

class DiscoDancerDiverge : public DiscoDancerState, public DiscoDancerInteractiveState {
    public:
    void enter(DiscoDancer *discoDancer) override;
    void toggle(DiscoDancer *discoDancer) override;
    void exit(DiscoDancer *discoDancer) override;
    void actingSwap(DiscoDancer *discoDancer) override;
};