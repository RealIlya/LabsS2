#ifndef TABLE_HPP
#define TABLE_HPP
#include <string>

class Table
{
private:
    struct TableNode
    {
        std::string key;
        float value;

        TableNode(std::string key, float value);

    public:
        std::string toString();
    } typedef TableNode;

    constexpr static const float rehashSize = 0.75;
    static const int defaultSize = 64;
    int size;
    int fulness;
    TableNode **elems;

    int getHash(std::string key);  // max key size is 15 chars
    int getIndex(std::string key); // max key size is 15 chars

    void resize();

public:
    Table(int size);
    ~Table();

    bool add(std::string key, float value);
    std::string toString();
};

#endif