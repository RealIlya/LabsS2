#ifndef HANDLER_H
#define HANDLER_H

class Handler
{
protected:
    Executor *executor;

public:
    Handler();
    ~Handler();

    virtual void start() = 0;
};

#endif