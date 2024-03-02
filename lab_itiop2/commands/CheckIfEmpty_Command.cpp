#include "_BaseCommand.cpp"

class CheckIfEmpty_Command : public _BaseCommand
{
public:
    CheckIfEmpty_Command(IOperations *operations, std::ostream &os) : _BaseCommand{operations, os} {}

    void execute()
    {
        os << "Sequence is " << (operations->empty() ? "empty" : "not empty") << std::endl;
    }
};