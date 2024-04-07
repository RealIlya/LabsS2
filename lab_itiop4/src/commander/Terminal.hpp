#ifndef TERMINAL_HPP
#define TERMINAL_HPP
#include "../../include/commander/ITerminal.hpp"
#include "../table/Table.hpp"
#include "../table/OrderedTable.hpp"
#include <ostream>
#include <istream>

class Terminal : public ITerminal
{
private:
    std::vector<std::string> *commands;

    Table *table;
    OrderedTable *ordered;

    std::ostream &os;
    std::istream &is;

public:
    Terminal(std::ostream &os, std::istream &is);
    ~Terminal();
    int invoke(ILine *line) override;
};

#endif