#include "Tail.h"

Tail::Tail(Receiver *receiver)
{
    this->receiver = receiver;
}

Tail::~Tail()
{
    delete keys;
    keys = nullptr;
    delete receiver;
    receiver = nullptr;
}

void Tail::execute(std::initializer_list<std::string> &inputKeys)
{
    for (std::string key : inputKeys)
    {
        if (!(std::find(this->keys->begin(), this->keys->end(), key) != this->keys->end()))
            return;
    }

    receiver->doOp(inputKeys);
}