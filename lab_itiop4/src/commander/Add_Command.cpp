#include "Add_Command.hpp"

Add_Command::Add_Command(Table *table, std::string key, float value)
{
    this->table = table;
    this->key = key;
    this->value = value;
}

Add_Command::~Add_Command()
{
    delete table;
    table = nullptr;
    key.clear();
}

void Add_Command::execute()
{
    table->add(key, value);
}