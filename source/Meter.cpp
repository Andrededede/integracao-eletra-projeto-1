#include "../include/Meter.h"
#include <iostream>
#include <string>

Meter::Meter(std::string meter_name)
    : meter_name(meter_name)
{
}

auto Meter::print_name() -> void
{
    std::cout << meter_name << " ";
}