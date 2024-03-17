#ifndef TREE_H
#define TREE_H
#include "IOperations.h"

class Tree : public IOperations
{
private:
    float value;
    Tree *left;
    Tree *right;

public:
    Tree();
    Tree(float value);
    ~Tree();

    float sum() override;
    void add(float value) override;
    void print(std::ostream &os) override;
};

#endif