#pragma once
#include "Line.h"
#include <string>
#include <vector>

class Maker
{
private:
    std::string brand_name{};
    std::vector<Line> lines{};

public:
    Maker(std::string brand_name);
    auto add_line(Line line) -> int;
    auto print_lines() -> void;
    auto print_all_meters() -> void;
    auto get_maker_name() -> std::string
    {
        return brand_name;
    }
};