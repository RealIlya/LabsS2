#include "proto/mode.h"

Mode::Mode(char c)
{
    if (c == 'q')
    {
        value = Value::queue;
    }
    else if (c == 's')
    {
        value = Value::stack;
    }
}

Mode *Mode::operator=(Value value)
{
    this->value = value;
    return this;
};

bool Mode::operator==(Value value)
{
    return this->value == value;
}

std::string Mode::toString()
{
    switch (value)
    {
    case Value::queue:
        return "queue";
    case Value::stack:
        return "stack";
    }
    return "Non";
}