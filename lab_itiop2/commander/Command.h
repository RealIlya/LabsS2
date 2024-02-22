#ifndef COMMANDER_H
#define COMMANDER_H
#include <functional>
#include <map>

class Command
{
    std::function<void()> command;

public:
    Command(std::function<void()> command);

    void execute();
};

#endif