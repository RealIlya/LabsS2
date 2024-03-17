#include "proto/Terminal.h"
#include "proto/Tree.h"
#include "commands/Add_Command.cpp"
#include "commands/AddMany_Command.cpp"
#include "commands/Sum_Command.cpp"
#include "commands/Print_Command.cpp"

Terminal::Terminal(std::ostream &os, std::istream &is) : os{os}, is{is}
{
    commands = new std::vector<ICommand *>;
    operations = new Tree;
}

Terminal::~Terminal()
{
    if (operations != nullptr)
    {
        delete operations;
        operations = nullptr;
    }
}

bool Terminal::ifCommandExists(std::string invoker)
{
    for (int i = 0; i < possibleCommands.size(); i++)
    {
        if (possibleCommands[i] == invoker)
            return true;
    }

    return false;
}

bool Terminal::invoke(ILine *line)
{
    ICommand *command = nullptr;
    std::string invoker = line->getInvoker();
    std::vector<std::string> *keys = line->getKeys();
    std::vector<float> *body = line->getBody();

    if (!ifCommandExists(invoker))
    {
        os << "This command does not exist!" << std::endl;
        return true;
    }

    if (invoker == "help")
    {
        os << "add [-<keys>] <value>\n  to add element in tree\n  It can take several values\n\n    [-help] for help" << std::endl;
        os << "sum [-<keys>]\n  to summarize elements of tree\n\n    [-help] for help" << std::endl;
        os << "prt [-<keys>]\n  to print tree in output stream\n\n    [-help] for help" << std::endl;
        os << "ext \n  to exit program" << std::endl;
    }
    else if (invoker == "add")
    {
        for (int i = 0; i < keys->size(); i++)
        {
            if (keys->at(i) == "-help")
            {
                os << "add [-<keys>] <value>\n  to add element in tree\n\n    [-help] for help" << std::endl;
                return true;
            }
        }
        if (!body)
        {
            os << "add [-<keys>] <value>\n  to add element in tree\n  It can take several values\n\n    [-help] for help" << std::endl;
            return true;
        }

        if (body->size() == 1)
            command = new Add_Command(operations, os, body->back());
        else
            command = new AddMany_Command(operations, os, body);
    }
    else if (invoker == "sum")
    {
        for (int i = 0; i < keys->size(); i++)
        {
            if (keys->at(i) == "-help")
            {
                os << "sum [-<keys>]\n  to summarize elements of tree\n\n    [-help] for help" << std::endl;
                return true;
            }
        }

        command = new Sum_Command(operations, os);
    }
    else if (invoker == "prt")
    {
        for (int i = 0; i < keys->size(); i++)
        {
            if (keys->at(i) == "-help")
            {
                os << "prt [-<keys>]\n  to print tree in output stream\n\n    [-help] for help" << std::endl;
                return true;
            }
        }

        command = new Print_Command(operations, os);
    }
    else if (invoker == "ext")
    {
        return false;
    }

    if (command != nullptr)
    {
        command->execute();
        commands->push_back(command);
    }

    return true;
}