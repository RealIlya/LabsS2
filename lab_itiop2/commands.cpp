#include "proto/commands.h"
#include "proto/queue.h"
#include "proto/stack.h"

Commands::Commands(std::ostream &ostream, std::istream &istream) : ostream{ostream}, istream{istream}
{
    mode = Mode::Value::queue;
    ostream << "Input command (help for help) >> ";
}

Commands::~Commands()
{
    delete operations;
    operations = nullptr;
}

void Commands::help_Command()
{
    ostream << "Now mode is the " << mode.toString() << std::endl;
    ostream << "switch to switch a mode\n"
            << "push to push an elem\n"
            << "pop to pop an elem\n"
            << "empty to check empty\n"
            << "print to print a sequence\n"
            << "ext to terminate program" << std::endl;
}

void Commands::switchMode_Command()
{
    ostream << "Input st to switch mode on stack or\n"
            << "input qu to switch mode on queue >> ";
    std::string com;
    istream >> com;

    if (com == "st" || com == "qu")
    {
        ostream << "Input size >> " << std::endl;
        int size;
        istream >> size;
        if (com == "st")
        {
            mode = Mode::Value::stack;
            operations = new stack(size);
        }
        else
        {
            mode = Mode::Value::queue;
            operations = new queue(size);
        }
    }
    else
    {
        ostream << "Incorrect input!";
    }
}

void Commands::push_Command()
{
    char elem;
    ostream << "Input a char to push >> ";
    istream >> elem;
    operations->push(elem);
}

void Commands::pop_Command()
{
    ostream << (operations->pop() ? "Pop" : "Does not contain values") << std::endl;
}

void Commands::checkEmpty_Command()
{
    ostream << mode.toString() << " is " << (operations->empty() ? "empty" : "not empty") << std::endl;
}

void Commands::print_Command()
{
    operations->print(ostream);
}