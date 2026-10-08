#include "../include/Maker.h"
#include <iostream>
#include <map>

Maker::Maker(std::string brand_name)
    : brand_name(brand_name)
{
}

auto Maker::add_meter(Meter meter) -> int
{
    auto it = std::find_if(meters.begin(), meters.end(),
                           [&meter](Meter &m) { return (m.get_meter_name() == meter.get_meter_name()) && (m.get_id() == meter.get_id()); });

    if (it == meters.end())
    {
        meters.push_back(meter);
        return 0;
    }
    else
    {
        return 1;
    }
}

auto Maker::print_lines() -> int
{
    std::map<Line, std::string> line_names;

    for (auto meter : meters)
    {
        line_names[meter.get_line()] = line_enum_to_string(meter.get_line());
    }

    if (line_names.empty())
    {
        std::cout << "Nenhuma linha disponível." << std::endl;
        return 1;
    }
    for (auto line_pair : line_names)
    {
        std::cout << line_pair.second << std::endl;
    }
    return 0;
}

auto Maker::print_line_meters(Line line) -> void
{
    for (auto meter : meters)
    {
        if (meter.get_line() == line)
        {
            meter.print_meter();
        }
    }
}

auto Maker::print_all_meters() -> void
{
    for (auto meter : meters)
    {
        meter.print_meter();
    }
}