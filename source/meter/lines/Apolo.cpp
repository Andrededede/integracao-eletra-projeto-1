#include "../../../include/meter/lines/Apolo.h"

Apolo::Apolo(std::string meter_name, MeterType meter_type, Client client)
    : Meter(meter_name, meter_type, client, Line::APOLO)
{
}

auto Apolo::Clone() -> std::unique_ptr<Meter> const
{
    return std::make_unique<Apolo>(*this);
}