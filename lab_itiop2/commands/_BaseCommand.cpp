#include "../proto/IOperations.h"
#include "../commander/ICommand.h"
#include <ostream>
#pragma once

class _BaseCommand : public ICommand
{
protected:
    IOperations *operations;
    std::ostream &os;

public:
    _BaseCommand(std::ostream &os) : _BaseCommand{nullptr, os} {}
    _BaseCommand(IOperations *operations, std::ostream &os) : operations{operations}, os{os} {}
    ~_BaseCommand()
    {
        if (operations != nullptr)
        {
            delete operations;
            operations = nullptr;
        }
    }
};
