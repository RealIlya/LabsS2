#include "proto/Stack.h"

Stack::Stack()
{
    value = 0;
    next = nullptr;
}

Stack::~Stack()
{
    clear();
}

Tree *Stack::pop()
{
    Stack *p = next;
    Tree *buffer = next->value;
    next = next->next;
    delete p;
    p = nullptr;
    return buffer;
}

void Stack::clear()
{
    while (next)
    {
        Stack *p = next;
        next = next->next;
        delete p;
        p = nullptr;
    }
}

void Stack::push(Tree *value)
{
    Stack *p = new Stack;
    p->value = value;
    p->next = next;
    next = p;
}

int Stack::size()
{
    int n = 1;
    Stack *s = this;

    while (s->next != NULL)
    {
        s = s->next;
        n++;
    }

    return n;
}