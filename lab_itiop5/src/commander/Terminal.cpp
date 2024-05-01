#include "Terminal.hpp"
#include "Add_Command.hpp"
#include "AddNum_Command.hpp"

Terminal::Terminal(std::ostream &os, std::istream &is) : os{os}, is{is}, tableStr{new TableStr(64)}, tableNum{new TableNum(64)}
{
    commands = new std::vector<std::string>{"add", "prts", "prtn", "ext"};
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
        if (longOptions->size() == 0)
            if (body->size() == 2)
                command = new Add_Command(tableStr, body->at(0), std::stod(body->at(1)));
            else
                os << "Incorrect input!\n";

        for (int i = 0; i < longOptions->size(); i++)
        {
            if (longOptions->at(i) == "num")
                if (body->size() == 3)
                    command = new AddNum_Command(tableNum, std::stoi(body->at(0)), std::stod(body->at(1)), body->at(2));
                else
                    os << "Incorrect input!\n";
        }
    }
    else if (invoker == "prts")
    {
        for (int i = 0; i < longOptions->size(); i++)
        {
            if (longOptions->at(i) == "sorted")
            {
                os << tableStr->toStringSorted() << std::endl;
                break;
            }
        }
        if (longOptions->size() == 0)
            os << tableStr->toString() << std::endl;
    }
    else if (invoker == "prtn")
    {
        for (int i = 0; i < longOptions->size(); i++)
        {
            if (longOptions->at(i) == "sorted")
            {
                os << tableNum->toStringSorted() << std::endl;
                break;
            }
        }
        if (longOptions->size() == 0)
            os << tableNum->toString() << std::endl;
    }

    else if (invoker == "ext")
        return false;

    if (command)
        command->execute();
    return true;
}