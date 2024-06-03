#include <Wire.h>
#include "TCS3472.h"

TCS3472 colorSensor;

void setup()
{
    Serial.begin(9600);
  
    if (colorSensor.begin()) {
        Serial.println("TCS3472 sensor started");
    } else {
        Serial.println("Failed to start TCS3472 sensor");
    }
}

void loop()
{
    uint16_t r, g, b;
    colorSensor.getRGB(r, g, b);

    Serial.print("R: ");
    Serial.print(r);
    Serial.print(" G: ");
    Serial.print(g);
    Serial.print(" B: ");
    Serial.println(b);

    delay(1000);
}
