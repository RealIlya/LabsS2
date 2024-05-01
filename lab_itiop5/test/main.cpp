#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "table/TableStr.hpp"
#include "table/TableNum.hpp"

int main(int argc, char **argv)
{
    doctest::Context context;

    context.setOption("abort-after", 5);
    context.setOption("tableNum-by", "name");

    context.applyCommandLine(argc, argv);

    int res = context.run();

    if (context.shouldExit())
        return res;

    return res + EXIT_SUCCESS;
}

TEST_CASE("Table testing #1")
{
    TableStr *tableStr = new TableStr(64);
    CHECK(tableStr->add("eloy", 80) == 80);
    CHECK(tableStr->add("cream", 90.14) == 90.14);
    CHECK(tableStr->add("jimihendrix", 50) == 50);
    CHECK(tableStr->add("moodyblues", 600.8) == 600.8);

    MESSAGE("\n", tableStr->toString());

    std::pair p(tableStr->selectionSort());
    MESSAGE("\n", tableStr->toStringSorted());

    MESSAGE("\n", "Comparisons: ", p.first, " | Swaps: ", p.second);
}

TEST_CASE("Table testing #2")
{
    TableNum *tableNum = new TableNum(64);
    CHECK(tableNum->add(4, 10, "traffic") == 10);
    CHECK(tableNum->add(9, 1, "yes") == 1);
    CHECK(tableNum->add(400, 11, "greenday") == 11);
    CHECK(tableNum->add(8, 3, "the5:55") == 3);
    CHECK(tableNum->add(1, 3, "the5:55") == 3);

    MESSAGE("\n", tableNum->toString());

    std::pair p(tableNum->insertionSort());
    MESSAGE("\n", tableNum->toStringSorted());

    MESSAGE("\n", "Comparisons: ", p.first, " | Swaps: ", p.second);
}

TEST_CASE("Table testing #3")
{
    TableStr *tableStr = new TableStr(64);
    CHECK(tableStr->add("cream", 89) == 89);
    CHECK(tableStr->add("cream", 777) == 777);
    CHECK(tableStr->add("cream", 41.3) == 41.3);
    CHECK(tableStr->add("cream", 12) == 12);
    CHECK(tableStr->add("cream", 12) == 12);

    MESSAGE("\n", tableStr->toString());

    std::pair p(tableStr->selectionSort());
    MESSAGE("\n", tableStr->toStringSorted());

    MESSAGE("\n", "Comparisons: ", p.first, " | Swaps: ", p.second);
}