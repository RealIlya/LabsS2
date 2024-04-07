#ifndef ORDERED_TABLE_HPP
#define ORDERED_TABLE_HPP
#include <string>

class OrderedTable
{
private:
    struct TableNode
    {
        int key;
        double value;
        std::string str;

        TableNode *left;
        TableNode *right;

        TableNode(int key, double value, std::string str);
        ~TableNode();

        std::string toString();
    } typedef TableNode;

    TableNode *_root;

public:
    OrderedTable();
    ~OrderedTable();

    double add(int key, double value, std::string str);
    std::string toString();
};

#endif
