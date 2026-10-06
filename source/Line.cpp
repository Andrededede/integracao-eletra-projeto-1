#include "../include/Line.h"
#include "../include/Meter.h"
#include <iostream>

Line::Line(std::string lineName) : lineName(lineName) {}

auto Line::addMeter(Meter meter) -> void { meters.push_back(meter); }

auto Line::printLineMeters() -> void {
  for (Meter meter : meters) {
    std::cout << lineName << " " << meter.getMeterName() << std::endl;
  }
}