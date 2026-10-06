#include <iostream>
#include <locale>
#include "../include/Meter.h"
#include "../include/Line.h"
#include "../include/Maker.h"

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int op;

    Maker Eletra("Eletra");

    Line Apolo("Apolo");
    Line Cronos("Cronos");
    Line Ares("Ares");
    Line Zeus("Zeus");

    Apolo.addMeter(Meter("6031"));

    Cronos.addMeter(Meter("6001 A"));
    Cronos.addMeter(Meter("6021 A"));
    Cronos.addMeter(Meter("6021L"));
    Cronos.addMeter(Meter("6003"));
    Cronos.addMeter(Meter("7023"));
    Cronos.addMeter(Meter("7023L"));
    Cronos.addMeter(Meter("7023L 2,5"));

    Ares.addMeter(Meter("7021"));
    Ares.addMeter(Meter("7031"));
    Ares.addMeter(Meter("7023"));
    Ares.addMeter(Meter("8023"));
    Ares.addMeter(Meter("8023 15"));
    Ares.addMeter(Meter("8023 200"));

    Zeus.addMeter(Meter("8021"));
    Zeus.addMeter(Meter("8023"));
    Zeus.addMeter(Meter("8031"));

    Eletra.addLine(Apolo);
    Eletra.addLine(Cronos);
    Eletra.addLine(Ares);
    Eletra.addLine(Zeus);

    
    do {
        std::cout << "\nEscolha uma opção:" << std::endl <<
            "1. Exibir todas as linhas disponíveis" << std::endl <<
            "2. Exibir todos modelos de Medidores de Energia" << std::endl <<
            "3. Exibir todos os modelos da Linha Ares" << std::endl <<
            "4. Exibir todos os modelos da Linha Apollo" << std::endl <<
            "5. Exibir todos os modelos da Linha Cronos" << std::endl <<
            "6. Exibir todos os modelos da Linha Zeus" << std::endl <<
            "7. Sair da Aplicação" << std::endl;
        std::cin >> op;
        std::cout << std::endl;
        switch(op){
            case 1:
                Eletra.printLines();
                break;
            case 2:
                Eletra.printAllMeters();
                break; 
            case 3:
                Ares.printLineMeters();
                break;
            case 4:
                Apolo.printLineMeters();
                break;
            case 5:
                Cronos.printLineMeters();
                break; 
            case 6:
                Zeus.printLineMeters();
                break;
            case 7:
                break;
            default:
                std::cout << "Opção inválida" << std::endl;
                break;
        }
    } while (op != 7);

}