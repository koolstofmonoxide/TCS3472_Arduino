#ifndef TCS3472_ENUM_H
#define TCS3472_ENUM_H

enum COMMAND
{
    ADDRESS = 0X29,

    COMMAND_ = 0x80,
    ENABLE = 0x00,
    ATIME = 0x01,
    WTIME = 0x03,
    AILTL = 0x04,
    AILTH = 0x05,
    AIHTL = 0X06,
    AIHTH = 0X07,
    PERS = 0X0C,
    CONFIG = 0X0D,
    CONTROL = 0X0F,
    ID = 0X12,
    STATUS = 0X13,
    CDATAL = 0X14,
    CDATAH = 0X15,
    RDATAL = 0X16,
    RDATAH = 0X17,
    GDATAL = 0X18,
    GDATAH = 0X19,
    BDATAL = 0X1A,
    BDATAH = 0X1B,

    ENABLE_PON = 0X01,
    ENABLE_AEN = 0X03,
    SET_ATIME = 0xF6
};

#endif