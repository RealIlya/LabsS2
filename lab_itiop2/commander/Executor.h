#ifndef EXECUTOR_H
#define EXECUTOR_H
#include <map>
#include "Tail.h"

class Executor
{
    // head: tail
    std::map<std::string, Tail *> *commands;

public:
    Executor();
    ~Executor();

    void addCommand(std::string head, Tail *command);
    bool executeCommand(std::string head);
};

#endif