#ifndef ADD_COMMAND_HPP
#define ADD_COMMAND_HPP
#include "../../include/commander/ICommand.hpp"
#include "../table/TableStr.hpp"

class Add_Command : public ICommand
{
private:
    TableStr *table;
    std::string key;
    double value;

public:
    Add_Command(TableStr *table, std::string key, double value);
    ~Add_Command();

    void execute() override;
};

#endif