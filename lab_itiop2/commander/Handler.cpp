#include "Handler.h"
#include "Executor.h"

template <typename T>
Handler<T>::Handler()
{
    executor = new Executor<T>();
}

template <typename T>
Handler<T>::~Handler()
{
    delete executor;
    executor = nullptr;
}

template <typename T>
bool Handler<T>::executeCommand(T call)
{
    return executor->executeCommand(call);
}