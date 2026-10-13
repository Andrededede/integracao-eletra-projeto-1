#pragma once
#include "Meter.h"
#include <memory>
#include <string>
#include <vector>

class Maker
{
private:
    std::string maker_name{};
    std::vector<std::unique_ptr<Meter>> meters{};

public:
    Maker(std::string maker_name);
    auto add_meter(std::unique_ptr<Meter> meter) -> bool;
    auto print_lines() -> bool;
    auto print_line_meters(Line line) -> bool;
    auto print_all_meters() -> void;
    auto get_maker_name() -> std::string
    {
        return maker_name;
    }
};