#pragma once
#include "Meter.h"
#include <string>
#include <vector>

class Line
{
private:
    std::string lineName{};
    std::vector<Meter> meters{};

public:
    Line(std::string lineName);
    auto addMeter(Meter meter) -> int;
    auto printLineMeters() -> void;
    auto getLineName() -> std::string
    {
        return lineName;
    }
};