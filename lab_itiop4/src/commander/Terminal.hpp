#ifndef TERMINAL_HPP
#define TERMINAL_HPP
#include "../../include/commander/ITerminal.hpp"
#include "../table/Table.hpp"

class Terminal : public ITerminal
{
private:
    std::vector<std::string> *commands;
    Table *table;

public:
    Terminal();
    ~Terminal();
    int invoke(ILine *line) override;
};

#endif