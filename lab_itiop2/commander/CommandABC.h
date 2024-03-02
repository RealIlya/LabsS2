#ifndef COMMANDABC_H
#define COMMANDABC_H

class CommandABC
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

#endif