#pragma once

#include <string>

class Meter {
private:
  std::string meterName{};

public:
  Meter(std::string meterName);
  auto printName() -> void;
  auto getMeterName() -> std::string { return meterName; }
};
