#include "proto/commands.h"
#include "proto/queue.h"
#include "proto/stack.h"

#include "commander/Tail.h"
#include "commander/Receiver.h"

#include <map>

const std::string comPointer = "^";

std::string invokers[] = {"sw", "push", "pop", "mt", "prnt", "ext"};
std::string keys[] = {"help"};

std::string helps[] = 
{
    "[-help] <args: st, qu> to switch a mode on stack, queue",
    "[-help] <char> to push into",
    "[-help] to pop from",
    "[-help] to check is empty",
    "[-help] to print in output stream",
    "[-help] to exit the program"
};

std::map<std::string, std::string> map;
void create()
{
    for (int i = 0; i < helps->length(); i++)
    {
        helps[i].replace(helps[i].find(comPointer), comPointer.length(), invokers[i]);
    }

    for (int i = 0; i < helps->length(); i++)
    {
        map[invokers[i]] = helps[i];
    }
    
}


Commands::Commands(std::ostream &ostream, std::istream &istream) : ostream{ostream}, istream{istream}
{
    mode = Mode::Value::queue;
    ostream << "Input command (help for help) >> ";

    new Tail(new Receiver() {});
}

Commands::~Commands()
{
    delete operations;
    operations = nullptr;
}

void Commands::help_Command()
{
    ostream << "Now mode is the " << mode.toString() << std::endl;
}

void Commands::switchMode_Command()
{
    std::string com;
    istream >> com;

    if (com == "st" || com == "qu")
    {
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

bool Commands::checkStopCommand(std::string command)
{
    return command == stopCommand;
}