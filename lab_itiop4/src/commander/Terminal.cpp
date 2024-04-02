#include "Terminal.hpp"
#include "Add_Command.hpp"

Terminal::CommandText::CommandText(char shortOption, std::string longOption, std::string text)
{
    this->shortOption = shortOption;
    this->longOption = longOption;
    this->text = text;
}

bool Terminal::CommandText::compare(std::string option)
{
    return this->longOption == option || this->shortOption == option[0];
}

Terminal::CommandText::~CommandText()
{
    shortOption = NULL;
    longOption.clear();
    text.clear();
}

Terminal::Terminal(std::ostream &os, std::istream &is) : os{os}, is{is}, table{new Table(64)}
{
    commands = new std::vector<std::string>{"add", "prt", "ext"};
    commandsWithText = {
        {"add", {
                    {"help", "add [options] <new-value>\n\tTo add the value to the table"},
                }},
        {"ext", {
                    {"help", "ext\n\tTo exit the program"},
                }}};
}

Terminal::~Terminal()
{
    delete[] commands;
}

std::string Terminal::getCommandText(std::vector<CommandText> &options, std::string option)
{
    for (CommandText commandText : options)
        if (commandText.compare(option))
            return commandText.text;

    return "";
}

int Terminal::invoke(ILine *line)
{
    ICommand *command = nullptr;
    std::string invoker = line->getInvoker();
    std::vector<char> *shortOptions = line->getShortOptions();
    std::vector<std::string> *longOptions = line->getLongOptions();
    std::vector<std::string> *body = line->getBody();

    if (invoker == "add")
    {
        // for (int i = 0; i < longOptions->size(); i++)
        // {
        //     std::string text = commandsWithText.at(invoker).at(longOptions->at(i));
        //     // os << text;
        // }

        if (body->size() == 2)
        {
            os << body->size() << std::endl;
            command = new Add_Command(table, body->at(0), std::stof(body->at(1)));
        }
    }
    else if (invoker == "prt")
    {
        os << table->toString() << std::endl;
    }
    else if (invoker == "ext")
        return false;
    else
    {
        // does not exist
        return true;
    }

    if (command)
        command->execute();
    return true;
}