#pragma once

#include "Meter.h"

class Cronos : public Meter
{
public:
    Cronos(std::string meter_name, MeterType meter_type, Client client);
    auto Clone() -> std::unique_ptr<Meter> const override;
};