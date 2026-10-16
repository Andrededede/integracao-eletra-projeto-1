#pragma once

#include "Meter.h"

class Cronos : public Meter
{
public:
    Cronos(std::string meter_name, MeterType meter_type, Client client, float phase1, std::optional<float> phase2 = std::nullopt,
           std::optional<float> phase3 = std::nullopt);
    auto Clone() -> std::unique_ptr<Meter> const override;
};