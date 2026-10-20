#include "Table.h"
#include <iomanip>
#include <iostream>

row_t table_header = {"id", "Nome", "Tipo", "Linha", "Cliente"};

auto Table::calculate_column_widths(const std::vector<row_t> &table) -> widths_t
{
    widths_t widths{};
    for (size_t i = 0; i != table_header.size(); ++i)
    {
        widths[i] = std::max(widths[i], table_header[i].size());
    }
    for (const row_t &row : table)
    {
        for (size_t i = 0; i != row.size(); ++i)
        {
            widths[i] = std::max(widths[i], row[i].size());
        }
    }
    return widths;
}

auto Table::print_row(const row_t &row, const widths_t &widths) -> void
{
    std::cout << '|';
    for (size_t i = 0; i != row.size(); ++i)
    {
        std::cout << ' ';
        std::cout << std::setw(widths[i]) << row[i] << " |";
    }
    std::cout << std::endl;
}

auto Table::print_break(const widths_t &widths) -> void
{
    std::cout.fill('-');
    std::cout << '+';
    for (std::size_t w : widths)
    {
        std::cout << std::setw(w + 2) << '-';
        std::cout << '+';
    }
    std::cout << std::endl;
    std::cout.fill(' ');
}

auto Table::print_table(const std::vector<row_t> &table_body) -> void
{
    if (table_body.empty())
    {
        std::cout << "Nenhum medidor encontrado." << std::endl;
        return;
    }
    auto widths = calculate_column_widths(table_body);
    std::cout.setf(std::ios::left, std::ios::adjustfield);
    print_break(widths);
    print_row(table_header, widths);
    print_break(widths);
    for (const row_t &row : table_body)
    {
        print_row(row, widths);
    }
    print_break(widths);
    return;
}