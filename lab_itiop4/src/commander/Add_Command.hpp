#ifndef ADD_COMMAND_HPP
#define ADD_COMMAND_HPP
#include "../../include/commander/ICommand.hpp"
#include "../table/Table.hpp"

class Add_Command : public ICommand
{
private:
    Table *table;
    std::string key;
    double value;

public:
    Add_Command(Table *table, std::string key, double value);
    ~Add_Command();

    void execute() override;
};

#endif