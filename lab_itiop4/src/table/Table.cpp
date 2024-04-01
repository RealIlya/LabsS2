#include "Table.hpp"

Table::TableNode::TableNode(std::string key, float value) : key{key}, value{value} {}

Table::Table()
{
    size = defaultSize;
    fulness = 0;
    elems = new Table::TableNode *[size];
    for (int i = 0; i < size; i++)
    {
        elems[i] = nullptr;
    }
}

Table::~Table()
{
    delete[] elems;
    elems = nullptr;
}

int Table::getHash(std::string key)
{
    int hash = 0;
    for (int i = 0; i < 15; i++)
        hash = (hash << 5) - hash + key[i];

    return abs(hash);
}

int Table::getIndex(std::string key)
{
    return getHash(key) % size;
}

void Table::resize()
{
    int sizeBuffer = size;
    size *= 2;
    fulness = 0;
    TableNode **elems2 = new TableNode *[size];

    for (int i = 0; i < size; i++)
        elems2[i] = nullptr;

    std::swap(elems, elems2);

    for (int i = 0; i < sizeBuffer; i++)
        if (elems2[i])
            add(elems2[i]->key, elems2[i]->value);

    delete[] elems2;
}

bool Table::add(std::string key, float value)
{
    // if (fulness + 1 > int(size * rehashSize))
    //     resize();

    int index = getIndex(key);

    // in case key collision, do not add value
    for (int i = 0; elems[index] != nullptr && i < size; i++)
    {
        if (elems[index]->key == key)
        {
            return false;
        }
    }

    elems[index] = new TableNode(key, value);
    fulness++;
    return true;
}