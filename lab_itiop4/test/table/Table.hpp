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
    } typedef TableNode;

    constexpr static const float rehashSize = 0.75;
    static const int defaultSize = 64;
    int size;
    int fulness;
    TableNode **elems;

    void resize();
    void rehash();

public:
    Table();
    ~Table();
    int getIndex(std::string key); // max key size is 15 chars

    int getHash(std::string key); // max key size is 15 chars
    float add(std::string key, float value);
};

#endif