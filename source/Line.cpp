#include "../include/Line.h"
#include "../include/Meter.h"
#include <algorithm>
#include <iostream>

Line::Line(std::string lineName)
    : lineName(lineName)
{
}

auto Line::addMeter(Meter meter) -> int
{
    auto it = std::find_if(meters.begin(), meters.end(), [&meter](Meter &m) { return m.getMeterName() == meter.getMeterName(); });

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

auto Line::printLineMeters() -> void
{
    for (Meter meter : meters)
    {
        std::cout << lineName << " " << meter.getMeterName() << std::endl;
    }
}