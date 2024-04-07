#include "Table.hpp"

Table::TableNode::TableNode(std::string key, double value) : key{key}, value{value} {}

std::string Table::TableNode::toString()
{
    return key + ": " + std::to_string(value);
}

Table::Table(int size) : _size{size}, _fulness{0}
{
    _elems = new Table::TableNode *[size];
    for (int i = 0; i < _size; i++)
        _elems[i] = nullptr;
}

Table::~Table()
{
    delete[] _elems;
    _elems = nullptr;
}

int Table::getHash(std::string key, bool h)
{
    int hash = 0;
    for (int i = 0; i < key.size(); i++)
        hash = (hash << 5) - hash + int(pow(-1, h)) * key[i];

    return abs(hash);
}

int Table::getIndex(std::string key)
{
    return getHash(key, 0) % _size;
}

double Table::add(std::string key, double value)
{
    int index = getIndex(key);

    for (int i = 0; i < _size; i++)
    {
        if (!_elems[index])
        {
            _elems[index] = new TableNode(key, value);
            _fulness++;
            return value;
        }

        index = (getHash(key, 0) + i * getHash(key, 1)) % _size;
    }

    return false;
}

std::string Table::toString()
{
    std::string result;
    for (int i = 0; i < _size; i++)
        if (_elems[i])
            result += _elems[i]->toString() + "\n";

    return result;
}