#include "TableNum.hpp"

TableNum::TableNode::TableNode(int key, double value, std::string str) : key{key}, value{value}, str{str} {}

std::string TableNum::TableNode::toString()
{
    return std::to_string(key) + ": [" + std::to_string(value) + ", " + str + "]";
}

TableNum::TableNum(int size) : _size{size}, _fulness{0}
{
    _elems = new TableNum::TableNode *[size];
    for (int i = 0; i < _size; i++)
        _elems[i] = nullptr;
}

TableNum::~TableNum()
{
    delete[] _elems;
    _elems = nullptr;
}

int TableNum::getHash(int key, bool h)
{
    int hash = (key << 5) + pow(-1, h) * key;

    return abs(hash);
}

int TableNum::getIndex(int key, int research)
{
    return abs(research == 0
                   ? getHash(key, 0) % _size
                   : (getHash(key, 0) + research * getHash(key, 1)) % _size);
}

double TableNum::add(int key, double value, std::string str)
{
    int index = getIndex(key, 0);

    for (int i = 1; i < _size; i++)
    {
        if (!_elems[index])
        {
            _elems[index] = new TableNode(key, value, str);
            _fulness++;
            return value;
        }

        index = getIndex(key, i);
    }

    return false;
}

TableNum::TableNode **TableNum::fromTableToArray()
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

std::pair<int, int> TableNum::insertionSort()
{
    _sorted = fromTableToArray();

    int cmpN = 0;
    int swpN = 0;
    TableNode *elem;

    for (int i = 1; i < _fulness; i++)
    {
        elem = _sorted[i];
        int j = i - 1;
        while (j >= 0 && ((_sorted[j]->key > elem->key) ||
                          (_sorted[j]->key == elem->key && _sorted[j]->value > elem->value) ||
                          (_sorted[j]->value == elem->value && _sorted[j]->str > elem->str)))
        {
            cmpN++;
            _sorted[j + 1] = _sorted[j];
            j--;
        }
        if (_sorted[j + 1] != elem)
            swpN++;
        _sorted[j + 1] = elem;
    }

    return std::pair(cmpN, swpN);
}

std::string TableNum::toString()
{
    std::string result;
    for (int i = 0; i < _size; i++)
        if (_elems[i])
            result += _elems[i]->toString() + "\n";

    return result;
}

std::string TableNum::toStringSorted()
{
    std::string result;
    for (int i = 0; i < _fulness; i++)
        if (_sorted[i])
            result += _sorted[i]->toString() + "\n";

    return result;
}