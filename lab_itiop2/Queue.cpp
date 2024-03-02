#include <iostream>
#include "proto/Queue.h"

Queue::Queue(int length)
{
    beg = 0;
    end = -1;
    this->length = length;
    data = new char[length];
}

Queue::~Queue()
{
    delete data;
    data = nullptr;
}

bool Queue::empty()
{
    return end == -1;
}

void Queue::print(std::ostream &ostream)
{
    if (empty())
    {
        ostream << "Queue is empty";
        return;
    }

    for (int i = 0; i < length; i++)
        ostream << data[i] << " ";
}

char Queue::pop()
{
    char b = data[beg];
    data[beg] = '\0';

    // in case of pseudo-fulness
    if (end == length - 1)
    {
    }

    if (beg == end)
    {
        beg = 0;
        end = -1;
    }
    else
        beg++;
    return b;
}

bool Queue::pop(char &out)
{
    if (empty())
        return 0;

    out = pop();
    return 1;
}

bool Queue::push(char value)
{
    if (end == length - 1)
        return 0;
    end++;
    data[end] = value;
    return 1;
}
