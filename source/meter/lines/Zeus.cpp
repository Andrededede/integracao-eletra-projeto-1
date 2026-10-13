#include "../../../include/meter/lines/Zeus.h"

Zeus::Zeus(std::string meter_name, MeterType meter_type, Client client)
    : Meter(meter_name, meter_type, client, Line::ZEUS)
{
}

auto Zeus::Clone() -> std::unique_ptr<Meter> const
{
    return std::make_unique<Zeus>(*this);
}