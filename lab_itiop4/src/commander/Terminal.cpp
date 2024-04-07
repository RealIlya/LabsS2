#include "Terminal.hpp"
#include "Add_Command.hpp"
#include "AddInOrder_Command.hpp"

Terminal::Terminal(std::ostream &os, std::istream &is) : os{os}, is{is}, table{new Table(64)}, ordered{new OrderedTable}
{
    commands = new std::vector<std::string>{"add", "prt", "ext"};
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
                command = new Add_Command(table, body->at(0), std::stod(body->at(1)));
            else
                os << "Incorrect input!\n";

        for (int i = 0; i < longOptions->size(); i++)
        {
            if (longOptions->at(i) == "order")
                if (body->size() == 3)
                    command = new AddInOrder_Command(ordered, std::stoi(body->at(0)), std::stod(body->at(1)), body->at(2));
                else
                    os << "Incorrect input!\n";
        }
    }
    else if (invoker == "prt")
    {
        for (int i = 0; i < longOptions->size(); i++)
        {
            if (longOptions->at(i) == "order")
                os << ordered->toString() << std::endl;
        }

        if (longOptions->size() == 0)
            os << table->toString() << std::endl;
    }
    else if (invoker == "ext")
        return false;

    if (command)
        command->execute();
    return true;
}