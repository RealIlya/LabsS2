#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "table/Table.hpp"

int main(int argc, char **argv)
{
    doctest::Context context;

    context.setOption("abort-after", 5);
    context.setOption("order-by", "name");

    context.applyCommandLine(argc, argv);

    int res = context.run();

    if (context.shouldExit())
        return res;

    return res + EXIT_SUCCESS;
}

TEST_CASE("Table testing")
{
    Table *table = new Table();

    CHECK(table->add("aboba", 80) == 80);
    CHECK(table->add("aboba", 10.1) == false);
    CHECK(table->add("foo", 90.14) == 90.14f);
    CHECK(table->add("fo", 40) == 40);
    CHECK(table->add("f", 50) == 50);
    CHECK(table->add("f", 90) == false);
    CHECK(table->add("f", 100) == false);
    CHECK(table->add("aboba", 600.8) == false);
    CHECK(table->add("foo", 89) == false);
    CHECK(table->add("bar", 777) == 777);
}