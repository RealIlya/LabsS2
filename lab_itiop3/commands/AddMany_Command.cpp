#include "_BaseCommand.cpp"
#include <vector>

class AddMany_Command : public _BaseCommand
{
    std::vector<float> *values;

public:
    AddMany_Command(IOperations *operations, std::ostream &os, std::vector<float> *values) : values{values}, _BaseCommand{operations, os} {}

    void execute() override
    {
        for (int i = 0; i < values->size(); i++)
            operations->add(values->at(i));
    }
};