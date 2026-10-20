#include "Maker.h"
#include "meter/MeterFactory.h"
#include <iostream>

auto MeterFactory::create_meter(const Line &line, const std::string &name, const MeterType &type, const Client &client, float phase1,
                                std::optional<float> phase2, std::optional<float> phase3) -> std::unique_ptr<Meter>
{

    BuilderMeter builder;
    builder.set_id(get_next_meter_id()).set_meter_name(name).set_meter_type(type).set_client(client).set_line(line).set_phase1(phase1);

    if (type == MeterType::THREE_PHASE)
    {
        if (phase2.has_value())
        {
            builder.set_phase2(phase2);
        }
        if (phase3.has_value())
        {
            builder.set_phase3(phase3);
        }
    }

    return builder.build();
}