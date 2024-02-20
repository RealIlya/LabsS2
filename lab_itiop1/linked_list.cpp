#include <ostream>
#include "proto/linked_list.h"

list::list()
{
    value = NULL;
    next = NULL;
}

list::list(char *value)
{
    this->value = value;
    next = NULL;
}

list *list::find(char *value)
{
    list *l = this;
    while (l->next != NULL && *l->next->value != *value)
        l = l->next;

    return l->next;
}

bool list::contains(char *value)
{
    list *l = this;
    while (l->next != NULL)
    {
        if (*l->next->value == *value)
        {
            return true;
        }
        l = l->next;
    }

    return false;
}

int list::size()
{
    int n = 1;
    list *l = this;

    while (l->next != NULL)
    {
        l = l->next;
        n++;
    }

    return n;
}

void list::print(std::ostream &ostream)
{
    if (size() == 1)
    {
        ostream << "List contains only root" << std::endl;
        return;
    }

    list *cur = this;
    while (cur->next != NULL)
    {
        if (cur->next->value != NULL)
            ostream << *cur->next->value << " ";
        cur = cur->next;
    }
    ostream << std::endl;
}

bool list::del(char *value)
{
    list *l = this;
    while (l->next != NULL && *l->next->value != *value)
        l = l->next;

    if (l->next)
    {
        list *p = l->next;
        l->next = p->next;
        delete p;
        p = nullptr;
        return 1;
    }

    return 0;
}

void list::push_back(char *value)
{
    list *p = new list(value);

    if (next == NULL)
        next = p;
    else
    {
        list *cur = next;
        while (cur->next != NULL)
            cur = cur->next;

        cur->next = p;
    }
}
