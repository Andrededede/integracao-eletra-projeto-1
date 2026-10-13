#pragma once

#include "Apolo.h"
#include "Ares.h"
#include "Cronos.h"
#include "Meter.h"
#include "Zeus.h"
#include <unordered_map>

class MeterFactory
{
private:
    std::unordered_map<Line, std::unique_ptr<Meter>> prototypes;

public:
    MeterFactory();
    auto create_meter(Line line) -> std::unique_ptr<Meter>;
};