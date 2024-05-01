#ifndef ITERMINAL_HPP
#define ITERMINAL_HPP
#include "ILine.hpp"
#include "ICommand.hpp"

class ITerminal
{
private:
    std::vector<std::string> possibleCommands;
    std::vector<ICommand *> *commands;

public:
    virtual int invoke(ILine *line) = 0;
};

#endif