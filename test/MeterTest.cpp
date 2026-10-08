#include "../include/Meter.h"
#include "catch.hpp"

TEST_CASE("Meter properties", "[meter]")
{
    Meter meter("Test Meter", MeterType::SINGLE_PHASE, Client::EDP, Line::APOLO);

    SECTION("Meter properties are returned correctly")
    {
        CHECK(meter.get_meter_name() == "Test Meter");
        CHECK(meter.get_meter_type() == MeterType::SINGLE_PHASE);
        CHECK(meter.get_client() == Client::EDP);
        CHECK(meter.get_line() == Line::APOLO);
    }

    SECTION("Meter ID increments correctly")
    {
        Meter meter2("Test Meter 2", MeterType::THREE_PHASE, Client::CEMIG, Line::CRONOS);
        CHECK(meter2.get_id() == meter.get_id() + 1);
    }
}