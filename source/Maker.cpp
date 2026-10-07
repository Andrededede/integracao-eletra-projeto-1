#include "../include/Maker.h"
#include <iostream>

Maker::Maker(std::string brandName)
    : brandName(brandName)
{
}

auto Maker::addLine(Line line) -> int
{
    auto it = std::find_if(lines.begin(), lines.end(), [&line](Line &l) { return l.getLineName() == line.getLineName(); });

    if (it == lines.end())
    {
        lines.push_back(line);
        return 0;
    }
    else
    {
        return 1;
    }
}

auto Maker::printLines() -> void
{
    for (Line line : lines)
    {
        std::cout << line.getLineName() << std::endl;
    }
}

auto Maker::printAllMeters() -> void
{
    for (Line line : lines)
    {
        line.printLineMeters();
    }
}