#include "Executor.h"

template <typename T>
Executor<T>::Executor()
{
    commands = new std::map<T, Command *>();
}

template <typename T>
Executor<T>::~Executor()
{
    delete commands;
    commands = nullptr;
}

template <typename T>
void Executor<T>::addCommand(T condition, Command *command)
{
    commands->insert({condition, command});
}

template <typename T>
bool Executor<T>::executeCommand(T call)
{
    if (commands->count(call))
    {
        commands->at(call)->execute();
        return 1;
    }

    return 0;
}