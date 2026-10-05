#pragma once
#include <string>
#include <vector>
#include "Line.h"

class Brand
{
private:
    std::string brandName{};
    std::vector<Line> lines{};
public:
    Brand(std::string brandName);
    auto addLine(Line line) -> void;
    auto printLines() -> void;
    auto getBrandName() -> std::string { return brandName; }
};