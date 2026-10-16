#include "../include/Console.h"
#include "../include/Maker.h"
#include "../include/Table.h"
#include "../include/meter/Meter.h"
#include "../include/meter/MeterFactory.h"
#include <iostream>
#include <locale>

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    std::unique_ptr<Maker> Eletra = std::make_unique<Maker>("Eletra");
    std::unique_ptr<MeterFactory> meter_factory = std::make_unique<MeterFactory>();

    std::unique_ptr<Meter> apolo_6031 = meter_factory->create_meter(Line::APOLO, "6031", MeterType::SINGLE_PHASE, Client::EDP, 210.0f);
    Eletra->add_meter(std::move(apolo_6031));

    std::unique_ptr<Meter> cronos_6001A = meter_factory->create_meter(Line::CRONOS, "6001 A", MeterType::SINGLE_PHASE, Client::CEMIG, 180.0f);
    Eletra->add_meter(std::move(cronos_6001A));
    std::unique_ptr<Meter> cronos_6021A = meter_factory->create_meter(Line::CRONOS, "6021 A", MeterType::SINGLE_PHASE, Client::COPEL, 195.0f);
    Eletra->add_meter(std::move(cronos_6021A));
    std::unique_ptr<Meter> cronos_6021L = meter_factory->create_meter(Line::CRONOS, "6021L", MeterType::SINGLE_PHASE, Client::EDP, 222.0f);
    Eletra->add_meter(std::move(cronos_6021L));
    std::unique_ptr<Meter> cronos_6003 =
        meter_factory->create_meter(Line::CRONOS, "6003", MeterType::THREE_PHASE, Client::COELCE, 213.0f, 327.0f, 225.0f);
    Eletra->add_meter(std::move(cronos_6003));
    std::unique_ptr<Meter> cronos_7023 =
        meter_factory->create_meter(Line::CRONOS, "7023", MeterType::THREE_PHASE, Client::CEMIG, 220.0f, 380.0f, 220.0f);
    Eletra->add_meter(std::move(cronos_7023));
    std::unique_ptr<Meter> cronos_7023L =
        meter_factory->create_meter(Line::CRONOS, "7023L", MeterType::THREE_PHASE, Client::EDP, 220.0f, 380.0f, 220.0f);
    Eletra->add_meter(std::move(cronos_7023L));
    std::unique_ptr<Meter> cronos_7023L_25 =
        meter_factory->create_meter(Line::CRONOS, "7023L 2,5", MeterType::THREE_PHASE, Client::COPEL, 220.0f, 380.0f, 220.0f);
    Eletra->add_meter(std::move(cronos_7023L_25));

    std::unique_ptr<Meter> ares_7021 = meter_factory->create_meter(Line::ARES, "7021", MeterType::SINGLE_PHASE, Client::COPEL, 220.0f);
    Eletra->add_meter(std::move(ares_7021));
    std::unique_ptr<Meter> ares_7031 = meter_factory->create_meter(Line::ARES, "7031", MeterType::SINGLE_PHASE, Client::COPEL, 220.0f);
    Eletra->add_meter(std::move(ares_7031));
    std::unique_ptr<Meter> ares_7023 = meter_factory->create_meter(Line::ARES, "7023", MeterType::SINGLE_PHASE, Client::EDP, 220.0f);
    Eletra->add_meter(std::move(ares_7023));
    std::unique_ptr<Meter> ares_8023 = meter_factory->create_meter(Line::ARES, "8023", MeterType::THREE_PHASE, Client::EDP, 220.0f, 380.0f, 220.0f);
    Eletra->add_meter(std::move(ares_8023));
    std::unique_ptr<Meter> ares_8023_15 =
        meter_factory->create_meter(Line::ARES, "8023 15", MeterType::THREE_PHASE, Client::COPEL, 220.0f, 380.0f, 220.0f);
    Eletra->add_meter(std::move(ares_8023_15));
    std::unique_ptr<Meter> ares_8023_200 =
        meter_factory->create_meter(Line::ARES, "8023 200", MeterType::THREE_PHASE, Client::COPEL, 220.0f, 380.0f, 220.0f);
    Eletra->add_meter(std::move(ares_8023_200));

    std::unique_ptr<Meter> zeus_8021 = meter_factory->create_meter(Line::ZEUS, "8021", MeterType::SINGLE_PHASE, Client::CEMIG, 220.0f);
    Eletra->add_meter(std::move(zeus_8021));
    std::unique_ptr<Meter> zeus_8031 = meter_factory->create_meter(Line::ZEUS, "8031", MeterType::SINGLE_PHASE, Client::CEMIG, 220.0f);
    Eletra->add_meter(std::move(zeus_8031));
    std::unique_ptr<Meter> zeus_8023 =
        meter_factory->create_meter(Line::ZEUS, "8023", MeterType::THREE_PHASE, Client::COELCE, 220.0f, 380.0f, 220.0f);
    Eletra->add_meter(std::move(zeus_8023));

    std::unique_ptr<Table> table = std::make_unique<Table>();
    Console console(std::move(Eletra), std::move(meter_factory), std::move(table));
    console.display_menu();
}