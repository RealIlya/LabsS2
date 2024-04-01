#include "Terminal.hpp"

Terminal::Terminal()
{
    commands = new std::vector<std::string>{"add", "ext"};
}

Terminal::~Terminal()
{
    delete[] commands;
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