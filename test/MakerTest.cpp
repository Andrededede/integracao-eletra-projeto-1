// #include "../include/Maker.h"
// #include "../include/meter/MeterFactory.h"
// #include "catch.hpp"

// TEST_CASE("Maker names are returned correctly", "[maker]")
// {
//     Maker maker("Test Maker");
//     CHECK(maker.get_maker_name() == "Test Maker");
// }

// TEST_CASE("Meters can be added to a Maker correctly", "[maker]")
// {
//     MeterFactory meter_factory;
//     auto meter1 = meter_factory.create_meter(Line::APOLO);
//     auto meter2 = meter_factory.create_meter(Line::CRONOS);
//     auto meter3 = meter_factory.create_meter(Line::APOLO);

//     Maker maker("Test Maker");

//     SECTION("Adding a new meter returns 0")
//     {
//         CHECK_FALSE(maker.add_meter(std::move(meter1)));
//         CHECK_FALSE(maker.add_meter(std::move(meter2)));
//     }

//     SECTION("Adding a duplicate meter returns 1")
//     {
//         CHECK_FALSE(maker.add_meter(std::move(meter1)));
//         CHECK(maker.add_meter(std::move(meter3)));
//     }
// }

// TEST_CASE("Maker can print lines correctly", "[maker]")
// {
//     Maker maker("Test Maker");

//     SECTION("Printing lines with no meters returns 1")
//     {
//         CHECK(maker.print_lines());
//     }

//     SECTION("Printing lines with meters returns 0")
//     {
//         MeterFactory meter_factory;
//         maker.add_meter(meter_factory.create_meter(Line::APOLO));
//         maker.add_meter(meter_factory.create_meter(Line::CRONOS));
//         CHECK_FALSE(maker.print_lines());
//     }
// }

// TEST_CASE("Maker can print line meters correctly", "[maker]")
// {
//     Maker maker("Test Maker");
//     MeterFactory meter_factory;
//     auto meter1 = meter_factory.create_meter(Line::APOLO);
//     auto meter2 = meter_factory.create_meter(Line::CRONOS);

//     maker.add_meter(std::move(meter1));
//     maker.add_meter(std::move(meter2));

//     SECTION("Printing meters for a line with no meters returns 1")
//     {
//         CHECK(maker.print_line_meters(Line::ARES));
//     }

//     SECTION("Printing meters for a line with meters returns 0")
//     {
//         CHECK_FALSE(maker.print_line_meters(Line::APOLO));
//         CHECK_FALSE(maker.print_line_meters(Line::CRONOS));
//     }
// }