#include "_BaseCommand.cpp"

class Pop_Command : public _BaseCommand
{
public:
    Pop_Command(IOperations *operations, std::ostream &os) : _BaseCommand{operations, os} {}

    void execute()
    {
        char elem;
        os << (operations->pop(elem) ? elem : '\0') << std::endl;
    }
};