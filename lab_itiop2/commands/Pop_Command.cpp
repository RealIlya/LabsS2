#include "_BaseCommand.cpp"

class Pop_Command : public _BaseCommand
{
public:
    Pop_Command(IOperations *operations, std::ostream &os) : _BaseCommand{operations, os} {}

    void execute()
    {
        char elem;
        if (operations->pop(elem))
            os << elem;
        else
            os << "Empty";
        os << std::endl;
    }
};