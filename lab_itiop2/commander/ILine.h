#ifndef ILINE_H
#define ILINE_H
#include <string>
#include <vector>

class ILine
{
public:
    virtual std::string getInvoker() = 0;
    virtual std::vector<std::string> *getKeys() = 0;
    virtual std::vector<char> *getBody() = 0;
};

#endif