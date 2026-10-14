#pragma once

#include <array>
#include <string>
#include <vector>

class Table
{
public:
    Table() = default;
    using row_t = std::array<std::string, 5>;
    using widths_t = std::array<std::size_t, 5>;
    auto calculate_column_widths(const std::vector<row_t> &table) -> widths_t;
    auto print_row(const row_t &row, const widths_t &widths) -> void;
    auto print_break(const widths_t &widths) -> void;
    auto print_table(const std::vector<row_t> &table_body) -> void;
};