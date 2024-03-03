#ifndef LINE_H
#define LINE_H
#include "ILine.h"
#include <string>
#include <vector>

class Line : public ILine
{
private:
    std::string invoker;
    std::vector<std::string> *keys;
    std::vector<char> *body;

    std::vector<std::string> *splitString(std::string string);

public:
    Line(std::string str);
    ~Line();

    std::string getInvoker();
    std::vector<std::string> *getKeys();
    std::vector<char> *getBody();
};

#endif