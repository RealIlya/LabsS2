#ifndef TERMINAL_HPP
#define TERMINAL_HPP
#include "../../include/commander/ITerminal.hpp"
#include "../table/TableStr.hpp"
#include "../table/TableNum.hpp"
#include <ostream>
#include <istream>

class Terminal : public ITerminal
{
private:
    std::vector<std::string> *commands;

    TableStr *tableStr;
    TableNum *tableNum;

    std::ostream &os;
    std::istream &is;

public:
    Terminal(std::ostream &os, std::istream &is);
    ~Terminal();
    int invoke(ILine *line) override;
};

#endif