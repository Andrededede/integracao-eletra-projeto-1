#include <iostream>
#include <locale>

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int op;

    std::cout << "Escolha uma opção:" << std::endl <<
        "1. Exibir todas as linhas disponíveis" << std::endl <<
        "2. Exibir todos modelos de Medidores de Energia" << std::endl <<
        "3. Exibir todos os modelos da Linha Ares" << std::endl <<
        "4. Exibir todos os modelos da Linha Apollo" << std::endl <<
        "5. Exibir todos os modelos da Linha Cronos" << std::endl <<
        "6. Exibir todos os modelos da Linha Zeus" << std::endl <<
        "7. Sair da Aplicação" << std::endl;

    
    std::cin >> op;
    std::cout << "Opção escolhida: ";
    switch(op){
        case 1:
            std::cout << "1" << std::endl;
            break;
        case 2:
            std::cout << "2" << std::endl;
            break; 
        case 3:
            std::cout << "3" << std::endl;
            break;
        case 4:
            std::cout << "4" << std::endl;
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

}