#include "TableStr.hpp"

TableStr::TableNode::TableNode(std::string key, double value) : key{key}, value{value} {}

std::string TableStr::TableNode::toString()
{
    return key + ": " + std::to_string(value);
}

TableStr::TableStr(int size) : _size{size}, _fulness{0}
{
    _elems = new TableStr::TableNode *[size];
    for (int i = 0; i < _size; i++)
        _elems[i] = nullptr;
}

TableStr::~TableStr()
{
    delete[] _elems;
    _elems = nullptr;
}

int TableStr::getHash(std::string key, bool h)
{
    int hash = 0;
    for (int i = 0; i < key.size(); i++)
        hash = (hash << 5) - hash + int(pow(-1, h)) * key[i];

    return abs(hash);
}

int TableStr::getIndex(std::string key, int research)
{
    return abs(research == 0
                   ? getHash(key, 0) % _size
                   : (getHash(key, 0) + research * getHash(key, 1)) % _size);
}

double TableStr::add(std::string key, double value)
{
    int index = getIndex(key, 0);

    for (int i = 1; i < _size; i++)
    {
        if (!_elems[index])
        {
            _elems[index] = new TableNode(key, value);
            _fulness++;
            return value;
        }

        index = getIndex(key, i);
    }

    return false;
}

TableStr::TableNode **TableStr::fromTableToArray()
{
    TableNode **array = new TableNode *[_fulness];
    for (int i = 0, k = 0; i < _size; i++)
    {
        if (_elems[i])
        {
            array[k] = _elems[i];
            k++;
        }
    }
    return array;
}

std::pair<int, int> TableStr::selectionSort()
{
    _sorted = fromTableToArray();

    int cmpN = 0;
    int swpN = 0;
    TableNode *min;
    int k;
    for (int i = 0; i < _fulness - 1; i++)
    {
        min = _sorted[i];
        k = i;
        for (int j = i + 1; j < _fulness; j++)
        {
            cmpN++;
            if ((_sorted[j]->key < min->key) || (_sorted[j]->key == min->key && _sorted[j]->value < min->value))
            {
                min = _sorted[j];
                k = j;
            }
        }
        if (min != _sorted[i])
            swpN++;
        _sorted[k] = _sorted[i];
        _sorted[i] = min;
    }

    return std::pair(cmpN, swpN);
}

std::string TableStr::toString()
{
    std::string result;
    for (int i = 0; i < _size; i++)
        if (_elems[i])
            result += _elems[i]->toString() + "\n";

    return result;
}

std::string TableStr::toStringSorted()
{
    selectionSort();
    std::string result;
    for (int i = 0; i < _fulness; i++)
        if (_sorted[i])
            result += _sorted[i]->toString() + "\n";

    return result;
}