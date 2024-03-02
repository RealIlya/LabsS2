#ifndef TERMINAL_H
#define TERMINAL_H
#include "/home/howgeed/TheHole/LabsS2/lab_itiop2/commander/ILine.h"
#include "/home/howgeed/TheHole/LabsS2/lab_itiop2/commander/ICommand.h"
#include "IOperations.h"
#include <ostream>

class Terminal
{
private:
    std::vector<std::string> possibleCommands = {"psh", "pop", "mt", "prt"};
    std::vector<ICommand *> *commands;
    IOperations *operations;
    std::ostream &os;

    bool ifCommandExists(std::string invoker);

public:
    Terminal(IOperations *operations, std::ostream &os);
    ~Terminal();

    void invoke(ILine *line);
};

#endif