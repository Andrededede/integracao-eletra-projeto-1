#include "../../../include/meter/lines/Ares.h"

Ares::Ares(std::string meter_name, MeterType meter_type, Client client)
    : Meter(meter_name, meter_type, client, Line::ARES)
{
}

auto Ares::Clone() -> std::unique_ptr<Meter> const
{
    return std::make_unique<Ares>(*this);
}