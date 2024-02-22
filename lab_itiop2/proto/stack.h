#ifndef STACK_H
#define STACK_H
#include "operations.h"

struct stack : public operations
{
    int top;
    int length;
    char *data;

    stack(int length);
    ~stack();

    bool empty();
    void print(std::ostream &ostream);
    bool pop(char &out);
    char pop();
    bool push(char value);
};

#endif