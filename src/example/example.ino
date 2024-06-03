#include <Wire.h>
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "ClosestColor.h"
#include "TCS3472.h"

TCS3472 colorSensor;
ClosestColor closestColorFinder;
LiquidCrystal_I2C lcd(0x27, 16, 2);

struct TargetColor {
    const char* name;
};

TargetColor colors[] = {
    {"Red"},
    {"Lime"},
    {"Blue"},
    {"Yellow"},
    {"Cyan"},
};

const int numColors = sizeof(colors) / sizeof(TargetColor);
TargetColor targetColor;

void setup() {
    Serial.begin(9600);
    if (!colorSensor.begin()) {
        Serial.println("Failed to start sensor.");
        while (1);
    }

    lcd.init();
    lcd.backlight();

    randomSeed(analogRead(0));
    selectNewColor();
}

void loop() {
    uint16_t r, g, b; 
    colorSensor.getRGB(r, g, b);

    String detectedColor = closestColorFinder.getClosestColor(r, g, b);
    Serial.println(detectedColor);

    if (detectedColor == targetColor.name) {
        delay(1000);
        selectNewColor();
    }

    delay(500);
}

void selectNewColor() {
    targetColor = colors[random(0, numColors)];

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Show me: ");
    lcd.print(targetColor.name);

    Serial.print("New target color: ");
    Serial.println(targetColor.name);
}
