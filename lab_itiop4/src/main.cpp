#include <iostream>
#include "commander/Terminal.hpp"
#include "commander/Line.hpp"

int main()
{
    std::ostream &os = std::cout;
    std::istream &is = std::cin;
    Terminal *terminal = new Terminal(os, is);
    Line *line;
    do
    {
        std::string input;
        is >> input;
        line = new Line(input);
    } while (terminal->invoke(line));

    return EXIT_SUCCESS;
}