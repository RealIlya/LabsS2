#include "commander/Handler.h"
#include "proto/commands.h"

class MyHandler : public Handler
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

    void start() override
    {
        executor->addCommand("help", new Command(std::bind(&Commands::help_Command, commands)));
        executor->addCommand("switch", new Command(std::bind(&Commands::switchMode_Command, commands)));
        executor->addCommand("push", new Command(std::bind(&Commands::push_Command, commands)));
        executor->addCommand("pop", new Command(std::bind(&Commands::pop_Command, commands)));
        executor->addCommand("empty", new Command(std::bind(&Commands::checkEmpty_Command, commands)));
        executor->addCommand("print", new Command(std::bind(&Commands::print_Command, commands)));

        std::string command;

        while (true)
        {
            istream >> command;
            if (commands->checkStopCommand(command))
                break;

            if (!executor->executeCommand(command))
            {
                ostream << "Incorrect command, try again >> ";
            }
        }
    }
};
