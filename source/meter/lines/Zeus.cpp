#include "../../../include/meter/lines/Zeus.h"

Zeus::Zeus(std::string meter_name, MeterType meter_type, Client client, float phase1, std::optional<float> phase2, std::optional<float> phase3)
    : Meter(meter_name, meter_type, client, Line::ZEUS, phase1, phase2, phase3)
{
}

Zeus::Zeus(int id)
    : Meter(id, "Default Zeus Single Phase", MeterType::SINGLE_PHASE, Client::EDP, Line::ZEUS, 220.0f)
{
}

auto Zeus::Clone() -> std::unique_ptr<Meter> const
{
    return std::make_unique<Zeus>(*this);
}