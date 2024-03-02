#include "proto/Terminal.h"
#include "commands/Push_Command.cpp"
#include "commands/Pop_Command.cpp"
#include "commands/CheckIfEmpty_Command.cpp"
#include "commands/Print_Command.cpp"

Terminal::Terminal(IOperations *operations, std::ostream &os) : operations{operations}, os{os}
{
    commands = new std::vector<ICommand *>;
}

Terminal::~Terminal()
{
    delete operations;
    operations = nullptr;
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

void Terminal::invoke(ILine *line)
{
    ICommand *command = nullptr;
    std::string invoker = line->getInvoker();
    std::vector<std::string> *keys = line->getKeys();
    char *body = line->getBody();
    if (!ifCommandExists(invoker))
    {
        os << "This command does not exist" << std::endl;
        return;
    }

    if (invoker == "psh")
    {
        for (int i = 0; i < keys->size(); i++)
        {
            if (keys->at(i) == "-help")
            {
                os << "psh [-help] <value>\nto push element to the current sequence\n\n\t[-help] for help" << std::endl;
                return;
            }
        }

        if (!body)
        {
            os << "psh [-help] <value>\nto push element to the current sequence\n\n\t[-help] for help" << std::endl;
            return;
        }
        command = new Push_Command(operations, os, *body);
    }
    else if (invoker == "pop")
    {
        for (int i = 0; i < keys->size(); i++)
        {
            if (keys->at(i) == "-help")
            {
                os << "pop [-help]\n\tto pop element from the current sequence\n\n\t-help for help" << std::endl;
                return;
            }
        }
        command = new Pop_Command(operations, os);
    }
    else if (invoker == "mt")
    {
        for (int i = 0; i < keys->size(); i++)
        {
            if (keys->at(i) == "-help")
            {
                os << "mt [-help]\n\tto check if the current sequence is empty\n\n\t-help for help" << std::endl;
                return;
            }
        }
        command = new CheckIfEmpty_Command(operations, os);
    }
    else if (invoker == "prt")
    {
        for (int i = 0; i < keys->size(); i++)
        {
            if (keys->at(i) == "-help")
            {
                os << "mt [-help]\n\tto check if the current sequence is empty\n\n\t-help for help" << std::endl;
                return;
            }
        }
        command = new Print_Command(operations, os);
    }

    if (command)
    {
        command->execute();
        commands->push_back(command);
    }
}