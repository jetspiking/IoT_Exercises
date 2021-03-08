#include "DiscoDancerWriter.h"

byte DiscoDancerWriter::pins[8] = {15, 4, 5, 18, 19, 21, 22, 23};

void DiscoDancerWriter::enterOff(DiscoDancer *discoDancer)
{
    for (byte b = 0; b < sizeof(DiscoDancerWriter::pins); b++)
        digitalWrite(DiscoDancerWriter::pins[b], WRITER_LED_OFF);
}

void DiscoDancerWriter::toggleOff(DiscoDancer *discoDancer)
{

}

void DiscoDancerWriter::exitOff(DiscoDancer *discoDancer)
{
    for (byte b = 0; b < sizeof(DiscoDancerWriter::pins); b++)
        digitalWrite(DiscoDancerWriter::pins[b], WRITER_LED_OFF);
}

void DiscoDancerWriter::enterOn(DiscoDancer *discoDancer)
{
    for (byte b = 0; b < sizeof(DiscoDancerWriter::pins); b++)
        digitalWrite(DiscoDancerWriter::pins[b], WRITER_LED_ON);
}

void DiscoDancerWriter::toggleOn(DiscoDancer *discoDancer)
{

}

void DiscoDancerWriter::exitOn(DiscoDancer *discoDancer)
{
}

void DiscoDancerWriter::enterBlinking(DiscoDancer *discoDancer)
{
}

void DiscoDancerWriter::toggleBlinking(DiscoDancer *discoDancer)
{
   
}

void DiscoDancerWriter::exitBlinking(DiscoDancer *discoDancer)
{
    for (byte b = 0; b < sizeof(DiscoDancerWriter::pins); b++)
        digitalWrite(DiscoDancerWriter::pins[b], WRITER_LED_OFF);
}

void DiscoDancerWriter::actingSwapBlinking(DiscoDancer *discoDancer)
{
    static bool blinkStateOn = true;
    for (byte b = 0; b < sizeof(DiscoDancerWriter::pins); b++)
        digitalWrite(DiscoDancerWriter::pins[b], blinkStateOn);
    blinkStateOn = !blinkStateOn;
}

void DiscoDancerWriter::enterPin(DiscoDancer *discoDancer)
{
    digitalWrite(this->singlePin, WRITER_LED_ON);
}

void DiscoDancerWriter::togglePin(DiscoDancer *discoDancer)
{
}

void DiscoDancerWriter::exitPin(DiscoDancer *discoDancer)
{
    for (byte b = 0; b < sizeof(DiscoDancerWriter::pins); b++)
        digitalWrite(DiscoDancerWriter::pins[b], WRITER_LED_OFF);
}

void DiscoDancerWriter::enterWave(DiscoDancer *discoDancer)
{
    for (byte b = 0; b < sizeof(DiscoDancerWriter::pins); b++)
        digitalWrite(DiscoDancerWriter::pins[b], WRITER_LED_OFF);
}

void DiscoDancerWriter::toggleWave(DiscoDancer *discoDancer)
{
}

void DiscoDancerWriter::exitWave(DiscoDancer *discoDancer)
{
    for (byte b = 0; b < sizeof(DiscoDancerWriter::pins); b++)
        digitalWrite(DiscoDancerWriter::pins[b], WRITER_LED_OFF);
}

void DiscoDancerWriter::actingSwapWave(DiscoDancer *discoDancer)
{
    static byte currentPin = 0;
    if (currentPin > 0)
        digitalWrite(DiscoDancerWriter::pins[currentPin - 1], WRITER_LED_OFF);
    else if (currentPin == 0)
        digitalWrite(DiscoDancerWriter::pins[sizeof(DiscoDancerWriter::pins)-1], WRITER_LED_OFF);    
    digitalWrite(DiscoDancerWriter::pins[currentPin], WRITER_LED_ON);
    if ((++currentPin) > sizeof(DiscoDancerWriter::pins)-1)
        currentPin = 0;
}

void DiscoDancerWriter::enterConverge(DiscoDancer *discoDancer)
{
}

void DiscoDancerWriter::toggleConverge(DiscoDancer *discoDancer)
{
}

void DiscoDancerWriter::exitConverge(DiscoDancer *discoDancer)
{
    for (byte b = 0; b < sizeof(DiscoDancerWriter::pins); b++)
        digitalWrite(DiscoDancerWriter::pins[b], WRITER_LED_OFF);
}

void DiscoDancerWriter::actingSwapConverge(DiscoDancer *discoDancer)
{
    static byte currentStepConverge = 0;
    for (byte b = 0; b < sizeof(DiscoDancerWriter::pins); b++)
        digitalWrite(DiscoDancerWriter::pins[b], WRITER_LED_OFF);
    byte maxStep = sizeof(DiscoDancerWriter::pins)/2;
    byte ledLeftToTurnIndex = currentStepConverge;
    byte ledRightToTurnIndex = sizeof(DiscoDancerWriter::pins)-currentStepConverge-1;
    digitalWrite(DiscoDancerWriter::pins[ledLeftToTurnIndex], WRITER_LED_ON);
    digitalWrite(DiscoDancerWriter::pins[ledRightToTurnIndex], WRITER_LED_ON);
    if (++currentStepConverge>maxStep) currentStepConverge=0;
}

void DiscoDancerWriter::enterDiverge(DiscoDancer *discoDancer)
{
}

void DiscoDancerWriter::toggleDiverge(DiscoDancer *discoDancer)
{
}

void DiscoDancerWriter::exitDiverge(DiscoDancer *discoDancer)
{
    for (byte b = 0; b < sizeof(DiscoDancerWriter::pins); b++)
        digitalWrite(DiscoDancerWriter::pins[b], WRITER_LED_OFF);
}

void DiscoDancerWriter::actingSwapDiverge(DiscoDancer *discoDancer)
{
    static byte currentStepDiverge = sizeof(DiscoDancerWriter::pins)/2;
    for (byte b = 0; b < sizeof(DiscoDancerWriter::pins); b++)
        digitalWrite(DiscoDancerWriter::pins[b], WRITER_LED_OFF);
    byte start = sizeof(DiscoDancerWriter::pins)/2;
    byte ledLeftToTurn = currentStepDiverge;
    byte ledRightToTurn = sizeof(DiscoDancerWriter::pins)-currentStepDiverge;
    digitalWrite(DiscoDancerWriter::pins[ledLeftToTurn-1], WRITER_LED_ON);
    digitalWrite(DiscoDancerWriter::pins[ledRightToTurn], WRITER_LED_ON);
    if (--currentStepDiverge<1) currentStepDiverge=start;
}