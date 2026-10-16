#pragma once
#include "Maker.h"
#include "Table.h"
#include "meter/MeterFactory.h"

class Console
{
private:
    std::unique_ptr<Maker> maker;
    std::unique_ptr<MeterFactory> meter_factory;
    std::unique_ptr<Table> table;
    auto get_line_input() -> Line;
    auto get_meter_type_input() -> MeterType;
    auto get_client_input() -> Client;
    auto get_meter_name_input() -> std::string;
    auto get_meter_id_input() -> int;
    auto add_meter_input() -> bool;

public:
    Console(std::unique_ptr<Maker> maker, std::unique_ptr<MeterFactory> meter_factory, std::unique_ptr<Table> table);
    auto display_menu() -> void;
};