#pragma once

#include "Meter.h"

class Ares : public Meter
{
public:
    Ares(std::string meter_name, MeterType meter_type, Client client);
    auto Clone() -> std::unique_ptr<Meter> const override;
};