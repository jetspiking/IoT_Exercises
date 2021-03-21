#include <Arduino.h>

const char* text = "Hey there! this is wireless communication with XBEE-modules in AT-MODE!";

void setup() 
{ 
  Serial.begin(9600);
}

void loop() 
{
  for (int i = 0; i < String(text).length(); i++) 
  {
    Serial.write(text[i]);
  }
  Serial.write('\n');
  delay(5000);
}