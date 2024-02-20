#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <ostream>

struct list
{
    char *value;
    list *next;

    list();
    list(char *value);
    list *find(char *value);
    bool contains(char *value);
    int size();
    void print(std::ostream &ostream);
    bool del(char *value);
    void push_back(char *value);
};

#endif