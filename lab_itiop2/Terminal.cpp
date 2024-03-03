#include "proto/Terminal.h"
#include "commands/Switch_Command.cpp"
#include "commands/Push_Command.cpp"
#include "commands/Pop_Command.cpp"
#include "commands/CheckIfEmpty_Command.cpp"
#include "commands/Print_Command.cpp"

Terminal::Terminal(std::ostream &os, std::istream &is) : os{os}, is{is}
{
    commands = new std::vector<ICommand *>;
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
    std::vector<char> *body = line->getBody();

    if (!ifCommandExists(invoker))
    {
        os << "This command does not exist!" << std::endl;
        return true;
    }

    if (!operations && invoker != "sw" && invoker != "ext")
    {
        os << "Sequence is not stated. Use \'sw\' command" << std::endl;
        return true;
    }

    if (invoker == "sw")
    {
        for (int i = 0; i < keys->size(); i++)
        {
            if (keys->at(i) == "-help")
            {
                os << "sw [<-keys>] <value>\nto switch current sequence to another\n\n\t[-help] for help\n\nUse 's' to set stack state\nUse 'q' to set queue state" << std::endl;
                return true;
            }
        }
        if (!body)
        {
            os << "sw [<-keys>] <value>\nto switch current sequence to another\n\n\t[-help] for help\n\nUse 's' to set stack state\nUse 'q' to set queue state" << std::endl;
            return true;
        }
        if (body->size() == 1)
            command = new Switch_Command(&operations, os, is, new Mode(body->back()));
    }
    else if (invoker == "psh")
    {
        for (int i = 0; i < keys->size(); i++)
        {
            if (keys->at(i) == "-help")
            {
                os << "psh [<-keys>] <values>\nto push element(s) to the current sequence\n\n\t[-help] for help" << std::endl;
                return true;
            }
        }

        if (!body)
        {
            os << "psh [<-keys>] <values>\nto push element(s) to the current sequence\n\n\t[-help] for help" << std::endl;
            return true;
        }
        command = new Push_Command(operations, os, body);
    }
    else if (invoker == "pop")
    {
        for (int i = 0; i < keys->size(); i++)
        {
            if (keys->at(i) == "-help")
            {
                os << "pop [<-keys>]\n\tto pop element from the current sequence\n\n\t-help for help" << std::endl;
                return true;
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
                os << "mt [<-keys>p]\n\tto check if the current sequence is empty\n\n\t-help for help" << std::endl;
                return true;
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
                os << "mt [<-keys>]\n\tto check if the current sequence is empty\n\n\t-help for help" << std::endl;
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