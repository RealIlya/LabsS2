#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "table/Table.hpp"
#include "table/OrderedTable.hpp"

int main(int argc, char **argv)
{
    doctest::Context context;

    // context.setOption("abort-after", 5);
    context.setOption("order-by", "name");

    context.applyCommandLine(argc, argv);

    int res = context.run();

    if (context.shouldExit())
        return res;
    
    return res + EXIT_SUCCESS;
}

TEST_CASE("Table testing")
{
    Table *table = new Table(64);

    CHECK(table->add("eloy", 80) == 80);
    CHECK(table->add("cream", 90.14) == 90.14);
    CHECK(table->add("jimihendrix", 50) == 50);
    CHECK(table->add("moodyblues", 600.8) == 600.8);
    CHECK(table->add("cream", 89) == 89);
    CHECK(table->add("styx", 777) == 777);

    MESSAGE(table->toString());

    OrderedTable *order = new OrderedTable;
    CHECK(order->add(4, 10, "traffic") == 10);
    CHECK(order->add(9, 1, "yes") == 1);
    CHECK(order->add(400, 11, "greenday") == 11);
    CHECK(order->add(8, 3, "the 5:55") == 3);

    MESSAGE(order->toString());
}