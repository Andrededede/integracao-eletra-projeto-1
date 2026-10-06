#pragma once
#include "Line.h"
#include <string>
#include <vector>


class Maker {
private:
  std::string brandName{};
  std::vector<Line> lines{};

public:
  Maker(std::string brandName);
  auto addLine(Line line) -> void;
  auto printLines() -> void;
  auto printAllMeters() -> void;
  auto getMakerName() -> std::string { return brandName; }
};