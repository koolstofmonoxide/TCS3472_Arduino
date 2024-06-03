#ifndef TCS3472_H
#define TCS3472_H

#include <Arduino.h>
#include <Wire.h>

class TCS3472 {
public:
    TCS3472();
    /**
     * Starts the TCS3472 color sensor.
     * @return True or False, depending if sensor started succesfully.
    */
    bool begin(uint8_t address = 0x29);

    /**
     * Retrieves the RGB values.
     * @return The RGB-values.
    **/
    void getRGB(uint16_t &r, uint16_t &g, uint16_t &b);

private:
    uint8_t _address;
    void writeToSensor(uint8_t reg, uint8_t value);
    uint16_t readFromSensor(uint8_t reg);
    void enable();
};

#endif