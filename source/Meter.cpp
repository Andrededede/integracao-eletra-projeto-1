#include "../include/Meter.h"
#include <iostream>
#include <string>

Meter::Meter(std::string meterName)
    : meterName(meterName)
{
}

auto Meter::printName() -> void
{
    std::cout << meterName << " ";
}