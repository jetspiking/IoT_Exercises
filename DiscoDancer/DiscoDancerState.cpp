#include "DiscoDancerState.h"

void DiscoDancerOff::enter(DiscoDancer *discoDancer)
{
    discoDancer->getDiscoDancerWriter()->enterOff(discoDancer);
}

void DiscoDancerOff::toggle(DiscoDancer *discoDancer)
{
    discoDancer->getDiscoDancerWriter()->toggleOff(discoDancer);
    discoDancer->setDiscoDancerState(std::make_shared<DiscoDancerOn>());
}

void DiscoDancerOff::exit(DiscoDancer *discoDancer)
{
    discoDancer->getDiscoDancerWriter()->exitOff(discoDancer);
}

void DiscoDancerOn::enter(DiscoDancer *discoDancer)
{
    discoDancer->getDiscoDancerWriter()->enterOn(discoDancer);
}

void DiscoDancerOn::toggle(DiscoDancer *discoDancer)
{
    discoDancer->getDiscoDancerWriter()->toggleOn(discoDancer);
    discoDancer->setDiscoDancerState(std::make_shared<DiscoDancerBlinking>());
}

void DiscoDancerOn::exit(DiscoDancer *discoDancer)
{
    discoDancer->getDiscoDancerWriter()->exitOn(discoDancer);
}

void DiscoDancerBlinking::enter(DiscoDancer *discoDancer)
{
    discoDancer->getDiscoDancerWriter()->enterBlinking(discoDancer);
}

void DiscoDancerBlinking::toggle(DiscoDancer *discoDancer)
{
    discoDancer->getDiscoDancerWriter()->toggleBlinking(discoDancer);
    discoDancer->setDiscoDancerState(std::make_shared<DiscoDancerWave>());
}

void DiscoDancerBlinking::exit(DiscoDancer *discoDancer)
{
    discoDancer->getDiscoDancerWriter()->exitBlinking(discoDancer);
}

void DiscoDancerBlinking::actingSwap(DiscoDancer *discoDancer)
{
    discoDancer->getDiscoDancerWriter()->actingSwapBlinking(discoDancer);
}

void DiscoDancerWave::enter(DiscoDancer *discoDancer)
{
    discoDancer->getDiscoDancerWriter()->enterWave(discoDancer);
}

void DiscoDancerWave::toggle(DiscoDancer *discoDancer)
{
    discoDancer->getDiscoDancerWriter()->toggleWave(discoDancer);
    discoDancer->setDiscoDancerState(std::make_shared<DiscoDancerPin>());
}

void DiscoDancerWave::exit(DiscoDancer *discoDancer)
{
    discoDancer->getDiscoDancerWriter()->exitWave(discoDancer);
}

void DiscoDancerWave::actingSwap(DiscoDancer *discoDancer)
{
    discoDancer->getDiscoDancerWriter()->actingSwapWave(discoDancer);
}

void DiscoDancerPin::enter(DiscoDancer *discoDancer)
{
    discoDancer->getDiscoDancerWriter()->enterPin(discoDancer);
}

void DiscoDancerPin::toggle(DiscoDancer *discoDancer)
{
    discoDancer->getDiscoDancerWriter()->togglePin(discoDancer);
    discoDancer->setDiscoDancerState(std::make_shared<DiscoDancerConverge>());
}

void DiscoDancerPin::exit(DiscoDancer *discoDancer)
{
    discoDancer->getDiscoDancerWriter()->exitPin(discoDancer);
}

void DiscoDancerConverge::enter(DiscoDancer *discoDancer) 
{
    discoDancer->getDiscoDancerWriter()->enterConverge(discoDancer);
}

void DiscoDancerConverge::toggle(DiscoDancer* discoDancer) {
    discoDancer->getDiscoDancerWriter()->toggleConverge(discoDancer);
    discoDancer->setDiscoDancerState(std::make_shared<DiscoDancerDiverge>());
}

void DiscoDancerConverge::exit(DiscoDancer* discoDancer) {
    discoDancer->getDiscoDancerWriter()->exitConverge(discoDancer);
}

void DiscoDancerConverge::actingSwap(DiscoDancer* discoDancer) {
    discoDancer->getDiscoDancerWriter()->actingSwapConverge(discoDancer);
}

void DiscoDancerDiverge::enter(DiscoDancer* discoDancer) {
    discoDancer->getDiscoDancerWriter()->enterDiverge(discoDancer);
}

void DiscoDancerDiverge::toggle(DiscoDancer* discoDancer) {
    discoDancer->getDiscoDancerWriter()->toggleDiverge(discoDancer);
    discoDancer->setDiscoDancerState(std::make_shared<DiscoDancerOn>());
}

void DiscoDancerDiverge::exit(DiscoDancer* discoDancer) {
    discoDancer->getDiscoDancerWriter()->exitDiverge(discoDancer);
}

void DiscoDancerDiverge::actingSwap(DiscoDancer* discoDancer) {
    discoDancer->getDiscoDancerWriter()->actingSwapDiverge(discoDancer);
}