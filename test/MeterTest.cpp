#include "../include/Meter.h"
#include "catch.hpp"

TEST_CASE("Meter properties are returned correctly", "[meter]")
{
    Meter meter("Test Meter", MeterType::SINGLE_PHASE, Client::EDP);

    SECTION("Meter properties are correct")
    {
        REQUIRE(meter.get_meter_name() == "Test Meter");
        REQUIRE(meter.get_meter_type() == MeterType::SINGLE_PHASE);
        REQUIRE(meter.get_client() == Client::EDP);
    }

    SECTION("Meter ID increments correctly")
    {
        Meter meter2("Test Meter 2", MeterType::THREE_PHASE, Client::CEMIG);
        REQUIRE(meter2.get_id() == meter.get_id() + 1);
    }
}