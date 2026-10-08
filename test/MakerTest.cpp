#include "../include/Maker.h"
#include "catch.hpp"

TEST_CASE("Maker names are returned correctly", "[maker]")
{
    Maker maker("Test Maker");
    CHECK(maker.get_maker_name() == "Test Maker");
}

TEST_CASE("Meters can be added to a Maker correctly", "[maker]")
{
    Maker maker("Test Maker");
    Meter meter1("Meter 1", MeterType::SINGLE_PHASE, Client::EDP, Line::APOLO);
    Meter meter2("Meter 2", MeterType::THREE_PHASE, Client::CEMIG, Line::CRONOS);

    SECTION("Adding a new meter returns 0")
    {
        CHECK_FALSE(maker.add_meter(meter1));
        CHECK_FALSE(maker.add_meter(meter2));
    }

    SECTION("Adding a duplicate meter returns 1")
    {
        maker.add_meter(meter1);
        CHECK(maker.add_meter(meter1));
    }
}

TEST_CASE("Maker can print lines correctly", "[maker]")
{
    Maker maker("Test Maker");

    SECTION("Printing lines with no meters returns 1")
    {
        CHECK(maker.print_lines());
    }

    SECTION("Printing lines with meters returns 0")
    {
        maker.add_meter(Meter("Meter 1", MeterType::SINGLE_PHASE, Client::EDP, Line::APOLO));
        maker.add_meter(Meter("Meter 2", MeterType::THREE_PHASE, Client::CEMIG, Line::CRONOS));
        CHECK_FALSE(maker.print_lines());
    }
}

TEST_CASE("Maker can print line meters correctly", "[maker]")
{
    Maker maker("Test Maker");
    Meter meter1("Meter 1", MeterType::SINGLE_PHASE, Client::EDP, Line::APOLO);
    Meter meter2("Meter 2", MeterType::THREE_PHASE, Client::CEMIG, Line::CRONOS);

    maker.add_meter(meter1);
    maker.add_meter(meter2);

    SECTION("Printing meters for a line with no meters returns 1")
    {
        CHECK(maker.print_line_meters(Line::ARES));
    }

    SECTION("Printing meters for a line with meters returns 0")
    {
        CHECK_FALSE(maker.print_line_meters(Line::APOLO));
        CHECK_FALSE(maker.print_line_meters(Line::CRONOS));
    }
}