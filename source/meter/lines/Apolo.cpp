#include "../../../include/meter/lines/Apolo.h"

Apolo::Apolo(std::string meter_name, MeterType meter_type, Client client, float phase1, std::optional<float> phase2, std::optional<float> phase3)
    : Meter(meter_name, meter_type, client, Line::APOLO, phase1, phase2, phase3)
{
}

Apolo::Apolo(int id)
    : Meter(id, "Default Apolo Single Phase", MeterType::SINGLE_PHASE, Client::EDP, Line::APOLO, 220.0f)
{
}

auto Apolo::Clone() -> std::unique_ptr<Meter> const
{
    return std::make_unique<Apolo>(*this);
}