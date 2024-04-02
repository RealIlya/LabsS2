#include "Terminal.hpp"

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

Terminal::Terminal()
{
    commands = new std::vector<std::string>{"add", "ext"};
    commandsWithText = {
        {"add", {
                    {'h', "help", "add [options] <new-value>\n\tTo add the value to the table"},
                }},
        {"ext", {
                    {'h', "help", "ext\n\tTo exit the program"},
                }}};
}

Terminal::~Terminal()
{
    delete[] commands;
}

std::string Terminal::getCommandText(std::vector<CommandText> &options, std::string option)
{
    for (CommandText commandText : options)
    {
        if (commandText.compare(option))
        {
            return commandText.text;
        }
    }

    return "";
}

int Terminal::invoke(ILine *line)
{
    ICommand *command = nullptr;
    std::string invoker = line->getInvoker();
    std::vector<char> *shortOptions = line->getShortOptions();
    std::vector<std::string> *longOptions = line->getLongOptions();
    std::vector<std::string> *body = line->getBody();

    for (int i = 0; i < longOptions->size(); i++)
    {
        std::string commandText = getCommandText(commandsWithText[invoker], longOptions->at(i));
        if (!commandText.empty())
        {
        }
    }

    if (invoker == "add")
    {
    }
    else if (invoker == "ext")
    {
    }
    else
    {
        // does not exist
        return true;
    }
}