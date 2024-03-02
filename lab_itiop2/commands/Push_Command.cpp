#include "_BaseCommand.cpp"

class Push_Command : public _BaseCommand
{
private:
    char value;

public:
    Push_Command(IOperations *operations, std::ostream &os, char value) : value{value}, _BaseCommand{operations, os} {}

    void execute() override
    {
        operations->push(value);
    }
};