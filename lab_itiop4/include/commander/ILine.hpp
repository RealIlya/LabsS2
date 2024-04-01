#ifndef ILINE_HPP
#define ILINE_HPP
#include <string>
#include <vector>

class ILine
{
public:
    virtual std::string getInvoker() = 0;
    virtual std::vector<char> *getShortOptions() = 0;
    virtual std::vector<std::string> *getLongOptions() = 0;
    virtual std::vector<std::string> *getBody() = 0;
};

#endif