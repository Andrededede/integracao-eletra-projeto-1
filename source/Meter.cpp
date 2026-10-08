#include "../include/Meter.h"
#include <iostream>
#include <string>

int Meter::ID = 0;

Meter::Meter(std::string meter_name, MeterType meter_type, Client client)
    : id(++ID)
    , meter_name(meter_name)
    , meter_type(meter_type)
    , client(client)
{
}

auto Meter::print_name() -> void
{
    std::cout << meter_name << " ";
}

auto meter_type_enum_to_string(MeterType type) -> std::string
{
    switch (type)
    {
    case MeterType::SINGLE_PHASE:
        return "SINGLE_PHASE";
    case MeterType::THREE_PHASE:
        return "THREE_PHASE";
    case MeterType::SINGLE_PHASE_PREPAID:
        return "SINGLE_PHASE_PREPAID";
    case MeterType::THREE_PHASE_PREPAID:
        return "THREE_PHASE_PREPAID";
    default:
        return "UNKNOWN";
    }
}

auto client_enum_to_string(Client client) -> std::string
{
    switch (client)
    {
    case Client::EDP:
        return "EDP";
    case Client::CEMIG:
        return "CEMIG";
    case Client::COELCE:
        return "COELCE";
    case Client::COPEL:
        return "COPEL";
    default:
        return "UNKNOWN";
    }
}