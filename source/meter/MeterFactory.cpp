#include "../../include/meter/MeterFactory.h"
#include <iostream>

MeterFactory::MeterFactory()
{
    prototypes.insert({Line::APOLO, std::make_unique<Apolo>(0)});
    prototypes.insert({Line::CRONOS, std::make_unique<Cronos>(0)});
    prototypes.insert({Line::ARES, std::make_unique<Ares>(0)});
    prototypes.insert({Line::ZEUS, std::make_unique<Zeus>(0)});
}

auto MeterFactory::create_meter(const Line &line, const std::string &name, const MeterType &type, const Client &client, float phase1,
                                std::optional<float> phase2, std::optional<float> phase3) -> std::unique_ptr<Meter>
{
    std::unique_ptr<Meter> meter = prototypes.at(line)->Clone();
    meter->set_meter_name(name);
    meter->set_meter_type(type);
    meter->set_client(client);
    meter->set_phase1(phase1);
    if (type == MeterType::THREE_PHASE)
    {
        if (phase2.has_value())
        {
            meter->set_phase2(phase2);
        }
        if (phase3.has_value())
        {
            meter->set_phase3(phase3);
        }
    }
    return meter;
}