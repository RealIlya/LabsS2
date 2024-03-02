#include <iostream>
#include "proto/Stack.h"

Stack::Stack(int length)
{
    top = -1;
    this->length = length;
    data = new char[length];
}

Stack::~Stack()
{
    delete data;
    data = nullptr;
}

bool Stack::empty()
{
    return top == -1;
}

void Stack::print(std::ostream &ostream)
{
    if (empty())
    {
        ostream << "Stack is empty";
        return;
    }

    for (int i = 0; i < length; i++)
    {
        char e = data[i];
        ostream << e << " ";
    }
}

char Stack::pop()
{
    char b = data[top];
    data[top--] = '\0';

    return b;
}

bool Stack::pop(char &out)
{
    if (empty())
        return 0;

    out = pop();
    return 1;
}

bool Stack::push(char value)
{
    if (top != length - 1)
    {
        data[++top] = value;
        return 1;
    }

    return 0;
}
