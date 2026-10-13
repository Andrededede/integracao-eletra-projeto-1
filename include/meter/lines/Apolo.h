#pragma once

#include "Meter.h"

class Apolo : public Meter
{
public:
    Apolo(std::string meter_name, MeterType meter_type, Client client);
    auto Clone() -> std::unique_ptr<Meter> const override;
};