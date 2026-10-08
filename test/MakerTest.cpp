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

TEST_CASE("Maker can print lines correctly", "[maker]")
{
    Maker maker("Test Maker");

    SECTION("Printing lines with no meters returns 1")
    {
        REQUIRE(maker.print_lines() == 1);
    }

    SECTION("Printing lines with meters returns 0")
    {
        maker.add_meter(Meter("Meter 1", MeterType::SINGLE_PHASE, Client::EDP, Line::APOLO));
        maker.add_meter(Meter("Meter 2", MeterType::THREE_PHASE, Client::CEMIG, Line::CRONOS));
        REQUIRE(maker.print_lines() == 0);
    }
}