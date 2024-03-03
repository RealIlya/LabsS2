#include "_BaseCommand.cpp"
#include <vector>

class Push_Command : public _BaseCommand
{
private:
    std::vector<char> *values;

public:
    Push_Command(IOperations *operations, std::ostream &os, std::vector<char> *values) : values{values}, _BaseCommand{operations, os} {}

    ~Push_Command()
    {
        delete values;
        values = nullptr;
    }

    void execute() override
    {
        for (int i = 0; i < values->size(); i++)
        {
            if (!operations->push(values->at(i)))
            {
                os << "The sequence is full, hence, the elements ";
                for (int j = i; j < values->size(); j++)
                {
                    os << "\'" << values->at(j) << "\'" << (j != (values->size() - 1) ? ", " : " ");
                }
                os << "are not pushed" << std::endl;
                break;
            }
        }
    }
};