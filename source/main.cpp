#include "../include/Maker.h"
#include "../include/Meter.h"
#include <iostream>
#include <locale>

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int op{};

    Maker Eletra("Eletra");

    Eletra.add_meter(Meter("6031", MeterType::SINGLE_PHASE, Client::EDP, Line::APOLO));

    Eletra.add_meter(Meter("6001 A", MeterType::SINGLE_PHASE, Client::CEMIG, Line::CRONOS));
    Eletra.add_meter(Meter("6021 A", MeterType::SINGLE_PHASE, Client::COPEL, Line::CRONOS));
    Eletra.add_meter(Meter("6021L", MeterType::SINGLE_PHASE, Client::EDP, Line::CRONOS));
    Eletra.add_meter(Meter("6003", MeterType::THREE_PHASE, Client::COELCE, Line::CRONOS));
    Eletra.add_meter(Meter("7023", MeterType::THREE_PHASE, Client::CEMIG, Line::CRONOS));
    Eletra.add_meter(Meter("7023L", MeterType::THREE_PHASE, Client::EDP, Line::CRONOS));
    Eletra.add_meter(Meter("7023L 2,5", MeterType::THREE_PHASE, Client::COPEL, Line::CRONOS));

    Eletra.add_meter(Meter("7021", MeterType::SINGLE_PHASE, Client::CEMIG, Line::ARES));
    Eletra.add_meter(Meter("7031", MeterType::SINGLE_PHASE, Client::COPEL, Line::ARES));
    Eletra.add_meter(Meter("7023", MeterType::SINGLE_PHASE, Client::EDP, Line::ARES));
    Eletra.add_meter(Meter("8023", MeterType::THREE_PHASE, Client::EDP, Line::ARES));
    Eletra.add_meter(Meter("8023 15", MeterType::THREE_PHASE, Client::COPEL, Line::ARES));
    Eletra.add_meter(Meter("8023 200", MeterType::THREE_PHASE, Client::COPEL, Line::ARES));

    Eletra.add_meter(Meter("8021", MeterType::SINGLE_PHASE, Client::CEMIG, Line::ZEUS));
    Eletra.add_meter(Meter("8031", MeterType::SINGLE_PHASE, Client::CEMIG, Line::ZEUS));
    Eletra.add_meter(Meter("8023", MeterType::THREE_PHASE, Client::COELCE, Line::ZEUS));

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