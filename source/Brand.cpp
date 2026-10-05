#include "../include/Brand.h"
#include "../include/Brand.h"


Brand::Brand(std::string brandName) : brandName(brandName) {}

auto Brand::addLine(Line line) -> void {
    lines.push_back(line);
}

auto Brand::printLines() -> void {
    for (Line line : lines) {
        line.printLine();
    }
}