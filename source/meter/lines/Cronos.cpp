#include "../../../include/meter/lines/Cronos.h"

Cronos::Cronos(std::string meter_name, MeterType meter_type, Client client)
    : Meter(meter_name, meter_type, client, Line::CRONOS)
{
}

auto Cronos::Clone() -> std::unique_ptr<Meter> const
{
    return std::make_unique<Cronos>(*this);
}