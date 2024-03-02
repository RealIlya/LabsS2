#include "Executor.h"

#include <vector>

Executor::Executor()
{
    commands = new std::map<std::string, Tail *>();
}

Executor::~Executor()
{
    delete commands;
    commands = nullptr;
}

void Executor::addCommand(std::string head, Tail *command)
{
    commands->insert({head, command});
}

bool Executor::executeCommand(std::string line)
{
    std::vector<std::string> lines = split(line);
    std::string head;

    if (commands->count(head))
    {
        commands->at(head)->execute({});
        return 1;
    }

    return 0;
}

std::vector<std::string> split(std::string s, std::string del = " ")
{
    std::vector<std::string> result;
    int start, end = -1 * del.size();
    do
    {
        start = end + del.size();
        end = s.find(del, start);
        result.push_back(s.substr(start, end - start));
    } while (end != -1);

    return result;
}