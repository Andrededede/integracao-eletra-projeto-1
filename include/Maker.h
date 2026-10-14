#pragma once
#include "Meter.h"
#include "Table.h"
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
    auto remove_meter(int id) -> bool;
    auto print_lines() -> bool;
    auto get_line_meters(const Line &line) -> std::vector<Table::row_t>;
    auto get_all_meters() -> std::vector<Table::row_t>;
    auto get_meter_line(int id) -> std::string;
    auto get_meter_type(int id) -> std::string;
    auto get_maker_name() -> std::string
    {
        return maker_name;
    }
};