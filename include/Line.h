#pragma once
#include "Meter.h"
#include <string>
#include <vector>

class Line
{
private:
    std::string line_name{};
    std::vector<Meter> meters{};

public:
    Line(std::string line_name);
    auto add_meter(Meter meter) -> int;
    auto print_line_meters() -> void;
    auto get_line_name() -> std::string
    {
        return line_name;
    }
};