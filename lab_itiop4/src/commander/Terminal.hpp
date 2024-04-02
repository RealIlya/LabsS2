#ifndef TERMINAL_HPP
#define TERMINAL_HPP
#include "../../include/commander/ITerminal.hpp"
#include "../table/Table.hpp"
#include <unordered_map>
#include <ostream>
#include <istream>

class Terminal : public ITerminal
{
private:
    struct CommandText
    {
        char shortOption;
        std::string longOption;
        std::string text;

        CommandText(char shortOption, std::string longOption, std::string text);
        ~CommandText();

        bool compare(std::string option);
    } typedef CommandText;

    std::vector<std::string> *commands;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> commandsWithText;
    Table *table;

    std::ostream &os;
    std::istream &is;

    std::string getCommandText(std::vector<CommandText> &options, std::string option);

public:
    Terminal(std::ostream &os, std::istream &is);
    ~Terminal();
    int invoke(ILine *line) override;
};

#endif