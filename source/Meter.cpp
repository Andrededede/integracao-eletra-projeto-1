#include "../include/Meter.h"
#include <iostream>
#include <string>

int Meter::ID = 0;

Meter::Meter(std::string meter_name, MeterType meter_type, Client client, Line line)
    : id(++ID)
    , meter_name(meter_name)
    , meter_type(meter_type)
    , client(client)
    , line(line)
{
}

auto Meter::print_meter() -> void
{
    std::cout << line_enum_to_string(line) << " " << meter_name << std::endl
              << "  ID: " << id << std::endl
              << "  Tipo: " << meter_type_enum_to_string(meter_type) << std::endl
              << "  Cliente: " << client_enum_to_string(client) << std::endl;
}

auto meter_type_enum_to_string(MeterType type) -> std::string
{
    switch (type)
    {
    case MeterType::SINGLE_PHASE:
        return "SINGLE_PHASE";
    case MeterType::THREE_PHASE:
        return "THREE_PHASE";
    default:
        return "UNKNOWN";
    }
}

auto line_enum_to_string(Line line) -> std::string
{
    switch (line)
    {
    case Line::APOLO:
        return "APOLO";
    case Line::CRONOS:
        return "CRONOS";
    case Line::ARES:
        return "ARES";
    case Line::ZEUS:
        return "ZEUS";
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