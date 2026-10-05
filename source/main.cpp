#include <iostream>
#include <locale>
#include "../include/Meter.h"
#include "../include/Line.h"
#include "../include/Brand.h"

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int op;

    Brand Eletra("Eletra");

    Line Apolo("Apolo");
    Line Cronos("Cronos");
    Line Ares("Ares");
    Line Zeus("Zeus");

    Eletra.addLine(Apolo);
    Eletra.addLine(Cronos);
    Eletra.addLine(Ares);
    Eletra.addLine(Zeus);

    Apolo.addMeter(Meter("6031"));

    Cronos.addMeter(Meter("6001 A"));
    Cronos.addMeter(Meter("6021 A"));
    Cronos.addMeter(Meter("6021L"));
    Cronos.addMeter(Meter("6003"));
    Cronos.addMeter(Meter("7023"));
    Cronos.addMeter(Meter("7023L"));
    Cronos.addMeter(Meter("7023L 2,5"));

    
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
        switch(op){
            case 1:
                Eletra.printLines();
                break;
            case 2:
                std::cout << "2" << std::endl;
                break; 
            case 3:
                Ares.printLine();
                break;
            case 4:
                Cronos.printLine();
                break;
            case 5:
                std::cout << "5" << std::endl;
                break; 
            case 6:
                std::cout << "6" << std::endl;
                break;
            case 7:
                std::cout << "7" << std::endl;
                break;
            default:
                std::cout << "Opção inválida" << std::endl;
                break;
        }
    } while (op != 7);

}