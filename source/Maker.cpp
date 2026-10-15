#include "../include/Maker.h"
#include <iostream>

Maker::Maker(std::string maker_name)
    : maker_name(maker_name)
{
}

auto Maker::add_meter(std::unique_ptr<Meter> meter) -> bool
{
    auto it = std::find_if(meters.begin(), meters.end(), [&meter](const auto &m) {
        return ((m->get_line() == meter->get_line()) && (m->get_meter_name() == meter->get_meter_name())) || (m->get_id() == meter->get_id());
    });
    if (it == meters.end())
    {
        meters.push_back(std::move(meter));
        return false;
    }

    return true;
}

auto Maker::remove_meter(int id) -> bool
{
    auto it = std::find_if(meters.begin(), meters.end(), [id](const auto &m) { return m->get_id() == id; });
    if (it != meters.end())
    {
        meters.erase(it);
        return false;
    }

    return true;
}

auto Maker::get_lines() -> std::map<Line, std::string>
{
    std::map<Line, std::string> line_names;

    for (const auto &meter : meters)
    {
        line_names.insert({meter->get_line(), line_enum_to_string(meter->get_line())});
    }

    return line_names;
}

auto Maker::get_line_meters_rows(const Line &line) -> std::vector<Table::row_t>
{
    std::vector<Table::row_t> result;
    for (const auto &meter : meters)
    {
        if (meter->get_line() == line)
        {
            result.push_back(meter->get_meter_as_row());
        }
    }
    return result;
}

auto Maker::get_meter_line(int id) -> std::string
{
    auto it = std::find_if(meters.begin(), meters.end(), [id](const auto &m) { return m->get_id() == id; });
    if (it != meters.end())
    {
        return line_enum_to_string((*it)->get_line());
    }
    return "";
}

auto Maker::get_meter_type(int id) -> std::string
{
    auto it = std::find_if(meters.begin(), meters.end(), [id](const auto &m) { return m->get_id() == id; });
    if (it != meters.end())
    {
        return meter_type_enum_to_string((*it)->get_meter_type());
    }
    return "";
}

auto Maker::get_all_meters_rows() -> std::vector<Table::row_t>
{
    std::vector<Table::row_t> result;
    for (const auto &meter : meters)
    {
        Table::row_t row = meter->get_meter_as_row();
        result.push_back(row);
    }
    return result;
}