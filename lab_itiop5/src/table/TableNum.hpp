#ifndef TABLENUM_HPP
#define TABLENUM_HPP
#include <string>

class TableNum
{
private:
    struct TableNode
    {
        int key;
        double value;
        std::string str;

        TableNode(int key, double value, std::string str);

        std::string toString();
    } typedef TableNode;

    int _size;
    int _fulness;
    TableNode **_elems;
    TableNode **_sorted;

    int getHash(int key, bool h);
    int getIndex(int key, int research);

    TableNode **fromTableToArray();

public:
    TableNum(int size);
    ~TableNum();

    double add(int key, double value, std::string str);
    std::pair<int, int> insertionSort();

    std::string toString();
    std::string toStringSorted();
};

#endif
