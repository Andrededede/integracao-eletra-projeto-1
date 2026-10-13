#pragma once
#include "Maker.h"
#include "meter/MeterFactory.h"

class Console
{
private:
    std::unique_ptr<Maker> maker;
    std::unique_ptr<MeterFactory> meter_factory;
    auto get_line_input() -> Line;
    auto get_meter_type_input() -> MeterType;
    auto get_client_input() -> Client;
    auto get_meter_name_input() -> std::string;
    auto add_meter_input() -> void;

public:
    Console(std::unique_ptr<Maker> maker, std::unique_ptr<MeterFactory> meter_factory);
    auto display_menu() -> void;
};