#include "_BaseCommand.cpp"

class Print_Command : public _BaseCommand
{
public:
    Print_Command(IOperations *operations, std::ostream &os) : _BaseCommand{operations, os} {}

    void execute()
    {
        operations->print(os);
        os << std::endl;
    }
};