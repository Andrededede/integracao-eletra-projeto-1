#include "../include/Line.h"
#include "catch.hpp"

TEST_CASE("Line names are returned correctly", "[line]")
{
    Line line("Test Line");
    REQUIRE(line.getLineName() == "Test Line");
}

TEST_CASE("Meters can be added to a Line correctly", "[line]")
{
    Line line("Test Line");
    Meter meter1("Meter 1");
    Meter meter2("Meter 2");

    REQUIRE(line.addMeter(meter1) == 0);
    REQUIRE(line.addMeter(meter2) == 0);
    REQUIRE(line.addMeter(meter1) == 1);
}