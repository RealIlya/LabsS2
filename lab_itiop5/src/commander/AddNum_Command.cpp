#include "AddNum_Command.hpp"

AddNum_Command::AddNum_Command(TableNum *table, int key, double value, std::string str) : table{table}, key{key}, value{value}, str{str} {}

AddNum_Command::~AddNum_Command()
{
    delete table;
    table = nullptr;
    str.clear();
}

void AddNum_Command::execute()
{
    table->add(key, value, str);
}