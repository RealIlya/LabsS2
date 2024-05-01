#ifndef ADDNUM_COMMAND_HPP
#define ADDNUM_COMMAND_HPP
#include "../../include/commander/ICommand.hpp"
#include "../table/TableNum.hpp"

class AddNum_Command : public ICommand
{
private:
    TableNum *table;
    int key;
    double value;
    std::string str;

public:
    AddNum_Command(TableNum *table, int key, double value, std::string str);
    ~AddNum_Command();

    void execute() override;
};

#endif