#include <string>
#include <iostream>
#include "../include/Meter.h"

Meter::Meter(std::string meterName) : meterName(meterName) {}

void Meter::printName(){
    std::cout << meterName << " ";
}