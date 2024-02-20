#include "commander/Command.h"
#include "commander/Handler.h"
#include "proto/commands.h"

class MyHandler : public Handler<char>
{
    std::ostream &ostream;
    std::istream &istream;
    Commands *commands;

public:
    MyHandler(std::ostream &ostream, std::istream &istream) : ostream{ostream}, istream{istream}, Handler()
    {
        commands = new Commands(this->ostream, this->istream);
    }

    ~MyHandler()
    {
        delete commands;
        commands = nullptr;
    }

    void start(char stopCommand)
    {
        executor->addCommand('h', new Command(std::bind(&Commands::help_Command, commands)));
        executor->addCommand('p', new Command(std::bind(&Commands::pushBack_Command, commands)));
        executor->addCommand('d', new Command(std::bind(&Commands::delete_Command, commands)));
        executor->addCommand('z', new Command(std::bind(&Commands::getSize_Command, commands)));
        executor->addCommand('c', new Command(std::bind(&Commands::checkContent_Command, commands)));
        executor->addCommand('t', new Command(std::bind(&Commands::print_Command, commands)));

        char command;

        while (true)
        {
            istream >> command;
            if (command == stopCommand)
                break;

            if (!executeCommand(command))
            {
                ostream << "Incorrect command, try again >> ";
            }
        }
    }
};
