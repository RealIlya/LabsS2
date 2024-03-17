#include "_BaseCommand.cpp"

class Add_Command : public _BaseCommand
{
    float value;

public:
    Add_Command(IOperations *operations, std::ostream &os, float value) : value{value}, _BaseCommand{operations, os} {}

    void execute() override
    {
        operations->add(value);
    }
};