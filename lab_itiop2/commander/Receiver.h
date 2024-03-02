#ifndef RECEIVER_H
#define RECEIVER_H
#include <string>
#include <functional>

class Receiver
{
    std::function<void()> operation;

public:
    Receiver(std::function<void()> operation);
    void doOp(std::initializer_list<std::string> &keys);
};

#endif