#pragma once

#include <string>

enum class MeterType
{
    SINGLE_PHASE,
    THREE_PHASE,
};

enum class Client
{
    EDP,
    CEMIG,
    COELCE,
    COPEL,
};

enum class Line
{
    APOLO,
    CRONOS,
    ARES,
    ZEUS,
};

auto meter_type_enum_to_string(MeterType type) -> std::string;
auto client_enum_to_string(Client client) -> std::string;
auto line_enum_to_string(Line line) -> std::string;

class Meter
{
private:
    static int ID;
    int id{0};
    std::string meter_name{};
    MeterType meter_type{};
    Client client{};
    Line line{};

public:
    Meter(std::string meter_name, MeterType meter_type, Client client, Line line);
    auto print_meter() -> void;
    auto get_id() -> int
    {
        return id;
    }
    auto get_meter_name() -> std::string
    {
        return meter_name;
    }
    auto get_meter_type() -> MeterType
    {
        return meter_type;
    }
    auto get_client() -> Client
    {
        return client;
    }
    auto get_line() -> Line
    {
        return line;
    }
};
