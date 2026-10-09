#include "../include/Maker.h"
#include "../include/meter/Meter.h"
#include "../include/meter/MeterFactory.h"
#include <iostream>
#include <locale>

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int op{};

    Maker Eletra("Eletra");
    std::unique_ptr<MeterFactory> meter_factory = std::make_unique<MeterFactory>();

    std::unique_ptr<Meter> apolo_6031 = meter_factory->create_meter(Line::APOLO);
    apolo_6031->set_meter_name("6031");
    apolo_6031->set_client(Client::EDP);
    Eletra.add_meter(std::move(apolo_6031));

    std::unique_ptr<Meter> cronos_6001A = meter_factory->create_meter(Line::CRONOS);
    cronos_6001A->set_meter_name("6001 A");
    cronos_6001A->set_client(Client::CEMIG);
    Eletra.add_meter(std::move(cronos_6001A));

    std::unique_ptr<Meter> cronos_6021A = meter_factory->create_meter(Line::CRONOS);
    cronos_6021A->set_meter_name("6021 A");
    cronos_6021A->set_client(Client::COPEL);
    Eletra.add_meter(std::move(cronos_6021A));

    std::unique_ptr<Meter> cronos_6021L = meter_factory->create_meter(Line::CRONOS);
    cronos_6021L->set_meter_name("6021L");
    cronos_6021L->set_client(Client::EDP);
    Eletra.add_meter(std::move(cronos_6021L));

    std::unique_ptr<Meter> cronos_6003 = meter_factory->create_meter(Line::CRONOS);
    cronos_6003->set_meter_name("6003");
    cronos_6003->set_meter_type(MeterType::THREE_PHASE);
    cronos_6003->set_client(Client::COELCE);
    Eletra.add_meter(std::move(cronos_6003));

    std::unique_ptr<Meter> cronos_7023 = meter_factory->create_meter(Line::CRONOS);
    cronos_7023->set_meter_name("7023");
    cronos_7023->set_meter_type(MeterType::THREE_PHASE);
    cronos_7023->set_client(Client::CEMIG);
    Eletra.add_meter(std::move(cronos_7023));

    std::unique_ptr<Meter> cronos_7023L = meter_factory->create_meter(Line::CRONOS);
    cronos_7023L->set_meter_name("7023L");
    cronos_7023L->set_meter_type(MeterType::THREE_PHASE);
    cronos_7023L->set_client(Client::EDP);
    Eletra.add_meter(std::move(cronos_7023L));

    std::unique_ptr<Meter> cronos_7023L_25 = meter_factory->create_meter(Line::CRONOS);
    cronos_7023L_25->set_meter_name("7023L 2,5");
    cronos_7023L_25->set_meter_type(MeterType::THREE_PHASE);
    cronos_7023L_25->set_client(Client::COPEL);
    Eletra.add_meter(std::move(cronos_7023L_25));

    std::unique_ptr<Meter> ares_7021 = meter_factory->create_meter(Line::ARES);
    ares_7021->set_meter_name("7021");
    ares_7021->set_client(Client::COPEL);
    Eletra.add_meter(std::move(ares_7021));

    std::unique_ptr<Meter> ares_7031 = meter_factory->create_meter(Line::ARES);
    ares_7031->set_meter_name("7031");
    ares_7031->set_client(Client::COPEL);
    Eletra.add_meter(std::move(ares_7031));

    std::unique_ptr<Meter> ares_7023 = meter_factory->create_meter(Line::ARES);
    ares_7023->set_meter_name("7023");
    ares_7023->set_client(Client::EDP);
    Eletra.add_meter(std::move(ares_7023));

    std::unique_ptr<Meter> ares_8023 = meter_factory->create_meter(Line::ARES);
    ares_8023->set_meter_name("8023");
    ares_8023->set_meter_type(MeterType::THREE_PHASE);
    ares_8023->set_client(Client::EDP);
    Eletra.add_meter(std::move(ares_8023));

    std::unique_ptr<Meter> ares_8023_15 = meter_factory->create_meter(Line::ARES);
    ares_8023_15->set_meter_name("8023 15");
    ares_8023_15->set_meter_type(MeterType::THREE_PHASE);
    ares_8023_15->set_client(Client::COPEL);
    Eletra.add_meter(std::move(ares_8023_15));

    std::unique_ptr<Meter> ares_8023_200 = meter_factory->create_meter(Line::ARES);
    ares_8023_200->set_meter_name("8023 200");
    ares_8023_200->set_meter_type(MeterType::THREE_PHASE);
    ares_8023_200->set_client(Client::COPEL);
    Eletra.add_meter(std::move(ares_8023_200));

    std::unique_ptr<Meter> zeus_8021 = meter_factory->create_meter(Line::ZEUS);
    zeus_8021->set_meter_name("8021");
    zeus_8021->set_client(Client::CEMIG);
    Eletra.add_meter(std::move(zeus_8021));

    std::unique_ptr<Meter> zeus_8031 = meter_factory->create_meter(Line::ZEUS);
    zeus_8031->set_meter_name("8031");
    zeus_8031->set_client(Client::CEMIG);
    Eletra.add_meter(std::move(zeus_8031));

    std::unique_ptr<Meter> zeus_8023 = meter_factory->create_meter(Line::ZEUS);
    zeus_8023->set_meter_name("8023");
    zeus_8023->set_meter_type(MeterType::THREE_PHASE);
    zeus_8023->set_client(Client::COELCE);
    Eletra.add_meter(std::move(zeus_8023));

    do
    {
        std::cout << "\nEscolha uma opção:" << std::endl
                  << "1. Exibir todas as linhas disponíveis" << std::endl
                  << "2. Exibir todos modelos de Medidores de Energia" << std::endl
                  << "3. Exibir todos os modelos da Linha Ares" << std::endl
                  << "4. Exibir todos os modelos da Linha Apollo" << std::endl
                  << "5. Exibir todos os modelos da Linha Cronos" << std::endl
                  << "6. Exibir todos os modelos da Linha Zeus" << std::endl
                  << "7. Sair da Aplicação" << std::endl;
        std::cin >> op;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
        switch (op)
        {
        case 1:
            Eletra.print_lines();
            break;
        case 2:
            Eletra.print_all_meters();
            break;
        case 3:
            Eletra.print_line_meters(Line::ARES);
            break;
        case 4:
            Eletra.print_line_meters(Line::APOLO);
            break;
        case 5:
            Eletra.print_line_meters(Line::CRONOS);
            break;
        case 6:
            Eletra.print_line_meters(Line::ZEUS);
            break;
        case 7:
            break;
        default:
            std::cout << "Opção inválida" << std::endl;
            break;
        }
    } while (op != 7);
}