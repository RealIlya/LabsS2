#ifndef TAIL_H
#define TAIL_H
#include "CommandABC.h"
#include "Receiver.h"
#include <string>

class Tail
{
    Receiver *receiver;
    std::initializer_list<std::string> *keys;

public:
    Tail(Receiver *receiver);
    ~Tail();

    void execute(std::initializer_list<std::string> &inputKeys);
};

#endif