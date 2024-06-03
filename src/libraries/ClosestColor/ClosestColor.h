#ifndef CLOSESTCOLOR_H
#define CLOSESTCOLOR_H

#include <Arduino.h>

struct Color
{
    int R_, G_, B_;
    String name_;
};

class ClosestColor
{
public:
    ClosestColor();
    String getClosestColor(int r, int g, int b);

private:
    int distanceBetweenToColors(int r1, int g1, int b1, int r2, int g2, int b2);

    static const Color colors[];
};

#endif