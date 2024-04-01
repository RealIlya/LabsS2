#ifndef LINE_HPP
#define LINE_HPP
#include "../../include/commander/ILine.hpp"

class Line : public ILine
{
private:
    std::string invoker;
    std::vector<char> *shortOptions;
    std::vector<std::string> *longOptions;
    std::vector<std::string> *body;

    std::vector<std::string> *splitString(std::string string);

public:
    Line(std::string str);
    ~Line();

    std::string getInvoker() override;
    std::vector<char> *getShortOptions() override;
    std::vector<std::string> *getLongOptions() override;
    std::vector<std::string> *getBody() override;
};

#endif