#include <iostream>
#include "proto/stack.h"

stack::stack(int length)
{
    top = -1;
    this->length = length;
    data = new char[length];
}

stack::~stack()
{
    delete data;
    data = nullptr;
}

bool stack::empty()
{
    return top == -1;
}

void stack::print(std::ostream &ostream)
{
    if (empty())
    {
        ostream << "Stack is empty" << std::endl;
        return;
    }

    for (int i = 0; i < length; i++)
    {
        char e = data[i];
        ostream << e << " ";
    }
    ostream << std::endl;
}

char stack::pop()
{
    char b = data[top];
    data[top--] = '\0';

    return b;
}

bool stack::pop(char &out)
{
    if (empty())
        return 0;

    out = pop();
    return 1;
}

bool stack::push(char value)
{
    if (top != length - 1)
    {
        data[++top] = value;
        return 1;
    }

    return 0;
}
