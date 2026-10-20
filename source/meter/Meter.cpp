#include "meter/Meter.h"
#include <iostream>
#include <string>

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

auto BuilderMeter::Reset() -> void
{
    meter = Meter();
}

auto BuilderMeter::set_id(int id) -> BuilderMeter &
{
    meter.set_id(id);
    return *this;
}
auto BuilderMeter::set_meter_name(std::string name) -> BuilderMeter &
{
    meter.set_meter_name(name);
    return *this;
}
auto BuilderMeter::set_meter_type(MeterType type) -> BuilderMeter &
{
    meter.set_meter_type(type);
    return *this;
}
auto BuilderMeter::set_client(Client client) -> BuilderMeter &
{
    meter.set_client(client);
    return *this;
}
auto BuilderMeter::set_line(Line line) -> BuilderMeter &
{
    meter.set_line(line);
    return *this;
}
auto BuilderMeter::set_phase1(float phase1) -> BuilderMeter &
{
    meter.set_phase1(phase1);
    return *this;
}
auto BuilderMeter::set_phase2(std::optional<float> phase2) -> BuilderMeter &
{
    meter.set_phase2(phase2);
    return *this;
}
auto BuilderMeter::set_phase3(std::optional<float> phase3) -> BuilderMeter &
{
    meter.set_phase3(phase3);
    return *this;
}
auto BuilderMeter::build() -> std::unique_ptr<Meter>
{
    std::unique_ptr<Meter> built_meter = std::make_unique<Meter>(meter);
    this->Reset();
    return built_meter;
}