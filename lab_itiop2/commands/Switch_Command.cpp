#include "../proto/mode.h"
#include "../proto/Stack.h"
#include "../proto/Queue.h"
#include "_BaseCommand.cpp"
#include <istream>

class Switch_Command : public _BaseCommand
{
private:
    std::istream &is;
    Mode *mode;

    IOperations **bufferedOperations;

public:
    Switch_Command(IOperations **operations, std::ostream &os, std::istream &is, Mode *mode) : bufferedOperations{operations}, is{is}, mode{mode}, _BaseCommand{os} {}

    void execute() override
    {
        if (*mode == Mode::Value::queue)
        {
            int length;
            os << "Input length of queue >> ";
            is >> length;
            *bufferedOperations = new Queue(length);
            os << "Switched" << std::endl;
        }
        else if (*mode == Mode::Value::stack)
        {
            int length;
            os << "Input length of stack >> ";
            is >> length;
            *bufferedOperations = new Stack(length);
            os << "Switched" << std::endl;
        }
        else
        {
            os << "Try again" << std::endl;
        }
    }
};