#pragma once

#include <string>

enum class MeterType
{
    SINGLE_PHASE,
    THREE_PHASE,
    SINGLE_PHASE_PREPAID,
    THREE_PHASE_PREPAID
};

enum class Client
{
    EDP,
    CEMIG,
    COELCE,
    COPEL,
};

auto meter_type_enum_to_string(MeterType type) -> std::string;
auto client_enum_to_string(Client client) -> std::string;

class Meter
{
private:
    static int ID;
    int id{0};
    std::string meter_name{};
    MeterType meter_type{};
    Client client{};

public:
    Meter(std::string meter_name, MeterType meter_type, Client client);
    auto print_name() -> void;
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
};
