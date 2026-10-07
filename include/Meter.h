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
    MeterType meterType{};
    Client client{};

public:
    Meter(std::string meter_name);
    auto print_name() -> void;
    auto get_meter_name() -> std::string
    {
        return meter_name;
    }
};
