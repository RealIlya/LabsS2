#include "/home/howgeed/TheHole/LabsS2/lab_itiop2/proto/IOperations.h"
#include "/home/howgeed/TheHole/LabsS2/lab_itiop2/commander/ICommand.h"
#include <ostream>
#pragma once

class _BaseCommand : public ICommand
{
protected:
    IOperations *operations;
    std::ostream &os;

public:
    _BaseCommand(IOperations *operations, std::ostream &os) : operations{operations}, os{os} {}
    ~_BaseCommand()
    {
        delete operations;
        operations = nullptr;
    }
};
