#include "../include/Maker.h"
#include "catch.hpp"

TEST_CASE("Maker names are returned correctly", "[maker]")
{
    Maker maker("Test Maker");
    REQUIRE(maker.getMakerName() == "Test Maker");
}

TEST_CASE("Lines can be added to a Maker correctly", "[maker]")
{
    Maker maker("Test Maker");
    Line line1("Line 1");
    Line line2("Line 2");

    REQUIRE(maker.addLine(line1) == 0);
    REQUIRE(maker.addLine(line2) == 0);
    REQUIRE(maker.addLine(line1) == 1);
}