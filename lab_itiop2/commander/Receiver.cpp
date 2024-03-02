#include "Receiver.h"

Receiver::Receiver(std::function<void()> operation)
{
    this->operation = operation;
}

void Receiver::doOp(std::initializer_list<std::string> &keys)
{
}