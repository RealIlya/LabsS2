#ifndef EXECUTOR_H
#define EXECUTOR_H
#include <map>
#include "Command.h"

template <typename T>
class Executor
{
    std::map<T, Command *> *commands;

public:
    Executor();
    ~Executor();

    void addCommand(T condition, Command *command);
    bool executeCommand(T call);
};

#endif