#ifndef COMMANDS_H
#define COMMANDS_H
#include <ostream>
#include <istream>
#include "operations.h"
#include "mode.h"

struct operations;

struct Commands
{
protected:
    std::ostream &ostream;
    std::istream &istream;

    Mode mode;

    struct operations *operations;

public:
    Commands(std::ostream &ostream, std::istream &istream);
    ~Commands();

    void help_Command();
    void switchMode_Command();
    void push_Command();
    void pop_Command();
    void checkEmpty_Command();
    void print_Command();
};

#endif