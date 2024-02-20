#ifndef COMMANDS_H
#define COMMANDS_H
#include <ostream>
#include <istream>
#include "linked_list.h"

struct list;

struct Commands
{
protected:
    std::ostream &ostream;
    std::istream &istream;
    struct list *list;

public:
    Commands(std::ostream &ostream, std::istream &istream);
    ~Commands();

    void help_Command();
    void pushBack_Command();
    void delete_Command();
    void getSize_Command();
    void checkContent_Command();
    void print_Command();
};

#endif