#include "Handler.h"
#include "Executor.h"

Handler::Handler()
{
    executor = new Executor();
}

Handler::~Handler()
{
    delete executor;
    executor = nullptr;
}