#include "AddInOrder_Command.hpp"

AddInOrder_Command::AddInOrder_Command(OrderedTable *ordered, int key, double value, std::string str) : ordered{ordered}, key{key}, value{value}, str{str} {}

AddInOrder_Command::~AddInOrder_Command()
{
    delete ordered;
    ordered = nullptr;
    str.clear();
}

void AddInOrder_Command::execute()
{
    ordered->add(key, value, str);
}