#pragma once
#include "Meter.h"
#include <string>
#include <vector>

class Maker
{
private:
    std::string brand_name{};
    std::vector<Meter> meters{};

public:
    Maker(std::string brand_name);
    auto add_meter(Meter meter) -> int;
    auto print_lines() -> int;
    auto print_line_meters(Line line) -> void;
    auto print_all_meters() -> void;
    auto get_maker_name() -> std::string
    {
        return brand_name;
    }
};