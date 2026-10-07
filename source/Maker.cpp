#include "../include/Maker.h"
#include <iostream>

Maker::Maker(std::string brand_name)
    : brand_name(brand_name)
{
}

auto Maker::add_line(Line line) -> int
{
    auto it = std::find_if(lines.begin(), lines.end(), [&line](Line &l) { return l.get_line_name() == line.get_line_name(); });

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

auto Maker::print_lines() -> void
{
    for (Line line : lines)
    {
        std::cout << line.get_line_name() << std::endl;
    }
}

auto Maker::print_all_meters() -> void
{
    for (Line line : lines)
    {
        line.print_line_meters();
    }
}