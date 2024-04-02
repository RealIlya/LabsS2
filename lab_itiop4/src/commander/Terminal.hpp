#ifndef TERMINAL_HPP
#define TERMINAL_HPP
#include "../../include/commander/ITerminal.hpp"
#include "../table/Table.hpp"
#include <map>

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
    std::map<std::string, std::vector<CommandText>> commandsWithText;
    Table *table;

    std::string getCommandText(std::vector<CommandText> &options, std::string option);

public:
    Terminal();
    ~Terminal();
    int invoke(ILine *line) override;
};

#endif