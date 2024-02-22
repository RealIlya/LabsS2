#ifndef MODE_H
#define MODE_H
#include <string>

class Mode
{
public:
    enum class Value
    {
        queue,
        stack
    };

private:
    Value value;

public:
    Mode *operator=(Value value);
    std::string toString();
};

#endif