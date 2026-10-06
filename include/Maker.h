#pragma once
#include <string>
#include <vector>
#include "Line.h"

class Maker
{
private:
    std::string brandName{};
    std::vector<Line> lines{};
public:
    Maker(std::string brandName);
    auto addLine(Line line) -> void;
    auto printLines() -> void;
    auto getMakerName() -> std::string { return brandName; }
};