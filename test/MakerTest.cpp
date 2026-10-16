#include "../include/Maker.h"
#include "../include/meter/MeterFactory.h"
#include "catch.hpp"

TEST_CASE("Maker names are returned correctly", "[maker]")
{
    Maker maker("Test Maker");
    CHECK(maker.get_maker_name() == "Test Maker");
}

TEST_CASE("Meters can be added to a Maker correctly", "[maker]")
{
    MeterFactory meter_factory;
    auto meter1 = meter_factory.create_meter(Line::APOLO, "Default Apolo Single Phase", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);
    auto meter2 =
        meter_factory.create_meter(Line::CRONOS, "Default Cronos Single Phase", MeterType::THREE_PHASE, Client::EDP, 220.0f, 230.0f, 250.0f);
    auto meter_1_clone = meter_factory.create_meter(Line::APOLO, "Default Apolo Single Phase", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);

    Maker maker("Test Maker");

    SECTION("Adding a new meter is successful")
    {
        CHECK(maker.add_meter(std::move(meter1)));
        CHECK(maker.add_meter(std::move(meter2)));
    }

    SECTION("Adding a duplicate meter is unsuccessful")
    {
        CHECK(maker.add_meter(std::move(meter1)));
        CHECK_FALSE(maker.add_meter(std::move(meter_1_clone)));
    }
}

TEST_CASE("Meters can be removed from a Maker correctly", "[maker]")
{
    MeterFactory meter_factory;
    auto meter1 = meter_factory.create_meter(Line::APOLO, "Default Apolo Single Phase", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);
    auto meter2 = meter_factory.create_meter(Line::CRONOS, "Default Cronos Single Phase", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);

    Maker maker("Test Maker");
    maker.add_meter(std::move(meter1));
    maker.add_meter(std::move(meter2));

    SECTION("Removing an existing meter is successful")
    {
        CHECK(maker.remove_meter(std::stoi(maker.get_all_meters_rows()[0][0])));
    }

    SECTION("Removing a non-existing meter is unsuccessful")
    {
        CHECK_FALSE(maker.remove_meter(std::stoi(maker.get_all_meters_rows()[1][0]) + 1));
    }
}

TEST_CASE("Maker can return active lines correctly", "[maker]")
{
    Maker maker("Test Maker");
    MeterFactory meter_factory;
    auto meter1 = meter_factory.create_meter(Line::APOLO, "Default Apolo Single Phase", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);
    auto meter2 = meter_factory.create_meter(Line::CRONOS, "Default Cronos Single Phase", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);

    maker.add_meter(std::move(meter1));
    maker.add_meter(std::move(meter2));

    SECTION("Getting lines returns the correct number of lines")
    {
        auto lines = maker.get_lines();
        CHECK(lines.size() == 2);
        CHECK(lines.find(Line::APOLO) != lines.end());
        CHECK(lines.at(Line::APOLO) == "APOLO");
        CHECK(lines.find(Line::CRONOS) != lines.end());
        CHECK(lines.at(Line::CRONOS) == "CRONOS");
        CHECK(lines.find(Line::ARES) == lines.end());
    }
}

TEST_CASE("Maker can get meters of a line correctly", "[maker]")
{
    Maker maker("Test Maker");
    MeterFactory meter_factory;
    auto meter1 = meter_factory.create_meter(Line::APOLO, "Default Apolo Single Phase", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);
    auto meter2 = meter_factory.create_meter(Line::CRONOS, "Default Cronos Single Phase", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);

    maker.add_meter(std::move(meter1));
    maker.add_meter(std::move(meter2));

    SECTION("Getting meters of a line with no meters returns empty vector")
    {
        CHECK(maker.get_line_meters_rows(Line::ARES).empty());
    }

    SECTION("Getting meters of a line with meters")
    {
        auto apolo_meters = maker.get_line_meters_rows(Line::APOLO);
        CHECK(apolo_meters.size() >= 1);
        CHECK(apolo_meters[0][1] == "Default Apolo Single Phase");

        auto cronos_meters = maker.get_line_meters_rows(Line::CRONOS);
        CHECK(cronos_meters.size() == 1);
        CHECK(cronos_meters[0][1] == "Default Cronos Single Phase");
    }
}

TEST_CASE("Maker can get the line of a meter correctly", "[maker]")
{
    Maker maker("Test Maker");
    MeterFactory meter_factory;
    auto meter1 = meter_factory.create_meter(Line::APOLO, "Default Apolo Single Phase", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);
    auto meter2 = meter_factory.create_meter(Line::CRONOS, "Default Cronos Single Phase", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);

    maker.add_meter(std::move(meter1));
    maker.add_meter(std::move(meter2));

    SECTION("Getting the line of an existing meter returns the correct line")
    {
        int id = std::stoi(maker.get_all_meters_rows()[0][0]);
        CHECK(maker.get_meter_line(id) == "APOLO");
    }

    SECTION("Getting the line of a non-existing meter returns ''")
    {
        CHECK(maker.get_meter_line(9999) == "");
    }
}

TEST_CASE("Maker can get the type of a meter correctly", "[maker]")
{
    Maker maker("Test Maker");
    MeterFactory meter_factory;
    auto meter1 = meter_factory.create_meter(Line::APOLO, "Default Apolo Single Phase", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);
    auto meter2 = meter_factory.create_meter(Line::CRONOS, "Default Cronos Single Phase", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);

    maker.add_meter(std::move(meter1));
    maker.add_meter(std::move(meter2));

    SECTION("Getting the type of an existing meter returns the correct type")
    {
        int id = std::stoi(maker.get_all_meters_rows()[0][0]);
        CHECK(maker.get_meter_type(id) == "SINGLE_PHASE");
    }

    SECTION("Getting the type of a non-existing meter returns ''")
    {
        CHECK(maker.get_meter_type(9999) == "");
    }
}

TEST_CASE("Maker can get all meters correctly", "[maker]")
{
    Maker maker("Test Maker");
    MeterFactory meter_factory;
    auto meter1 = meter_factory.create_meter(Line::APOLO, "Default Apolo Single Phase", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);
    auto meter2 = meter_factory.create_meter(Line::CRONOS, "Default Cronos Single Phase", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);

    maker.add_meter(std::move(meter1));
    maker.add_meter(std::move(meter2));

    SECTION("Getting all meters returns the correct number of meters")
    {
        auto all_meters = maker.get_all_meters_rows();
        CHECK(all_meters.size() == 2);
    }
}