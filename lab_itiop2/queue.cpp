#include <iostream>
#include "proto/queue.h"

queue::queue(int length)
{
    beg = 0;
    end = -1;
    this->length = length;
    data = new char[length];
}

queue::~queue()
{
    delete data;
    data = nullptr;
}

bool queue::empty()
{
    return end == -1;
}

void queue::print(std::ostream &ostream)
{
    if (empty())
    {
        ostream << "Queue is empty" << std::endl;
        return;
    }

    for (int i = 0; i < length; i++)
        ostream << data[i] << " ";
    ostream << std::endl;
}

char queue::pop()
{
    char b = data[beg];
    data[beg] = '\0';

    // in case of preudo-fulness
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

bool queue::pop(char &out)
{
    if (empty())
        return 0;

    out = pop();
    return 1;
}

bool queue::push(char value)
{
    if (end == length - 1)
        return 0;
    end++;
    data[end] = value;
    return 1;
}
