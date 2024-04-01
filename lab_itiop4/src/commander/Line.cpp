#include "Line.hpp"

std::vector<std::string> *Line::splitString(std::string string)
{
    std::vector<std::string> *output = new std::vector<std::string>;
    std::string buffer;

    for (int i = 0; i < string.size(); i++)
    {
        if (string[i] != ' ')
            buffer += string[i];

        else
        {
            output->push_back(buffer);
            buffer.clear();
        }
    }
    if (!buffer.empty())
        output->push_back(buffer);

    return output;
}

Line::Line(std::string str)
{
    std::vector<std::string> *parts = splitString(str);

    std::string invoker = parts->at(0);

    std::vector<char> *shortOptions = new std::vector<char>;
    std::vector<std::string> *longOptions = new std::vector<std::string>;
    std::vector<std::string> *body = new std::vector<std::string>;
    int k = 0;

    for (int i = 0; i < parts->size(); i++)
    {
        std::string str = parts->at(i);
        if (str.at(0) == '-' && str.at(1) != '-')
        {
            shortOptions->push_back(str.at(1));
            k++;
        }
    }

    for (int i = 0; i < parts->size(); i++)
    {
        std::string str = parts->at(i);
        if (str.at(0) == '-' && str.at(1) == '-')
        {
            longOptions->push_back(str.substr(2));
            k++;
        }
    }

    for (int i = k + 1; i < parts->size(); i++)
        body->push_back(parts->at(i));

    this->invoker = invoker;
    this->shortOptions = shortOptions;
    this->longOptions = longOptions;
    this->body = body;
}

Line::~Line()
{
    delete shortOptions;
    shortOptions = nullptr;
    delete longOptions;
    longOptions = nullptr;
    delete body;
    body = nullptr;
}

std::string Line::getInvoker()
{
    return invoker;
}

std::vector<char> *Line::getShortOptions()
{
    return shortOptions;
}

std::vector<std::string> *Line::getLongOptions()
{
    return longOptions;
}

std::vector<std::string> *Line::getBody()
{
    return body;
}
