#include "_BaseCommand.cpp"

class Clear_Command : public _BaseCommand
{
public:
    Clear_Command(IOperations *operations, std::ostream &os) : _BaseCommand{operations, os} {}

    void execute() override
    {
        operations->clear();
        os << "Sequence is cleared" << std::endl;
    }
};