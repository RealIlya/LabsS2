#ifndef TERMINAL_H
#define TERMINAL_H
#include "../commander/ILine.h"
#include "../commander/ICommand.h"
#include "IOperations.h"
#include <ostream>
#include <istream>

class Terminal
{
private:
    std::vector<std::string> possibleCommands = {"sw", "psh", "pop", "mt", "prt", "ext"};
    std::vector<ICommand *> *commands;
    IOperations *operations;
    std::ostream &os;
    std::istream &is;

    bool ifCommandExists(std::string invoker);

public:
    Terminal(std::ostream &os, std::istream &is);
    ~Terminal();

    bool invoke(ILine *line);
};

#endif