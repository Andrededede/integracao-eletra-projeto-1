#include "../../include/meter/MeterFactory.h"
#include <iostream>

MeterFactory::MeterFactory()
{
    prototypes.insert({Line::APOLO, std::make_unique<Apolo>("Default Apolo Single Phase", MeterType::SINGLE_PHASE, Client::EDP)});
    prototypes.insert({Line::CRONOS, std::make_unique<Cronos>("Default Cronos Single Phase", MeterType::SINGLE_PHASE, Client::EDP)});
    prototypes.insert({Line::ARES, std::make_unique<Ares>("Default Ares Single Phase", MeterType::SINGLE_PHASE, Client::EDP)});
    prototypes.insert({Line::ZEUS, std::make_unique<Zeus>("Default Zeus Single Phase", MeterType::SINGLE_PHASE, Client::EDP)});
}

auto MeterFactory::create_meter(const Line &line, const std::string &name, const MeterType &type, const Client &client) -> std::unique_ptr<Meter>
{
    std::unique_ptr<Meter> meter = prototypes.at(line)->Clone();
    meter->set_meter_name(name);
    meter->set_meter_type(type);
    meter->set_client(client);
    std::cout << client_enum_to_string(client) << std::endl;
    return meter;
}