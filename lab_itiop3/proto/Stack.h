#ifndef STACK_H
#define STACK_H
#include <ostream>
#include "Tree.h"

class Stack
{
private:
    Tree *value;
    Stack *next;
    void clear();

public:
    Stack();
    ~Stack();

    Tree *pop();
    void push(Tree *value);
    int size();
};

#endif