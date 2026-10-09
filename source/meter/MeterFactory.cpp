#include "../../include/meter/MeterFactory.h"

MeterFactory::MeterFactory()
{
    prototypes.insert({Line::APOLO, std::make_unique<Apolo>("Default Single Phase", MeterType::SINGLE_PHASE, Client::EDP)});
    prototypes.insert({Line::CRONOS, std::make_unique<Cronos>("Default Single Phase", MeterType::SINGLE_PHASE, Client::EDP)});
    prototypes.insert({Line::ARES, std::make_unique<Ares>("Default Single Phase", MeterType::SINGLE_PHASE, Client::EDP)});
    prototypes.insert({Line::ZEUS, std::make_unique<Zeus>("Default Single Phase", MeterType::SINGLE_PHASE, Client::EDP)});
}

auto MeterFactory::create_meter(Line line) -> std::unique_ptr<Meter>
{
    return prototypes.at(line)->Clone();
}