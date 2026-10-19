#include "../include/Maker.h"
#include <iostream>

Maker::Maker(std::string maker_name)
    : maker_name(maker_name)
{
}

auto get_next_meter_id() -> int
{
    return next_meter_id++;
}

auto Maker::add_meter(std::unique_ptr<Meter> meter) -> bool
{
    auto it = std::find_if(meters.begin(), meters.end(), [&meter](const std::unique_ptr<Meter> &m) { return *meter == *m; });

    if (it == meters.end())
    {
        meters.push_back(std::move(meter));
        return true;
    }

    return false;
}

auto Maker::remove_meter(int id) -> bool
{
    auto it = std::find_if(meters.begin(), meters.end(), [id](const auto &m) { return m->get_id() == id; });
    if (it != meters.end())
    {
        meters.erase(it);
        return true;
    }

    return false;
}

auto Maker::get_lines() -> std::map<Line, std::string>
{
    std::map<Line, std::string> line_names;

    for (const auto &meter : meters)
    {
        line_names.insert({meter->get_line(), line_enum_to_string(meter->get_line()).value_or("UNKNOWN")});
    }

    return line_names;
}

auto Maker::get_line_meters_rows(const Line &line) -> std::vector<row_t>
{
    std::vector<row_t> result;
    for (const auto &meter : meters)
    {
        if (meter->get_line() == line)
        {
            result.push_back(meter->get_meter_as_row());
        }
    }
    return result;
}

auto Maker::get_meter_line(int id) -> std::optional<std::string>
{
    auto it = std::find_if(meters.begin(), meters.end(), [id](const auto &m) { return m->get_id() == id; });
    if (it != meters.end())
    {
        return line_enum_to_string((*it)->get_line());
    }
    return std::nullopt;
}

auto Maker::get_meter_type(int id) -> std::optional<std::string>
{
    auto it = std::find_if(meters.begin(), meters.end(), [id](const auto &m) { return m->get_id() == id; });
    if (it != meters.end())
    {
        return meter_type_enum_to_string((*it)->get_meter_type());
    }
    return std::nullopt;
}

auto Maker::get_meter_phases(int id) -> std::vector<float>
{
    auto it = std::find_if(meters.begin(), meters.end(), [id](const auto &m) { return m->get_id() == id; });
    if (it != meters.end())
    {
        std::vector<float> phases;
        phases.push_back((*it)->get_phase1());
        if ((*it)->get_phase2().has_value())
        {
            phases.push_back((*it)->get_phase2().value());
        }
        if ((*it)->get_phase3().has_value())
        {
            phases.push_back((*it)->get_phase3().value());
        }
        return phases;
    }
    return {};
}

auto Maker::get_all_meters_rows() -> std::vector<row_t>
{
    std::vector<row_t> result;
    for (const auto &meter : meters)
    {
        row_t row = meter->get_meter_as_row();
        result.push_back(row);
    }
    return result;
}