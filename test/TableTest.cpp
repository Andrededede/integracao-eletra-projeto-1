#include "../include/Table.h"
#include "catch.hpp"

TEST_CASE("Table column widths calculation", "[table]")
{
    Table table;

    SECTION("Calculate column widths for a non-empty table")
    {
        std::vector<row_t> table_data = {{"1", "Meter A", "SINGLE_PHASE", "ARES", "ABCDEFGH"},
                                         {"12345", "Meter B", "THREE_PHASE", "APOLO", "EDP"},
                                         {"3", "Meter C", "SINGLE_PHASE", "CRONOS", "EDP"}};

        auto widths = table.calculate_column_widths(table_data);

        CHECK(widths[0] == 5);
        CHECK(widths[1] == 7);
        CHECK(widths[2] == 12);
        CHECK(widths[3] == 6);
        CHECK(widths[4] == 8);
    }

    SECTION("Calculate column widths for an empty table")
    {
        std::vector<row_t> empty_table_data;
        auto widths = table.calculate_column_widths(empty_table_data);

        CHECK(widths[0] == 2);
        CHECK(widths[1] == 4);
        CHECK(widths[2] == 4);
        CHECK(widths[3] == 5);
        CHECK(widths[4] == 7);
    }
}