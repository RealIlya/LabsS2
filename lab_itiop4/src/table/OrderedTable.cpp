#include "OrderedTable.hpp"
#include <functional>

OrderedTable::TableNode::TableNode(int key, double value, std::string str) : key{key}, value{value}, str{str}, left{nullptr}, right{nullptr} {}

OrderedTable::TableNode::~TableNode()
{
    delete left, right;
    left, right = nullptr, nullptr;
}

std::string OrderedTable::TableNode::toString()
{
    return std::to_string(key) + ": [" + std::to_string(value) + ", " + str + "]";
}

OrderedTable::OrderedTable() : _root{nullptr} {}

OrderedTable::~OrderedTable()
{
    delete _root;
    _root = nullptr;
}

double OrderedTable::add(int key, double value, std::string str)
{
    if (!_root)
    {
        _root = new TableNode(key, value, str);
        return value;
    }

    TableNode *node = new TableNode(key, value, str);
    TableNode *cur = _root;
    TableNode *buff;
    while (cur)
    {
        buff = cur;

        cur = key > cur->key || (key == cur->key && value > cur->value) || (value == cur->value && str > cur->str)
                  ? cur->left
                  : cur->right;
    }

    key > buff->key || (key == buff->key && value > buff->value) || (value == buff->value && str > buff->str)
        ? buff->left = node
        : buff->right = node;

    return value;
}

std::string OrderedTable::toString()
{
    if (!_root)
        return "";

    std::string result;
    std::function<void(TableNode *)> func;
    func = [&](TableNode *tableNode)
    {
        if (tableNode->right)
            func(tableNode->right);

        result += tableNode->toString() + "\n";

        if (tableNode->left)
            func(tableNode->left);
    };
    func(_root);

    return result;
}