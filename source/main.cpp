#include "../include/Line.h"
#include "../include/Maker.h"
#include "../include/Meter.h"
#include <iostream>
#include <locale>

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int op{};

    Maker Eletra("Eletra");

    Line Apolo("Apolo");
    Line Cronos("Cronos");
    Line Ares("Ares");
    Line Zeus("Zeus");

    Apolo.add_meter(Meter("6031"));

    Cronos.add_meter(Meter("6001 A"));
    Cronos.add_meter(Meter("6021 A"));
    Cronos.add_meter(Meter("6021L"));
    Cronos.add_meter(Meter("6003"));
    Cronos.add_meter(Meter("7023"));
    Cronos.add_meter(Meter("7023L"));
    Cronos.add_meter(Meter("7023L 2,5"));

    Ares.add_meter(Meter("7021"));
    Ares.add_meter(Meter("7031"));
    Ares.add_meter(Meter("7023"));
    Ares.add_meter(Meter("8023"));
    Ares.add_meter(Meter("8023 15"));
    Ares.add_meter(Meter("8023 200"));

    Zeus.add_meter(Meter("8021"));
    Zeus.add_meter(Meter("8023"));
    Zeus.add_meter(Meter("8031"));

    Eletra.add_line(Apolo);
    Eletra.add_line(Cronos);
    Eletra.add_line(Ares);
    Eletra.add_line(Zeus);

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
            Ares.print_line_meters();
            break;
        case 4:
            Apolo.print_line_meters();
            break;
        case 5:
            Cronos.print_line_meters();
            break;
        case 6:
            Zeus.print_line_meters();
            break;
        case 7:
            break;
        default:
            std::cout << "Opção inválida" << std::endl;
            break;
        }
    } while (op != 7);
}