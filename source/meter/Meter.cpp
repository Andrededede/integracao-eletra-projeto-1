#include "../../include/meter/Meter.h"
#include <iostream>
#include <string>

int Meter::ID = 0;

Meter::Meter(std::string meter_name, MeterType meter_type, Client client, Line line, float phase1, std::optional<float> phase2,
             std::optional<float> phase3)
    : id(++ID)
    , meter_name(meter_name)
    , meter_type(meter_type)
    , client(client)
    , line(line)
    , phase1(phase1)
    , phase2(phase2)
    , phase3(phase3)
{
}

Meter::Meter(int id, std::string meter_name, MeterType meter_type, Client client, Line line, float phase1, std::optional<float> phase2,
             std::optional<float> phase3)
    : id(id)
    , meter_name(meter_name)
    , meter_type(meter_type)
    , client(client)
    , line(line)
    , phase1(phase1)
    , phase2(phase2)
    , phase3(phase3)
{
}

Meter::Meter(Meter &outro)
    : id(++ID)
    , meter_name(outro.meter_name)
    , meter_type(outro.meter_type)
    , client(outro.client)
    , line(outro.line)
{
}

auto Meter::get_meter_as_row() -> std::array<std::string, 5>
{
    return {std::to_string(id), meter_name, meter_type_enum_to_string(meter_type).value_or("UNKNOWN"), line_enum_to_string(line).value_or("UNKNOWN"),
            client_enum_to_string(client).value_or("UNKNOWN")};
}

auto meter_type_enum_to_string(MeterType type) -> std::optional<std::string>
{
    switch (type)
    {
    case MeterType::SINGLE_PHASE:
        return "SINGLE_PHASE";
    case MeterType::THREE_PHASE:
        return "THREE_PHASE";
    default:
        return std::nullopt;
    }
}

auto line_enum_to_string(Line line) -> std::optional<std::string>
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
        return std::nullopt;
    }
}

auto client_enum_to_string(Client client) -> std::optional<std::string>
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
        return std::nullopt;
    }
}