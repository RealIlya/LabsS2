#ifndef HANDLER_H
#define HANDLER_H

template <typename T>
class Handler
{
protected:
    Executor<T> *executor;

public:
    Handler();
    ~Handler();

    void start(T stopCommand);
    bool executeCommand(T call);
};

#endif