#ifndef LINE_H
#define LINE_H
#include "ILine.h"

class Line : public ILine
{
private:
    std::string invoker;
    std::vector<std::string> *keys;
    std::vector<float> *body;

    std::vector<std::string> *splitString(std::string string);

public:
    Line(std::string str);
    ~Line();

    std::string getInvoker();
    std::vector<std::string> *getKeys();
    std::vector<float> *getBody();
};

#endif