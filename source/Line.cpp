#include "../include/Line.h"
#include "../include/Meter.h"
#include <algorithm>
#include <iostream>

Line::Line(std::string line_name)
    : line_name(line_name)
{
}

auto Line::add_meter(Meter meter) -> int
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

auto Line::print_line_meters() -> void
{
    for (Meter meter : meters)
    {
        std::cout << line_name << " " << meter.get_meter_name() << std::endl
                  << "  ID: " << meter.get_id() << std::endl
                  << "  Tipo: " << meter_type_enum_to_string(meter.get_meter_type()) << std::endl
                  << "  Cliente: " << client_enum_to_string(meter.get_client()) << std::endl;
    }
}