#include <iostream>
#include "commander/Terminal.hpp"
#include "commander/Line.hpp"

int main()
{
    std::ostream &os = std::cout;
    std::istream &is = std::cin;
    Terminal *terminal = new Terminal(os, is);
    Line *line;
    std::string input;
    while (true)
    {
        std::getline(is, input);
        if (input.empty())
            continue;
        line = new Line(input);
        if (!terminal->invoke(line))
            break;
    }

    return 0;
}