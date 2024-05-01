#ifndef TABLESTR_HPP
#define TABLESTR_HPP
#include <string>

class TableStr
{
private:
    struct TableNode
    {
        std::string key;
        double value;

        TableNode(std::string key, double value);

        std::string toString();
    } typedef TableNode;

    int _size;
    int _fulness;
    TableNode **_elems;
    TableNode **_sorted;

    int getHash(std::string key, bool h);        // max key size is 15 chars
    int getIndex(std::string key, int research); // max key size is 15 chars

    TableNode **fromTableToArray();

public:
    TableStr(int size);
    ~TableStr();

    double add(std::string key, double value);
    std::pair<int, int> selectionSort();

    std::string toString();
    std::string toStringSorted();
};

#endif