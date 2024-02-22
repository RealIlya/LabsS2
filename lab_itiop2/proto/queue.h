#ifndef QUEUE_H
#define QUEUE_H
#include "operations.h"

struct queue : public operations
{
    int beg = 0;
    int end = -1;
    int length;
    char *data;

    queue(int length);
    ~queue();

    bool empty() override;
    void print(std::ostream &ostream);
    bool pop(char &out);
    char pop();
    bool push(char value);
};

#endif