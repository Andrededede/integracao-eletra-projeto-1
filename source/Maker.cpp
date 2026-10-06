#include "../include/Maker.h"
#include <iostream>

Maker::Maker(std::string brandName) : brandName(brandName) {}

auto Maker::addLine(Line line) -> void { lines.push_back(line); }

auto Maker::printLines() -> void {
  for (Line line : lines) {
    std::cout << line.getLineName() << std::endl;
  }
}

auto Maker::printAllMeters() -> void {
  for (Line line : lines) {
    line.printLineMeters();
  }
}