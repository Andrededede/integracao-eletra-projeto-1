// #include "../include/meter/MeterFactory.h"
// #include "catch.hpp"

// TEST_CASE("Meter properties", "[meter]")
// {
//     MeterFactory meter_factory;

//     SECTION("Meter properties are returned correctly")
//     {
//         auto meter = meter_factory.create_meter(Line::APOLO);
//         CHECK(meter->get_meter_name() == "Default Apolo Single Phase");
//         CHECK(meter->get_meter_type() == MeterType::SINGLE_PHASE);
//         CHECK(meter->get_client() == Client::EDP);
//         CHECK(meter->get_line() == Line::APOLO);
//     }

//     SECTION("Meter ID increments correctly")
//     {
//         auto meter = meter_factory.create_meter(Line::APOLO);
//         auto meter2 = meter_factory.create_meter(Line::CRONOS);
//         CHECK(meter2->get_id() == meter->get_id() + 1);
//     }
// }