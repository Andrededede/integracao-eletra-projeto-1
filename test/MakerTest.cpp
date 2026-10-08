#include "../include/Maker.h"
#include "catch.hpp"

TEST_CASE("Maker names are returned correctly", "[maker]")
{
    Maker maker("Test Maker");
    REQUIRE(maker.get_maker_name() == "Test Maker");
}

TEST_CASE("Meters can be added to a Maker correctly", "[maker]")
{
    Maker maker("Test Maker");
    Meter meter1("Meter 1", MeterType::SINGLE_PHASE, Client::EDP, Line::APOLO);
    Meter meter2("Meter 2", MeterType::THREE_PHASE, Client::CEMIG, Line::CRONOS);

    SECTION("Adding a new meter returns 0")
    {
        REQUIRE(maker.add_meter(meter1) == 0);
        REQUIRE(maker.add_meter(meter2) == 0);
    }

    SECTION("Adding a duplicate meter returns 1")
    {
        maker.add_meter(meter1);
        REQUIRE(maker.add_meter(meter1) == 1);
    }
}