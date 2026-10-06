#include "../include/Meter.h"
#include <iostream>
#include <string>

Meter::Meter(std::string meterName) : meterName(meterName) {}

void Meter::printName() { std::cout << meterName << " "; }