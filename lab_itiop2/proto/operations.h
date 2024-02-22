#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <ostream>

struct operations
{
    virtual bool empty() = 0;
    virtual void print(std::ostream &ostream) = 0;
    virtual char pop() = 0;
    virtual bool pop(char &out) = 0;
    virtual bool push(char value) = 0;
};

#endif