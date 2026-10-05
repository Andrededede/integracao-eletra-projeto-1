#pragma once
#include <string>
#include "Meter.h"
#include <vector>

class Line
{
private:
    std::string lineName{};
    std::vector<Meter> meters{};
public:
    Line(std::string lineName);
    auto addMeter(Meter meter) -> void;
    auto printLine() -> void;
    auto getLineName() -> std::string { return lineName; }
};