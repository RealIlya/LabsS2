#ifndef ADDINORDER_COMMAND_HPP
#define ADDINORDER_COMMAND_HPP
#include "../../include/commander/ICommand.hpp"
#include "../table/OrderedTable.hpp"

class AddInOrder_Command : public ICommand
{
private:
    OrderedTable *ordered;
    int key;
    double value;
    std::string str;

public:
    AddInOrder_Command(OrderedTable *ordered, int key, double value, std::string str);
    ~AddInOrder_Command();

    void execute() override;
};

#endif