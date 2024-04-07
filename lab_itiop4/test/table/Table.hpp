#ifndef TABLE_HPP
#define TABLE_HPP
#include <string>

class Table
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

    int getHash(std::string key, bool h); // max key size is 15 chars
    int getIndex(std::string key);        // max key size is 15 chars

public:
    Table(int size);
    ~Table();

    double add(std::string key, double value);
    std::string toString();
};

#endif