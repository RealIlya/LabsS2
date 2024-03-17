#ifndef IOPERATIONS_H
#define IOPERATIONS_H
#include <ostream>

// concrete receiver, will be inherited by sequences for implementation
class IOperations
{
public:
    virtual float sum() = 0;
    virtual void add(float value) = 0;
    virtual void print(std::ostream &os) = 0;
};

#endif