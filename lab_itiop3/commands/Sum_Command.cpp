#include "_BaseCommand.cpp"

class Sum_Command : public _BaseCommand
{

public:
    Sum_Command(IOperations *operations, std::ostream &os) : _BaseCommand{operations, os} {}

    void execute() override
    {
        os << operations->sum() << std::endl;
    }
};