#include "../include/Console.h"
#include <iostream>

Console::Console(std::unique_ptr<Maker> maker, std::unique_ptr<MeterFactory> meter_factory)
    : maker(std::move(maker))
    , meter_factory(std::move(meter_factory))
{
}

auto Console::get_line_input() -> Line
{
    int op{0};
    std::cout << "\nEscolha a linha:" << std::endl
              << "1. Ares" << std::endl
              << "2. Apolo" << std::endl
              << "3. Cronos" << std::endl
              << "4. Zeus" << std::endl;
    std::cin >> op;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (op)
    {
    case 1:
        return Line::ARES;
    case 2:
        return Line::APOLO;
    case 3:
        return Line::CRONOS;
    case 4:
        return Line::ZEUS;
    default:
        std::cout << "Opção inválida. Tente novamente." << std::endl;
        return get_line_input();
    }
}

auto Console::get_meter_type_input() -> MeterType
{
    int op{0};
    std::cout << "\nEscolha o tipo de medidor:" << std::endl << "1. SINGLE_PHASE" << std::endl << "2. THREE_PHASE" << std::endl;
    std::cin >> op;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (op)
    {
    case 1:
        return MeterType::SINGLE_PHASE;
    case 2:
        return MeterType::THREE_PHASE;
    default:
        std::cout << "Opção inválida. Tente novamente." << std::endl;
        return get_meter_type_input();
    }
}

auto Console::get_client_input() -> Client
{
    int op{0};
    std::cout << "\nEscolha o cliente:" << std::endl
              << "1. EDP" << std::endl
              << "2. CEMIG" << std::endl
              << "3. COPEL" << std::endl
              << "4. COELCE" << std::endl;
    std::cin >> op;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (op)
    {
    case 1:
        return Client::EDP;
    case 2:
        return Client::CEMIG;
    case 3:
        return Client::COPEL;
    case 4:
        return Client::COELCE;
    default:
        std::cout << "Opção inválida. Tente novamente." << std::endl;
        return get_client_input();
    }
}

auto Console::get_meter_name_input() -> std::string
{
    std::string meter_name;
    std::cout << "\nDigite o nome do modelo do medidor: ";
    std::getline(std::cin >> std::ws, meter_name);
    if (meter_name.length() > 10)
    {
        std::cout << "Nome do modelo do medidor não pode ter mais de 10 caracteres. Tente novamente." << std::endl;
        return get_meter_name_input();
    }
    return meter_name;
}

auto Console::add_meter_input() -> void
{
    auto line = get_line_input();
    auto meter_type = get_meter_type_input();
    auto client = get_client_input();
    auto meter_name = get_meter_name_input();

    std::unique_ptr<Meter> new_meter = meter_factory->create_meter(line);
    new_meter->set_meter_name(meter_name);
    new_meter->set_meter_type(meter_type);
    new_meter->set_client(client);

    maker->add_meter(std::move(new_meter));
}

auto Console::display_menu() -> void
{
    int op{0};
    int id{0};
    do
    {
        std::cout << "\nEscolha uma opção:" << std::endl
                  << "1. Exibir todas as linhas disponíveis" << std::endl
                  << "2. Exibir todos modelos de Medidores de Energia" << std::endl
                  << "3. Exibir todos os modelos da Linha Ares" << std::endl
                  << "4. Exibir todos os modelos da Linha Apolo" << std::endl
                  << "5. Exibir todos os modelos da Linha Cronos" << std::endl
                  << "6. Exibir todos os modelos da Linha Zeus" << std::endl
                  << "7. Adicionar um novo modelo a uma linha específica" << std::endl
                  << "8. Remover o modelo informando o seu id" << std::endl
                  << "9. Realizar Leitura de Fase de um medidor" << std::endl
                  << "10. Sair da Aplicação" << std::endl;
        std::cin >> op;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
        switch (op)
        {
        case 1:
            maker->print_lines();
            break;
        case 2:
            maker->print_all_meters();
            break;
        case 3:
            maker->print_line_meters(Line::ARES);
            break;
        case 4:
            maker->print_line_meters(Line::APOLO);
            break;
        case 5:
            maker->print_line_meters(Line::CRONOS);
            break;
        case 6:
            maker->print_line_meters(Line::ZEUS);
            break;
        case 7:
            add_meter_input();
            break;
        case 8:
            std::cout << "Digite o ID do medidor que deseja remover: ";
            std::cin >> id;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (maker->remove_meter(id))
            {
                std::cout << "Medidor com ID " << id << " não encontrado." << std::endl;
            }
            else
            {
                std::cout << "Medidor com ID " << id << " removido com sucesso." << std::endl;
            }
            break;
        case 9:
            std::cout << "Digite o ID do medidor que deseja visualizar: ";
            std::cin >> id;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (maker->print_meter_line(id))
            {
                std::cout << "Medidor com ID " << id << " não encontrado." << std::endl;
            }
            break;
        case 10:
            break;
        default:
            std::cout << "Opção inválida. Tente novamente." << std::endl;
            break;
        }
    } while (op != 10);
}