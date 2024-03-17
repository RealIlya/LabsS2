#include "Line.h"

std::vector<std::string> *Line::splitString(std::string string)
{
    std::vector<std::string> *output = new std::vector<std::string>;
    std::string buffer;

    for (int i = 0; i < string.size(); i++)
    {
        if (string[i] != ' ')
        {
            buffer += string[i];
        }
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

    std::vector<std::string> *keys = new std::vector<std::string>;
    std::vector<float> *body = new std::vector<float>;
    int k = 1;
    for (; k < parts->size(); k++)
    {
        if (parts->at(k).at(0) == '-')
            keys->push_back(parts->at(k));
        else
            break;
    }

    if (parts->size() != k)
    {
        for (int i = k; i < parts->size(); i++)
        {
            body->push_back(std::stof(parts->at(i)));
        }
    }
    else
        body = nullptr;

    this->invoker = invoker;
    this->keys = keys;
    this->body = body;
}

Line::~Line()
{
    delete keys;
    keys = nullptr;
    delete body;
    body = nullptr;
}

std::string Line::getInvoker()
{
    return invoker;
}

std::vector<std::string> *Line::getKeys()
{
    return keys;
}

std::vector<float> *Line::getBody()
{
    return body;
}
