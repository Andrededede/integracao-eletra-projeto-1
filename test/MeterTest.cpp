#include "catch.hpp"
#include "meter/MeterFactory.h"

TEST_CASE("Meter properties", "[meter]")
{
    MeterFactory meter_factory;

    SECTION("Meter properties are returned correctly")
    {
        auto meter = meter_factory.create_meter(Line::APOLO, "Default Apolo Single Phase", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);
        CHECK(meter->get_meter_name() == "Default Apolo Single Phase");
        CHECK(meter->get_meter_type() == MeterType::SINGLE_PHASE);
        CHECK(meter->get_client() == Client::EDP);
        CHECK(meter->get_line() == Line::APOLO);
    }

    SECTION("Meter ID increments correctly")
    {
        auto meter = meter_factory.create_meter(Line::APOLO, "Default Apolo Single Phase", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);
        auto meter2 = meter_factory.create_meter(Line::CRONOS, "Default Cronos Single Phase", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);
        CHECK(meter2->get_id() == meter->get_id() + 1);
    }
}

TEST_CASE("MeterFactory creates meters correctly", "[meter]")
{
    MeterFactory meter_factory;

    SECTION("Creating an Apolo meter keeps the correct properties")
    {
        auto apolo_meter = meter_factory.create_meter(Line::APOLO, "Apolo Test Meter", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);
        CHECK(apolo_meter->get_line() == Line::APOLO);
        CHECK(apolo_meter->get_meter_name() == "Apolo Test Meter");
        CHECK(apolo_meter->get_meter_type() == MeterType::SINGLE_PHASE);
        CHECK(apolo_meter->get_client() == Client::EDP);
    }

    SECTION("Creating a Cronos meter keeps the correct properties")
    {
        auto cronos_meter =
            meter_factory.create_meter(Line::CRONOS, "Cronos Test Meter", MeterType::THREE_PHASE, Client::CEMIG, 220.0f, 230.0f, 250.0f);
        CHECK(cronos_meter->get_line() == Line::CRONOS);
        CHECK(cronos_meter->get_meter_name() == "Cronos Test Meter");
        CHECK(cronos_meter->get_meter_type() == MeterType::THREE_PHASE);
        CHECK(cronos_meter->get_client() == Client::CEMIG);
    }

    SECTION("Creating an Ares meter keeps the correct properties")
    {
        auto ares_meter = meter_factory.create_meter(Line::ARES, "Ares Test Meter", MeterType::SINGLE_PHASE, Client::COPEL, 220.0f);
        CHECK(ares_meter->get_line() == Line::ARES);
        CHECK(ares_meter->get_meter_name() == "Ares Test Meter");
        CHECK(ares_meter->get_meter_type() == MeterType::SINGLE_PHASE);
        CHECK(ares_meter->get_client() == Client::COPEL);
    }

    SECTION("Creating a Zeus meter keeps the correct properties")
    {
        auto zeus_meter = meter_factory.create_meter(Line::ZEUS, "Zeus Test Meter", MeterType::THREE_PHASE, Client::COELCE, 220.0f, 230.0f, 250.0f);
        CHECK(zeus_meter->get_line() == Line::ZEUS);
        CHECK(zeus_meter->get_meter_name() == "Zeus Test Meter");
        CHECK(zeus_meter->get_meter_type() == MeterType::THREE_PHASE);
        CHECK(zeus_meter->get_client() == Client::COELCE);
    }
}
TEST_CASE("Enum to string conversion", "[meter]")
{
    SECTION("MeterType enum to string conversion returns correct string")
    {
        CHECK(meter_type_enum_to_string(MeterType::SINGLE_PHASE) == "SINGLE_PHASE");
        CHECK(meter_type_enum_to_string(MeterType::THREE_PHASE) == "THREE_PHASE");
    }

    SECTION("MeterType enum to string conversion returns nullopt for invalid enum")
    {
        CHECK(meter_type_enum_to_string(static_cast<MeterType>(999)) == std::nullopt);
    }

    SECTION("Client enum to string conversion returns correct string")
    {
        CHECK(client_enum_to_string(Client::EDP) == "EDP");
        CHECK(client_enum_to_string(Client::CEMIG) == "CEMIG");
        CHECK(client_enum_to_string(Client::COELCE) == "COELCE");
        CHECK(client_enum_to_string(Client::COPEL) == "COPEL");
    }
    SECTION("Client enum to string conversion returns nullopt for invalid enum")
    {
        CHECK(client_enum_to_string(static_cast<Client>(999)) == std::nullopt);
    }

    SECTION("Line enum to string conversion returns correct string")
    {
        CHECK(line_enum_to_string(Line::APOLO) == "APOLO");
        CHECK(line_enum_to_string(Line::CRONOS) == "CRONOS");
        CHECK(line_enum_to_string(Line::ARES) == "ARES");
        CHECK(line_enum_to_string(Line::ZEUS) == "ZEUS");
    }
    SECTION("Line enum to string conversion returns nullopt for invalid enum")
    {
        CHECK(line_enum_to_string(static_cast<Line>(999)) == std::nullopt);
    }
}

TEST_CASE("Meter row representation", "[meter]")
{
    MeterFactory meter_factory;
    auto meter = meter_factory.create_meter(Line::APOLO, "Default Apolo Single Phase", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);
    auto row = meter->get_meter_as_row();

    SECTION("Meter row representation has correct size")
    {
        CHECK(row.size() == 5);
    }

    SECTION("Meter row representation has correct values")
    {
        CHECK(row[0] == std::to_string(meter->get_id()));
        CHECK(row[1] == "Default Apolo Single Phase");
        CHECK(row[2] == "SINGLE_PHASE");
        CHECK(row[3] == "APOLO");
        CHECK(row[4] == "EDP");
    }
}

TEST_CASE("Meter equality operator", "[meter]")
{
    MeterFactory meter_factory;
    auto meter1 = meter_factory.create_meter(Line::APOLO, "Default Apolo Single Phase", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);
    auto meter2 =
        meter_factory.create_meter(Line::APOLO, "Default Apolo Single Phase", MeterType::THREE_PHASE, Client::COPEL, 220.0f, 230.0f, 250.0f);
    auto meter3 = meter_factory.create_meter(Line::CRONOS, "Default Cronos Single Phase", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);

    SECTION("Meters with the same line and name are equal")
    {
        CHECK(*meter1 == *meter2);
    }

    SECTION("Meters with different lines or names are not equal")
    {
        CHECK_FALSE(*meter1 == *meter3);
    }
}
