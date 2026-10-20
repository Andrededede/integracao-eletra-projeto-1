#pragma once
#include "Table.h"
#include "meter/Meter.h"
#include <map>
#include <memory>
#include <string>
#include <vector>

static int next_meter_id = 1;
auto get_next_meter_id() -> int;

class Maker
{
private:
    std::string maker_name{};
    std::vector<std::unique_ptr<Meter>> meters{};

public:
    Maker(std::string maker_name);
    auto add_meter(std::unique_ptr<Meter> meter) -> bool;
    auto remove_meter(int id) -> bool;
    auto get_lines() -> std::map<Line, std::string>;
    auto get_line_meters_rows(const Line &line) -> std::vector<row_t>;
    auto get_all_meters_rows() -> std::vector<row_t>;
    auto get_meter_line(int id) -> std::optional<std::string>;
    auto get_meter_type(int id) -> std::optional<std::string>;
    auto get_meter_phases(int id) -> std::vector<float>;
    auto get_maker_name() -> std::string
    {
        return maker_name;
    }
};