#include "_BaseCommand.cpp"

class Pop_Command : public _BaseCommand
{
public:
    Pop_Command(IOperations *operations, std::ostream &os) : _BaseCommand{operations, os} {}

    void execute()
    {
        os << operations->pop() << std::endl;
    }
};