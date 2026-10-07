#include "../include/Meter.h"
#include "catch.hpp"

TEST_CASE("Meter names are returned correctly", "[meter]")
{
    Meter meter("Test Meter");
    REQUIRE(meter.getMeterName() == "Test Meter");
}