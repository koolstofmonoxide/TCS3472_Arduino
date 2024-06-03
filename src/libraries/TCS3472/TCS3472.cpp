#include "TCS3472.h"

TCS3472::TCS3472() {}

void TCS3472::getRGB(uint16_t &r, uint16_t &g, uint16_t &b) // Lezen van de RGB values
{
    r = readFromSensor(0x16);
    g = readFromSensor(0x18);
    b = readFromSensor(0x1A);
}

void TCS3472::writeToSensor(uint8_t reg, uint8_t value) // Schrijven naar sensor
{
    Wire.beginTransmission(_address);
    Wire.write(0x80 | reg);
    Wire.write(value);
    Wire.endTransmission();
}

uint16_t TCS3472::readFromSensor(uint8_t reg) // Lezen van sensor
{
    uint16_t value;
    Wire.beginTransmission(_address);
    Wire.write(0x80 | reg);
    Wire.endTransmission();

    Wire.requestFrom(_address, (uint8_t)2);
    value = Wire.read();
    value |= (Wire.read() << 8);

    return value;
}

bool TCS3472::begin(uint8_t address) // Starten van de sensor
{
    _address = address;
    Wire.begin();

    Wire.beginTransmission(_address);
    if (Wire.endTransmission() != 0)
    {
        return false;
    }

    enable();
    writeToSensor(0x01, 0xEB);
    writeToSensor(0x0F, 0x00);

    return true;
}

void TCS3472::enable() // Aanzetten van de sensor
{
    writeToSensor(0x00, 0X01);
    delay(3);
    writeToSensor(0x00, 0X01 | 0X02);
}