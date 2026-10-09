#include "../include/Maker.h"
#include <iostream>
#include <map>

Maker::Maker(std::string maker_name)
    : maker_name(maker_name)
{
}

auto Maker::add_meter(std::unique_ptr<Meter> meter) -> bool
{
    auto it = std::find_if(meters.begin(), meters.end(), [&meter](const std::unique_ptr<Meter> &m) {
        return (m->get_meter_name() == meter->get_meter_name()) && (m->get_id() == meter->get_id());
    });
    if (it == meters.end())
    {
        meters.push_back(std::move(meter));
        return false;
    }

    return true;
}

auto Maker::print_lines() -> bool
{
    std::map<Line, std::string> line_names;

    for (auto &meter : meters)
    {
        line_names.insert({meter->get_line(), line_enum_to_string(meter->get_line())});
    }

    if (line_names.empty())
    {
        std::cout << "Nenhuma linha disponível." << std::endl;
        return true;
    }
    for (auto line_pair : line_names)
    {
        std::cout << line_pair.second << std::endl;
    }
    return false;
}

auto Maker::print_line_meters(Line line) -> bool
{
    bool not_found = true;
    for (auto &meter : meters)
    {
        if (meter->get_line() == line)
        {
            meter->print_meter();
            not_found = false;
        }
    }
    if (not_found)
    {
        std::cout << "Nenhum medidor encontrado para a linha " << line_enum_to_string(line) << "." << std::endl;
    }
    return not_found;
}

auto Maker::print_all_meters() -> void
{
    for (auto &meter : meters)
    {
        meter->print_meter();
    }
}