#include "proto/mode.h"

Mode *Mode::operator=(Value value)
{
    this->value = value;
    return this;
};

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