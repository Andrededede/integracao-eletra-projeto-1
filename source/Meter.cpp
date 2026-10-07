#include "../include/Meter.h"
#include <iostream>
#include <string>

Meter::Meter(int id, std::string meter_name, MeterType meter_type, Client client)
    : id(id)
    , meter_name(meter_name)
    , meter_type(MeterType::SINGLE_PHASE)
    , client(Client::EDP)
{
}

auto Meter::print_name() -> void
{
    std::cout << meter_name << " ";
}