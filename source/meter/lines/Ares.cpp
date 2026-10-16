#include "../../../include/meter/lines/Ares.h"

Ares::Ares(std::string meter_name, MeterType meter_type, Client client, float phase1, std::optional<float> phase2, std::optional<float> phase3)
    : Meter(meter_name, meter_type, client, Line::ARES, phase1, phase2, phase3)
{
}

auto Ares::Clone() -> std::unique_ptr<Meter> const
{
    return std::make_unique<Ares>(*this);
}