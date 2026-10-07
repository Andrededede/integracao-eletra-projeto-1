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

class Meter
{
private:
    int id{};
    std::string meter_name{};
    MeterType meter_type{};
    Client client{};

public:
    Meter(int id, std::string meter_name, MeterType meter_type, Client client);
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
