#include "../../../include/meter/lines/Cronos.h"

Cronos::Cronos(std::string meter_name, MeterType meter_type, Client client, float phase1, std::optional<float> phase2, std::optional<float> phase3)
    : Meter(meter_name, meter_type, client, Line::CRONOS, phase1, phase2, phase3)
{
}

auto Cronos::Clone() -> std::unique_ptr<Meter> const
{
    return std::make_unique<Cronos>(*this);
}